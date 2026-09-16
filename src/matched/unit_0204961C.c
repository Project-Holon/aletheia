/*
 * unit:     yes
 * address:  0x0204961C
 * packet:   pkt_0204961C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0204A1BC  0x0204A1BC  arm
 *   func_0204968C  0x0204968C  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;

u16 func_0204961C(void *obj)
{
    return *(u16 *)((u8 *)obj + 0x4E);
}

extern u32 func_0204A1BC(void *a0, void *a1, u32 a5, u16 a6);
extern u32 func_0204968C(u32 ret, void *a2, void *a3, u32 a4, u32 a5);

u32 func_02049624(void *a0, void *a1, void *a2, void *a3, u32 a4, u32 a5, u16 a6)
{
    u32 ret = func_0204A1BC(a0, a1, a5, a6);
    return func_0204968C(ret, a2, a3, a4, a5);
}
