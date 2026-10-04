/*
 * function: func_0215D7FC
 * address:  0x0215D7FC
 * packet:   pkt_02156B70
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * When the +0xa0 object exists and the caller asked for flag 2, latch its
 * +0xfe byte to 1 and put it back afterwards.  Mode 1 at +0xaf takes the
 * direct path, anything else goes through func_0215D898 and follows up with
 * func_0215DD28 when that did not fail.
 */

struct SOCLSocket;
extern int func_0215DDC4(struct SOCLSocket *socket, void *buffer, int buffer_len, unsigned short *remote_port, unsigned long *remote_ip, long flag_block);
extern int func_0215D898(char *a, int b, int c, int d, int e, int f);
extern void func_0215DD28(char *a);

int func_0215D7FC(char *a, int b, int c, int d, int e, int f, int g)
{
    char *q = *(char **)(a + 0xa0);
    int old;
    int t;
    int r;

    if ((g & 2) != 0 && q != 0)
        t = 1;
    else
        t = 0;

    if (t != 0) {
        old = *(signed char *)(q + 0xfe);
        *(signed char *)(q + 0xfe) = 1;
    }

    if (*(signed char *)(a + 0xaf) == 1) {
        r = func_0215DDC4((struct SOCLSocket *)a, (void *)b, c, (short unsigned int *)d, (long unsigned int *)e, f);
    } else {
        r = func_0215D898(a, b, c, d, e, f);
        if (r >= 0)
            func_0215DD28(a);
    }

    if (t != 0)
        *(signed char *)(q + 0xfe) = old;

    return r;
}
