/*
 * function: FLDMMDL_StoreSaveTable
 * address:  0x0200EE64
 * packet:   pkt_0200EE64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_ClearSaveTable  0x0200EE50  thumb
 *   FLDMMDL_GetNextUsed  0x0200F0CC  thumb
 *   FLDMMDL_StoreSaveRecord  0x0200EED8  thumb
 *
 * Drain loop over a producer: while the enumerator at 0x0200F0CC still hands
 * back 1, take the item at the out-slot and, unless bit 20 of its +4 word is
 * set, retire the 0x50-byte destination cursor through FLDMMDL_StoreSaveRecord.  The
 * enumerator call is rotated (first test above the loop body) so this is a
 * plain `while`, not a do/while.
 */
#include "../include/Obj00607.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern void FLDMMDL_ClearSaveTable(void *p);
extern u32 FLDMMDL_GetNextUsed(const void *a0, void *out, u32 *hint);
extern void FLDMMDL_StoreSaveRecord(const void *item, void *record);

void FLDMMDL_StoreSaveTable(u32 a0, u8 *a1)
{
    u32 hint = 0;
    void *item;

    FLDMMDL_ClearSaveTable(a1);

    while (FLDMMDL_GetNextUsed((const void *)a0, &item, &hint) == 1) {
        if ((((struct Obj00607 *)item)->f4 & 0x100000) == 0) {
            FLDMMDL_StoreSaveRecord(item, a1);
            a1 += 0x50;
        }
    }
}
