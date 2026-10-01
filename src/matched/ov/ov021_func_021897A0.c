/*
 * function: func_021897A0
 * address:  0x021897A0
 * packet:   pkt_ov021_021897A0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 */

typedef struct {
    int id;
    void *buf;
} Slot;

void func_020307B0(void *p);

void func_021897A0(unsigned char *p, int id)
{
    Slot *s = (Slot *)(p + 0x118);
    if (id != -1) {
        func_020307B0(s->buf);
        s->id = -1;
    }
}
