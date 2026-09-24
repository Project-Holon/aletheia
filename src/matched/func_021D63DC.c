/*
 * function: func_021D63DC
 * address:  0x021D63DC
 * packet:   pkt_021D63DC
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D639C  0x021D639C  thumb
 *   func_021D63BC  0x021D63BC  thumb
 *
 * Only when the +0x18 pointer is live: spin on func_021D63BC until it
 *     reports ready, then hand the object to the func_021D639C release path.
 */

typedef unsigned long u32;

extern u32 func_021D63BC(char *obj);
extern void func_021D639C(char *obj);

void func_021D63DC(char *obj)
{
    if (*(u32 *)(obj + 0x18) != 0) {
        while (func_021D63BC(obj) == 0)
            ;
        func_021D639C(obj);
    }
}

