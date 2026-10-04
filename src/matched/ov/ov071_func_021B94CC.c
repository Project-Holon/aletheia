/*
 * function: func_021B94CC
 * address:  0x021B94CC
 * packet:   pkt_ov071_021B94CC
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_020435F4  0x020435F4  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_0201CE48  0x0201CE48  thumb
 *   func_02045808  0x02045808  arm
 *   func_021B9A18  0x021B9A18  thumb  ov071
 *   func_021B71FC  0x021B71FC  thumb  ov071
 *   func_021B718C  0x021B718C  thumb  ov071
 *   func_021B9BA0  0x021B9BA0  thumb  ov071
 *   func_021B9B3C  0x021B9B3C  thumb  ov071
 *   func_021B9BC8  0x021B9BC8  thumb  ov071
 *   func_021B9C1C  0x021B9C1C  thumb  ov071
 *   func_021B9694  0x021B9694  thumb  ov071
 *   func_021B9734  0x021B9734  thumb  ov071
 *   func_021B95CC  0x021B95CC  thumb  ov071
 *   func_02045C04  0x02045C04  arm
 *   func_020315D4  0x020315D4  arm
 */
#include "../include/Obj03177.h"
#include "../include/Obj20746.h"
#include "../include/Obj20747.h"

typedef unsigned int u32;

struct Node;
struct PrintSys;
struct Rec;
struct Rec3;
struct S020315D4;
struct U16Vec;
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_020435F4(u32 a);
extern void func_02030EAC(struct Node *n);
extern void func_0201CE48(struct Rec3 *p);
extern void func_02045808(struct U16Vec *vec);
extern void func_021B9A18(char *p);
extern void func_021B71FC(void *a);
extern void func_021B718C(void *a);
extern void func_021B9BA0(void *a);
extern void func_021B9B3C(char *p);
extern void func_021B9BC8(char *p);
extern void func_021B9C1C(char *p);
extern void func_021B9694(void *a);
extern void func_021B9734(char *p);
extern void func_021B95CC(void);
extern void func_02045C04(struct Rec *rec);
extern void func_020315D4(struct S020315D4 *p);

int func_021B94CC(void *a, void *b, char *c, char *d)
{
    if (func_0201C6B4(((struct Obj20747 *)(*(char * *)&((struct Obj20746 *)c)->f4))->f8) == 0)
        return 0;
    func_020435F4(8);
    func_02030EAC(((struct Obj03177 *)d)->f0);
    if (((struct Obj03177 *)d)->f294 != 0)
        func_0201CE48(((struct Obj03177 *)d)->f294);
    if (((struct Obj03177 *)d)->f290 != 0)
        func_02045808(((struct Obj03177 *)d)->f290);
    func_021B9A18(d);
    if (((struct Obj03177 *)d)->f310 != 0)
        func_021B71FC(((struct Obj03177 *)d)->f310);
    func_021B718C(((struct Obj03177 *)d)->f30C);
    func_021B9BA0(d);
    func_021B9B3C(d);
    func_021B9BC8(d);
    func_021B9C1C(d);
    func_021B9694(d);
    func_021B9734(d);
    func_021B95CC();
    func_02045C04(((struct Obj03177 *)d)->f20);
    func_020315D4(a);
    return 1;
}
