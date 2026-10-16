/*
 * function: MicStartAutoSampling
 * address:  0x0208B650
 * packet:   pkt_0208B650
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MicStartAutoSampling (libspi.TWL.HYB.a mic.o)
 *
 * symbols:
 *   PXI_SendWordByFifo             0x02088610  arm
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int BOOL;

int PXI_SendWordByFifo(int fifotag, u32 data, BOOL err);

BOOL MicStartAutoSampling(void *buf, u32 size, u32 span, u8 flags)
{
    if (PXI_SendWordByFifo(9, 0x02000000 | 0x4100 | flags, 0) < 0) {
        return 0;
    }
    if (PXI_SendWordByFifo(9, 0x10000 | ((u32)buf >> 16), 0) < 0) {
        return 0;
    }
    if (PXI_SendWordByFifo(9, 0x20000 | ((u32)buf & 0xffff), 0) < 0) {
        return 0;
    }
    if (PXI_SendWordByFifo(9, 0x30000 | (size >> 16), 0) < 0) {
        return 0;
    }
    if (PXI_SendWordByFifo(9, 0x40000 | (size & 0xffff), 0) < 0) {
        return 0;
    }
    if (PXI_SendWordByFifo(9, 0x50000 | (span >> 16), 0) < 0) {
        return 0;
    }
    if (PXI_SendWordByFifo(9, 0x01000000 | 0x60000 | (span & 0xffff), 0) < 0) {
        return 0;
    }
    return 1;
}
