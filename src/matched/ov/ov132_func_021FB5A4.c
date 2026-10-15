/*
 * function: func_021FB5A4
 * address: 0x021FB5A4
 * packet: pkt_ov132_021FB5A4
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: inferred extent ends with two zero padding bytes before the next labelled function.
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   func_021FB1F4 0x021FB1F4 thumb ov132
 *   STA_ACTING_GetActorSystem 0x021F9DA0 thumb ov132
 *   STA_ACTING_GetActor 0x021F9DA4 thumb ov132
 *   func_021F80A0 0x021F80A0 thumb ov112
 */
#include "../include/Obj14105.h"
#include "../include/Obj14106.h"
typedef unsigned char u8;
struct Cursor;
extern unsigned int VM_GetU32(struct Cursor *p);
extern int func_021FB1F4(char *, int);
typedef unsigned int   u32;
extern void *STA_ACTING_GetActorSystem(char *p);
extern void *STA_ACTING_GetActor(char *p, u32 i);
extern void func_021F80A0(int a, u8 *p);
int func_021FB5A4(int unused, char *p)
{
    char *obj;
    int mask;
    char *ctx;
    u8 i;
    obj = *(char * *)&((struct Obj14105 *)p)->f0;
    mask = func_021FB1F4(p, VM_GetU32(((struct Obj14105 *)p)->f4));
    ctx = STA_ACTING_GetActorSystem(((struct Obj14106 *)obj)->f34);
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            func_021F80A0((int)ctx, STA_ACTING_GetActor(((struct Obj14106 *)obj)->f34, i));
        }
    }
    return 0;
}
