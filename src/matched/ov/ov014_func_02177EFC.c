/*
 * function: NET_WHPIPE_TaskParentSearchWait
 * address:  0x02177EFC
 * packet:   pkt_ov014_02177EFC
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_pWhPipeWork     0x021797A4  data  ov014  a4
 *   WIH_Finalize  0x02179498  thumb
 *   NET_WHPIPE_SetTask  0x0217727C  thumb
 *   NET_WHPIPE_TaskChildScanStart  0x02177FF0  thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u8 *g_pWhPipeWork;
int WIH_Finalize(void);
void NET_WHPIPE_SetTask(u32 *p, u32 v);
void NET_WHPIPE_TaskChildScanStart(u8 *a);

void NET_WHPIPE_TaskParentSearchWait(u8 *a)
{
    if (g_pWhPipeWork[0xCF3] == 0) {
        if (a[0xCF2] != 0)
            a[0xCF2]--;
        if (a[0xCF2] == 0) {
            if (WIH_Finalize() != 0)
                NET_WHPIPE_SetTask((u32 *)g_pWhPipeWork, (u32)NET_WHPIPE_TaskChildScanStart);
        }
    }
}
