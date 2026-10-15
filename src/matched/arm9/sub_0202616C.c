/*
 * function: CURSOR_MOVE_GetEntry
 * address:  0x0202616C
 * packet:   pkt_02025C44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char u8;
typedef unsigned int  u32;

void *CURSOR_MOVE_GetEntry(void **obj, u32 idx)
{
    return (u8 *)(*obj) + idx * 12;
}
