/*
 * function: func_021D4B30
 * address: 0x021D4B30
 * packet: pkt_ov122_021D4B30
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D4244 0x021D4244 thumb ov122
 */
#include "../include/Obj13964.h"
extern int func_020221A4(char *);
struct Ctx;
extern unsigned int func_02012138(const struct Ctx *p);
typedef unsigned int   u32;
extern u32 func_02026454(void *obj);
extern void func_021D4244(void *p, u32 a, int a2);
void func_021D4B30(char *p)
{
    if (func_020221A4(p)) {
        if (((struct Obj13964 *)p)->f8 == 1) {
            if (!func_02026454((void *)func_02012138(((struct Obj13964 *)p)->f354)))
                func_021D4244(p, 0, 0x341);
        } else {
            func_021D4244(p, 0, 0x345);
        }
    }
}
