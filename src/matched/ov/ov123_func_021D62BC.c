/*
 * function: GSYNC_DISP_SetSlotAnimSeq
 * address:  0x021D62BC
 * packet:   pkt_021D62BC
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);

void GSYNC_DISP_SetSlotAnimSeq(u8 *p, int i, u32 v)
{
    CLACT_SetActorAnimSeq(*(void **)(p + i * 4 + 0x74), (u16)v);
}
