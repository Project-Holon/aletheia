/*
 * function: func_021B6C30
 * address:  0x021B6C30
 * packet:   pkt_ov070_021B6C30
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02028754  0x02028754  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_021B6100  0x021B6100  thumb  ov070
 *   func_021B6AD8  0x021B6AD8  thumb  ov070
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Obj;
extern u32 func_02028754(struct Obj *obj, u32 n);
struct MsgBank;
struct WordSet;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021B6100(void *obj, void *fn);
extern void func_021B6AD8(int p);

u32 func_021B6C30(u8 *p)
{
    if (func_02028754(*(void **)(p + 0xC), 2)) {
        *(u32 *)(p + 0x844) = 8;
        func_021B6100(p, 0);
        return 1;
    }
    func_02045CAC((struct MsgBank *)(*(u32 *)(p + 0x51C)), 0x3A, (void *)(*(u32 *)(p + 0x524)));
    func_0201F02C((struct WordSet *)(*(u32 *)(p + 0x520)), 0, (void *)(*(u32 *)(p + 8)));
    func_0201F250((struct WordSet *)(*(u32 *)(p + 0x520)), (void *)(*(u32 *)(p + 0x528)), (void *)(*(u32 *)(p + 0x524)));
    func_021B6100(p, (void *)func_021B6AD8);
    return 0;
}
