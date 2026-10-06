/*
 * function: func_021B8CE4
 * address:  0x021B8CE4
 * packet:   pkt_ov070_021B8CE4
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B6288  0x021B6288  thumb  ov070
 *   func_021B80BC  0x021B80BC  thumb  ov070
 *   func_021B81F4  0x021B81F4  thumb  ov070
 *   func_021B6138  0x021B6138  thumb  ov070
 *   func_020061E4  0x020061E4  thumb
 *   func_0204B8C4  0x0204B8C4  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_021B6100  0x021B6100  thumb  ov070
 *   func_021B8D88  0x021B8D88  thumb  ov070
 */
#include "../include/Obj00002.h"

struct Obj;
extern void func_021B6288(struct Obj *o, int a, int b);
extern void func_021B80BC(void *p);
typedef unsigned short u16;
typedef unsigned char  u8;
struct Obj;
extern void func_021B81F4(u8 *p);
extern void func_021B6138(char *p);
typedef unsigned int   u32;
extern void func_020061E4(u32 a);
extern void func_0204B8C4(struct Obj *p, u32 value);
extern void func_0204B878(struct Obj *p, u16 value);
struct Obj;
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_021B6100(char *p, int k);
extern void func_021B8D88(char *p);

void func_021B8CE4(int p, int u, int a, int b)
{
    int x;
    func_021B6288((struct Obj *)p, u, ((struct Obj00002 *)p)->f80C);
    func_021B80BC((void *)p);
    func_021B81F4((u8 *)p);
    ((struct Obj00002 *)p)->f818 = 0xFFFF;
    func_021B6138((char *)p);
    if (a == 1) {
        func_020061E4(0x7D9);
        x = 0xD;
    } else if (a == 0) {
        func_020061E4(0x7D9);
        x = 0xC;
    }
    ((struct Obj00002 *)p)->f864 = a;
    ((struct Obj00002 *)p)->f866 = 6;
    func_0204B8C4((struct Obj *)(*(int *)((char *)p + ((struct Obj00002 *)p)->f864 * 4 + 0x710)), 0);
    func_0204B878((struct Obj *)(*(int *)((char *)p + ((struct Obj00002 *)p)->f864 * 4 + 0x710)), (unsigned short)x);
    func_0204B92C((struct Obj *)*(int *)((char *)p + ((struct Obj00002 *)p)->f864 * 4 + 0x710), 1);
    *(int *)&((struct Obj00002 *)p)->f868 = b;
    func_021B6100((char *)p, (int)func_021B8D88);
}
