/*
 * function: func_021CE3C8
 * address: 0x021CE3C8
 * packet: pkt_ov093_021CE3C8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EAE44 0x021EAE44 thumb ov093
 *   func_021EAE54 0x021EAE54 thumb ov093
 *   func_021B990C 0x021B990C thumb ov093
 *   func_021D8434 0x021D8434 thumb ov093
 *   func_021CF470 0x021CF470 thumb ov093
 *   func_021CF81C 0x021CF81C thumb ov093
 *   func_021D54C0 0x021D54C0 thumb ov093
 *   func_021D81F8 0x021D81F8 thumb ov093
 *   func_021D82D0 0x021D82D0 thumb ov093
 *   func_021CF58C 0x021CF58C thumb ov093
 *   func_021CE150 0x021CE150 thumb ov093
 *   func_021CF2F0 0x021CF2F0 thumb ov093
 */
#include "../include/Obj00662.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021EAE44(void *);
extern int func_021EAE54(void *);
typedef signed int     s32;
extern void *func_021B990C(char *p, unsigned int i, unsigned int j);
struct Unk021D82D0;
extern void func_021D8434(u32 *p);
extern u32 func_021CF470(u8 *,void *,u8 *);
extern u32 func_021CF81C(u8 *,void *,u8 *);
extern u16 func_021D54C0(u8 *p, int i);
extern u32 func_021D81F8(void *,void *,void *,u32,void *);
extern void func_021D82D0(struct Unk021D82D0 *out, u32 id, u32 sub);
extern void func_021CF58C(struct Unk021D82D0 *out, u8 *p, void *q);
extern void func_021CE150(u8 *p, void *q);
extern u32 func_021CF2F0(u8 *p, s32 *st);
int func_021CE3C8(u8 *p,int *state)
{
    u8 out[4];
    u32 i;
    u32 id;
    switch (*state) {
    case 0:
        func_021EAE44(((struct Obj00662 *)p)->f54);
        (*state)++;
        break;
    case 1:
        if (func_021EAE54(((struct Obj00662 *)p)->f54)) {
            for (; p[0x11d] < p[0x11c]; p[0x11d]++) {
                ((struct Obj00662 *)p)->f8 = func_021B990C(((struct Obj00662 *)p)->f4,p[0x1a6],p[0x11d]);
                *(u8 * *)&((struct Obj00662 *)p)->fC = p+0x124+p[0x11d]*4;
                func_021D8434((u32 *)(*(u8 * *)&((struct Obj00662 *)p)->fC));
                if (!func_021CF470(p,((struct Obj00662 *)p)->f8,*(u8 * *)&((struct Obj00662 *)p)->fC)) {
                    i = func_021CF81C(p,((struct Obj00662 *)p)->f8,out);
                    if (i < 4) {
                        id = func_021D54C0(((struct Obj00662 *)p)->f8,i);
                        func_021D82D0((struct Unk021D82D0 *)(*(u8 * *)&((struct Obj00662 *)p)->fC),id,func_021D81F8(((struct Obj00662 *)p)->f0,((struct Obj00662 *)p)->f4,((struct Obj00662 *)p)->f8,id,p+0x38));
                    } else func_021CF58C((struct Unk021D82D0 *)(*(u8 * *)&((struct Obj00662 *)p)->fC),p,((struct Obj00662 *)p)->f8);
                }
            }
            (*state)++;
        }
        break;
    case 2:
        *(u8 * *)&((struct Obj00662 *)p)->fD8 = p+0x124;
        ((struct Obj00662 *)p)->fDC = p[0x11c]*4;
        func_021CE150(p,(void *)((u32)func_021CF2F0));
        break;
    }
    return 0;
}
