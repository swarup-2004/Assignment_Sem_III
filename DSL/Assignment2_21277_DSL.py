class String:

    def __init__(self,string):
        self.string = string
        self.length = 0

        for i in string:
            self.length += 1

    def words(self):
        word = []
        w = ""
        for i in range(self.length):
            if self.string[i] == " " or self.string[i] == "/n" or i == self.length - 1:
                if i == self.length - 1:
                    w += self.string[i]
                word += [w]
                w = ""
            else:
                w += self.string[i]
        return word

    def longestWord(self):

        longest = ""
        long_len = 0

        word = self.words()

        for i in word:
            word_len = 0
            for j in i:
                word_len += 1

            if word_len >  long_len:
                long_len = word_len
                longest = i

        return longest, long_len

    def charFreq(self, char):

        count = 0
        for i in self.string:
            if i == char:
                count += 1

        return count

    def isPalindrome(self):

        for i in range(self.length):
            if self.string[i] != self.string[self.length - 1 - i]:
                return False
        return True

    def findChar(self,char):
        for i in range(self.length):
            if self.string[i] == char:
                return i
        return -1




    def find(self,sub):

        sub_len = 0
        charpos = []
        for i in sub:
            charpos += [self.findChar(i)]

        charpos_len = 0
        for i in charpos:
            charpos_len += 1

        for i in range(charpos_len - 1):
            if charpos[i + 1] - charpos[i] != 1:
                return -1


        return charpos[0]

    def countWord(self, w):

        word = self.words()
        count = 0
        for i in word:
            if i == w:
                count += 1
        return count

    def occurance(self):

        occur = []
        word = self.words()

        #finding distinct words
        for i in word:
            flag = True
            for j in occur:
                if i == j[0]:
                    flag = False
            if flag:
                occur += [[i]]

        #counting occurance of each distinct word
        for i in occur:
            i += [self.countWord(i[0])]

        return occur



string = input("Enter a string : ")

strOb = String(string)

print("Press 0 to exit\nPress 1 to display word with longest length")
print("Press 2 to determine frequency of occurance of particular character")
print("Press 3 for check whether given string is palindrome or not")
print("Press 4 for display index of first appearance of substring")
print("Press 5 for count occurence of each word")

ch = int(input("Enter your choice : "))

while ch != 0:

    if ch == 0:
        break

    if ch == 1:
        longest = strOb.longestWord()
        print("The longest word in the string is ", longest)

    elif ch == 2:
        char = input("Enter a character : ")
        count = strOb.charFreq(char)
        print("The frequency of the character ", char, " is ", count)

    elif ch == 3:
        if strOb.isPalindrome():
            print("Given String is palindrome")
        else:
            print("Given string is not a palindrome")

    elif ch == 4:
        sub = input("Enter a substring : ")
        index = strOb.find(sub)
        if index == -1:
            print("The given substring doesn' t exist in a string")

        else:
            print("The given substring exist at the index ", index)

    elif ch == 5:
        wordOccur = strOb.occurance()
        for i in wordOccur:
            print(i[0], " : ", i[1])

    else:
        print("Invalid Choice!!!")

    ch = int(input("Enter your choice : "))
