/*
 * function: GTSNEGO_MSG_CreateYesNoUi
 * address: 0x021D7D6C
 * packet: pkt_ov120_021D7D6C
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GTSNEGO_MSG_DeleteRows 0x021D7C1C thumb ov120
 *   GTSNEGO_MSG_CreateRow 0x021D7C48 thumb ov120
 *   GTSNEGO_MSG_FlushRowLayer 0x021D7D30 thumb ov120
 *   GTSNEGO_MSG_DeleteButtons 0x021D7710 thumb ov120
 *   BUTTON_MAN_Create 0x02051B84 arm
 *   gGtsnegoButtonYesNo 0x021D8AF8 data a4
 */
#include "../include/Obj13937.h"
typedef unsigned short u16;
extern const int gGtsnegoButtonYesNo[];
extern void GTSNEGO_MSG_DeleteRows(char *);
extern int GTSNEGO_MSG_CreateRow(unsigned char *p, int n, int a, int b, int c, int d);
extern void GTSNEGO_MSG_FlushRowLayer(char *);
extern void GTSNEGO_MSG_DeleteButtons(unsigned char *p);
typedef unsigned char  u8;
extern void *BUTTON_MAN_Create(u8 *a0, int a1, int a2, int a3);
void GTSNEGO_MSG_CreateYesNoUi(char *p,int a,int b)
{
    GTSNEGO_MSG_DeleteRows(p);
    GTSNEGO_MSG_CreateRow((unsigned char *)p,0,8,7,16,6);
    GTSNEGO_MSG_CreateRow((unsigned char *)p,1,8,13,16,6);
    GTSNEGO_MSG_FlushRowLayer(p);
    GTSNEGO_MSG_DeleteButtons((unsigned char *)p);
    ((struct Obj13937 *)p)->f8=BUTTON_MAN_Create((u8 *)gGtsnegoButtonYesNo,a,b,((struct Obj13937 *)p)->fC8);
}
