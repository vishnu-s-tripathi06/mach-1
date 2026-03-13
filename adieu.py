import inflect
p=inflect.engine()
name_list=[]
def main():
   while True:
        try:

            name=input("input: ").strip().title()
            name_list.append(name)
        except EOFError:
            print("Adieu, adieu, to" ,p.join(name_list))
            break



main()
