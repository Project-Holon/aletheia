/*
 * file:     palette_anime_p12.c
 * unit:     yes
 * function: func_021C271C, func_021C272C
 * address:  0x021C271C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C278C  0x021C278C  thumb  ov217
 *   func_021C288C  0x021C288C  thumb  ov217
 *   func_021C2888  0x021C2888  thumb  ov217
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

extern u32 func_021C278C();
extern void func_021C288C(void *p, u32 a, u32 b);
extern void func_021C2888(void *p, u8 v);
u32 func_021C271C(u32 a0, u32 a1, u32 a2);
u32 func_021C272C(u32 a0, u32 a1);

/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C271C(u32 a0, u32 a1, u32 a2)
{
    func_021C288C((void *)a0, a1, a2);
    return func_021C278C(a0);
}

u32 func_021C272C(u32 a0, u32 a1)
{
    func_021C2888((void *)a0, ((u32)((u32)a1 << 24) >> 24));
    return func_021C278C(a0);
}
