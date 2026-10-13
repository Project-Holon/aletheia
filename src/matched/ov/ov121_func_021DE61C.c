/*
 * function: func_021DE61C
 * address: 0x021DE61C
 * packet: pkt_ov121_021DE61C
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_StartSession 0x0203CBAC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   func_02010360 0x02010360 thumb
 *   GFL_NET_BeaconScanStart 0x0203D010 arm
 *   func_021DEEA4 0x021DEEA4 thumb ov121
 *   func_021DE6F8 0x021DE6F8 thumb ov121
 *   d_021DFABC 0x021DFABC data a4
 */
#include "../include/Obj10424.h"
struct Req;
extern void GFL_NET_StartSession(struct Req *req, unsigned int a2, unsigned int a3);
typedef unsigned int   u32;
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern int GFL_NET_GetRunState(void);
extern void GFL_NET_RestartWithDefaultTimeout(unsigned, unsigned);
typedef unsigned char  u8;
extern u8 *func_02010360(int idx, void *heap);
extern void GFL_NET_BeaconScanStart(void);
extern void func_021DEEA4(u32 *p, void *f);
extern void func_021DE6F8(int, int, char *);
extern unsigned d_021DFABC[];
void func_021DE61C(void *a, int *state, char *p)
{
    switch (*state) {
    case 0:
        GFL_NET_StartSession((struct Req *)d_021DFABC, 0, (unsigned)p);
        BG_SYS_SetSubPlaneVisible(0x10, 0);
        *state = 1;
        break;
    case 1:
        if (GFL_NET_GetRunState()) {
            GFL_NET_RestartWithDefaultTimeout(1, ((struct Obj10424 *)p)->f58);
            ((struct Obj10424 *)p)->f10 = func_02010360(4, (void *)(((struct Obj10424 *)p)->f58));
            GFL_NET_BeaconScanStart();
            *state = 2;
        }
        break;
    case 2:
        BG_SYS_SetSubPlaneVisible(0x10, 1);
        func_021DEEA4(a, func_021DE6F8);
        break;
    }
}
