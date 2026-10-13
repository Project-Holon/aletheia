/*
 * function: BSUBWAY_SCR_CreateRoundTrainers
 * address:  0x021CA05C
 * packet:   pkt_ov021_021CA05C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Draws the current page of the +0x32 list through 0x021CBED8; kinds 2, 3, 7, 8 draw two pages with the slot tags.
 *
 * symbols:
 *   func_0200DA54  0x0200DA54  thumb
 *   func_0200DEA8  0x0200DEA8  thumb
 *   BSUBWAY_SCR_CreateTrainer  0x021CBED8  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01671.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 tag : 11;
    u16 hi  : 5;
    u16 val;
    u8  pad4[0x38];
} Slot;

struct Blk3C;
extern u16 func_0200DA54(struct Blk3C *p);
extern void func_0200DEA8(u32 h, u8 *list, u8 n, u16 id);
extern u8 BSUBWAY_SCR_CreateTrainer(u32 unused, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);

void BSUBWAY_SCR_CreateRoundTrainers(u8 *p)
{
    u32 n = func_0200DA54((struct Blk3C *)(((struct Obj01671 *)p)->f70));
    int i;
    u32 j;
    u16 tags[2];
    u16 vals[2];

    switch (p[9]) {
    case 4:
        func_0200DEA8(((struct Obj01671 *)p)->f78, p + 0x88, n, ((struct Obj01671 *)p)->f4);
        return;
    case 2:
    case 3:
    case 7:
    case 8:
        i = 0;
        j = n * 2;
        BSUBWAY_SCR_CreateTrainer((u32)p, (u32)(p + 0x88), ((u16 *)(p + 0x32))[j], p[8], 0, 0, 0, ((struct Obj01671 *)p)->f4);
        for (; i < p[8]; i++) {
            tags[i] = ((Slot *)(p + 0xb8))[i].tag;
            vals[i] = ((Slot *)(p + 0xb8))[i].val;
        }
        BSUBWAY_SCR_CreateTrainer((u32)p, (u32)(p + 0x1a8), ((u16 *)(p + 0x32))[j + 1], p[8], (u32)tags, (u32)vals, 0, ((struct Obj01671 *)p)->f4);
        return;
    }
    BSUBWAY_SCR_CreateTrainer((u32)p, (u32)(p + 0x88), ((u16 *)(p + 0x32))[n], p[8], 0, 0, 0, ((struct Obj01671 *)p)->f4);
}
