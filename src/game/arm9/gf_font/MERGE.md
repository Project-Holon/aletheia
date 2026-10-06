# gf_font.c (arm9)

Translation unit 0201CEE0..0201F53C, 104 functions, confidence likely (tools/tuboundary.py).

The member files below each match on their own. Merging them into one
`gf_font.c` is blocked by:

- func_0201CEE0.c..sub_0201F4A0.c: type struct PrintCtx differs between members (src/matched/arm9/sub_0201D110.c); prototype of func_0201DB20 differs between members (src/matched/arm9/unit_0201DAF0.c); prototype of func_0201DC44 differ
- func_0201CEE0.c..sub_0201DB20.c: prototype of func_0201DB20 differs between members (src/matched/arm9/unit_0201DAF0.c)
- func_0201D6D8.c..sub_0201DB20.c: prototype of func_0201DB20 differs between members (src/matched/arm9/unit_0201DAF0.c)
- unit_0201D9C8.c..sub_0201DB20.c: c99=CCERR: line 249: identifier 'func_0201DB20(struct Font_0201DAF0 *, unsigned short)' redeclared as 'unsigned int (struct Font_0201DB20 *, unsigned short)' | line 158: identifier 'func_0201DB20(stru
- func_0201DAA4.c..sub_0201DB20.c: c99=CCERR: line 135: identifier 'func_0201DB20(struct Font_0201DAF0 *, unsigned short)' redeclared as 'unsigned int (struct Font_0201DB20 *, unsigned short)' | line 95: identifier 'func_0201DB20(struc
- unit_0201DAF0.c..sub_0201DB20.c: c99=CCERR: line 95: identifier 'func_0201DB20(struct Font_0201DAF0 *, unsigned short)' redeclared as 'unsigned int (struct Font_0201DB20 *, unsigned short)' | line 74: identifier 'func_0201DB20(struct
- sub_0201DBBC.c..sub_0201F4A0.c: prototype of func_0201DC44 differs between members (src/matched/arm9/sub_0201DBF4.c); global g_02146578 declared two ways (src/matched/arm9/func_0201DE40.c); type struct FontState differs between memb
- sub_0201DBBC.c..func_0201E738.c: prototype of func_0201DC44 differs between members (src/matched/arm9/sub_0201DBF4.c); global g_02146578 declared two ways (src/matched/arm9/func_0201DE40.c); type struct FontState differs between memb
- sub_0201DBBC.c..unit_0201DD58.c: prototype of func_0201DC44 differs between members (src/matched/arm9/sub_0201DBF4.c)
- sub_0201DBBC.c..sub_0201DC44.c: prototype of func_0201DC44 differs between members (src/matched/arm9/sub_0201DBF4.c)
- sub_0201DBF4.c..sub_0201DC44.c: c99=CCERR: line 69: identifier 'func_0201DC44(struct Font_0201DBF4 *, const unsigned char *, unsigned int, void *, unsigned char *)' redeclared as 'void (struct Font_0201DC44 *, const unsigned char *,
- sub_0201DD78.c..func_0201E738.c: global g_02146578 declared two ways (src/matched/arm9/func_0201DE40.c); type struct FontState differs between members (src/matched/arm9/func_0201E538.c); global g_02146578 declared two ways (src/match
- sub_0201DD78.c..func_0201DE40.c: global g_02146578 declared two ways (src/matched/arm9/func_0201DE40.c)
- unit_0201DE00.c..func_0201DE40.c: global g_02146578 declared two ways (src/matched/arm9/func_0201DE40.c)
- sub_0201E4C8.c..func_0201E738.c: type struct FontState differs between members (src/matched/arm9/func_0201E738.c); prototype of func_0201E4C8 differs between members (src/matched/arm9/func_0201E738.c); prototype of sub_0201E4D4 diffe
- func_0201E928.c..sub_0201F4A0.c: prototype of func_0201ED84 differs between members (src/matched/arm9/unit_0201F020.c); prototype of func_0201EDD0 differs between members (src/matched/arm9/unit_0201F020.c); prototype of func_0201ED64
- func_0201E928.c..sub_0201F094.c: prototype of func_0201ED84 differs between members (src/matched/arm9/unit_0201F020.c); prototype of func_0201EDD0 differs between members (src/matched/arm9/unit_0201F020.c); prototype of func_0201ED64
- func_0201E928.c..func_0201EC74.c: c99=DIFF nolang=DIFF
- unit_0201EC64.c..func_0201EC74.c: c99=DIFF nolang=DIFF

Status after the merge-lane pass (same-settings runs merged greedily; the blocker list above may include entries already resolved):

Parts: gf_font_p01.c, gf_font_p02.c, gf_font_p03.c, gf_font_p04.c, gf_font_p05.c, gf_font_p06.c, gf_font_p07.c, gf_font_p08.c

Members still separate:

- `sub_0201DBF4.c`
