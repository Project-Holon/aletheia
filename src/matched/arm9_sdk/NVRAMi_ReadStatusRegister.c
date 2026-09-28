/*
 * function: NVRAMi_ReadStatusRegister
 * address:  0x02084330
 * packet:   pkt_02084330
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libnvram nvram.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  Static
 * in the vendor object: the destination address travels in three PXI words.
 *
 * symbols:
 *   PXI_SendWordByFifo  0x02088610  arm
 */

typedef unsigned long u32;
typedef unsigned char u8;
typedef int BOOL;

extern int PXI_SendWordByFifo(int fifotag, u32 data, BOOL err);

BOOL NVRAMi_ReadStatusRegister(u8 *pData)
{
    if (0 > PXI_SendWordByFifo(4, 0x02002200 | ((u32)pData >> 24), 0)) {
        return 0;
    }
    if (0 > PXI_SendWordByFifo(4, 0x00010000 | (((u32)pData >> 8) & 0x0000FFFF), 0)) {
        return 0;
    }
    if (0 > PXI_SendWordByFifo(4, 0x01000000 | 0x00020000 | (((u32)pData << 8) & 0x0000FF00), 0)) {
        return 0;
    }
    return 1;
}
