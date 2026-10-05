/*
 * function: func_021DD238
 * address:  0x021DD238
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020355D8  0x020355D8  arm  arm9
 *
 * Enable the pooled object when it reports zero.
 */
#include "../include/Obj00000.h"
#include "../include/Obj18441.h"
#include "../include/Obj18442.h"

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Sound;
struct Struct_02025CD0;
extern void func_020355D8(u8 v);
extern u32 func_020260F0(struct Sound *obj);
extern void func_020260F4(struct Struct_02025CD0 *obj, u32 state);

void func_021DD238(char *p)
{
    func_020355D8(0);
    if (func_020260F0(((struct Obj18441 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f70) == 0)
        func_020260F4(((struct Obj18442 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f70, 1);
}

