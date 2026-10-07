/*
 * file:     ui_scene_p17.c
 * unit:     yes
 * function: func_021B9394, func_021B9398, func_021B93A4, func_021B93B0, func_021B93B8, func_021B93C0, func_021B93D4
 * address:  0x021B9394
 * region:   ov067
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B92F0  0x021B92F0  thumb  ov067
 */
#include "../../matched/include/Obj20627.h"
#include "../../matched/include/Obj20628.h"
#include "../../matched/include/Obj13135.h"
#include "../../matched/include/Obj20629.h"
#include "../../matched/include/Obj20630.h"
#include "../../matched/include/Obj13136.h"

typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef signed short s16;

struct Ops {
    void *f0;
    void (*f4)(void *obj, int pos, int flag);
};

struct S {
    u8 _0[0x20];
    struct Ops *f20;
    void *f24;
    u8 _28[0x5c - 0x28];
    s16 f5c;
    u8 _5e[0x60 - 0x5e];
    s16 f60;
    s16 f62;
};

extern void func_021B92F0(struct S *p, u32 a1, u32 a2);
unsigned func_021B9394(char *p);
u32 func_021B9398(char *p, int index);
int func_021B93A4(char *p);
int func_021B93B0(char *p);
int func_021B93B8(char *p);
int func_021B93C0(char *p);
void func_021B93D4(struct S *s, int v);
void func_021B940C(struct S *s);
void func_021B941C(struct S *s);

/*
 * extent: four-byte getter; next leaf 021B9398 belongs to S27, not this file.
 */
unsigned func_021B9394(char *p)
{
    return ((struct Obj20627 *)p)->f34;
}

/*
 * trailing: 2-byte alignment padding; separate existing functions follow
 */
u32 func_021B9398(char *p, int index)
{
    return *(u32 *)(*(char * *)&((struct Obj20628 *)p)->f28 + index * 8 + 4);
}

/*
 * Caller ov209 021BCE98 reads the signed sum. ov067 is loaded by
 * ov209 021BCC94 and unloaded by 021BCD48. Following code starts at 021B93B0.
 */
int func_021B93A4(char *p)
{
    return ((struct Obj13135 *)p)->f5C + ((struct Obj13135 *)p)->f62;
}


/*
 * Unlabelled leaf in ov067, printed as a .word run; signed halfword getter.
 * Blocker target of ov210's func_021BF728 (pkt_021BF728), reached across the
 * ov210/ov067 overlay pair.
 */
int func_021B93B0(char *p)
{
    return ((struct Obj20629 *)p)->f5C;
}


int func_021B93B8(char *p)
{
    return ((struct Obj20630 *)p)->f62;
}


/*
 * Unlabelled leaf in ov067, printed as a .word run: true when the signed
 * halfword at +0x62 is below the unsigned halfword at +0x64.  Blocker target
 * of ov210's func_021BF728 (pkt_021BF728), across the ov210/ov067 pair.
 */
int func_021B93C0(char *p)
{
    return ((struct Obj13136 *)p)->f62 < ((struct Obj13136 *)p)->f64;
}


void func_021B93D4(struct S *s, int v)
{
    s->f60 = s->f5c;
    s->f5c = v;
    func_021B92F0(s, (u16)s->f5c, (u16)s->f60);
    s->f20->f4(s->f24, s->f5c + s->f62, 1);
}


void func_021B940C(struct S *s)
{
    func_021B92F0(s, (u16)s->f5c, (u16)0xff);
}


/*
 * The handed 460-byte extent is this 56-byte function, two unlabelled
 * 16-byte tail-call stubs into func_021B92F0 (0x021B940C, 0x021B941C), and
 * rodata from 0x021B942C on. tu reproduces 0x021B93D4..0x021B942C.
 */
void func_021B941C(struct S *s)
{
    func_021B92F0(s, (u16)0xff, (u16)s->f5c);
}
