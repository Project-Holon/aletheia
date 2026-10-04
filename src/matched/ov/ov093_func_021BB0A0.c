/*
 * function: func_021BB0A0
 * address:  0x021BB0A0
 * packet:   pkt_ov093_021BB0A0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BB830  0x021BB830  thumb  ov093
 *   func_021EEB64  0x021EEB64  thumb  ov093
 *   func_021D8454  0x021D8454  thumb  ov093
 *   func_021B9920  0x021B9920  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 */
#include "../include/Obj21031.h"
#include "../include/Obj21032.h"

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u32 pad : 7;
    u32 f : 3;
} B;

extern int func_021BB830(u8 *);
extern B *func_021EEB64(u32, int);
extern u32 func_021D8454(B *);
extern u8 *func_021B9920(void *p, u32 i, u8 j);
extern u8 func_021D5440(u8 *p);

u32 func_021BB0A0(u8 *p)
{
    u8 *q = p + 0x20;
    B *b;

    if (func_021BB830(q) != 0) {
        b = func_021EEB64(((struct Obj21032 *)q)->f0, 0);
        if (func_021D8454(b) == 3) {
            u8 *r = func_021B9920(((struct Obj21031 *)p)->f10, 1, b->f);
            return func_021D5440(r);
        }
    }
    return 0x1f;
}
