def main():
    inputted_greeting = input("Greeting: ")
    penalty = value(inputted_greeting)
    print(f"${penalty}")


def value(greeting):
    greeting = str(greeting.lower().strip())
    if greeting.startswith("hello"):
        return 0
    elif greeting.startswith('h'):
        return 20
    else:
        return 100


if __name__ == "__main__":
    main()