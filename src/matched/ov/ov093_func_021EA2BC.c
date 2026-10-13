/*
 * function: func_021EA2BC
 * address:  0x021EA2BC
 * packet:   pkt_ov093_021EA2BC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E9100  0x021E9100  thumb  ov093
 *   BTL_CLIENT_IsMainStepActive  0x021CD9E0  thumb  ov093
 *   func_021ED208  0x021ED208  thumb  ov093
 *   func_021ED250  0x021ED250  thumb  ov093
 *   func_021ECF68  0x021ECF68  thumb  ov093
 *   func_021EA32C  0x021EA32C  thumb  ov093
 */
#include "../include/Obj04377.h"
#include "../include/Obj07844.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *func_021E9100(u8 *p, int n);
extern u32 BTL_CLIENT_IsMainStepActive(u8 *p);
extern void func_021ED208(char *p, u8 k, u16 a, int flag);
extern int func_021ED250(char *p);
struct T;
extern int func_021ECF68(struct T *p);
extern void func_021EA32C(u8 *p, int k);

int func_021EA2BC(char *ctx)
{
    u8 *t;
    u32 f;
    u32 i;

    t = func_021E9100((u8 *)ctx, 0x14);
    switch (((struct Obj04377 *)t)->f8) {
    case 0:
        f = BTL_CLIENT_IsMainStepActive(*(u8 * *)&((struct Obj07844 *)ctx)->f4);
        for (i = 0; i < t[6]; i++) {
            func_021ED208(*(char * *)&((struct Obj07844 *)ctx)->f17C, t[i], ((struct Obj04377 *)t)->f10, f);
        }
        func_021EA32C((u8 *)ctx, ((struct Obj04377 *)t)->fC);
        ((struct Obj04377 *)t)->f8 = ((struct Obj04377 *)t)->f8 + 1;
        break;
    case 1:
        if (func_021ED250(*(char * *)&((struct Obj07844 *)ctx)->f17C) != 0) {
            if (func_021ECF68((struct T *)(*(char * *)&((struct Obj07844 *)ctx)->f17C)) != 0) {
                return 1;
            }
        }
        break;
    }
    return 0;
}
