/*
 * function: BSUBWAY_SAVEDATA_ExportTrainer
 * address:  0x0200DEA8
 * packet:   pkt_0200DEA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuCopy8  0x02082D44  arm
 */
#include "../include/Obj11710.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void MI_CpuCopy8(void *dst, const void *src, u32 n);

void BSUBWAY_SAVEDATA_ExportTrainer(u8 *base, u8 *out, int idx)
{
    u8 *rec = base + 0x104 + idx * 0xf0;

    ((struct Obj11710 *)out)->f0 = 0xffff;
    ((struct Obj11710 *)out)->f4 = rec[0xd5];
    MI_CpuCopy8(rec + 0xb4, out + 8, 0x10);
    MI_CpuCopy8(rec + 0xd6, out + 0x18, 8);
    MI_CpuCopy8(rec + 0xde, out + 0x20, 8);
    MI_CpuCopy8(rec + 0xe6, out + 0x28, 8);
    MI_CpuCopy8(rec, out + 0x30, 0xb4);
}
