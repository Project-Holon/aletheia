/*
 * function: func_021DE570
 * address: 0x021DE570
 * packet: pkt_ov121_021DE570
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0200FB24 0x0200FB24 thumb
 *   GFL_NET_STATE_GetError 0x0203CA98 arm
 *   GFL_NET_STATE_SetWifiError 0x0203CA04 arm
 *   func_02059F18 0x02059F18 arm
 *   func_0200FBB0 0x0200FBB0 thumb
 *   GFL_NET_ERR_ShowSimpleScreen 0x0200F83C thumb
 *   func_0200FBA0 0x0200FBA0 thumb
 *   func_0200FA84 0x0200FA84 thumb
 */
#include "../include/Obj22914.h"
typedef unsigned int   u32;
extern u32 func_0200FB24(void);
extern u32 GFL_NET_STATE_GetError(void);
extern void GFL_NET_STATE_SetWifiError(void);
extern void func_02059F18(void);
extern u32 func_0200FBB0(void);
extern void GFL_NET_ERR_ShowSimpleScreen(void);
extern void func_0200FBA0(void);
extern void func_0200FA84(void);
int func_021DE570(char *p)
{
    int result=0;
    if (func_0200FB24()) {
        switch (*(unsigned *)(GFL_NET_STATE_GetError()+4)) {
        case 1: case 2: case 3: case 4: case 5: case 6:
            if (((struct Obj22914 *)p)->f790==1) return result;
            GFL_NET_STATE_SetWifiError();
            func_02059F18();
            func_0200FBB0();
            GFL_NET_ERR_ShowSimpleScreen();
            func_0200FBA0();
            result=1; break;
        case 7:
            GFL_NET_STATE_SetWifiError();
            func_0200FA84();
            result=3; break;
        case 0: default: break;
        }
    }
    return result;
}
