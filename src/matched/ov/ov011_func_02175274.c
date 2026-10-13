/*
 * function: INTRUDE_COMM_AdjustAllRemotePositions
 * address:  0x02175274
 * packet:   pkt_ov011_02175274
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_COMM_GetGameData  0x02026478  thumb
 *   GAME_DATA_GetExitMode  0x02012B58  thumb
 *   INTRUDE_COMM_AdjustRemotePosition  0x021751D4  thumb ov011
 */
#include "../include/Obj12425.h"
#include "../include/Obj19182.h"

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct C12 {
    int w[3];
} C12;

typedef unsigned int   u32;
struct BigObj;
struct Ent;
u32 GAME_COMM_GetGameData(void *obj);
u8 GAME_DATA_GetExitMode(const struct BigObj *p);
void INTRUDE_COMM_AdjustRemotePosition(u8 *p, u16 a, int b, struct Ent *c);

void INTRUDE_COMM_AdjustAllRemotePositions(u8 *p, int arg)
{
    u8 *arr;
    u8 *h;
    int n;
    int i;
    u8 *e;

    n = GAME_DATA_GetExitMode((const struct BigObj *)GAME_COMM_GetGameData((void *)(((struct Obj12425 *)p)->f4)));
    h = p + 0x70;
    i = 0;
    arr = p + 0x8C;
    for (; i < 3; i++) {
        if ((p[0x8FB] & (1 << i)) && i != n) {
            e = arr + i * 0x1C;
            *(C12 *)(e + 4) = *(C12 *)(p + 0xE4 + i * 0x14);
            INTRUDE_COMM_AdjustRemotePosition(p, ((struct Obj19182 *)h)->f14, arg, (struct Ent *)e);
        }
    }
}
