/*
 * function: MISC_SAVEDATA_ExportRingRecord
 * address:  0x0200ECF0
 * packet:   pkt_0200E9E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MISC_SAVEDATA_ExportRecord  0x0200EC2C  thumb
 */
#include "../include/Obj15609.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct Src0200EC2C;
struct Dst0200EC2C;
extern void MISC_SAVEDATA_ExportRecord(const struct Src0200EC2C *base, int idx, struct Dst0200EC2C *dst);

void MISC_SAVEDATA_ExportRingRecord(void *a0, u32 a1, void *a2, void *a3)
{
    int v = ((struct Obj15609 *)a0)->f1554 - 1 - (int)a1;

    if (v < 0)
        v += 0xf;
    MISC_SAVEDATA_ExportRecord((const struct Src0200EC2C *)((u8 *)a0 + v * 0x16c), (int)a2, a3);
}
