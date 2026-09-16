/*
 * function: func_020414C4
 * address:  0x020414C4
 * packet:   pkt_020414C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A44     0x02146A44  data
 *   func_02040B94  0x02040B94  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct BgSys {
    u16 heapId;
    u16 unk_02;
    u8 pad[0x1b0 - 4];
    void *unk_1b0[8];
};

extern struct BgSys *g_02146A44;
extern void func_02040B94(u32, void *, u32, u16);

void func_020414C4(u32 idx)
{
    func_02040B94(idx, g_02146A44->unk_1b0[idx], 0, g_02146A44->heapId);
}
