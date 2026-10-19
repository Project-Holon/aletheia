/*
 * function: GAME_DATA_GetMiscSave
 * address:  0x02012F08
 * packet:   pkt_02012F08
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MISC_GetBlock  0x0200C0F0  thumb
 */

extern void *MISC_GetBlock(void *sys);
void *GAME_DATA_GetMiscSave(int *p)
{
    return MISC_GetBlock((void *)(*p));
}
