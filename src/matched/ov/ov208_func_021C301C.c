/*
 * function: ov208_func_021C301C
 * address: 0x021C301C
 * packet: pkt_ov208_021C301C
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B454 0x0204B454 arm
 *   func_0204B5C0 0x0204B5C0 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B5AC 0x0204B5AC arm
 *   _fflt 0x0209BDBC arm
 *   _fdiv 0x0209CE10 arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _fmul 0x0209C77C arm
 *   _ffix 0x0209C494 arm
 *   _fgr 0x0209BBB0 arm
 *   _fleq 0x0209BC0C arm
 *   _fgeq 0x0209BB54 arm
 */
#include "../include/Obj10906.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

struct Pos { s16 x; s16 y; };
struct Pair { int x; int y; };

struct Actor; struct PtS;
extern void func_0204B454(struct Actor *,struct PtS *,unsigned int);
struct Obj;
extern void func_0204B5C0(const struct Obj *o, struct Pair *p);
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B5AC(void *obj, struct Pair *scale);

#define OBJ(p) (*(void **)((p) + *(int *)((p) + 0x5c) * 4 + 0x54))

void ov208_func_021C301C(u16 *heap, u8 *p, int key)
{
    struct Pos pos;
    struct Pair sc;
    float f;
    switch (((struct Obj10906 *)p)->f60) {
    case 0:
    case 2:
        break;
    case 1:
        func_0204B454(OBJ(p), (struct PtS *)&pos, 1);
        func_0204B5C0(OBJ(p), &sc);
        f = (float)sc.y / 4096.0f;
        f += 0.01f;
        if (f >= 1.1f) {
            f = 1.1f;
            ((struct Obj10906 *)p)->f60 = 2;
        }
        pos.y = 0x80 - (int)(96.0f * (f - 1.0f) / 2.0f);
        if (f > 0.0f)
            sc.y = (int)(4096.0f * f + 0.5f);
        else
            sc.y = (int)(4096.0f * f - 0.5f);
        func_0204B404(OBJ(p), (const struct Vec2 *)(&pos), 1);
        func_0204B5AC(OBJ(p), &sc);
        break;
    case 3:
        func_0204B454(OBJ(p), (struct PtS *)&pos, 1);
        func_0204B5C0(OBJ(p), &sc);
        f = (float)sc.y / 4096.0f - 0.01f;
        if (f <= 1.0f) {
            f = 1.0f;
            ((struct Obj10906 *)p)->f60 = 0;
            pos.y = 0x80;
        } else {
            pos.y = 0x80 - (int)(96.0f * (f - 1.0f) / 2.0f);
        }
        if (f > 0.0f)
            sc.y = (int)(4096.0f * f + 0.5f);
        else
            sc.y = (int)(4096.0f * f - 0.5f);
        func_0204B404(OBJ(p), (const struct Vec2 *)(&pos), 1);
        func_0204B5AC(OBJ(p), &sc);
        break;
    }
}
