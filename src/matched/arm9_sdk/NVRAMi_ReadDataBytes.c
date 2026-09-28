/*
 * function: NVRAMi_ReadDataBytes
 * address:  0x020843B4
 * packet:   pkt_020843B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libnvram nvram.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * Static in the vendor object: sends the SPI read command (0x23) to the
 * ARM7 as six PXI words: address high byte with the command, address low
 * half, size high and low halves, destination pointer high and low halves.
 *
 * symbols:
 *   PXI_SendWordByFifo               0x02088610  arm
 */

typedef unsigned long u32;
typedef unsigned char u8;
typedef int BOOL;

extern int PXI_SendWordByFifo(int fifotag, u32 data, BOOL err);

BOOL NVRAMi_ReadDataBytes(u32 address, u32 size, u8 *pData)
{
    if (0 > PXI_SendWordByFifo(4, 0x02000000 | 0x2300 | ((address >> 16) & 0x000000FF), 0)) {
        return 0;
    }
    if (0 > PXI_SendWordByFifo(4, 0x00010000 | (address & 0x0000FFFF), 0)) {
        return 0;
    }
    if (0 > PXI_SendWordByFifo(4, 0x00020000 | (size >> 16), 0)) {
        return 0;
    }
    if (0 > PXI_SendWordByFifo(4, 0x00030000 | (size & 0x0000FFFF), 0)) {
        return 0;
    }
    if (0 > PXI_SendWordByFifo(4, 0x00040000 | ((u32)pData >> 16), 0)) {
        return 0;
    }
    if (0 > PXI_SendWordByFifo(4, 0x01000000 | 0x00050000 | ((u32)pData & 0x0000FFFF), 0)) {
        return 0;
    }
    return 1;
}
