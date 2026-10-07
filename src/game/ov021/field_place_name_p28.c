/*
 * file:     field_place_name_p28.c
 * unit:     yes
 * function: func_021BE148, func_021BE158, func_021BE17C, func_021BE180
 * address:  0x021BE148
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
 *   func_02048F4C  0x02048F4C  arm
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_0218EC90  0x0218EC90  thumb  ov021
 *   func_0218E104  0x0218E104  thumb  ov021
 *   func_0218EC60  0x0218EC60  thumb  ov021
 */
#include "../../matched/include/Obj18253.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern void func_02048F4C(void *dst, u32 archive_id, u32 member);
extern void func_0218E104(u8 *a, u32 b);
extern void func_0218EC54(u8 *p);
extern int func_0218EC60(u32 a);
extern u32 func_0218EC90(u32, u32);
void func_021BE148(u32 a, int b);
int func_021BE158(u32 a, u32 b);
u32 func_021BE17C(u8 *p);
u8 *func_021BE180(u8 *p);


void func_021BE148(u32 a, int b)
{
    func_02048F4C((void *)a, 0xb3, b - 7);
}


int func_021BE158(u32 a, u32 b)
{
func_0218EC54((u8 *)a);
func_0218EC90(a, b);
func_0218E104((u8 *)a, 0);
return func_0218EC60(a);
}


u32 func_021BE17C(u8 *p)
{
    return ((struct Obj18253 *)p)->f4;
}


/*
 * Returns the object pointer advanced by 0x58 bytes.
 */
u8 *func_021BE180(u8 *p)
{
    return p + 0x58;
}
