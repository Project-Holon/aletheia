/*
 * file:     palette_anime_p11.c
 * unit:     yes
 * function: func_021C2630, func_021C2644, func_021C2654, func_021C2664, func_021C2674, func_021C2684, func_021C26AC, func_021C26E8, func_021C270C
 * address:  0x021C2630
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
 *   func_021C28FC  0x021C28FC  thumb  ov217
 *   func_021C291C  0x021C291C  thumb  ov217
 *   func_021C2934  0x021C2934  thumb  ov217
 *   func_021C2914  0x021C2914  thumb  ov217
 *   func_021C2950  0x021C2950  thumb  ov217
 */
typedef unsigned char u8;

typedef signed char s8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef signed int s32;

extern u32 func_021C28FC(u32 a0);
extern u32 func_021C291C();
extern u32 func_021C2934(u32 a0, u32 a1, u32 a2);
extern u32 func_021C2914(void *a0);
extern void func_021C2950(u32);
void func_021C2630(char *p, char *q);
u32 func_021C2644(void *p, u32 i, u8 j);
u32 func_021C2654(void *p, u32 i, u32 j);
u32 func_021C2664(void *p, u32 i, u32 j);
u32 func_021C2674(void *p, u32 i, u32 j);
u32 func_021C2684(void *p, u32 v);
u32 func_021C26AC(const u8 *p, u8 unused, u8 key);
u32 func_021C26E8(u32 a0, u32 a1, u32 a2);
u32 func_021C270C(void *a0);


void func_021C2630(char *p, char *q)
{
    struct S { int a, b, c, d, e, f; };

    *(struct S *)(p + 8) = *(struct S *)q;
}


u32 func_021C2644(void *p, u32 i, u8 j)
{
    return *(u16 *)((char *)p + i * 0xd4 + 0xc + j * 0xc);
}


/*
 * Element field: u8 at +0xe of a 12-byte sub-record of record 0xd4.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C2654(void *p, u32 i, u32 j)
{
    return *(u8 *)((char *)p + i * 0xd4 + 0xe + j * 0xc);
}


/*
 * Element field: u8 at +0xf of a 12-byte sub-record of record 0xd4.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C2664(void *p, u32 i, u32 j)
{
    return *(u8 *)((char *)p + i * 0xd4 + 0xf + j * 0xc);
}


/*
 * Element field: u8 at +0x10 of a 12-byte sub-record of record 0xd4.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C2674(void *p, u32 i, u32 j)
{
    return *(u8 *)((char *)p + i * 0xd4 + 0x10 + j * 0xc);
}


/*
 * Find the 0xd4-byte record whose byte +4 equals the argument; its index or zero.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C2684(void *p, u32 v)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (*(u8 *)((char *)p + i * 0xd4 + 4) == v)
            return (u8)i;
    }
    return 0;
}


/*
 * Const base pointer, i declared before e, e assigned in its own statement.
 */
u32 func_021C26AC(const u8 *p, u8 unused, u8 key)
{
    s32 i;
    const u8 *e;
    e = p + 4 + func_021C2684((void *)p, unused) * 0xd4;
    for (i = 0; i < e[1]; i++) {
        if (key == *(u16 *)(e + 8 + i * 0xc))
            return (u8)i;
    }
    return 0;
}

/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C26E8(u32 a0, u32 a1, u32 a2)
{
    u32 v1 = func_021C28FC(a0);
    func_021C291C(v1, a0);
    func_021C2934(v1, a1, a2);
    return v1;
}

u32 func_021C270C(void *a0)
{
    func_021C2950((u32)a0);
    return func_021C2914(a0);
}
