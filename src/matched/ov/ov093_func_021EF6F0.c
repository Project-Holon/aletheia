/*
 * function: func_021EF6F0
 * address:  0x021EF6F0
 * packet:   pkt_ov093_021EF6F0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EEFE0  0x021EEFE0  thumb  ov093
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   d_021F6398     0x021F6398  data   a4
 *
 * Unlabelled leaf, callee of the tail stub 0x021EF6E8 that func_021EA55C calls.
 * Twin of func_021EF6B0 without the +0x5a flag stores, using the +0x28 slot.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void ***f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 pad[10];
    u32 f54;
    u16 f58;
    u16 f5a;
} D;

struct MsgBank;
struct WordSet;
extern void func_021EEFE0(void *s, const u32 *values, void *w);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern D d_021F6398;

void func_021EF6F0(u32 a, u32 b, u32 c)
{
    func_02045CAC((struct MsgBank *)d_021F6398.f28, b, (void *)d_021F6398.fc);
    func_021EEFE0((void *)d_021F6398.fc, (const u32 *)c, (void *)d_021F6398.f8);
    func_0201F250((struct WordSet *)d_021F6398.f8, (void *)a, (void *)d_021F6398.fc);
}
