/*
 * file:     unit_021CAB34_p03.c
 * unit:     yes
 * function: func_021CAD48, func_021CAD6C, func_021CADAC
 * address:  0x021CAD48
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021CABC0  0x021CABC0  arm  ov114
 *   func_021CAAE8  0x021CAAE8  arm  ov114
 *   func_021CAAB4  0x021CAAB4  arm  ov114
 *   func_02082D44  0x02082D44  arm
 */
typedef unsigned char u8;

typedef unsigned int u32;

extern void func_02082BCC(void *, int, int);
extern void func_021CABC0(int a);
extern void func_021CAAE8(void *);
extern void *func_021CAAB4(unsigned long);
extern void func_02082D44(void *, void *, unsigned long);
void func_021CAD48(u8 *p);
void func_021CAD6C(u8 *ctx);
u8 *func_021CADAC(u8 *a, int n);


/*
 * Clears a 0x110-byte record and both of its end markers.
 */
void func_021CAD48(u8 *p)
{
    func_02082BCC(p, 0, 0x110);
    *(u32 *)p = 0;
    *(u32 *)(p + 0x108) = 0;
}


/*
 * sdk:      CRYPTOi__BN_CTX_free (crypto_bobj1.o)
 *
 * The twelve BIGNUMs embedded at ctx+4 (stride 20) are cleared, then the
 * context itself is released when its malloc flag is set.
 */
void func_021CAD6C(u8 *ctx)
{
    int i;
    for (i = 0; i < 12; i++)
        func_021CABC0((int)(ctx + 4 + i * 20));
    if (*(unsigned int *)(ctx + 0x108) & 1)
        func_021CAAE8(ctx);
}


u8 *func_021CADAC(u8 *a, int n)
{
    if (n > *(int *)(a + 8)) {
        u8 *newd;
        if (*(u32 *)(a + 0x10) & 2)
            return 0;
        newd = func_021CAAB4((n + 1) * 4);
        if (newd == 0)
            return 0;
        if (*(void **)a != 0) {
            func_02082D44(*(void **)a, newd, *(int *)(a + 4) * 4);
            func_021CAAE8(*(void **)a);
        }
        *(void **)a = newd;
        *(int *)(a + 8) = n;
    }
    return a;
}
