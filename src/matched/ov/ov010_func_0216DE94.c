/*
 * function: func_0216DE94
 * address:  0x0216DE94
 * packet:   pkt_ov010_0216DE94
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * First free object (func_0216DBB4 zero) with the given id in the map,
 * or NULL (func_0216DE54 is the by-kind twin).
 *
 * symbols:
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_0216DBB4  0x0216DBB4  thumb  ov010
 *   func_0216D588  0x0216D588  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0216DD1C(void *map, void **out, u32 *iter);
extern int func_0216DBB4(void *obj);
extern u16 func_0216D588(void *obj);

void *func_0216DE94(void *map, u32 id)
{
    u32 iter;
    void *obj;

    iter = 0;
    while (func_0216DD1C(map, &obj, &iter) == 1) {
        if (func_0216DBB4(obj) == 0 && func_0216D588(obj) == id)
            return obj;
    }
    return 0;
}
