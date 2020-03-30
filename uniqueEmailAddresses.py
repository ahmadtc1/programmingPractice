class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        localName = ""
        domainName = ""
        emailAddress = ""
        emailAddresses = {}
        count: int = 0
        for email in emails:
            splitEmail = email.split('@')
            localSection = splitEmail[0]
            domainName = splitEmail[1]
            if (localSection.find('+') != -1):
                plusSplit = localSection.split('+')
                beforePlus = plusSplit[0]
                if (beforePlus.find('.') != -1):
                    splitIntoPeriodSections = beforePlus.split('.')
                    for section in splitIntoPeriodSections:
                        localName += section
                else:
                    localName = beforePlus
            else:
                if (localSection.find('.') != -1):
                    splitIntoPeriodSections = localSection.split('.')
                    for section in splitIntoPeriodSections:
                        localName += section
                else:
                    localName = localSection
            email = localName + '@' + domainName
            if email in emailAddresses:
                pass
            elif email not in emailAddresses:
                count += 1
                emailAddresses[email] = 0
            localName = ""
            domainName = ""
            email = ""
        return count
                
                
