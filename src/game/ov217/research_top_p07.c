/*
 * file:     research_top_p07.c
 * unit:     yes
 * function: func_021BAB50, func_021BAB58, func_021BAB68, func_021BAB70, func_021BAB80, func_021BABB4, func_021BABC4, func_021BAC90, func_021BAC98, func_021BACA0, func_021BAE00, func_021BAF70, func_021BB190, func_021BB200
 * address:  0x021BAB50
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204A648  0x0204A648  arm
 *   func_02005654  0x02005654  thumb
 *   func_021BC634  0x021BC634  thumb  ov217
 *   func_021BC638  0x021BC638  thumb  ov217
 *   func_021BC640  0x021BC640  thumb  ov217
 *   func_021BC758  0x021BC758  thumb  ov217
 *   func_021BC774  0x021BC774  thumb  ov217
 *   func_021C09AC  0x021C09AC  thumb  ov217
 *   func_021BC818  0x021BC818  thumb  ov217
 *   func_021BC954  0x021BC954  thumb  ov217
 *   func_021BB974  0x021BB974  thumb  ov217
 *   func_021BB710  0x021BB710  thumb  ov217
 *   func_021BB69C  0x021BB69C  thumb  ov217
 *   func_021BB484  0x021BB484  thumb  ov217
 *   func_021BB2B4  0x021BB2B4  thumb  ov217
 *   func_021BB534  0x021BB534  thumb  ov217
 *   func_021BB37C  0x021BB37C  thumb  ov217
 *   func_021BB784  0x021BB784  thumb  ov217
 *   func_021BB5F4  0x021BB5F4  thumb  ov217
 *   func_021BB84C  0x021BB84C  thumb  ov217
 *   func_021BC5F0  0x021BC5F0  thumb  ov217
 *   func_021BC5D4  0x021BC5D4  thumb  ov217
 *   func_021BB908  0x021BB908  thumb  ov217
 *   func_021BB94C  0x021BB94C  thumb  ov217
 *   func_021BC93C 0x021BC93C thumb ov217
 *   func_021BC8B4 0x021BC8B4 thumb ov217
 *   func_021BC8E4 0x021BC8E4 thumb ov217
 *   func_021BC960 0x021BC960 thumb ov217
 *   func_021BC43C 0x021BC43C thumb ov217
 *   func_021BC820 0x021BC820 thumb ov217
 *   func_021BC9FC 0x021BC9FC thumb ov217
 *   func_021BCAE8 0x021BCAE8 thumb ov217
 *   func_021BCB48 0x021BCB48 thumb ov217
 *   func_021BCB70 0x021BCB70 thumb ov217
 *   func_021BCBD0 0x021BCBD0 thumb ov217
 *   func_021BCC40 0x021BCC40 thumb ov217
 *   func_021BCC68 0x021BCC68 thumb ov217
 *   func_021BCDF0 0x021BCDF0 thumb ov217
 *   func_021BCE7C 0x021BCE7C thumb ov217
 *   func_021BCF68 0x021BCF68 thumb ov217
 *   func_021BCFD0 0x021BCFD0 thumb ov217
 *   func_021BD094 0x021BD094 thumb ov217
 *   func_021BD0C4 0x021BD0C4 thumb ov217
 *   func_021BD178 0x021BD178 thumb ov217
 *   func_021BD274 0x021BD274 thumb ov217
 *   func_021BD38C 0x021BD38C thumb ov217
 *   func_021BD3B4 0x021BD3B4 thumb ov217
 *   func_021BD47C 0x021BD47C thumb ov217
 *   func_021BD4F0 0x021BD4F0 thumb ov217
 *   func_021BD53C 0x021BD53C thumb ov217
 *   func_021BD5C4 0x021BD5C4 thumb ov217
 *   func_021BD5B4 0x021BD5B4 thumb ov217
 *   func_021BD588 0x021BD588 thumb ov217
 *   func_021BC580 0x021BC580 thumb ov217
 *   func_021BC72C 0x021BC72C thumb ov217
 *   func_021BC644 0x021BC644 thumb ov217
 *   func_021BBC50 0x021BBC50 thumb ov217
 *   func_021BBDF0 0x021BBDF0 thumb ov217
 *   func_021BC6EC 0x021BC6EC thumb ov217
 *   func_021BC014 0x021BC014 thumb ov217
 *   func_021BC168 0x021BC168 thumb ov217
 *   func_021BBF60 0x021BBF60 thumb ov217
 *   func_021BC06C 0x021BC06C thumb ov217
 *   func_021BB928 0x021BB928 thumb ov217
 *   func_021BBD68 0x021BBD68 thumb ov217
 *   func_021BC128 0x021BC128 thumb ov217
 *   func_021BB91C 0x021BB91C thumb ov217
 *   func_021BB910 0x021BB910 thumb ov217
 *   func_021BBDAC 0x021BBDAC thumb ov217
 *   func_021BC0E8 0x021BC0E8 thumb ov217
 *   func_021BC480 0x021BC480 thumb ov217
 *   func_021C09B8 0x021C09B8 thumb ov217
 *   func_021BC6D0 0x021BC6D0 thumb ov217
 *   func_021BBAD0 0x021BBAD0 thumb ov217
 *   func_021BB934 0x021BB934 thumb ov217
 *   func_021BC6F4 0x021BC6F4 thumb ov217
 *   func_021BBAA4 0x021BBAA4 thumb ov217
 *   func_021BC428 0x021BC428 thumb ov217
 *   func_020362DC 0x020362DC arm
 *   func_02035C08 0x02035C08 arm
 *   func_02035CB8 0x02035CB8 arm
 *   func_02035BA4 0x02035BA4 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021BC600 0x021BC600 thumb ov217
 *   func_021BC608 0x021BC608 thumb ov217
 *   func_021BC5FC 0x021BC5FC thumb ov217
 *   func_021BBD40 0x021BBD40 thumb ov217
 *   func_021BC6DC 0x021BC6DC thumb ov217
 *   func_0203630C 0x0203630C arm
 *   func_021BB98C 0x021BB98C thumb ov217
 *   func_021BBADC 0x021BBADC thumb ov217
 *   func_021BB990 0x021BB990 thumb ov217
 *   func_021BC2D8 0x021BC2D8 thumb ov217
 *   func_021BC338 0x021BC338 thumb ov217
 *   func_021BC2FC 0x021BC2FC thumb ov217
 *   func_021BC280 0x021BC280 thumb ov217
 *   func_021BC2B8 0x021BC2B8 thumb ov217
 *   func_021BC200 0x021BC200 thumb ov217
 *   func_021BC30C 0x021BC30C thumb ov217
 *   func_021BC380 0x021BC380 thumb ov217
 *   func_021BC274 0x021BC274 thumb ov217
 *   func_021BC250 0x021BC250 thumb ov217
 *   func_021BC264 0x021BC264 thumb ov217
 *   func_021BBA30 0x021BBA30 thumb ov217
 */
#include "../../matched/include/Obj25840.h"
#include "../../matched/include/Obj25841.h"
#include "../../matched/include/Obj25842.h"
#include "../../matched/include/Obj00025.h"

struct S;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

struct S { char pad0[0x34]; int f34; char pad38[0x14]; int f4c; };

extern void func_0204A648(void);
extern int func_02005654(int a, int b);
extern void func_0200566C(void);
extern void func_0203D34C(u32 a, u32 b);
extern u32 func_021BC634();
extern void func_021BC638(void *p, u32 v);
extern void func_021BC640(void *p, u32 v);
extern u32 func_021BC758(u32 a0);
extern void func_021BC774(u8 *p);
extern u32 func_021C09AC(void *p);
extern u32 func_021BC818(void *a0);
extern void func_021BC954(u8 *a0);
extern u32 func_021BB974(void *p);
extern void func_021BB710(u8 *p);
extern void func_021BB69C(u8 *p);
extern void func_021BB484(u8 *p);
extern void func_021BB2B4(char *p);
extern void func_021BB534(u8 *p);
extern void func_021BB37C(char *p);
extern void func_021BB784(struct S *p);
extern void func_021BB5F4(u8 *p);
extern void func_021BB84C(u8 *p);
extern void func_021BC5F0(u8 *a0);
extern void func_021BC5D4(int *p);
extern void func_0204A600(void);
extern void func_021BB908(void *);
extern void func_021BB94C(u32 a0);
/* The caller supplies r0 to B48/C40 and consumes BB928 r0 despite legacy prototypes. */
extern void func_021BC93C(u32);
extern void func_021BC8B4(u32);
extern void func_021BC8E4(struct S *);
extern void func_021BC960(u8 *);
extern void func_021BC43C(u8 *);
extern void func_021BC820(u8 *);
extern void func_021BC9FC(char *);
extern void func_021BCAE8(char *);
extern u32 func_021BCB48(u32);
extern void func_021BCB70(char *);
extern void func_021BCBD0(struct S *);
extern u32 func_021BCC40(u32);
extern void func_021BCC68(struct S *);
extern void func_021BCDF0(char *);
extern void func_021BCE7C(char *);
extern void func_021BCF68(struct S *);
extern void func_021BCFD0(u8 *);
extern void func_021BD094(struct S *);
extern void func_021BD0C4(u8 *);
extern void func_021BD178(struct S *p);
extern void func_021BD274(struct S *p);
extern void func_021BD38C(char *);
extern void func_021BD3B4(u8 *);
extern void func_021BD47C(u8 *);
extern void func_021BD4F0(char *);
extern void func_021BD53C(int *);
extern void func_021BD5C4(char *p);
extern void func_021BD5B4(u32);
extern void func_021BD588(void *);
extern void func_021BC580(char *,int);
extern void func_021BC72C(u8 *,u32,u8 *);
extern void func_021BC644(struct S *);
extern u8 func_021BBC50(u8 *);
extern void func_021BBDF0(u32,u32);
extern void func_021BC6EC(void *,u8);
extern void func_021BC014(u8 *);
extern void func_021BC168(u32);
extern void func_021BBF60(u8 *);
extern int func_021BC06C(char *p);
extern u32 func_021BB928(u8 *);
extern void func_021BBD68(u8 *);
extern u32 func_021BC128(u32);
extern void func_021BB91C(void *);
extern void func_021BB910(u8 *,u32);
extern void func_021BBDAC(u8 *);
extern u32 func_021BC0E8(u32);
extern void func_021BC480(void);
extern u32 func_020362DC(void);
extern int func_02035C08(const void *p);
extern int func_02035BA4(const void *p);
extern u32 func_02035CB8(u32 *,u32 *);
extern void func_020061E4(u32);
extern void *func_021C09B8(void *);
extern u32 func_021BC6D0(void *);
extern void func_021BBAD0(u32);
extern void func_021BB934(u8 *,u32);
extern u32 func_021BC6F4(u32 a0, u32 a1);
extern u32 func_021BBAA4(u32,u8);
extern int func_021BC428(void *);
extern u32 func_0203630C(void);
extern void func_021BC600(void *p);
extern void func_021BC608(void *p);
extern u32 func_021BC6DC(void *p);
extern u32 func_021BC5FC(void *p);
extern void func_021BBD40(u8 *p, int a);
extern unsigned func_021BB98C(void *);
extern void func_021BBADC(u8 *);
extern void func_021BB990(void *);
extern void func_021BC2D8(struct S *p);
extern void func_021BC338(u8 *);
extern int func_021BC2FC(void *);
extern void func_021BC280(struct S *p);
extern void func_021BC2B8(void *p);
extern int func_021BC200(void *p, int position);
extern void func_021BC30C(struct S *p, int v);
extern void func_021BC380(struct S *p);
extern void func_021BC274(void *p);
extern void func_021BC250(void *p);
extern int func_021BC264(void *p);
extern void func_021BBA30(u8 *p);
void func_021BAB50(void);
void func_021BAB58(void *a0);
void func_021BAB68(void);
void func_021BAB70(u32 a0);
u32 func_021BAB80(u32 a0, u32 a1);
u32 func_021BABB4(void *a0);
void func_021BABC4(void *self);
u32 func_021BAC90(void *p);
u32 func_021BAC98(void *p);
void func_021BACA0(u8 *p);
/* Narrow selection parameters follow the caller's explicit lsls/lsrs #24 pairs. */ void func_021BAE00(u8 *p);
void func_021BAF70(char *p);
void func_021BB190(u8 *p);
void func_021BB200(struct S *p);


/*
 * Tail-call thunk: ldr r3,[pc,#0]; bx r3; .word 0x0204A648.  Blocker target
 * for func_021BAB58 (pkt_021B9850).
 */
void func_021BAB50(void)
{
    func_0204A648();
}

void func_021BAB58(void *a0)
{
    func_02005654((int)func_021BAB50, 0);
}


/*
 * Tail-call veneer: branch to func_0200566C.
 *
 * Addresses are Black-image addresses.
 */
void func_021BAB68(void)
{
    func_0200566C();
}

void func_021BAB70(u32 a0)
{
    func_0203D34C(1, ((struct Obj25840 *)(((u8*)a0 + 0)))->f4);
}

/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BAB80(u32 a0, u32 a1)
{
    u32 v1 = func_021C09AC((void *)a0);
    u32 v2 = func_021BC758(v1);
    func_021BC774((u8 *)v2);
    func_021BC634(v2, v1);
    func_021BC638((void *)v2, a0);
    func_021BC640((void *)v2, a1);
    return v2;
}

u32 func_021BABB4(void *a0)
{
    func_021BC954((u8 *)a0);
    return func_021BC818(a0);
}


void func_021BABC4(void *self)
{
    switch (func_021BB974(self)) {
    case 0: func_021BACA0(self); break;
    case 1: func_021BAE00(self); break;
    case 2: func_021BAF70(self); break;
    case 3: func_021BB190(self); break;
    case 4: func_021BB200(self); break;
    case 6: func_021BB69C(self); break;
    case 5: func_021BB710(self); break;
    case 7: func_021BB484(self); break;
    case 8: func_021BB2B4(self); break;
    case 9: func_021BB534(self); break;
    case 10: func_021BB37C(self); break;
    case 11: func_021BB784(self); break;
    case 12: func_021BB5F4(self); break;
    case 13: func_021BB84C(self); break;
    case 14: break;
    }
    if (!func_021BAC90(self)) {
        func_021BC5F0(self);
        func_021BC5D4(self);
        func_0204A600();
    }
    func_021BB908(self);
    func_021BB94C((u32)self);
}


u32 func_021BAC90(void *p)
{
    return ((struct Obj25841 *)p)->f164;
}


/*
 * Field getter, u32 at +0x168.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BAC98(void *p)
{
    return ((struct Obj25842 *)p)->f168;
}

void func_021BACA0(u8 *p)
{
    u8 slot;
    func_021BC93C((u32)p);
    func_021BC8B4((u32)p);
    func_021BC8E4((struct S *)p);
    func_021BC960(p);
    func_021BC43C(p);
    func_021BC820(p);
    func_021BC9FC((char *)p);
    func_021BCAE8((char *)p);
    func_021BCB48((u32)p);
    func_021BCB70((char *)p);
    func_021BCBD0((struct S *)p);
    func_021BCC40((u32)p);
    func_021BCC68((struct S *)p);
    func_021BCDF0((char *)p);
    func_021BCE7C((char *)p);
    func_021BCF68((struct S *)p);
    func_021BCFD0(p);
    func_021BD094((struct S *)p);
    func_021BD0C4(p);
    func_021BD178((struct S *)p);
    func_021BD274((struct S *)p);
    func_021BD38C((char *)p);
    func_021BD3B4(p);
    func_021BD47C(p);
    func_021BD4F0((char *)p);
    func_021BD53C((int *)p);
    func_021BD5C4((char *)p);
    func_021BD5B4((u32)p);
    func_021BD588(p);
    func_021BC580((char *)p,0);
    func_021BC72C(p,0,0);
    func_021BC72C(p,1,0);
    func_021BC72C(p,2,0);
    func_021BC644((struct S *)p);
    slot=func_021BBC50(p);
    if(slot!=255) {
        func_021BBDF0((u32)p,slot);
        func_021BC6EC(p,slot);
        func_021BC014(p);
    }
    func_021BC43C(p);
    func_021BC168((u32)p);
    func_021BC014(p);
    func_021BBF60(p);
    func_021BC06C((char *)p);
    if(func_021BB928(p)==0) {
        func_021BBD68(p);
        func_021BC128((u32)p);
        func_021BB91C(p);
        func_021BB910(p,2);
    } else {
        func_021BBDAC(p);
        func_021BC0E8((u32)p);
        func_021BB91C(p);
        func_021BB910(p,1);
    }
    func_021BC480();
}

/* Narrow selection parameters follow the caller's explicit lsls/lsrs #24 pairs. */
void func_021BAE00(u8 *p)
{
    u32 keys=func_020362DC();
    int sel=func_02035C08(p+0x64);
    int flag;
    u32 a,b;
    flag=func_02035C08(func_021C09B8(*(void **)p));
    func_02035CB8(&a,&b);
    if(func_021BC6D0(p)!=0 || flag==0) {
        func_020061E4(0x551);
        func_021BBAD0((u32)p);
        func_021BB934(p,1);
        func_021BB91C(p);
        func_021BB910(p,5);
        return;
    }
    if(keys&2) {
        func_020061E4(0x551);
        func_021BBAD0((u32)p);
        func_021BB934(p,0);
        func_021BB91C(p);
        func_021BB910(p,5);
        return;
    }
    if((keys&0x40)||(keys&0x80)||(keys&0x20)||(keys&0x10)||(keys&1)) {
        func_021BBD68(p);
        func_021BC128((u32)p);
        func_021BB91C(p);
        func_021BB910(p,2);
        return;
    }
    if(sel>=0 && sel<=9) {
        if(b>=24 && b<=168) {
            if(func_021BC6F4((u32)p,(u8)sel)==1) {
                func_021BBAA4((u32)p,sel);
                func_021BC6EC(p,p[0x32]);
                func_020061E4(0x54c);
                func_021BC580((char *)p,2);
                func_021BC06C((char *)p);
                func_021BC128((u32)p);
                func_021BB91C(p);
                func_021BB910(p,7);
                return;
            }
        }
    } else {
        if(func_02035BA4(p+0x90)==0 || func_02035C08(p+0x90)==0) {
            if(func_021BC428(p)==1) {
                func_021BB91C(p);
                func_021BB910(p,4);
                func_021BB910(p,1);
            }
        }
    }
}


void func_021BAF70(char *p)
{
    u32 trg = func_0203630C();
    u32 keys = func_020362DC();
    int sel = func_02035C08(p + 0x64);
    int flag;
    u32 a;
    u32 b;
    flag = func_02035C08(func_021C09B8(*(void **)p));
    func_02035CB8(&a, &b);
    if (trg & 0xc0) {
        func_021BC600(p);
    } else {
        func_021BC608(p);
    }
    if (func_021BC6D0(p) != 0 || flag == 0) {
        func_020061E4(0x551);
        func_021BBAD0((u32)p);
        func_021BB934((u8 *)p, (int)1);
        func_021BB91C(p);
        func_021BB910((u8 *)p, (int)6);
        return;
    }
    if ((keys & 0x40) || ((trg & 0x40) && ((struct Obj00025 *)p)->f32 != 0 && func_021BC5FC(p) > 10)) {
        func_021BBDAC((u8 *)p);
        func_021BBD40((u8 *)p, -1);
        func_021BB91C(p);
        func_021BB910((u8 *)p, (int)3);
        func_021BB910((u8 *)p, (int)2);
        return;
    }
    if ((keys & 0x80) || ((trg & 0x80) && ((struct Obj00025 *)p)->f32 < (int)func_021BC6DC(p) - 1 && func_021BC5FC(p) > 10)) {
        func_021BBDAC((u8 *)p);
        func_021BBD40((u8 *)p, 1);
        func_021BB91C(p);
        func_021BB910((u8 *)p, (int)3);
        func_021BB910((u8 *)p, (int)2);
        return;
    }
    if (keys & 1) {
        func_021BC580(p, 2);
        func_021BC6EC(p, ((struct Obj00025 *)p)->f32);
        func_020061E4(0x54c);
        func_021BB910((u8 *)p, (int)9);
        func_021BB91C(p);
        return;
    }
    if (sel >= 0 && sel <= 9) {
        if (b >= 0x18 && b <= 0xa8 && func_021BC6F4((u32)p, (u8)sel) == 1) {
            func_021BBAA4((u32)p, (u8)sel);
            func_021BC6EC(p, ((struct Obj00025 *)p)->f32);
            func_021BC580(p, 2);
            func_020061E4(0x54c);
            func_021BC06C(p);
            func_021BB91C(p);
            func_021BB910((u8 *)p, (int)7);
        }
        return;
    }
    if (keys & 2) {
        func_020061E4(0x551);
        func_021BBAD0((u32)p);
        func_021BB934((u8 *)p, (int)0);
        func_021BB91C(p);
        func_021BB910((u8 *)p, (int)6);
        return;
    }
    if (func_02035BA4(p + 0x90) == 0 || func_02035C08(p + 0x90) == 0) {
        if (func_021BC428(p) == 1) {
            func_021BBDAC((u8 *)p);
            func_021BC0E8((u32)p);
            func_021BB91C(p);
            func_021BB910((u8 *)p, (int)4);
            func_021BB910((u8 *)p, (int)1);
        }
    }
}

void func_021BB190(u8 *p)
{
    switch (func_021BB98C(p)) {
    case 0:
        func_021BBADC(p);
        func_021BBAA4((unsigned)p, p[0x33]);
        func_021BC06C((char *)p);
        func_021BB990(p);
        break;
    case 1:
        func_021BC2D8((struct S *)p);
        func_021BC338(p);
        func_021BC43C(p);
        func_021BC168((unsigned)p);
        func_021BC014(p);
        func_021BBF60(p);
        if (func_021BC2FC(p)) {
            func_021BBF60(p);
            func_021BB91C(p);
        }
        break;
    }
}


void func_021BB200(struct S *p)
{
    int a;
    int b;
    int r = func_02035CB8((unsigned int *)(&a), (unsigned int *)(&b));
    int m = func_021BB98C(p);
    switch (m) {
    case 0:
    {
        if (r == 0) {
            func_021BC280(p);
            func_021BC2B8(p);
            func_021BB990(p);
        } else {
            func_021BC30C(p, func_021BC200(p, b));
            func_021BC380(p);
            func_021BC43C((u8 *)p);
            func_021BC168((unsigned int)p);
            func_021BC014((u8 *)p);
            func_021BC274(p);
        }
        break;
    }
    case 1:
    {
        func_021BC30C(p, p->f34 + p->f4c);
        func_021BC380(p);
        func_021BC43C((u8 *)p);
        func_021BC168((unsigned int)p);
        func_021BC014((u8 *)p);
        func_021BC250(p);
        if (func_021BC264(p) == 0) {
            func_021BC06C((char *)p);
            func_021BB91C(p);
        }
        break;
    }
    }
    func_021BBA30((u8 *)p);
}
