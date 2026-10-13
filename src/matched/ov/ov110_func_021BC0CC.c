/*
 * function: PMSIV_EDIT_ApplyPalette
 * address: 0x021BC0CC
 * packet: pkt_ov110_021BC0CC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMS_INPUT_GetInputMode 0x021BF6D8 thumb ov110
 *   PMS_INPUT_GetSentenceType 0x021BF6E4 thumb ov110
 *   GX_LoadBGPltt 0x0207E3D0 arm
 *   func_0207E468 0x0207E468 arm
 */
#include "../include/Obj10276.h"
typedef unsigned char u8;
extern unsigned PMS_INPUT_GetInputMode(u8 *);
extern int PMS_INPUT_GetSentenceType(u8 *p);
extern void GX_LoadBGPltt(void *,int,int);
extern void func_0207E468(void *,int,int);
void PMSIV_EDIT_ApplyPalette(u8 *p)
{
    if (PMS_INPUT_GetInputMode(*(u8 * *)&((struct Obj10276 *)p)->f4)==2 && (unsigned)PMS_INPUT_GetSentenceType(*(u8 * *)&((struct Obj10276 *)p)->f4)<5) {
        unsigned n=(unsigned)PMS_INPUT_GetSentenceType(*(u8 * *)&((struct Obj10276 *)p)->f4)+1;
        GX_LoadBGPltt(p+0x58+n*32,0,32);
        func_0207E468(p+0x58+n*32,0,32);
    } else {
        GX_LoadBGPltt(p+0x58,0,32);
        func_0207E468(p+0x58,0,32);
    }
}
