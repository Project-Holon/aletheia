/*
 * file:     unit_021D4240_p05.c
 * unit:     yes
 * function: func_021D50DC, func_021D5110, func_021D5278, func_021D5310, func_021D533C, func_021D5368, func_021D5370, func_021D5514
 * address:  0x021D50DC
 * region:   ov122
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203D798 0x0203D798 arm
 *   func_02082D44 0x02082D44 arm
 *   func_0203CF10 0x0203CF10 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045994 0x02045994 arm
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02045808 0x02045808 arm
 *   func_0204B898 0x0204B898 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_021D50B4 0x021D50B4 thumb ov122
 *   func_0203EFC8 0x0203EFC8 arm
 *   func_0204A648 0x0204A648 arm
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204363C 0x0204363C arm
 *   func_0207D46C 0x0207D46C arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_020433E0 0x020433E0 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_02043534 0x02043534 arm
 *   func_020435F4 0x020435F4 arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_021D424C 0x021D424C thumb ov122
 *   func_021D48D8 0x021D48D8 thumb ov122
 *   func_0203101C 0x0203101C arm
 *   func_0207D63C 0x0207D63C arm
 *   func_021D4A64 0x021D4A64 thumb ov122
 *   func_021D4244 0x021D4244 thumb ov122
 *   func_0203D34C 0x0203D34C arm
 *   func_0203CD98 0x0203CD98 arm
 *   func_02178118 0x02178118 thumb ov014
 *   func_020355D8 0x020355D8 arm
 *   data_021D58B0 0x021D58B0 data a4
 *   data_021D5770 0x021D5770 data a4
 *   data_021D5740 0x021D5740 data a4
 *   func_02027974 0x02027974 thumb
 *   func_0204A600 0x0204A600 arm
 *   func_0201283C 0x0201283C thumb
 *   func_0201058C 0x0201058C thumb
 *   func_020310C4 0x020310C4 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_02040618 0x02040618 arm
 *   func_020221A4 0x020221A4 thumb
 *   func_020121CC 0x020121CC thumb
 *   func_02012204 0x02012204 thumb
 *   func_0202223C 0x0202223C thumb
 */
#include "../../matched/include/Obj13966.h"
#include "../../matched/include/Obj22933.h"
#include "../../matched/include/Obj00208.h"
#include "../../matched/include/Obj00073.h"
#include "../../matched/include/Obj13967.h"
#include "../../matched/include/Obj22934.h"
#include "../../matched/include/Obj22935.h"

struct BigObj;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct Obj;
struct SoundSys;
struct Strbuf;
struct U16Vec;
struct Obj0203159C;
struct DispConfig;
struct DispVram;
struct Bank;
struct R;
struct Tcbl;
struct WordSet;
struct Ctx;
struct IcaAnime;
struct PrintSys;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

typedef struct { char f00[8]; u16 f08, f0a; } Entry;

typedef struct { char pad00[0x64]; Entry f64[16]; } Object;

typedef signed int     s32;

typedef struct { u32 v[4]; } Display;

extern void *func_0203D798(void);
extern void func_02082D44(const void *,void *,u32);
extern u32 func_0201283C(const struct BigObj *p);
extern int func_020107FC(void *);
extern u32 func_0203CF10(u32 a);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u16 *func_0202E930(void *);
extern void func_02045994(struct Strbuf *o, const u16 *src, u32 len);
extern u32 func_0204B3F4(struct Obj *p);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201C7D0(void *, s16, s16, void *, void *, u16);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_02041B6C(u32 bit);
extern void func_021D50B4(char *p, u32 n);
extern void func_02045808(struct U16Vec *vec);
extern unsigned int func_02012A30(const struct BigObj *);
extern void func_02028A64(struct SoundSys *sys);
extern void func_02028A70(struct SoundSys *sys);
extern u16 func_0204B898(struct Obj *p);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B92C(struct Obj *p, u32 v);
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern void func_0204A648(void);
extern void func_0203064C(u32, u32, u32);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *, int, u32);
extern void func_0204363C(u32);
extern void func_0207D46C(void);
extern void func_0203F8F4(u16);
extern void func_02045088(u16);
extern void func_0201DD60(void);
extern void func_020433E0(const struct DispVram *c);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_02043534(u32);
extern void func_020435F4(u32);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void *func_020056A0(u32, void *, u32);
extern void func_021D424C(void *);
extern void func_021D48D8(char *);
extern struct WordSet *func_0201EC74(u32 n, u32 size, u16 heap);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 func_0201C440(void *p);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void func_0207D63C(void *, u32, u32, u32, u32);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void func_021D4A64(char *);
extern void func_021D4244(void *p, u32 a, int a2);
extern void func_0203D34C(u32, u32);
extern int func_0203CD98(void);
extern void func_02178118(u32, u32);
extern void func_020355D8(u8);
extern void func_02027974(void *);
extern void func_0204A600(void);
extern u32 func_0201058C(void *);
extern void func_020310C4(struct Tcbl *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_02040618(u32, u32, u32);
extern u32 func_020221A4(void);
extern u32 func_020121CC(struct IcaAnime *p);
extern u32 func_02012204(const struct Ctx *p);
extern void func_0202223C(u32, u32);
void func_021D50DC(char *p);
void func_021D5110(char *p);
void func_021D5278(Object *p, const char *data, int value, int tag);
void func_021D5310(u8 *p);
u32 func_021D533C(u8 *p);
void func_021D5368(void);
int func_021D5370(void *owner, void *unused, char *args);
int func_021D5514(void *a, void *b, void *c, char *p);
extern u32 data_021D58B0[], data_021D5740[];
extern const Display data_021D5770;

void func_021D50DC(char *p) {u8 buf[6]={0};func_0203D798();((struct Obj22933 *)(*(char * *)&((struct Obj13966 *)p)->f344))->f10=1;func_02082D44(buf,*(char * *)&((struct Obj13966 *)p)->f344+20,6);}

void func_021D5110(char *p)
{
    int index;
    void *record, *text;
    index = func_020107FC((void *)func_0201283C(((struct Obj00208 *)p)->f350));
    if (index != -1) {
        record = (void *)func_0203CF10(index);
        text = func_020457B0(200, ((struct Obj00208 *)p)->fC);
        func_02045994(text, func_0202E930(record), 8);
        if (!func_0204B3F4(((struct Obj00208 *)p)->f3A0)) {
            func_02045994(((struct Obj00208 *)p)->f58, func_0202E930(record), 8);
            func_02043B5C(func_02045770(((struct Obj00208 *)p)->f3C), 0);
            func_0201C7D0(func_02045770(((struct Obj00208 *)p)->f3C), 0, 0, ((struct Obj00208 *)p)->f58, ((struct Obj00208 *)p)->f4C, 0x39e3);
            func_02045334(((struct Obj00208 *)p)->f3C);
            func_02045374(((struct Obj00208 *)p)->f3C);
            func_0204B3DC(((struct Obj00208 *)p)->f3A0, 1);
            func_02041B6C(5);
            func_021D50B4(p, index);
        }
        func_02045808(text);
        func_02028A64((struct SoundSys *)func_02012A30(((struct Obj00208 *)p)->f350));
        if (func_0204B898(((struct Obj00208 *)p)->f39C) == 15)
            func_0204B878(((struct Obj00208 *)p)->f39C, 16);
        if (func_0204B898(((struct Obj00208 *)p)->f394) == 11) {
            func_0204B92C(((struct Obj00208 *)p)->f394, 1);
            func_0204B878(((struct Obj00208 *)p)->f394, 19);
        }
    } else {
        func_02028A70((struct SoundSys *)func_02012A30(((struct Obj00208 *)p)->f350));
        func_0204B3DC(((struct Obj00208 *)p)->f3A0, 0);
        func_02043B5C(func_02045770(((struct Obj00208 *)p)->f3C), 0);
        func_02045334(((struct Obj00208 *)p)->f3C);
        func_021D50DC(p);
        if (func_0204B898(((struct Obj00208 *)p)->f394) == 19) {
            func_0204B92C(((struct Obj00208 *)p)->f394, 0);
            func_0204B878(((struct Obj00208 *)p)->f394, 11);
        }
        if (func_0204B898(((struct Obj00208 *)p)->f39C) == 16)
            func_0204B878(((struct Obj00208 *)p)->f39C, 15);
    }
}

/*
 * extent: zero padding at 0x021D530E; next function at 0x021D5310.
 */
void func_021D5278(Object *p, const char *data, int value, int tag)
{
    int i;
    if (value >= 20 && value <= 27) {
        for (i = 0; i < 16; i++) {
            if (p->f64[i].f08 && !func_0203EFC8((const u8 *)p->f64[i].f00, (const u8 *)(data + 4), 6)) {
                p->f64[i].f08 = 600;
                p->f64[i].f0a = tag;
                return;
            }
        }
        for (i = 0; i < 16; i++) {
            if (!p->f64[i].f08) {
                func_02082D44(data + 4, p->f64[i].f00, 6);
                p->f64[i].f08 = 600;
                p->f64[i].f0a = tag;
                return;
            }
        }
    }
}

void func_021D5310(u8 *p) { int i; for(i=0;i<16;i++) if(*(u16 *)(p+i*12+108)) --*(u16 *)(p+i*12+108); }

u32 func_021D533C(u8 *p) { int i; int sum; sum=0; for(i=0;i<16;i++) if(*(u16 *)(p+i*12+108)) sum+=*(u16 *)(p+i*12+110); return sum; }

/*
 * leaf: root-claimed sole callback witness for func_021D5370.
 */
void func_021D5368(void)
{
    func_0204A648();
}

/*
 * volatile: 021D53BA reads hardware DISPCNT, 021D53C0 writes the update.
 * ABI: 0203159C leaves the allocator result in r0 (020315BC/15C0); caller uses it.
 */
int func_021D5370(void *owner, void *unused, char *args)
{
    char *p;
    Display display;
    func_0203064C(1, 31, 0x18000);
    p = func_0203159C(owner, 0x3a8, 31);
    func_02082BCC(p, 0, 0x3a8);
    ((struct Obj00073 *)p)->fC = 31;
    ((struct Obj00073 *)p)->f350 = ((struct Obj13967 *)args)->f4;
    ((struct Obj00073 *)p)->f354 = ((struct Obj13967 *)args)->f0;
    func_0204363C(1);
    *(volatile u32 *)0x04001000 |= 0x10000;
    func_0207D46C();
    func_0203F8F4(((struct Obj00073 *)p)->fC);
    func_02045088(((struct Obj00073 *)p)->fC);
    func_0201DD60();
    func_020433E0((const struct DispVram *)data_021D58B0);
    display = data_021D5770;
    func_0203FC28((struct DispConfig *)(&display));
    func_02043534(0);
    func_020435F4(0);
    func_0204A48C((const struct Cfg *)data_021D5740, (u32)data_021D58B0, ((struct Obj00073 *)p)->fC);
    ((struct Obj00073 *)p)->f30C = func_0204B100(40, 0, ((struct Obj00073 *)p)->fC);
    ((struct Obj00073 *)p)->f310 = func_020056A0((u32)func_021D5368, p, 0);
    func_021D424C(p);
    func_021D48D8(p);
    ((struct Obj00073 *)p)->f48 = func_0201EC74(11, 200, ((struct Obj00073 *)p)->fC);
    ((struct Obj00073 *)p)->f31C = func_0203101C(((struct Obj00073 *)p)->fC, ((struct Obj00073 *)p)->fC, 1, 0);
    ((struct Obj00073 *)p)->f320 = func_0201C440((void *)(((struct Obj00073 *)p)->fC));
    ((struct Obj00073 *)p)->f340 = func_02027F60(5, 13, *(u32 *)&((struct Obj00073 *)p)->f4C, ((struct Obj00073 *)p)->f320, ((struct Obj00073 *)p)->fC);
    func_0207D63C((void *)0x04001050, 4, 1, 15, 4);
    func_0202208C((void *)4, 1, 1, 0, 6, 1, ((struct Obj00073 *)p)->fC);
    func_020435F4(31);
    func_021D4244(p, (u32)func_021D4A64, 0x6cb);
    *(char * *)&((struct Obj00073 *)p)->f344 = args;
    func_0203D798();
    ((struct Obj22934 *)(*(char * *)&((struct Obj00073 *)p)->f344))->f10 = 1;
    ((struct Obj22935 *)(*(char * *)&((struct Obj00073 *)p)->f344))->fC = ((struct Obj00073 *)p)->f350;
    func_0203D34C(0, ((struct Obj00073 *)p)->fC);
    if (func_0203CD98()) func_02178118((u32)func_021D5278, (u32)p);
    func_020355D8(1);
    return 1;
}

/*
 * extent: two-byte zero alignment at 021D55FA, then next labelled function.
 */
int func_021D5514(void *a, void *b, void *c, char *p)
{
    int result = 1;
    if (*(void (**)(char *))p) {
        (*(void (**)(char *))p)(p);
        result = 0;
    }
    if (((struct Obj00208 *)p)->f324) func_02027974(((struct Obj00208 *)p)->f324);
    if (((struct Obj00208 *)p)->f8 != 1) func_021D5110(p);
    func_021D5310((unsigned char *)p);
    func_0204A600();
    if (func_0203CD98()) {
        ((struct Obj00208 *)p)->f368 = ((struct Obj00208 *)p)->f364;
        ((struct Obj00208 *)p)->f364 = func_0201058C((void *)func_0201283C(((struct Obj00208 *)p)->f350));
        ((struct Obj00208 *)p)->f370 = ((struct Obj00208 *)p)->f36C;
        ((struct Obj00208 *)p)->f36C = func_021D533C((u8 *)p);
    }
    func_020310C4(((struct Obj00208 *)p)->f31C);
    func_0201C4E4(((struct Obj00208 *)p)->f320);
    func_02040618(4, 3, ((struct Obj00208 *)p)->f358);
    ((struct Obj00208 *)p)->f358 = ((struct Obj00208 *)p)->f358 - 1;
    if (func_020221A4() && ((struct Obj00208 *)p)->f38C == 0) func_020121CC(((struct Obj00208 *)p)->f354);
    if (func_020221A4() && func_02012204(((struct Obj00208 *)p)->f354)) {
        ((struct Obj00208 *)p)->f8 = 2;
        result = 1;
        func_0202223C(0, 0);
        func_0202223C(1, 0);
    }
    return result;
}
