/*
 * function: func_021B7F64
 * address: 0x021B7F64
 * packet: pkt_ov173_021B7F64
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02026124 0x02026124 thumb
 *   func_0202614C 0x0202614C thumb
 */
#include "../include/Obj00180.h"
#include "../include/Obj24190.h"
#include "../include/Obj24191.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Sound;
extern void func_02026124(struct Sound *obj, u32 idx);
extern void func_0202614C(struct Sound *obj, u32 idx);
void func_021B7F64(char *p)
{
    if (((struct Obj00180 *)p)->f1B8 < 4) {
        func_02026124(((struct Obj00180 *)p)->f1C8, 4);
        func_02026124(((struct Obj00180 *)p)->f1C8, 5);
        return;
    }
    if (((struct Obj24190 *)(*(char * *)&((struct Obj00180 *)p)->f0))->f16 == 0)
        func_02026124(((struct Obj00180 *)p)->f1C8, 5);
    else
        func_0202614C(((struct Obj00180 *)p)->f1C8, 5);
    if (((struct Obj24191 *)(*(char * *)&((struct Obj00180 *)p)->f0))->f16 + 4 >= ((struct Obj00180 *)p)->f1B8) {
        func_02026124(((struct Obj00180 *)p)->f1C8, 4);
        return;
    } else {
        func_0202614C(((struct Obj00180 *)p)->f1C8, 4);
        return;
    }
}
