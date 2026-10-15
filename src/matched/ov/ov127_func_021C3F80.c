/*
 * function: WIFI_2DCHAR_Delete
 * address: 0x021C3F80
 * packet: pkt_ov127_021C3F80
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WF2DMAP_MAP_IsEmpty 0x021C4790 thumb ov127
 *   WIFI_2DCHAR_DeleteActor 0x021C41BC thumb ov127
 *   WIFI_2DCHAR_ReleaseCellAnims 0x021C4330 thumb ov127
 *   WIFI_2DCHAR_ReleaseCells 0x021C4010 thumb ov127
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj05371.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int WF2DMAP_MAP_IsEmpty(char *p);
extern void WIFI_2DCHAR_DeleteActor(u8 *p);
extern void WIFI_2DCHAR_ReleaseCellAnims(char *p, int a1);
extern void WIFI_2DCHAR_ReleaseCells(u8 *p);
extern void ARC_TOOL_DeleteHandle(u32);
extern u32 func_020307B0(void *p);
void WIFI_2DCHAR_Delete(u8 *p)
{
    u32 i;
    for (i = 0; i < ((struct Obj05371 *)p)->fC; i++) {
        if (!WF2DMAP_MAP_IsEmpty((char *)(*(u8 * *)&((struct Obj05371 *)p)->f8 + i * 24)))
            WIFI_2DCHAR_DeleteActor(*(u8 * *)&((struct Obj05371 *)p)->f8 + i * 24);
    }
    WIFI_2DCHAR_ReleaseCellAnims((char *)p, 0);
    WIFI_2DCHAR_ReleaseCells(p);
    ARC_TOOL_DeleteHandle(((struct Obj05371 *)p)->f2F8);
    ARC_TOOL_DeleteHandle(((struct Obj05371 *)p)->f2FC);
    func_020307B0(((struct Obj05371 *)p)->f8);
    func_020307B0(p);
}
