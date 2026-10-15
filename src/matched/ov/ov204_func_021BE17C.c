/*
 * function: INTRO_GRAPHIC_CmdMenu
 * address: 0x021BE17C
 * packet: pkt_ov204_021BE17C
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 021BE1EE..021BE1F0 is two zero alignment bytes.
 * symbols:
 *   INTRO_MSG_CreateMenuList 0x021BF384 thumb ov204
 *   INTRO_MSG_MainMenuList 0x021BF528 thumb ov204
 *   INTRO_MSG_GetMenuChoice 0x021BF538 thumb ov204
 *   INTRO_GRAPHIC_DrawMenuEntry 0x021BE138 thumb ov204
 */
#include "../include/Obj04608.h"
typedef struct { int a, b; } Pair;
typedef struct { Pair first, second; } Request;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void INTRO_MSG_CreateMenuList(char *p, u32 *entries, u32 count, int flag);
extern void INTRO_MSG_MainMenuList(u8 *p);
extern int INTRO_MSG_GetMenuChoice(u8 *p, int *out);
extern void INTRO_GRAPHIC_DrawMenuEntry(char *, int);
int INTRO_GRAPHIC_CmdMenu(char *p, int *state, int *values)
{
    Request request;
    int result, choice;
    switch (*state) {
    case 0:
        request.first.a = values[0];
        request.first.b = 0;
        request.second.a = values[1];
        request.second.b = 1;
        INTRO_MSG_CreateMenuList(*(char * *)&((struct Obj04608 *)p)->f18, (u32 *)(&request), 2, values[2]);
        ++*state;
        break;
    case 1:
        INTRO_MSG_MainMenuList((u8 *)(*(char * *)&((struct Obj04608 *)p)->f18));
        result = INTRO_MSG_GetMenuChoice((u8 *)(*(char * *)&((struct Obj04608 *)p)->f18), &choice);
        if (result == 1) { INTRO_GRAPHIC_DrawMenuEntry(p, choice); return 1; }
        if (result == 2) { INTRO_GRAPHIC_DrawMenuEntry(p, 1); return 1; }
        break;
    }
    return 0;
}
