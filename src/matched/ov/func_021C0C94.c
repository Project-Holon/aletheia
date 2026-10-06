/*
 * function: func_021C0C94
 * address:  0x021C0C94
 * packet:   pkt_021C0C94
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AA1C  0x0201AA1C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
struct BigObj;
extern void *func_02012934(const struct BigObj *p);
extern u32 func_0201AA1C(void *);

u32 func_021C0C94(u32 a)
{
return func_0201AA1C(func_02012934(func_020120F4((const struct Ctx *)a)));
}

