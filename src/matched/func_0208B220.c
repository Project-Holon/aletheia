/*
 * function: func_0208B220
 * address:  0x0208B220
 * packet:   pkt_0208B220
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     spi/ARM9/tp.o TP_WaitBusy.
 *
 * symbols:
 *   tpState  0x02152FA4  data  a4
 */

typedef struct {
    char pad[0x3a];
    volatile unsigned short command_flg;
} TPState;

extern TPState tpState;

void func_0208B220(unsigned int command_flgs)
{
    while (tpState.command_flg & command_flgs) {
    }
}
