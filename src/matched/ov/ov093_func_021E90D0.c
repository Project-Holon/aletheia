/*
 * function: BTLV_CORE_PollOpening
 * address:  0x021E90D0
 * packet:   pkt_ov093_021E90D0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
typedef int (*Step)(void *self, void *a, void *b);

struct S {
    char pad[0x10];
    int state;
    Step fn;
    char a[0x14];
    char b[4];
};

int BTLV_CORE_PollOpening(struct S *s)
{
    if (s->state != 4) {
        if (s->fn(s, s->a, s->b) != 0) {
            s->state = 4;
            s->fn = 0;
            return 1;
        }
        return 0;
    }
    return 1;
}
