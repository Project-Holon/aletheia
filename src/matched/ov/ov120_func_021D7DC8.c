/*
 * function: GTSNEGO_MSG_CreateListUi
 * address: 0x021D7DC8
 * packet: pkt_ov120_021D7DC8
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * follower: existing 021D7E88, 021D7E9C, 021D7EB0 files remain separate.
 * symbols:
 *   GTSNEGO_MSG_DeleteRows 0x021D7C1C thumb ov120
 *   GTSNEGO_MSG_CreateRowEx 0x021D7CD4 thumb ov120
 *   GTSNEGO_MSG_FlushRowLayer 0x021D7D30 thumb ov120
 *   GTSNEGO_MSG_DeleteButtons 0x021D7710 thumb ov120
 *   BUTTON_MAN_Create 0x02051B84 arm
 *   gGtsnegoRowLabelA 0x021D8BD8 data a2
 *   gGtsnegoRowLabelB 0x021D8BE0 data a2
 *   gGtsnegoButtonList 0x021D8B04 data a4
 *   GF_FONT_SetTextColor  0x0201DD78  thumb  arm9
 */
#include "../include/Obj06443.h"
typedef unsigned short u16;
extern const u16 gGtsnegoRowLabelA[],gGtsnegoRowLabelB[];
extern const int gGtsnegoButtonList[];
extern void GTSNEGO_MSG_DeleteRows(char *);
typedef unsigned int   u32;
extern void GF_FONT_SetTextColor(u32 r, u32 g, u32 b);
extern int GTSNEGO_MSG_CreateRowEx(int a, int b, int c, int d);
extern void GTSNEGO_MSG_FlushRowLayer(char *);
extern void GTSNEGO_MSG_DeleteButtons(unsigned char *p);
typedef unsigned char  u8;
extern void *BUTTON_MAN_Create(u8 *a0, int a1, int a2, int a3);
void GTSNEGO_MSG_CreateListUi(char *p,int a,int b,int c,int d,int e)
{
    GTSNEGO_MSG_DeleteRows(p);
    GF_FONT_SetTextColor(15,2,0);
    GTSNEGO_MSG_CreateRowEx((int)p,2,0,0);
    GF_FONT_SetTextColor(15,2,0);
    GTSNEGO_MSG_CreateRowEx((int)p,3,3,6);
    GTSNEGO_MSG_CreateRowEx((int)p,23,1,11);
    GTSNEGO_MSG_CreateRowEx((int)p,24,1,16);
    GF_FONT_SetTextColor(1,2,0);
    ((struct Obj06443 *)p)->f24=GTSNEGO_MSG_CreateRowEx((int)p,gGtsnegoRowLabelA[c],13,6);
    ((struct Obj06443 *)p)->f28=GTSNEGO_MSG_CreateRowEx((int)p,gGtsnegoRowLabelB[d],16,11);
    ((struct Obj06443 *)p)->f2C=GTSNEGO_MSG_CreateRowEx((int)p,gGtsnegoRowLabelB[e],16,16);
    GTSNEGO_MSG_FlushRowLayer(p);
    GTSNEGO_MSG_DeleteButtons((unsigned char *)p);
    ((struct Obj06443 *)p)->f8=BUTTON_MAN_Create((u8 *)gGtsnegoButtonList,a,b,((struct Obj06443 *)p)->fC8);
}
