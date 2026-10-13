/*
 * function: func_021DEDAC
 * address: 0x021DEDAC
 * packet: pkt_ov137_021DEDAC
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021E1FA0 0x021E1FA0 data a2
 *   func_021E16AC 0x021E16AC thumb ov137
 *   func_021E1768 0x021E1768 thumb ov137
 *   func_021DEB10 0x021DEB10 thumb ov137
 *   UNION_APP_GetMemberEntry 0x02184180 thumb ov022
 *   func_021DEF6C 0x021DEF6C thumb ov137
 *   func_021E0304 0x021E0304 thumb ov137
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb  arm9
 */
#include "../include/Obj02869.h"
#include "../include/Obj08215.h"
#include "../include/Obj23748.h"
#include "../include/Obj23749.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u8 pad[0x90]; void *slots[5]; void *other[5]; } Obj;
extern const u16 d_021E1FA0[][5];
extern u8 *func_021E16AC(void *, int);
extern int func_021E1768(char *, int);
extern void *func_021DEB10(char *p);
extern char *UNION_APP_GetMemberEntry(unsigned char *p, int i);
extern void func_02008500(void *, void *);
extern void func_021DEF6C(void *);
extern void GFL_USE_CancelChangeAndPlayBgm(int, int);
extern void func_021E0304(u8 *p);
int func_021DEDAC(Obj *obj)
{
    u8 *p = (u8 *)obj;
    u8 *q;
    int i, count;
    q = func_021E16AC(p, 24);
    ((struct Obj08215 *)q)->f10 = ((struct Obj02869 *)p)->f2C;
    count = ((struct Obj02869 *)p)->f30;
    ((struct Obj08215 *)q)->f14 = count;
    ((struct Obj08215 *)q)->f4 = d_021E1FA0[count][((struct Obj02869 *)p)->f2C];
    for (i = 0; i < 5; i++) {
        if (func_021E1768((char *)p, i)) {
            obj->slots[i] = UNION_APP_GetMemberEntry(func_021DEB10((char *)p), (u8)i);
            func_02008500(obj->slots[i], obj->other[i]);
        }
    }
    func_021DEF6C(p);
    ((struct Obj02869 *)p)->f120 = ((struct Obj08215 *)q)->f4 << 12;
    ((struct Obj02869 *)p)->f0 = 17;
    GFL_USE_CancelChangeAndPlayBgm(1157, 65535);
    ((struct Obj23749 *)(*(u8 * *)&((struct Obj23748 *)(*(u8 * *)&((struct Obj02869 *)p)->fD8))->f14))->f14 = 1;
    func_021E0304(p);
    return 1;
}
