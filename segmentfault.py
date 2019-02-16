#pytest
#coding=utf-8
#!/usr/bin/python
# 掘金网站文章爬虫
# 作者：小鸡  flyphp@outlook.com

import pymysql
import time
from bs4 import BeautifulSoup
import requests,sys
import datetime
import re

# 填入连接数据库需要，IP，user，密码，库名
db = pymysql.connect(host='', user="", passwd='', db='')
cur_tag = ''
urls = []
tar = []
link_head = "https://juejin.im"
otar = []
ourls = []
ii = 0
it = 0

# url_fo = open("mysql_urls.log", "w")
# car_fo = open("mysql_cars.log", "w")


#################################################
# 		文章插入，数据库部分
#################################################
def insert_post(ti,au,con,ta,tim,db):
	title = ti.encode('utf-8')
	author = au.encode('utf-8')
	content = con
	content = content.replace("'","`")
	tag = ta.encode('utf-8')
	time = tim.encode('utf-8')
	cursor = db.cursor()
	# check repeat post
	check_title="SELECT `ID` FROM `wp_posts` WHERE `post_title` = '" + title + "'"
	try:
		cursor.execute(check_title)
	except:
		return 1
	data = cursor.fetchone()
	if data is None:

		# check tag
		check_tag = "SELECT `term_id` FROM `wp_terms` WHERE `name` = '" + tag + "'"
		cursor.execute(check_tag)
		tag_id = cursor.fetchone()
		tag_data = cursor.fetchall()
		if tag_id is None:
			try:	
				insert_tag = "INSERT INTO `wp_terms` (`term_id`, `name`, `slug`, `term_group`) VALUES (NULL, '"+ tag +"','" + tag + "', '0')"
				cursor.execute(insert_tag)
				cursor.execute(insert_tag)


				check_tag = "SELECT `term_id` FROM `wp_terms` WHERE `name` = '" + tag + "'"
				cursor.execute(check_tag)
				tag_data = cursor.fetchall()
				insert_taxonomy_tag = "INSERT INTO `wp_term_taxonomy` (`term_taxonomy_id`, `term_id`, `taxonomy`, `description`, `parent`, `count`) VALUES (NULL, '" + str(tag_data[0][0]) + "', 'post_tag', '', '0', '1')"
				insert_taxonomy_category = "INSERT INTO `wp_term_taxonomy` (`term_taxonomy_id`, `term_id`, `taxonomy`, `description`, `parent`, `count`) VALUES (NULL, '" + str(tag_data[1][0]) + "', 'category', '', '0', '1')"

				cursor.execute(insert_taxonomy_tag)
				cursor.execute(insert_taxonomy_category)
				db.commit()
			except:
				db.rollback()



		# check author
		check_author = "SELECT `ID` FROM `wp_users` WHERE `display_name` LIKE '" + author + "'"
		cursor = db.cursor()
		cursor.execute(check_author)
		author_id = cursor.fetchone()
		if author_id is None:
			insert_author = "INSERT INTO `wp_users` (`ID`, `user_login`, `user_pass`, `user_nicename`, `user_email`, `user_url`, `user_registered`, `user_activation_key`, `user_status`, `display_name`) VALUES (NULL, '', '', '', '', '', '0000-00-00 00:00:00.000000', '', '0', '" + author +"')"
			cursor = db.cursor()
			try:
				cursor.execute(insert_author)
				db.commit()
			except:
				db.rollback()
			check_author = "SELECT `ID` FROM `wp_users` WHERE `display_name` LIKE '" + author + "'"
			cursor = db.cursor()
			cursor.execute(check_author)
			author_id = cursor.fetchone()

		# creat new post

		insert_post = "INSERT INTO `wp_posts` (`ID`, `post_author`, `post_date`, `post_date_gmt`, `post_content`, `post_title`, `post_excerpt`, `post_status`, `comment_status`, `ping_status`, `post_password`, `post_name`, `to_ping`, `pinged`, `post_modified`, `post_modified_gmt`, `post_content_filtered`, `post_parent`, `guid`, `menu_order`, `post_type`, `post_mime_type`, `comment_count`) VALUES (NULL, '" + str(author_id[0]) + "', '" + str(time) + "', '" + str(time) + "', '" + str(content) + "', '" + str(title) + "', '', 'publish', 'open', 'open', '', '', '', '', '" + str(time) + "', '" + str(time) + "', '', '0', '', '0', 'post', '', '0')"
		try:

			try:
				cursor.execute(insert_post)
			except Exception as e:
				print(e)

			# check tag
			check_tag = "SELECT `term_id` FROM `wp_terms` WHERE `name` = '" + tag + "'"

			cursor.execute(check_title)
			post_id = cursor.fetchone()
			cursor.execute(check_tag)
			tag_data = cursor.fetchall()
			#print(tag_data)
			check_taxo = "SELECT `term_taxonomy_id` FROM `wp_term_taxonomy` WHERE `term_id` = '" + str(tag_data[0][0]) + "'"
			try:
				cursor.execute(check_taxo)

			except Exception as e:
				print(e)
			#print(cursor.fetchall())
			taxo_data = cursor.fetchone()

			insert_relationship = "INSERT INTO `wp_term_relationships` (`object_id`, `term_taxonomy_id`, `term_order`) VALUES ('" + str(post_id[0]) + "', '" + str(taxo_data[0]) + "', '0')"

			try:
				cursor.execute(insert_relationship)
			except Exception as e:
				print(e)
			update_taxo = "UPDATE `wp_term_taxonomy` SET `count` = `count`+1 WHERE `wp_term_taxonomy`.`term_taxonomy_id` = " + str(taxo_data[0])
			try:
				cursor.execute(update_taxo)
			except Exception as e:
				print(e)


			check_taxo = "SELECT `term_taxonomy_id` FROM `wp_term_taxonomy` WHERE `term_id` = '" + str(tag_data[1][0]) + "'"
			try:
				cursor.execute(check_taxo)
				#print(cursor.fetchall())
			except Exception as e:
				print(e)
			taxo_data = cursor.fetchone()
			insert_relationship = "INSERT INTO `wp_term_relationships` (`object_id`, `term_taxonomy_id`, `term_order`) VALUES ('" + str(post_id[0]) + "', '" + str(taxo_data[0]) + "', '0')"
			try:
				cursor.execute(insert_relationship)
			except Exception as e:
				print(e)

			update_taxo = "UPDATE `wp_term_taxonomy` SET `count` = `count`+1 WHERE `wp_term_taxonomy`.`term_taxonomy_id` = " + str(taxo_data[0])
			try:
				cursor.execute(update_taxo)
			except Exception as e:
				print(e)

			db.commit()
			global ii
			tip = "\tsucceed catch post" + str(title) + " this is the"+ str(ii) + "post"
			print(tip)
			ii = ii + 1
		except:
			db.rollback()
			print("\tinsert error!")
	else:
		global it
		print(u"\tThe post already exit! times" + str(it))
		it = it + 1
		return 0
	return 1

#################################################
# 		链接获取，爬虫部分
#################################################

def get_post(lin):
	link = lin
	requests.adapters.DEFAULT_RETRIES = 5
	s = requests.session()
	
	s.keep_alive = False
	try:
		req = s.get(url = link)
		bf = BeautifulSoup(req.text,"html.parser")
		s.close
		req.close

		texts = bf.find('div',class_='article fmt article__content')
		origin = u"<p>来源：<a target=_blank href="
		origin = origin.encode('utf-8')
		texts = str(texts) + origin + str(link) +" rel=noopener>" + str(link) + "</a></p>"
		title = bf.find('h1',id='articleTitle').find('a').text
		
		tim = '2019-01-19 20:20:20'
		author = bf.find('div', class_='article__authormeta').find('strong').text
		tag = bf.find('a',class_='tag').get('data-original-title')
		time.sleep(2)
	except:
		print("\t######################\n\n\terror!\n\n\t#######################")
		time.sleep(3)
		# get_url(nextlink)

	return insert_post(title,author,texts,tag,tim,db)


def get_url(begin):
	# global tar
	# global urls
	# global ourls
	requests.adapters.DEFAULT_RETRIES = 5
	s = requests.session()
	
	s.keep_alive = False
	try:
		req = s.get(url = begin)
		bf = BeautifulSoup(req.text,"html.parser")
		s.close
		req.close

		tags = bf.find_all('a',class_='tag')
		for x in tags:
			tar.append('https://segmentfault.com' + x.get('href')  + '/blogs?page=')
	except:
		print("error")
	
	for y in tar:
		ts = y
		print('\n\t*************************\n')
		print('\t new tag!!! ' + ts)
		print('\n\t*************************\n')
		for temp in xrange(1,500):
			new_urls = ts + str(temp)
			print('\n\tnew page ! ' + new_urls)
			new_req = s.get(url = new_urls)
			nbf = BeautifulSoup(new_req.text,"html.parser")
			hh = nbf.find_all(name = 'h2')
			if len(hh) < 10:
				print('\t\n\nthe last page!\n\n')
				break
			for hhh in hh:
				hhhh = hhh.find(name = 'a')
				if hhhh != None:
					hhhh = str(hhhh.get('href'))
					if	get_post('https://segmentfault.com' + hhhh) == 0:
						print('\tnext!')
						break
				

if __name__ == '__main__':

	print("\tbegin catch segment all post！\n")
	get_url('https://segmentfault.com/tags')
	# url_fo.close()
	# car_fo.close()
db.close()

