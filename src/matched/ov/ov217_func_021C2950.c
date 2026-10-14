/*
 * function: PERCENTAGE_Exit
 * address:  0x021C2950
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: branch to PERCENTAGE_DeleteActors.
 *
 * symbols:
 *   PERCENTAGE_DeleteActors  0x021C299C  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void PERCENTAGE_DeleteActors(int *);

void PERCENTAGE_Exit(u32 a0)
{
    PERCENTAGE_DeleteActors((int *)a0);
}
