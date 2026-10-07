/*
 * file:     unit_021B7658_p03.c
 * unit:     yes
 * function: func_021B7EB0, func_021B7F50, func_021B7F64, func_021B7FD0
 * address:  0x021B7EB0
 * region:   ov173
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02027FEC 0x02027FEC thumb
 *   func_02028148 0x02028148 thumb
 *   func_02026124 0x02026124 thumb
 *   func_0202614C 0x0202614C thumb
 *   func_020409B4 0x020409B4 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B8C4 0x0204B8C4 arm
 */
#include "../../matched/include/Obj00362.h"
#include "../../matched/include/Obj24189.h"
#include "../../matched/include/Obj00180.h"
#include "../../matched/include/Obj24190.h"
#include "../../matched/include/Obj24191.h"
#include "../../matched/include/Obj02506.h"
#include "../../matched/include/Obj24192.h"
#include "../../matched/include/Obj24193.h"

struct Sound;
struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern u32 func_02027FEC(u32, u32, u32, u32, u8, u16);
extern void func_02028148(u8 *p);
extern void func_02026124(struct Sound *obj, u32 idx);
extern void func_0202614C(struct Sound *obj, u32 idx);
extern void func_020409B4(u32);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B8C4(struct Obj *p, u32 value);
void func_021B7EB0(char *p, int flag);
int func_021B7F50(char *p);
void func_021B7F64(char *p);
void func_021B7FD0(u8 *p,int direction);

/*
 * extent: padding at 0x021B7F4E; separate follower func_021B7F50 at 0x021B7F50.
 */
void func_021B7EB0(char *p, int flag)
{
    if (flag == 1) {
        if (*(u32 *)&((struct Obj00362 *)p)->f220 == 0) {
            *(u32 *)&((struct Obj00362 *)p)->f220 = func_02027FEC(((struct Obj00362 *)p)->f1DC, (u32)(p + 0x1e4), 13, 21, 9, 0x4f);
            *(u32 *)&((struct Obj00362 *)p)->f224 = func_02027FEC(((struct Obj00362 *)p)->f1DC, (u32)(p + 0x1f0), 22, 21, 9, 0x4f);
            func_0202614C(((struct Obj00362 *)p)->f1C8, 8);
            ((struct Obj00362 *)p)->f1CE = 1;
            return;
        }
    } else {
        if (*(u32 *)&((struct Obj00362 *)p)->f220 != 0) {
            func_02028148(((struct Obj00362 *)p)->f220);
            func_02028148(((struct Obj00362 *)p)->f224);
            func_020409B4(4);
            *(u32 *)&((struct Obj00362 *)p)->f220 = 0;
            *(u32 *)&((struct Obj00362 *)p)->f224 = 0;
        }
        func_02026124(((struct Obj00362 *)p)->f1C8, 8);
        ((struct Obj00362 *)p)->f1CE = 0;
    }
}

int func_021B7F50(char *p)
{
    if (((struct Obj24189 *)p)->f220 != 0)
        return 1;
    return 0;
}

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

void func_021B7FD0(u8 *p,int direction)
{
    func_0204B8C4(((struct Obj02506 *)p)->f108,0);
    func_0204B8C4(((struct Obj02506 *)p)->f104,0);
    if(direction>0) {
        if(((struct Obj24192 *)(*(u8 * *)&((struct Obj02506 *)p)->f0))->f16+4 < ((struct Obj02506 *)p)->f1B8) func_0204B878(((struct Obj02506 *)p)->f104,10);
        else func_0204B878(((struct Obj02506 *)p)->f104,23);
        func_0204B878(((struct Obj02506 *)p)->f108,3);
    } else {
        if(((struct Obj24193 *)(*(u8 * *)&((struct Obj02506 *)p)->f0))->f16==0) func_0204B878(((struct Obj02506 *)p)->f108,24);
        else func_0204B878(((struct Obj02506 *)p)->f108,11);
        func_0204B878(((struct Obj02506 *)p)->f104,2);
    }
}
