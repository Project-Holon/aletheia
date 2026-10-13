/*
 * function: GAME_BEACON_ACCESSOR_GetFreeText
 * address:  0x02165D8C
 * packet:   pkt_02165D8C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   STRBUF_Clear  0x0204581C  arm
 *   STRBUF_SetString  0x02045924  arm
 */
#include "../include/Obj17725.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int STRBUF_Clear();
extern int STRBUF_SetString();

int GAME_BEACON_ACCESSOR_GetFreeText(int a0, int a1)
{
    int a2;

a2 = a0 + 0;
a0 = ((struct Obj17725 *)a2)->f30;
    if (a0 == 0x31) goto loc_02165D9E;
loc_02165D96:
a0 = a1 + 0;
    a0 = STRBUF_Clear(a0);
loc_02165D9C:
    return a0;
loc_02165D9E:
a2 = a2 + 0x34;
a0 = a1 + 0;
a1 = a2 + 0;
    a0 = STRBUF_SetString(a0, a1);
loc_02165DA8:
    return a0;}
