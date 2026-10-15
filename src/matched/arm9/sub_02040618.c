/*
 * function: BG_SYS_FillScrollArea
 * address:  0x02040618
 * packet:   pkt_02040618
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A44     0x02146A44  data
 *   BG_SYS_SetScrollField  0x02042360  arm
 *   BG_SYS_RotScale  0x020423D4  arm
 *   GFL_NET_SetIrcParams  0x0203D814  arm
 *
 * The per-layer scroll register flush.  Closed in wave 11 by two facts:
 * GFL_NET_SetIrcParams takes the layer's scroll pair (x, y) as its two arguments
 * (the case-1 arm keeps r0/r1 live across the register write for the call,
 * as in BG_SYS_CommitScroll), and scrollX is read before scrollY.  The star is the
 * unlabelled follower BG_SYS_GetScrollX (already EXACT in unit_020407E8.c); the
 * true extent is 464 bytes, ending at 0x020407E8.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct BgLayer {
    u32 unk00; u32 unk04; u32 unk08; u32 unk0C; u32 unk10;
    u32 scrollX; u32 scrollY; u32 unk1C; u32 unk20; u32 unk24; u32 unk28;
};

extern struct BgLayer *g_02146A44;

struct Obj;
extern void BG_SYS_SetScrollField(struct Obj *p, u32 op, u32 value);
extern void BG_SYS_RotScale(u32 layer);
extern void GFL_NET_SetIrcParams(u32 x, u32 y);

#define W(a) (*(volatile u32 *)(a))

void BG_SYS_FillScrollArea(u32 layer, u32 a, u32 b)
{
    u32 mask = 0x1ff;
    u32 hmask = mask << 16;
    u32 x, y;

    BG_SYS_SetScrollField((struct Obj *)((u8 *)g_02146A44 + 8 + layer * sizeof(struct BgLayer)), a, b);

    x = g_02146A44[layer].scrollX;
    y = g_02146A44[layer].scrollY;

    switch (layer) {
    case 0:
        W(0x04000010) = (x & mask) | (hmask & (y << 16));
        break;
    case 1:
        W(0x04000014) = (x & mask) | (hmask & (y << 16));
        GFL_NET_SetIrcParams(x, y);
        break;
    case 2:
        if (((u8 *)g_02146A44)[0x74] == 0) {
            W(0x04000018) = (x & mask) | (hmask & (y << 16));
        } else {
            BG_SYS_RotScale(2);
        }
        break;
    case 3:
        if (((u8 *)g_02146A44)[0xa0] == 0) {
            W(0x0400001c) = (x & mask) | (hmask & (y << 16));
        } else {
            BG_SYS_RotScale(3);
        }
        break;
    case 4:
        W(0x04001010) = (x & mask) | (hmask & (y << 16));
        break;
    case 5:
        W(0x04001014) = (x & mask) | (hmask & (y << 16));
        break;
    case 6:
        if (((u8 *)g_02146A44)[0x124] == 0) {
            W(0x04001018) = (x & mask) | (hmask & (y << 16));
        } else {
            BG_SYS_RotScale(6);
        }
        break;
    case 7:
        if (((u8 *)g_02146A44)[0x150] == 0) {
            W(0x0400101c) = (x & mask) | (hmask & (y << 16));
        } else {
            BG_SYS_RotScale(7);
        }
        break;
    }
}
