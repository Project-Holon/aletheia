/*
 * function: func_021DA36C
 * address:  0x021DA36C
 * packet:   pkt_021DA36C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0203C554  0x0203C554  arm
 *   func_0203D7B0  0x0203D7B0  arm
 *   func_0203D7BC  0x0203D7BC  arm
 *
 * Three-call init/reset sequence: 0x0203D7B0(0), 0x0203D7BC(0) and
 *     0x0203C554(1).
 */

extern void func_0203D7B0(int v);
extern void func_0203D7BC(int v);
typedef unsigned int   u32;
extern void func_0203C554(u32 a);

void func_021DA36C(void)
{
    func_0203D7B0(0);
    func_0203D7BC(0);
    func_0203C554(1);
}

