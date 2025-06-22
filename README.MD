# C-Programming Practice

### This repository contains all the basic code of C language.

~~~
1. Variables
2. Flow control
3. Functions
4. Macros
5. Enums
6. Arrays
7. Strings
8. Pointers
~~~

```
Pointer Operations:
    char charArr[] = "Any String";
    for(int i = 0; i < strlen(charArr); i++){
        printf("charArr[%d] = %c\t*(p+%d) = %c\t&charArr[%d] = %p\tp+%d = %p\n",
            i,charArr[i],i,*(p+i),i,&charArr[i],i,p+i 
        );
    }

    Output:
    charArr[0] = A  *(p+0) = A      &charArr[0] = 0x7fff3d1999ad    p+0 = 0x7fff3d1999ad
    charArr[1] = n  *(p+1) = n      &charArr[1] = 0x7fff3d1999ae    p+1 = 0x7fff3d1999ae
    charArr[2] = y  *(p+2) = y      &charArr[2] = 0x7fff3d1999af    p+2 = 0x7fff3d1999af
    charArr[3] =    *(p+3) =        &charArr[3] = 0x7fff3d1999b0    p+3 = 0x7fff3d1999b0
    charArr[4] = S  *(p+4) = S      &charArr[4] = 0x7fff3d1999b1    p+4 = 0x7fff3d1999b1
    charArr[5] = t  *(p+5) = t      &charArr[5] = 0x7fff3d1999b2    p+5 = 0x7fff3d1999b2
    charArr[6] = r  *(p+6) = r      &charArr[6] = 0x7fff3d1999b3    p+6 = 0x7fff3d1999b3
    charArr[7] = i  *(p+7) = i      &charArr[7] = 0x7fff3d1999b4    p+7 = 0x7fff3d1999b4
    charArr[8] = n  *(p+8) = n      &charArr[8] = 0x7fff3d1999b5    p+8 = 0x7fff3d1999b5
    charArr[9] = g  *(p+9) = g      &charArr[9] = 0x7fff3d1999b6    p+9 = 0x7fff3d1999b6
```

...and many more to come as I understand them and do practice of those topics.