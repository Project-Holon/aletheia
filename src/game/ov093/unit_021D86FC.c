/*
 * file:     unit_021D86FC.c
 * unit:     yes
 * function: func_021D86FC, func_021D8734, func_021D8760, func_021D8794
 * address:  0x021D86FC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F07C8 0x021F07C8 data ov093 a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   func_0201C1E8 0x0201C1E8 thumb
 *   d_021F0740 0x021F0740 data ov093 a4
 *   func_021C8288 0x021C8288 thumb ov093
 *   d_021F05D8 0x021F05D8 data a4
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021D775C(int);
extern void func_021D7704(int,int);
extern int func_0201C1E8(int);
extern int func_021C8288(u8 *p);
void func_021D86FC(int a,int b,int c);
u8 *func_021D8728(u32 *p);
void func_021D8734(int a,int b,int c);
void func_021D8760(int a,int b,int c);
u8 *func_021D8788(u32 *p);
void func_021D8794(int a,int b,int c);
u8 *func_021D87BC(u32 *p);
extern u8 d_021F07C8[];
extern u8 d_021F0740[];
extern u8 d_021F05D8[];

void func_021D86FC(int a,int b,int c) { u8 k; if (c==func_021D775C(4)) { k=func_021D775C(22); if (k==14 || k==9) func_021D7704(53,2048); } }

u8 *func_021D8728(u32 *p) { *p=1; return d_021F07C8; }

void func_021D8734(int a,int b,int c) { if (c==func_021D775C(3)) { if (func_0201C1E8((u16)func_021D775C(18))==1) func_021D7704(53,8192); } }

void func_021D8760(int a,int b,int c) { if (c==func_021D775C(2)) { if (func_021C8288((u8 *)b)==2) func_021D7704(53,8192); } }

u8 *func_021D8788(u32 *p) { *p=1; return d_021F0740; }

void func_021D8794(int a,int b,int c) { if (c==func_021D775C(2)) { if (func_021C8288((u8 *)b)==1) func_021D7704(53,8192); } }

u8 *func_021D87BC(u32 *p) { *p=1; return d_021F05D8; }
