/*
 * function: func_021D9D50
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
 *   func_0200DFD8  0x0200DFD8  thumb
 *   func_0200DFE4  0x0200DFE4  thumb
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

extern u32 func_0200DFD8(u32 save, u32 table, u32 slot);
extern void func_0200DFE4(u32 save, u32 table, u32 slot, u32 value);

int func_021D9D50(char *obj, u32 *rec)
{
    int changed = 0;

    if (rec[4] != func_0200DFD8(((struct Obj24320 *)(*(char * *)&((struct Obj00013 *)obj)->f104))->f10, 10, 0)
        || rec[2] != func_0200DFD8(((struct Obj24321 *)(*(char * *)&((struct Obj00013 *)obj)->f104))->f10, 10, 1)
        || rec[3] != func_0200DFD8(((struct Obj24322 *)(*(char * *)&((struct Obj00013 *)obj)->f104))->f10, 10, 2))
        changed = 1;
    func_0200DFE4(((struct Obj24323 *)(*(char * *)&((struct Obj00013 *)obj)->f104))->f10, 10, 0, rec[4]);
    func_0200DFE4(((struct Obj24324 *)(*(char * *)&((struct Obj00013 *)obj)->f104))->f10, 10, 1, rec[2]);
    func_0200DFE4(((struct Obj24325 *)(*(char * *)&((struct Obj00013 *)obj)->f104))->f10, 10, 2, rec[3]);
    return changed;
}
