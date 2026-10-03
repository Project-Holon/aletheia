/*
 * function: func_021B718C
 * address:  0x021B718C
 * packet:   pkt_ov071_021B718C
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to func_02027FD8.
 *
 * symbols:
 *   func_02027FD8  0x02027FD8  thumb
 */

struct TaskMenuState;
void func_021B718C(void *p)
{
    void func_02027FD8(struct TaskMenuState *s);
    func_02027FD8(p);
}
