from hello import hello_welt

def hello_test(str):
    if str == "Hello Welt":
        print ("Das Programm ist richtig")
    else:
        print("das programm es fasch es gibt 'str' heraus")
    return 0

hello_test(hello_welt())
