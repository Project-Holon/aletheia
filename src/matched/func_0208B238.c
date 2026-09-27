/*
 * function: func_0208B238
 * address:  0x0208B238
 * packet:   pkt_0208B238
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     spi/ARM9/tp.o TP_CheckError.
 *
 * symbols:
 *   tpState  0x02152FA4  data  a4
 */

typedef struct {
    char pad[0x38];
    unsigned short err_flg;
} TPState;

extern TPState tpState;

unsigned int func_0208B238(unsigned int command_flgs)
{
    return (unsigned int)(tpState.err_flg & command_flgs);
}
