/*
 * file:     unit_0689ACCC.c
 * unit:     yes
 * function: func_0689ACCC, func_0689ACD8
 * address:  0x0689ACCC
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_0689ACEC 0x0689ACEC thumb ov095
 */
typedef unsigned char u8;

void func_02082BCC(void *p, int v, int n);
extern int func_0689ACEC(int, int, u8 *);
void func_0689ACCC(void *p);
void func_0689ACD8(u8 *p, int a, unsigned short b);


void func_0689ACCC(void *p)
{
    func_02082BCC(p, 0, 9);
}

/*
 * extent: Two bytes of alignment padding follow the return.
 */
void func_0689ACD8(u8 *p, int a, unsigned short b)
{
    p[0] = func_0689ACEC(a, b, p + 3);
}
