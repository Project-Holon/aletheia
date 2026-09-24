/*
 * function: func_021596E8
 * address:  0x021596E8
 * packet:   pkt_021596E8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The record's arm9 handle and the caller's second argument are the two
 * operands of the arm9 pair call.
 *
 * symbols:
 *   func_02011330   0x02011330  thumb
 *   func_0215A5E4   0x0215A5E4  thumb  ov010
 *   func_02012B38   0x02012B38  thumb
 *   func_02014474   0x02014474  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_02011330(void *);
extern void *func_0215A5E4(void *);
extern void *func_02012B38(void *);
extern void func_02014474(void *, void *);

int func_021596E8(void *a0, void *a1)
{
    void *v = func_02011330(a0);

    func_02014474(func_02012B38(func_0215A5E4(a1)), v);

    return 0;
}

