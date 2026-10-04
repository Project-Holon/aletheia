/*
 * function: func_021DA390
 * address:  0x021DA390
 * packet:   pkt_021DA390
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D9ED4  0x021D9ED4  thumb
 *   func_021D9EEC  0x021D9EEC  thumb
 *   func_0203D7B0  0x0203D7B0  arm
 *   func_0203D7BC  0x0203D7BC  arm
 *   func_0203C554  0x0203C554  arm
 *
 * Link shutdown sequence stepped by the word at +0x154: sync 0x18, wait for the sync (600 frame timeout on +0x1a0), stop the two link services, wait 30 frames on +0x134, restart the parent service, then report done (1).
 */
#include "../include/Obj02513.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

extern void func_021D9ED4(char *obj, u32 v);
extern int func_021D9EEC(char *obj);
extern void func_0203D7B0(int v);
extern void func_0203D7BC(int v);
extern void func_0203C554(u32 a);

int func_021DA390(char *obj)
{
    switch (((struct Obj02513 *)obj)->f154) {
    case 0:
        func_021D9ED4(obj, 0x18);
        ((struct Obj02513 *)obj)->f1A0 = 0;
        (((struct Obj02513 *)obj)->f154)++;
        break;
    case 1:
        if (func_021D9EEC(obj) != 0)
            (((struct Obj02513 *)obj)->f154)++;
        else if ((((struct Obj02513 *)obj)->f1A0)++ > 600)
            (((struct Obj02513 *)obj)->f154)++;
        break;
    case 2:
        func_0203D7B0(0);
        func_0203D7BC(0);
        ((struct Obj02513 *)obj)->f134 = 0;
        (((struct Obj02513 *)obj)->f154)++;
        break;
    case 3:
        if ((((struct Obj02513 *)obj)->f134)++ > 30)
            (((struct Obj02513 *)obj)->f154)++;
        break;
    case 4:
        func_0203C554(1);
        (((struct Obj02513 *)obj)->f154)++;
        break;
    case 5:
        return 1;
    }
    return 0;
}
