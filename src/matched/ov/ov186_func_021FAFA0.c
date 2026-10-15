/*
 * function: BR_BTN_SetDrawPriority
 * address:  0x021FAFA0
 * packet:   pkt_021FAFA0
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BR_BTN_SetObjectDrawPriority  0x021FB578  thumb  ov186
 */

typedef struct {
    char  pad_00[8];
    void *f8;
} T;

extern int BR_BTN_SetObjectDrawPriority(void *, unsigned char);

int BR_BTN_SetDrawPriority(T *p, int b)
{
    return BR_BTN_SetObjectDrawPriority(p->f8, (unsigned char)b);
}
