/*
 * file:     unit_0207312C_p02.c
 * unit:     yes
 * function: func_02073500, func_02073548
 * address:  0x02073500
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02060614  0x02060614  arm
 *   func_02060550  0x02060550  arm
 */
#include "../../matched/include/Obj00513.h"

struct DList;
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct Obj_02073548 {
    char pad4[4];
    void *f4;
    char pad3d[0x3d - 8];
    u8 b3d;
} Obj_02073548;

extern void *func_02060614(struct DList *list, void *elem);
extern void func_02060550(volatile struct DList *list, void *before, void *elem);
int func_02073500(int a0);
void func_02073548(void *list, Obj_02073548 *obj);


int func_02073500(int a0){ int t0, t1; ((struct Obj00513 *)((char *)(a0)))->f2E = (unsigned char)0; ((struct Obj00513 *)((char *)(a0)))->f2D = (unsigned char)0; ((struct Obj00513 *)((char *)(a0)))->f2F = (unsigned char)0; ((struct Obj00513 *)((char *)(a0)))->f34 = (unsigned short)0; ((struct Obj00513 *)((char *)(a0)))->f3E = (unsigned short)0; ((struct Obj00513 *)((char *)(a0)))->f40 = (unsigned char)0x7f; ((struct Obj00513 *)((char *)(a0)))->f41 = (unsigned char)0x7f; t0 = func_02075B94((int)(a0 + 0x1c), (int)0x7f); t1 = func_02075BAC((int)(a0 + 0x1c), (int)0x7f00, (int)1); return t1; }


void func_02073548(void *list, Obj_02073548 *obj)
{
    Obj_02073548 *curr = (Obj_02073548 *)func_02060614(list, 0);
    while (curr != 0) {
        if (obj->b3d < curr->b3d) {
            break;
        }
        curr = (Obj_02073548 *)func_02060614(list, curr);
    }
    func_02060550(list, curr, obj);
    obj->f4 = list;
}
