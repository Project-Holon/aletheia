/*
 * function: IRCi_CommRead
 * address:  0x0217A718
 * packet:   pkt_ov015_0217A718
 * region:   ov015
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      IRCi_CommRead (libirc.a irc_internal.o)
 *
 * symbols:
 *   func_020870D0  0x020870D0  arm
 *   _ll_udiv       0x0209C00C  arm
 */

typedef struct {
    int unk0;
    unsigned char *wp;
    unsigned char *rp;
} IRCParam;

extern unsigned long long func_020870D0(void);

void IRCi_CommRead(IRCParam *p)
{
    unsigned long long time;

    time = func_020870D0();
    while ((func_020870D0() - time) * 64000 / 0x82EA < 50)
        ;
    *(volatile unsigned short *)0x040001A2 = 0;
    while (*(volatile unsigned short *)0x040001A0 & 0x80)
        ;
    *p->rp = *(volatile unsigned short *)0x040001A2;
    p->rp++;
}
