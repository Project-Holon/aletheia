/*
 * file:     unit_021CAB34_p02.c
 * unit:     yes
 * function: func_021CACD0, func_021CACE4, func_021CAD1C
 * address:  0x021CACD0
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
 *   func_021CAAB4  0x021CAAB4  arm  ov114
 *   func_021CAD48  0x021CAD48  arm  ov114
 */
typedef unsigned char u8;

typedef unsigned int u32;

extern void func_02082BCC(int, int, int);
extern void *func_021CAAB4(unsigned long);
extern void func_021CAD48(u8 *);
void func_021CACD0(int a);
void *func_021CACE4(void);
void *func_021CAD1C(void);


/*
 * Thunk: func_02082BCC(a, 0, 20).
 */
void func_021CACD0(int a)
{
    func_02082BCC(a, 0, 0x14);
}


/*
 * sdk:      CRYPTOi__BN_new (crypto_bobj1.o)
 */
void *func_021CACE4(void)
{
    u8 *p = func_021CAAB4(0x14);
    if (p == 0)
        return 0;
    *(u32 *)(p + 0x10) = 1;
    *(u32 *)(p + 4) = 0;
    *(u32 *)(p + 0xc) = 0;
    *(u32 *)(p + 8) = 0;
    *(u32 *)p = 0;
    return p;
}


/*
 * sdk:      CRYPTOi__BN_CTX_new (crypto_bobj1.o)
 */
void *func_021CAD1C(void)
{
    u8 *p = func_021CAAB4(0x110);
    if (p == 0)
        return 0;
    func_021CAD48(p);
    *(u32 *)(p + 0x108) = 1;
    return p;
}
