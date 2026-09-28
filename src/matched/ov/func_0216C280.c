/*
 * function: func_0216C280
 * address:  0x0216C280
 * packet:   pkt_0216C280
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * unblocked: func_021BE480 (ov021, unlabelled leaf) matched bottom-up and
 *           filed as pkt_021BE480; the `ov021` token resolves the +0x18
 *           call as `matched, overlay`.  func_02188D2C was already matched.
 *
 * Asks the arm9 side for the slot's descriptor, sizes it through the
 * overlay helper and copies the second word of the local into it.
 *
 * symbols:
 *   func_02011610   0x02011610  thumb
 *   func_02188D2C   0x02188D2C  thumb
 *   func_021BE480   0x021BE480  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_02011610(void *, void *);
extern void *func_02188D2C(void *);
extern void *func_021BE480(void *, int, int);

void *func_0216C280(void *p)
{
    char v[12];
    void *q;

    func_02011610(*(void **)((char *)p + 0x10), v);
    q = func_021BE480(func_02188D2C(*(void **)((char *)p + 8)), 0, 0);
    *(void **)((char *)q + 4) = *(void **)(v + 4);

    return q;
}

