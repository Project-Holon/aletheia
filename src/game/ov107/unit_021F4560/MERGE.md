# unit_021F4560.c (ov107)

Translation unit 021F4560..021F636C, 27 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021F4560.c` is blocked by:

- ov107_func_021F4560.c..ov107_func_021F6334.c: global d_021F6F90 declared two ways (src/matched/ov_sdk/ov107_func_021F46C8.c); global mbi_life_mp declared two ways (src/matched/ov_sdk/ov107_func_021F46C8.c); prototype of WM_StartMPEx differs betwe
- ov107_func_021F4560.c..ov107_func_021F5CAC.c: global d_021F6F90 declared two ways (src/matched/ov_sdk/ov107_func_021F46C8.c); global mbi_life_mp declared two ways (src/matched/ov_sdk/ov107_func_021F46C8.c); prototype of WM_StartMPEx differs betwe
- ov107_func_021F4560.c..ov107_func_021F4E9C.c: global d_021F6F90 declared two ways (src/matched/ov_sdk/ov107_func_021F46C8.c); global mbi_life_mp declared two ways (src/matched/ov_sdk/ov107_func_021F46C8.c)
- ov107_func_021F4684.c..ov107_func_021F4E9C.c: global d_021F6F90 declared two ways (src/matched/ov_sdk/ov107_func_021F46C8.c)
- ov107_func_021F4EFC.c..ov107_func_021F5CAC.c: prototype of MI_CpuCopy8 differs between members (src/matched/ov_sdk/ov107_func_021F5904.c)
- ov107_func_021F4EFC.c..ov107_func_021F5904.c: prototype of MI_CpuCopy8 differs between members (src/matched/ov_sdk/ov107_func_021F5904.c)
- ov107_func_021F589C.c..ov107_func_021F5904.c: c99=DIFF nolang=DIFF
- ov107_func_021F5E7C.c..ov107_func_021F6334.c: global d_021F6F90 declared two ways (src/matched/ov_sdk/ov107_func_021F6334.c)
- ov107_func_021F5E7C.c..ov107_func_021F6148.c: c99=DIFF nolang=DIFF
- ov107_func_021F5E7C.c..ov107_func_021F5EE4.c: c99=DIFF nolang=DIFF
- ov107_func_021F5EA0.c..ov107_func_021F5EE4.c: c99=DIFF nolang=DIFF
- ov107_func_021F6158.c..ov107_func_021F6334.c: global d_021F6F90 declared two ways (src/matched/ov_sdk/ov107_func_021F6334.c)
- ov107_func_021F62A0.c..ov107_func_021F6334.c: global d_021F6F90 declared two ways (src/matched/ov_sdk/ov107_func_021F6334.c)
- ov107_func_021F6314.c..ov107_func_021F6334.c: global d_021F6F90 declared two ways (src/matched/ov_sdk/ov107_func_021F6334.c)
- no verified entry for 021F5ED8

Members, in address order:

- `ov107_func_021F4684.c`
- `ov107_func_021F4EFC.c`
- `ov107_func_021F589C.c`
- `ov107_func_021F5904.c`
- `ov107_func_021F5E7C.c`
- `ov107_func_021F5EA0.c`
- `ov107_func_021F5EE4.c`
- `ov107_func_021F6314.c`
- `ov107_func_021F6334.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021F4560.c` again.
