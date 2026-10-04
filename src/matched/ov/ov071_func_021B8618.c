/*
 * function: func_021B8618
 * address: 0x021B8618
 * packet: pkt_ov071_021B8618
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_02043534 0x02043534 arm
 *   func_020315D4 0x020315D4 arm
 *   func_021B8750 0x021B8750 thumb ov071
 *   func_021B869C 0x021B869C thumb ov071
 *   func_021B878C 0x021B878C thumb ov071
 */
#include "../include/Obj20733.h"
#include "../include/Obj20734.h"

typedef unsigned int   u32;
struct PrintSys;
struct S020315D4;
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_02043534(unsigned int);
extern void func_020315D4(struct S020315D4 *p);
extern void func_021B8750(void **);
extern void func_021B869C(void);
extern void func_021B878C(void *);
int func_021B8618(void *a, void *b, char *c, void **d)
{
    if (func_0201C6B4(((struct Obj20734 *)(*(char * *)&((struct Obj20733 *)c)->f4))->f8) == 0) return 0;
    func_02043534(8);
    func_021B8750(d);
    func_021B869C();
    func_021B878C(d);
    func_020315D4(a);
    return 1;
}
