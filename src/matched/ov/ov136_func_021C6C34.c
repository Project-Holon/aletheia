/*
 * function: func_021C6C34
 * address: 0x021C6C34
 * packet: pkt_ov136_021C6C34
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_02025DE8 0x02025DE8 thumb
 *   func_020260E0 0x020260E0 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021C7648 0x021C7648 thumb
 *   func_021C7250 0x021C7250 thumb
 *   func_021C71D0 0x021C71D0 thumb
 *   func_021C66A0 0x021C66A0 thumb
 *   func_021C7738 0x021C7738 thumb
 */
#include "../include/Obj00412.h"
#include "../include/Obj23618.h"
#include "../include/Obj23619.h"
#include "../include/Obj23620.h"
#include "../include/Obj23621.h"
#include "../include/Obj23622.h"
#include "../include/Obj23623.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct PrintSys;
struct Sound;
extern u32 func_0201C6B4(const struct PrintSys *p);
extern int func_021C7648(u8 *p);
extern void func_020061E4(u32);
extern int func_021C7250(u8 *p, int v, int w);
extern int func_021C71D0(u8 *p, int v, int w);
extern void func_021C66A0(u8 *p, int i, u32 v);
extern int func_02025DE8(struct Sound *obj);
extern u8 func_020260E0(struct Sound *obj);
extern int func_021C7738(void);

int func_021C6C34(u8 *p)
{
    u32 k;
    u8 *r;

    if (func_0201C6B4(((struct Obj23618 *)(*(u8 * *)&((struct Obj00412 *)p)->f8))->f1C4) == 0) {
        return 9;
    }
    switch (func_021C7648(p)) {
    case 0:
        if (((struct Obj00412 *)p)->f1C != 0) {
            ((struct Obj00412 *)p)->f1C -= 1;
            func_020061E4(0x548);
            return func_021C7250(p, 0, 0xB);
        }
        return 9;
    case 1:
        if (((struct Obj00412 *)p)->f1C != ((struct Obj23619 *)(*(u8 * *)&((struct Obj00412 *)p)->f8))->f2FE) {
            ((struct Obj00412 *)p)->f1C += 1;
            func_020061E4(0x548);
            return func_021C7250(p, 1, 0xB);
        }
        return 9;
    case 2:
        func_020061E4(0x551);
        func_021C66A0(((struct Obj00412 *)p)->f8, 3, 9);
        ((struct Obj00412 *)p)->f28 = 10;
        return 0x18;
    case 3:
        func_020061E4(0x556);
        func_021C66A0(((struct Obj00412 *)p)->f8, 7, 8);
        ((struct Obj00412 *)p)->f28 = 10;
        return 0x19;
    }
    k = func_02025DE8(((struct Obj23620 *)(*(u8 * *)&((struct Obj00412 *)p)->f8))->f294);
    switch (k) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        r = *(u8 * *)&((struct Obj00412 *)p)->f8 + k + ((struct Obj00412 *)p)->f1C * 10;
        if (r[0x2E8] == 0xFF) {
            break;
        }
        p[0x1E] = k;
        p[0x1F] = r[0x2E8];
        func_020061E4(0x54C);
        return func_021C71D0(p, k, 0xC);
    case (u32)-2:
        func_020061E4(0x551);
        func_021C66A0(((struct Obj00412 *)p)->f8, 3, 9);
        ((struct Obj00412 *)p)->f28 = 10;
        return 0x18;
    case (u32)-5:
        func_020260E0(((struct Obj23621 *)(*(u8 * *)&((struct Obj00412 *)p)->f8))->f294);
        if (((struct Obj00412 *)p)->f1C != ((struct Obj23622 *)(*(u8 * *)&((struct Obj00412 *)p)->f8))->f2FE) {
            ((struct Obj00412 *)p)->f1C += 1;
            func_020061E4(0x548);
            return func_021C7250(p, 1, 0xB);
        }
        break;
    case (u32)-6:
        func_020260E0(((struct Obj23623 *)(*(u8 * *)&((struct Obj00412 *)p)->f8))->f294);
        if (((struct Obj00412 *)p)->f1C != 0) {
            ((struct Obj00412 *)p)->f1C -= 1;
            func_020061E4(0x548);
            return func_021C7250(p, 0, 0xB);
        }
        break;
    case (u32)-3:
        func_020061E4(0x548);
        break;
    case (u32)-4:
        break;
    default:
        if (func_021C7738()) {
            func_020061E4(0x556);
            func_021C66A0(((struct Obj00412 *)p)->f8, 7, 8);
            ((struct Obj00412 *)p)->f28 = 10;
            return 0x19;
        }
        break;
    }
    return 9;
}
