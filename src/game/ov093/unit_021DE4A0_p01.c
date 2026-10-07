/*
 * file:     unit_021DE4A0_p01.c
 * unit:     yes
 * function: func_021DE4C4, func_021DE4F4
 * address:  0x021DE4C4
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
 *   func_021DCFF8 0x021DCFF8 thumb ov093
 *   func_021D76BC 0x021D76BC thumb ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

extern int func_021D775C(int);
extern int func_021DCFF8(int,int);
extern int func_021D76BC(int,u32);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
void func_021DE4C4(int a, int b, int c);
void func_021DE4F4(int a, void *b, int c);

/*
 * extent: two-byte alignment padding at 021DE4F2.
 * lever: u8 result local narrows in r0 before copying to r1; twin 021DE3FC.
 */
void func_021DE4C4(int a, int b, int c) { u8 j; if(c == func_021D775C(3) && func_021D775C(0x25)==0) { j=func_021DCFF8(a,2); func_021D76BC(0x26,j); } }


void func_021DE4F4(int a, void *b, int c)
{
    u8 *m;

    if (c == func_021D775C(2)) {
        m = (u8 *)func_021C88A4(b, 0x2b, c);
        m[4] = c;
        m[5] = 100;
        func_021C88C8(b, m);
    }
}
