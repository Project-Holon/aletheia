/*
 * function: NVRAMi_AlarmHandler
 * address:  0x02084288
 * packet:   pkt_02084288
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libnvram nvram.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  Static
 * in the vendor object: re-enters the PXI callback (tag 4) from the retry
 * alarm, a tail call.
 *
 * symbols:
 *   NVRAMi_Callback  0x02084204  arm
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int BOOL;

extern void NVRAMi_Callback(int tag, u32 data, BOOL err);

void NVRAMi_AlarmHandler(void *arg)
{
    NVRAMi_Callback(4, (u32)arg, 0);
}
