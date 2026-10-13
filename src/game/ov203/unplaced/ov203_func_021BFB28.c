/*
 * function: func_021BFB28
 * address:  0x021BFB28
 * packet:   pkt_021BFB28
 * region:   ov203
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BFB28 0x021BFB28 thumb
 *   UI_SCENE_FreeActorGfx 0x021B6284 thumb
 *   func_020307B0 0x020307B0 arm
 */
#include "../../../matched/include/Obj14601.h"

typedef unsigned char u8;

extern void UI_SCENE_FreeActorGfx(void *);

#pragma thumb off
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
#pragma thumb on

void func_021BFB28(char *arg0)
{
    char *ptr = *(char * *)&((struct Obj14601 *)arg0)->f10;
    UI_SCENE_FreeActorGfx(ptr + 4);
    ptr = *(char * *)&((struct Obj14601 *)arg0)->f10;
    func_020307B0(ptr);
}
