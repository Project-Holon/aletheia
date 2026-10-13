/*
 * function: func_021EB988
 * address:  0x021EB988
 * packet:   pkt_ov170_021EB988
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BGWINFRM_GetSize 0x0202CFC0 thumb
 *   func_021EB6D8 0x021EB6D8 thumb
 *   BGWINFRM_ChangePalette 0x0202CE50 thumb
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_021EAAE4 0x021EAAE4 thumb
 */

typedef struct {
    unsigned short a;
    unsigned short b;
} Ent;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
struct WinMgr;
extern void BGWINFRM_GetSize(struct WinMgr *mgr, u32 idx, u16 *w, u16 *h);
extern void func_021EB6D8(int a, int b, int c, int d);
extern void BGWINFRM_ChangePalette(struct WinMgr *mgr, u32 idx, s32 x, s32 y, u8 w, u8 h, u8 pal);
struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void func_021EAAE4(unsigned char *p, unsigned i);

#define WORK(p) (*(char **)((p) + 0x2C))
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))

void func_021EB988(char *p, Ent *e, unsigned n)
{
    unsigned short w;
    unsigned short h;
    unsigned i = 0;
    BGWINFRM_GetSize(MGR(p), 0, &w, &h);
    for (i = 0; i < n; i++) {
        Ent *x = &e[n - 1 - i];
        if (x->b == 0)
            func_021EB6D8((int)p, 0x13 - i, x->a, 0);
        else
            func_021EB6D8((int)p, 0x13 - i, x->a, 1);
        BGWINFRM_ChangePalette(MGR(p), 5 - i, 0, 0, w, h, 0xC);
    }
    for (; n < 6; n++) {
        unsigned k = 0x13 - n;
        BMP_Clear(func_02045770(*(void **)(WORK(p) + k * 8 + 0x94)), 0);
        func_021EAAE4((unsigned char *)WORK(p), k);
    }
}
