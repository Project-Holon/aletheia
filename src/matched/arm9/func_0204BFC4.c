/*
 * function: func_0204BFC4
 * address:  0x0204BFC4
 * packet:   pkt_0204BE84
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A74     0x02146A74  data
 *   func_0204BF40  0x0204BF40  arm
 *
 * Forward one command at the manager itself: the manager is the command
 * block, its u16 at +0xf0 is the id and the word at +0xf4 the payload.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Mgr {
    u8  pad_000[0xf0];
    u16 unk_f0;
    u16 unk_f2;
    u32 unk_f4;
};

extern struct Mgr *g_02146A74;

struct OamEntry;
struct Win;
extern void func_0204BF40(struct Win *win, struct OamEntry *src, u32 mode, u32 pal, u32 op);

void func_0204BFC4(u32 a0, u32 a1)
{
    func_0204BF40((struct Win *)g_02146A74, (struct OamEntry *)a0, a1, g_02146A74->unk_f0, g_02146A74->unk_f4);
}
