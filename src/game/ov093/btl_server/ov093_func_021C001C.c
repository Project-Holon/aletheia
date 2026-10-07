/*
 * function: func_021C001C
 * address: 0x021C001C
 * packet: pkt_ov093_021C001C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Naming the one-word union result before passing it restores the original frame.
 * Symbol hints retain the Thumb ISA of the two already-matched ARM9 callees.
 * symbols:
 *   func_0201BEB8 0x0201BEB8 thumb
 *   func_0201C314 0x0201C314 thumb
 *   func_021C03D8 0x021C03D8 thumb ov093
 *   func_021D62A8 0x021D62A8 thumb ov093
 *   func_021C0274 0x021C0274 thumb ov093
 *   func_021C0404 0x021C0404 thumb ov093
 *   func_021D5778 0x021D5778 thumb ov093
 *   func_021D5584 0x021D5584 thumb ov093
 *   func_021C02CC 0x021C02CC thumb ov093
 *   func_021D5BB0 0x021D5BB0 thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021D6314 0x021D6314 thumb ov093
 *   func_021E8B80 0x021E8B80 thumb ov093
 *   func_021EF948 0x021EF948 thumb ov093
 *   func_021D67B8 0x021D67B8 thumb ov093
 *   func_021D67A8 0x021D67A8 thumb ov093
 *   func_021EF91C 0x021EF91C thumb ov093
 *   func_021C031C 0x021C031C thumb ov093
 *   func_021D7AF0 0x021D7AF0 thumb ov093
 *   func_021C03AC 0x021C03AC thumb ov093
 *   func_021C0450 0x021C0450 thumb ov093
 *   func_021C0520 0x021C0520 thumb ov093
 *   func_021C5480 0x021C5480 thumb ov093
 *   func_021C557C 0x021C557C thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021CD64C 0x021CD64C thumb ov093
 */
#include "../../../matched/include/Obj04359.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
union Slot {
    struct { u32 kind:3; u32 pad:6; u32 id:16; u32 rest:7; } a;
    struct { u32 kind:3; u32 pad:12; u32 id:16; u32 rest:1; } b;
};
extern void func_021C03D8(u8 *, u8 *, u16);
struct QL;
struct Unk021D62A8;
struct UtilWork;
extern int func_021D62A8(struct Unk021D62A8 *p);
extern int func_021C0274(u8 *, u8 *, u32, u32);
extern int func_021C0404(u8 *, u8 *, void *);
struct UtilWork;
extern u8 func_021D5778(struct UtilWork *p, u16 id);
extern u8 func_021D5584(struct UtilWork *p, u32 i);
extern int func_021C02CC(u8 *, u8 *, u32, int);
extern int func_021D5BB0(struct UtilWork *p, u32 n);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern union Slot func_021D6314(void *, int);
extern u16 func_021E8B80(union Slot);
extern u32 func_0201BEB8(u16, u32);
extern int func_021EF948(int);
extern u16 func_021D67B8(u8 *);
extern u16 func_021D67A8(struct QL *p);
extern u32 func_0201C314(void *p);
extern int func_021EF91C(void *, u8 *, u16);
extern int func_021C031C(u8 *, u8 *);
extern int func_021D7AF0(u32);
extern int func_021C03AC(u8 *, u8 *);
extern void func_021C0450(u8 *, u8 *, u16, int);
extern void func_021C0520(u8 *, u8 *, u16, u32);
extern void func_021C5480(u8 *, u8 *, int);
extern void func_021C557C(u8 *, u8 *, int, int);
extern u8 func_021D5440(u8 *);
extern void func_021CD64C(void *, u8, ...);
int func_021C001C(u8 *p, u8 *a, u16 c, u16 d)
{
    int mode;
    int changed = 0;
    int reason;
    union Slot move;
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
    if (func_021D62C4((struct Unk021D62A8 *)a, 15) && func_0201BEB8(c, 12)) { reason = 13; goto done; }
    if (func_021EF948(2) && func_0201BEB8(c, 9)) { reason = 20; goto done; }
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
