/*
 * function: func_021CDA18
 * address: 0x021CDA18
 * packet: pkt_ov093_021CDA18
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D3FDC 0x021D3FDC thumb ov093
 *   func_021EEBE8 0x021EEBE8 thumb ov093
 *   func_021CDD34 0x021CDD34 thumb ov093
 *   func_021EEC20 0x021EEC20 thumb ov093
 *   func_021CDD50 0x021CDD50 thumb ov093
 *   func_021D3FAC 0x021D3FAC thumb ov093
 *   func_021D3FC4 0x021D3FC4 thumb ov093
 *   func_021D3F4C 0x021D3F4C thumb ov093
 *   func_021EEC4C 0x021EEC4C thumb ov093
 *   func_021D3F60 0x021D3F60 thumb ov093
 *   func_02005CA4 0x02005CA4 thumb
 *   func_02006740 0x02006740 thumb
 *   func_02005E50 0x02005E50 thumb
 *   func_021D3FA8 0x021D3FA8 thumb ov093
 *   func_021BA73C 0x021BA73C thumb ov093
 *   func_02006734 0x02006734 thumb
 */
#include "../include/Obj00463.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int (*Callback)(u8 *,int *);
typedef struct { u8 f0:1,f1:1,f2:1,f3:1,f4:1,f5:1,rest:2; } Flags;
extern void func_021D3FDC(u8 *,void *);
extern u8 func_021EEBE8(void *);
extern void func_021CDD34(u8 *);
extern int func_021EEC20(int,u32 **);
extern Callback func_021CDD50(u8 *,u32,int *);
extern int func_021D3FAC(u8 *);
extern void func_021D3FC4(u8 *);
extern int func_021D3F4C(void *);
extern int func_021EEC4C(void *,void *,u32);
extern u8 func_021D3F60(u8 *);
extern void func_02005CA4(int,u32);
extern void func_02006740(void);
extern int func_02005E50(void);
extern u16 func_021D3FA8(u8 *p);
extern void func_021BA73C(char *,int);
extern void func_02006734(u8);
int func_021CDA18(u8 *p)
{
    u32 id, *pair, x, y;
    int flag, n;
    func_021D3FDC(p,p+0x18);
    switch (p[0x1a8]) {
    case 0:
        id = func_021EEBE8(((struct Obj00463 *)p)->f50);
        if (p[0x1a7] == 2 && (((Flags *)(p+0x1b2))->f4 || ((Flags *)(p+0x1b2))->f5) && !id) return 0;
        func_021CDD34(p);
        if (id == 9) {
            func_021EEC20(*(int *)&((struct Obj00463 *)p)->f50,&pair);
            x = pair[0]; y = pair[1];
            ((struct Obj00463 *)p)->f30 = y;
            ((struct Obj00463 *)p)->f2C = x;
            ((struct Obj00463 *)p)->fCC = 0;
            p[0x1a8] = 3;
        } else if (id) {
            *(Callback *)&((struct Obj00463 *)p)->fC8 = func_021CDD50(p,id,&flag);
            if (flag) {
                if (!func_021D3FAC(p+0x18)) { p[0x1a8] = 6; break; }
            } else func_021D3FC4(p+0x18);
            if (*(Callback *)&((struct Obj00463 *)p)->fC8) {
                p[0x1a8] = 1;
                ((struct Obj00463 *)p)->fCC = 0;
            } else {
                ((struct Obj00463 *)p)->fCC = 0;
                p[0x1a8] = 2;
            }
        } else if (((Flags *)(p+0x1b2))->f1) return 1;
        break;
    case 1:
        if ((*(Callback *)(p+0xc8))(p,(int *)(p+0xcc))) {
            if (((Flags *)(p+0x1b2))->f1) return 1;
            if (func_021D3F4C(p+0x18)) p[0x1a8] = 4;
            else p[0x1a8] = 2;
        }
        break;
    case 2:
        if (func_021EEC4C(((struct Obj00463 *)p)->f50,((struct Obj00463 *)p)->fD8,((struct Obj00463 *)p)->fDC)) p[0x1a8] = 0;
        if (((Flags *)(p+0x1b2))->f1) return 1;
        break;
    case 3:
        if (func_021EEC4C(((struct Obj00463 *)p)->f50,((struct Obj00463 *)p)->fD8,((struct Obj00463 *)p)->fDC)) p[0x1a8] = 7;
        if (((Flags *)(p+0x1b2))->f1) return 1;
        break;
    case 6:
        if (func_021D3F4C(p+0x18)) p[0x1a8] = 4;
        break;
    case 4:
        if (func_021D3F60(p+0x18) == 1) p[0x1a8] = 7;
        else {
            if (((struct Obj00463 *)p)->f54) { func_02005CA4(1,62); func_02006740(); }
            p[0x1a8] = 5;
        }
        break;
    case 5:
        if (!func_02005E50()) {
            n = func_021D3FA8(p+0x18);
            func_02005CA4(0,1);
            func_021BA73C(*(char * *)&((struct Obj00463 *)p)->f0,n);
            func_02006734(0);
        }
        break;
    case 7:
        return 1;
    }
    return 0;
}
