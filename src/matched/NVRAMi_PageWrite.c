/*
 * function: NVRAMi_PageWrite
 * address:  0x020844A8
 * packet:   pkt_020844A8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libnvram nvram.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  Static
 * in the vendor object: address, size and source pointer in five PXI words.
 *
 * symbols:
 *   PXI_SendWordByFifo  0x02088610  arm
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int BOOL;

extern int PXI_SendWordByFifo(int fifotag, u32 data, BOOL err);

BOOL NVRAMi_PageWrite(u32 address, u16 size, u8 *pData)
{
    if (0 > PXI_SendWordByFifo(4, 0x02000000 | 0x2500 | ((address >> 16) & 0x000000FF), 0)) {
        return 0;
    }
    if (0 > PXI_SendWordByFifo(4, 0x00010000 | (address & 0x0000FFFF), 0)) {
        return 0;
    }
    if (0 > PXI_SendWordByFifo(4, 0x00020000 | size, 0)) {
        return 0;
    }
    if (0 > PXI_SendWordByFifo(4, 0x00030000 | ((u32)pData >> 16), 0)) {
        return 0;
    }
    if (0 > PXI_SendWordByFifo(4, 0x01000000 | 0x00040000 | ((u32)pData & 0x0000FFFF), 0)) {
        return 0;
    }
    return 1;
}
