/*
 * function: func_021FAFB0
 * address:  0x021FAFB0
 * packet:   pkt_021FAFB0
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FB5A0  0x021FB5A0  thumb  ov186
 */

typedef struct {
    char  pad_00[8];
    void *f8;
} T;

extern int func_021FB5A0(void *, unsigned char);

int func_021FAFB0(T *p, int b)
{
    return func_021FB5A0(p->f8, (unsigned char)b);
}
