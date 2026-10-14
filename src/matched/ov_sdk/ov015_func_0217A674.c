/*
 * function: IRCi_CommWrite
 * address:  0x0217A674
 * packet:   pkt_ov015_0217A674
 * region:   ov015
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      IRCi_CommWrite (libirc.a irc_internal.o)
 *
 * symbols:
 *   func_020870D0  0x020870D0  arm
 *   _ll_udiv       0x0209C00C  arm
 * note: volatile in this file is a matching device (it forces the reload the
 *   original performs); the vendor DWARF declares the object without volatile.
 */

typedef struct {
    int unk0;
    unsigned char *wp;
    unsigned char *rp;
} IRCParam;

extern unsigned long long func_020870D0(void);

unsigned char IRCi_CommWrite(IRCParam *p)
{
    unsigned long long time;
    volatile unsigned short tmp;

    time = func_020870D0();
    while ((func_020870D0() - time) * 64000 / 0x82EA < 50)
        ;
    *(volatile unsigned short *)0x040001A2 = *p->wp;
    p->wp++;
    while (*(volatile unsigned short *)0x040001A0 & 0x80)
        ;
    tmp = *(volatile unsigned short *)0x040001A2;
    return tmp;
}
