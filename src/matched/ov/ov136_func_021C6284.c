/*
 * function: func_021C6284
 * address:  0x021C6284
 * packet:   pkt_ov136_021C6284
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201F250     0x0201F250  thumb
 *   func_02045808              0x02045808  arm
 *   func_02045EC0        0x02045EC0  arm
 *   func_021C61D4  0x021C61D4  thumb
 *   func_021C6230 0x021C6230 thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021C61D4(void *, u32);
struct MsgBank;
struct U16Vec;
struct WordSet;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045808(struct U16Vec *vec);
extern void func_021C6230(u8 *p);
void func_021C6284(u8 *p)
{
    void *t;
    func_021C61D4(p, 0);
    t = func_02045EC0(*(void **)(*(u8 **)(p + 8) + 0x1D0), 9);
    func_0201F250(*(void **)(*(u8 **)(p + 8) + 0x1D4), *(void **)(*(u8 **)(p + 8) + 0x1D8), t);
    func_02045808(t);
    func_021C6230(p);
}
