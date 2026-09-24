/*
 * function: func_021D63C8
 * address:  0x021D63C8
 * packet:   pkt_021D63C8
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D62A4  0x021D62A4  thumb
 *   func_021D63B0  0x021D63B0  thumb
 *
 * Runs func_021D62A4 once (the object's start-op) and then spins on
 *     func_021D63B0 until it reports the object ready.
 */

typedef unsigned long u32;

extern void func_021D62A4(char *obj);
extern u32 func_021D63B0(char *obj);

void func_021D63C8(char *obj)
{
    func_021D62A4(obj);
    while (func_021D63B0(obj) == 0)
        ;
}

