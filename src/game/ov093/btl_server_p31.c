/*
 * file:     btl_server_p31.c
 * unit:     yes
 * function: func_021C001C, func_021C024C, func_021C0274, func_021C02CC, func_021C031C, func_021C03AC, func_021C03D8, func_021C0404, func_021C0450, func_021C0520, func_021C0780, func_021C07AC, func_021C07D4
 * address:  0x021C001C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201BEB8 0x0201BEB8 thumb
 *   func_0201C314 0x0201C314 thumb
 *   func_021D62A8 0x021D62A8 thumb ov093
 *   func_021D5778 0x021D5778 thumb ov093
 *   func_021D5584 0x021D5584 thumb ov093
 *   func_021D5BB0 0x021D5BB0 thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021D6314 0x021D6314 thumb ov093
 *   func_021E8B80 0x021E8B80 thumb ov093
 *   func_021EF948 0x021EF948 thumb ov093
 *   func_021D67B8 0x021D67B8 thumb ov093
 *   func_021D67A8 0x021D67A8 thumb ov093
 *   func_021EF91C 0x021EF91C thumb ov093
 *   func_021D7AF0 0x021D7AF0 thumb ov093
 *   func_021C5480 0x021C5480 thumb ov093
 *   func_021C557C 0x021C557C thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021CD64C 0x021CD64C thumb ov093
 *   func_021D74F8  0x021D74F8  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D7630  0x021D7630  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 *   func_021D61A8  0x021D61A8  thumb  ov093
 *   func_021C5620  0x021C5620  thumb  ov093
 *   func_021C54C8  0x021C54C8  thumb  ov093
 *   func_021C54FC  0x021C54FC  thumb  ov093
 *   func_021D6130  0x021D6130  thumb  ov093
 *   func_021C63D0 0x021C63D0 thumb ov093
 *   func_021C4F64 0x021C4F64 thumb ov093
 *   func_021BC2B0 0x021BC2B0 thumb ov093
 *   func_021D7D18 0x021D7D18 thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021C5C1C 0x021C5C1C thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021C6564 0x021C6564 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   func_021D78AC 0x021D78AC thumb ov093
 *   func_021C5604 0x021C5604 thumb ov093
 *   func_021D69A0  0x021D69A0  thumb  ov093
 *   func_021C0898 0x021C0898 thumb ov093
 *   func_021C0868  0x021C0868  thumb  ov093
 *   func_021C0878  0x021C0878  thumb  ov093
 *   func_021C0888  0x021C0888  thumb  ov093
 *   func_021D75A8  0x021D75A8  thumb  ov093
 */
#include "../../matched/include/Obj04359.h"
#include "../../matched/include/Obj04359.h"
#include "../../matched/include/Obj00003.h"

struct QL;
struct Unk021D62A8;
struct UtilWork;
union Slot_021C024C;
struct UtilSlots;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

union Slot_021C001C {
    struct { u32 kind:3; u32 pad:6; u32 id:16; u32 rest:7; } a;
    struct { u32 kind:3; u32 pad:12; u32 id:16; u32 rest:1; } b;
};

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

union Slot_021C024C { u32 raw; struct { u32 kind:3; u32 lo:6; u32 hi:6; u32 rest:17; } s; };

struct Lock { u32 a:10; u32 b:9; u32 c:9; u32 d:1; u32 e:1; u32 f:1; u32 g:1; };

extern int func_021D62A8(struct Unk021D62A8 *p);
extern u8 func_021D5778(struct UtilWork *p, u16 id);
extern u8 func_021D5584(struct UtilWork *p, u32 i);
extern int func_021D5BB0(struct UtilWork *p, u32 n);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern union Slot_021C001C func_021D6314(void *, int);
extern u16 func_021E8B80(union Slot_021C001C);
extern int func_0201BEB8(void *bag, int item);
extern int func_021EF948(int);
extern u16 func_021D67B8(u8 *);
extern u16 func_021D67A8(struct QL *p);
extern u32 func_0201C314(void *p);
extern int func_021EF91C(void *, u8 *, u16);
extern int func_021D7AF0(u32);
extern void func_021C5480(u8 *, u8 *, int);
extern void func_021C557C(u8 *, u8 *, int, int);
extern u8 func_021D5440(u8 *);
extern void func_021CD64C(void *, u8, ...);
extern void func_021D74F8(int line);
extern void func_021D75EC(int key, u32 val);
extern void func_021D7630(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern int func_021D775C(int key);
extern void func_021D7540(int line);
extern int func_021D61A8(struct UtilSlots *p);
extern void func_021C5620(u8 *p, u8 *a, int k, union Slot_021C024C *out);
extern void func_021C54C8(u8 *p, u8 *a);
extern void func_021C54FC(u8 *p, u8 *a);
extern int func_021D6130(struct UtilSlots *p);
extern u32 func_021C63D0(u8 *, u8 *);
extern int func_021C4F64(u8 *, u8 *);
extern int func_021BC2B0(u8 *);
extern union Slot_021C024C func_021D7D18(int);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021C5C1C(u8 *, u8 *, int, union Slot_021C024C);
extern u32 func_021CC8D8(void *, int);
extern void func_021C6564(u8 *, u8 *, u32, u32);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern u32 func_021D78AC(u32 range);
extern void func_021C5604(u8 *p, u8 *a, int b);
extern void func_021D69A0(u8 *base, int idx, u8 val);
extern int func_021C0898(u8 *, u8 *, u32, u32);
extern u32 func_021C0868(int e);
extern u8 *func_021C0878(int e, int i);
extern u8 *func_021C0888(int e, int i);
extern void func_021D75A8(int key, u32 val);
int func_021C001C(u8 *p, u8 *a, u16 c, u16 d);
int func_021C024C(u8 *p, u8 *a, u16 c);
int func_021C0274(u8 *p, u8 *a, u32 c, u32 d);
int func_021C02CC(u8 *p, u8 *a, u32 c, int k);
int func_021C031C(u8 *p, u8 *a);
int func_021C03AC(u8 *p, u8 *a);
void func_021C03D8(u8 *p, u8 *a, u16 a2);
int func_021C0404(u8 *p, u8 *a, void *bag);
void func_021C0450(u8 *p, u8 *q, u16 c, int k);
void func_021C0520(u8 *p, u8 *a, u16 b, u32 c);
void func_021C0780(u8 *p, u8 *a, int i, u8 v);
int func_021C07AC(u8 *p, u8 *a, u16 c, u16 d, int e);
int func_021C07D4(u8 *p, u8 *a, u16 c, u16 d, int e);


/*
 * lever: Naming the one-word union result before passing it restores the original frame.
 * Symbol hints retain the Thumb ISA of the two already-matched ARM9 callees.
 */
int func_021C001C(u8 *p, u8 *a, u16 c, u16 d)
{
    int mode;
    int changed = 0;
    int reason;
    union Slot_021C001C move;
    func_021C03D8(p, a, c);
    mode = func_021D62A8((struct Unk021D62A8 *)a);
    if (mode == 2) {
        reason = 2;
        if (func_021C0274(p, a, c, 2) == 0) goto done;
    }
    changed = func_021C0404(p, a, (void *)c);
    mode = func_021D62A8((struct Unk021D62A8 *)a);
    if (mode == 3 && changed == 0) { reason = 4; goto done; }
    if (((struct Obj04359 *)p)->f1F78 == 4) { reason = 22; goto done; }
    if (((struct Obj04359 *)p)->f1F78 == 2) { reason = 23; goto done; }
    if (d == 0) {
        int index = func_021D5778((struct UtilWork *)a, c);
        if (index != 4 && func_021D5584((struct UtilWork *)a, index) == 0) { reason = 1; goto done; }
    }
    reason = func_021C02CC(p, a, c, 30);
    if (reason) goto done;
    if (func_021D5BB0((struct UtilWork *)a, 6)) { reason = 7; goto done; }
    if (func_021D5BB0((struct UtilWork *)a, 4)) { reason = 6; goto done; }
    if (func_021D62C4((struct Unk021D62A8 *)a, 13) && c != 165) {
        move = func_021D6314(a, 13);
        if (c == func_021E8B80(move)) { reason = 9; goto done; }
    }
    if (func_021D62C4((struct Unk021D62A8 *)a, 15) && (u32)func_0201BEB8((void *)c, (int)12)) { reason = 13; goto done; }
    if (func_021EF948(2) && (u32)func_0201BEB8((void *)c, (int)9)) { reason = 20; goto done; }
    if (c != 165) {
        if (func_021D62C4((struct Unk021D62A8 *)a, 23)) {
            u16 id = func_021D67B8(a);
            if (id != 165 && id != c) { reason = 17; goto done; }
        }
        if (func_021D62C4((struct Unk021D62A8 *)a, 25) && c != func_021D67A8((struct QL *)a)) { reason = 17; goto done; }
        if (func_021D62C4((struct Unk021D62A8 *)a, 11) && func_0201C314((void *)c) == 0) { reason = 10; goto done; }
        if (func_021EF948(3) && func_021EF91C(((struct Obj04359 *)p)->f8, a, c)) { reason = 12; goto done; }
    }
    if (func_021C031C(p, a)) { reason = 5; goto done; }
    if (mode == 1 && func_021D7AF0(25)) { reason = 3; goto done; }
    if (func_021C03AC(p, a)) reason = 8;
done:
    if (reason) {
        func_021C0450(p, a, c, reason);
        return 1;
    }
    if (mode == 2) {
        func_021C0520(p, a, c, 2);
        func_021C5480(p, a, 598);
    } else if (changed && mode == 3) {
        func_021C557C(p, a, mode, 0);
        func_021CD64C(((struct Obj04359 *)p)->fC, 91, 303, func_021D5440(a), c, 0xffff0000);
    }
    return 0;
}





/*
 * lever: Wide third extern argument preserves the full r2 passed by the image.
 */
int func_021C024C(u8 *p, u8 *a, u16 c)
{
    int result;
    if (c != 0xa5) {
        result = func_021C02CC(p, a, c, 0x1f);
        if (result != 0) {
            func_021C0450(p, a, c, result);
            return 1;
        }
    }
    return 0;
}






int func_021C0274(u8 *p, u8 *a, u32 c, u32 d)
{
    int r;
    func_021D74F8(5537);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(0x22, d);
    func_021D75EC(0x12, c);
    func_021D7630(0x41, 0);
    func_021D70F0(p, 0x1D);
    r = func_021D775C(0x41);
    func_021D7540(5544);
    return r;
}






int func_021C02CC(u8 *p, u8 *a, u32 c, int k)
{
    int r;
    func_021D74F8(5563);
    func_021D75EC(0x12, c);
    func_021D75EC(2, func_021D5440(a));
    func_021D7630(0x22, 0);
    func_021D70F0(p, k);
    r = func_021D775C(0x22);
    func_021D7540(5569);
    return r;
}





int func_021C031C(u8 *p, u8 *a)
{
    int k = 6;
    if (((struct Obj04359 *)p)->f1F78 == 3) {
        func_021CD64C(((struct Obj04359 *)p)->fC, 0x5a, 0xbc, func_021D5440(a), 0xffff0000);
        return 1;
    }
    if (func_021D62C4((struct Unk021D62A8 *)a, k) != 0) {
        if (func_021D61A8((struct UtilSlots *)a) != 0) {
            func_021C5620(p, a, k, 0);
            func_021CD64C(((struct Obj04359 *)p)->fC, 0x5b, 0x15f, func_021D5440(a), 0xffff0000);
            return 0;
        }
        func_021C54C8(p, a);
        return func_021D7AF0(50);
    }
    return 0;
}






int func_021C03AC(u8 *p, u8 *a)
{
    if (func_021D62C4((struct Unk021D62A8 *)a, 7) != 0) {
        func_021C54FC(p, a);
        if (func_021D7AF0(50) != 0) return 1;
    }
    return 0;
}






void func_021C03D8(u8 *p, u8 *a, u16 a2)
{
    int k = func_021D62A8((struct Unk021D62A8 *)a);
    if (k == 2 && func_021D6130((struct UtilSlots *)a) != 0) {
        func_021C557C(p, a, k, 1);
    }
}





int func_021C0404(u8 *p, u8 *a, void *bag)
{
    int k = func_021D62A8((struct Unk021D62A8 *)a);
    int f = 0;
    int r = 0;
    if (k == 3) {
        if (func_0201BEB8(bag, 10) != 0) {
            r = 1;
        } else if (func_021D7AF0(20) != 0) {
            f = 1;
        }
    }
    if (f != 0) {
        func_021C557C(p, a, k, 1);
    }
    return r;
}





/*
 * lever: Raw u32 lock return avoids an aggregate frame word; Slot_021C024C remains a one-word aggregate.
 */
/*
 * lever: Raw u32 lock return avoids an aggregate frame word; Slot remains a one-word aggregate.
 */
void func_021C0450(u8 *p, u8 *q, u16 c, int k)
{
    u32 old;
    if (k == 5) {
        func_021C63D0(p, q);
        if (func_021C4F64(p, q) && func_021BC2B0(p)) return;
    } else {
        func_021C0520(p, q, c, k);
        switch (k) {
        case 2: func_021C5480(p, q, 598); break;
        case 3: func_021C5480(p, q, 602); break;
        case 4: func_021C5480(p, q, 601); break;
        case 23: {
            union Slot_021C024C s = func_021D7D18(2);
            func_021CD4B0(((struct Obj00003 *)p)->fC, 49, func_021D5440(q), 0);
            func_021C5C1C(p, q, 2, s);
            func_021C5480(p, q, 598);
            break;
        }
        }
    }
    old = func_021CC8D8(p + 0x1d74, 5728);
    func_021C6564(p, q, c, k);
    func_021CC95C((u32 *)(p + 0x1d74), old, 5730);
}





/*
 * lever: a u8 local for the random result narrows in r0 before copying to r2.
 */
void func_021C0520(u8 *p, u8 *a, u16 b, u32 c)
{
    u32 id = func_021D5440(a);
    switch (c) {
    case 2: func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x135, id, 0xffff0000); break;
    case 3: func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x114, id, 0xffff0000); break;
    case 4: func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x123, id, 0xffff0000); break;
    case 6: func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x16b, id, 0xffff0000); break;
    case 7: func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x16e, id, 0xffff0000); break;
    case 8: func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x150, id, 0xffff0000); break;
    case 9: func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x253, id, b, 0xffff0000); break;
    case 18: func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x1bd, id, 0xffff0000); break;
    case 10: func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x23b, id, b, 0xffff0000); break;
    case 11: func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x244, id, b, 0xffff0000); break;
    case 12: func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x24d, id, b, 0xffff0000); break;
    case 13: func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x37a, id, b, 0xffff0000); break;
    case 14: func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x37d, id, 0xffff0000); break;
    case 15:
        func_021CD4B0(((struct Obj00003 *)p)->fC, 0x57, id);
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x1c3, id, 0xffff0000);
        func_021CD4B0(((struct Obj00003 *)p)->fC, 0x58, id);
        break;
    case 20: func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x43e, id, b, 0xffff0000); break;
    case 22:
        if (func_021D62C4((struct Unk021D62A8 *)a, 2) != 0) {
            func_021CD64C(((struct Obj00003 *)p)->fC, 0x5a, 0xc2, id, 0xffff0000);
        } else {
            u8 rand = func_021D78AC(4);
            func_021CD64C(((struct Obj00003 *)p)->fC, 0x5a, rand + 0xbc, id, 0xffff0000);
        }
        break;
    case 23: func_021CD64C(((struct Obj00003 *)p)->fC, 0x5a, 0xc1, id, 0xffff0000); break;
    case 1:
        func_021C5604(p, a, b);
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5a, 0x52, id, 0xffff0000);
        break;
    default: func_021CD64C(((struct Obj00003 *)p)->fC, 0x5a, 0x47, id, 0xffff0000); break;
    case 19:
    case 25:
        break;
    }
}






void func_021C0780(u8 *p, u8 *a, int i, u8 v)
{
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x25, func_021D5440(a), (u8)i, v);
    func_021D69A0(a, i, v);
}





/*
 * extent: Two alignment bytes at 0x021C07D2 precede matched func_021C07D4.
 * lever: Wide forwarded arguments avoid truncations absent before the first call.
 */
int func_021C07AC(u8 *p, u8 *a, u16 c, u16 d, int e)
{
    u8 result = func_021C07D4(p, a, d, c, e);
    return func_021C0898(p, a, d, result);
}


/*
 * c and d are narrow parameters: their home stores (`str r2,[sp]` first,
 * `str r3,[sp,#4]` after `adds r7,r1`) sit where the narrow-parameter idiom
 * puts them; as u32 both sink below `ldr r5`. u8 and u16 compile the same
 * (any mix of the two); nothing in the image fixes the width, u16 chosen.
 * func_021C0868/0878/0888 are `bx pc` ARM veneers declared as thumb externs.
 * `i = 0;` as its own statement before the func_021C0868 call puts
 * `movs r4,#0` between `adds r0,r5` and that bl.
 */
int func_021C07D4(u8 *p, u8 *a, u16 c, u16 d, int e)
{
    int i;
    u8 *r;
    int res;
    func_021D74F8(0x16ef);
    i = 0;
    func_021D75EC(5, func_021C0868(e));
    r = func_021C0878(e, 0);
    if (r != 0) {
        do {
            func_021D75EC(i + 6, func_021D5440(r));
            i++;
            r = func_021C0888(e, i);
        } while (r != 0);
    }
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x12, d);
    func_021D75EC(0x17, c);
    func_021D75A8(0x20, 1);
    func_021D70F0(p, 0x4e);
    res = func_021D775C(0x20);
    func_021D7540(0x1704);
    return res;
}
