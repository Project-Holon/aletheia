/*
 * function: NVRAMi_SoftwareReset
 * address:  0x02084570
 * packet:   pkt_02084570
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libnvram nvram.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  Static
 * in the vendor object: one single-word PXI command to the ARM7 NVRAM driver
 * (tag 4, start and end bits set).
 *
 * symbols:
 *   PXI_SendWordByFifo  0x02088610  arm
 */

typedef unsigned long u32;
typedef unsigned char u8;
typedef int BOOL;

extern int PXI_SendWordByFifo(int fifotag, u32 data, BOOL err);

BOOL NVRAMi_SoftwareReset(void)
{
    if (0 > PXI_SendWordByFifo(4, 0x03002D00, 0)) {
        return 0;
    }
    return 1;
}
