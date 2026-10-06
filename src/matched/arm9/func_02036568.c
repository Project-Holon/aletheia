/*
 * function: func_02036568
 * address:  0x02036568
 * packet:   pkt_02036568
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02036624  0x02036624  arm
 *
 * wm_icon.c ring reader. Wave 17 lane untried_small, from 25 out: the ring
 * is a const pointer, in this function and in func_02036624's prototype (both
 * only read it). With the read-only qualifier the compiler hoists the
 * loop-bottom bound load above the byte store through dst, as the image does.
 * The write cursor +0x0E stays volatile (the func_02036428 lever).
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8   *buf;
    int   size;
    u32   pad8;
    short head;
    volatile short tail;
} NetRingBuff;

extern int func_02036624(void *p, int v);

int func_02036568(const NetRingBuff *r, u8 *dst, int len, int max)
{
    int i;
    int n;

    n = 0;
    for (i = r->head; i < r->head + len; i++) {
        if (r->tail == func_02036624((void *)r, i) || n == max) {
            return n;
        }
        dst[n] = r->buf[func_02036624((void *)r, i)];
        n++;
    }
    return n;
}
