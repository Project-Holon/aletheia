/*
 * function: func_021BB13C
 * address:  0x021BB13C
 * packet:   pkt_021BB13C
 * region:   ov206
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BB184 0x021BB184 thumb
 *   func_021BB23C 0x021BB23C thumb
 *   func_021BB2D4 0x021BB2D4 thumb
 */

extern void func_021BB184(char *p, int index);
extern void func_021BB23C(char *p, int x, int y, int index);
extern void func_021BB2D4(char *p);

void func_021BB13C(void *a0, void *a1, void *a2, void *a3)
{
    func_021BB184(a0, (int)a3);
    func_021BB23C(a0, (int)a1, (int)a2, (int)a3);
    func_021BB2D4(a0);
}
