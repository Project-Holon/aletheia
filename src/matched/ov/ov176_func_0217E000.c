/*
 * function: LIVEBATTLEMATCH_IRC_DeleteMenuRecord
 * address: 0x0217E000
 * packet: pkt_ov176_0217E000
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Unlabelled blocker leaf for DA38 and DB0C; parent confirmed unowned.
 * symbols:
 *   WIFIBATTLEMATCH_UTIL_ClearBmp 0x021E8870 thumb ov177
 */
struct S;
extern void WIFIBATTLEMATCH_UTIL_ClearBmp(struct S *);
void LIVEBATTLEMATCH_IRC_DeleteMenuRecord(int *p)
{
    WIFIBATTLEMATCH_UTIL_ClearBmp((struct S *)p[6]);
}
