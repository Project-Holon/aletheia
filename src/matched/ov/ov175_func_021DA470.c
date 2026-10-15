/*
 * function: WIFIBATTLEMATCH_NET_GetDateTime
 * address: 0x021DA470
 * packet: pkt_ov175_021DA470
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * stack: four date words (including weekday), three time words.
 * symbols:
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   func_0200FA84 0x0200FA84 thumb
 *   DWC_GetDateTime 0x02167ED8 arm ov009
 *   MI_CpuFill8 0x02082BCC arm
 */
extern int GFL_NET_GetRunState(void);
extern void func_0200FA84(void);
extern int DWC_GetDateTime(void *date, void *time);
extern void MI_CpuFill8(void *, int, int);
void WIFIBATTLEMATCH_NET_GetDateTime(unsigned char *dest)
{
    int date[4];
    int time[3];
    if (!GFL_NET_GetRunState()) func_0200FA84();
    if (!DWC_GetDateTime(date, time)) func_0200FA84();
    MI_CpuFill8(dest, 0, 6);
    dest[0] = date[0];
    dest[1] = date[1];
    dest[2] = date[2];
    dest[3] = time[0];
    dest[4] = time[1];
    dest[5] = time[2];
}
