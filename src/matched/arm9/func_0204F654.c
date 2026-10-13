/*
 * function: BILLBOARD_GetElemCell
 * address:  0x0204F654
 * packet:   pkt_0204F654
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Leaf witness for ov021 0x021BBF10 / 0x021BC138 (lane wA1-12).
 */

typedef unsigned short u16;
typedef struct { char pad[0x10]; u16 f10; char pad2[0xA]; } E1C_0204F654;
typedef struct { int pad[2]; E1C_0204F654 *f8; } Mgr_0204F654;

void BILLBOARD_GetElemCell(Mgr_0204F654 *p, int i, u16 *out)
{
    *out = p->f8[i].f10;
}
