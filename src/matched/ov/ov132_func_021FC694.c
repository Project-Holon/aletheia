/*
 * function: MUS_COMM_FUNC_StartSession
 * address: 0x021FC694
 * packet: pkt_ov132_021FC694
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_StartSession 0x0203CBAC arm
 *   OS_GetMacAddress 0x02087C6C arm
 *   d_021FDE4C 0x021FDE4C data a4
 *   d_021FDDEC 0x021FDDEC data a4
 *   MUS_COMM_FUNC_SetReady 0x021FCAA0 thumb ov132
 *   MYSTATUS_Copy  0x02008494  thumb  arm9
 *   GAME_DATA_GetMyStatus  0x02012944  thumb  arm9
 */
#include "../include/Obj06493.h"
typedef unsigned short u16;
typedef unsigned char  u8;
extern u8 *GAME_DATA_GetMyStatus(void *p);
typedef unsigned int   u32;
struct Req;
extern void GFL_NET_StartSession(struct Req *req, u32 a2, u32 a3);
extern void MYSTATUS_Copy(void *, void *);
extern void OS_GetMacAddress(void *);
extern void MUS_COMM_FUNC_SetReady(char *p);
extern char d_021FDE4C[];
extern char d_021FDDEC[];
void *MUS_COMM_FUNC_StartSession(int a,char *p)
{
    ((struct Obj06493 *)p)->f5C=GAME_DATA_GetMyStatus(((struct Obj06493 *)p)->f58);
    if(((struct Obj06493 *)p)->fC==1) d_021FDE4C[5]=4;
    else {
        d_021FDE4C[5]=0;
        GFL_NET_StartSession((struct Req *)d_021FDDEC,(u32)MUS_COMM_FUNC_SetReady,(u32)p);
    }
    MYSTATUS_Copy(((struct Obj06493 *)p)->f5C,p+0x20);
    OS_GetMacAddress(p+0x40);
    ((struct Obj06493 *)p)->f46=0x3a0b;
    return p;
}
