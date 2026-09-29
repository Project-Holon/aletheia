/*
 * function: func_02176194
 * address:  0x02176194
 * packet:   pkt_ov011_02176194
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * note:     an unlabelled leaf follows the pool word, at 0x021761C4.
 *
 * symbols:
 *   func_021740AC  0x021740AC  thumb  ov011
 */

typedef unsigned char u8;

typedef struct {
    u8 pad[0x197];
    u8 f197[3];
} Work;

extern int func_021740AC(void *a, int b, int c);

void func_02176194(void *a, Work *w)
{
    int i;

    for (i = 0; i < 3; i++) {
        if (w->f197[i] != 0 && func_021740AC(a, w->f197[i], i) == 1) {
            w->f197[i] = 0;
        }
    }
}
