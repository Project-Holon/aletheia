/*
 * function: func_02177888
 * address:  0x02177888
 * packet:   pkt_ov014_02177888
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_pWhPipeWork     0x021797A4  data  a4
 *   func_02178E4C  0x02178E4C  thumb  ov014
 *   func_02177AEC  0x02177AEC  thumb  ov014
 *   func_021777FC  0x021777FC  thumb  ov014
 *   WIH_GetOwnAid  0x021795A4  thumb  ov014
 *   func_02177ACC  0x02177ACC  thumb  ov014
 *   DWCi_MOV_WH_GetLastError  0x02178E68  thumb  ov014
 *   func_02177704  0x02177704  thumb  ov014
 *   func_02179570  0x02179570  thumb  ov014
 *   GFL_NET_CallErrorStateFunc  0x0203D720  arm
 *   GFL_NET_CallStateChangeFunc  0x0203D754  arm
 */
#include "../include/Obj02358.h"
#include "../include/G_W.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern struct W *g_pWhPipeWork;
int func_02178E4C(void);
int func_02177AEC(void);
void func_021777FC(void);
unsigned short WIH_GetOwnAid(void);
unsigned int func_02177ACC(void);
int DWCi_MOV_WH_GetLastError(void);
void func_02177704(void);
int func_02179570(void (*cb)(int));
void GFL_NET_CallErrorStateFunc(u32 a);
void GFL_NET_CallStateChangeFunc(u32 a);

void func_02177888(u32 arg)
{
    int mode = func_02178E4C();
    u8 *base = ((u8 *)g_pWhPipeWork);

    if (func_02177AEC() == 0)
        func_021777FC();
    if (((struct Obj02358 *)base)->fC6A == 0xFFFF)
        ((struct Obj02358 *)base)->fC6A = arg;
    if (base[0xCEC] != 0) {
        if (WIH_GetOwnAid() == 0 && func_02177ACC() == 0)
            base[0xCEB] = 1;
        if (((struct Obj02358 *)base)->fC6A > arg)
            base[0xCEB] = 1;
    }
    if (DWCi_MOV_WH_GetLastError() == 0x19)
        GFL_NET_CallErrorStateFunc(0);
    switch (mode) {
    case 0:
        if (base[0xCE7] == 1)
            func_02177704();
        break;
    case 1:
        if (base[0xCE7] == 1 && func_02179570(0) != 0)
            return;
        if (base[0xCE7] == 2 && func_02179570(0) != 0)
            return;
        break;
    case 8:
    case 9:
        if (base != 0) {
            if (base[0xCEB] == 0)
                GFL_NET_CallStateChangeFunc(DWCi_MOV_WH_GetLastError());
            base[0xCEB] = 1;
        }
        break;
    }
}
