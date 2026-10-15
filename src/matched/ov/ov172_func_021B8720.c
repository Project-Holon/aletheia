/*
 * function: CTVT_COMM_SendSlotHit
 * address:  0x021B8720
 * packet:   pkt_021C12F4
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Registers a 1-word/1-word record at a1[0xee..0xef] when the helper rejects the
 * request.
 *
 * symbols:
 *   CTVT_COMM_SendCommand  0x021B8740  thumb  ov172
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

typedef unsigned char  u8;
extern u32 CTVT_COMM_SendCommand(int a, int b, u8 c, u32 d);

void CTVT_COMM_SendSlotHit(void *a0, u32 *a1, u32 a2)
{
    if (CTVT_COMM_SendCommand((int)a0, (int)a1, 2, a2) == 0) {
        a1[0xee] = 1;
        a1[0xef] = a2;
    }
}
