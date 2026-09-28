/*
 * function: func_0216DE54
 * address:  0x0216DE54
 * packet:   pkt_ov010_0216DE54
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * First object of the given kind in the map (func_0216DD1C walks it),
 * or NULL.
 *
 * symbols:
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_0216D5A0  0x0216D5A0  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0216DD1C(void *map, void **out, u32 *iter);
extern u16 func_0216D5A0(void *obj);

void *func_0216DE54(void *map, u32 kind)
{
    u32 iter;
    void *obj;

    iter = 0;
    while (func_0216DD1C(map, &obj, &iter) == 1) {
        if (func_0216D5A0(obj) == kind)
            return obj;
    }
    return 0;
}
