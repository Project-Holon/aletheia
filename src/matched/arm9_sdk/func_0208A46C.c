/*
 * function: SND_GetFirstInstDataPos
 * address:  0x0208A46C
 * packet:   pkt_0208A46C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     snd_bank.o SND_GetFirstInstDataPos.
 */

typedef struct {
    unsigned int prgNo;
    unsigned int index;
} SNDInstPos;

SNDInstPos SND_GetFirstInstDataPos(const void *bank)
{
    SNDInstPos pos;

    pos.prgNo = 0;
    pos.index = 0;

    return pos;
}
