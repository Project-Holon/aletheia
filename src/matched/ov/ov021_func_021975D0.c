/*
 * function: func_021975D0
 * address:  0x021975D0
 * packet:   pkt_ov021_021975D0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Per-frame poll of the object at +0x2B4; returns 1 when it is absent.
 *
 * symbols:
 *   func_020286C4  0x020286C4  thumb
 *   func_0201CE30  0x0201CE30  thumb
 *   func_0201CE48  0x0201CE48  thumb
 *   func_0201CE38  0x0201CE38  thumb
 *   func_0201CE5C  0x0201CE5C  thumb
 *   func_02035C60  0x02035C60  arm
 *   func_02035C38  0x02035C38  arm
 *   func_020061E4  0x020061E4  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Ctx;
struct Rec;
struct Rec3;
extern void func_020286C4(struct Ctx *ctx, void *p, void *cell);
extern u32 func_0201CE30(void *p);
extern void func_0201CE48(struct Rec3 *p);
extern void func_0201CE38(void *h);
extern void func_0201CE5C(struct Rec *p, s32 v);
extern int func_02035C60(void);
extern int func_02035C38(void);
extern void func_020061E4(u32 a);

int func_021975D0(u8 *p)
{
    if (*(void **)(p + 0x2B4) != 0) {
        if (*(void **)(p + 0x2B0) != 0)
            func_020286C4(*(void **)(p + 0x2A8), *(void **)(p + 0x2B4), *(void **)(p + 0x2B0));
        switch (func_0201CE30(*(void **)(p + 0x2B4))) {
        case 2:
            func_0201CE48(*(void **)(p + 0x2B4));
            *(void **)(p + 0x2B4) = 0;
            break;
        case 1:
            if (func_02035C60() != 0) {
                func_020061E4(0x547);
                func_0201CE38(*(void **)(p + 0x2B4));
            }
            break;
        case 0:
            if (func_02035C38() != 0)
                func_0201CE5C(*(void **)(p + 0x2B4), 0);
            break;
        }
        return 0;
    }
    return 1;
}
