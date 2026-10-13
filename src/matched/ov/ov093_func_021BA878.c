/*
 * function: func_021BA878
 * address: 0x021BA878
 * packet: pkt_ov093_021BA878
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_SERVER_GetFlow 0x021BB964 thumb ov093
 *   func_021C8138 0x021C8138 thumb ov093
 *   func_021C8140 0x021C8140 thumb ov093
 *   func_021C7CBC 0x021C7CBC thumb ov093
 *   func_021C7CC8 0x021C7CC8 thumb ov093
 *   func_021C7CD4 0x021C7CD4 thumb ov093
 *   func_021C7CDC 0x021C7CDC thumb ov093
 *   func_021C7CE8 0x021C7CE8 thumb ov093
 *   func_021B9AEC 0x021B9AEC thumb ov093
 *   func_021B9B94 0x021B9B94 thumb ov093
 *   func_021B9B98 0x021B9B98 thumb ov093
 *   func_021B9BF0 0x021B9BF0 thumb ov093
 *   BTL_POKEPARAM_GetUsedMoveTotal 0x021D54B4 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   BTL_MAIN_IsClientUsed 0x021B8B9C thumb ov093
 */
#include "../include/Obj01687.h"
#include "../include/Obj09945.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Q1;
struct Q5;
struct Q7;
extern u32 BTL_SERVER_GetFlow(struct Q5 *p);
extern u16 func_021C8138(struct Q7 *p);
struct Q6;
struct S2;
extern unsigned char func_021C8140(char *p, int i);
extern u16 func_021C7CBC(u8 *p);
extern u16 func_021C7CC8(u8 *p);
extern u16 func_021C7CD4(struct Q6 *p);
extern u16 func_021C7CDC(u8 *p);
extern u16 func_021C7CE8(u8 *p);
extern char *func_021B9AEC(char *, int);
extern u8 func_021B9B94(struct Q1 *p);
extern u8 func_021B9B98(u8 *p);
extern u32 func_021B9BF0(struct S2 *p, u32 i);
extern u8 BTL_POKEPARAM_GetUsedMoveTotal(u8 *p);
extern int func_021D59B4(u8 *p, int k);
extern int BTL_MAIN_IsClientUsed(unsigned char *p, unsigned char k);

void func_021BA878(u8 *p)
{
    u8 *q;
    u8 *a;
    char *list;
    u32 n;
    u32 count;
    u32 i;
    void *item;
    if (((struct Obj09945 *)p)->f8 == 0)
        return;
    a = (u8 *)BTL_SERVER_GetFlow(((struct Obj09945 *)p)->f8);
    q = *(u8 * *)&((struct Obj09945 *)p)->f0;
    q[0xb6] = func_021C8138((struct Q7 *)a);
    q[0xb7] = func_021C8140((char *)a, 0);
    q[0xb8] = func_021C7CBC(a);
    q[0xb9] = func_021C7CC8(a);
    q[0xba] = func_021C7CD4((struct Q6 *)a);
    q[0xbb] = func_021C7CDC(a);
    q[0xbc] = func_021C7CE8(a);
    if (((struct Obj01687 *)q)->f8C == 1)
        q[0xbd] = 1;
    list = func_021B9AEC((char *)p + 0x1b0, 0);
    n = func_021B9B94((struct Q1 *)list);
    count = func_021B9B98((u8 *)list);
    for (i = 0; i < n; i++) {
        item = (void *)func_021B9BF0((struct S2 *)list, (u8)i);
        q[0xc0] += BTL_POKEPARAM_GetUsedMoveTotal(item);
        ((struct Obj01687 *)q)->fB4 += (u16)func_021D59B4(item, 13);
    }
    q[0xbf] = n - count;
    list = func_021B9AEC((char *)p + 0x1b0, 1);
    n = func_021B9B94((struct Q1 *)list);
    count = func_021B9B98((u8 *)list);
    q[0xbe] = n - count;
    if (BTL_MAIN_IsClientUsed(p, 3)) {
        list = func_021B9AEC((char *)p + 0x1b0, 3);
        if (list) {
            n = func_021B9B94((struct Q1 *)list);
            count = func_021B9B98((u8 *)list);
            q[0xbe] += (u8)(n - count);
        }
    }
}
