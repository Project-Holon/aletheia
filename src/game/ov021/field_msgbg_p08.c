/*
 * file:     field_msgbg_p08.c
 * unit:     yes
 * function: func_0218B88C, func_0218B8AC, func_0218B910
 * address:  0x0218B88C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0218C934  0x0218C934  thumb  ov021
 *   func_02013B38  0x02013B38  thumb
 *   func_0218BC1C  0x0218BC1C  thumb
 *   func_020140D8  0x020140D8  thumb
 *   func_0218BB0C  0x0218BB0C  thumb
 *   func_0218BC40  0x0218BC40  thumb
 *   func_0218BB78  0x0218BB78  thumb
 *   func_0218BD28  0x0218BD28  thumb
 *   func_0218BDD8  0x0218BDD8  thumb
 *   func_0218BBD0  0x0218BBD0  thumb  ov021
 *   func_0218BBF4  0x0218BBF4  thumb  ov021
 */
#include "../../matched/include/Obj09453.h"

struct Sub020140BCObj;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef signed short   s16;

typedef signed char    s8;

void func_0218C934(unsigned char *p);
extern u32 func_02013B38(u32 id);
extern unsigned short func_0218BC1C(int x);
extern u8 func_020140D8(struct Sub020140BCObj *p);
extern void func_0218BB0C(u8 *s, u16 a, u32 n);
extern void func_0218BC40(unsigned char *p, int a, int b, int c);
extern void func_0218BB78(u8 *s, int k);
extern void func_0218BD28(char *p, int c);
extern void func_0218BDD8(u8 *s, u32 *out);
extern u32 func_0218BBD0(u32, u32);
extern int func_0218BBF4(u32 a, u32 b);
void func_0218B88C(unsigned char *p);
void func_0218B8AC(char *p, int a, int b, int c);
int func_0218B910(u32 a, u32 b);


void func_0218B88C(unsigned char *p)
{
    int i;
    for (i = 0; i < 7; i++) {
        if (((void **)(p + 0x1DC))[i] != 0)
            func_0218C934(((void **)(p + 0x1DC))[i]);
    }
}


/*
 * Addresses are Black-image addresses.
 */
void func_0218B8AC(char *p, int a, int b, int c)
{
    void *s;
    int k1;
    int k2;
    int k3;

    s = (void *)func_0218BC1C(func_02013B38(a));
    if (func_020140D8((struct Sub020140BCObj *)b)) {
        k1 = 0xE5;
        k2 = 0xB0;
        k3 = 0x15;
    } else {
        k1 = 0xE6;
        k2 = 0xB1;
        k3 = 0x14;
    }
    func_0218BB0C((u8 *)p, k1, (u32)s);
    func_0218BC40((unsigned char *)p, (u16)k2, (int)s, c);
    func_0218BB78((u8 *)p, k3);
    func_0218BD28(p, c);
    func_0218BDD8((u8 *)p, (u32 *)(p + 0x1B0));
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0218B910(u32 a, u32 b)
{
return func_0218BBF4(((struct Obj09453 *)((u8 *)(a)))->f18, func_0218BBD0(a, b));
}
