/*
 * function: func_02188FCC
 * address:  0x02188FCC
 * packet:   pkt_ov096_02188FCC
 * region:   ov096
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   func_0218A160  0x0218A160  thumb  ov096
 *   func_0218A308  0x0218A308  thumb  ov096
 *   func_0218A0F4  0x0218A0F4  thumb  ov096
 *   func_021B8DE4  0x021B8DE4  thumb  ov093
 *   func_021B99B8  0x021B99B8  thumb  ov093
 *   func_021B9B94  0x021B9B94  thumb  ov093
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   BTL_POKEPARAM_GetMajorStatusIndex  0x021D62A8  thumb  ov093
 *   ITEMMENU_FreeGraphics  0x021B9AF8  thumb  ov070
 */
#include "../include/Obj10180.h"

typedef unsigned char u8;
typedef unsigned int u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern u8 func_0218A160(u8 *p, int k);
extern u8 func_021B8DE4(char *p, int i);
extern char *ITEMMENU_FreeGraphics(char *p, int i);
extern int func_021B99B8(void *pp, unsigned int b);
struct Q1;
extern u8 func_021B9B94(struct Q1 *p);
extern u8 *func_0218A308(void *, u32);
extern int BTL_POKEPARAM_IsFainted(void *);
struct Unk021D62A8;
extern int BTL_POKEPARAM_GetMajorStatusIndex(struct Unk021D62A8 *p);
extern int func_0218A0F4(u8 *a, int op, int x, int y, int z);

void func_02188FCC(struct Cursor *a, int b, int c)
{
    int t0;
    int t1;
    int n;
    char *handle;
    int i;

    t0 = VM_GetU32(a);
    t1 = VM_GetU32(a);
    n = func_021B8DE4((char *)(((struct Obj10180 *)b)->fB0), func_0218A160((u8 *)b, t0));
    handle = ITEMMENU_FreeGraphics(*(char * *)&((struct Obj10180 *)b)->fB8, n);
    for (i = func_021B99B8((void *)(((struct Obj10180 *)b)->fB0), n);
         i < func_021B9B94((struct Q1 *)handle); i++) {
        u8 *t = func_0218A308(handle, (unsigned char)i);

        if (BTL_POKEPARAM_IsFainted(t) == 0) {
            if (func_0218A0F4((u8 *)a, c, BTL_POKEPARAM_GetMajorStatusIndex((struct Unk021D62A8 *)t), 0, t1) != 0)
                break;
        }
    }
}
