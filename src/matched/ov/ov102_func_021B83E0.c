/*
 * function: IRC_COMPATIBLE_MENU_HandleCheckLink
 * address: 0x021B83E0
 * packet: pkt_ov102_021B83E0
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   COMPATIBLE_IRC_SYS_GetValueDifference 0x021B6480 thumb ov101
 *   COMPATIBLE_IRC_SYS_IsPartnerReady 0x021B62FC thumb ov101
 *   COMPATIBLE_IRC_SYS_SetOwnValue 0x021B63CC thumb ov101
 *   IRC_COMPATIBLE_MENU_SetHandler 0x021B7F08 thumb ov102
 *   IRC_COMPATIBLE_MENU_HandleFinish 0x021B82DC thumb ov102
 *   IRC_COMPATIBLE_MENU_HandleChoice 0x021B81B0 thumb ov102
 */
#include "../include/Obj07977.h"
#include "../include/Obj22159.h"
#include "../include/Obj22160.h"
#include "../include/Obj22161.h"
#include "../include/Obj22162.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int COMPATIBLE_IRC_SYS_GetValueDifference(int *);
extern int COMPATIBLE_IRC_SYS_IsPartnerReady(int *);
extern void COMPATIBLE_IRC_SYS_SetOwnValue(int *, int);
extern void IRC_COMPATIBLE_MENU_SetHandler(unsigned p, unsigned x);
extern void IRC_COMPATIBLE_MENU_HandleFinish(u8 *, u16 *);
extern void IRC_COMPATIBLE_MENU_HandleChoice(u8 *, u16 *);
void IRC_COMPATIBLE_MENU_HandleCheckLink(u8 *p)
{
    COMPATIBLE_IRC_SYS_GetValueDifference(*(int * *)&((struct Obj22159 *)(*(u8 * *)&((struct Obj07977 *)p)->f48C))->f4);
    if (COMPATIBLE_IRC_SYS_IsPartnerReady(*(int * *)&((struct Obj22160 *)(*(u8 * *)&((struct Obj07977 *)p)->f48C))->f4)) {
        COMPATIBLE_IRC_SYS_SetOwnValue(*(int * *)&((struct Obj22161 *)(*(u8 * *)&((struct Obj07977 *)p)->f48C))->f4, 1);
        ((struct Obj22162 *)(*(u8 * *)&((struct Obj07977 *)p)->f48C))->fC = 0;
        IRC_COMPATIBLE_MENU_SetHandler((unsigned int)p, (unsigned int)IRC_COMPATIBLE_MENU_HandleFinish);
    } else {
        IRC_COMPATIBLE_MENU_SetHandler((unsigned int)p, (unsigned int)IRC_COMPATIBLE_MENU_HandleChoice);
    }
}
