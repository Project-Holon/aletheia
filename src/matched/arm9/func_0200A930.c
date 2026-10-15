/*
 * function: IRC_RANKING_GetLastSlot
 * address:  0x0200A930
 * packet:   pkt_0200A930
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf: low byte of the word at +0x348.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 v : 8; u32 rest : 24; } B;
u8 IRC_RANKING_GetLastSlot(char *p)
{
    return ((B *)(p + 0x348))->v;
}
