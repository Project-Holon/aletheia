/*
 * function: func_0202E83C
 * address:  0x0202E83C
 * packet:   pkt_0202E79C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_02158468  0x02158468  thumb
 */
typedef unsigned int   u32;
struct Ctx;
extern u32 func_02012138(const struct Ctx *p);
extern int func_02158468(int a0);

int func_0202E83C(void *a0)
{
    return func_02158468(func_02012138(a0));
}
