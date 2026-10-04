/*
 * function: func_02196974
 * address:  0x02196974
 * packet:   pkt_ov021_02196974
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020061E4  0x020061E4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AA1C  0x0201AA1C  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_02196034  0x02196034  thumb  ov021
 *   func_02197644  0x02197644  thumb  ov021
 *   func_021968DC  0x021968DC  thumb  ov021
 *   func_02196944  0x02196944  thumb  ov021
 */
#include "../include/Obj03115.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

extern void func_020061E4(u32 a);
struct BigObj;
struct Obj;
extern void *func_02012934(const struct BigObj *p);
extern int func_0201AA1C(void *p);
struct MsgBank;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_02196034(u8 *p, void *fn, u32 n);
extern void func_02197644(u8 *p, u32 b);
extern void func_021968DC(struct Obj *a);
extern void func_02196944(u8 *a);

int func_02196974(u32 s, u8 *p)
{
    int r = 0;

    ((struct Obj03115 *)p)->f300 = s;
    switch (s) {
    case 0:
    case 5:
        func_020061E4(0x73B);
        func_02196034(p, (void *)func_021968DC, 0x3DE);
        r = 1;
        ((struct Obj03115 *)p)->f8 = 1;
        break;
    case 1:
    case 6:
        if (func_0201AA1C(func_02012934(((struct Obj03115 *)p)->f30)) < 2) {
            func_02045CAC((struct MsgBank *)(((struct Obj03115 *)p)->f28), 0x2C, (void *)(((struct Obj03115 *)p)->f38));
            func_02197644(p, 0);
            func_02196034(p, (void *)func_02196944, 0x3EA);
        } else {
            func_020061E4(0x73B);
            ((struct Obj03115 *)p)->f8 = 6;
            func_02196034(p, (void *)func_021968DC, 0x3F0);
            r = 1;
        }
        break;
    case 2:
        func_020061E4(0x73B);
        ((struct Obj03115 *)p)->f8 = 8;
        func_02196034(p, (void *)func_021968DC, 0x3F6);
        r = 1;
        break;
    case 3:
    case 7:
        func_020061E4(0x73B);
        ((struct Obj03115 *)p)->f8 = 7;
        func_02196034(p, (void *)func_021968DC, 0x3FD);
        r = 1;
        break;
    case 4:
        func_020061E4(0x73C);
        ((struct Obj03115 *)p)->f8 = 0xC;
        func_02196034(p, (void *)func_021968DC, 0x404);
        break;
    }
    return r;
}
