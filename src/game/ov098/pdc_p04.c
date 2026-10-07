/*
 * file:     pdc_p04.c
 * unit:     yes
 * function: func_021B67D4, func_021B68DC
 * address:  0x021B67D4
 * region:   ov098
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02008374 0x02008374 thumb
 *   func_02013080 0x02013080 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_02041300 0x02041300 arm
 *   func_02040C14 0x02040C14 arm
 *   func_020496E4 0x020496E4 arm
 *   func_021F86E0 0x021F86E0 thumb ov094
 *   func_020215EC 0x020215EC thumb
 *   func_020450F0 0x020450F0 arm
 *   func_02045374 0x02045374 arm
 *   func_020454E0 0x020454E0 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02040588 0x02040588 arm
 *   func_021B6C34 0x021B6C34 thumb ov098
 *   d_021B6E74 0x021B6E74 data a4
 *   d_021B6E24 0x021B6E24 data a4
 *   func_02045808 0x02045808 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_020403F4 0x020403F4 arm
 *   func_02045C04 0x02045C04 arm
 *   func_020452E8 0x020452E8 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../../matched/include/Obj01704.h"
#include "../../matched/include/Obj05259.h"

struct BgTemplate;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct PalAnmSlot;
struct Cfg;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_0203FCA0(u32, const struct BgTemplate *, u32);
extern struct MsgBank *func_02045B38(u32, u32, u32, u32);
extern u32 func_02008374(int);
extern signed char func_02013080(u32);
extern struct U16Vec *func_020457B0(u32, u32);
extern struct WordSet *func_0201EC64(u32);
extern void func_02041300(u32, int, int, int, u8, u8, u8);
extern void func_02040C14(u32, u32, u32, u32);
extern u32 func_020496E4(u32, u32, u32, u32, u32, u16);
extern int func_021F86E0(void);
extern void func_020215EC(struct PalAnmSlot *, u32, u32, u32, u32, u32, u16, u16);
extern u32 func_020450F0(u32, u32, u32, u32, u8, u8, u8);
extern void func_02045374(struct Cfg *);
extern void func_020454E0(struct Cfg *, u16, u32);
extern void func_020409B4(u32);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_021B6C34(char *, int);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201ED04(void *);
extern void func_0201CE48(void *);
extern void func_020403F4(int);
extern void func_02045C04(void *);
extern void func_020452E8(void *);
extern void func_020307B0(void *);
u8 *func_021B67D4(void *a, void *b, void *c, u32 heap);
void func_021B68DC(u8 *p);
extern const char d_021B6E74[];
extern const struct BgTemplate d_021B6E24;

/*
 * prototype: 02008374's three unused legacy trailing inputs omitted: full getter reads only r0, no forwarding; caller supplies no new values.
 */
u8 *func_021B67D4(void *a, void *b, void *c, u32 heap)
{
    u8 *p;
    u32 idx;
    p = func_02030734(heap, 0x48, 1, d_021B6E74, 0x82);
    func_0203FCA0(1, &d_021B6E24, 0);
    ((struct Obj01704 *)p)->f44 = heap;
    ((struct Obj01704 *)p)->f28 = c;
    *(struct MsgBank * *)&((struct Obj01704 *)p)->f20 = func_02045B38(0, 2, 0x56, ((struct Obj01704 *)p)->f44);
    ((struct Obj01704 *)p)->f24 = a;
    ((struct Obj01704 *)p)->f34 = func_02013080(func_02008374((int)b));
    *(struct U16Vec * *)&((struct Obj01704 *)p)->f2C = func_020457B0(0x100, heap);
    *(struct WordSet * *)&((struct Obj01704 *)p)->f30 = func_0201EC64(heap);
    func_02041300(1, 0, 0, 0, 32, 32, 17);
    func_02040C14(1, 0, 1, 0);
    idx = func_020496E4(11, 89, 1, 0, 0, ((struct Obj01704 *)p)->f44);
    func_020215EC((struct PalAnmSlot *)func_021F86E0(), 11, 90, ((struct Obj01704 *)p)->f44, 0, 32, 0, 0);
    *(u32 *)&((struct Obj01704 *)p)->f1C = func_020450F0(1, 1, 19, 30, 4, 0, 0);
    func_02045374(*(struct Cfg * *)&((struct Obj01704 *)p)->f1C);
    func_020454E0(*(struct Cfg * *)&((struct Obj01704 *)p)->f1C, idx, 0);
    func_020409B4(1);
    func_02040588(1, 0);
    func_021B6C34((char *)p + 4, *(int *)&((struct Obj01704 *)p)->f1C);
    return p;
}

void func_021B68DC(u8 *p) { func_02045808(((struct Obj05259 *)p)->f2C); func_0201ED04(((struct Obj05259 *)p)->f30); if (((struct Obj05259 *)p)->f0) func_0201CE48(((struct Obj05259 *)p)->f0); func_020403F4(1); func_02045C04(((struct Obj05259 *)p)->f20); func_020452E8(((struct Obj05259 *)p)->f1C); func_020307B0(p); }
