/*
 * function: func_021D1290
 * address: 0x021D1290
 * packet: pkt_ov093_021D1290
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: the 0x1B2 bit5 test is a byte bitfield, not a shifted integer mask.
 * symbols:
 *   func_021B904C 0x021B904C thumb ov093
 *   func_021D13A4 0x021D13A4 thumb ov093
 *   func_021B86C8 0x021B86C8 thumb ov093
 *   func_021B916C 0x021B916C thumb ov093
 *   func_021B86DC 0x021B86DC thumb ov093
 *   func_021EAF18 0x021EAF18 thumb ov093
 *   func_021EAF50 0x021EAF50 thumb ov093
 *   func_021EA614 0x021EA614 thumb ov093
 *   func_021EA710 0x021EA710 thumb ov093
 *   func_02005D90 0x02005D90 thumb
 *   func_02005E30 0x02005E30 thumb
 *   func_02005E50 0x02005E50 thumb
 *   func_02005D28 0x02005D28 thumb
 */
#include "../include/Obj00066.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 pad[0x1B2]; unsigned char f0:5; unsigned char flag:1; unsigned char f6:2; } Flags;
extern u8 func_021B904C(u8 *p, int k);
extern int func_021D13A4(void *);
extern int func_021B86C8(u8 *);
extern void func_021B916C(u8 *p, u32 x);
extern u16 func_021B86DC(void **p);
extern void func_021EAF18(void *, int, u16);
extern void func_021EAF50(void *, int);
extern void func_021EA614(void *, void *);
extern int func_021EA710(u32 *p);
extern void func_02005D90(u16, u16);
extern void func_02005E30(u32);
extern int func_02005E50(void);
extern void func_02005D28(void);
int func_021D1290(u8 *p, int *state)
{
    int idx;
    int mode;
    u8 flag;
    u16 msg;
    switch (*state) {
    case 0:
        if (((Flags *)p)->flag != 0)
            return 1;
        idx = func_021B904C(((struct Obj00066 *)p)->f0, 0);
        mode = func_021D13A4(p);
        flag = func_021B86C8(*(u8 * *)&((struct Obj00066 *)p)->f0);
        func_021B916C(((struct Obj00066 *)p)->f0, mode);
        switch (mode) {
        case 1: msg = flag != 0 ? 0x31 : 0x30; break;
        case 0: msg = flag != 0 ? 0x33 : 0x32; break;
        case 2: msg = flag != 0 ? 0x35 : 0x34; break;
        default: return 1;
        }
        func_021EAF18(p + 0x58, 1, msg);
        func_021EAF50(p + 0x58, idx);
        if (flag != 0)
            func_021EAF50(p + 0x58, func_021B904C(((struct Obj00066 *)p)->f0, 1));
        func_021EA614(((struct Obj00066 *)p)->f54, p + 0x58);
        if (mode == 1) {
            func_02005D90(func_021B86DC(((struct Obj00066 *)p)->f0), 0xFFFF);
            (*state)++;
        } else {
            func_02005E30(0x1E);
            *state += 2;
        }
        break;
    case 1:
        if (func_021EA710(((struct Obj00066 *)p)->f54) != 0)
            return 1;
        break;
    case 2:
        if (func_021EA710(((struct Obj00066 *)p)->f54) != 0)
            (*state)++;
        break;
    case 3:
        if (func_02005E50() == 0) {
            func_02005D28();
            return 1;
        }
        break;
    }
    return 0;
}
