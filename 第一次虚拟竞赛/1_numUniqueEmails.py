import re
class Solution:
    def numUniqueEmails(self, emails) -> int:
        mail_list = []
        for mail in emails:
            mail_ = re.sub(r"\+.*?@", "@", mail)  
            s = mail_.split("@") 
            a = s[0].replace(".", "") + "@" + s[1]
            if a not in mail_list:
                mail_list.append(a)
                
        return len(mail_list)

s = Solution()
print(s.numUniqueEmails(["gm.e.i+vcj.fcn@m.hkelhyekj.com","gm.e.i+kt.h.me+v@m.hkelhyekj.com","gm.e.i+w.q+h.a.ai@m.hkelhyekj.com"]))