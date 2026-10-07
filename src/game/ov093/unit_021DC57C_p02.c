/*
 * file:     unit_021DC57C_p02.c
 * unit:     yes
 * function: func_021DC630, func_021DC664, func_021DC6A0
 * address:  0x021DC630
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
 *   d_021F06D0 0x021F06D0 data a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C8288 0x021C8288 thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   d_021F0628 0x021F0628 data a4
 *   func_021D76BC 0x021D76BC thumb ov093
 *   func_021DC6DC 0x021DC6DC thumb ov093
 *   func_021E8624 0x021E8624 thumb ov093
 */
typedef unsigned char  u8;

typedef unsigned short u16;

extern int func_021D775C(int);
extern int func_021C8288(u8 *p);
extern void func_021D7704(int,int);
extern int func_021D76BC(int,unsigned int);
extern int func_021DC6DC(u16);
extern int func_021E8624(int a, int b);
void func_021DC630(int a, void *b, int c);
void *func_021DC658(int *p);
void func_021DC664(int a, int b, int c);
void *func_021DC694(int *p);
void func_021DC6A0(int a, void *b, int c);
extern unsigned char d_021F06D0[];
extern unsigned char d_021F0628[];

void func_021DC630(int a, void *b, int c) { if (c == func_021D775C(2) && func_021C8288(b) == 4) func_021D7704(53,8192); }

void *func_021DC658(int *p) { *p = 1; return d_021F06D0; }

void func_021DC664(int a, int b, int c) { if (c == func_021D775C(4) && func_021D775C(26) == 0 && (unsigned int)func_021D775C(43) > 50) func_021D76BC(43,50); }

void *func_021DC694(int *p) { *p = 1; return d_021F0628; }

void func_021DC6A0(int a, void *b, int c) { if (c == func_021D775C(3) && func_021DC6DC(func_021D775C(18)) == 0 && func_021E8624((int)b,c) != 0) func_021D7704(49,0x14cd); }
