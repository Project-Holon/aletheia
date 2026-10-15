/*
 * function: WF2DMAP_OBJDRAW_DeleteAnimSeq
 * address: 0x021C5608
 * packet: pkt_ov127_021C5608
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 021C5656 follow the return.
 * symbols:
 *   WF2DMAP_OBJDRAW_IsActorFree 0x021C58B8 thumb ov127
 *   WF2DMAP_OBJDRAW_RemoveActor 0x021C5704 thumb ov127
 *   WIFI_2DCHAR_ReleaseBmp 0x021C40B4 thumb ov127
 *   WF2DMAP_OBJDRAW_DeleteSprite 0x021C5658 thumb ov127
 *   WIFI_2DCHAR_Delete 0x021C3F80 thumb ov127
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj05374.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int WF2DMAP_OBJDRAW_IsActorFree(char *p);
extern void WF2DMAP_OBJDRAW_RemoveActor(u8 *p);
extern void WIFI_2DCHAR_ReleaseBmp(u8 *p);
extern void WF2DMAP_OBJDRAW_DeleteSprite(void *);
extern void WIFI_2DCHAR_Delete(u8 *p);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void WF2DMAP_OBJDRAW_DeleteAnimSeq(u8 *p)
{
    int i;
    for (i = 0; i < ((struct Obj05374 *)p)->f8; i++) {
        int offset = i * 20;
        if (!WF2DMAP_OBJDRAW_IsActorFree((char *)(*(u8 * *)&((struct Obj05374 *)p)->f4+offset)))
            WF2DMAP_OBJDRAW_RemoveActor(*(u8 * *)&((struct Obj05374 *)p)->f4+offset);
    }
    WIFI_2DCHAR_ReleaseBmp(((struct Obj05374 *)p)->f0);
    WF2DMAP_OBJDRAW_DeleteSprite(p);
    WIFI_2DCHAR_Delete(((struct Obj05374 *)p)->f0);
    func_020307B0(((struct Obj05374 *)p)->f4);
    func_020307B0(p);
}
