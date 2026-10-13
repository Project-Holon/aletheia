/*
 * function: func_021DE500
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
 *   func_021DE5D8 0x021DE5D8 thumb ov121
 *   func_021DE570 0x021DE570 thumb ov121
 *   func_021DE5F8 0x021DE5F8 thumb ov121
 */
extern int GFL_NET_GetRunState(void);
extern char *GFL_NET_GetInitParam(void);
extern int func_021DE5D8(void *);
extern int func_021DE570(char *p);
extern int func_021DE5F8(void *);
int func_021DE500(void *p)
{
    int result=0;
    if (GFL_NET_GetRunState()) {
        switch (*(unsigned char *)(GFL_NET_GetInitParam()+0x65)) {
        case 0: case 5: result=func_021DE5D8(p); break;
        case 1: result=func_021DE570(p); break;
        case 3: result=func_021DE5F8(p); break;
        case 2: case 4: default: break;
        }
    }
    return result;
}
