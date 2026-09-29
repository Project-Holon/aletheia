/*
 * function: func_021B9A6C
 * address:  0x021B9A6C
 * packet:   pkt_ov093_021B9A6C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * volatile: field n1 (+2) re-read at 0x021B9A8E (entry guard) and 0x021B9AA2 (back edge) with no store in the loop; a plain u16 is hoisted into r2 (docs/idioms/a-re-read-loop-bound-is-a-volatile-field.md)
 * symbols:
 *   func_021B99E0  0x021B99E0  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

struct Unk021EFD70 { u16 n0; volatile u16 n1; u8 b[6]; };
extern struct Unk021EFD70 *func_021B99E0(int i);

int func_021B9A6C(int a, u32 b)
{
    struct Unk021EFD70 *p = func_021B99E0(a);
    u32 i;

    for (i = 0; i < p->n0; i++) {
        if (b == p->b[i])
            return 1;
    }
    for (i = 0; i < p->n1; i++) {
        if (b == *((u8 *)p + 7 + i))
            return 1;
    }
    return 0;
}
