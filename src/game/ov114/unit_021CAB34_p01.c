/*
 * file:     unit_021CAB34_p01.c
 * unit:     yes
 * function: func_021CAB34, func_021CAB94, func_021CABC0, func_021CABDC, func_021CAC24, func_021CAC8C
 * address:  0x021CAB34
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
 *   bits  0x021CE202  data
 *   func_021CAE94  0x021CAE94  arm  ov114
 *   func_021CAAE8  0x021CAAE8  arm  ov114
 *   func_021CADAC  0x021CADAC  arm  ov114
 */
typedef unsigned long ulong;

typedef unsigned char u8;

typedef unsigned int u32;

typedef struct
{
    unsigned int *d;
    int top;
    int max;
} BIGNUM;

typedef struct
{
    int *data;
    int count;
} Stack;

extern void func_021CAE94(u8 *p);
extern void func_021CAAE8(void *);
extern BIGNUM *func_021CADAC(BIGNUM *, int);
int func_021CAB34(ulong l);
char *func_021CAB94(u8 *p);
void func_021CABC0(int a);
void func_021CABDC(u8 *p);
BIGNUM *func_021CAC24(BIGNUM *a, int n);
void func_021CAC8C(Stack *s);
extern const char bits[];


/*
 * sdk:      CRYPTOi__BN_num_bits_word (crypto_bobj1.o)
 *
 * The static nibble->bit-count table BN_num_bits_word::bits, 16 signed
 * bytes, is pinned at its image address rather than defined locally so the
 * pool word resolves to the vendor object's datum.
 */
int func_021CAB34(ulong l)
{
    int sh;
    if (l & 0xffff0000UL) {
        if (l & 0xff000000UL)
            sh = 24;
        else
            sh = 16;
    } else {
        if (l & 0xff00UL)
            sh = 8;
        else
            sh = 0;
    }
    l >>= sh;
    if (l & 0xf0)
        return bits[l >> 4] + sh + 4;
    return bits[l] + sh;
}


/*
 * Last element of the pointer table at p: resolves entry n-1 and offsets by n-1 records.
 */
char *func_021CAB94(u8 *p)
{
    u32 n = *(u32 *)(p + 4);
    u32 i;
    if (n == 0)
        return 0;
    i = n - 1;
    return (char *)(func_021CAB34(*(u32 *)(*(u8 **)p + i * 4)) + i * 0x20);
}


/*
 * Null-guarded flush: seals the pending batch, then drains `a`.
 */
void func_021CABC0(int a)
{
    if (a == 0)
        return;
    func_021CAE94((u8 *)a);
    func_021CABDC((u8 *)a);
}


/*
 * sdk:      CRYPTOi__BN_free (crypto_bobj1.o)
 * extra:    callee of CRYPTOi__BN_MONT_CTX_free / CRYPTOi__BN_RECP_CTX_free
 */
void func_021CABDC(u8 *p)
{
    if (p == 0)
        return;
    if (*(u32 *)p != 0 && !(*(u32 *)(p + 0x10) & 2))
        func_021CAAE8(*(void **)p);
    *(u32 *)(p + 0x10) |= 0x8000;
    if (*(u32 *)(p + 0x10) & 1)
        func_021CAAE8(p);
}


/*
 * sdk:      CRYPTOi__bn_zexpand (crypto_bobj1.o)
 *
 * bn_wexpand shape: grow to n words then zero the newly exposed words.
 */
BIGNUM *func_021CAC24(BIGNUM *a, int n)
{
    int i;
    if (a->top < n) {
        if ((n > a->max ? func_021CADAC(a, n) : a) == 0)
            return 0;
        if (a->d != 0) {
            for (i = a->top; i < n; i++)
                a->d[i] = 0;
        }
    }
    return a;
}


void func_021CAC8C(Stack *s)
{
    int *p;

    if (s->count <= 0)
        return;
    p = &s->data[s->count - 1];
    while (s->count > 0)
    {
        if (*p-- != 0)
            return;
        s->count--;
    }
}
