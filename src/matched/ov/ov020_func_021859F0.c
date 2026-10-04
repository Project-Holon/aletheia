/*
 * function: func_021859F0
 * address:  0x021859F0
 * packet:   pkt_021859F0
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02012964  0x02012964  thumb
 *   func_0216CF6C  0x0216CF6C  thumb
 */

typedef unsigned int   u32;
struct BigObj;
u32 func_02012964(const struct BigObj *p);
void func_0216CF6C(int x);

void func_021859F0(int a)
{
    func_0216CF6C(func_02012964((const struct BigObj *)a));
}
