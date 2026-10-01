/*
 * function: func_0219D390
 * address:  0x0219D390
 * packet:   pkt_ov021_0219D390
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0219D324  0x0219D324  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { u32 p; u16 id; u16 pad; u32 x; } Slot;
extern void func_0219D324(u8 *, Slot *);

void func_0219D390(u8 *s)
{
    Slot *e = *(Slot **)(s + 0x20);
    int i;
    if (e != 0) {
        for (i = 0; i < 4; i++, e++) {
            if (e->p != 0) {
                func_0219D324(s, e);
            }
        }
    }
}
