/*
 * function: func_021BA31C
 * address:  0x021BA31C
 * packet:   pkt_ov068_021BA31C
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Switch with `case 0: default: return 1;` written first puts the shared
 * return right after the dispatch, as in the original.
 *
 * symbols:
 *   func_02028484  0x02028484  thumb
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045770  0x02045770  arm
 *   func_02045334  0x02045334  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef signed int     s32;
struct Blk;
struct PrintSys;
extern s32 func_02028484(struct Blk *blk, void *h);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02045334(struct Descriptor *d);

int func_021BA31C(u8 *p)
{
    u32 t;

    switch (*(u32 *)(p + 0x28)) {
    case 0:
    default:
        return 1;
    case 2:
        t = *(u32 *)(p + 0x24);
        if (p[0x20] != 0) {
            if (func_0201C6C4((struct PrintSys *)t, (void *)((u32)func_02045770((struct Descriptor *)*(u32 *)(p + 0x1c)))) == 0) {
                func_02045334((struct Descriptor *)*(u32 *)(p + 0x1c));
                p[0x20] = 0;
            }
        }
        if (p[0x20] == 0) {
            return 1;
        }
        return 0;
    case 1:
        return func_02028484((struct Blk *)(p + 0x2c), (void *)(*(u32 *)(p + 8)));
    }
}
