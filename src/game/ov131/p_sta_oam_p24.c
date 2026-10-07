/*
 * file:     p_sta_oam_p24.c
 * unit:     yes
 * function: func_021D8F0C, func_021D8F50, func_021D8FAC, func_021D909C, func_021D90C0, func_021D911C, func_021D91EC, func_021D91F0, func_021D92B0, func_021D93E4
 * address:  0x021D8F0C
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D9428 0x021D9428 thumb ov131
 *   func_020410D0 0x020410D0 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02040AE0 0x02040AE0 arm
 *   func_0204B878 0x0204B878 arm
 *   func_021D9440 0x021D9440 thumb ov131
 *   func_021DBE2C 0x021DBE2C thumb ov131
 *   func_021DBCA4 0x021DBCA4 thumb ov131
 *   func_021DBCF4 0x021DBCF4 thumb ov131
 *   func_020452E8 0x020452E8 arm
 *   func_02041300 0x02041300 arm
 *   func_020409B4 0x020409B4 arm
 *   d_021DC2B0 0x021DC2B0 data a1
 *   func_021D6064 0x021D6064 thumb ov131
 *   func_021DBF2C 0x021DBF2C thumb ov131
 *   func_02017E88 0x02017E88 thumb
 *   func_020437D4 0x020437D4 arm
 *   func_02082D44 0x02082D44 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201DD78 0x0201DD78 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_0201DD68 0x0201DD68 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_0200616C 0x0200616C thumb
 *   _u32_div_f 0x0209C2B0 arm
 */
#include "../../matched/include/Obj05393.h"
#include "../../matched/include/Obj02845.h"
#include "../../matched/include/Obj01548.h"
#include "../../matched/include/Obj23149.h"
#include "../../matched/include/Obj23150.h"
#include "../../matched/include/Obj04510.h"
#include "../../matched/include/Obj23151.h"
#include "../../matched/include/Obj23152.h"
#include "../../matched/include/Obj06484.h"
#include "../../matched/include/Obj10516.h"
#include "../../matched/include/Obj10517.h"
#include "../../matched/include/Obj10518.h"
#include "../../matched/include/Obj23153.h"
#include "../../matched/include/Obj00091.h"
#include "../../matched/include/Obj03816.h"
#include "../../matched/include/Obj08147.h"
#include "../../matched/include/Obj23154.h"

struct Obj;
struct Descriptor;
struct Bmp;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct PrintSys;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

struct Entry { u16 id; u8 gap[14]; u8 *object; };

struct List { u8 gap[0x70]; struct Entry entries[10]; };

struct Counts { u8 value[5]; };

typedef signed char s8;

extern unsigned int func_021D9428(unsigned char *p, unsigned int target);
extern void func_020410D0(u32,u32,u32,u32,u8,u32,u8,u8,u8,u8);
extern void func_02041B6C(u32);
extern void func_02040AE0(u32 index, const void *src, u32 mode);
extern void func_0204B878(struct Obj *p, u16 value);
extern s16 func_021D9440(u8 *,u32);
extern void func_021DBE2C(u8 *,s16,s16);
extern void func_021DBCA4(u8 *,int);
extern void func_021DBCF4(u8 *p);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_02041300(unsigned int,int,int,int,unsigned char,unsigned char,unsigned char);
extern void func_020409B4(unsigned int);
extern void *func_021D6064(u8 *);
extern u32 func_021DBF2C(u32,u32);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern void *func_020437D4(const struct Bmp *bmp);
extern void func_02082D44(const void *,void *,u32);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201DD78(u32,u32,u32);
extern void func_0201C7A4(void *,s16,s16,void *,void *);
extern void func_0201DD68(void);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_0200616C(void *,int);
void func_021D8F0C(void *unused, unsigned char *p, int delta);
void func_021D8F50(void *a, unsigned char *p);
void func_021D8FAC(u8 *a,u8 *p);
void func_021D909C(u8 *a,u8 *p);
void func_021D90C0(unsigned char *a, unsigned char *p);
void func_021D911C(u8 *a,u8 *p);
void func_021D91EC(void *a0, void *a1);
void func_021D91F0(u8 *a,u8 *p,u8 *entry);
void func_021D92B0(u8 *a,u8 *p);
u32 func_021D93E4(u8 *p, u32 target);
extern const struct Counts d_021DC2B0;


void func_021D8F0C(void *unused, unsigned char *p, int delta)
{
    int max = (p[0x10] - 6) * 24;
    unsigned int old;
    if (max < 0) max = 0;
    if (delta > 24) delta = 24;
    if (delta < -24) delta = -24;
    old = ((struct Obj05393 *)p)->f14;
    if ((short)old + delta < 0) ((struct Obj05393 *)p)->f14 = 0;
    else if (old + delta > (unsigned int)max) ((struct Obj05393 *)p)->f14 = max;
    else ((struct Obj05393 *)p)->f14 = old + delta;
    if (delta != 0) ((struct Obj05393 *)p)->fC = 1;
}

void func_021D8F50(void *a, unsigned char *p)
{
    unsigned char i;
    p[0x58]=255;
    p[0x59]=255;
    p[0x5a]=255;
    ((struct Obj02845 *)p)->f14=0;
    ((struct Obj02845 *)p)->f0=1;
    ((struct Obj02845 *)p)->f4=0;
    ((struct Obj02845 *)p)->f8=0;
    ((struct Obj02845 *)p)->fC=1;
    ((struct Obj02845 *)p)->f20=0;
    ((struct Obj02845 *)p)->f24=0;
    for(i=0;i<10;i++) {
        *(unsigned short *)(p+i*20+0x70)=func_021D9428(p,i);
        func_021D91F0(a,p,p+0x70+i*20);
    }
}

/*
 * lever: The image's 20-byte records are subscripted per field, avoiding
 *   the pointer-arithmetic spelling's cached object-field base and spill.
 * proof: i is initialized u8 and bounded by 10; i*20 fits int.
 *   Loaded address payloads use u32 +12 for full-word modulo arithmetic.
 */
void func_021D8FAC(u8 *a,u8 *p)
{
    u8 i;
    u16 value;
    func_020410D0(2,0,0,32,24,((struct Obj01548 *)p)->f28+12,0,0,32,32);
    func_02041B6C(2);
    func_02040AE0(6,*(u8 * *)&((struct Obj01548 *)p)->f30+12,((struct Obj23150 *)(*(u8 * *)&((struct Obj01548 *)p)->f30))->f8);
    func_02041B6C(6);
    func_020410D0(5,0,0,32,3,((struct Obj01548 *)p)->f40+12,0,0,32,32);
    func_02041B6C(5);
    for(i=0;i<10;i++) {
        value=((struct List *)p)->entries[i].id;
        func_021DBE2C(((struct List *)p)->entries[i].object,8,func_021D9440(p,i));
        if(value!=0xffff) {
            func_021DBCA4(((struct List *)p)->entries[i].object,1);
            func_021DBCF4(((struct List *)p)->entries[i].object);
        } else func_021DBCA4(((struct List *)p)->entries[i].object,0);
    }
    ((struct Obj01548 *)p)->f14=0;
    p[0x58]=255;
    p[0x59]=255;
    p[0x5a]=255;
    ((struct Obj01548 *)p)->f0=1;
    ((struct Obj01548 *)p)->fC=1;
    func_0204B878(((struct Obj23149 *)a)->f180,5);
}

void func_021D909C(u8 *a,u8 *p)
{
    ((struct Obj04510 *)p)->f0=0;
    if(((struct Obj04510 *)p)->f20!=0) {
        func_020452E8(((struct Obj04510 *)p)->f20);
        ((struct Obj04510 *)p)->f20=0;
    }
    if(((struct Obj04510 *)p)->f24!=0) {
        func_020452E8(((struct Obj04510 *)p)->f24);
        ((struct Obj04510 *)p)->f24=0;
    }
}

void func_021D90C0(unsigned char *a, unsigned char *p)
{
    unsigned char i;
    for(i=0;i<10;i++) func_021DBCA4(*(void **)(p+0x80+i*20),0);
    func_02041300(1,0,0,0,19,21,16);
    func_020409B4(1);
    ((struct Obj23152 *)p)->f0=0;
    func_0204B878(((struct Obj23151 *)a)->f180,2);
}

/*
 * lever: Initialize the count after the clear loop so its zero shares the
 *   clear-store value without a redundant live zero register.
 * proof: Loop indices are initialized u8 values bounded by 80 or 10.
 *   func_021DBF2C field 5 reads byte +12 of immutable d_021DC2F8;
 *   all 80 original records have selector 0..4 (B8/table-proof.log).
 *   count begins with five ROM bytes 1,1,1,1,1 and never exceeds 81.
 *   All scaling and count increments fit int; stores preserve u8 narrowing.
 * interface: func_021D9428 forwards live r1 to func_021D93E4, whose
 *   own matched body consumes target; caller sets r1 despite stale one-arg
 *   declaration in func_021D9428's source.
 */
void func_021D911C(u8 *a,u8 *p)
{
    struct Counts counts = d_021DC2B0;
    void *object;
    u8 i, n, selector;
    object=func_021D6064(a);
    for(i=0;i<80;i++) *(u32 *)(p+0x138+i*8)=0;
    n=0;
    for(i=0;i<80;i++) {
        if(func_02017E88(object,func_021DBF2C(i,0),0)==1) {
            selector=func_021DBF2C(i,5);
            *(u32 *)(p+0x138+n*8)=1;
            p[0x13c+n*8]=i;
            p[0x13d+n*8]=selector;
            p[0x13e + n*8]=counts.value[selector];
            counts.value[selector]++;
            n++;
        }
    }
    p[0x10]=n;
    for(i=0;i<10;i++) *(u16 *)(p+0x70+i*20)=func_021D9428(p,i);
}

void func_021D91EC(void *a0, void *a1)
{
}

void func_021D91F0(u8 *a,u8 *p,u8 *entry)
{
    u8 *record;
    u8 *pixels;
    void *text;
    void *buffer;
    void *object;
    void *source;
    record=p+0x138+((struct Obj06484 *)entry)->f0*8;
    if (((struct Obj10518 *)record)->f0!=1) return;
    pixels=*(u8 * *)&((struct Obj23153 *)(*(u8 * *)&((struct Obj10517 *)p)->f48))->f14;
    source=func_020437D4(((struct Obj06484 *)entry)->fC);
    if (((struct Obj06484 *)entry)->f0==p[0x59]) pixels+=0x660;
    func_02082D44(pixels,source,0x660);
    text=func_02045EC0(((struct Obj10517 *)p)->f50,record[5]+160);
    buffer=func_020457B0(32,((struct Obj10516 *)a)->f0);
    object=func_0201EC64(((struct Obj10516 *)a)->f0);
    func_0201EFA4(object,0,record[6],2,2,1);
    func_0201F250(object,buffer,text);
    func_0201DD78(1,2,0);
    func_0201C7A4(((struct Obj06484 *)entry)->fC,10,6,buffer,((struct Obj10516 *)a)->f80);
    func_0201DD68();
    func_02045808(text);
    func_02045808(buffer);
    func_0201ED04(object);
    func_021DBCF4(((struct Obj06484 *)entry)->f10);
}

/*
 * proof: loop i starts at zero and tests i<10 after each byte increment;
 * i*20 <=180. Each other byte index is guarded <10 before *20.
 * prototype: 021D92EA loads r1 for 021D9428 despite its legacy one-input
 * source. Preserve this observed full-word argument in the caller extern.
 */
void func_021D92B0(u8 *a,u8 *p)
{
    int changed;
    u8 *entries;
    u8 i;
    u32 value;
    u8 *entry;
    s16 y;
    changed=0;
    entries=p;
    entries+=0x70;
    for(i=0;i<10;i++) {
        if(((struct Obj00091 *)p)->fC==1) {
            y=func_021D9440(p,i);
            func_021DBE2C(*(u8 **)((p+i*20)+0x80),8,y);
            value=func_021D9428(p,i);
            if(value==65535) {
                *(u16 *)((p+i*20)+0x70)=value;
                func_021DBCA4(*(u8 **)((p+i*20)+0x80),0);
            } else if(value!=*(u16 *)((p+i*20)+0x70)) {
                changed=1;
                *(u16 *)((p+i*20)+0x70)=value;
                func_021D91F0(a,p,entries+i*20);
                func_021DBCA4(*(u8 **)((p+i*20)+0x80),1);
            }
        }
        entry=p+i*20;
        if(((struct Obj08147 *)entry)->f78==1 && func_0201C6C4(((struct Obj03816 *)a)->f84,((struct Obj08147 *)entry)->f7C)==0) {
            ((struct Obj08147 *)entry)->f78=0;
            func_021DBCF4(((struct Obj08147 *)entry)->f80);
        }
    }
    if(changed==1 && p[0x60]==0) {
        func_0200616C((void *)1605,1);
        p[0x60]=3;
    }
    if(((struct Obj00091 *)p)->f68==1) {
        if(p[0x58]<10) func_021D91F0(a,p,(p+0x70)+p[0x58]*20);
        if(p[0x5a]<10) func_021D91F0(a,p,(p+0x70)+p[0x5a]*20);
        p[0x5a]=p[0x58];
        ((struct Obj00091 *)p)->f68=0;
    }
    ((struct Obj00091 *)p)->fC=0;
}

u32 func_021D93E4(u8 *p, u32 target)
{
    u8 row;
    s8 delta;
    row = ((struct Obj23154 *)p)->f14 / 24u;
    delta = target - (u8)(row % 10);
    if (delta < -2) delta += 10;
    if (delta > 8) delta -= 10;
    return (u8)(row + delta);
}
