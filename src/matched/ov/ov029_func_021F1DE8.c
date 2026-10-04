/*
 * function: func_021F1DE8
 * address:  0x021F1DE8
 * packet:   pkt_ov029_021F1DE8
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   func_020090F0  0x020090F0  thumb
 *   func_0204B100  0x0204B100  arm
 *   func_0204B034  0x0204B034  arm
 *   func_0204B258  0x0204B258  arm
 *   func_021F1458  0x021F1458  thumb  ov029
 *   func_021F1574  0x021F1574  thumb  ov029
 *   func_021F1950  0x021F1950  thumb  ov029
 *   func_021F1C0C  0x021F1C0C  thumb  ov029
 *   func_02051B84  0x02051B84  arm
 *   func_021F1010  0x021F1010  thumb  ov029
 *   func_021F1A64  0x021F1A64  thumb  ov029
 *   func_021F1A44  0x021F1A44  thumb  ov029
 *   func_021F13FC  0x021F13FC  thumb  ov029
 *   func_021F18F0  0x021F18F0  thumb  ov029
 *   d_021F3214     0x021F3214  data  a4
 *   d_021F3272     0x021F3272  data  a2
 */
#include "../include/Obj00106.h"

struct Bank;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern int func_02012944(int);
extern int func_02008550(int);
extern int func_020090F0(int);
extern int func_0204B100(int, int, int);
extern void *func_0204B034(void *a0, unsigned int a1, unsigned int heap);
extern void func_0204B258(struct Bank *bank, void *p);
extern void func_021F1458(void *, int, int, int);
typedef unsigned char  u8;
extern void func_021F1574(char *p, int idx);
extern void func_021F1950(char *p);
extern void func_021F1C0C(char *p);
extern int func_02051B84(void *, void *, void *, int);
extern void func_021F1010(void *);
extern void func_021F1A64(char *p, int flag);
extern void func_021F1A44(char *p, int flag);
extern void func_021F13FC(void *);
extern void func_021F18F0(int key, int flag, u8 *p);
extern char d_021F3214[];
extern char d_021F3272[];

void func_021F1DE8(char *p, int flag)
{
    int z;

    ((struct Obj00106 *)p)->f459 = func_02008550(func_02012944((int)func_020120F4((const struct Ctx *)(((struct Obj00106 *)p)->f1C))));
    ((struct Obj00106 *)p)->f458 = func_020090F0(((struct Obj00106 *)p)->f20);
    z = 0;
    ((struct Obj00106 *)p)->f34 = func_0204B100(0x44, 0, ((struct Obj00106 *)p)->fC);
    ((struct Obj00106 *)p)->f38 = func_0204B034(d_021F3214, 1, ((struct Obj00106 *)p)->fC);
    func_0204B258((struct Bank *)(((struct Obj00106 *)p)->f34), ((struct Obj00106 *)p)->f38);
    func_021F1458(p, ((struct Obj00106 *)p)->f459, ((struct Obj00106 *)p)->f458, 1);
    func_021F1574(p, ((struct Obj00106 *)p)->f459);
    func_021F1950(p);
    func_021F1C0C(p);
    ((struct Obj00106 *)p)->f10 = func_02051B84(d_021F3272, (void *)func_021F18F0, p, ((struct Obj00106 *)p)->fC);
    if (flag) {
        func_021F1010(p);
        func_021F1A64(p, z);
    } else {
        func_021F13FC(p);
        func_021F1A64(p, 1);
        func_021F1A44(p, 1);
    }
}
