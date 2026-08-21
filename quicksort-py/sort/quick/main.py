from sort.quick.quicksort import quicksort

# python -m sort.quick.main

def beispieleins():
    liste = [0,-1,2,-3,1]
    geordnet = quicksort(liste)
    print(geordnet)

def main():
    beispieleins()

if __name__ == "__main__":
    main()
