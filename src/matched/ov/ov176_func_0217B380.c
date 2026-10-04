/*
 * function: func_0217B380
 * address:  0x0217B380
 * packet:   pkt_ov176_0217B380
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021E8AA0  0x021E8AA0  thumb  ov177
 *   func_0217B3C0  0x0217B3C0  thumb  ov176
 *   func_0217B4A0  0x0217B4A0  thumb  ov176
 *   func_0217B6AC  0x0217B6AC  thumb  ov176
 */

extern void func_021E8AA0(int *p, int v);
extern void func_0217B3C0(int p, unsigned *state, int *q);
extern void func_0217B4A0(int p, unsigned *state, int *q);
extern void func_0217B6AC(int p, unsigned *state, int *q);

void func_0217B380(int a, int b, int *p)
{
    switch (*(int *)((char *)p + 0x14)) {
    case 0:
        func_021E8AA0((int *)a, (int)func_0217B3C0);
        break;
    case 1:
        func_021E8AA0((int *)a, (int)func_0217B4A0);
        break;
    case 2:
        func_021E8AA0((int *)a, (int)func_0217B6AC);
        break;
    }
}