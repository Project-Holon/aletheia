/*
 * function: func_021FB698
 * address: 0x021FB698
 * packet: pkt_ov132_021FB698
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: inferred extent ends with two zero padding bytes before the next labelled function.
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   func_021FB1F4 0x021FB1F4 thumb ov132
 *   func_021F9DA0 0x021F9DA0 thumb ov132
 *   func_021F9DA4 0x021F9DA4 thumb ov132
 *   func_021F8154 0x021F8154 thumb ov112
 */
#include "../include/Obj10551.h"
#include "../include/Obj14108.h"
typedef unsigned char u8;
struct Cursor;
extern unsigned int VM_GetU32(struct Cursor *p);
extern int func_021FB1F4(char *, int);
typedef unsigned int   u32;
extern void *func_021F9DA0(char *p);
extern void *func_021F9DA4(char *p, u32 i);
extern int func_021F8154(int a0, int *a1, int a2);
int func_021FB698(int unused, char *p)
{
    char *obj;
    int mask;
    int value;
    char *ctx;
    u8 i;
    obj = *(char * *)&((struct Obj10551 *)p)->f0;
    mask = func_021FB1F4(p, VM_GetU32(((struct Obj10551 *)p)->f4));
    value = VM_GetU32(((struct Obj10551 *)p)->f4);
    ctx = func_021F9DA0(((struct Obj14108 *)obj)->f34);
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            func_021F8154((int)ctx, func_021F9DA4(((struct Obj14108 *)obj)->f34, i), value != 0);
        }
    }
    return 0;
}
