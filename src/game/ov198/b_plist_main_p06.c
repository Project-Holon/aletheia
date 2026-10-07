/*
 * file:     b_plist_main_p06.c
 * unit:     yes
 * function: func_022110F8, func_02211128, func_02211168, func_02211190, func_022112AC, func_02211378, func_0221139C, func_022113B8, func_022113FC, func_02211420, func_02211810, func_02211844, func_0221189C, func_022118F4, func_02211944, func_02211958, func_02211970, func_02211984, func_02211998, func_022119E8, func_022119F8, func_02211A10, func_02211A24
 * address:  0x022110F8
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02210C88 0x02210C88 thumb ov198
 *   func_022110D4 0x022110D4 thumb ov198
 *   func_02210F04 0x02210F04 thumb ov198
 *   func_02210F84 0x02210F84 thumb ov198
 *   func_02210F98 0x02210F98 thumb ov198
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_02021ED8 0x02021ED8 thumb
 *   func_02210A4C 0x02210A4C thumb ov198
 *   func_0220B760 0x0220B760 thumb ov198
 *   func_022110E0 0x022110E0 thumb ov198
 *   func_0220E13C 0x0220E13C thumb ov198
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_0220C688 0x0220C688 thumb
 *   func_0220E27C 0x0220E27C thumb
 *   func_0204162C 0x0204162C arm
 *   func_02082A60 0x02082A60 arm
 *   func_0220F22C 0x0220F22C thumb ov198
 *   func_022110A4 0x022110A4 thumb ov198
 *   func_0220F2DC 0x0220F2DC thumb ov198
 *   data_02212550 0x02212550 data ov198
 *   func_0220BBF0 0x0220BBF0 thumb ov198
 *   func_0220C67C 0x0220C67C thumb ov198
 *   func_02210EFC 0x02210EFC thumb ov198
 *   func_02025CD0 0x02025CD0 thumb
 *   func_02025D1C 0x02025D1C thumb
 *   func_02025D24 0x02025D24 thumb
 *   d_022122D4 0x022122D4 data a4
 *   d_022122A0 0x022122A0 data a4
 *   func_02025D14  0x02025D14  thumb
 *   func_0220AFDC  0x0220AFDC  thumb  ov196
 *   func_0202616C  0x0202616C  thumb
 *   func_0220B000  0x0220B000  thumb  ov196
 */
#include "../../matched/include/Obj10854.h"
#include "../../matched/include/Obj01431.h"
#include "../../matched/include/Obj08366.h"
#include "../../matched/include/Obj02536.h"
#include "../../matched/include/Obj25281.h"
#include "../../matched/include/Obj14570.h"
#include "../../matched/include/Obj14571.h"
#include "../../matched/include/Obj25284.h"
#include "../../matched/include/Obj25286.h"
#include "../../matched/include/Obj25288.h"
#include "../../matched/include/Obj10855.h"
#include "../../matched/include/Obj25289.h"
#include "../../matched/include/Obj25290.h"

#define MGR (*(struct WinMgr **)(p + 0x2194))
struct MsgBank;
struct U16Vec;
struct WordSet;
struct WinMgr;
struct Struct_02025CD0;
struct Struct_02025D1C;
struct Struct_02025D24;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned u32_02211190;

typedef unsigned int   u32_022112AC;

typedef unsigned int   u32_02211378;

typedef signed char s8;

typedef signed short s16;

typedef unsigned int u32_0221139C;

typedef signed int s32;

typedef unsigned int   u32_022113B8;

typedef unsigned int u32_02211420;

typedef struct { u8 lo:7; u8 high:1; } Bits;

typedef unsigned int   u32_02211944;

typedef unsigned int   u32_02211958;

typedef unsigned int   u32_02211970;

typedef unsigned int   u32_02211984;

typedef unsigned u32_02211998;

typedef enum { task_offset=0x218c } Offset;

typedef unsigned int   u32_022119E8;

typedef unsigned int   u32_022119F8;

typedef unsigned int   u32_02211A10;

typedef unsigned int   u32_02211A24;

extern int func_02210C88(u8 *, unsigned);
extern int func_022110D4(u8 *, int);
extern u32_02211190 func_02210F04(u32_02211190, u32_02211190);
extern int func_02210F84(char **, unsigned);
extern unsigned func_02210F98(u8 *p, int index);
extern void *func_02045EC0(struct MsgBank *bank, u32_02211190 index);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201EEF4(struct WordSet *p, u32_02211190 i, void *mon);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32_022112AC func_02021ED8(const char *ptr);
extern int func_02210A4C(u8 *);
extern void func_0220B760(u8 *, unsigned);
extern void func_022110E0(u8 **, unsigned, unsigned);
extern void func_0220E13C(u8 *);
extern void func_0201F7A8(void *desc, u32_02211378 kind);
extern void func_0220C688(char *p);
extern void func_0220E27C(u8 *p);
extern u32_022113B8 func_0204162C(int channel);
extern void func_02082A60(const void *, void *, unsigned);
extern void func_0220F22C(u8 *, int, int);
extern struct WinMgr *func_0202C9B4(u32_02211420 a0, u32_02211420 a1, u32_02211420 heap);
extern void func_0202CA3C(struct WinMgr *mgr, u32_02211420 idx, u32_02211420 a, u32_02211420 b, u32_02211420 c);
extern void func_0202CAC4(struct WinMgr *mgr, u32_02211420 idx, const void *src);
extern void func_0202CB4C(struct WinMgr *mgr, u32_02211420 idx, s8 x, s8 y);
extern void func_0202CD94(struct WinMgr *mgr);
extern void func_0202CD64(struct WinMgr *mgr, u32_02211420 idx, s8 dx, s8 dy, u8 frames);
extern void func_0202CF98(struct WinMgr *mgr, u32_02211420 idx, s8 *x, s8 *y);
extern u32_02211420 func_0202CE40(struct WinMgr *mgr, u32_02211420 idx);
extern void func_0202CA0C(struct WinMgr *mgr);
extern void *func_02030734(u32_02211420 heapId, u32_02211420 size, int clear, const char *site, u16 tag);
extern u32_02211420 func_020307B0(void *p);
extern void func_022110A4(u8 *p, int a, int b);
extern void func_0220F2DC(char *p, int a1, int a2);
extern void func_0220BBF0(u8 *);
extern void func_0220C67C(char *p);
extern int func_02210EFC(char **p);
extern void func_020061E4(u32_02211970);
extern struct Struct_02025CD0 *func_02025CD0(u32_02211998,u32_02211998,u32_02211998,u32_02211998,u8,u16);
extern void func_02025D1C(struct Struct_02025D1C *);
extern void func_02025D24(struct Struct_02025D24 *);
extern u32_022119E8 func_02025D14(void *a0);
extern u32_02211A10 func_0220AFDC(u32_02211A10, u32_02211A10);
extern void *func_0202616C(void **obj, u32_02211A24 idx);
extern void func_0220B000(int *p, u8 *q);
void func_022110F8(u8 *p, int a, int b);
int func_02211128(unsigned char *p, unsigned char *a, unsigned char *b, int clear);
int func_02211168(u8 *p);
int func_02211190(u8 *p);
int func_022112AC(u8 *p);
int func_02211378(char *p);
void func_0221139C(u8 *a, u8 *b, unsigned int c);
void func_022113B8(u8 *dst, unsigned bg, unsigned which);
void func_022113FC(u8 *p, int a, int b);
int func_02211420(u8 *p);
int func_02211810(u8 *p);
int func_02211844(u8 *p);
int func_0221189C(u8 *p);
void func_022118F4(u8 *p);
void func_02211944(u8 **p);
u32_02211958 func_02211958(u8 **p);
void func_02211970(u8 **p, u32_02211970 b);
void func_02211984(u8 **p, u32_02211984 b);
void func_02211998(u8 *p,u32_02211998 index,u32_02211998 b);
u32_022119E8 func_022119E8(u8 *p);
void func_022119F8(u8 *p, u32_022119F8 a, u32_022119F8 b);
u32_02211A10 func_02211A10(u8 *p, u32_02211A10 v);
void func_02211A24(u8 *p, u32_02211A24 idx);
extern u8 data_02212550[];
extern const u32_02211998 d_022122D4[],d_022122A0[];


void func_022110F8(u8 *p, int a, int b)
{
    u8 i;
    for (i = 0; i < 2; i++) {
        u8 *q = p + i * 4;
        if (((struct Obj10854 *)q)->f249C == 0xff) {
            ((struct Obj10854 *)q)->f249C = a;
            ((struct Obj10854 *)q)->f249E = b;
            return;
        }
    }
}

int func_02211128(unsigned char *p, unsigned char *a, unsigned char *b, int clear)
{
    int i;

    for (i = 1; i >= 0; i--) {
        if (*(unsigned short *)(p + 0x249c + i * 4) == 0xff) {
            continue;
        }
        *a = (unsigned char)*(unsigned short *)(p + 0x249c + i * 4);
        *b = (unsigned char)*(unsigned short *)(p + 0x249c + 2 + i * 4);
        if (clear == 1) {
            *(unsigned short *)(p + 0x249c + i * 4) = 0xff;
            *(unsigned short *)(p + 0x249c + 2 + i * 4) = 0xff;
        }
        return 1;
    }
    return 0;
}

int func_02211168(u8 *p)
{
    int mode = 8;
    if (func_02210C88(p, mode) == 0) {
        p[0x2498] = (*(u8 **)p)[0x20];
        return 0x13;
    }
    return mode;
}

int func_02211190(u8 *p)
{
    u8 *row;
    int idx;
    void *text;
    idx = func_022110D4(p, (*(u8 **)p)[0x20]);
    row = p + 4 + idx * 0x4c;
    if (func_02210F04((u32_02211190)p, idx) == 1) {
        text = func_02045EC0(((struct Obj01431 *)p)->f1EA0, 0x5a);
        func_0201F250(((struct Obj01431 *)p)->f1EA4, ((struct Obj01431 *)p)->f1EA8, text);
        func_02045808(text);
        return 0;
    }
    if (func_02210F84((char **)p, (*(u8 **)p)[0x20]) == 0) {
        if (func_02210F84((char **)p, idx) == 1)
            text = func_02045EC0(((struct Obj01431 *)p)->f1EA0, 0x6b);
        else
            text = func_02045EC0(((struct Obj01431 *)p)->f1EA0, 0x6a);
        func_0201EEF4(((struct Obj01431 *)p)->f1EA4, 0, ((struct Obj08366 *)row)->f0);
        func_0201F250(((struct Obj01431 *)p)->f1EA4, ((struct Obj01431 *)p)->f1EA8, text);
        func_02045808(text);
        return 0;
    }
    if (func_02210F98(p, (*(u8 **)p)[0x20]) == 1) {
        text = func_02045EC0(((struct Obj01431 *)p)->f1EA0, 0x56);
        func_0201EEF4(((struct Obj01431 *)p)->f1EA4, 0, ((struct Obj08366 *)row)->f0);
        func_0201F250(((struct Obj01431 *)p)->f1EA4, ((struct Obj01431 *)p)->f1EA8, text);
        func_02045808(text);
        return 0;
    }
    if (((struct Obj08366 *)row)->f10 != 0) {
        text = func_02045EC0(((struct Obj01431 *)p)->f1EA0, 0x56);
        func_0201EEF4(((struct Obj01431 *)p)->f1EA4, 0, ((struct Obj08366 *)row)->f0);
        func_0201F250(((struct Obj01431 *)p)->f1EA4, ((struct Obj01431 *)p)->f1EA8, text);
        func_02045808(text);
        return 0;
    }
    return 1;
}

int func_022112AC(u8 *p)
{
    if (func_02021ED8(((struct Obj02536 *)p)->f1D8) != 0) return 8;
    if (func_02211958((u8 **)p) == 1) return 0x1f;
    if (func_02210A4C(p) == 1) {
        if ((*(u8 **)p)[0x20] == 6) {
            func_02211970((u8 **)p, 0x552);
            func_0220B760(p, 6);
            (*(u8 **)p)[0x20] = p[0x2498];
            ((struct Obj02536 *)p)->f217C = 0xc;
            return 0x1d;
        }
        if ((*(u8 **)p)[0x20] == p[0x2498]) return 0xc;
        if (func_02211190(p) == 1) {
            func_022110F8(p, (*(u8 **)p)[0x20], p[0x2498]);
            func_022110E0((u8 **)p, (*(u8 **)p)[0x20], p[0x2498]);
            p[0x2499] = (*(u8 **)p)[0x20];
            p[0x249a] = p[0x2498];
            p[0x1e98] = 0;
            return 9;
        }
        func_0220E13C(p);
        ((struct Obj02536 *)p)->f217C = 0xa;
        return 0x17;
    }
    return 8;
}


int func_02211378(char *p)
{
    func_0201F7A8(((struct Obj25281 *)p)->f1F68, 0);
    func_0220C688(p);
    func_0220E27C((u8 *)p);
    return 8;
}


void func_0221139C(u8 *a, u8 *b, unsigned int c)
{
    int lo = c & 1;

    *a = (u8)(lo << 4);
    *b = (u8)(lo + (c >> 1) * 6);
}

/*
 * Trailing 022113FA halfword is zero alignment padding, not a follower.
 */
void func_022113B8(u8 *dst, unsigned bg, unsigned which)
{
    u8 xy[2];
    u8 *src = (u8 *)func_0204162C(bg);
    u8 i;
    func_0221139C(&xy[1], &xy[0], which);
    for (i = 0; i < 6; i++) {
        func_02082A60(src + 2 * (xy[1] + ((xy[0] + i) << 5)), dst + (i << 5), 32);
    }
}

/*
 * prototype: delta is word-wide at this call; the callee's short extern inserts lsls/asrs absent from 0x02211418.
 */
void func_022113FC(u8 *p, int a, int b)
{
    int delta = 1;
    if (a & delta) {
        if (b == 0) delta = 8;
        else delta = -8;
    } else {
        delta = -8;
        if (b != 0) delta = 8;
    }
    func_0220F22C(p, a, delta);
}


int func_02211420(u8 *p)
{
    s8 xy[4];
    s8 pos[4];
    s8 pos2[4];
    switch (p[0x1e98]) {
    case 0: {
        u8 *buf;
        MGR = func_0202C9B4(2, 4, *(u16 *)(*(u8 **)p + 0x10));
        func_0202CA3C(MGR, 0, 5, 0x10, 6);
        func_0202CA3C(MGR, 1, 6, 0x10, 6);
        func_0202CA3C(MGR, 2, 5, 0x10, 6);
        func_0202CA3C(MGR, 3, 6, 0x10, 6);
        buf = func_02030734((u16)(0x8000 | (*(u16 *)(*(u8 **)p + 0x10) & 0x7fff)), 0xc0, 0, (const char *)data_02212550, 0xb89);
        func_022113B8(buf, 5, p[0x2499]);
        func_0202CAC4(MGR, 0, buf);
        func_022113B8(buf, 6, p[0x2499]);
        func_0202CAC4(MGR, 1, buf);
        func_022113B8(buf, 5, p[0x249a]);
        func_0202CAC4(MGR, 2, buf);
        func_022113B8(buf, 6, p[0x249a]);
        func_0202CAC4(MGR, 3, buf);
        func_020307B0(buf);
        func_0221139C((u8 *)&xy[1], (u8 *)&xy[0], p[0x2499]);
        func_0202CB4C(MGR, 0, xy[1], xy[0]);
        func_0202CB4C(MGR, 1, xy[1], xy[0]);
        func_0221139C((u8 *)&xy[1], (u8 *)&xy[0], p[0x249a]);
        func_0202CB4C(MGR, 2, xy[1], xy[0]);
        func_0202CB4C(MGR, 3, xy[1], xy[0]);
        func_0202CD94(MGR);
        p[0x1e98]++;
        break;
    }
    case 1:
        if (p[0x2499] & 1) {
            func_0202CD64(MGR, 0, 1, 0, 0x10);
            func_0202CD64(MGR, 1, 1, 0, 0x10);
        } else {
            func_0202CD64(MGR, 0, -1, 0, 0x10);
            func_0202CD64(MGR, 1, -1, 0, 0x10);
        }
        if (p[0x249a] & 1) {
            func_0202CD64(MGR, 2, 1, 0, 0x10);
            func_0202CD64(MGR, 3, 1, 0, 0x10);
        } else {
            func_0202CD64(MGR, 2, -1, 0, 0x10);
            func_0202CD64(MGR, 3, -1, 0, 0x10);
        }
        p[0x1e98]++;
        break;
    case 2: {
        func_0202CD94(MGR);
        func_022113FC(p, p[0x2499], 0);
        func_022113FC(p, p[0x249a], 0);
        func_0202CF98(MGR, 0, &pos[3], &pos[2]);
        func_0202CF98(MGR, 2, &pos[1], &pos[0]);
        if (func_0202CE40(MGR, 0) != 0) break;
        func_022110A4(p, p[0x2499], p[0x249a]);
        func_0202CB4C(MGR, 0, pos[1], pos[0]);
        func_0202CB4C(MGR, 1, pos[1], pos[0]);
        func_0202CB4C(MGR, 2, pos[3], pos[2]);
        func_0202CB4C(MGR, 3, pos[3], pos[2]);
        func_0220F2DC((char *)p, p[0x2499], p[0x249a]);
        p[0x1e98]++;
        break;
    }
    case 3:
        func_0202CD94(MGR);
        if (p[0x249a] & 1) {
            func_0202CD64(MGR, 0, -1, 0, 0x10);
            func_0202CD64(MGR, 1, -1, 0, 0x10);
        } else {
            func_0202CD64(MGR, 0, 1, 0, 0x10);
            func_0202CD64(MGR, 1, 1, 0, 0x10);
        }
        if (p[0x2499] & 1) {
            func_0202CD64(MGR, 2, -1, 0, 0x10);
            func_0202CD64(MGR, 3, -1, 0, 0x10);
        } else {
            func_0202CD64(MGR, 2, 1, 0, 0x10);
            func_0202CD64(MGR, 3, 1, 0, 0x10);
        }
        p[0x1e98]++;
        break;
    case 4: {
        func_0202CD94(MGR);
        func_022113FC(p, p[0x2499], 1);
        func_022113FC(p, p[0x249a], 1);
        func_0202CF98(MGR, 0, &pos2[3], &pos2[2]);
        func_0202CF98(MGR, 2, &pos2[1], &pos2[0]);
        if (func_0202CE40(MGR, 0) == 0) p[0x1e98]++;
        break;
    }
    case 5:
        func_0202CA0C(MGR);
        MGR = 0;
        p[0x1e98] = 0;
        return 0;
    }
    return 1;
}

int func_02211810(u8 *p)
{
    if (func_02211420(p) == 0) {
        if (func_0221189C(p) == 0) return 31;
        func_0220BBF0(p);
        func_0220C67C((char *)p);
        func_0220E27C(p);
        return 3;
    }
    return 9;
}

/*
 * tail: 0221189A..0221189C is zero alignment padding.
 */
int func_02211844(u8 *p)
{
    u8 count,i,bound;
    if(func_02210EFC((char **)((unsigned)p))==1) return 0;
    bound=(*(u8 **)p)[0x22];
    if(bound==1) return 0;
    count=0;
    for(i=0;i<bound;i++) {
        if(*(unsigned short *)(p+func_022110D4(p,i)*0x4c+0x14)==0) {
            count++;
            if(count==2) return 1;
        }
    }
    return 0;
}

int func_0221189C(u8 *p)
{
    u8 i;
    if(func_02210EFC((char **)((unsigned)p))==1) return 0;
    i=(*(u8 **)p)[0x22];
    if(i==1) return 0;
    for(;i<6;i++) {
        u8 *record=p+func_022110D4(p,i)*0x4c;
        if(((struct Obj14570 *)record)->f8!=0 && ((Bits *)(record+0x1b))->high==0 && ((struct Obj14570 *)record)->f14!=0) return 1;
    }
    return 0;
}

/*
 * lever: associate the index with the destination pointer before adding 0x48.
 */
void func_022118F4(u8 *p)
{
    unsigned i;
    if(func_02210EFC((char **)((unsigned)p))==1) {
        (*(u8 **)p)[0x48]=func_022110D4(p,(*(u8 **)p)[0x20]);
    } else {
        for(i=0;i<3;i++) {
            if(*(unsigned short *)(p+func_022110D4(p,i)*0x4c+0x14)==0) {
                ((*(u8 * *)&((struct Obj14571 *)p)->f0)+i)[0x48]=(*(u8 **)p)[0x20];
                break;
            }
        }
    }
}


/*
 * Addresses are Black-image addresses.
 */
void func_02211944(u8 **p)
{
    u32_02211944 i;

    for (i = 0; i < 3; i++) {
        *(u8 *)(*p + i + 0x48) = 0xff;
    }
}


u32_02211958 func_02211958(u8 **p)
{
    if (((struct Obj25284 *)(*p))->f30 == 1) {
        func_02211944(p);
        return 1;
    }
    return 0;
}


void func_02211970(u8 **p, u32_02211970 b)
{
    if (((struct Obj25286 *)(*p))->f40 == 1) {
        func_020061E4(b);
    }
}


void func_02211984(u8 **p, u32_02211984 b)
{
    if (((struct Obj25288 *)(*p))->f40 == 1) {
        func_020061E4(b);
    }
}

/*
 * lever: enum offset retains 0x218C across calls and derives 0x2184.
 * ABI: 02211A24 explicitly receives the forwarded entry r2 as its r1.
 */
void func_02211998(u8 *p,u32_02211998 index,u32_02211998 b)
{
    Offset offset=task_offset;
    struct Struct_02025CD0 *result;
    result=func_02025CD0(d_022122D4[index],(u32_02211998)d_022122A0,(u32_02211998)p,*(u32_02211998 *)(p+offset),b,((struct Obj25289 *)(*(u8 * *)&((struct Obj10855 *)p)->f0))->f10);
    *(struct Struct_02025CD0 **)(p+(offset-8))=result;
    func_02025D1C((struct Struct_02025D1C *)result);
    offset-=8;
    func_02025D24(*(struct Struct_02025D24 **)(p+offset));
    func_02211A24(p,b);
}


u32_022119E8 func_022119E8(u8 *p)
{
    return func_02025D14((void *)(((struct Obj25290 *)p)->f2184));
}


void func_022119F8(u8 *p, u32_022119F8 a, u32_022119F8 b)
{
    func_022119E8(p);
    func_02211998(p, a, b);
}


/*
 * note:     the callee takes (p, v); passing v as the second argument keeps r1 live
 *           across the store, so the index decrement stays in r2.
 */
u32_02211A10 func_02211A10(u8 *p, u32_02211A10 v)
{
    u32_02211A10 i = 0x218c;

    *(u32_02211A10 *)(p + i) = v;
    i -= 4;
    return func_0220AFDC(*(u32_02211A10 *)(p + i), v);
}


void func_02211A24(u8 *p, u32_02211A24 idx)
{
    void *t = func_0202616C(*(void ** *)&((struct Obj10855 *)p)->f2184, idx);

    func_0220B000((int *)(((struct Obj10855 *)p)->f2188), (u8 *)((u32_02211A24)t));
}
