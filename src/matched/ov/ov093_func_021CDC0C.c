/*
 * unit: yes
 * function: func_021CDC0C, func_021CDD34
 * address: 0x021CDC0C
 * packet: pkt_ov093_021CDC0C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: The store-and-return follower at 0x021CDD34 is included here;
 * the larger lookup follower at 0x021CDD50 has its own verified shard.
 * symbols:
 *   func_021D3FDC 0x021D3FDC thumb ov093
 *   func_021D3F98 0x021D3F98 thumb ov093
 *   func_021EEBE8 0x021EEBE8 thumb ov093
 *   func_021CDD50 0x021CDD50 thumb ov093
 *   func_021CDD34 0x021CDD34 thumb ov093
 *   func_02005CA4 0x02005CA4 thumb
 *   func_021EAE24 0x021EAE24 thumb ov093
 *   func_02005DF8 0x02005DF8 thumb
 *   func_021F88BC 0x021F88BC thumb ov094
 *   func_02006740 0x02006740 thumb
 *   func_021F8678 0x021F8678 thumb ov094
 *   func_021EEC4C 0x021EEC4C thumb ov093
 *   func_021EAE34 0x021EAE34 thumb ov093
 *   func_02005E50 0x02005E50 thumb
 *   func_021D3FA8 0x021D3FA8 thumb ov093
 *   func_021EAE74 0x021EAE74 thumb ov093
 *   func_021BA7F8 0x021BA7F8 thumb ov093
 */
#include "../include/Obj00818.h"
#include "../include/Obj09986.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int (*Callback)(u8 *,int *);
extern void func_021D3FDC(u8 *,u8 *);
extern int func_021D3F98(u8 *);
extern u8 func_021EEBE8(void *);
extern Callback func_021CDD50(u8 *,u32,int *);
extern void func_021CDD34(u8 *);
extern void func_02005CA4(int,u32);
extern void func_021EAE24(u8 *p);
extern void func_02005DF8(u32 a);
extern void func_021F88BC(int);
extern void func_02006740(void);
extern void *func_021F8678(void);
extern int func_021EEC4C(void *,void *,u32);
extern int func_021EAE34(u8 *p);
extern int func_02005E50(void);
extern int func_021D3FA8(u8 *);
extern void func_021EAE74(char *p, u32 a, u32 b);
extern void func_021BA7F8(char *p);
int func_021CDC0C(u8 *p)
{
    u32 id;
    u16 n;
    int zero;
    func_021D3FDC(p,p+0x18);
    switch (p[0x1a8]) {
    case 0:
        p[0x1a8] = 1;
    case 1:
        if (!func_021D3F98(p+0x18)) {
            id = func_021EEBE8(((struct Obj00818 *)p)->f50);
            if (id) {
                zero = 0;
                *(Callback *)&((struct Obj00818 *)p)->fC8 = func_021CDD50(p,id,0);
                if (*(Callback *)&((struct Obj00818 *)p)->fC8) {
                    p[0x1a8] = 2;
                    ((struct Obj00818 *)p)->fCC = zero;
                }
                else {
                    func_021CDD34(p);
                    p[0x1a8] = 3;
                    ((struct Obj00818 *)p)->fCC = zero;
                }
            }
        } else {
            if (((struct Obj00818 *)p)->f54) {
                func_02005CA4(1,1);
                func_021EAE24(((struct Obj00818 *)p)->f54);
                func_02005DF8(30);
                func_021F88BC(0);
                func_02006740();
            }
            p[0x1a8] = 4;
        }
        break;
    case 2:
        if ((*(Callback *)(p+0xc8))(p,(int *)(p+0xcc))) {
            p[0x1a8] = 3;
            ((struct Obj00818 *)p)->fCC = 0;
            if (func_021F8678()) func_021F88BC(1);
        }
        break;
    case 3:
        if (func_021EEC4C(((struct Obj00818 *)p)->f50,((struct Obj00818 *)p)->fD8,((struct Obj00818 *)p)->fDC)) p[0x1a8] = 1;
        break;
    case 4:
        if (((struct Obj00818 *)p)->f54) {
            if (func_021EAE34(((struct Obj00818 *)p)->f54)) {
                if (!func_02005E50()) {
                    n = func_021D3FA8(p+0x18);
                    func_021EAE74(((struct Obj00818 *)p)->f54,n,n);
                    func_021BA7F8(((struct Obj00818 *)p)->f0);
                }
            }
        }
        break;
    case 5: return 1;
    }
    return 0;
}
void func_021CDD34(u8 *p)
{
    ((struct Obj09986 *)p)->fE0 = 0;
    *(u8 * *)&((struct Obj09986 *)p)->fD8 = p+0xe0;
    ((struct Obj09986 *)p)->fDC = 4;
}
