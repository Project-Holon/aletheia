/*
 * function: BEACON_VIEW_TaskStateArrowAnim
 * address: 0x021F25D4
 * packet: pkt_ov032_021F25D4
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BEACON_VIEW_SetArrowAnim 0x021F05E8 thumb ov032
 *   BEACON_VIEW_IsArrowAnimActive 0x021F0668 thumb ov032
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void BEACON_VIEW_SetArrowAnim(u8 *, int, u32);
extern int BEACON_VIEW_IsArrowAnimActive(char *p, int i);
int BEACON_VIEW_TaskStateArrowAnim(u8 *p, int *st)
{
    switch (st[0]) {
    case 0:
        BEACON_VIEW_SetArrowAnim(p, st[6], 1);
        st[0]++;
        return 0;
    case 1:
        if (BEACON_VIEW_IsArrowAnimActive((char *)p, st[6]) != 0)
            return 0;
        break;
    }
    return 1;
}
