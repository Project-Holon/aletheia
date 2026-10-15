/*
 * function: MYSTERY_NET_UpdateWifiError
 * address: 0x021DE500
 * packet: pkt_ov121_021DE500
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding after the return.
 * symbols:
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   GFL_NET_GetInitParam 0x0203D798 arm
 *   MYSTERY_NET_ShowWifiError 0x021DE5D8 thumb ov121
 *   MYSTERY_NET_HandleWifiError 0x021DE570 thumb ov121
 *   MYSTERY_NET_ShowWifiErrorDw 0x021DE5F8 thumb ov121
 */
extern int GFL_NET_GetRunState(void);
extern char *GFL_NET_GetInitParam(void);
extern int MYSTERY_NET_ShowWifiError(void *);
extern int MYSTERY_NET_HandleWifiError(char *p);
extern int MYSTERY_NET_ShowWifiErrorDw(void *);
int MYSTERY_NET_UpdateWifiError(void *p)
{
    int result=0;
    if (GFL_NET_GetRunState()) {
        switch (*(unsigned char *)(GFL_NET_GetInitParam()+0x65)) {
        case 0: case 5: result=MYSTERY_NET_ShowWifiError(p); break;
        case 1: result=MYSTERY_NET_HandleWifiError(p); break;
        case 3: result=MYSTERY_NET_ShowWifiErrorDw(p); break;
        case 2: case 4: default: break;
        }
    }
    return result;
}
