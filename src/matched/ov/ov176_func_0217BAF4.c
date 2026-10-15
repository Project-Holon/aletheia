/*
 * function: LIVEBATTLEMATCH_FLOW_Release
 * address: 0x0217BAF4
 * packet: pkt_ov176_0217BAF4
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFIBATTLEMATCH_UTIL_InvokeCallback 0x021E8A80 thumb ov177
 *   LIVEBATTLEMATCH_IRC_NoOp 0x0217E074 thumb ov176
 *   WIFIBATTLEMATCH_VIEW_Noop 0x021E7E08 thumb ov177
 *   WIFIBATTLEMATCH_VIEW_UpdatePokeList 0x021E64C0 thumb ov177
 *   WIFIBATTLEMATCH_VIEW_UpdateRecordWindow 0x021E7774 thumb ov177
 *   WIFIBATTLEMATCH_VIEW_UpdatePartyWindow 0x021E84F8 thumb ov177
 */
extern void WIFIBATTLEMATCH_UTIL_InvokeCallback(int);
extern void LIVEBATTLEMATCH_IRC_NoOp(int);
extern void WIFIBATTLEMATCH_VIEW_Noop(int);
extern int WIFIBATTLEMATCH_VIEW_UpdatePokeList(unsigned char *, void *);
extern int WIFIBATTLEMATCH_VIEW_UpdateRecordWindow(void *p, void *mgr);
extern int WIFIBATTLEMATCH_VIEW_UpdatePartyWindow(char *p, void *q);
void LIVEBATTLEMATCH_FLOW_Release(int *p)
{
    WIFIBATTLEMATCH_UTIL_InvokeCallback(p[0]);
    LIVEBATTLEMATCH_IRC_NoOp(p[3]);
    WIFIBATTLEMATCH_VIEW_Noop(p[7]);
    if (p[4]) WIFIBATTLEMATCH_VIEW_UpdatePokeList((unsigned char *)p[4], (void *)p[0x6B]);
    if (p[5]) WIFIBATTLEMATCH_VIEW_UpdateRecordWindow((void *)p[5], (void *)p[0x6B]);
    if (p[6]) WIFIBATTLEMATCH_VIEW_UpdatePartyWindow((char *)p[6], (void *)p[0x6B]);
}
