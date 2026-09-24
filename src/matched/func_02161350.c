/*
 * function: func_02161350
 * address:  0x02161350
 * packet:   pkt_02161350
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Five arguments to the overlay builder: the two words of the descriptor,
 * the object's halfword, the descriptor's classification and a pointer to
 * the object's tail; the result goes to the arm9 call with the
 * object's word at +0x14.
 *
 * symbols:
 *   func_021616A4   0x021616A4  thumb  ov010
 *   func_02188C54   0x02188C54  thumb
 *   func_02012374   0x02012374  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_021616A4(void *, void *, u16, void *, void *);
extern void *func_02188C54(void *);
extern void func_02012374(void *, void *);

void func_02161350(void *a0)
{
    char *r4 = *(char **)((char *)a0 + 0x18);
    void *t = func_02188C54(*(void **)(r4 + 4));

    func_02012374(*(void **)((char *)a0 + 0x14),
                  func_021616A4(*(void **)r4, *(void **)(r4 + 4),
                                *(u16 *)a0, t, (char *)a0 + 0x10));
}

