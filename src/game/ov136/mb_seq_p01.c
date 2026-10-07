/*
 * file:     mb_seq_p01.c
 * unit:     yes
 * function: func_021C6984, func_021C6A5C, func_021C6AD4, func_021C6AF0, func_021C6B4C, func_021C6BC4
 * address:  0x021C6984
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020056A0       0x020056A0  thumb
 *   func_0203064C   0x0203064C  arm
 *   func_02030734        0x02030734  arm
 *   func_02030EAC   0x02030EAC  arm
 *   func_0203D34C  0x0203D34C  arm
 *   func_02043534  0x02043534  arm
 *   func_020435F4             0x020435F4  arm
 *   func_0204363C  0x0204363C  arm
 *   func_02082AC0    0x02082AC0  arm
 *   func_021C54FC 0x021C54FC thumb
 *   func_021C5508 0x021C5508 thumb
 *   func_021C5518 0x021C5518 thumb
 *   func_021C574C 0x021C574C thumb
 *   func_021C5828 0x021C5828 thumb
 *   func_021C587C 0x021C587C thumb
 *   func_021C5924 0x021C5924 thumb
 *   func_021C59B8 0x021C59B8 thumb
 *   func_021C5B40 0x021C5B40 thumb
 *   func_021C5C00 0x021C5C00 thumb
 *   func_021C5DD8 0x021C5DD8 thumb
 *   func_021C5E58 0x021C5E58 thumb
 *   func_021C6170 0x021C6170 thumb
 *   func_021C64A8 0x021C64A8 thumb
 *   func_021C7658  0x021C7658  thumb
 *   d_021C7F04 0x021C7F04 data a1
 *   func_020307B0 0x020307B0 arm
 *   func_020306F0 0x020306F0 arm
 *   func_021C5AA8 0x021C5AA8 thumb ov136
 *   func_021C5954 0x021C5954 thumb ov136
 *   func_021C76A8 0x021C76A8 thumb ov136
 *   func_021C5E30 0x021C5E30 thumb ov136
 *   func_021C657C 0x021C657C thumb ov136
 *   func_021C5918 0x021C5918 thumb ov136
 *   func_021C5F44 0x021C5F44 thumb ov136
 *   func_021C5714 0x021C5714 thumb ov136
 *   func_021C5BE0 0x021C5BE0 thumb ov136
 *   func_020221A4  0x020221A4  thumb
 *   func_02035C60 0x02035C60 arm
 *   func_020362DC 0x020362DC arm
 *   d_021C7D68 0x021C7D68 data a4
 *   func_021C5C84  0x021C5C84  thumb
 */
#include "../../matched/include/Obj03836.h"
#include "../../matched/include/Obj04536.h"
#include "../../matched/include/Obj23607.h"
#include "../../matched/include/Obj23608.h"
#include "../../matched/include/Obj06529.h"
#include "../../matched/include/Obj23609.h"
#include "../../matched/include/Obj23610.h"
#include "../../matched/include/Obj23611.h"
#include "../../matched/include/Obj06530.h"
#include "../../matched/include/Obj23612.h"
#include "../../matched/include/Obj23613.h"
#include "../../matched/include/Obj23614.h"
#include "../../matched/include/Obj23615.h"
#include "../../matched/include/Obj23616.h"
#include "../../matched/include/Obj23617.h"

struct Node;
struct Rec3;
struct TaskMenu;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

struct Row { int (*a)(u8 *); int (*b)(u8 *); };

extern void func_02030EAC(struct Node *n);
extern void func_02043534(u32);
extern void func_020435F4(u32);
extern void func_0204363C(u32);
extern void func_0203064C(u32, u32, u32);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082AC0(u32, void *, u32);
extern void func_021C5B40(u8 *);
extern void func_021C5508(void);
extern void func_021C5518(u8 *);
extern void func_021C574C(u8 *);
extern void func_021C5828(void *a0);
extern void func_021C5E58(u8 *);
extern void func_021C587C(u8 *);
extern void func_021C64A8(u8 *);
extern void func_021C5DD8(u8 *);
extern void func_021C7658(u8 *);
extern void func_021C5924(u8 *);
extern void func_021C6170(u8 *);
extern void func_021C5C00(u8 *);
extern void func_021C59B8(u8 *);
extern void func_021C54FC(void);
extern void *func_020056A0(void (*)(void *), void *, u32);
extern void func_0203D34C(u32, u32);
extern void func_021C5AA8(u8 *);
extern void func_021C5954(u8 *p);
extern void func_021C76A8(u8 *p);
extern void func_021C5E30(u8 *p);
extern void func_021C657C(u8 *);
extern void func_021C5918(u8 *p);
extern void func_021C5F44(u8 *p);
extern void func_021C5714(void *);
extern void func_021C5BE0(u8 *p);
extern u32 func_020307B0(void *p);
extern void func_020306F0(u32);
extern u32 func_020221A4(void);
extern u32 func_0201CE30(void *p);
extern void func_0201CE48(struct Rec3 *p);
extern int func_02035C60(void);
extern u32 func_020362DC(void);
extern void func_020061E4(u32);
extern void func_02027974(void *);
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *);
extern void func_02027858(struct TaskMenu *m);
extern int func_021C5C84(u8 *p);
int func_021C6984(u8 *p);
u32 func_021C6A5C(u8 *p);
int func_021C6AD4(u8 *p);
u32 func_021C6AF0(u8 *p);
int func_021C6B4C(u8 *p);
int func_021C6BC4(u8 *p);
extern const char d_021C7F04[];
extern const struct Row d_021C7D68[];

int func_021C6984(u8 *p)
{
    if (((struct Obj03836 *)p)->f2C != 0) {
        func_02030EAC(((struct Obj03836 *)p)->f2C);
        *(u32 *)&((struct Obj03836 *)p)->f2C = 0;
    }
    func_02043534(0);
    func_020435F4(0);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    func_0204363C(0);
    func_0203064C(1, 0x66, 0x60000);
    ((struct Obj03836 *)p)->f8 = func_02030734(0x66, 0x370, 0, d_021C7F04, 0x10C);
    func_02082AC0(0, ((struct Obj03836 *)p)->f8, 0x370);
    func_021C5B40(p);
    func_021C5508();
    func_021C5518(p);
    func_021C574C(p);
    func_021C5828(p);
    func_021C5E58(p);
    func_021C587C(p);
    func_021C64A8(p);
    func_021C5DD8(p);
    func_021C7658(p);
    func_021C5924(*(u8 * *)&((struct Obj03836 *)p)->f8);
    func_021C6170(p);
    func_021C5C00(p);
    func_021C59B8(p);
    ((struct Obj03836 *)p)->f2C = func_020056A0((void (*)(void *))func_021C54FC, p, 1);
    func_0203D34C(0, 0x66);
    return ((struct Obj03836 *)p)->f28;
}

u32 func_021C6A5C(u8 *p)
{
    if (((struct Obj04536 *)p)->f2C != 0) {
        func_02030EAC(((struct Obj04536 *)p)->f2C);
        ((struct Obj04536 *)p)->f2C = 0;
    }
    func_021C5AA8(p);
    func_021C5954(((struct Obj04536 *)p)->f8);
    func_021C76A8(p);
    func_021C5E30(p);
    func_021C657C(p);
    func_021C5918(p);
    func_021C5F44(p);
    func_021C5714(p);
    func_021C5BE0(p);
    *(u16 *)0x04000050 = 0;
    *(u16 *)0x04001050 = 0;
    func_02043534(0);
    func_020435F4(0);
    func_020307B0(((struct Obj04536 *)p)->f8);
    ((struct Obj04536 *)p)->f8 = 0;
    func_020306F0(102);
    return ((struct Obj04536 *)p)->f28;
}


/*
 * Addresses are Black-image addresses.
 */
int func_021C6AD4(u8 *p)
{
    if (func_020221A4() == 1)
        return ((struct Obj23608 *)((u8 *)((struct Obj23607 *)p)->f8))->f308;
    return 2;
}

u32 func_021C6AF0(u8 *p)
{
    if (func_0201CE30(((struct Obj23609 *)(*(u8 * *)&((struct Obj06529 *)p)->f8))->f1C8) == 2) {
        if ((*(u8 **)(p + 8))[0x1dd] == 0) {
            func_0201CE48(((struct Obj23610 *)(*(u8 * *)&((struct Obj06529 *)p)->f8))->f1C8);
            return ((struct Obj06529 *)p)->f28;
        }
        if (func_02035C60() == 1 || (func_020362DC() & 3) != 0) {
            func_0201CE48(((struct Obj23611 *)(*(u8 * *)&((struct Obj06529 *)p)->f8))->f1C8);
            func_020061E4(1352);
            return ((struct Obj06529 *)p)->f28;
        }
    }
    return 3;
}

int func_021C6B4C(u8 *p)
{
    func_02027974(((struct Obj23612 *)(*(u8 * *)&((struct Obj06530 *)p)->f8))->f310);
    if (func_020279E8(((struct Obj23613 *)(*(u8 * *)&((struct Obj06530 *)p)->f8))->f310) == 0) return 4;
    switch (func_02027A04(*(u8 * *)&((struct Obj23614 *)(*(u8 * *)&((struct Obj06530 *)p)->f8))->f310)) {
    case 0:
        func_02027858(((struct Obj23615 *)(*(u8 * *)&((struct Obj06530 *)p)->f8))->f310);
        return d_021C7D68[*(int *)(*(u8 **)(p + 8) + 0x1E0)].a(p);
    case 1:
        func_02027858(((struct Obj23616 *)(*(u8 * *)&((struct Obj06530 *)p)->f8))->f310);
        return d_021C7D68[*(int *)(*(u8 **)(p + 8) + 0x1E0)].b(p);
    }
    return 4;
}


int func_021C6BC4(u8 *p)
{
    if (func_021C5C84(p) == 0)
        return ((struct Obj23617 *)p)->f28;
    return 5;
}
