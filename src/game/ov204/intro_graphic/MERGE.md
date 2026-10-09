# intro_graphic: still split in two parts (r3_ov10 recheck)

Parts: intro_graphic_p01.c (0x021BDA40..) and intro_graphic_p02.c (0x021BDDF8..).
Boundary p01|p02: func_021BDFA4 and func_021BE03C (p02) take u8 heap and use it without narrowing.
Tried by r3_ov10: heap of func_021BDC18 as u8 (like the ov203 demo3d_graphic fix) and a char * cast for the p+8 arguments: it compiles, but func_021BDA40 (p01) then calls func_021BDC18 with the u16 field Obj00689.f0 and the compiler adds a narrowing lsls/lsrs pair (+4 bytes, everything after shifts). The original caller passes the u16 without narrowing, so it saw no u8 prototype. Boundary stays; probably two source files.
Round 6 (lane s_mid2): tried deleting the prototypes of func_021BDFA4 and func_021BE03C before the callers (implicit call). mwcc c99 rejects
it ("redeclared as void (char *, unsigned char)", originally declared as int (...)), also with an int return type. Boundary stays.
