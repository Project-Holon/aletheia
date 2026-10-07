/*
 * file:     unit_021DB0E4_p02.c
 * unit:     yes
 * function: func_021DB224, func_021DB254, func_021DB274, func_021DB298, func_021DB2B8
 * address:  0x021DB224
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
 *   d_021F0C24 0x021F0C24 data a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7324 0x021D7324 thumb ov093
 *   func_021C8288 0x021C8288 thumb ov093
 *   func_021DB374 0x021DB374 thumb ov093
 *   func_021DB318 0x021DB318 thumb ov093
 */
typedef unsigned char  u8;

extern int func_021D775C(int);
extern void func_021D7324(u8 *p);
extern int func_021C8288(u8 *p);
extern void func_021DB374(void *,int,unsigned int);
extern void func_021DB318(int, void *, int);
void func_021DB224(char *a, int b, int c, int *d);
const unsigned int *func_021DB248(int *n);
void func_021DB254(int a, void *b, int c, int *d);
void func_021DB274(int a, void *b, int c, int *d);
void func_021DB298(int a, void *b, int c, int *d);
void func_021DB2B8(int a, void *b, int c, int *d);
extern const unsigned int d_021F0C24[];

void func_021DB224(char *a, int b, int c, int *d) { if (c == func_021D775C(2) && *d == 1) { func_021D7324((u8 *)a); *d = 0; } }

const unsigned int *func_021DB248(int *n) { *n = 5; return d_021F0C24; }


void func_021DB254(int a, void *b, int c, int *d)
{
    func_021DB374(b, c, func_021C8288(b));
    *d = 1;
}


void func_021DB274(int a, void *b, int c, int *d)
{
    if (c == func_021D775C(2)) func_021DB254(a, b, c, d);
}


void func_021DB298(int a, void *b, int c, int *d)
{
    if (*d != 0) func_021DB374(b, c, func_021C8288(b));
}


void func_021DB2B8(int a, void *b, int c, int *d)
{
    if (*d != 0) func_021DB318(a, b, c);
}
