/*
 * function: func_021FB55C
 * address: 0x021FB55C
 * packet: pkt_ov132_021FB55C
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: inferred extent ends with two zero padding bytes before the next labelled function.
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021FB1F4 0x021FB1F4 thumb ov132
 *   func_021F9DA0 0x021F9DA0 thumb ov132
 *   func_021F9DA4 0x021F9DA4 thumb ov132
 *   func_021F80B0 0x021F80B0 thumb ov112
 */
#include "../include/Obj14103.h"
#include "../include/Obj14104.h"
typedef unsigned char u8;
struct Cursor;
extern unsigned int func_0201134C(struct Cursor *p);
extern int func_021FB1F4(char *, int);
typedef unsigned int   u32;
extern void *func_021F9DA0(char *p);
extern void *func_021F9DA4(char *p, u32 i);
extern void func_021F80B0(char *, char *);
int func_021FB55C(int unused, char *p)
{
    char *obj;
    int mask;
    char *ctx;
    u8 i;
    obj = *(char * *)&((struct Obj14103 *)p)->f0;
    mask = func_021FB1F4(p, func_0201134C(((struct Obj14103 *)p)->f4));
    ctx = func_021F9DA0(((struct Obj14104 *)obj)->f34);
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            func_021F80B0(ctx, func_021F9DA4(((struct Obj14104 *)obj)->f34, i));
        }
    }
    return 0;
}
