/*
 * function: func_021ED3D4
 * address:  0x021ED3D4
 * packet:   pkt_ov093_021ED3D4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Lever: the record from TCBL_GetWork is a struct pointer, not u8 *: the
 * cnt field is then forwarded across the st store instead of being reloaded
 * (u8 * base plus a local kept in r1 gave 84 bytes out).
 *
 * symbols:
 *   BTL_SIDE_GetClientPoke  0x021B9920  thumb  ov093
 *   BTL_MAIN_GetViewPosOfSlot  0x021B8E70  thumb  ov093
 *   BTL_POKEPARAM_GetDisplayMon  0x021D5864  thumb  ov093
 *   func_021F7EE8  0x021F7EE8  thumb  ov094
 *   func_021F7A28  0x021F7A28  thumb  ov094
 *   TCBL_AddTask  0x020311B8  arm
 *   TCBL_GetWork  0x02031290  arm
 *   func_021ED460  0x021ED460  thumb  ov093
 */
#include "../include/Obj10119.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

struct T { char *e; u16 st; u16 pad; u8 *cnt; };

extern u8 *BTL_SIDE_GetClientPoke(void *p, u32 i, u8 j);
extern u8 BTL_MAIN_GetViewPosOfSlot(u8 *p, u32 k);
struct Work;
extern void *BTL_POKEPARAM_GetDisplayMon(struct Work *p);
extern void func_021F7EE8(void *m, int key);
struct Q;
struct S02030FB4;
extern void func_021F7A28(int a, u32 b);
extern void *TCBL_AddTask(u32 a, void *fn, u32 sz, u32 a3);
extern void *TCBL_GetWork(struct S02030FB4 *p);
extern void func_021ED460(void *task, struct Q *q);

void func_021ED3D4(char *p, u8 k, int a, u8 b, int flag)
{
    struct T *t;
    u8 *m;
    u8 y;

    t = (struct T *)TCBL_GetWork(TCBL_AddTask(((struct Obj10119 *)p)->f2C, (void *)func_021ED460, 0xc, 1));
    t->e = p + 0x48 + k * 0xc;
    t->cnt = (u8 *)p + 0x41;
    t->st = 0;
    (*t->cnt)++;
    m = BTL_SIDE_GetClientPoke(((struct Obj10119 *)p)->f138, a, b);
    y = BTL_MAIN_GetViewPosOfSlot(*(u8 * *)&((struct Obj10119 *)p)->f134, k);
    func_021F7EE8(BTL_POKEPARAM_GetDisplayMon((struct Work *)m), y);
    if (flag == 0)
        func_021F7A28(y, 0x26d);
}
