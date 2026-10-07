/*
 * file:     worldtrade_adapter_p26.c
 * unit:     yes
 * function: func_021FF58C, func_021FF65C
 * address:  0x021FF58C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F50EC 0x021F50EC thumb ov135
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_020120F4 0x020120F4 thumb
 *   func_021F6B34 0x021F6B34 thumb ov135
 *   func_021F6B80 0x021F6B80 thumb ov135
 *   func_021F6B40 0x021F6B40 thumb ov135
 *   func_02031348 0x02031348 arm
 *   str_02203E30 0x02203E30 data a1
 *   d_021DC800 0x021DC800 data ov131 a4
 *   func_021F4EC0  0x021F4EC0  thumb  ov135
 */
#include "../../matched/include/Obj01162.h"
#include "../../matched/include/Obj23428.h"
#include "../../matched/include/Obj23429.h"
#include "../../matched/include/Obj23430.h"
#include "../../matched/include/Obj23431.h"
#include "../../matched/include/Obj23432.h"
#include "../../matched/include/Obj23433.h"
#include "../../matched/include/Obj23434.h"
#include "../../matched/include/Obj23435.h"
#include "../../matched/include/Obj12221.h"

struct Ctx;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    void *mon, *ctx, *save;
    u8 type, fD, fE, fF, f10, pad11[3];
    u16 f14, pad16;
    void *f18;
    u32 f1C, f20, f24;
} Request;

typedef signed int s32;

typedef signed short s16;

extern void func_021F50EC(u8 *);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *,u32,u32);
extern void *func_020120F4(const struct Ctx *p);
extern int func_021F6B34(int);
extern u32 func_021F6B80(u8 *p, u32 b, u32 c);
extern void *func_021F6B40(void *,void *,int,int);
extern void func_02031348(void *,u32,const void *,void *);
extern void func_021F4EC0(u8 *p, u32 a, u32 b);
void func_021FF58C(u8 *p);
u32 func_021FF65C(u8 *p);
extern const char str_02203E30[], ov131_id[];
extern const u32 d_021DC800[];

void func_021FF58C(u8 *p)
{
    Request *r;
    func_021F50EC(p);
    *(Request * *)&((struct Obj01162 *)p)->f10DC=func_02030734(0x48,sizeof(Request),0,str_02203E30,0x4C);
    func_02082BCC(*(Request * *)&((struct Obj01162 *)p)->f10DC,0,sizeof(Request));
    r=*(Request * *)&((struct Obj01162 *)p)->f10DC;
    r->ctx=((struct Obj23428 *)(*(u8 * *)&((struct Obj01162 *)p)->f0))->f20;
    r->save=func_020120F4(((struct Obj23429 *)(*(u8 * *)&((struct Obj01162 *)p)->f0))->f40);
    if(func_021F6B34(((struct Obj01162 *)p)->fC4))
        r->fE=func_021F6B80(((struct Obj23430 *)(*(u8 * *)&((struct Obj01162 *)p)->f0))->f8,(u32)(((struct Obj23431 *)(*(u8 * *)&((struct Obj01162 *)p)->f0))->fC),((struct Obj01162 *)p)->fC4);
    else r->fE=30;
    r->fF=((struct Obj01162 *)p)->fC6;
    r->fD=1;
    r->f14=0;
    r->f10=0;
    r->f18=((struct Obj23432 *)(*(u8 * *)&((struct Obj01162 *)p)->f0))->f2C;
    r->f20=0;
    if(func_021F6B34(((struct Obj01162 *)p)->fC4)) {
        r->mon=((struct Obj23433 *)(*(u8 * *)&((struct Obj01162 *)p)->f0))->f8;
        r->type=1;
    } else {
        r->mon=func_021F6B40(((struct Obj23434 *)(*(u8 * *)&((struct Obj01162 *)p)->f0))->f8,((struct Obj23435 *)(*(u8 * *)&((struct Obj01162 *)p)->f0))->fC,((struct Obj01162 *)p)->fC4,0);
        r->type=2;
    }
    func_02031348(((struct Obj01162 *)p)->f12F0,(u32)ov131_id,d_021DC800,r);
    ((struct Obj01162 *)p)->fB8=1;
}


/*
 * Answer 2, or set the 5/mode pair and answer 3 when the +0x12f4 word is clear.
 */
u32 func_021FF65C(u8 *p)
{
    u32 r = 2;

    if (((struct Obj12221 *)p)->f12F4 == 0) {
        func_021F4EC0(p, 5, ((struct Obj12221 *)p)->f20);
        r = 3;
    }
    return r;
}
