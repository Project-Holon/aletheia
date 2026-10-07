# camera_system.c (ov172)

Translation unit 021B6100..021B6A00, 84 functions, confidence weak (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`camera_system.c` is blocked by:

- ov172_func_021B6100.c..ov172_func_021B69F0.c: settings differ: src/matched/ov/ov172_func_021B62A8.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa
- ov172_func_021B6100.c..ov172_func_021B65D8.c: settings differ: src/matched/ov/ov172_func_021B62A8.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa
- ov172_func_021B6100.c..ov172_func_021B6390.c: settings differ: src/matched/ov/ov172_func_021B62A8.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa
- ov172_func_021B6100.c..ov172_func_021B62E8.c: settings differ: src/matched/ov/ov172_func_021B62A8.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa
- ov172_func_021B6100.c..ov172_func_021B62C0.c: settings differ: src/matched/ov/ov172_func_021B62A8.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa
- ov172_func_021B6100.c..ov172_func_021B62A8.c: settings differ: src/matched/ov/ov172_func_021B62A8.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa
- ov172_func_021B62F0.c..ov172_func_021B6390.c: settings differ: src/matched/ov/ov172_func_021B6338.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': '', 'isa': 'thumb'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa'
- ov172_func_021B6318.c..ov172_func_021B6390.c: settings differ: src/matched/ov/ov172_func_021B6338.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': '', 'isa': 'thumb'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa'
- ov172_func_021B6330.c..ov172_func_021B6390.c: settings differ: src/matched/ov/ov172_func_021B6338.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': '', 'isa': 'thumb'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa'
- ov172_func_021B6338.c..ov172_func_021B6390.c: settings differ: src/matched/ov/ov172_func_021B6390.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': '', 'isa': 
- ov172_func_021B6398.c..ov172_func_021B65D8.c: settings differ: src/matched/ov/ov172_func_021B63B8.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'i
- ov172_func_021B6398.c..ov172_func_021B6444.c: settings differ: src/matched/ov/ov172_func_021B63B8.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'i
- ov172_func_021B6398.c..ov172_func_021B63B8.c: settings differ: src/matched/ov/ov172_func_021B63B8.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'i
- ov172_func_021B63A8.c..ov172_func_021B63B8.c: settings differ: src/matched/ov/ov172_func_021B63B8.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'i
- ov172_func_021B63B0.c..ov172_func_021B63B8.c: settings differ: src/matched/ov/ov172_func_021B63B8.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'i
- ov172_func_021B644C.c..ov172_func_021B65D8.c: settings differ: src/matched/ov/ov172_func_021B649C.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': '', 'isa': 
- ov172_func_021B644C.c..ov172_func_021B655C.c: settings differ: src/matched/ov/ov172_func_021B649C.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': '', 'isa': 
- ov172_func_021B644C.c..ov172_func_021B649C.c: settings differ: src/matched/ov/ov172_func_021B649C.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': '', 'isa': 
- ov172_func_021B64A4.c..ov172_func_021B655C.c: settings differ: src/matched/ov/ov172_func_021B64AC.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'i
- ov172_func_021B64AC.c..ov172_func_021B655C.c: settings differ: src/matched/ov/ov172_func_021B655C.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa
- ov172_func_021B6564.c..ov172_func_021B65D8.c: settings differ: src/matched/ov/ov172_func_021B657C.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': '', 'isa': 'thumb'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa'
- ov172_func_021B6608.c..ov172_func_021B69F0.c: settings differ: src/matched/ov/ov172_func_021B6620.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'i
- ov172_func_021B6608.c..ov172_func_021B6860.c: settings differ: src/matched/ov/ov172_func_021B6620.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'i
- ov172_func_021B6608.c..ov172_func_021B6724.c: settings differ: src/matched/ov/ov172_func_021B6620.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'i
- ov172_func_021B6608.c..ov172_func_021B662C.c: settings differ: src/matched/ov/ov172_func_021B6620.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'i
- ov172_func_021B6618.c..ov172_func_021B662C.c: settings differ: src/matched/ov/ov172_func_021B6620.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'i
- ov172_func_021B6698.c..ov172_func_021B6724.c: settings differ: src/matched/ov/ov172_func_021B66B0.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': '', 'isa': 'thumb'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa'
- ov172_func_021B66A8.c..ov172_func_021B6724.c: settings differ: src/matched/ov/ov172_func_021B66B0.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': '', 'isa': 'thumb'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa'
- ov172_func_021B66B0.c..ov172_func_021B6724.c: settings differ: src/matched/ov/ov172_func_021B6724.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': '', 'isa': 
- ov172_func_021B672C.c..ov172_func_021B6860.c: settings differ: src/matched/ov/ov172_func_021B6744.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'i
- ov172_func_021B672C.c..ov172_func_021B674C.c: settings differ: src/matched/ov/ov172_func_021B6744.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'i
- ov172_func_021B673C.c..ov172_func_021B674C.c: settings differ: src/matched/ov/ov172_func_021B6744.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'i
- ov172_func_021B67BC.c..ov172_func_021B6860.c: settings differ: src/matched/ov/ov172_func_021B680C.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': '', 'isa': 
- ov172_func_021B67BC.c..ov172_func_021B6814.c: settings differ: src/matched/ov/ov172_func_021B680C.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': '', 'isa': 
- ov172_func_021B680C.c..ov172_func_021B6814.c: settings differ: src/matched/ov/ov172_func_021B6814.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'i
- ov172_func_021B6868.c..ov172_func_021B69F0.c: settings differ: src/matched/ov/ov172_func_021B6884.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa
- ov172_func_021B6868.c..ov172_func_021B6944.c: settings differ: src/matched/ov/ov172_func_021B6884.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa
- ov172_func_021B6868.c..ov172_func_021B6918.c: settings differ: src/matched/ov/ov172_func_021B6884.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa
- ov172_func_021B6868.c..ov172_func_021B6884.c: settings differ: src/matched/ov/ov172_func_021B6884.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa
- ov172_func_021B688C.c..ov172_func_021B6918.c: settings differ: src/matched/ov/ov172_func_021B6918.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa
- ov172_func_021B68A0.c..ov172_func_021B6918.c: settings differ: src/matched/ov/ov172_func_021B6918.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': '', 'isa': 
- ov172_func_021B6920.c..ov172_func_021B6944.c: settings differ: src/matched/ov/ov172_func_021B6938.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'i
- ov172_func_021B6930.c..ov172_func_021B6944.c: settings differ: src/matched/ov/ov172_func_021B6938.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'i
- ov172_func_021B6950.c..ov172_func_021B69F0.c: settings differ: src/matched/ov/ov172_func_021B6974.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa
- ov172_func_021B6950.c..ov172_func_021B699C.c: settings differ: src/matched/ov/ov172_func_021B6974.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa
- ov172_func_021B6950.c..ov172_func_021B6974.c: settings differ: src/matched/ov/ov172_func_021B6974.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa
- ov172_func_021B697C.c..ov172_func_021B699C.c: settings differ: src/matched/ov/ov172_func_021B6994.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'arm'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa
- ov172_func_021B6994.c..ov172_func_021B699C.c: settings differ: src/matched/ov/ov172_func_021B699C.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'i
- ov172_func_021B69B4.c..ov172_func_021B69F0.c: settings differ: src/matched/ov/ov172_func_021B69BC.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'i
- ov172_func_021B69B4.c..ov172_func_021B69D0.c: settings differ: src/matched/ov/ov172_func_021B69BC.c has {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'isa': 'thumb'}, first member {'compiler': '1.1p1', 'flags': '-O4,p', 'lang': 'c99', 'i

Members, in address order:

- `ov172_func_021B6100.c`
- `ov172_func_021B62A8.c`
- `ov172_func_021B6330.c`
- `ov172_func_021B6338.c`
- `ov172_func_021B6390.c`
- `ov172_func_021B63A8.c`
- `ov172_func_021B63B0.c`
- `ov172_func_021B63B8.c`
- `ov172_func_021B644C.c`
- `ov172_func_021B649C.c`
- `ov172_func_021B64A4.c`
- `ov172_func_021B64AC.c`
- `ov172_func_021B655C.c`
- `ov172_func_021B6618.c`
- `ov172_func_021B66A8.c`
- `ov172_func_021B66B0.c`
- `ov172_func_021B6724.c`
- `ov172_func_021B673C.c`
- `ov172_func_021B67BC.c`
- `ov172_func_021B680C.c`
- `ov172_func_021B6814.c`
- `ov172_func_021B6868.c`
- `ov172_func_021B6884.c`
- `ov172_func_021B688C.c`
- `ov172_func_021B68A0.c`
- `ov172_func_021B6918.c`
- `ov172_func_021B6930.c`
- `ov172_func_021B6950.c`
- `ov172_func_021B6974.c`
- `ov172_func_021B697C.c`
- `ov172_func_021B6994.c`
- `ov172_func_021B699C.c`
- `ov172_func_021B69B4.c`

To merge: give each listed global and function one declaration that every
member compiles against byte-exact, then run
`python tools/restructure.py --proposal <tsv> --names camera_system.c` again.
