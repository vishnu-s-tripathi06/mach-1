    
def count_words(text):
     counts=0
     for i in text.split():
          counts+=1
     return counts
def count_lines(text):
     line_count=0
     for i in text.splitlines():
          line_count+=1
     return line_count
def count_characters(text):
    character_count=0
    for i in text:
          character_count+=1
    return character_count

with open ("file2.txt","r") as file:
    text=file.read()
    print(f"number of words in file: {count_words(text)}")
    print(f"Number of lines: {count_lines(text)}")
    print(f"Total number of charactes: {count_characters(text)}")
    
          
