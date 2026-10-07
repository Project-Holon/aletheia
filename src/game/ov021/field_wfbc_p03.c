/*
 * file:     field_wfbc_p03.c
 * unit:     yes
 * function: func_02193B04, func_02193B20
 * address:  0x02193B04
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
 *   func_02193C08  0x02193C08  thumb  ov021
 *   func_02193D30  0x02193D30  thumb  ov021
 *   func_02193EB4  0x02193EB4  thumb  ov021
 *   func_02193EFC  0x02193EFC  thumb  ov021
 *   func_02193F6C  0x02193F6C  thumb  ov021
 *   func_02193EE8  0x02193EE8  thumb  ov021
 */
struct V;
struct E50;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern void func_02193C08(char *p, int heap);
extern u32 func_02193D30(u32, u32, u32);
extern void func_02193EB4(struct V *v);
extern u32 func_02193EE8(u32);
extern struct E50 *func_02193EFC(struct V *v, u32 key);
extern void func_02193F6C(struct E50 *e);
int func_02193B04(u32 a, u32 b, u32 c, u32 d);
int func_02193B20(u32 a, u32 b);


int func_02193B04(u32 a, u32 b, u32 c, u32 d)
{
func_02193C08((char *)a, d);
return func_02193D30(a, b, c);
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02193B20(u32 a, u32 b)
{
func_02193EB4((struct V *)a);
func_02193F6C(func_02193EFC((struct V *)a, b));
return func_02193EE8(a);
}
