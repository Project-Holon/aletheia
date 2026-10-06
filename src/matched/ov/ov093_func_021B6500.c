/*
 * function: func_021B6500
 * address: 0x021B6500
 * packet: pkt_ov093_021B6500
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * witness: ov093 leaf shards 021EF980, 021D4D5C, 021EEA54 and the 021D8058/021D805C unit resolve all four former wildcards.
 * lever: cache each re-read fade value for the comparison and setter; associate callback integer offsets before adding the base.
 * volatile: fade field re-read at 021B6584 and 021B659C across hardware-brightness calls.
 * symbols:
 *   func_0207D55C 0x0207D55C arm
 *   func_0207D534 0x0207D534 arm
 *   func_020307B0 0x020307B0 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02006740 0x02006740 thumb
 *   func_021EF980 0x021EF980 thumb ov093
 *   func_021D4D5C 0x021D4D5C thumb ov093
 *   func_021D7894 0x021D7894 thumb ov093
 *   func_021BA0CC 0x021BA0CC thumb ov093
 *   func_021B9DE8 0x021B9DE8 thumb ov093
 *   func_021B6804 0x021B6804 thumb ov093
 *   func_021EEA54 0x021EEA54 thumb ov093
 *   func_021D4254 0x021D4254 thumb ov093
 *   func_021D8058 0x021D8058 thumb ov093
 *   func_021E8DF8 0x021E8DF8 thumb ov093
 *   func_021E88F8 0x021E88F8 thumb ov093
 */
#include "../include/Obj01370.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 pad[0x473]; u8 low:5; u8 flag5:1; u8 flag6:1; u8 flag7:1; } Flags;
typedef struct { int (*first)(u32 *, void *); int (*second)(u32 *, void *); void *object; u32 state; } Callback;
typedef struct { u8 pad[0x460]; volatile int fade; } Fade;
struct S;
struct S020315D4;
extern void func_02005E30(u32);
extern int func_02005E50(void);
extern void func_02005D28(void);
extern int func_0207D55C(volatile u16 *);
extern void func_0207D534(volatile u16 *, int);
extern void func_021EF980(void *);
extern u32 func_020307B0(void *p);
extern void func_021D4D5C(void *);
extern void func_021D7894(void);
extern void func_021BA0CC(struct S *);
extern void func_021B9DE8(char *);
extern void func_021B6804(Callback *, u8 *, u8 *);
extern void func_021EEA54(void);
extern void func_021D4254(void);
extern void func_021D8058(void);
extern void func_021E8DF8(void);
extern void func_02005CA4(int, u32);
extern void func_02006740(void);
extern void func_02029F6C(void);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(unsigned int);
extern void func_021E88F8(void);
static inline int poll(u8 *p, u32 offset)
{
    typedef int (*Fn)(u32 *, void *);
    if (*(Fn *)(p + offset)) {
        if ((*(Fn *)(p + offset))((u32 *)(p + (offset + 12)), *(void **)(p + (offset + 8)))) {
            *(Fn *)(p + offset) = 0; *(u32 *)(p + (offset + 12)) = 0;
        }
        return 0;
    }
    if (*(Fn *)(p + (offset + 4))) {
        if ((*(Fn *)(p + (offset + 4)))((u32 *)(p + (offset + 12)), *(void **)(p + (offset + 8)))) *(Fn *)(p + (offset + 4)) = 0;
        else return 0;
    }
    return 1;
}
int func_021B6500(int handle, u32 *state, int unused, u8 *p)
{
    switch (*state) {
    case 0:
        if (!((Flags *)p)->flag5) func_02005E30(30);
        ((Fade *)p)->fade = 0;
        if (func_0207D55C((volatile u16 *)0x0400006c) != 0) {
            ((Fade *)p)->fade = -16;
            func_0207D534((volatile u16 *)0x0400006c, -16);
            func_0207D534((volatile u16 *)0x0400106c, -16);
            *state += 2;
        } else *state += 1;
        break;
    case 1: {
        int v;
        v = ((Fade *)p)->fade;
        if (v > -16) {
            ((Fade *)p)->fade = v - 1;
            if (func_0207D55C((volatile u16 *)0x0400006c) > (v = ((Fade *)p)->fade))
                func_0207D534((volatile u16 *)0x0400006c, v);
            if (func_0207D55C((volatile u16 *)0x0400106c) > (v = ((Fade *)p)->fade))
                func_0207D534((volatile u16 *)0x0400106c, v);
        } else *state += 1;
        break;
    }
    case 2:
        if (!((Flags *)p)->flag5) {
            if (func_02005E50() == 0) { func_02005D28(); *state += 1; }
        } else *state += 1;
        break;
    case 3:
        if (((struct Obj01370 *)p)->f2BC) { func_021EF980(((struct Obj01370 *)p)->f2BC); ((struct Obj01370 *)p)->f2BC = 0; }
        if (((struct Obj01370 *)p)->f2C0) { func_020307B0(((struct Obj01370 *)p)->f2C0); ((struct Obj01370 *)p)->f2C0 = 0; }
        if (((struct Obj01370 *)p)->f2C4) { func_021D4D5C(((struct Obj01370 *)p)->f2C4); ((struct Obj01370 *)p)->f2C4 = 0; }
        func_021D7894();
        func_021BA0CC((struct S *)p);
        func_021B9DE8((char *)p);
        func_021B6804((Callback *)(p + 0x450), p, *(u8 * *)&((struct Obj01370 *)p)->f0);
        *state += 1;
        break;
    case 4:
        if (poll(p, 0x450)) {
            func_021EEA54(); func_021D4254(); func_021D8058();
            *state += 1;
        }
        break;
    case 5:
        func_021E8DF8();
        func_02005CA4(1, 62);
        func_02006740();
        if (((Flags *)p)->flag7) { func_02029F6C(); ((Flags *)p)->flag7 = 0; }
        func_020315D4((struct S020315D4 *)handle);
        func_020306F0(19);
        func_020306F0(20);
        func_020306F0(18);
        func_021E88F8();
        return 1;
    }
    return 0;
}
