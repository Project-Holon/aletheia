/*
 * function: COMM_PLAYER_GetState849
 * address:  0x021673C4
 * packet:   pkt_ov010_021673C4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reads the byte at +0x849 of the shared state under its lock
 * (SYMBOL_SAVE_FinalizeChecksum / SYMBOL_SAVE_UpdateChecksum).
 *
 * symbols:
 *   SYMBOL_SAVE_FinalizeChecksum  0x0200E06C  thumb
 *   SYMBOL_SAVE_UpdateChecksum  0x0200E024  thumb
 */

typedef unsigned char u8;

extern void SYMBOL_SAVE_FinalizeChecksum(char *p);
extern void SYMBOL_SAVE_UpdateChecksum(void *p);

u8 COMM_PLAYER_GetState849(u8 *p)
{
    u8 v;

    SYMBOL_SAVE_FinalizeChecksum((char *)p);
    v = p[0x849];
    SYMBOL_SAVE_UpdateChecksum(p);
    return v;
}
