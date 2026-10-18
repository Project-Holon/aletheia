/*
 * function: BOX2_MAIN_PlayCursorSound
 * address:  0x021DD238
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   UI_SetInputMode  0x020355D8  arm  arm9
 *   CURSOR_MOVE_GetState  0x020260F0  thumb  arm9
 *   CURSOR_MOVE_SetState  0x020260F4  thumb  arm9
 *
 * Enable the pooled object when it reports zero.
 */
#include "../include/Obj00000.h"
#include "../include/Obj18441.h"
#include "../include/Obj18442.h"

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Sound;
struct Struct_02025CD0;
extern void UI_SetInputMode(u8 v);
extern u32 CURSOR_MOVE_GetState(struct Sound *obj);
extern void CURSOR_MOVE_SetState(struct Struct_02025CD0 *obj, u32 state);

void BOX2_MAIN_PlayCursorSound(char *p)
{
    UI_SetInputMode(0);
    if (CURSOR_MOVE_GetState(((struct Obj18441 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f70) == 0)
        CURSOR_MOVE_SetState(((struct Obj18442 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f70, 1);
}

