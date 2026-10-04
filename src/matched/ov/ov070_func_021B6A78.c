/*
 * function: func_021B6A78
 * address:  0x021B6A78
 * packet:   pkt_ov070_021B6A78
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_021BACF0  0x021BACF0  thumb  ov070
 *   func_021B6100  0x021B6100  thumb  ov070
 *   func_021B6A14  0x021B6A14  thumb  ov070
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct MsgBank;
struct WordSet;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021BACF0(int p, int mode);
extern void func_021B6100(void *obj, void *fn);
extern void func_021B6A14(u8 *p);

void func_021B6A78(u8 *p)
{
    if (*(u32 *)(p + 0x84C) - 0x268 <= 1) {
        func_02045CAC((struct MsgBank *)(*(u32 *)(p + 0x51C)), 0x38, (void *)(*(u32 *)(p + 0x524)));
        func_0201F02C((struct WordSet *)(*(u32 *)(p + 0x520)), 0, (void *)(*(u32 *)(p + 8)));
        func_0201F250((struct WordSet *)(*(u32 *)(p + 0x520)), (void *)(*(u32 *)(p + 0x528)), (void *)(*(u32 *)(p + 0x524)));
        func_021BACF0((int)p, 1);
        func_021B6100(p, (void *)func_021B6A14);
    }
}
