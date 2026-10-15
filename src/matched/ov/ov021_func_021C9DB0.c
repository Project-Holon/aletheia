/*
 * function: BSUBWAY_SCR_AddBattlePoint
 * address:  0x021C9DB0
 * packet:   pkt_ov021_021C9DB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Picks a step amount from a 7x10 byte table by mode byte +9 and a clamped
 * counter, adds it to the record at +0x74 and returns it.
 *
 * symbols:
 *   GDS_PROFILE_GetFieldRecField  0x0200D884  thumb
 *   GDS_PROFILE_GetScoreRecLevel  0x0200DC08  thumb
 *   GDS_PROFILE_GetScoreRecCountCDec  0x0200DB80  thumb
 *   GDS_PROFILE_AddScoreRecTotal  0x0200DA80  thumb
 *   d_021DACDC     0x021DACDC  data  a1
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04291.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

typedef struct { u16 b0 : 1; u16 b1 : 2; } Bits;

struct Blk1AC;
struct Blk3C;
extern u32 GDS_PROFILE_GetFieldRecField(struct Blk3C *p, u32 id, void *out);
extern u8 GDS_PROFILE_GetScoreRecLevel(struct Blk1AC *p);
extern u16 GDS_PROFILE_GetScoreRecCountCDec(struct Blk1AC *p, u32 i);
extern void GDS_PROFILE_AddScoreRecTotal(struct Blk1AC *p, s32 v);
extern const u8 d_021DACDC[7][10];

u32 BSUBWAY_SCR_AddBattlePoint(u8 *p)
{
    int r;
    int row;
    int idx;
    u16 n;

    if (p[9] == 4) {
        r = 0;
        if ((u16)GDS_PROFILE_GetFieldRecField(((struct Obj04291 *)p)->f70, 0xB, 0) == 1) {
            idx = (s8)GDS_PROFILE_GetScoreRecLevel(((struct Obj04291 *)p)->f74);
            if (idx < 0)
                idx = 0;
            else if (idx >= 10)
                idx = 9;
            r = d_021DACDC[6][idx];
        } else {
            r = 5;
        }
    } else {
        r = 0;
        n = GDS_PROFILE_GetScoreRecCountCDec(((struct Obj04291 *)p)->f74, p[9]);
        switch (p[9]) {
        case 0:
            row = 0;
            break;
        case 5:
            row = 1;
            r = 1;
            break;
        case 1:
            row = 2;
            break;
        case 6:
            row = 3;
            r = 1;
            break;
        case 2:
            row = 4;
            break;
        case 3:
            row = 4;
            break;
        case 7:
            row = 5;
            r = 1;
            break;
        case 8:
            row = 5;
            r = 1;
            break;
        case 4:
            row = 6;
            break;
        default:
            row = 0;
            break;
        }
        n = n - 1;
        if ((s16)n < 0)
            idx = 0;
        else if (n >= 10)
            idx = 9;
        else
            idx = n;
        if (((Bits *)(p + 0xC))->b1) {
            if (r == 1)
                r = 30;
            else
                r = 10;
        } else {
            r = d_021DACDC[row][idx];
        }
    }
    if (r == 0)
        r = 1;
    GDS_PROFILE_AddScoreRecTotal(((struct Obj04291 *)p)->f74, r);
    return r;
}
