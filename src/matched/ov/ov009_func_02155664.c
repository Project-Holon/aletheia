/*
 * function: func_02155664
 * address: 0x02155664
 * packet: pkt_ov009_02155664
 * region: ov009
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: caller ov099021BEEC4 BL targets this word-run start; full
 *   Thumb decode stores the original callback R0 at global +0x2a4 and returns.
 * symbols:
 *   g_021A8264 0x021A8264 data ov009
 */
extern char *g_021A8264;
void func_02155664(void (*callback)(void))
{
    *(void (**)(void))(g_021A8264+0x2a4)=callback;
}
