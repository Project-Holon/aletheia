/*
 * file:     field_effect_p45.c
 * unit:     yes
 * function: func_021ABC14, func_021ABC38
 * address:  0x021ABC14
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
 *   func_021ABB54  0x021ABB54  thumb  ov021
 *   func_021ABC5C  0x021ABC5C  thumb  ov021
 *   func_021ABD08  0x021ABD08  thumb  ov021
 *   func_021ABB78  0x021ABB78  thumb  ov021
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern u32 func_021ABB54(u32, u32, u32, u32);
extern void func_021ABC5C(u8 *a0, char *p, void *q);
extern u32 func_021ABD08(u32, u32, u32);
extern u32 func_021ABB78(u32, u32, u32, u32);
int func_021ABC14(u8 *a, u32 b, u32 c, u32 d);
int func_021ABC38(u8 *a, u32 b, u32 c, u32 d);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021ABC14(u8 *a, u32 b, u32 c, u32 d)
{
func_021ABB54((u32)a, b, c, d);
func_021ABC5C(a, (char *)b, (void *)c);
return func_021ABD08((u32)a, b, c);
}


int func_021ABC38(u8 *a, u32 b, u32 c, u32 d)
{
func_021ABB78((u32)a, b, c, d);
func_021ABC5C(a, (char *)b, (void *)c);
return func_021ABD08((u32)a, b, c);
}
