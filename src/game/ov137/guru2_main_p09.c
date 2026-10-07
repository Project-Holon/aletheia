/*
 * file:     guru2_main_p09.c
 * unit:     yes
 * function: func_021DEF14, func_021DEF3C, func_021DEF6C, func_021DEFB4
 * address:  0x021DEF14
 * region:   ov137
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02039338 0x02039338 arm
 *   func_021DCBC4 0x021DCBC4 thumb ov137
 *   func_0200ED48 0x0200ED48 thumb
 *   func_021E16C4 0x021E16C4 thumb ov137
 */
#include "../../matched/include/Obj08216.h"
#include "../../matched/include/Obj14223.h"
#include "../../matched/include/Obj10621.h"
#include "../../matched/include/Obj23750.h"
#include "../../matched/include/Obj23751.h"
#include "../../matched/include/Obj01753.h"

struct Big;
struct L0200ED54;
struct Sub0200852CObj;
typedef unsigned short u16;

typedef unsigned char u8;

typedef unsigned int u32;

typedef struct { u8 pad[0x90]; void *slots[5]; } Obj;

extern u16 func_02039338(void);
extern int func_021DCBC4(void *,int,void *,int);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200ED48(void *);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void func_0200ED54(struct L0200ED54 *l, u32 val);
extern int func_021E16C4(char *,int);
int func_021DEF14(char *p);
int func_021DEF3C(u8 *p);
void func_021DEF6C(Obj *obj);
int func_021DEFB4(char *p);

/*
 * extent: two trailing bytes of zero alignment padding.
 */
int func_021DEF14(char *p) {if(++((struct Obj08216 *)p)->fC>30){((struct Obj08216 *)p)->fC=0;if(func_02039338()==0)((struct Obj08216 *)p)->f0=20;else ((struct Obj08216 *)p)->f0=21;}return 0;}

int func_021DEF3C(u8 *p) { u16 buf; buf=4; if(func_021DCBC4(((struct Obj14223 *)p)->fDC,0x2805,&buf,2)==1) ((struct Obj14223 *)p)->f0=22; return 0; }

void func_021DEF6C(Obj *obj)
{
    u8 *p = (u8 *)obj;
    void *q;
    int i;
    q = func_0200ED48(func_02012EBC(((struct Obj23751 *)(*(u8 * *)&((struct Obj23750 *)(*(u8 * *)&((struct Obj10621 *)p)->fD8))->f14))->f4));
    for (i = 0; i < 5; i++) {
        if (obj->slots[i] && i != func_02039338())
            func_0200ED54(q, func_02008530(obj->slots[i]));
    }
}

/*
 * trailing: Two zero alignment bytes.
 */
int func_021DEFB4(char *p) { if(func_021E16C4(p,4)==1) { ((struct Obj01753 *)p)->f0=22; return 1; } return 0; }
