/*
 * file:     unit_021CAB34_p04.c
 * unit:     yes
 * function: func_021CAE20, func_021CAE94, func_021CAEC8
 * address:  0x021CAE20
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
 *   func_021CADAC  0x021CADAC  arm  ov114
 *   func_02082D44  0x02082D44  arm
 *   func_02082BCC  0x02082BCC  arm
 */
typedef unsigned char u8;

typedef unsigned int u32;

extern u8 *func_021CADAC(u8 *a, int n);
extern void func_02082D44(void *, void *, unsigned long);
extern void func_02082BCC(void *, int, unsigned long);
u8 *func_021CAE20(u8 *a, u8 *b);
void func_021CAE94(u8 *p);
int func_021CAEC8(u8 *a, unsigned long w);


/*
 * sdk:      CRYPTOi__BN_copy (crypto_bobj1.o)
 * extra:    callee of CRYPTOi__BN_RECP_CTX_set
 */
u8 *func_021CAE20(u8 *a, u8 *b)
{
    u8 *A;
    if (a == b)
        return a;
    A = (*(int *)(b + 4) <= *(int *)(a + 8)) ? a : func_021CADAC(a, *(int *)(b + 4));
    if (A == 0)
        return 0;
    func_02082D44(*(void **)b, *(void **)a, *(int *)(b + 4) * 4);
    {
        int t = *(int *)(b + 4);
        *(int *)(a + 4) = t;
        if (t == 0) {
            if (*(void **)a != 0)
                *(u32 *)*(void **)a = 0;
        }
    }
    *(int *)(a + 0xc) = *(int *)(b + 0xc);
    return a;
}


/*
 * sdk:      CRYPTOi__BN_clear (crypto_bobj1.o)
 */
void func_021CAE94(u8 *p)
{
    if (*(void **)p != 0)
        func_02082BCC(*(void **)p, 0, *(u32 *)(p + 8) * 4);
    *(u32 *)(p + 4) = 0;
    *(u32 *)(p + 0xc) = 0;
}


/*
 * sdk:      CRYPTOi__BN_set_word (crypto_bobj1.o)
 * extra:    callee of CRYPTOi__BN_RECP_CTX_set
 */
int func_021CAEC8(u8 *a, unsigned long w)
{
    u8 *A;
    A = (*(int *)(a + 8) < 1) ? func_021CADAC(a, 2) : a;
    if (A == 0)
        return 0;
    *(u32 *)(a + 0xc) = 0;
    *(u32 *)(a + 4) = 0;
    *(u32 *)*(u32 **)a = w;
    if (*(u32 *)*(u32 **)a != 0)
        *(u32 *)(a + 4) = 1;
    return 1;
}
