/*
 * file:     research_top_p08.c
 * unit:     yes
 * function: func_021BB2B4, func_021BB37C, func_021BB484, func_021BB534, func_021BB5F4, func_021BB69C, func_021BB710, func_021BB784, func_021BB84C, func_021BB908, func_021BB910, func_021BB91C, func_021BB928, func_021BB934
 * address:  0x021BB2B4
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
 *   func_021BBA00 0x021BBA00 thumb ov217
 *   func_021BC5A8 0x021BC5A8 thumb ov217
 *   func_021BC580 0x021BC580 thumb ov217
 *   func_021BC6D0 0x021BC6D0 thumb ov217
 *   func_020362DC 0x020362DC arm
 *   func_02035C08 0x02035C08 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021BB9A0 0x021BB9A0 thumb ov217
 *   func_021BB9D0 0x021BB9D0 thumb ov217
 *   func_021BB98C 0x021BB98C thumb ov217
 *   func_021BBD28 0x021BBD28 thumb ov217
 *   func_021BC72C 0x021BC72C thumb ov217
 *   func_021C1038 0x021C1038 thumb ov217
 *   func_021BC4B4 0x021BC4B4 thumb ov217
 *   func_021BBBE4 0x021BBBE4 thumb ov217
 *   func_021BB990 0x021BB990 thumb ov217
 *   func_021BC2D8 0x021BC2D8 thumb ov217
 *   func_021BC338 0x021BC338 thumb ov217
 *   func_021BC43C 0x021BC43C thumb ov217
 *   func_021BC168 0x021BC168 thumb ov217
 *   func_021BC014 0x021BC014 thumb ov217
 *   func_021BBF60 0x021BBF60 thumb ov217
 *   func_021BC2FC 0x021BC2FC thumb ov217
 *   func_021BBD14 0x021BBD14 thumb ov217
 *   func_021BBD18 0x021BBD18 thumb ov217
 *   func_021BBC50 0x021BBC50 thumb ov217
 *   func_021BBE7C 0x021BBE7C thumb ov217
 *   func_021BBCB0 0x021BBCB0 thumb ov217
 *   func_021BC6E4 0x021BC6E4 thumb ov217
 *   func_021BBDF0 0x021BBDF0 thumb ov217
 *   func_021BC490 0x021BC490 thumb ov217
 *   func_021BC4A0 0x021BC4A0 thumb ov217
 *   func_021BC50C 0x021BC50C thumb ov217
 *   func_021BC55C 0x021BC55C thumb ov217
 *   func_021BB948 0x021BB948 thumb ov217
 *   func_021BBB60 0x021BBB60 thumb ov217
 *   func_021BC5B8 0x021BC5B8 thumb ov217
 *   func_021BC688 0x021BC688 thumb ov217
 *   func_021BD5E0 0x021BD5E0 thumb ov217
 *   func_021BD56C 0x021BD56C thumb ov217
 *   func_021BD520 0x021BD520 thumb ov217
 *   func_021C09E0 0x021C09E0 thumb ov217
 *   func_021C09EC 0x021C09EC thumb ov217
 *   func_021BD4CC 0x021BD4CC thumb ov217
 *   func_021BD370 0x021BD370 thumb ov217
 *   func_021BD458 0x021BD458 thumb ov217
 *   func_021BD3A4 0x021BD3A4 thumb ov217
 *   func_021BD05C 0x021BD05C thumb ov217
 *   func_021BCF98 0x021BCF98 thumb ov217
 *   func_021BCE5C 0x021BCE5C thumb ov217
 *   func_021BCF20 0x021BCF20 thumb ov217
 *   func_021BCD90 0x021BCD90 thumb ov217
 *   func_021BCC58 0x021BCC58 thumb ov217
 *   func_021BCBCC 0x021BCBCC thumb ov217
 *   func_021BCC3C 0x021BCC3C thumb ov217
 *   func_021BCB60 0x021BCB60 thumb ov217
 *   func_021BCB44 0x021BCB44 thumb ov217
 *   func_021BCAC0 0x021BCAC0 thumb ov217
 *   func_021BC924 0x021BC924 thumb ov217
 *   func_021BC8D8 0x021BC8D8 thumb ov217
 *   func_021BB940 0x021BB940 thumb ov217
 *   func_021C0E4C  0x021C0E4C  thumb  ov217
 *   func_021C09CC  0x021C09CC  thumb  ov217
 *   func_021C09C4  0x021C09C4  thumb  ov217
 */
#include "../../matched/include/Obj02928.h"
#include "../../matched/include/Obj00025.h"
#include "../../matched/include/Obj25844.h"
#include "../../matched/include/Obj25845.h"
#include "../../matched/include/Obj25846.h"

struct S;
typedef unsigned int u32;

typedef unsigned char  u8;

struct S { char pad0[0x32]; unsigned char f32; char pad33[0x81]; void *arr[8]; };

typedef unsigned short u16;

typedef signed int     s32;

extern u32 func_020362DC(void);
extern int func_02035C08(const void *p);
extern void func_020061E4(u32 a);
extern u32 func_021BBA00(u32 a0, u32 a1);
extern void func_021BC5A8(u8 *a0, int a1);
extern void func_021BC580(char *p, int i);
extern u32 func_021BC6D0(void *p);
extern u32 func_021BB9A0(u32 a0);
extern u32 func_021BB9D0(u32 a0);
extern unsigned func_021BB98C(void *);
extern void func_021BBD28(int, int);
extern void func_021BC72C(u8 *, unsigned, u8 *);
extern void func_021C1038(u8 *p, u8 palette);
extern void func_021BC4B4(char *);
extern void func_021BBBE4(u8 *);
extern void func_021BB990(void *);
extern void func_021BC2D8(struct S *p);
extern void func_021BC338(u8 *);
extern void func_021BC43C(u8 *);
extern void func_021BC168(unsigned);
extern void func_021BC014(u8 *);
extern void func_021BBF60(u8 *);
extern int func_021BC2FC(void *);
extern void func_021BBD14(void *, unsigned);
extern void func_021BBD18(int, int);
extern u8 func_021BBC50(u8 *);
extern void func_021BBE7C(unsigned int object, unsigned int slot);
extern void func_021BBCB0(u8 *);
extern unsigned func_021BC6E4(void *);
extern void func_021BBDF0(unsigned int object, unsigned int slot);
extern void func_021BC490(void);
extern int func_021BC4A0(void);
extern void func_021BC50C(char *p);
extern unsigned func_021BC55C(unsigned);
extern unsigned func_021BB948(u8 *);
extern void func_021BBB60(u8 *p);
extern u32 func_021BC5B8(u32 a0, u32 a1);
extern void func_021BC688(char *);
extern void func_021BD5E0(unsigned);
extern void func_021BD56C(int *);
extern void func_021BD520(int *);
extern void func_021C09E0(unsigned);
extern void func_021C09EC(unsigned);
extern unsigned func_021BD4CC(unsigned);
extern void func_021BD370(int *);
extern void func_021BD458(int *);
extern void func_021BD3A4(u8 *);
extern void func_021BD05C(int *);
extern void func_021BCF98(int *);
extern unsigned func_021BCE5C(unsigned);
extern unsigned func_021BCF20(unsigned);
extern void func_021BCD90(u8 *);
extern void func_021BCC58(unsigned);
extern void func_021BCBCC(u8 *);
extern void func_021BCC3C(u8 *);
extern void func_021BCB60(unsigned);
extern void func_021BCB44(u8 *);
extern unsigned func_021BCAC0(u8 *);
extern void func_021BC924(int *);
extern void func_021BC8D8(u8 *);
extern void func_021BB940(void *, unsigned);
extern void func_021C0E4C(u32, u32);
extern u32 func_021C09CC(void *p);
extern void func_021C09C4(u8 *p, u32 v);
void func_021BB2B4(char *p);
void func_021BB37C(char *p);
void func_021BB484(u8 *p);
void func_021BB534(u8 *p);
void func_021BB5F4(u8 *p);
void func_021BB69C(u8 *p);
void func_021BB710(u8 *p);
void func_021BB784(struct S *p);
void func_021BB84C(u8 *p);
void func_021BB908(void *p);
void func_021BB910(u8 *a0, u32 a1);
void func_021BB91C(void *p);
u32 func_021BB928(u8 *a0);
void func_021BB934(u8 *a0, u32 a1);


void func_021BB2B4(char *p)
{
    u32 keys = func_020362DC();
    int st = func_02035C08(p + 0x58);
    if ((keys & 0x40) || (keys & 0x80) || (keys & 0x20) || (keys & 0x10) || (keys & 1)) {
        func_021BB91C(p);
        func_021BB910((unsigned char *)p, 9);
        return;
    }
    if (st == 0) {
        func_021BBA00((u32)p, 0);
        func_021BC5A8((u8 *)p, 3);
        func_021BC580(p, 5);
        func_021BB934((u8 *)p, 1);
        func_021BB91C(p);
        func_021BB910((unsigned char *)p, 12);
        return;
    }
    if (func_021BC6D0(p) != 0 || (keys & 2) || st == 1) {
        func_021BBA00((u32)p, 1);
        func_021BC5A8((u8 *)p, 3);
        func_021BC580(p, 5);
        func_020061E4(0x551);
        func_021BB91C(p);
        func_021BB910((unsigned char *)p, 11);
        func_021BB910((unsigned char *)p, 2);
    }
}


void func_021BB37C(char *p)
{
    u32 keys = func_020362DC();
    int st = func_02035C08(p + 0x58);
    if (keys & 0x40) {
        func_021BB9A0((u32)p);
    }
    if (keys & 0x80) {
        func_021BB9D0((u32)p);
    }
    if (keys & 1) {
        func_021BC5A8((u8 *)p, 3);
        func_021BC580(p, 5);
        switch (*(int *)&((struct Obj02928 *)p)->f2C) {
        case 0:
            func_021BB934((u8 *)p, 0);
            func_021BB91C(p);
            func_021BB910((unsigned char *)p, 12);
            break;
        case 1:
            func_020061E4(0x551);
            func_021BB91C(p);
            func_021BB910((unsigned char *)p, 11);
            func_021BB910((unsigned char *)p, 2);
            break;
        }
        return;
    }
    if (st == 0) {
        func_021BBA00((u32)p, 0);
        func_021BC5A8((u8 *)p, 3);
        func_021BC580(p, 5);
        func_021BB934((u8 *)p, 1);
        func_021BB91C(p);
        func_021BB910((unsigned char *)p, 12);
        return;
    }
    if (func_021BC6D0(p) != 0 || (keys & 2) || st == 1) {
        func_021BBA00((u32)p, 1);
        func_021BC5A8((u8 *)p, 3);
        func_021BC580(p, 5);
        func_020061E4(0x551);
        func_021BB91C(p);
        func_021BB910((unsigned char *)p, 11);
        func_021BB910((unsigned char *)p, 2);
    }
}

void func_021BB484(u8 *p)
{
    switch (func_021BB98C(p)) {
    case 0:
        func_021BBD28((int)p, 1);
        func_021BBD28((int)p, 0);
        func_021BC72C(p, 0, (u8 *)1);
        func_021BC72C(p, 1, (u8 *)1);
        func_021BC72C(p, 2, (u8 *)1);
        if (((struct Obj00025 *)p)->f15C == 0) {
            func_021C1038((u8 *)(*(unsigned *)(p + p[0x32] * 4 + 0xb4)), 14);
            func_021BC4B4((char *)p);
        }
        func_021BBBE4(p);
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
            func_021BB91C(p);
            func_021BB910(p, 8);
        }
        break;
    }
}

void func_021BB534(u8 *p)
{
    switch (func_021BB98C(p)) {
    case 0:
        func_021BBD14(p, 0);
        func_021BBD28((int)p, 1);
        func_021BBD18((int)p, 0);
        func_021BC580((char *)((unsigned)p), 3);
        func_021BC72C(p, 0, (u8 *)1);
        func_021BC72C(p, 1, (u8 *)1);
        func_021BC72C(p, 2, (u8 *)1);
        if (((struct Obj00025 *)p)->f15C == 0) {
            func_021C1038((u8 *)(*(unsigned *)(p + p[0x32] * 4 + 0xb4)), 14);
            func_021BC4B4((char *)p);
        }
        func_021BBBE4(p);
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
            func_021BB91C(p);
            func_021BB910(p, 10);
        }
        break;
    }
}

/*
 * arity: BB910 retains supplied r1=13 through its forwarding chain.
 */
void func_021BB5F4(u8 *p)
{
    switch (func_021BB98C(p)) {
    case 0:
        func_021BBE7C((unsigned int)p, func_021BBC50(p));
        func_021BBCB0(p);
        func_021BBDF0((unsigned int)p, func_021BC6E4(p));
        func_021BC014(p);
        func_021BC72C(p, 3, (u8 *)1);
        func_020061E4(1898);
        func_021BB990(p);
        break;
    case 1:
        if (((struct Obj00025 *)p)->f24 >= 60) {
            func_021BC490();
            func_021BB990(p);
        }
        break;
    case 2:
        if (func_021BC4A0()) {
            func_021BC50C((char *)p);
            func_021BB990(p);
        }
        break;
    case 3:
        if (func_021BC55C((unsigned)p)) {
            func_021BB91C(p);
            func_021BB910(p, 13);
        }
        break;
    }
}

/*
 * extent: 021BB70E..021BB710 is two zero bytes of alignment padding.
 * arity: BB910 visibly receives r1=13; retain it through the forwarding chain despite its one-argument legacy file.
 */
void func_021BB69C(u8 *p)
{
    switch (func_021BB98C(p)) {
    case 0:
        if (func_021BB948(p) < ((struct Obj00025 *)p)->f24) {
            func_021BC490();
            func_021BB990(p);
        }
        break;
    case 1:
        if (func_021BC4A0()) {
            func_021BC50C((char *)p);
            func_021BB990(p);
        }
        break;
    case 2:
        if (func_021BC55C((unsigned)p)) {
            func_021C1038((u8 *)(*(unsigned *)(p + p[0x32] * 4 + 0xb4)), 15);
            func_021BB91C(p);
            func_021BB910(p, 13);
        }
        break;
    }
}

/*
 * extent: 021BB782..021BB784 is two zero bytes of alignment padding.
 * arity: BB910 visibly receives r1=13; retain it through the forwarding chain despite its one-argument legacy file.
 */
void func_021BB710(u8 *p)
{
    switch (func_021BB98C(p)) {
    case 0:
        if (func_021BB948(p) < ((struct Obj00025 *)p)->f24) {
            func_021BC490();
            func_021BB990(p);
        }
        break;
    case 1:
        if (func_021BC4A0()) {
            func_021BC50C((char *)p);
            func_021BB990(p);
        }
        break;
    case 2:
        if (func_021BC55C((unsigned)p)) {
            func_021C1038((u8 *)(*(unsigned *)(p + p[0x32] * 4 + 0xb4)), 15);
            func_021BB91C(p);
            func_021BB910(p, 13);
        }
        break;
    }
}


void func_021BB784(struct S *p)
{
    switch (func_021BB98C(p)) {
    case 0:
        func_021BBB60((u8 *)p);
        func_021BB990(p);
        break;
    case 1:
        func_021BC2D8(p);
        func_021BC338((u8 *)p);
        func_021BC43C((u8 *)p);
        func_021BC168((unsigned int)p);
        func_021BC014((u8 *)p);
        func_021BBF60((u8 *)p);
        if (func_021BC2FC(p) != 0) {
            func_021BB990(p);
        }
        break;
    case 2:
        if (func_021BC5B8((u32)p, 5) != 0) {
            func_021BC72C((u8 *)p, 0, 0);
            func_021BC72C((u8 *)p, 1, 0);
            func_021BC72C((u8 *)p, 2, 0);
            func_021BBF60((u8 *)p);
            func_021BC50C((char *)p);
            func_021BB990(p);
        }
        break;
    case 3:
        if (func_021BC55C((u32)p) != 0) {
            func_021C1038(p->arr[p->f32], 15);
            func_021BB91C(p);
        }
        break;
    }
}

/*
 * volatile: DISPCNT read at 021BB8FA and write at 021BB900.
 * arity: C09E0/C09EC overwrite r1 before their indexed targets; BD3A4 overwrites r1=300; BCC58/BCB60 overwrite r1/r2 before 02040DA8. Omit only unused legacy trailing inputs, retain each visibly supplied context and BB910 r1=14.
 */
void func_021BB84C(u8 *p)
{
    func_021BC688((char *)p);
    func_021BD5E0((unsigned)p);
    func_021BD56C((int *)p);
    func_021BD520((int *)p);
    func_021C09E0(*(unsigned *)p);
    func_021C09EC(*(unsigned *)p);
    func_021BD4CC((unsigned)p);
    func_021BD370((int *)p);
    func_021BD458((int *)p);
    func_021BD3A4(p);
    func_021BD05C((int *)p);
    func_021BCF98((int *)p);
    func_021BCE5C((unsigned)p);
    func_021BCF20((unsigned)p);
    func_021BCD90(p);
    func_021BCC58((unsigned)p);
    func_021BCBCC(p);
    func_021BCC3C(p);
    func_021BCB60((unsigned)p);
    func_021BCB44(p);
    func_021BCAC0(p);
    func_021BC924((int *)p);
    func_021BC8D8(p);
    func_021BB940(p, 0);
    func_021BB91C(p);
    func_021BB910(p, 14);
    ((struct Obj00025 *)p)->f164 = 1;
    *(volatile unsigned *)0x04000000 &= 0xffff1fff;
}


void func_021BB908(void *p)
{
    u32 *c = (u32 *)((char *)p + 0x24);
    *c += 1;
}


void func_021BB910(u8 *a0, u32 a1)
{
    func_021C0E4C((u32)(((struct Obj25844 *)a0)->f18), a1);
}


/*
 * Set the u32 at +0x158 to 1.
 *
 * Addresses are Black-image addresses.
 */
void func_021BB91C(void *p)
{
    ((struct Obj25845 *)p)->f158 = 1;
}


/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0)) to func_021C09CC.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BB928(u8 *a0)
{
    return func_021C09CC((void *)((u32)(((struct Obj25846 *)a0)->f0)));
}


void func_021BB934(u8 *a0, u32 a1)
{
    func_021C09C4(*(u8 * *)&((struct Obj02928 *)a0)->f0, a1);
}
