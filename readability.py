text = input("text: ")
def letters():
    count = 0
    
    for word in text:
        if word.isalpha():
            count += 1 
    return count

def words():
	words = len(text.split())
	return words

def sentences():
    count = 0
    for word in text:
    	for char in word:
    		if char in [".","?","!"]:
    		    count += 1
    return count		    


letters = letters()
words = words()
sentences = sentences()
    
def readability():
    L = (100*letters)/words
    S = (100*sentences)/words
    index = round(0.0588 * L - 0.296 * S - 15.8)
    return index

def grade():    
    grade = readability()
    if grade >= 1 and grade < 16:
        print(f"Grade {grade}")
    elif grade < 1:
        print("Before Grade 1")
    elif grade >= 16:
        print("Grade 16+")

grade()