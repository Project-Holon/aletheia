# unit_0206EB7C.c (arm9)

Translation unit 0206EB7C..0207010C, 12 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`unit_0206EB7C.c` is blocked by:

- func_0206EB7C.c..func_0206FFA0.c: settings differ: src/matched/arm9/func_0206EBB8.c has {'compiler': '../2.0/sp2', 'flags': '-O4,p -proc arm946e', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lan
- func_0206EB7C.c..func_0206F214.c: settings differ: src/matched/arm9/func_0206EBB8.c has {'compiler': '../2.0/sp2', 'flags': '-O4,p -proc arm946e', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lan
- func_0206EB7C.c..func_0206EC50.c: settings differ: src/matched/arm9/func_0206EBB8.c has {'compiler': '../2.0/sp2', 'flags': '-O4,p -proc arm946e', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lan
- func_0206EBB8.c..func_0206EC50.c: c99=CCERR: line 38: identifier 'Root' redeclared | line 38: was declared as: 'struct ' | line 38: now declared as: 'struct Root' nolang=CCERR: line 38: identifier 'Root' redeclared | line 38: was decl
- func_0206ECE0.c..func_0206F214.c: global g_02148DB0 declared two ways (src/matched/arm9/func_0206EE60.c)
- func_0206EE60.c..func_0206F214.c: c99=CCERR: line 107: illegal implicit conversion from 'unsigned int *' to | line 107: 'int *' | line 116: illegal implicit conversion from 'unsigned int *' to nolang=CCERR: line 107: illegal implicit 
- func_0206F36C.c..func_0206FFA0.c: settings differ: src/matched/arm9/func_0206F4C8.c has {'compiler': '../2.0/sp2p2', 'flags': '-O4,p -proc arm946e', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '../2.0/sp2', 'flags': '-O4,p
- func_0206F36C.c..func_0206F6B0.c: settings differ: src/matched/arm9/func_0206F4C8.c has {'compiler': '../2.0/sp2p2', 'flags': '-O4,p -proc arm946e', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '../2.0/sp2', 'flags': '-O4,p
- func_0206F4C8.c..func_0206F6B0.c: settings differ: src/matched/arm9/func_0206F6B0.c has {'compiler': '../2.0/sp2', 'flags': '-O4,p -proc arm946e', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '../2.0/sp2p2', 'flags': '-O4,p
- func_0206F844.c..func_0206FFA0.c: settings differ: src/matched/arm9/func_0206FC5C.c has {'compiler': '../2.0/sp2', 'flags': '-O4,p -proc arm946e', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '../2.0/sp2p2', 'flags': '-O4,p
- func_0206FC5C.c..func_0206FFA0.c: settings differ: src/matched/arm9/func_0206FFA0.c has {'compiler': '../2.0/sp2p2', 'flags': '-O4,p -proc arm946e', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '../2.0/sp2', 'flags': '-O4,p

Status after the merge-lane pass (same-settings runs merged greedily; the blocker list above may include entries already resolved):

Parts: 

Members still separate:

- `func_0206EB7C.c`
- `func_0206EBB8.c`
- `func_0206EC50.c`
- `func_0206ECE0.c`
- `func_0206EE60.c`
- `func_0206F214.c`
- `func_0206F36C.c`
- `func_0206F4C8.c`
- `func_0206F6B0.c`
- `func_0206F844.c`
- `func_0206FC5C.c`
- `func_0206FFA0.c`
