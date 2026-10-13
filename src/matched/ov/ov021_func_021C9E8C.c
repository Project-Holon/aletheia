/*
 * function: BSUBWAY_SCR_DrawTrainerNos
 * address:  0x021C9E8C
 * packet:   pkt_ov021_021C9E8C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Fills the +0x32 halfword list with distinct draws: 14 for kinds 2, 3, 7, 8, else 7.
 *
 * symbols:
 *   BSUBWAY_SCR_GetWinCount  0x021CA234  thumb
 *   BSUBWAY_SCR_GetStageNo  0x021CA2CC  thumb
 *   BSUBWAY_SCR_DrawTrainerNo  0x021CBD90  thumb
 *   BSUBWAY_SCR_IsTrainerNoUsed  0x021CA2A4  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj05094.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 BSUBWAY_SCR_GetWinCount(u8 *p);
extern u16 BSUBWAY_SCR_GetStageNo(u16 v);
extern u16 BSUBWAY_SCR_DrawTrainerNo(void *ctx, u32 round, u32 stage, u32 line, u8 alt);
extern int BSUBWAY_SCR_IsTrainerNoUsed(const u16 *arr, u16 val, u16 n);

void BSUBWAY_SCR_DrawTrainerNos(u8 *p)
{
    u8 kind = p[9];
    u16 lim = BSUBWAY_SCR_GetStageNo(BSUBWAY_SCR_GetWinCount(p));
    int i;
    u16 v;

    if (kind == 2 || kind == 3 || kind == 7 || kind == 8) {
        if (lim < ((struct Obj05094 *)p)->f18)
            lim = ((struct Obj05094 *)p)->f18;
        for (i = 0; i < 14; i++) {
            do {
                v = BSUBWAY_SCR_DrawTrainerNo(p, lim, (u8)(i / 2), kind, (u8)(i & 1));
            } while (BSUBWAY_SCR_IsTrainerNoUsed((u16 *)(p + 0x32), v, i));
            ((u16 *)(p + 0x32))[i] = v;
        }
    } else {
        for (i = 0; i < 7; i++) {
            do {
                v = BSUBWAY_SCR_DrawTrainerNo(p, lim, (u8)i, p[9], 0);
            } while (BSUBWAY_SCR_IsTrainerNoUsed((u16 *)(p + 0x32), v, i));
            ((u16 *)(p + 0x32))[i] = v;
        }
    }
}
