/*
 * function: OEKAKI_RecvReset
 * address:  0x02184320
 * packet:   pkt_ov023_02184320
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   OEKAKI_HandleEvent  0x02185AB0  thumb  ov023
 *   MIi_CpuClearFast  0x02082AC0  arm
 *   UNION_APP_GetMemberCount  0x021841A4  thumb  ov022
 *   UNION_APP_GetJoinedBits  0x021841A0  thumb  ov022
 */
#include "../include/Obj06117.h"

typedef unsigned int u32;

extern void OEKAKI_HandleEvent(char *p, int a, int b);
extern void MIi_CpuClearFast(int v, char *dst, u32 n);
extern int UNION_APP_GetMemberCount(unsigned char *p);
extern unsigned char UNION_APP_GetJoinedBits(unsigned char *p);

void OEKAKI_RecvReset(int a0, int a1, int a2, char *p)
{
    OEKAKI_HandleEvent(p, 3, 0);
    MIi_CpuClearFast(0, p + 0x4290, 0x3840);
    ((struct Obj06117 *)p)->f1AC = UNION_APP_GetMemberCount((unsigned char *)(*(u32 *)*(u32 * *)&((struct Obj06117 *)p)->f4));
    ((struct Obj06117 *)p)->f1B0 = UNION_APP_GetJoinedBits((unsigned char *)(*(u32 *)*(u32 * *)&((struct Obj06117 *)p)->f4));
    ((struct Obj06117 *)p)->f9E6C = 1;
}
