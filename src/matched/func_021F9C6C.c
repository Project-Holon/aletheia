/*
 * function: func_021F9C6C
 * address:  0x021F9C6C
 * packet:   pkt_021F9C6C
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F9BA0  0x021F9BA0  thumb  ov186
 */

typedef struct {
    char pad_00[0x64];
    int  unk_64;
} S;

extern void func_021F9BA0(S *);

void func_021F9C6C(S *p)
{
    while (p->unk_64 != 0)
        func_021F9BA0(p);
}
