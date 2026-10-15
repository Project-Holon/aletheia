/*
 * function: SCRIPT_COMMAND_TaskCameraPos
 * address: 0x021FB0DC
 * packet: pkt_ov132_021FB0DC
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STA_ACT_SCRIPT_StepTaskInt 0x021FAE1C thumb ov132
 *   STA_ACTING_SetCameraPos 0x021F9E00 thumb ov132
 *   STA_ACT_SCRIPT_RemoveTask 0x021FADF8 thumb ov132
 */
#include "../include/Obj10547.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int STA_ACT_SCRIPT_StepTaskInt(char *, int *);
extern void STA_ACTING_SetCameraPos(void *, u16);
extern void STA_ACT_SCRIPT_RemoveTask(char *, char *);
void SCRIPT_COMMAND_TaskCameraPos(void *unused, char *p)
{
    int v;
    int done = STA_ACT_SCRIPT_StepTaskInt(p, &v);
    STA_ACTING_SetCameraPos(((struct Obj10547 *)p)->f0, v);
    if (done == 1) STA_ACT_SCRIPT_RemoveTask(*(char * *)&((struct Obj10547 *)p)->f10, *(char * *)&((struct Obj10547 *)p)->f14);
}
