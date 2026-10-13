/*
 * function: func_021D505C
 * address: 0x021D505C
 * packet: pkt_ov120_021D505C
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D4988 0x021D4988 thumb ov120
 *   func_021D8638 0x021D8638 thumb ov120
 *   GFL_NET_STATE_WifiDisconnect 0x0203C554 arm
 *   func_020355D8 0x020355D8 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D4FF4 0x021D4FF4 thumb ov120
 */
#include "../include/Obj13931.h"
typedef unsigned char u8;
extern void func_021D4988(int);
extern void func_021D8638(u8 *);
typedef unsigned int   u32;
extern void GFL_NET_STATE_WifiDisconnect(u32 a);
extern void func_020355D8(u8 v);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void func_021D4244(int *p, int v, int a2);
extern void func_021D4FF4(u8 *p);
void func_021D505C(int a, int b, int *p)
{
    if (b == 0 && *(void (**)(int))p == func_021D4988) {
        func_021D8638(*(u8 * *)&((struct Obj13931 *)p)->f40);
        GFL_NET_STATE_WifiDisconnect(1);
        func_020355D8(1);
        GFL_USE_PlaySeDefaultVolume(0x551);
        func_021D4244(p, (int)((void (*)(int))func_021D4FF4), 0x5f5);
    }
}
