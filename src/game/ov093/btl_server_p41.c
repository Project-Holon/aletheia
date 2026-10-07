/*
 * file:     btl_server_p41.c
 * unit:     yes
 * function: func_021C02CC, func_021C031C, func_021C03AC, func_021C03D8
 * address:  0x021C02CC
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
 *   func_021D74F8  0x021D74F8  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D7630  0x021D7630  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 *   func_021CD64C  0x021CD64C  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021D61A8  0x021D61A8  thumb  ov093
 *   func_021C5620  0x021C5620  thumb  ov093
 *   func_021C54C8  0x021C54C8  thumb  ov093
 *   func_021D7AF0  0x021D7AF0  thumb  ov093
 *   func_021C54FC  0x021C54FC  thumb  ov093
 *   func_021D62A8  0x021D62A8  thumb  ov093
 *   func_021D6130  0x021D6130  thumb  ov093
 *   func_021C557C  0x021C557C  thumb  ov093
 */
#include "../../matched/include/Obj04359.h"

struct Slot;
struct Unk021D62A8;
struct UtilSlots;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern void func_021D74F8(int line);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int key, u32 val);
extern void func_021D7630(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern int func_021D775C(int key);
extern void func_021D7540(int line);
extern void func_021CD64C(void *w, u8 id, ...);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern int func_021D61A8(struct UtilSlots *p);
extern void func_021C5620(u8 *p, u8 *a, int k, struct Slot *out);
extern void func_021C54C8(u8 *p, u8 *a);
extern int func_021D7AF0(u32 pct);
extern void func_021C54FC(u8 *p, u8 *a);
extern int func_021D62A8(struct Unk021D62A8 *p);
extern int func_021D6130(struct UtilSlots *p);
extern void func_021C557C(u8 *p, u8 *a, int k, int flag);
int func_021C02CC(u8 *p, u8 *a, u32 c, int k);
int func_021C031C(u8 *p, u8 *a);
int func_021C03AC(u8 *p, u8 *a);
void func_021C03D8(u8 *p, u8 *a, u16 a2);


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
