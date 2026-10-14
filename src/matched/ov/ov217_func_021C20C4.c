/*
 * function: ARROW_Update
 * address:  0x021C20C4
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: branch to ARROW_RunState.
 *
 * symbols:
 *   ARROW_RunState  0x021C20EC  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void ARROW_RunState(void *p);

void ARROW_Update(void *p)
{
    ARROW_RunState(p);
}
