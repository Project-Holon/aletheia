/*
 * file:     fldeff_namipoke_p08.c
 * unit:     yes
 * function: func_021AD7A0, func_021AD7B4, func_021AD7E4
 * address:  0x021AD7A0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021ADA1C  0x021ADA1C  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   d_021DE0E8  0x021DE0E8  data
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_021AD8DC  0x021AD8DC  thumb  ov021
 *   func_021AD96C  0x021AD96C  thumb  ov021
 *   d_021DE094     0x021DE094  data  a2
 */
#define R(a) ((Rec *)((char *)(a) + 0x88))
struct Q;
struct Desc;
struct P;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct P { u32 f0; } P;

typedef struct Rec {
    u16 h[7];
} Rec;

extern void func_021ADA1C(struct Q *a);
extern u32 func_020307B0(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_021ABE24(u8 *p);
extern void func_021AD8DC(struct P *a, struct Desc *d, int c);
extern void func_021AD96C(struct P *a, struct Desc *d, int c);
void func_021AD7A0(u32 a, u8 *p);
P *func_021AD7B4(u32 a, int heap, u32 c);
void func_021AD7E4(int *a, u32 b);
extern char d_021DE0E8[];
extern Rec d_021DE094[];


/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021AD7A0(u32 a, u8 *p)
{
    func_021ADA1C((struct Q *)p);
    func_020307B0(p);
}


P *func_021AD7B4(u32 a, int heap, u32 c)
{
    P *p;

    p = (P *)func_02030734(heap, 0x98, 1, d_021DE0E8, 0x11e);
    p->f0 = a;
    func_021AD7E4((int *)p, c);
    return p;
}


void func_021AD7E4(int *a, u32 b)
{
    int t;

    *R(a) = d_021DE094[b];
    t = func_021ABE24((u8 *)(*a));
    if (b == 0) {
        func_021AD8DC((struct P *)a, (struct Desc *)R(a), t);
    } else {
        func_021AD96C((struct P *)a, (struct Desc *)R(a), t);
    }
}
