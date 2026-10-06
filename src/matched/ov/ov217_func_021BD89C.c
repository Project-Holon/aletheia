/*
 * function: func_021BD89C
 * address:  0x021BD89C
 * packet:   pkt_ov217_021BD89C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203630C  0x0203630C  arm
 *   func_020362DC  0x020362DC  arm
 *   func_02035C08  0x02035C08  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_021C09B8  0x021C09B8  thumb  ov217
 *   func_021BE448  0x021BE448  thumb  ov217
 *   func_021BE454  0x021BE454  thumb  ov217
 *   func_021BE498  0x021BE498  thumb  ov217
 *   func_021BE614  0x021BE614  thumb  ov217
 *   func_021BE678  0x021BE678  thumb  ov217
 *   func_021BE704  0x021BE704  thumb  ov217
 *   func_021BE790  0x021BE790  thumb  ov217
 *   func_021BE7B4  0x021BE7B4  thumb  ov217
 *   func_021BE808  0x021BE808  thumb  ov217
 *   func_021BE934  0x021BE934  thumb  ov217
 *   func_021BEAF8  0x021BEAF8  thumb  ov217
 *   func_021BEB40  0x021BEB40  thumb  ov217
 *   func_021BEC00  0x021BEC00  thumb  ov217
 *   func_021BF758  0x021BF758  thumb  ov217
 *   func_021BF810  0x021BF810  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00021.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern unsigned int func_0203630C(void);
extern u32 func_020362DC(void);
extern int func_02035C08(const void *rect);
extern void *func_021C09B8(void *p);
extern void func_020061E4(u32 a);
extern void func_021BE448(void *p);
extern void func_021BE454(u8 *a0, u32 a1);
extern void func_021BE498(u8 *a0, u32 a1);
extern u32 func_021BE614(u32 a0, u32 a1);
extern void func_021BE678(char *p);
extern void func_021BE704(char *p);
extern u32 func_021BE790(u32 a0);
extern u32 func_021BE7B4(u32 a0);
extern void func_021BE808(char *p);
extern int func_021BE934(char *p);
extern void func_021BEAF8(u8 *p);
extern u32 func_021BEB40(u32 a0);
extern void func_021BEC00(u32 *p);
extern u32 func_021BF758(void *p);
extern u32 func_021BF810(void *p);

void func_021BD89C(u8 *p)
{
    u32 keys;
    int hit;
    int sub;

    func_0203630C();
    keys = func_020362DC();
    hit = func_02035C08(p + 0x2FE);
    sub = func_02035C08(func_021C09B8(((struct Obj00021 *)p)->f0));
    if (*(int *)&((struct Obj00021 *)p)->f3C8 != 0 && ((struct Obj00021 *)p)->f3D8 != 0 && *(int *)&((struct Obj00021 *)p)->f3D4 != 0) {
        func_021BE448(p);
        func_021BE498(p, 8);
        func_021BE498(p, 6);
        func_021BE498(p, 7);
        func_021BE498(p, 5);
        func_021BE498(p, 2);
        return;
    }
    if (func_021BF758(p) != 0 || sub == 0) {
        func_021BE454(p, 1);
        func_021BEC00((u32 *)p);
        func_020061E4(0x551);
        func_021BE448(p);
        func_021BE498(p, 11);
        func_021BE498(p, 10);
        func_021BE498(p, 12);
        return;
    }
    if ((keys & 0x40) || (keys & 0x80) || (keys & 0x20) || (keys & 0x10) || (keys & 1)) {
        func_021BE934((char *)p);
        func_021BEAF8(p);
        func_021BE448(p);
        func_021BE498(p, 3);
        return;
    }
    if (hit == 6 && *(int *)&((struct Obj00021 *)p)->f3C8 == 0 && func_021BF810(p) != 0) {
        ((struct Obj00021 *)p)->f3CC = 1;
        func_021BEB40((u32)p);
        func_021BE448(p);
        func_021BE498(p, 4);
        func_021BE498(p, 6);
        func_021BE498(p, 7);
        func_021BE498(p, 5);
        func_021BE498(p, 2);
    } else if (hit == 7) {
        if (*(int *)&((struct Obj00021 *)p)->f3C8 == 0 && func_021BF810(p) != 0) {
            ((struct Obj00021 *)p)->f3CC = 1;
            func_021BEB40((u32)p);
            func_021BE448(p);
            func_021BE498(p, 4);
            func_021BE498(p, 6);
            func_021BE498(p, 7);
            func_021BE498(p, 5);
            func_021BE498(p, 2);
        } else {
            func_020061E4(0x557);
        }
    } else if (hit == 2) {
        if (*(int *)&((struct Obj00021 *)p)->f3C8 == 0 && func_021BF810(p) != 0) {
            ((struct Obj00021 *)p)->f3CC = 1;
            func_021BEB40((u32)p);
            func_021BE448(p);
            func_021BE498(p, 4);
            func_021BE498(p, 6);
            func_021BE498(p, 7);
            func_021BE498(p, 5);
            func_021BE498(p, 2);
        } else {
            func_021BE614((u32)p, 0);
        }
    } else if (*(int *)&((struct Obj00021 *)p)->f3C8 != 0 && func_021BF810(p) != 0 && hit == 3) {
        func_021BE614((u32)p, 1);
        func_021BE934((char *)p);
        func_021BEAF8(p);
        func_021BE448(p);
        func_021BE498(p, 3);
    } else if (*(int *)&((struct Obj00021 *)p)->f3C8 != 0 && func_021BF810(p) != 0 && hit == 4) {
        func_021BE614((u32)p, 2);
        func_021BE934((char *)p);
        func_021BEAF8(p);
        func_021BE448(p);
        func_021BE498(p, 3);
    } else if (hit == 5) {
        func_021BE614((u32)p, 3);
        func_021BE934((char *)p);
        func_021BEAF8(p);
        func_021BE448(p);
        func_021BE498(p, 3);
    } else if (hit == 0) {
        func_021BE934((char *)p);
        func_021BEAF8(p);
        func_021BE448(p);
        func_021BE498(p, 3);
        switch (*(int *)&((struct Obj00021 *)p)->f34) {
        case 0: func_021BE704((char *)p); break;
        case 1: func_021BE7B4((u32)p); break;
        case 3: func_021BE808((char *)p); break;
        }
    } else if (hit == 1) {
        func_021BE934((char *)p);
        func_021BEAF8(p);
        func_021BE448(p);
        func_021BE498(p, 3);
        switch (*(int *)&((struct Obj00021 *)p)->f34) {
        case 0: func_021BE678((char *)p); break;
        case 1: func_021BE790((u32)p); break;
        case 3: func_021BE808((char *)p); break;
        }
    } else if (keys & 2) {
        func_021BE454(p, 0);
        func_021BEC00((u32 *)p);
        func_020061E4(0x551);
        func_021BE448(p);
        func_021BE498(p, 11);
        func_021BE498(p, 10);
        func_021BE498(p, 12);
    }
}
