/*
 * function: func_021BE9C8
 * address: 0x021BE9C8
 * packet: pkt_ov099_021BE9C8
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: enclosing guard shares the final return and keeps the original callee-saved register assignment.
 * prototypes: SDK 414AC and 49238 preserve their original live R0 inputs despite void(void) assembly declarations.
 * symbols:
 *   func_0203D210 0x0203D210 arm
 *   func_021B96CC 0x021B96CC thumb ov099
 *   func_0202208C 0x0202208C thumb
 *   func_021BE26C 0x021BE26C thumb ov099
 *   func_0204A698 0x0204A698 arm
 *   func_021C1A44 0x021C1A44 thumb ov099
 *   func_021C1AC0 0x021C1AC0 thumb ov099
 *   func_021BA8BC 0x021BA8BC thumb ov099
 *   func_020414AC 0x020414AC arm
 *   func_020490F4 0x020490F4 arm
 *   func_021BE53C 0x021BE53C thumb ov099
 *   func_02049238 0x02049238 arm
 *   func_020452E8 0x020452E8 arm
 *   func_0202020C 0x0202020C thumb
 *   func_0201F868 0x0201F868 thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_021BB050 0x021BB050 thumb ov099
 *   func_021BDD0C 0x021BDD0C thumb ov099
 *   func_0203C8A8 0x0203C8A8 arm
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 */
#include "../include/Obj02802.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_0203D210(void);
extern int func_021B96CC(int *);
extern void func_0202208C(void *, u32, u32, u32, u32, u32, u32);
extern void func_021BE26C(char *);
extern void func_0204A698(void);
extern int func_021C1A44(char *);
extern void func_021C1AC0(char *);
extern int func_021BA8BC(void *);
extern void func_020414AC(u32);
extern void *func_020490F4(unsigned int id, u16 heap);
extern void func_021BE53C(char *, void *);
extern void func_02049238(void *);
struct Descriptor;
struct Obj;
extern void func_020452E8(struct Descriptor *d);
extern void func_0202020C(struct Obj *o, u16 *a, u16 *b);
extern void func_0201F868(void *);
extern void func_02082BCC(void *, u32, u32);
extern void func_021BB050(void *);
extern void func_021BDD0C(void *, int);
extern void func_0203C8A8(void);
extern void func_021BAAB8(char *, int, int);
int func_021BE9C8(char *p, int v)
{
    void *h;
    if (func_0203D210() == 0) {
        if (func_021B96CC((int *)(p + 0x274)) == 1) {
            func_0202208C(0, 0, 0, 0, 6, 1, 0x21);
            func_021BE26C(p);
            func_0204A698();
        }
        if (func_021C1A44(p) == 1) func_021C1AC0(p);
        ((struct Obj02802 *)p)->f198 = (void *)func_021BA8BC(((struct Obj02802 *)p)->f198);
        func_020414AC(3);
        h = func_020490F4(0x21, 0x21);
        func_021BE53C(p, h);
        func_02049238(h);
        ((struct Obj02802 *)p)->f1328 = 1;
        if (((struct Obj02802 *)p)->fB0 != 0) {
            func_020452E8(((struct Obj02802 *)p)->f1A0);
            func_0202020C(((struct Obj02802 *)p)->fB4, 0, 0);
            ((struct Obj02802 *)p)->fB4 = 0;
            func_0201F868(((struct Obj02802 *)p)->fB0);
            ((struct Obj02802 *)p)->fB0 = 0;
        }
        func_02082BCC(p + 0x10, 0, 0x20);
        func_02082BCC(p + 0x30, 0, 0x20);
        func_02082BCC(p + 0x50, 0, 0x20);
        func_02082BCC(p + 0x70, 0, 0x20);
        func_02082BCC(p + 0x90, 0, 0x20);
        func_021BB050(p);
        func_021BDD0C(p, 0);
        func_0203C8A8();
        func_021BAAB8(p, 0x17, 1);
        ((struct Obj02802 *)p)->f1CC = 5;
    }
    return v;
}
