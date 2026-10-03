/*
 * function: func_0215CE98
 * address:  0x0215CE98
 * packet:   pkt_0215CE98
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * unblocked: func_021C3400 (ov021, unlabelled leaf) was matched bottom-up
 *   and filed as pkt_021C3400; the `ov021` token then resolves the site as
 *   `matched, overlay`.  Extent runs 36 bytes against 34 compiled: the
 *   unlabelled follower.
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D50  0x02188D50  thumb
 *   func_021C3400  0x021C3400  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern unsigned short *func_02159AE8(void *a0, void *a1);
extern void *func_0215A5DC(void *a0);
extern void *func_0201210C(void *p);
extern void *func_02188D50(void *a0);
extern int func_021C3400(int a0);

int func_0215CE98(int a0, int a1)
{    int t5;
    unsigned short *v0;
    void *v1;
    void *v2;

t5 = a1 + 0;
    v0 = func_02159AE8((void *)a0, (void *)a1);
loc_0215CEA0:
a0 = t5 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_0215CEA8:
    v2 = func_0201210C(v1);
loc_0215CEAC:
    a0 = (int)func_02188D50(v2);
loc_0215CEB0:
    a0 = func_021C3400(a0);
loc_0215CEB4:
*(u16 *)((char *)v0) = a0;
a0 = 0;
    return a0;}
