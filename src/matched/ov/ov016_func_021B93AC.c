/*
 * function: func_021B93AC
 * address:  0x021B93AC
 * packet:   pkt_ov016_021B93AC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   WCM_LockApList   0x02165C28  arm
 *   WCM_CountApList  0x02165BD0  arm
 *   WCM_PointApList  0x02165CA0  arm
 *   MIi_CpuCopy32    0x02082A90  arm
 */
extern int WCM_LockApList(int lock);
extern int WCM_CountApList(void);
extern void *WCM_PointApList(unsigned short index);
extern void MIi_CpuCopy32(void *srcp, void *destp, unsigned long size);

int func_021B93AC(char *buf, int max)
{
    int n;
    int i;

    WCM_LockApList(1);
    n = WCM_CountApList();
    if (n > 0) {
        for (i = 0; i < n; i++) {
            if (i >= max)
                break;
            MIi_CpuCopy32(WCM_PointApList(i), buf, 0xc0);
            buf += 0xc0;
        }
    }
    WCM_LockApList(0);
    return n;
}
