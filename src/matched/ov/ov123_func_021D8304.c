/*
 * function: GSYNC_STATE_StateOpenConfirmMenu
 * address: 0x021D8304
 * packet: pkt_ov123_021D8304
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_MESSAGE_UpdateStream 0x021D580C thumb ov123
 *   GSYNC_MESSAGE_OpenYesNoMenu 0x021D5890 thumb ov123
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateConfirmMenuSelect 0x021D8270 thumb ov123
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "../include/Obj06466.h"
typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern int GSYNC_MESSAGE_UpdateStream(char *);
extern int GSYNC_MESSAGE_OpenYesNoMenu(char *p, int mode);
typedef unsigned char  u8;
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateConfirmMenuSelect(char *p);
void GSYNC_STATE_StateOpenConfirmMenu(char *p)
{
    if (((struct Obj06466 *)p)->f64 % 110 == 0) GFL_USE_PlaySeDefaultVolume(0x659);
    (((struct Obj06466 *)p)->f64)++;
    if (GSYNC_MESSAGE_UpdateStream(*(char * *)&((struct Obj06466 *)p)->f18)) {
        ((struct Obj06466 *)p)->f1C = (void *)GSYNC_MESSAGE_OpenYesNoMenu(*(char * *)&((struct Obj06466 *)p)->f18, 0);
        GSYNC_STATE_ChangeState((u8 *)p, (int)GSYNC_STATE_StateConfirmMenuSelect, 0x632);
    }
}
