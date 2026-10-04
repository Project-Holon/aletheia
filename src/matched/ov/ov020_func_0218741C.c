/*
 * function: func_0218741C
 * address:  0x0218741C
 * packet:   pkt_ov020_0218741C
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_0219129C  0x0219129C  thumb  ov021
 *   d_02187E04     0x02187E04  data  ov020  a2
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef unsigned int   u32;
struct Ent;
struct MsgBank;
struct WordSet;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern struct Ent *func_0219129C(u8 *base, int idx, u32 c, u32 d, u32 f, u32 g);
extern u16 d_02187E04[];

void func_0218741C(char *p, int a1, int *out, int a3)
{
    int i;

    func_02045CAC((struct MsgBank *)(*(int *)(p + 0x18)),
                  (u16)(a1 + (d_02187E04[(*(u16 **)(p + 0x48))[1]] + *(u16 *)(p + 0x4c) * 8)),
                  (void *)(*(int *)(p + 0x24)));
    func_0201F250((struct WordSet *)(*(int *)(p + 0x1c)), (void *)(*(int *)(p + 0x20)), (void *)(*(int *)(p + 0x24)));
    i = 0;
    *(int *)(p + 0x10) = (int)func_0219129C((u8 *)(*(int *)(p + 0xc)), 2, (u32)(p + 0x34), *(int *)(p + 0x20), i, i);
    *out = 0x10;
    *(u16 *)(p + 0x4e) = a3;
    *(u16 *)(p + 0x52) = 0;
    *(u8 *)(p + 0x54) = 1;
    *(u8 *)(p + 0x55) = 0;
}
