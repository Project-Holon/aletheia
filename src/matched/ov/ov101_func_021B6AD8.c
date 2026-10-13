/*
 * function: IRC_COMPATIBLE_HandleTests
 * address: 0x021B6AD8
 * packet: pkt_ov101_021B6AD8
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: full own C20 body reads/forwards fourth int arg; original r3=p
 *   remains live into all three calls, preserved as the same full-word payload.
 * symbols:
 *   IRC_COMPATIBLE_StepRunnerRun 0x021B6C20 thumb ov101
 *   IRC_COMPATIBLE_SetHandler 0x021B6A3C thumb ov101
 *   IRC_COMPATIBLE_HandleMenu 0x021B6A7C thumb ov101
 */
#include "../include/Obj02808.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int IRC_COMPATIBLE_StepRunnerRun(int *,int,int,int);
extern void IRC_COMPATIBLE_SetHandler(u8 *,u32);
extern void IRC_COMPATIBLE_HandleMenu(u8 *,u16 *);
void IRC_COMPATIBLE_HandleTests(u8 *p,u16 *state)
{
    switch(*state) {
    case 0:
        p[0x2e]=0;
        p[0x2c]=0;
        *state=1;
        break;
    case 1:
        if(IRC_COMPATIBLE_StepRunnerRun((int *)(p+4),2,0x3a,(int)p)) *state=2;
        break;
    case 2:
        if(((struct Obj02808 *)p)->f28==0) *state=3;
        else if(((struct Obj02808 *)p)->f28==2) {
            p[0x2e]=0;
            p[0x2c]=0;
            *state=5;
        } else *state=6;
        break;
    case 3:
        if(IRC_COMPATIBLE_StepRunnerRun((int *)(p+4),1,0x3a,(int)p)) *state=4;
        break;
    case 4:
        if(((struct Obj02808 *)p)->f24==0) *state=5;
        else if(((struct Obj02808 *)p)->f24==2) {
            p[0x2e]=0;
            p[0x2c]=0;
            *state=5;
        } else *state=6;
        break;
    case 5:
        if(IRC_COMPATIBLE_StepRunnerRun((int *)(p+4),3,0x3a,(int)p)) *state=6;
        break;
    case 6:
        IRC_COMPATIBLE_SetHandler(p,(u32)IRC_COMPATIBLE_HandleMenu);
        break;
    }
}
