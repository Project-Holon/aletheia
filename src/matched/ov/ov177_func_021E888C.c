/*
 * function: WIFIBATTLEMATCH_UTIL_ShowMenu
 * address:  0x021E888C
 * packet:   pkt_ov177_021E888C
 * region:   ov177
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WIFIBATTLEMATCH_UTIL_CreateMenu  0x021E88B0  thumb  ov177
 */

typedef struct {
    char           pad0[0x1c];
    unsigned int f1c;
} S;

extern void WIFIBATTLEMATCH_UTIL_CreateMenu(S *, int, unsigned char, int, int, int);

void WIFIBATTLEMATCH_UTIL_ShowMenu(S *p, int a)
{
    int v = (p->f1c & 0x7f) << 1;

    WIFIBATTLEMATCH_UTIL_CreateMenu(p, 0x13, 0x11 - v, 0xc, v, a);
}
