/*
 * file:     worldtrade_adapter_p37.c
 * unit:     yes
 * function: func_02201A48, func_02201A64, func_02201B18, func_02201B44, func_02201C08
 * address:  0x02201A48
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F513C  0x021F513C  thumb  ov135
 *   func_0220252C  0x0220252C  thumb  ov135
 *   func_0200FBB0  0x0200FBB0  thumb
 *   func_0200FBA0  0x0200FBA0  thumb
 *   func_0203CA04  0x0203CA04  arm
 *   func_0203C968  0x0203C968  arm
 *   func_021C866C  0x021C866C  arm
 *   func_021C86A8  0x021C86A8  arm
 *   func_021F4EC0  0x021F4EC0  thumb  ov135
 *   func_02008DF0 0x02008DF0 thumb
 *   func_0200ED48 0x0200ED48 thumb
 *   func_0200ED54 0x0200ED54 thumb
 *   func_021F72C4 0x021F72C4 thumb ov135
 *   func_02009EC8 0x02009EC8 thumb
 *   func_02009DE8 0x02009DE8 thumb
 *   func_020307B0 0x020307B0 arm
 *   memset 0x02082BCC arm
 *   func_02008494 0x02008494 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_0202EB7C 0x0202EB7C thumb
 *   func_021C89F0  0x021C89F0  arm  ov114
 */
#include "../../matched/include/Obj12237.h"
#include "../../matched/include/Obj03532.h"
#include "../../matched/include/Obj09247.h"
#include "../../matched/include/Obj06521.h"
#include "../../matched/include/Obj08195.h"
#include "../../matched/include/Obj23452.h"
#include "../../matched/include/Obj23453.h"
#include "../../matched/include/Obj23454.h"
#include "../../matched/include/Obj23455.h"
#include "../../matched/include/Obj12238.h"

struct L0200ED54;
struct Sub0200852CObj;
struct Sub02008C20Obj;
struct Sub02009D9CObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

typedef struct {
    u8 raw[0x20];
    u16 old_species;
    u16 new_species;
    u8 x;
    u8 y;
    u8 flags;
    u8 tail;
} Record;

extern void func_021C87FC(u8 *p);
extern u32 func_021C866C(u8 *p);
extern s32 func_021C86A8(void);
extern void func_021F513C(u8 *p);
extern u32 func_0220252C(u8 *p);
extern u32 func_0200FBB0(void);
extern void func_0200FBA0(void);
extern void func_0203CA04(void);
extern void func_0203C968(void);
extern void func_021F4EC0(u8 *p, u32 a, u32 b);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern void *func_0200ED48(void *);
extern void func_0200ED54(struct L0200ED54 *l, u32 val);
extern void *func_021F72C4(void *);
extern void *func_02009EC8(void *);
extern void func_02009DE8(struct Sub02009D9CObj *obj, struct Sub0200852CObj *p);
extern u32 func_020307B0(void *p);
extern void *memset(void *, int, u32);
extern void func_02008494(void *src, void *dst);
extern u32 func_02017E1C(void *, u32, u32);
extern u32 func_0202EB7C(u32 a0, u32 a1);
extern void func_021C89F0(void);
int func_02201A48(u8 *p);
int func_02201A64(u8 *p);
void func_02201B18(u8 *p);
void func_02201B44(u8 *p, void *mon, u8 *r, void *old);
int func_02201C08(char *p);


/*
 * State setter: hand over the object, latch the state word at +0x28 and clear the slot.
 */
int func_02201A48(u8 *p)
{
    func_021C87FC(p + 0xe4);
    ((struct Obj12237 *)p)->f28 = 0x1f;
    ((struct Obj12237 *)p)->fF8C = 0x0;
    return 0x2;
}


/*
 * Switch on the 0x021C86A8 index (case value = index + 15): the 0x1a guard
 * over func_0220252C with the +0x32 flag, index 12 with only the flag, the
 * +0x38/0x2b group returning 2, and the plain redraw returning 2.  The nine
 * hole indices 4..11 and 14 are LISTED as empty cases: without them the
 * compiler folds the case set into a compare chain instead of the listing's
 * 16-slot table, and the func_02201B18 call sits after the switch (every
 * break and every hole lands on it).
 * The shape is settled and every concrete byte is reproduced; the site is
 * parked because 0x021C866C / 0x021C86A8 carry no func_ label in any
 * overlay listing (see the wave-5 residue note for the one-line fix).
 *
 * UNBLOCKED: func_021C866C (0x021C866C) and func_021C86A8
 * (0x021C86A8) are now EXACT entries in layout/matched/ov114
 * (pkt_ov114_021C866C, pkt_ov114_021C86A8); both BLX sites
 * resolve as `matched`.  Verdict promoted to EXACT.
 */
int func_02201A64(u8 *p)
{
    s32 n;

    if (func_021C866C(p) != 0) {
        n = func_021C86A8();
        ((struct Obj03532 *)p)->fF8C = 0;
        switch (n + 15) {
        case 15:
            if (func_0220252C(p) != 0) {
                ((struct Obj03532 *)p)->f28 = 0x1a;
                ((struct Obj03532 *)p)->f32 = 0;
                return 2;
            }
            ((struct Obj03532 *)p)->f32 = 1;
            break;
        case 12:
            ((struct Obj03532 *)p)->f32 = 0;
            break;
        case 0:
        case 1:
        case 3:
        case 13:
            ((struct Obj03532 *)p)->f38 = n;
            ((struct Obj03532 *)p)->f28 = 0x2b;
            func_0200FBB0();
            func_0203CA04();
            func_0200FBA0();
            func_0203C968();
            return 2;
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 14:
            break;
        case 2:
            func_021F513C(p);
            return 2;
        }
        func_02201B18(p);
    } else {
        if (++((struct Obj03532 *)p)->fF8C == 0xe10) {
            func_021F513C(p);
        }
    }
    return 2;
}


/*
 * Switch on the mode word at +0x18; both arms latch state 0x28.
 */
void func_02201B18(u8 *p)
{
    switch (((struct Obj09247 *)p)->f18) {
    case 1:
        func_021F4EC0(p, 1, 0);
        ((struct Obj09247 *)p)->f28 = 0x28;
        break;
    case 2:
        func_021F4EC0(p, 2, 3);
        ((struct Obj09247 *)p)->f28 = 0x28;
        break;
    }
}

/*
 * lever: u16 local joins species branches; byte flags use explicit masked RMW.
 */
void func_02201B44(u8 *p, void *mon, u8 *r, void *old)
{
    void *copy;
    Record rec;
    u16 species;
    func_02008DF0(((struct Obj23452 *)(*(u8 * *)&((struct Obj08195 *)p)->f0))->f24, 0x10);
    func_0200ED54(func_0200ED48(((struct Obj23453 *)(*(u8 * *)&((struct Obj08195 *)p)->f0))->f3C), ((struct Obj06521 *)r)->f10C);
    copy = func_021F72C4(r);
    func_02009DE8(func_02009EC8(((struct Obj23454 *)(*(u8 * *)&((struct Obj08195 *)p)->f0))->f3C), copy);
    func_020307B0(copy);
    copy = func_021F72C4(r);
    memset(&rec, 0, sizeof(rec));
    func_02008494(copy, &rec);
    if (old != 0) species = func_02017E1C(old, 5, 0);
    else species = ((struct Obj06521 *)r)->fEC;
    rec.old_species = species;
    rec.new_species = func_02017E1C(mon, 5, 0);
    rec.x = ((struct Obj06521 *)r)->f126;
    rec.flags = (rec.flags & ~7) | (((struct Obj06521 *)r)->fF7 & 7);
    rec.y = ((struct Obj06521 *)r)->f127;
    func_0202EB7C((u32)(((struct Obj23455 *)(*(u8 * *)&((struct Obj08195 *)p)->f0))->f18), (u32)(&rec));
    func_020307B0(copy);
}


/*
 * Addresses are Black-image addresses.
 */
int func_02201C08(char *p)
{
    ((struct Obj12238 *)p)->fF8C = 0;
    func_021C89F0();
    ((struct Obj12238 *)p)->f28 = 0x2f;
    return 2;
}
