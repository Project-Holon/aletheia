/*
 * function: func_021C236C
 * address: 0x021C236C
 * packet: pkt_ov093_021C236C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   sub_0201BD28 0x0201BD28 thumb
 *   WAZA_TOOL_GetSickCont 0x0201BF58 thumb
 *   func_021D7C70 0x021D7C70 thumb ov093
 *   func_021D74F8 0x021D74F8 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021D75EC 0x021D75EC thumb ov093
 *   func_021D75A8 0x021D75A8 thumb ov093
 *   func_021D7630 0x021D7630 thumb ov093
 *   func_021D70F0 0x021D70F0 thumb ov093
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7540 0x021D7540 thumb ov093
 *   func_021D78AC 0x021D78AC thumb ov093
 *   func_021B911C 0x021B911C thumb ov093
 */
#include "../include/Obj21082.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u16 v; } W;
typedef struct { u32 v; } Word;
extern u32 sub_0201BD28(u16, u32);
extern W WAZA_TOOL_GetSickCont(u16);
extern void func_021D7C70(W, u32, Word *);
extern void func_021D74F8(int);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int, u32);
extern void func_021D75A8(int, u32);
extern void func_021D7630(int, u32);
extern void func_021D70F0(void *a, int id);
extern u32 func_021D775C(int);
extern void func_021D7540(int);
extern u32 func_021D78AC(u32);
extern int func_021B911C(void *, int);
static inline int chance(u32 n)
{
    return func_021D78AC(100) < n;
}
u32 func_021C236C(u8 *p, u16 id, u8 *a, u8 *b, Word *dest)
{
    u32 s;
    W w;
    Word out;
    u8 rate;
    u32 result;
    u8 changedRate;
    u8 veto;
    s = sub_0201BD28(id, 11);
    w = WAZA_TOOL_GetSickCont(id);
    rate = sub_0201BD28(id, 12);
    func_021D7C70(w, (u32)a, &out);
    func_021D74F8(0x1d7c);
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x12, id);
    func_021D75A8(0x1d, s);
    func_021D7630(0x41, 0);
    func_021D7630(0x1e, out.v);
    func_021D75A8(0x26, rate);
    func_021D70F0(p, 0x64);
    result = func_021D775C(0x1d);
    rate = func_021D775C(0x26);
    veto = func_021D775C(0x41);
    if (result == 0xffff) result = 0;
    out.v = func_021D775C(0x1e);
    func_021D7540(0x1d8f);
    if (!veto && result) {
        if (chance(rate)) {
            *dest = out;
            return result;
        }
        if (func_021B911C(((struct Obj21082 *)p)->f4, 0)) {
            *dest = out;
            return result;
        }
    }
    return 0;
}
