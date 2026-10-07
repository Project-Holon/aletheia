# unit_021D0B44.c (ov016)

Translation unit 021D0B44..021D1208, 8 functions, confidence proven (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_021D0B44.c` is blocked by:

- ov016_func_021D0B44.c..ov016_func_021D10D8.c: global g_021DE654 declared two ways (src/matched/ov_sdk/ov016_func_021D0CB8.c); global g_021DE654 declared two ways (src/matched/ov_sdk/ov016_func_021D0CEC.c)
- ov016_func_021D0B44.c..func_021D0DC8.c: global g_021DE654 declared two ways (src/matched/ov_sdk/ov016_func_021D0CB8.c); global g_021DE654 declared two ways (src/matched/ov_sdk/ov016_func_021D0CEC.c)
- ov016_func_021D0B44.c..ov016_func_021D0CB8.c: global g_021DE654 declared two ways (src/matched/ov_sdk/ov016_func_021D0CB8.c)
- ov016_func_021D0DE0.c..ov016_func_021D10D8.c: c99=CCERR: line 28: the file '../arm9_sdk/libc/memcmp/string.h' cannot be opened | line 80: identifier 'MemUsbT' redeclared | line 80: was declared as: 'struct ' nolang=CCERR: line 28: the file '../ar
- ov016_func_021D0DE0.c..ov016_func_021D0E74.c: c99=CCERR: line 78: identifier 'MemUsbT' redeclared | line 78: was declared as: 'struct ' | line 78: now declared as: 'struct ' nolang=CCERR: line 78: identifier 'MemUsbT' redeclared | line 78: was de
- ov016_func_021D0FCC.c..ov016_func_021D10D8.c: c99=CCERR: line 24: the file '../arm9_sdk/libc/memcmp/string.h' cannot be opened | line 83: identifier 'MemUsbT' redeclared | line 83: was declared as: 'struct ' nolang=CCERR: line 24: the file '../ar

Members, in address order:

- `ov016_func_021D0B44.c`
- `ov016_func_021D0CB8.c`
- `ov016_func_021D0DE0.c`
- `ov016_func_021D0E74.c`
- `ov016_func_021D0FCC.c`
- `ov016_func_021D10D8.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names unit_021D0B44.c` again.
