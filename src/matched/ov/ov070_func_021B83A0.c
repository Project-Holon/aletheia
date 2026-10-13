/*
 * function: func_021B83A0
 * address: 0x021B83A0
 * packet: pkt_ov070_021B83A0
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * EXACT*: two bytes of zero alignment padding follow at 021B83B6.
 * The original explicitly narrows r1 before 0202E448; its extern uses u16.
 * symbols:
 *   func_0202E448 0x0202E448 thumb
 *   GAME_DATA_CheckSaveFlag 0x02012BF8 thumb
 */
#include "../include/Obj20669.h"
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 func_0202E448(u32 id);
extern int GAME_DATA_CheckSaveFlag(int p, int value);
int func_021B83A0(char *p, int value)
{
    return GAME_DATA_CheckSaveFlag(((struct Obj20669 *)p)->f0, (int)func_0202E448((u16)value));
}
