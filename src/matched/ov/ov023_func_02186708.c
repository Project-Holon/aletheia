/*
 * function: func_02186708
 * address:  0x02186708
 * packet:   pkt_ov023_02186708
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_0201C4E4(u32 a);
struct Descriptor;
extern void *func_02045770(struct Descriptor *a);
extern int func_0201C6C4(u32 a, u32 b);
extern void func_02045334(u32 a);

void func_02186708(char *p)
{
    int i;
    u32 h;

    func_0201C4E4(*(u32 *)(p + 0x164));
    func_0201C4E4(*(u32 *)(p + 0x168));
    for (i = 0; i < 5; i++) {
        h = *(u32 *)(p + 0x164);
        if (*(u8 *)(p + i * 8 + 0x130) != 0) {
            if (func_0201C6C4(h, (u32)func_02045770((struct Descriptor *)*(u32 *)(p + i * 8 + 0x12C))) == 0) {
                func_02045334(*(u32 *)(p + i * 8 + 0x12C));
                *(u8 *)(p + i * 8 + 0x130) = 0;
            }
        }
    }
    h = *(u32 *)(p + 0x168);
    if (*(u8 *)(p + 0x160) != 0) {
        if (func_0201C6C4(h, (u32)func_02045770((struct Descriptor *)*(u32 *)(p + 0x15C))) == 0) {
            func_02045334(*(u32 *)(p + 0x15C));
            *(u8 *)(p + 0x160) = 0;
        }
    }
}
