/*
 * file:     queue_p06.c
 * unit:     yes
 * function: func_021C0B74, func_021C0B8C, func_021C0B94, func_021C0BA8, func_021C0BB4, func_021C0BBC, func_021C0C2C, func_021C0C38, func_021C0C40, func_021C0C50, func_021C0C5C, func_021C0CC8, func_021C0CF0, func_021C0CF8, func_021C0D08, func_021C0D14, func_021C0D2C, func_021C0D38, func_021C0D5C, func_021C0D6C, func_021C0D7C, func_021C0D88, func_021C0DB4
 * address:  0x021C0B74
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
 *   func_0204B1CC  0x0204B1CC  arm
 *   d_021C3F80 0x021C3F80 data a4
 *   func_021C0DBC 0x021C0DBC thumb ov217
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_02021540  0x02021540  thumb
 *   func_0202155C 0x0202155C thumb
 *   func_020216D4 0x020216D4 thumb
 *   func_020215A0  0x020215A0  thumb
 *   func_021C29C8  0x021C29C8  thumb  ov217
 *   func_021C29D8  0x021C29D8  thumb  ov217
 *   func_021C29E8  0x021C29E8  thumb  ov217
 *   func_021C2A08  0x021C2A08  thumb  ov217
 *   func_021C29F8  0x021C29F8  thumb  ov217
 *   d_021C3F5C     0x021C3F5C  data   a4
 *   d_021C3F60     0x021C3F60  data   a1
 *   func_021C2A00  0x021C2A00  thumb  ov217
 *   func_021C29F0  0x021C29F0  thumb  ov217
 *   d_021C3F48  0x021C3F48  data  a1
 */
#include "../../matched/include/Obj10964.h"
#include "../../matched/include/Obj25985.h"
#include "../../matched/include/Obj00791.h"
#include "../../matched/include/Obj25986.h"
#include "../../matched/include/Obj25987.h"
#include "../../matched/include/Obj25988.h"
#include "../../matched/include/Obj25989.h"
#include "../../matched/include/Obj25990.h"
#include "../../matched/include/Obj25992.h"
#include "../../matched/include/Obj25993.h"
#include "../../matched/include/Obj25994.h"
#include "../../matched/include/Obj25995.h"

struct Bank;
struct Obj;
struct PalAnmSlot;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

struct Arg { s16 x,y,z; u8 a,b; };

struct Entry { s16 x,y,z; u8 a,b; u32 c,d,e,f; u16 g,pad; };

extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern u32 func_0204AFD8();
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern u32 func_0204B1CC(struct Bank *bank);
extern u32 func_021C0DBC(void *, u32);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B3DC(struct Obj *, u32);
extern void func_0204B3B4(struct Obj *p);
extern void *func_02021518(u32 heap);
extern u32 func_02021540(void *a0);
extern void func_0202155C(struct PalAnmSlot *, u32, u32, u32);
extern void func_020216D4(struct PalAnmSlot *, u32, u32, u32);
extern void func_020215A0(struct PalAnmSlot *slots, u32 idx);
extern u32 func_021C29C8(u32 a0);
extern u32 func_021C29D8(void *a0);
extern u32 func_021C29E8();
extern int func_021C2A08(char *p);
extern void func_021C29F8(u8 *p, u32 b, u16 c);
extern void func_021C2A00(u32);
extern void func_021C29F0(u32);
u32 func_021C0B74(u32 a0);
void func_021C0B8C(void *p);
void func_021C0B94(u32 a0);
void func_021C0BA8(u8 *a0);
void func_021C0BB4(void *p);
void func_021C0BBC(u8 *p);
void func_021C0C2C(u8 *a0);
void func_021C0C38(void *p);
void func_021C0C40(u32 a0);
void func_021C0C50(u8 *a0);
void func_021C0C5C(u8 *p);
void func_021C0CC8(int *p);
void func_021C0CF0(void *p);
void func_021C0CF8(u32 a0);
void func_021C0D08(u8 *a0);
u32 func_021C0D14(u8 *a0);
void func_021C0D2C(u8 *a0);
void func_021C0D38(u8 *p, u32 i);
void func_021C0D5C(u8 *p, u32 i);
void func_021C0D6C(u8 *p, u32 i);
void func_021C0D7C(u32 *p);
void func_021C0D88(u8 *p);
u32 func_021C0DB4(void *p, u32 i);
extern const struct Entry d_021C3F80;
extern u8 d_021C3F5C[];
extern u8 d_021C3F60[];
extern const u8 d_021C3F48[];

/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C0B74(u32 a0)
{
    func_0204A8D4(((struct Obj10964 *)(((u8*)a0)))->f14);
    func_0204ADA4(((struct Obj10964 *)(((u8*)a0)))->f18);
    return func_0204AFD8(((struct Obj10964 *)(((u8*)a0)))->f1C);
}


/*
 * Clear the u32 at +0x20.
 *
 * Addresses are Black-image addresses.
 */
void func_021C0B8C(void *p)
{
    ((struct Obj25985 *)p)->f20 = 0;
}

/*
 * Reconstructed from the listing.
 *
 * Addresses are Black-image addresses.
 */
void func_021C0B94(u32 a0)
{
    ((struct Obj00791 *)(((u8*)a0 + 0)))->f20 = (u32)func_0204B100(1, 2, ((struct Obj00791 *)((u8*)a0))->f0);
}


/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 32)) to func_0204B1CC.
 *
 * Addresses are Black-image addresses.
 */
void func_021C0BA8(u8 *a0)
{
    func_0204B1CC((struct Bank *)((u32)(((struct Obj25986 *)a0)->f20)));
}


void func_021C0BB4(void *p)
{
    ((struct Obj25987 *)p)->f24 = 0;
}

/*
 * prototype: DBC reads only r0/r1; original r2 was an earlier local-store base, not a live reader input. B294 caller observes r0 despite legacy void return.
 */
void func_021C0BBC(u8 *p)
{
    struct Arg arg;
    u32 a,b,c,d;
    arg.x=d_021C3F80.x; arg.y=d_021C3F80.y; arg.z=d_021C3F80.z;
    arg.a=d_021C3F80.a; arg.b=d_021C3F80.b;
    a=func_021C0DBC(p,d_021C3F80.c);
    b=func_021C0DB4(p,d_021C3F80.d);
    c=func_021C0DB4(p,d_021C3F80.e);
    d=func_021C0DB4(p,d_021C3F80.f);
    *(u32 *)&((struct Obj00791 *)p)->f24=(u32)func_0204B294((void *)a,b,c,d,&arg,d_021C3F80.g,((struct Obj00791 *)p)->f0);
    func_0204B3DC(*(struct Obj * *)&((struct Obj00791 *)p)->f24,1);
}


/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 36)) to func_0204B3B4.
 *
 * Addresses are Black-image addresses.
 */
void func_021C0C2C(u8 *a0)
{
    func_0204B3B4((struct Obj *)((u32)(((struct Obj25988 *)a0)->f24)));
}


void func_021C0C38(void *p)
{
    ((struct Obj25989 *)p)->f28 = 0;
}

void func_021C0C40(u32 a0)
{
    *(u32 *)&((struct Obj00791 *)(((u8*)a0 + 0)))->f28 = (u32)func_02021518(((struct Obj00791 *)((u8*)a0))->f0);
}

void func_021C0C50(u8 *a0)
{
    func_02021540((void *)(((struct Obj25990 *)(((u8*)a0)))->f28));
}

void func_021C0C5C(u8 *p)
{
    struct PalAnmSlot *slots = *(struct PalAnmSlot * *)&((struct Obj00791 *)p)->f28;
    func_0202155C(slots, 0, 512, ((struct Obj00791 *)p)->f0);
    func_0202155C(slots, 2, 512, ((struct Obj00791 *)p)->f0);
    func_0202155C(slots, 1, 512, ((struct Obj00791 *)p)->f0);
    func_0202155C(slots, 3, 512, ((struct Obj00791 *)p)->f0);
    func_020216D4(slots, 0, 0, 512);
    func_020216D4(slots, 2, 0, 512);
    func_020216D4(slots, 1, 0, 512);
    func_020216D4(slots, 3, 0, 512);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021C0CC8(int *p)
{
    int obj;
    obj = p[10];
    func_020215A0((struct PalAnmSlot *)obj, 0);
    func_020215A0((struct PalAnmSlot *)obj, 2);
    func_020215A0((struct PalAnmSlot *)obj, 1);
    func_020215A0((struct PalAnmSlot *)obj, 3);
}


/*
 * Clear the u32 at +0x2c.
 *
 * Addresses are Black-image addresses.
 */
void func_021C0CF0(void *p)
{
    ((struct Obj25992 *)p)->f2C = 0;
}

void func_021C0CF8(u32 a0)
{
    ((struct Obj00791 *)(((u8*)a0 + 0)))->f2C = func_021C29C8(((struct Obj00791 *)((u8*)a0))->f0);
}


void func_021C0D08(u8 *a0)
{
    func_021C29D8((void *)(((struct Obj25993 *)a0)->f2C));
}

u32 func_021C0D14(u8 *a0)
{
    return func_021C29E8(((struct Obj25994 *)(((u8*)a0)))->f2C, *(u32*)(((u8*)0x21C3F50)), *(u32*)(((u8*)0x21C3F50) + 4), *(u8*)(((u8*)0x21C3F50) + 8));
}


/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 44)) to func_021C2A08.
 *
 * Addresses are Black-image addresses.
 */
void func_021C0D2C(u8 *a0)
{
    func_021C2A08((char *)((u32)(((struct Obj25995 *)a0)->f2C)));
}


/*
 * Unlabelled 22-byte ov217 leaf in a .word run; tail-calls func_021C29F8 with
 * two ov217 data-table loads indexed by i*0x14.  Middle of the
 * func_021BA31C blocker chain.
 *
 * Addresses are Black-image addresses.
 */
void func_021C0D38(u8 *p, u32 i)
{
    func_021C29F8((u8 *)(*(u32 *)(p + i * 4 + 0x2c)),
                  *(u32 *)(d_021C3F5C + i * 0x14),
                  *(u16 *)(d_021C3F60 + i * 0x14));
}

void func_021C0D5C(u8 *p, u32 i)
{
    func_021C2A00(*(u32 *)(p + i * 4 + 0x2c));
}

/*
 * Indexed getter, tail call to func_021C2A08.
 *
 * Addresses are Black-image addresses.
 */
void func_021C0D6C(u8 *p, u32 i)
{
    func_021C2A08((char *)(*(u32 *)(p + i * 4 + 0x2c)));
}

/*
 * Indexed getter, tail call to func_021C29F0.
 *
 * Addresses are Black-image addresses.
 */
void func_021C0D7C(u32 *p)
{
    func_021C29F0(p[0xb]);
}


void func_021C0D88(u8 *p)
{
    int i;
    for (i = 0; i < 2; i++) {
        p[i * 4 + 0xE] = d_021C3F48[i * 4];
        p[i * 4 + 0xF] = d_021C3F48[i * 4 + 1];
        p[i * 4 + 0xC] = d_021C3F48[i * 4 + 2];
        p[i * 4 + 0xD] = d_021C3F48[i * 4 + 3];
    }
}


/*
 * Indexed u32 read: element i of the table at +0x14.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C0DB4(void *p, u32 i)
{
    return *(u32 *)((char *)p + i * 4 + 0x14);
}
