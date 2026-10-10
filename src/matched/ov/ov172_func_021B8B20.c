/*
 * function: func_021B8B20
 * address: 0x021B8B20
 * packet: pkt_ov172_021B8B20
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov172/ctvt_comm_p03.c and filed here.
 *
 * symbols:
 *   func_021B8B94 0x021B8B94 thumb
 */

#include "../include/Obj24087.h"

typedef unsigned char  u8;
char *func_021B8B20(int i, char *q);
char *func_021B8B94(int unused, char *base, int i);

char *func_021B8B20(int i, char *q)
{
    return func_021B8B94((int)((struct Obj24087 *)q)->f3DC, q, (u8)i);
}
