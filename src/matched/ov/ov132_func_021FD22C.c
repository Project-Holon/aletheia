/*
 * function: func_021FD22C
 * address: 0x021FD22C
 * packet: pkt_ov132_021FD22C
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKE_TOOL_GetBoxParamSize 0x020173E8 thumb
 *   MI_CpuCopy8 0x02082D44 arm
 *   GFL_NET_HANDLE_GetNetHandle 0x0203996C arm
 *   GFL_NET_SendData 0x0203D3F8 arm
 *   MYSTATUS_GetSize  0x02008468  thumb  arm9
 */
#include "../include/Obj14127.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 POKE_TOOL_GetBoxParamSize(void);
typedef signed int     s32;
struct Entry;
extern int MYSTATUS_GetSize(void);
extern void MI_CpuCopy8(void *,void *,u32);
extern struct Entry *GFL_NET_HANDLE_GetNetHandle(s32 idx);
extern u32 GFL_NET_SendData(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
int func_021FD22C(char *p)
{
    u8 i;
    u32 n;
    u32 m;
    char *q;
    u32 k;
    void *h;
    for(i=0;i<4;i++) {
        m=MYSTATUS_GetSize();
        n=POKE_TOOL_GetBoxParamSize();
        q=*(char * *)&((struct Obj14127 *)p)->f13C;
        k=i*(m+4+n);
        m=MYSTATUS_GetSize();
        n=POKE_TOOL_GetBoxParamSize();
        MI_CpuCopy8(*(void **)(p+i*0x30+0x8c),q+k,m+4+n);
    }
    h=GFL_NET_HANDLE_GetNetHandle(0xff);
    m=MYSTATUS_GetSize();
    n=POKE_TOOL_GetBoxParamSize();
    return GFL_NET_SendData((u32)h,0xff,0x1102,(m+4+n)*4,(u32)(((struct Obj14127 *)p)->f13C),1,0,1);
}
