/*
 * function: func_021B7824
 * address:  0x021B7824
 * packet:   pkt_ov071_021B7824
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_020435F4  0x020435F4  arm
 *   func_0201CE48  0x0201CE48  thumb
 *   func_02045808  0x02045808  arm
 *   func_021B7068  0x021B7068  thumb  ov071
 *   func_021B7BE4  0x021B7BE4  thumb  ov071
 *   func_021B7B9C  0x021B7B9C  thumb  ov071
 *   func_021B7AAC  0x021B7AAC  thumb  ov071
 *   func_021B7994  0x021B7994  thumb  ov071
 *   func_021B78D4  0x021B78D4  thumb  ov071
 *   func_020315D4  0x020315D4  arm
 */
#include "../include/Obj06184.h"
#include "../include/Obj20691.h"
#include "../include/Obj20692.h"

typedef unsigned int u32;

struct PrintSys;
struct Rec3;
struct S020315D4;
struct U16Vec;
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_020435F4(u32 a);
extern void func_0201CE48(struct Rec3 *p);
extern void func_02045808(struct U16Vec *vec);
extern void func_021B7068(void *a);
extern void func_021B7BE4(void *a);
extern void func_021B7B9C(char *p);
extern void func_021B7AAC(void **p);
extern void func_021B7994(void *a);
extern void func_021B78D4(void);
extern void func_020315D4(struct S020315D4 *p);

int func_021B7824(void *a, void *b, char *c, char *d)
{
    if (func_0201C6B4(((struct Obj20692 *)(*(char * *)&((struct Obj20691 *)c)->f4))->f8) == 0)
        return 0;
    func_020435F4(8);
    if (((struct Obj06184 *)d)->f8 != 0)
        func_0201CE48(((struct Obj06184 *)d)->f8);
    if (((struct Obj06184 *)d)->f4 != 0)
        func_02045808(((struct Obj06184 *)d)->f4);
    func_021B7068(((struct Obj06184 *)d)->f7C);
    func_021B7BE4(d);
    func_021B7B9C(d);
    func_021B7AAC((void **)d);
    func_021B7994(d);
    func_021B78D4();
    func_020315D4(a);
    return 1;
}
