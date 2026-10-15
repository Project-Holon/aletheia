/*
 * function: WIFIBATTLEMATCH_NET_GetSetCompStat
 * address:  0x021D9D50
 * packet:   pkt_021D9D50
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BSUBWAY_SAVEDATA_GetStat  0x0200DFD8  thumb
 *   BSUBWAY_SAVEDATA_SetStat  0x0200DFE4  thumb
 *
 * Syncs three words of a record (+0x10, +0x8, +0xc) into slots 0..2 of table 10 of the save block at +0x104; returns 1 when any of them differed from what was stored.
 *
 * Both callees 0x0200DFD8 and 0x0200DFE4 resolve since seeds_2 labelled and
 *     matched them (src/matched/unit_0200DFD8.c).
 */
#include "../include/Obj00013.h"
#include "../include/Obj24320.h"
#include "../include/Obj24321.h"
#include "../include/Obj24322.h"
#include "../include/Obj24323.h"
#include "../include/Obj24324.h"
#include "../include/Obj24325.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

extern u32 BSUBWAY_SAVEDATA_GetStat(u32 save, u32 table, u32 slot);
extern void BSUBWAY_SAVEDATA_SetStat(u32 save, u32 table, u32 slot, u32 value);

int WIFIBATTLEMATCH_NET_GetSetCompStat(char *obj, u32 *rec)
{
    int changed = 0;

    if (rec[4] != BSUBWAY_SAVEDATA_GetStat(((struct Obj24320 *)(*(char * *)&((struct Obj00013 *)obj)->f104))->f10, 10, 0)
        || rec[2] != BSUBWAY_SAVEDATA_GetStat(((struct Obj24321 *)(*(char * *)&((struct Obj00013 *)obj)->f104))->f10, 10, 1)
        || rec[3] != BSUBWAY_SAVEDATA_GetStat(((struct Obj24322 *)(*(char * *)&((struct Obj00013 *)obj)->f104))->f10, 10, 2))
        changed = 1;
    BSUBWAY_SAVEDATA_SetStat(((struct Obj24323 *)(*(char * *)&((struct Obj00013 *)obj)->f104))->f10, 10, 0, rec[4]);
    BSUBWAY_SAVEDATA_SetStat(((struct Obj24324 *)(*(char * *)&((struct Obj00013 *)obj)->f104))->f10, 10, 1, rec[2]);
    BSUBWAY_SAVEDATA_SetStat(((struct Obj24325 *)(*(char * *)&((struct Obj00013 *)obj)->f104))->f10, 10, 2, rec[3]);
    return changed;
}
