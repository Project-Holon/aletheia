/*
 * unit:     yes
 * function: func_021B7168, func_021B7170
 * address:  0x021B7168
 * packet:   pkt_ov071_021B7168
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * ARM9 tail call followed by an empty function.
 *
 * symbols:
 *   func_0204B3B4  0x0204B3B4  arm
 */

struct Obj;
void func_021B7168(void *p)
{
    void func_0204B3B4(struct Obj *p);
    func_0204B3B4(p);
}

void func_021B7170(void)
{
}
