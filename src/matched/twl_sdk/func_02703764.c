/*
 * function: NWMi_AddMACHeader
 * address:  0x02703764
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuCopy8  0x02082D44  arm twl a2
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void MI_CpuCopy8(u32, u32, u32);

void NWMi_AddMACHeader(u32 a0, u32 a1, u8 *a2, u32 a3) {
    if (a3 < 0xE) {
        return;
    }
    MI_CpuCopy8(a0, (u32)a2, 6);
    MI_CpuCopy8(a1, (u32)(a2 + 6), 6);
}
