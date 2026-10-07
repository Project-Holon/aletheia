/*
 * file:     pokemontrade_demo_up_p10.c
 * unit:     yes
 * function: func_021D6750, func_021D67D4, func_021D67F8
 * address:  0x021D6750
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021E3BB0  0x021E3BB0  thumb  ov119
 *   func_021E3230  0x021E3230  thumb  ov119
 *   func_021D8A24  0x021D8A24  thumb  ov119
 *   func_020399A8  0x020399A8  arm
 *   func_02039C68  0x02039C68  arm
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021D6544  0x021D6544  thumb  ov118
 *   func_02039CB4  0x02039CB4  arm
 *   func_021D6738  0x021D6738  thumb  ov118
 *   func_02030734  0x02030734  arm
 *   func_021D6734  0x021D6734  thumb  ov118
 *   func_021DFD24  0x021DFD24  thumb  ov119
 *   func_021DFB84  0x021DFB84  thumb  ov119
 *   func_02015F2C  0x02015F2C  thumb
 *   func_021DFD0C  0x021DFD0C  thumb  ov119
 *   func_02015F50  0x02015F50  thumb
 *   func_021E106C  0x021E106C  thumb  ov119
 *   func_02040EBC  0x02040EBC  arm
 *   func_021D6918  0x021D6918  thumb  ov118
 *   d_021D8650     0x021D8650  data
 *   d_021D7CC4     0x021D7CC4  data
 *   d_021D7CD0     0x021D7CD0  data
 */
#include "../../matched/include/Obj00001.h"

#define OBJ(i) (((u32 *)(p + 0x844))[i])
#define HEAP (*(u16 *)(p + 0x5F4))
#define SLOT0 (*(u32 *)(p + 0x85C))
#define SLOT1 (*(u32 *)(p + 0x860))
#define FADE (*(s8 **)(p + 0x818))
struct Entry;
struct Link;
struct McssFade;
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef signed char s8;

typedef int s32;

typedef struct {
    s32 x, y, z;
} Vec;

extern void func_021E3BB0(char *p);
extern void func_021E3230(void *p);
extern int func_021D8A24(void *p);
extern struct Entry *func_020399A8(void);
extern void func_02039C68(struct Link *h, u32 a, u32 b);
extern void func_021D8E84(void *p, int next);
extern void func_021D6544(u8 *p, u8 *outSame, u8 *outFlag, u32 key, int enemy);
extern u32 func_02039CB4(struct Link *h, u32 a, u32 b);
extern void func_021D6738(u8 *p, u32 v);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_021D6734(int);
extern void func_021DFD24(u32 *p);
extern void *func_021DFB84(void *a0, void *a1, void *a2, u32 heapId);
extern void func_02015F2C(u32 obj, void *arg, void (*cb)(void), int a);
extern void func_021DFD0C(char *p);
extern void func_02015F50(struct McssFade *w, u32 cur, u32 target, s32 step, u32 e);
extern void func_021E106C(char *p);
extern void func_02040EBC(u32 a0, u32 a1);
extern void func_021D6918(u8 *p);
void func_021D6750(u8 *p);
void func_021D67D4(u8 *p);
void func_021D67F8(u8 *p);
extern const char d_021D8650[];
extern const Vec d_021D7CC4;
extern const Vec d_021D7CD0;


/*
 * Addresses are Black-image addresses.
 */
void func_021D6750(u8 *p)
{
    func_021E3BB0((char *)p);
    if (((struct Obj00001 *)p)->f854 == 1) {
        func_021D6544(p, p + 0x11ED, p + 0x11EF, ((struct Obj00001 *)p)->f834, 1);
        func_021D6544(p, p + 0x11EE, p + 0x11F0, ((struct Obj00001 *)p)->f830, 0);
        func_021E3230(p);
        if (func_021D8A24(p) != 0) {
            func_02039C68((struct Link *)func_020399A8(), 0x11, 8);
            func_021D8E84(p, (int)func_021D67D4);
        } else {
            func_021D8E84(p, (int)func_021D67F8);
        }
    }
}


void func_021D67D4(u8 *p)
{
    if (func_02039CB4((struct Link *)func_020399A8(), 0x11, 8) != 0) {
        func_021D8E84(p, (int)func_021D67F8);
    }
}


void func_021D67F8(u8 *p)
{
    Vec a;
    Vec b;

    func_021D6738(p, 0);
    FADE = func_02030734(HEAP, 4, 1, d_021D8650, 0xF5);
    FADE[0] = func_021D6734(0xE);
    FADE[1] = 0;
    FADE[2] = 0;
    FADE[3] = -0x10;
    a = d_021D7CC4;
    func_021DFD24((u32 *)SLOT0);
    SLOT0 = (u32)func_021DFB84((void *)OBJ(0), (void *)func_021D6734(0x2A), &a, HEAP);
    b = d_021D7CD0;
    func_021DFD24((u32 *)SLOT1);
    SLOT1 = (u32)func_021DFB84((void *)OBJ(1), (void *)func_021D6734(0x54), &b, HEAP);
    func_02015F2C(OBJ(0), p, (void (*)(void))func_021DFD0C, 1);
    func_02015F50((struct McssFade *)OBJ(1), 0, 0x10, (s8)(func_021D6734(0xE) / 16), 0);
    func_021E106C((char *)p);
    func_02040EBC(1, 0);
    func_02040EBC(5, 0);
    func_021D6738(p, 0);
    func_021D8E84(p, (int)func_021D6918);
}
