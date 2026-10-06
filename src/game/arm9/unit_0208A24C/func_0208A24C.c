/*
 * function: func_0208A24C
 * address:  0x0208A24C
 * packet:   pkt_0208A24C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SND_CalcChannelVolume (snd_util.o)
 *
 * symbols:
 *   VolumeTable  0x020A5E08  data
 */

extern const unsigned char VolumeTable[724];

unsigned short func_0208A24C(int dB)
{
    unsigned char volume;
    int shift;

    if (dB < -723) {
        dB = -723;
    } else if (dB > 0) {
        dB = 0;
    }

    volume = VolumeTable[dB + 723];

    if (dB < -240) {
        shift = 3;
    } else if (dB < -120) {
        shift = 2;
    } else if (dB < -60) {
        shift = 1;
    } else {
        shift = 0;
    }

    return (unsigned short)(volume | (shift << 8));
}
