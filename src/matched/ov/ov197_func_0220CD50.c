/*
 * function: func_0220CD50
 * address: 0x0220CD50
 * packet: pkt_ov197_0220CD50
 * region: ov197
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PALANM_GetFadeRequestBits 0x02021ED8 thumb
 *   func_0220D884 0x0220D884 thumb ov197
 *   func_02025DE8 0x02025DE8 thumb
 *   func_0220BB98 0x0220BB98 thumb ov197
 *   func_0220D89C 0x0220D89C thumb ov197
 *   func_0220BF20 0x0220BF20 thumb ov197
 *   func_020260E0 0x020260E0 thumb
 */
#include "../include/Obj00389.h"
#include "../include/Obj25073.h"
#include "../include/Obj25074.h"
#include "../include/Obj25075.h"
#include "../include/Obj25076.h"
#include "../include/Obj25077.h"
#include "../include/Obj25078.h"
#include "../include/Obj25079.h"
#include "../include/Obj25080.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Sound;
extern u32 PALANM_GetFadeRequestBits(const char *ptr);
extern int func_0220D884(char **);
extern int func_02025DE8(struct Sound *obj);
extern unsigned func_0220BB98(const char *p, unsigned n);
extern void func_0220D89C(char **, int);
extern void func_0220BF20(char *, int);
extern u8 func_020260E0(struct Sound *obj);
int func_0220CD50(char *p)
{
    unsigned sel;
    if (PALANM_GetFadeRequestBits(((struct Obj00389 *)p)->f8) != 0) goto done;
    if (func_0220D884((char **)p) == 1) return 0x12;
    sel = func_02025DE8(((struct Obj00389 *)p)->f144);
    switch (sel) {
    case 0: case 1: case 2: case 3: case 4: case 5:
        if (func_0220BB98(p, sel) != 0) {
            func_0220D89C((char **)p, 0x54d);
            *(u16 *)(*(char * *)&((struct Obj00389 *)p)->f0 + ((struct Obj00389 *)p)->f533 * 2 + 0x30) = (u8)sel;
            ((struct Obj00389 *)p)->f531 = 9;
            func_0220BF20(p, (u8)(sel + 4));
            return 0x10;
        }
        break;
    case 6:
        func_0220D89C((char **)p, 0x552);
        func_0220BF20(p, 0xa);
        if (((struct Obj25073 *)(*(char * *)&((struct Obj00389 *)p)->f0))->f8 == 1 || ((struct Obj25074 *)(*(char * *)&((struct Obj00389 *)p)->f0))->f8 == 3) {
            ((struct Obj25075 *)(*(char * *)&((struct Obj00389 *)p)->f0))->f16 = 0;
            ((struct Obj25076 *)(*(char * *)&((struct Obj00389 *)p)->f0))->f2A = 4;
            return 0x12;
        }
        ((struct Obj00389 *)p)->f531 = 7;
        return 0x10;
    case (unsigned)-2:
        func_0220D89C((char **)p, 0x552);
        func_0220BF20(p, 0xa);
        if (((struct Obj25077 *)(*(char * *)&((struct Obj00389 *)p)->f0))->f8 == 1 || ((struct Obj25078 *)(*(char * *)&((struct Obj00389 *)p)->f0))->f8 == 3) {
            ((struct Obj25079 *)(*(char * *)&((struct Obj00389 *)p)->f0))->f16 = 0;
            ((struct Obj25080 *)(*(char * *)&((struct Obj00389 *)p)->f0))->f2A = 4;
            return 0x12;
        }
        ((struct Obj00389 *)p)->f531 = 7;
        return 0x10;
    case 7:
        if (*(u8 *)(p + ((struct Obj00389 *)p)->f533 + 0x539) != 0) {
            func_0220D89C((char **)p, 0x54d);
            *(u16 *)(*(char * *)&((struct Obj00389 *)p)->f0 + ((struct Obj00389 *)p)->f533 * 2 + 0x30) = 0;
            ((struct Obj00389 *)p)->f531 = 0xb;
            *(signed char *)&((struct Obj00389 *)p)->f534 = -1;
            func_0220BF20(p, 0xb);
            return 0x10;
        }
        break;
    case 8:
        if (*(u8 *)(p + ((struct Obj00389 *)p)->f533 + 0x539) != 0) {
            func_0220D89C((char **)p, 0x54d);
            *(u16 *)(*(char * *)&((struct Obj00389 *)p)->f0 + ((struct Obj00389 *)p)->f533 * 2 + 0x30) = 0;
            ((struct Obj00389 *)p)->f531 = 0xb;
            ((struct Obj00389 *)p)->f534 = 1;
            func_0220BF20(p, 0xc);
            return 0x10;
        }
        break;
    case (unsigned)-4: case (unsigned)-3:
        func_0220D89C((char **)p, 0x548);
        break;
    case (unsigned)-6:
        func_020260E0(((struct Obj00389 *)p)->f144);
        if (*(u8 *)(p + ((struct Obj00389 *)p)->f533 + 0x539) != 0) {
            func_0220D89C((char **)p, 0x54d);
            ((struct Obj00389 *)p)->f531 = 0xb;
            *(signed char *)&((struct Obj00389 *)p)->f534 = -1;
            func_0220BF20(p, 0xb);
            return 0x10;
        }
        break;
    case (unsigned)-5:
        func_020260E0(((struct Obj00389 *)p)->f144);
        if (*(u8 *)(p + ((struct Obj00389 *)p)->f533 + 0x539) != 0) {
            func_0220D89C((char **)p, 0x54d);
            ((struct Obj00389 *)p)->f531 = 0xb;
            ((struct Obj00389 *)p)->f534 = 1;
            func_0220BF20(p, 0xc);
            return 0x10;
        }
        break;
    case (unsigned)-8: case (unsigned)-7: case (unsigned)-1:
        break;
    }
done:
    return 5;
}
