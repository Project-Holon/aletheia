/*
 * function: func_021FB208
 * address: 0x021FB208
 * packet: pkt_ov132_021FB208
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   func_021FB1F4 0x021FB1F4 thumb ov132
 *   STA_ACTING_GetActorSystem 0x021F9DA0 thumb ov132
 *   STA_ACTING_GetActor 0x021F9DA4 thumb ov132
 *   func_021F80D4 0x021F80D4 thumb ov112
 */
#include "../include/Obj10548.h"
#include "../include/Obj14101.h"
typedef unsigned char u8;
struct Cursor;
extern unsigned int VM_GetU32(struct Cursor *p);
extern int func_021FB1F4(char *, int);
typedef unsigned int   u32;
extern void *STA_ACTING_GetActorSystem(char *p);
extern void *STA_ACTING_GetActor(char *p, u32 i);
extern void func_021F80D4(char *, char *, int);
int func_021FB208(int unused, char *p)
{
    char *obj;
    int mask;
    char *ctx;
    int value;
    u8 i;
    obj = *(char * *)&((struct Obj10548 *)p)->f0;
    mask = func_021FB1F4(p, VM_GetU32(((struct Obj10548 *)p)->f4));
    value = VM_GetU32(((struct Obj10548 *)p)->f4);
    ctx = STA_ACTING_GetActorSystem(((struct Obj14101 *)obj)->f34);
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            func_021F80D4(ctx, STA_ACTING_GetActor(((struct Obj14101 *)obj)->f34, i), value);
        }
    }
    return 0;
}
