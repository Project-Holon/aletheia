/*
 * function: sub_02014488
 * address:  0x02014488
 * packet:   pkt_02014488
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * blocking: unresolved: 02188BD8 (thumb, from header) has no witness outside 02014488..02014; unresolved: 0215FA44 (thumb, from header) has no witness outside 02014488..02014
 *
 * symbols:
 *   sub_020120F0   0x020120F0  thumb
 *   sub_02012A30   0x02012A30  thumb
 *   sub_020289B8   0x020289B8  thumb
 *   func_0215FA44  0x0215FA44  thumb
 *   func_02188BD8  0x02188BD8  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *sub_02012A30(void *a);
extern int   sub_020120F0(void *a);
extern int   sub_020289B8(void *a);
extern void  func_0215FA44(void *a);
extern void  func_02188BD8(void *a);

int sub_02014488(void *a0, u32 *a1, u8 *a2)
{
    void *v = (void *)*(u32 *)(a2 + 8);
    void *w = (void *)*(u32 *)a2;
    void *x = (void *)*(u32 *)(a2 + 4);
    void *y;

    y = sub_02012A30(v);
    switch (*a1) {
    case 0:
        func_02188BD8(x);
        *a1 = *a1 + 1;
        break;
    case 1:
        if (sub_020120F0(w) != 0) {
            break;
        }
        if (sub_020289B8(y) == 1) {
            break;
        }
        if (*(u32 *)(a2 + 0xc) != 0) {
            func_0215FA44((void *)*(u32 *)(a2 + 0xc));
        }
        return 1;
    }
    return 0;
}
