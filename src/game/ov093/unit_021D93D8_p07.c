/*
 * file:     unit_021D93D8_p07.c
 * unit:     yes
 * function: func_021D99F8, func_021D9A24
 * address:  0x021D99F8
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
 *   d_021F0CEC 0x021F0CEC data a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D76BC 0x021D76BC thumb ov093
 *   func_021E85F8 0x021E85F8 thumb ov093
 */
extern int func_021D775C(int);
extern int func_021D76BC(int, unsigned int);
extern int func_021E85F8(int);
void func_021D99F8(int a,int b,int c);
void *func_021D9A18(int *p);
void func_021D9A24(int a,int b,int c);
extern unsigned int d_021F0CEC;

void func_021D99F8(int a,int b,int c) { if(func_021E85F8(c)!=0 && func_021D775C(5)==1) func_021D76BC(0x47,1); }

void *func_021D9A18(int *p) { *p=5; return &d_021F0CEC; }

void func_021D9A24(int a,int b,int c) { unsigned short v; if(c==func_021D775C(3)) { v=func_021D775C(0x26)*2; func_021D76BC(0x26,v); } }
