/*
 * function: func_021D8958
 * address: 0x021D8958
 * packet: pkt_ov123_021D8958
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020093C8 0x020093C8 thumb
 *   func_0203F4E4 0x0203F4E4 arm
 *   func_0203F540 0x0203F540 arm
 *   func_0203CD98 0x0203CD98 arm
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 *   func_021B95D4 0x021B95D4 thumb ov114
 *   func_021B9748 0x021B9748 thumb ov114
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D81E4 0x021D81E4 thumb ov123
 *   func_021D88C0 0x021D88C0 thumb ov123
 */
#include "../include/Obj06468.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct RtcDate { int year; u32 month; int day, week; };
struct Sub02008AECSession;
struct Sub02009448Obj;
extern struct Sub02008AECSession *func_02008B14(void *sys);
extern int func_02008BD0(const struct Sub02008AECSession *s);
extern struct Sub02009448Obj *func_02009448(void *sys);
struct Sub02009210Obj;
extern u32 func_020093C8(const struct Sub02009210Obj *obj);
extern void func_0203F4E4(struct RtcDate *);
extern int func_0203F540(struct RtcDate *);
extern int func_0203CD98(void);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern int func_021B95D4(int index, u8 *p);
extern int func_021B9748(u8 *p);
extern void func_021D6EE0(u8 *p, u32 v, int unused);
extern void func_021D81E4(char *);
extern void func_021D88C0(char *);
void func_021D8958(char *p)
{
    struct RtcDate saved, current;
    u32 value;
    int day;
    if (func_02008BD0(func_02008B14(((struct Obj06468 *)p)->f28)) && ((struct Obj06468 *)p)->fAC) {
        func_021D6EE0((u8 *)p,(int)func_021D81E4,0x85c);
        return;
    }
    value=func_020093C8((const struct Sub02009210Obj *)func_02009448(((struct Obj06468 *)p)->f28));
    saved.year=(u8)(value>>24);
    saved.month=(u8)(value>>16);
    saved.day=(u8)(value>>8);
    saved.week=(u8)value;
    func_0203F4E4(&current);
    day=func_0203F540(&saved);
    if (day==func_0203F540(&current)) {
        func_021D6EE0((u8 *)p,(int)func_021D81E4,0x869);
        return;
    }
    if (func_0203CD98()) {
        if (func_021B95D4(1,((struct Obj06468 *)p)->f10) && !func_021B9748(((struct Obj06468 *)p)->f10))
            func_021D6EE0((u8 *)p,(int)func_021D88C0,0x871);
    } else {
        if (func_020362DC() || func_02035C60())
            func_021D6EE0((u8 *)p,(int)func_021D88C0,0x878);
    }
}
