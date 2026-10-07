/*
 * file:     btl_calc_p01.c
 * unit:     yes
 * function: func_021D6E04, func_021D6E0C, func_021D6E24, func_021D6E40, func_021D6E50, func_021D6E74, func_021D6E88
 * address:  0x021D6E04
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
 *   func_0202142C 0x0202142C thumb
 *   func_02017E40 0x02017E40 thumb
 */
#include "../../matched/include/Obj13446.h"
#include "../../matched/include/Obj10052.h"
#include "../../matched/include/Obj18422.h"
#include "../../matched/include/Obj00041.h"

typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern unsigned short func_0202142C(int a0);
extern void func_02017E40(void *, u32, u32);
unsigned char func_021D6E04(unsigned char *p);
u8 func_021D6E0C(u8 *p, u32 i);
void func_021D6E24(void **p, int value);
void func_021D6E40(u8 *p, u8 a, u16 b);
int func_021D6E50(u8 *p, u8 *id, u16 *value);
/* 021D6E74 first round: `== 0x1f` gave bne; the image is beq. */ u32 func_021D6E74(u8 *p);
void func_021D6E88(u8 *p);

unsigned char func_021D6E04(unsigned char *p)
{
    return p[0xd0];
}

/*
 * lever: left-associated pointer addition preserves base-plus-index then +0xD1.
 */
u8 func_021D6E0C(u8 *p, u32 i)
{
    if (i < p[0xd0]) return *(p + i + 0xd1);
    return 0x1f;
}

/*
 * prototype: reads r0 after func_0202142C, so returns the live wrapper result.
 */
void func_021D6E24(void **p, int value)
{
    u32 n;
    n = func_0202142C(value);
    if (n == 0) n = 4;
    func_02017E40(*p, 0x98, n);
}


void func_021D6E40(u8 *p, u8 a, u16 b)
{
    p[0x1F6] = a;
    ((struct Obj13446 *)p)->f1F4 = b;
}

int func_021D6E50(u8 *p, u8 *id, u16 *value)
{
    if (p[0x1f6] != 0x1f) {
        *id = p[0x1f6];
        *value = ((struct Obj10052 *)p)->f1F4;
        return 1;
    }
    return 0;
}


/* 021D6E74  first round: `== 0x1f` gave bne; the image is beq. */
/*
 * 8 instructions, 16 bytes: ldr r1, pool_021D6E84; ldrb r0, [r0, r1]; cmp r0, #0x1f; beq loc_021D6E80; movs r0, #1; bx lr; movs r0, #0; bx lr.
 */
u32 func_021D6E74(u8 *p)
{
    return (((struct Obj18422 *)p)->f1F6 != 0x1f);
}

/*
 * extent: existing follower ov093_func_021D6EA0 stays separate.
 */
void func_021D6E88(u8 *p)
{
    if (p[0x1f6] != 0x1f) {
        p[0x1f6] = 0x1f;
        ((struct Obj00041 *)p)->f1F4 = 0;
    }
}
