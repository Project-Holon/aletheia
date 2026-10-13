/*
 * function: func_021E237C
 * address: 0x021E237C
 * packet: pkt_ov093_021E237C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Word return from BTLV_CORE_MakeSlotKind2 reserves the unused aggregate slot;
 * u8 c schedules its stack reload after the zero store at 021E23CE.
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   BTL_EVENT_GetFactorKey 0x021D70A8 thumb ov093
 *   BTLV_CORE_MakeSlotKind2 0x021E896C thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   func_021C7D00 0x021C7D00 thumb ov093
 *   func_021C8120 0x021C8120 thumb ov093
 *   func_021C7F68 0x021C7F68 thumb ov093
 */
#include "../include/Obj05222.h"
#include "../include/Obj13508.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Word { u32 v; } Word;
extern int BTL_EVENT_GetVar(int);
struct QQ;
struct Unk021D62A8;
extern void *func_021C7CF4(int *p, int i);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern void *func_021C88A4(char *p, int a, int b);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern Word BTLV_CORE_MakeSlotKind2(int, int);
extern void func_021C8838(void *, int, int);
struct S;
extern void func_021C8860(struct S *, u32);
extern void func_021C88C8(void *, void *);
extern int func_021C7D00(u8 *p, int b);
extern u8 *func_021C8120(u8 *p, int b);
extern u8 func_021C7F68(int *p, int b, u8 *out);
void func_021E237C(void *a, void *b, u8 c, u8 *d)
{
    u8 *p;
    u8 *buf;
    u32 flags;
    unsigned i;
    u8 *entry;
    if (c != BTL_EVENT_GetVar(3)) return;
    if (BTL_POKEPARAM_HasSick(func_021C7CF4(b, c), 25) != 0) return;
    if (((struct Obj13508 *)d)->f18 != 0) return;
    p = func_021C88A4(b, 12, c);
    ((struct Obj05222 *)p)->f4 = 25;
    *(Word *)(p + 8) = BTLV_CORE_MakeSlotKind2(3, BTL_EVENT_GetFactorKey(a));
    p[12] = 0;
    p[15] = c;
    func_021C88C8(b, p);
    p = func_021C88A4(b, 4, c);
    func_021C8838(p + 4, 2, 703);
    func_021C8860((struct S *)(p + 4), c);
    func_021C88C8(b, p);
    flags = func_021C7D00(b, c);
    buf = func_021C8120(b, 7);
    buf[0] = func_021C7F68(b, (u16)(flags | 0x800), buf + 1);
    for (i = 0; i < buf[0]; i++) {
        entry = buf + i;
        if (BTL_POKEPARAM_HasSick(func_021C7CF4(b, entry[1]), 2) != 0) {
            p = func_021C88A4(b, 11, c);
            ((struct Obj05222 *)p)->f4 = 2;
            p[20] = 1;
            p[8] = entry[1];
            func_021C8838(p + 24, 2, 706);
            func_021C8860((struct S *)(p + 24), entry[1]);
            func_021C88C8(b, p);
        }
    }
    ((struct Obj13508 *)d)->f18 = 1;
}
