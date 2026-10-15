/*
 * function: WF2DMAP_OBJDRAW_SetFrame
 * address: 0x021C5944
 * packet: pkt_ov127_021C5944
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFI_2DCHAR_GetActorAnimSeqCount 0x021C4280 thumb ov127
 *   WIFI_2DCHAR_GetActorAnimId 0x021C4270 thumb ov127
 *   WIFI_2DCHAR_SetActorAnim 0x021C42A8 thumb ov127
 *   WIFI_2DCHAR_SetActorAnimIndex 0x021C4274 thumb ov127
 *   sWf2dmapSlotFlags 0x021C60AC data a1
 */
#include "../include/Obj00328.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int WIFI_2DCHAR_GetActorAnimSeqCount(char *p);
typedef unsigned int   u32;
extern u32 WIFI_2DCHAR_GetActorAnimId(char *p);
struct obj;
extern void WIFI_2DCHAR_SetActorAnim(struct obj *p, int idx, int a);
extern void WIFI_2DCHAR_SetActorAnimIndex(char *p, u32 a);
extern u8 sWf2dmapSlotFlags[];
void WF2DMAP_OBJDRAW_SetFrame(u8 *p, int n, int a)
{
    int v = WIFI_2DCHAR_GetActorAnimSeqCount(((struct Obj00328 *)p)->f4);
    u16 old = WIFI_2DCHAR_GetActorAnimId(((struct Obj00328 *)p)->f4);
    WIFI_2DCHAR_SetActorAnim(((struct Obj00328 *)p)->f4, n, a);
    if (old != n) {
        if (sWf2dmapSlotFlags[n] == 1 && ((struct Obj00328 *)p)->f10 == n)
            WIFI_2DCHAR_SetActorAnimIndex(((struct Obj00328 *)p)->f4, ((struct Obj00328 *)p)->fE);
        if (sWf2dmapSlotFlags[old] == 1) {
            ((struct Obj00328 *)p)->f10 = old;
            ((struct Obj00328 *)p)->fE = v;
        }
    }
}
