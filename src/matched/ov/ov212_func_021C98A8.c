/*
 * function: func_021C98A8
 * address:  0x021C98A8
 * packet:   pkt_021C98A8
 * region:   ov212
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKE_PERSONAL_LoadFormTable  0x0201AF80  thumb
 *   func_0204A39C  0x0204A39C  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 *POKE_PERSONAL_LoadFormTable(u32 heap, u16 *countOut);
extern void *func_0204A39C(void *narc, int fileId, int decompress, u32 heapId, u32 *out_size);

void func_021C98A8(u32 a0, u32 a1, u16 *a2, u32 *a3,
                   u16 *a4, u32 *a5, u16 *a6, u32 *a7, u16 *a8, u32 *a9)
{
    u32 buf;

    *a3 = (u32)POKE_PERSONAL_LoadFormTable(a1, 0);
    *a2 = 0x28A;
    *a5 = (u32)func_0204A39C((void *)a0, 1, 0, a1, &buf);
    *a4 = buf;
    *a7 = (u32)func_0204A39C((void *)a0, 2, 0, a1, &buf);
    *a6 = buf;
    *a9 = (u32)func_0204A39C((void *)a0, 0, 0, a1, &buf);
    *a8 = buf >> 1;
}
