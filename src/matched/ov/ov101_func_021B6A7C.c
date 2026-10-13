/*
 * function: IRC_COMPATIBLE_HandleMenu
 * address: 0x021B6A7C
 * packet: pkt_ov101_021B6A7C
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   IRC_COMPATIBLE_StepRunnerRun 0x021B6C20 thumb ov101
 *   IRC_COMPATIBLE_SetHandler 0x021B6A3C thumb ov101
 *   IRC_COMPATIBLE_HandleTests 0x021B6AD8 thumb ov101
 *   IRC_COMPATIBLE_HandleHelp 0x021B6BA8 thumb ov101
 *   IRC_COMPATIBLE_HandleQuit 0x021B6A60 thumb ov101
 */
#include "../include/Obj22111.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int IRC_COMPATIBLE_StepRunnerRun(int *p, int index, int heap, int arg);
extern void IRC_COMPATIBLE_SetHandler(u8 *,u32);
extern void IRC_COMPATIBLE_HandleTests(u8 *p, u16 *state);
extern void IRC_COMPATIBLE_HandleHelp(u8 *p, u16 *state);
extern void IRC_COMPATIBLE_HandleQuit(u8 *p, u16 *state);
void IRC_COMPATIBLE_HandleMenu(u8 *p,u16 *state)
{
    switch(*state) {
    case 0:
        if(IRC_COMPATIBLE_StepRunnerRun((int *)(p+4),0,58,(int)p)) *state=1;
        break;
    case 1:
        switch(((struct Obj22111 *)p)->f20) {
        case 0: IRC_COMPATIBLE_SetHandler(p,(u32)IRC_COMPATIBLE_HandleTests); break;
        case 1: IRC_COMPATIBLE_SetHandler(p,(u32)IRC_COMPATIBLE_HandleHelp); break;
        case 2: IRC_COMPATIBLE_SetHandler(p,(u32)IRC_COMPATIBLE_HandleQuit); break;
        }
        break;
    }
}
