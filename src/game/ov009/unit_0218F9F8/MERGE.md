# unit_0218F9F8.c (ov009)

Translation unit 0218F9F8..021903B0, 20 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0218F9F8.c` is blocked by:

- ov009_func_0218F9F8.c..ov009_func_02190188.c: type struct GPIFindProfileByUserData differs between members (src/matched/ov_sdk/ov009_func_0218FF98.c); type struct GPIFindProfileData differs between members (src/matched/ov_sdk/ov009_func_0219008C.
- ov009_func_0218F9F8.c..ov009_func_0218FF24.c: c99=CCERR: line 372: illegal implicit conversion from 'struct GPIProfile **' to | line 372: 'struct GPIProfile_0218FD9C **' nolang=CCERR: line 372: illegal implicit conversion from 'struct GPIProfile 
- ov009_func_0218FCD8.c..ov009_func_0218FF24.c: c99=CCERR: line 54: struct/union/enum/class tag 'GPIProfile' redefined | line 199: illegal implicit conversion from 'struct GPIProfile **' to | line 199: 'struct  **' nolang=CCERR: line 54: struct/uni
- ov009_func_0218FCD8.c..ov009_func_0218FD9C.c: c99=CCERR: line 39: struct/union/enum/class tag 'GPIProfile' redefined | line 45: struct/union/enum/class tag 'GPIConnection' redefined nolang=CCERR: line 39: struct/union/enum/class tag 'GPIProfile' 
- ov009_func_0218FF38.c..ov009_func_02190188.c: type struct GPIFindProfileByUserData differs between members (src/matched/ov_sdk/ov009_func_0218FF98.c); type struct GPIFindProfileData differs between members (src/matched/ov_sdk/ov009_func_0219008C.
- ov009_func_0218FF38.c..ov009_func_0219003C.c: type struct GPIFindProfileByUserData differs between members (src/matched/ov_sdk/ov009_func_0218FF98.c)

Members, in address order:

- `ov009_func_0218FCD8.c`
- `ov009_func_0218FD9C.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_0218F9F8.c` again.
