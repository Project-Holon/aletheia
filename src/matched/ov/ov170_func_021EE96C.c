/*
 * function: BOX2_UI_CursorInputRight
 * address:  0x021EE96C
 * packet:   pkt_ov170_021EE96C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CURSOR_MOVE_PollRepeatInput 0x02025DE8 thumb
 *   KEY_GetTrg 0x020362DC arm
 *   KEY_GetRepeat 0x0203633C arm
 *   BOX2_MAIN_PlayCursorSound 0x021DD238 thumb
 */
#include "../include/Obj00000.h"
#include "../include/Obj24040.h"

typedef unsigned int u32;


struct Sound;
extern int CURSOR_MOVE_PollRepeatInput(struct Sound *obj);
extern u32 KEY_GetTrg(void);
extern unsigned int KEY_GetRepeat(void);
extern void BOX2_MAIN_PlayCursorSound(char *p);

unsigned BOX2_UI_CursorInputRight(char *p)
{
    unsigned r = CURSOR_MOVE_PollRepeatInput(((struct Obj24040 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f70);
    if (r == -1) {
        if (KEY_GetTrg() & 0x800) {
            BOX2_MAIN_PlayCursorSound(p);
            return 0x28;
        }
        if (KEY_GetRepeat() & 0x200) {
            BOX2_MAIN_PlayCursorSound(p);
            return 0x25;
        }
        if (KEY_GetRepeat() & 0x100) {
            BOX2_MAIN_PlayCursorSound(p);
            return 0x26;
        }
    }
    return r;
}
