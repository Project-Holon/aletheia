/*
 * file:     compatible_irc_sys_p04.c
 * unit:     yes
 * function: func_021B678C, func_021B67B0, func_021B67C4, func_021B67E4
 * address:  0x021B678C
 * region:   ov101
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B6494 0x021B6494 thumb ov101
 */
typedef unsigned int   u32;

extern int func_021B6494(u32 p, u32 a, u32 b, u32 c);
int func_021B678C(int *p,int a,int b);
int func_021B67B0(int *p);
int func_021B67C4(int *p);
int func_021B67E4(int *p);

int func_021B678C(int *p,int a,int b) { p[5]=a; p[4]=b; return func_021B6494((u32)((int *)p[0]),0x1000,8,(u32)(p+4))!=0; }

int func_021B67B0(int *p) { if(p[6]==1) { p[6]=0; return 1; } return 0; }

int func_021B67C4(int *p) { int value; return func_021B6494((u32)((int *)p[0]),0x1001,4,(u32)(&value))!=0; }

int func_021B67E4(int *p) { if(p[7]==1) { p[7]=0; return 1; } return 0; }
