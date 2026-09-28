/*
 * function: NVRAMi_VerifyDataArray
 * address:  0x020842A0
 * packet:   pkt_020842A0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libnvram nvram.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * Static in the vendor object: byte-wise compare of two buffers; TRUE when
 * all size bytes agree.
 */

typedef unsigned long u32;
typedef unsigned char u8;
typedef int BOOL;

BOOL NVRAMi_VerifyDataArray(u8 *data0, u8 *data1, u32 size)
{
    u32 i;

    for (i = 0; i < size; i++) {
        if (data0[i] != data1[i]) {
            return 0;
        }
    }
    return 1;
}
