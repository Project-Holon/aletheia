/*
 * function: B_BAG_MAIN_StateChooseItem
 * address: 0x0220D024
 * packet: pkt_ov197_0220D024
 * region: ov197
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   B_BAG_MAIN_CheckCancel 0x0220D884 thumb ov197
 *   CURSOR_MOVE_PollRepeatInput 0x02025DE8 thumb
 *   B_BAG_MAIN_PlaySe 0x0220D89C thumb ov197
 *   B_BAG_MAIN_GetSlotItem 0x0220BB98 thumb ov197
 *   B_BAG_MAIN_GetItemFlag 0x0220BBD8 thumb ov197
 *   B_BAG_MAIN_StartFrameAnim 0x0220BF20 thumb ov197
 *   B_BAG_MAIN_StateShowMessage 0x0220D11C thumb ov197
 */
#include "../include/Obj02245.h"
#include "../include/Obj25081.h"
#include "../include/Obj25082.h"
#include "../include/Obj25083.h"
#include "../include/Obj25084.h"
#include "../include/Obj25085.h"
#include "../include/Obj25086.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int B_BAG_MAIN_CheckCancel(char **);
typedef unsigned int   u32;
struct Sound;
extern int CURSOR_MOVE_PollRepeatInput(struct Sound *obj);
extern void B_BAG_MAIN_PlaySe(char **, int);
extern unsigned B_BAG_MAIN_GetSlotItem(const char *p, unsigned n);
extern int B_BAG_MAIN_GetItemFlag(u32 key);
extern void B_BAG_MAIN_StartFrameAnim(char *, int);
extern int B_BAG_MAIN_StateShowMessage(char *);
int B_BAG_MAIN_StateChooseItem(char *p)
{
    if (B_BAG_MAIN_CheckCancel((char **)p) == 1) return 0x12;
    switch ((unsigned)CURSOR_MOVE_PollRepeatInput(((struct Obj02245 *)p)->f144)) {
    case 0:
        B_BAG_MAIN_PlaySe((char **)p, 0x54d);
        ((struct Obj25081 *)(*(char * *)&((struct Obj02245 *)p)->f0))->f16 = B_BAG_MAIN_GetSlotItem(p, *(short *)(*(char * *)&((struct Obj02245 *)p)->f0 + ((struct Obj02245 *)p)->f533 * 2 + 0x30));
        ((struct Obj25082 *)(*(char * *)&((struct Obj02245 *)p)->f0))->f2A = ((struct Obj02245 *)p)->f533;
        if (((struct Obj25083 *)(*(char * *)&((struct Obj02245 *)p)->f0))->f8 == 1)
            ((struct Obj25085 *)(*(char * *)&((struct Obj02245 *)p)->f0))->f18 = B_BAG_MAIN_GetItemFlag(((struct Obj25084 *)(*(char * *)&((struct Obj02245 *)p)->f0))->f16);
        else
            ((struct Obj25086 *)(*(char * *)&((struct Obj02245 *)p)->f0))->f18 = 0;
        B_BAG_MAIN_StartFrameAnim(p, 0xd);
        return B_BAG_MAIN_StateShowMessage(p);
    case 1:
        B_BAG_MAIN_PlaySe((char **)p, 0x552);
        ((struct Obj02245 *)p)->f531 = 8;
        B_BAG_MAIN_StartFrameAnim(p, 0xa);
        return 0x10;
    case (unsigned)-2:
        B_BAG_MAIN_PlaySe((char **)p, 0x552);
        ((struct Obj02245 *)p)->f531 = 8;
        B_BAG_MAIN_StartFrameAnim(p, 0xa);
        return 0x10;
    case (unsigned)-4:
    case (unsigned)-3:
        B_BAG_MAIN_PlaySe((char **)p, 0x548);
        break;
    case (unsigned)-8:
    case (unsigned)-7:
    case (unsigned)-6:
    case (unsigned)-5:
    case (unsigned)-1:
        break;
    }
    return 6;
}
