/*
 * function: B_BAG_MAIN_StateSelectPocket
 * address: 0x0220CC18
 * packet: pkt_ov197_0220CC18
 * region: ov197
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PALANM_GetFadeRequestBits 0x02021ED8 thumb
 *   B_BAG_MAIN_CheckCancel 0x0220D884 thumb ov197
 *   CURSOR_MOVE_PollRepeatInput 0x02025DE8 thumb
 *   B_BAG_MAIN_PlaySe 0x0220D89C thumb ov197
 *   B_BAG_MAIN_StartFrameAnim 0x0220BF20 thumb ov197
 *   B_BAG_MAIN_SyncCursorToItem 0x0220B9D8 thumb ov197
 */
#include "../include/Obj02244.h"
#include "../include/Obj25069.h"
#include "../include/Obj25070.h"
#include "../include/Obj25071.h"
#include "../include/Obj25072.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Sound;
extern u32 PALANM_GetFadeRequestBits(const char *ptr);
extern int B_BAG_MAIN_CheckCancel(char **);
extern int CURSOR_MOVE_PollRepeatInput(struct Sound *obj);
extern void B_BAG_MAIN_PlaySe(char **, int);
extern void B_BAG_MAIN_StartFrameAnim(char *, int);
extern void B_BAG_MAIN_SyncCursorToItem(u8 *p);
int B_BAG_MAIN_StateSelectPocket(char *p)
{
    unsigned sel;
    if (PALANM_GetFadeRequestBits(((struct Obj02244 *)p)->f8) != 0) goto done;
    if (B_BAG_MAIN_CheckCancel((char **)p) == 1) return 0x12;
    sel = CURSOR_MOVE_PollRepeatInput(((struct Obj02244 *)p)->f144);
    switch (sel) {
    case 0: case 1: case 2: case 3:
        B_BAG_MAIN_PlaySe((char **)p, 0x54d);
        ((struct Obj02244 *)p)->f533 = (u8)sel;
        ((struct Obj02244 *)p)->f531 = 8;
        B_BAG_MAIN_StartFrameAnim(p, (u8)sel);
        return 0x10;
    case 4:
        if (((struct Obj02244 *)p)->f540 != 0) {
            B_BAG_MAIN_PlaySe((char **)p, 0x54d);
            ((struct Obj02244 *)p)->f533 = ((struct Obj02244 *)p)->f542;
            ((struct Obj02244 *)p)->f531 = 9;
            B_BAG_MAIN_SyncCursorToItem((u8 *)p);
            B_BAG_MAIN_StartFrameAnim(p, 0xd);
            return 0x10;
        }
        break;
    case 5:
        B_BAG_MAIN_PlaySe((char **)p, 0x552);
        ((struct Obj25069 *)(*(char * *)&((struct Obj02244 *)p)->f0))->f16 = 0;
        ((struct Obj25070 *)(*(char * *)&((struct Obj02244 *)p)->f0))->f2A = 4;
        B_BAG_MAIN_StartFrameAnim(p, 0xa);
        return 0x12;
    case (unsigned)-2:
        B_BAG_MAIN_PlaySe((char **)p, 0x552);
        ((struct Obj25071 *)(*(char * *)&((struct Obj02244 *)p)->f0))->f16 = 0;
        ((struct Obj25072 *)(*(char * *)&((struct Obj02244 *)p)->f0))->f2A = 4;
        B_BAG_MAIN_StartFrameAnim(p, 0xa);
        return 0x12;
    case (unsigned)-4: case (unsigned)-3:
        B_BAG_MAIN_PlaySe((char **)p, 0x548);
        break;
    case (unsigned)-8: case (unsigned)-7: case (unsigned)-6:
    case (unsigned)-5: case (unsigned)-1:
        break;
    }
done:
    return 4;
}
