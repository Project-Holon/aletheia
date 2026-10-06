/*
 * function: func_021BFB24
 * address: 0x021BFB24
 * packet: pkt_ov210_021BFB24
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 2-byte zero alignment padding at 021BFB8A before owned 021BFB8C.
 * symbols:
 *   func_021B93B8 0x021B93B8 thumb ov067
 *   func_021BFA14 0x021BFA14 thumb ov210
 */
#include "../include/Obj25631.h"
extern int func_021B93B8(char *);
extern void func_021BFA14(char *p, int y, int flag);
void func_021BFB24(char *ctx)
{
    unsigned center = func_021B93B8(*(char * *)&((struct Obj25631 *)ctx)->f1E0);
    int index = (*(unsigned char ***)(ctx))[2][6];
    signed short lower = index - 4;
    signed short upper = index + 4;
    if (lower < 0) lower = 0;
    if (index >= lower && index < center) {
        func_021BFA14(ctx, (signed short)(192 - (center - index) * 40), 0);
    } else if (index >= center && index < upper) {
        func_021BFA14(ctx, (signed short)((index - center) * 40), 1);
    }
}
