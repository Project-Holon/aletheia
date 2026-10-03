/*
 * function: func_021BBF1C
 * address:  0x021BBF1C
 * packet:   pkt_ov088_021BBF1C
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * EXACT*: extent runs long; the follower at 0x021BBF98 is an unlabelled
 * tail-call stub (function_starts seed).
 *
 * symbols:
 *   func_02045CAC  0x02045CAC  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_02012FFC  0x02012FFC  thumb
 *   func_0201CCE4  0x0201CCE4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void func_02045CAC(u32 a0, u32 a1, u32 a2);
extern u32 func_02045770(u32 p);
extern void func_02043B5C(u32 win, u32 c);
typedef unsigned char  u8;
struct Cfg;
struct Descriptor;
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern signed char func_02012FFC(void);
extern u32 func_0201CCE4(u32 a0, u32 a1, u32 a2, u32 a3, u32 a5, u32 a6, u32 a7,
                         u32 a8, u16 a9, u16 a10);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);

void func_021BBF1C(char *p, u32 a1)
{
    void *h;
    func_02045CAC(*(u32 *)(p + 0x5c), a1, *(u32 *)(p + 0x64));
    func_02043B5C(func_02045770(*(u32 *)(p + 0xe8)), 0xf);
    func_0201F73C(*(void **)(p + 0xe8), 2, 1, 0xe);
    *(u32 *)(p + 0x6c) = func_0201CCE4(*(u32 *)(p + 0xe8), 0, 0, *(u32 *)(p + 0x64),
                                       *(u32 *)(p + 0x58), func_02012FFC(),
                                       *(u32 *)(p + 0x70), 0xa, 0xb, 0xf);
    *(u32 *)(p + 0x78) = 0;
    h = *(void **)(p + 0xe8);
    func_02045334(h);
    func_02045374(h);
    func_02041B6C(func_02045730(h));
}
