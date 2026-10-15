/*
 * function: INTRUDE_COMM_VIEW_SelectRow
 * address: 0x021D4C50
 * packet: pkt_ov122_021D4C50
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   INTRUDE_COMM_GetRequestState 0x02158630 thumb ov010
 *   INTRUDE_COMM_VIEW_AnimateSelectedRow 0x021D4BF4 thumb ov122
 *   INTRUDE_COMM_VIEW_SetCallback 0x021D4244 thumb ov122
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb  arm9
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "../include/Obj05359.h"
#include "../include/Obj22931.h"
struct Ctx;
extern unsigned int GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern int INTRUDE_COMM_GetRequestState(int a);
typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void INTRUDE_COMM_VIEW_AnimateSelectedRow(char *p);
extern void INTRUDE_COMM_VIEW_SetCallback(void *p, u32 a, int a2);
int INTRUDE_COMM_VIEW_SelectRow(int value, char *p)
{
    void *obj;
    obj = (void *)GAMESYSTEM_GetGameComm(((struct Obj05359 *)p)->f354);
    ((struct Obj05359 *)p)->f35C = value;
    switch (value) {
    case 0:
    case 3:
        ((struct Obj22931 *)(*(char * *)&((struct Obj05359 *)p)->f344))->f28 = INTRUDE_COMM_GetRequestState((int)obj);
        ((struct Obj05359 *)p)->f8 = 0;
        GFL_USE_PlaySeDefaultVolume(0x73b);
        INTRUDE_COMM_VIEW_SetCallback(p, (u32)INTRUDE_COMM_VIEW_AnimateSelectedRow, 0x3c4);
        break;
    case 1:
    case 4:
        ((struct Obj05359 *)p)->f8 = 1;
        GFL_USE_PlaySeDefaultVolume(0x73b);
        INTRUDE_COMM_VIEW_SetCallback(p, (u32)INTRUDE_COMM_VIEW_AnimateSelectedRow, 0x3cd);
        break;
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x73c);
        ((struct Obj05359 *)p)->f8 = 2;
        INTRUDE_COMM_VIEW_SetCallback(p, (u32)INTRUDE_COMM_VIEW_AnimateSelectedRow, 0x3d3);
        break;
    }
    return 1;
}
