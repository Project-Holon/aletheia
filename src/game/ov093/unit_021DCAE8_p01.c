/*
 * file:     unit_021DCAE8_p01.c
 * unit:     yes
 * function: func_021DCC10, func_021DCC2C, func_021DCC5C
 * address:  0x021DCC10
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
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   d_021F0708 0x021F0708 data a4
 *   func_021D76BC 0x021D76BC thumb ov093
 *   func_021DCC80 0x021DCC80 thumb ov093
 */
extern int func_021D775C(int);
extern void func_021D7704(int,int);
extern int func_021D76BC(int,unsigned int);
extern void func_021DCC80(void *,void *,int,int *);
void func_021DCC10(int a, int b, int c);
void func_021DCC2C(int a, int b, int c, int *d);
void *func_021DCC50(int *p);
void func_021DCC5C(void *a,void *b,int c,int *d);
extern unsigned char d_021F0708[];

/*
 * extent: trailing two-byte zero alignment at 021DCC2A.
 */
void func_021DCC10(int a, int b, int c) { if (c == func_021D775C(2)) func_021D7704(0x35, 2048); }

void func_021DCC2C(int a, int b, int c, int *d) { if (c == func_021D775C(2)) *d = func_021D76BC(32,-func_021D775C(32)); }

void *func_021DCC50(int *p) { *p = 1; return d_021F0708; }

void func_021DCC5C(void *a,void *b,int c,int *d) { if(c==func_021D775C(2)) func_021DCC80(a,b,c,d); }
