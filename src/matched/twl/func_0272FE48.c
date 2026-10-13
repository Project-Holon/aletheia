/*
 * function: MI_Card_NDmaCopy
 * address:  0x0272FE48
 * packet:   twl_audio
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   MIi_CardNDmaRecv32 0x0272FDDC arm twl
 */

void MIi_CardNDmaRecv32(int ch, const void *src, void *dst);

void MI_Card_NDmaCopy(int ch, const void *src, void *dst)
{
    MIi_CardNDmaRecv32(ch, src, dst);
}
