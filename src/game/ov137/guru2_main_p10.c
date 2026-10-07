/*
 * file:     guru2_main_p10.c
 * unit:     yes
 * function: func_021DEFD0, func_021DEFE8, func_021DF004, func_021DF01C, func_021DF050, func_021DF060, func_021DF1C4, func_021DF204, func_021DF22C, func_021DF2A0, func_021DF2B8, func_021DF2E0, func_021DF370, func_021DF3E8, func_021DF434, func_021DF488, func_021DF4AC, func_021DF548, func_021DF56C, func_021DF5B0, func_021DF5EC, func_021DF648, func_021DF6A4, func_021DF6B8, func_021DF6D4, func_021DF6FC, func_021DF778, func_021DF7A4, func_021DF7CC, func_021DF7E8
 * address:  0x021DEFD0
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
 *   func_020399A8 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_021E1584 0x021E1584 thumb ov137
 *   func_021E129C 0x021E129C thumb ov137
 *   func_021E0478 0x021E0478 thumb ov137
 *   func_02039338  0x02039338  arm
 *   func_021E161C 0x021E161C thumb ov137
 *   func_021E1210 0x021E1210 thumb ov137
 *   func_021E11F4 0x021E11F4 thumb ov137
 *   func_021E1400 0x021E1400 thumb ov137
 *   func_021E04C4 0x021E04C4 thumb ov137
 *   func_021E140C 0x021E140C thumb ov137
 *   func_021DCBC4 0x021DCBC4 thumb ov137
 *   func_021E1204 0x021E1204 thumb ov137
 *   func_021E0634 0x021E0634 thumb ov137
 *   func_021E1604 0x021E1604 thumb ov137
 *   func_021E0A44 0x021E0A44 thumb ov137
 *   func_021E19C0 0x021E19C0 thumb ov137
 *   d_021E1FDC 0x021E1FDC data a2
 *   func_021E15DC 0x021E15DC thumb ov137
 *   func_021E1830 0x021E1830 thumb ov137
 *   func_021E0570 0x021E0570 thumb ov137
 *   func_021E07A4 0x021E07A4 thumb ov137
 *   func_021E0450 0x021E0450 thumb ov137
 *   func_021E01B0 0x021E01B0 thumb ov137
 *   func_021E1988 0x021E1988 thumb ov137
 *   func_021E19A4 0x021E19A4 thumb ov137
 *   func_021E14E4 0x021E14E4 thumb ov137
 *   func_021E026C 0x021E026C thumb ov137
 *   func_020056EC 0x020056EC thumb
 *   func_0201292C 0x0201292C thumb
 *   func_02007E50 0x02007E50 thumb
 *   _u32_div_f 0x0209C2B0 arm
 *   d_021E1F34 0x021E1F34 data a4
 *   func_021E0130 0x021E0130 thumb ov137
 *   func_02008DF0 0x02008DF0 thumb
 *   func_0203516C 0x0203516C arm
 *   func_021E1784 0x021E1784 thumb ov137
 *   func_0201088C 0x0201088C thumb
 *   func_0202EE30 0x0202EE30 thumb
 *   func_02010904 0x02010904 thumb
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0200FBB0 0x0200FBB0 thumb
 *   func_0200F7B8 0x0200F7B8 thumb
 *   func_0202223C 0x0202223C thumb
 *   func_0202F038 0x0202F038 thumb
 *   func_02010934 0x02010934 thumb
 *   func_0203D7BC 0x0203D7BC arm
 *   func_0203D7B0 0x0203D7B0 arm
 *   func_0203A5E4 0x0203A5E4 arm
 *   func_021DEB10 0x021DEB10 thumb ov137
 *   func_02184174 0x02184174 thumb ov022
 *   func_0218417C 0x0218417C thumb ov022
 *   func_0202208C 0x0202208C thumb
 *   func_020221A4 0x020221A4 thumb
 *   func_02021D50 0x02021D50 thumb
 *   func_0204A648 0x0204A648 arm
 *   func_020419E4 0x020419E4 arm
 */
#include "../../matched/include/Obj02209.h"
#include "../../matched/include/Obj06538.h"
#include "../../matched/include/Obj23754.h"
#include "../../matched/include/Obj01415.h"
#include "../../matched/include/Obj05429.h"
#include "../../matched/include/Obj23755.h"
#include "../../matched/include/Obj23756.h"
#include "../../matched/include/Obj04542.h"
#include "../../matched/include/Obj23757.h"
#include "../../matched/include/Obj02497.h"
#include "../../matched/include/Obj14225.h"
#include "../../matched/include/Obj04539.h"
#include "../../matched/include/Obj10622.h"
#include "../../matched/include/Obj06540.h"
#include "../../matched/include/Obj06541.h"
#include "../../matched/include/Obj08217.h"
#include "../../matched/include/Obj05430.h"
#include "../../matched/include/Obj23759.h"
#include "../../matched/include/Obj23760.h"
#include "../../matched/include/Obj08218.h"
#include "../../matched/include/Obj08219.h"
#include "../../matched/include/Obj08220.h"
#include "../../matched/include/Obj14226.h"
#include "../../matched/include/Obj23761.h"
#include "../../matched/include/Obj23762.h"
#include "../../matched/include/Obj05431.h"
#include "../../matched/include/Obj23763.h"
#include "../../matched/include/Obj10623.h"
#include "../../matched/include/Obj14227.h"
#include "../../matched/include/Obj03305.h"
#include "../../matched/include/Obj10624.h"
#include "../../matched/include/Obj23766.h"

struct Entry;
struct Link;
struct BigObj;
struct Sub02008C20Obj;
struct Sub0201088CObj;
struct S02021D50;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

typedef struct {int a,b;u16 values[5];u16 flag;} Msg;

typedef struct {u8 pad[28]; int angle;} Selected;

typedef struct { int state; u8 pad[36]; Selected *selected; int index, count; } Obj_021DF22C;

typedef struct { u8 pad[0x60]; u16 angles[5]; } Obj_021DF2E0;

struct Range { u32 low, high; };

extern struct Entry *func_020399A8(void);
extern void func_02039C68(struct Link *,unsigned int,unsigned int);
extern u32 func_02039CB4(struct Link *,u32,u32);
extern void func_021E1584(char *,int);
extern void func_021E129C(char *);
extern void func_021E0478(u8 *p, u32 i);
extern u16 func_02039338(void);
extern int func_021E161C(char *);
extern int func_021E1210(char *);
extern u16 func_021E1400(char *p);
extern int func_021E04C4(char *);
extern int func_021E1204(char *);
extern void func_021E11F4(char *);
extern void func_021E140C(char *);
extern void func_021E0634(u8 *p, int a);
extern void func_021E1604(char *,int);
extern int func_021DCBC4(void *,int,void *,int);
extern u8 *func_021E0A44(void *);
extern void func_020061E4(u32 a);
extern void func_021E19C0(char *,int);
extern void func_021E15DC(int *, int);
extern int func_021E1830(char *p, int angle, int index);
extern void func_021E0570(u8 *p);
extern void func_021E07A4(char *p);
extern void func_021E0450(u8 *p, void *text, int index, int a);
extern void func_021E01B0(u8 *p, int message, void *value);
extern void func_021E1988(unsigned int n);
extern int func_021E19A4(void);
extern void func_021E14E4(const char *p);
extern void func_021E026C(u8 *p, int message, unsigned value);
extern u32 func_020056EC(u32);
extern void *func_0201292C(const struct BigObj *p);
extern u32 func_02007E50(u8 *, u16, u16, u16);
extern void func_021E0130(u8 *p, int message);
extern u32 func_02008DF0(struct Sub02008C20Obj *,int);
extern void func_0203516C(u32);
extern void func_021E1784(char *p, int i);
extern void *func_0201088C(unsigned, unsigned);
extern u8 *func_0202EE30(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);
extern u32 func_02010904(struct Sub0201088CObj *p);
extern unsigned func_0200FB24(void);
extern u32 func_0200FBB0(void);
extern u32 func_0200F7B8(u32 a0);
extern void func_0202223C(unsigned, unsigned);
extern void func_0202F038(u8 *p);
extern void func_02010934(struct Sub0201088CObj *p);
extern void func_0203D7BC(u8 a0);
extern void func_0203D7B0(u8 a0);
extern void func_0203A5E4(unsigned);
extern void *func_021DEB10(char *p);
extern void func_02184174(u8 *p);
extern u32 func_0218417C(u8 *);
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern u32 func_020221A4(void);
extern void func_02021D50(struct S02021D50 *);
extern void func_0204A648(void);
extern void func_020419E4(void);
int func_021DEFD0(int *p);
int func_021DEFE8(int *p);
int func_021DF004(char *p);
int func_021DF01C(u8 *p);
int func_021DF050(u8 *p);
int func_021DF060(char *p);
int func_021DF1C4(u8 *p);
int func_021DF204(char *p);
int func_021DF22C(Obj_021DF22C *obj);
int func_021DF2A0(int *p);
int func_021DF2B8(int *p);
int func_021DF2E0(Obj_021DF2E0 *obj);
int func_021DF370(u8 *p);
int func_021DF3E8(u8 *p);
int func_021DF434(u8 *p);
int func_021DF488(u8 *p);
int func_021DF4AC(u8 *p);
int func_021DF548(u8 *p);
int func_021DF56C(u8 *p);
int func_021DF598(u8 *p);
int func_021DF5B0(u8 *p);
int func_021DF5EC(u8 *p);
int func_021DF648(u8 *p);
int func_021DF6A4(u8 *p);
int func_021DF6B8(char *p);
int func_021DF6D4(u8 *p);
int func_021DF6FC(u8 *p);
int func_021DF778(char *p);
int func_021DF7A4(int *p);
int func_021DF7CC(int *p);
int func_021DF7E4(void);
void func_021DF7E8(void *arg,char *p);
extern u16 d_021E1FDC[][5];
extern struct Range d_021E1F34[];

int func_021DEFD0(int *p) { func_02039C68((struct Link *)func_020399A8(),203,40); *p=23; return 0; }

int func_021DEFE8(int *p) { if(func_02039CB4((struct Link *)func_020399A8(),203,40)) *p=24; return 0; }

int func_021DF004(char *p) { func_021E1584(p,1); func_021E129C(p); ((struct Obj02209 *)p)->f0=25; return 0; }

int func_021DF01C(u8 *p) { int i; ((struct Obj06538 *)p)->fC+=1; if(((struct Obj06538 *)p)->fC<95) return 0; for(i=0;i<((struct Obj06538 *)p)->f30;i++) func_021E0478(p,i); ((struct Obj06538 *)p)->fC=0; ((struct Obj06538 *)p)->f0=26; return 0; }


/*
 * Addresses are Black-image addresses.
 */
int func_021DF050(u8 *p)
{
    func_02039338();
    ((struct Obj23754 *)p)->f0 = 0x1b;
    return 0;
}

int func_021DF060(char *p)
{
    char *s;
    Msg msg;
    int state,i,rate;
    state=func_021E161C(p);
    if(state==1 && func_021E1210(p)==0 && ((struct Obj01415 *)p)->f5C==0) ((struct Obj01415 *)p)->f20=1;
    if(((struct Obj01415 *)p)->f6A==1) {((struct Obj01415 *)p)->f0=28;return 1;}
    if(state==0) {
        if(((struct Obj01415 *)p)->f34 && func_021E1210(p)==0) func_021E11F4(p);
        if(func_021E1400(p)==0 && func_021E04C4(p)==1) {
            if(func_021E1210(p)==0) ((struct Obj01415 *)p)->f38=1;
            func_021E140C(p);
        }
        if(((struct Obj01415 *)p)->f38) {
            if(func_021DCBC4(((struct Obj23755 *)(*(char * *)&((struct Obj01415 *)p)->fD8))->f18,0x2807,p+0x38,1)==1) ((struct Obj01415 *)p)->f38=0;
        }
    }
    s=p+0xe0;
    if(func_02039338()==0) {
        if(((struct Obj01415 *)p)->f8<300) {
            ((struct Obj05429 *)s)->f48+=95;
            if(((struct Obj05429 *)s)->f48>=0x7000) ((struct Obj05429 *)s)->f48=0x7000;
        } else {
            ((struct Obj05429 *)s)->f48-=95;
            if(((struct Obj05429 *)s)->f48<0x4000) ((struct Obj05429 *)s)->f48=0x4000;
        }
    }
    if(func_02039338()==0) {
        msg.a=((struct Obj01415 *)p)->f11C;
        msg.flag=((struct Obj01415 *)p)->f20;
        msg.b=((struct Obj01415 *)p)->f33C;
        for(i=0;i<((struct Obj01415 *)p)->f30;i++) msg.values[i]=*(int *)(p+i*0xb4+0x2fc)/4096;
        func_021DCBC4(((struct Obj01415 *)p)->fDC,0x2808,&msg,20);
    }
    if(func_02039338()==0) {
        rate=((struct Obj01415 *)p)->f128;
        if(func_021E1204(p)==1) func_021E0634((u8 *)(p+0xe0),rate*2);
        else func_021E1604(p,rate);
    }
    return 0;
}

int func_021DF1C4(u8 *p)
{
    func_021E1584((char *)p, 0);
    *(u8 * *)&((struct Obj02209 *)p)->f28 = func_021E0A44(p);
    if (func_02039338() == 0) {
        if (((struct Obj23756 *)(*(u8 * *)&((struct Obj02209 *)p)->f28))->fC == func_02039338())
            ((struct Obj02209 *)p)->f0 = 29;
        else
            ((struct Obj02209 *)p)->f0 = 30;
    } else {
        ((struct Obj02209 *)p)->f0 = 31;
    }
    func_020061E4(1833);
    return 1;
}

int func_021DF204(char *p) { func_021E19C0(p,0x4000); *(u8 * *)&((struct Obj04542 *)p)->f28=func_021E0A44(p); if(((struct Obj23757 *)(*(u8 * *)&((struct Obj04542 *)p)->f28))->fC!=func_02039338()) ((struct Obj04542 *)p)->f0=30; return 0; }

#pragma opt_propagation off

/*
 * note 2026-10-05 (wave P17 L7, final push G6L7): DIFF 26/116, obj/step/target colour
 * rotation and index load order; about 60 forms tried (see git history of the pending copy).
 *
 * pass 2 2026-10-06 P2L39: EXACT in --lang c99 and --lang c. Under #pragma opt_propagation
 * off, all locals declared at the top (target before step), with step assigned before
 * target: this gives obj r6, step r5, target r4. A named table pointer local assigned first
 * keeps the table load live across the multiply (table r4), which lets count be a named
 * local without a copy before muls. The reads in the order index, selected, count, angle
 * give the low colours (angle r1, count r2, index r3).
 */
int func_021DF22C(Obj_021DF22C *obj)
{
    Selected *sel;
    int current, index, count;
    int target, step;
    int angle, delta;
    u16 (*table)[5];
    table = d_021E1FDC;
    index = obj->index;
    sel = obj->selected;
    count = obj->count;
    current = sel->angle;
    step = 0x4000;
    target = table[count][index] << 12;
    angle = current;
    delta = target - current;
    if (delta < 0) delta = target + 0x168000 - current;
    if (delta <= 0x10000) step >>= 1;
    if (delta < step) step = delta;
    func_021E19C0((char *)obj, step);
    func_021E15DC(&angle, step);
    if (angle / 4096 == target / 4096) obj->state = 31;
    return 0;
}

#pragma opt_propagation reset

int func_021DF2A0(int *p) { func_02039C68((struct Link *)func_020399A8(),204,40); *p=32; return 0; }

int func_021DF2B8(int *p) { if(func_02039CB4((struct Link *)func_020399A8(),204,40)) { if(func_02039338()==0) *p=33; else *p=34; } return 0; }

int func_021DF2E0(Obj_021DF2E0 *obj)
{
    u8 *p = (u8 *)obj;
    struct { u16 angle, mask, entries[6]; } buf;
    int i;
    u8 *q;
    buf.angle = ((struct Obj02497 *)p)->f58 / 4096;
    ((struct Obj02497 *)p)->f1C = 0;
    for (i = 0; i < ((struct Obj02497 *)p)->f30; i++) {
        q = p + 0x2e0 + i * 180;
        {
        int angle;
        angle = obj->angles[i];
        buf.entries[((struct Obj14225 *)q)->f10] = angle;
        if (func_021E1830((char *)p, angle << 12, ((struct Obj02497 *)p)->f30) == 1)
            ((struct Obj02497 *)p)->f1C |= 1 << ((struct Obj14225 *)q)->fC;
        }
    }
    buf.mask = ((struct Obj02497 *)p)->f1C;
    if (func_021DCBC4(((struct Obj02497 *)p)->fDC, 10252, &buf, 16) == 1) ((struct Obj02497 *)p)->f0 = 35;
    return 0;
}

int func_021DF370(u8 *p)
{
    int i;
    u8 *entry;
    u16 *values;
    if (((struct Obj04539 *)p)->f40 == 1) {
        values = (u16 *)(p + 108);
        ((struct Obj04539 *)p)->f11C = values[0] << 12;
        ((struct Obj04539 *)p)->f58 = values[0] << 12;
        for (i = 0; i < ((struct Obj04539 *)p)->f30; i++) {
            entry = p + 736 + i * 180;
            ((struct Obj10622 *)entry)->f1C = values[((struct Obj10622 *)entry)->f10 + 2] << 12;
            *(u16 *)(p + 96 + i * 2) = values[((struct Obj10622 *)entry)->f10 + 2];
        }
        ((struct Obj04539 *)p)->f1C = values[1];
        func_021E0570(p);
        func_021E07A4((char *)p);
        *(u8 * *)&((struct Obj04539 *)p)->f28 = func_021E0A44(p);
        ((struct Obj04539 *)p)->f0 = 35;
    }
    return 0;
}

int func_021DF3E8(u8 *p)
{
    int index, i, count, selected;
    index = (*(int **)(p + 40))[4];
    ((struct Obj06540 *)p)->f5C = 0;
    for (i = 0; i < ((struct Obj06540 *)p)->f30; i++) {
        selected = *(int *)(p + 748 + index * 180);
        func_021E0450(p, (void *)(*(int *)(p + 164 + selected * 4)), i, selected);
        count = ((struct Obj06540 *)p)->f30;
        index = (index + 1) % count;
    }
    ((struct Obj06540 *)p)->fC = 0;
    ((struct Obj06540 *)p)->f0 = 36;
    return 0;
}

int func_021DF434(u8 *p)
{
    int i;
    ((struct Obj06541 *)p)->fC += 1;
    if (((struct Obj06541 *)p)->fC < 120) return 0;
    ((struct Obj06541 *)p)->fC = 0;
    for (i = 0; i < ((struct Obj06541 *)p)->f30; i++) func_021E0478(p, i);
    func_021E01B0(p, 2, (void *)(*(int *)(p + 144 + 4 * (*(int **)(p + 40))[3])));
    func_021E1988(1302);
    ((struct Obj06541 *)p)->f0 = 37;
    return 0;
}

int func_021DF488(u8 *p) { if(((struct Obj08217 *)p)->fC<120) ((struct Obj08217 *)p)->fC+=1; else if(!func_021E19A4()) { ((struct Obj08217 *)p)->fC=0; ((struct Obj08217 *)p)->f0=38; } return 0; }

/*
 * lever: Mutable range table is reloaded after RNG; updating low in place preserves r4/r5 colouring.
 */
int func_021DF4AC(u8 *p)
{
    u32 low, high, value;
    int count;
    func_021E14E4((const char *)p);
    if ((((struct Obj05430 *)p)->f1C & (1 << (*(int **)(p + 40))[3])) == 0) {
        ((struct Obj05430 *)p)->f0 = 42;
        return 0;
    }
    count = ((struct Obj05430 *)p)->f30;
    low = d_021E1F34[count].low;
    high = d_021E1F34[count].high;
    low += func_020056EC(65535) % (high - low + 1);
    if (low < d_021E1F34[count].low) low = d_021E1F34[count].low;
    else if (low > high) low = high;
    func_021E026C(p, 3, low);
    value = func_02007E50(func_0201292C((((struct Obj23760 *)(*(u8 * *)&((struct Obj23759 *)(*(u8 * *)&((struct Obj05430 *)p)->fD8))->f14))->f4)), low, 1, 114);
    func_021E1988(1302);
    if (value == 1) ((struct Obj05430 *)p)->f0 = 39;
    else ((struct Obj05430 *)p)->f0 = 40;
    return 0;
}

int func_021DF548(u8 *p) { if(((struct Obj08218 *)p)->fC<180) ((struct Obj08218 *)p)->fC+=1; if(!func_021E19A4()) { ((struct Obj08218 *)p)->fC=0; ((struct Obj08218 *)p)->f0=42; } return 0; }

int func_021DF56C(u8 *p)
{
    if (((struct Obj08219 *)p)->fC < 180) {
        ((struct Obj08219 *)p)->fC += 1;
    } else if (func_021E19A4() == 0) {
        ((struct Obj08219 *)p)->fC = 0;
        ((struct Obj08219 *)p)->f0 = 41;
        func_021E0130(p, 4);
    }
    return 0;
}

int func_021DF598(u8 *p)
{
    if (((struct Obj08220 *)p)->fC < 180) {
        ((struct Obj08220 *)p)->fC += 1;
    } else {
        ((struct Obj08220 *)p)->fC = 0;
        ((struct Obj08220 *)p)->f0 = 42;
    }
    return 0;
}

/*
 * trailing: Two zero alignment bytes.
 */
int func_021DF5B0(u8 *p) { struct Link *link; link=(struct Link *)func_020399A8(); func_02008DF0(*(struct Sub02008C20Obj * *)&((struct Obj23762 *)(*(u8 * *)&((struct Obj23761 *)(*(u8 * *)&((struct Obj14226 *)p)->fD8))->f14))->f10,90); func_021E0130(p,11); func_02039C68(link,205,40); ((struct Obj14226 *)p)->f0=43; func_0203516C(8); return 0; }

int func_021DF5EC(u8 *p)
{
    if (func_02039CB4((struct Link *)func_020399A8(), 205, 40)) {
        func_021E1784((char *)p, (*(int **)(p + 40))[3]);
        ((struct Obj05431 *)p)->fDA0 = func_0201088C(114, (*(unsigned **)(*(u8 * *)&((struct Obj05431 *)p)->fD8 + 20))[1]);
        ((struct Obj05431 *)p)->fDA8 = func_0202EE30(((struct Obj05431 *)p)->fD98, ((struct Obj05431 *)p)->fCF0, 15, 16, 114);
        ((struct Obj05431 *)p)->f0 = 44;
    }
    return 0;
}

/*
 *   extern void func_020307B0(void *);
 *   void func_02010934(void *p) { func_020307B0(p); }
 * tail: 021DF6A2..021DF6A4 is two zero alignment bytes.
 */
int func_021DF648(u8 *p)
{
    int ready;
    ready = func_02010904(*(void **)(p + 3488));
    if (func_0200FB24()) {
        func_0200FBB0();
        func_0200F7B8(1);
        func_0202223C(0, 0);
        func_0202223C(1, 0);
        return 0;
    }
    if (ready) {
        func_0202F038(*(void **)(p + 3496));
        *(void **)(p + 3496) = 0;
        func_02010934(*(void **)(p + 3488));
        *(int *)p = 47;
    }
    return 0;
}

int func_021DF6A4(u8 *p){func_021E0130(p,12);((struct Obj23763 *)p)->f0=46;return 0;}

/*
 * follower: unlabelled timer inside handed 021DF6A4 extent, followed by 2-byte zero padding.
 */
int func_021DF6B8(char *p){if(++((struct Obj10623 *)p)->fC>=180){((struct Obj10623 *)p)->fC=0;((struct Obj10623 *)p)->f0=47;return 1;}return 0;}

int func_021DF6D4(u8 *p){void *ctx=func_020399A8();if(!((struct Obj14227 *)p)->f18)func_02039C68(ctx,206,40);func_021E0130(p,10);((struct Obj14227 *)p)->f0=48;return 0;}

int func_021DF6FC(u8 *p)
{
    void *ctx;
    ctx = func_020399A8();
    if (((struct Obj03305 *)p)->f18 == 0) {
        if (func_02039CB4(ctx, 206, 40)) {
            ((struct Obj03305 *)p)->fDA8 = func_0202EE30(((struct Obj03305 *)p)->fD98, ((struct Obj03305 *)p)->fCF0, 15, 16, 114);
            func_0203D7BC(0);
            func_0203A5E4(10240);
            func_02184174(func_021DEB10((char *)p));
            ((struct Obj03305 *)p)->f0 = 49;
        }
    } else {
        ((struct Obj03305 *)p)->fC += 1;
        if (((struct Obj03305 *)p)->fC >= 180) {
            ((struct Obj03305 *)p)->fC = 0;
            if ((*(int **)(p + 220))[15] == 0) func_0203D7B0(0);
            ((struct Obj03305 *)p)->f0 = 49;
        }
    }
    return 0;
}

int func_021DF778(char *p){if(func_0218417C(func_021DEB10(p))){func_0202F038(((struct Obj10624 *)p)->fDA8);((struct Obj10624 *)p)->fDA8=0;((struct Obj10624 *)p)->f0=50;return 1;}return 0;}

int func_021DF7A4(int *p){func_0202208C((void *)2,0,0,0,8,1,114);*p=51;return 0;}

int func_021DF7CC(int *p){if(func_020221A4()){*p=52;return 1;}return 0;}

int func_021DF7E4(void){return 2;}

void func_021DF7E8(void *arg,char *p){func_02021D50(*(struct S02021D50 * *)&((struct Obj23766 *)p)->fD78);func_0204A648();func_020419E4();}
