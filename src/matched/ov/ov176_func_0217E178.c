/*
 * function: LIVEBATTLEMATCH_IRC_WaitExit,LIVEBATTLEMATCH_IRC_ResetState
 * unit: yes
 * address: 0x0217E178
 * packet: pkt_ov176_0217E178
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   GFL_NET_Exit 0x0203CEAC arm
 *   GFL_NET_IsSessionNull 0x0203CDBC arm
 */
extern int GFL_NET_GetRunState(void);
extern int GFL_NET_Exit(int a0);
extern int GFL_NET_IsSessionNull(void);
int LIVEBATTLEMATCH_IRC_WaitExit(int *p)
{
    switch (*p) {
    case 0:
        if (GFL_NET_GetRunState()) {
            GFL_NET_Exit(0);
            *p = 1;
        } else {
            *p = 2;
        }
        break;
    case 1:
        if (GFL_NET_IsSessionNull())
            *p = 2;
        break;
    case 2:
        return 1;
    }
    return 0;
}
int LIVEBATTLEMATCH_IRC_ResetState(int *p) { *p = 0; return 1; }
