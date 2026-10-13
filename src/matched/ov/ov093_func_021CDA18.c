/*
 * function: BTL_CLIENT_StepMain
 * address: 0x021CDA18
 * packet: pkt_ov093_021CDA18
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D3FDC 0x021D3FDC thumb ov093
 *   BTL_ADAPTER_GetRecvCommand 0x021EEBE8 thumb ov093
 *   BTL_CLIENT_ResetSendWord 0x021CDD34 thumb ov093
 *   BTL_ADAPTER_GetRecvData 0x021EEC20 thumb ov093
 *   func_021CDD50 0x021CDD50 thumb ov093
 *   func_021D3FAC 0x021D3FAC thumb ov093
 *   func_021D3FC4 0x021D3FC4 thumb ov093
 *   func_021D3F4C 0x021D3F4C thumb ov093
 *   BTL_ADAPTER_SetRecvTarget 0x021EEC4C thumb ov093
 *   func_021D3F60 0x021D3F60 thumb ov093
 *   GFL_USE_SetPlayersAudible 0x02005CA4 thumb
 *   PM_VOICE_ResetMasterVolume 0x02006740 thumb
 *   GFL_USE_IsBgmFading 0x02005E50 thumb
 *   func_021D3FA8 0x021D3FA8 thumb ov093
 *   func_021BA73C 0x021BA73C thumb ov093
 *   PM_VOICE_SetMasterVolume 0x02006734 thumb
 */
#include "../include/Obj00463.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int (*Callback)(u8 *,int *);
typedef struct { u8 f0:1,f1:1,f2:1,f3:1,f4:1,f5:1,rest:2; } Flags;
struct Q;
extern void func_021D3FDC(u8 *p, struct Q *q);
extern u8 BTL_ADAPTER_GetRecvCommand(void *);
extern void BTL_CLIENT_ResetSendWord(u8 *);
extern int BTL_ADAPTER_GetRecvData(int,u32 **);
extern Callback func_021CDD50(u8 *,u32,int *);
extern int func_021D3FAC(u8 *);
extern void func_021D3FC4(u8 *);
extern int func_021D3F4C(void *);
extern int BTL_ADAPTER_SetRecvTarget(void *,void *,u32);
extern u8 func_021D3F60(u8 *);
extern void GFL_USE_SetPlayersAudible(int,u32);
extern void PM_VOICE_ResetMasterVolume(void);
extern int GFL_USE_IsBgmFading(void);
extern u16 func_021D3FA8(u8 *p);
extern void func_021BA73C(char *,int);
extern void PM_VOICE_SetMasterVolume(u8);
int BTL_CLIENT_StepMain(u8 *p)
{
    u32 id, *pair, x, y;
    int flag, n;
    func_021D3FDC(p,(struct Q *)(p+0x18));
    switch (p[0x1a8]) {
    case 0:
        id = BTL_ADAPTER_GetRecvCommand(((struct Obj00463 *)p)->f50);
        if (p[0x1a7] == 2 && (((Flags *)(p+0x1b2))->f4 || ((Flags *)(p+0x1b2))->f5) && !id) return 0;
        BTL_CLIENT_ResetSendWord(p);
        if (id == 9) {
            BTL_ADAPTER_GetRecvData(*(int *)&((struct Obj00463 *)p)->f50,&pair);
            x = pair[0]; y = pair[1];
            ((struct Obj00463 *)p)->f30 = y;
            ((struct Obj00463 *)p)->f2C = x;
            ((struct Obj00463 *)p)->fCC = 0;
            p[0x1a8] = 3;
        } else if (id) {
            *(Callback *)&((struct Obj00463 *)p)->fC8 = func_021CDD50(p,id,&flag);
            if (flag) {
                if (!func_021D3FAC(p+0x18)) { p[0x1a8] = 6; break; }
            } else func_021D3FC4(p+0x18);
            if (*(Callback *)&((struct Obj00463 *)p)->fC8) {
                p[0x1a8] = 1;
                ((struct Obj00463 *)p)->fCC = 0;
            } else {
                ((struct Obj00463 *)p)->fCC = 0;
                p[0x1a8] = 2;
            }
        } else if (((Flags *)(p+0x1b2))->f1) return 1;
        break;
    case 1:
        if ((*(Callback *)(p+0xc8))(p,(int *)(p+0xcc))) {
            if (((Flags *)(p+0x1b2))->f1) return 1;
            if (func_021D3F4C(p+0x18)) p[0x1a8] = 4;
            else p[0x1a8] = 2;
        }
        break;
    case 2:
        if (BTL_ADAPTER_SetRecvTarget(((struct Obj00463 *)p)->f50,((struct Obj00463 *)p)->fD8,((struct Obj00463 *)p)->fDC)) p[0x1a8] = 0;
        if (((Flags *)(p+0x1b2))->f1) return 1;
        break;
    case 3:
        if (BTL_ADAPTER_SetRecvTarget(((struct Obj00463 *)p)->f50,((struct Obj00463 *)p)->fD8,((struct Obj00463 *)p)->fDC)) p[0x1a8] = 7;
        if (((Flags *)(p+0x1b2))->f1) return 1;
        break;
    case 6:
        if (func_021D3F4C(p+0x18)) p[0x1a8] = 4;
        break;
    case 4:
        if (func_021D3F60(p+0x18) == 1) p[0x1a8] = 7;
        else {
            if (((struct Obj00463 *)p)->f54) { GFL_USE_SetPlayersAudible(1,62); PM_VOICE_ResetMasterVolume(); }
            p[0x1a8] = 5;
        }
        break;
    case 5:
        if (!GFL_USE_IsBgmFading()) {
            n = func_021D3FA8(p+0x18);
            GFL_USE_SetPlayersAudible(0,1);
            func_021BA73C(*(char * *)&((struct Obj00463 *)p)->f0,n);
            PM_VOICE_SetMasterVolume(0);
        }
        break;
    case 7:
        return 1;
    }
    return 0;
}
