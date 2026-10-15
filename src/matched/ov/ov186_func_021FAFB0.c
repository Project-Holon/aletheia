/*
 * function: BR_BTN_SetBgPriority
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
 *   BR_BTN_SetObjectBgPriority  0x021FB5A0  thumb  ov186
 */

typedef struct {
    char  pad_00[8];
    void *f8;
} T;

extern int BR_BTN_SetObjectBgPriority(void *, unsigned char);

int BR_BTN_SetBgPriority(T *p, int b)
{
    return BR_BTN_SetObjectBgPriority(p->f8, (unsigned char)b);
}
