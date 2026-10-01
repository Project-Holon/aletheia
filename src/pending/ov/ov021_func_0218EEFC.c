/*
 * function: func_0218EEFC
 * address:  0x0218EEFC
 * packet:   pkt_ov021_0218EEFC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * symbols:
 *   d_021DDA28  0x021DDA28  data  ov021  a4
 *
 * 2026-10-01: body byte-identical except the fifth (stack) parameter a: the image
 * writes it back to its own home slot at entry (ldr r0,[sp,#0x28]; str r0,[sp,#0x28])
 * and at the end computes &a->ec as ldr/adds #0xec/str [sp,#0x28] before the store
 * of t, i.e. a spilled local coalesced with the parameter slot and reassigned
 * (idiom a-dead-store-to-a-spilled-local-survives...). Tried: local copy p = a with
 * p += 0xec / p = a + 0xec, a Track** slot local, a += 0xec, volatile a (adds an
 * extra reload). All copy-propagate or reload; 2 stores (8 bytes) missing.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

typedef struct { int x, y, z; } Vec3;

typedef struct {
    int count;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 flag1;
    u32 flag2;
    u32 flag4;
    Vec3 *bufA;
    Vec3 *bufB;
    u32 unk28;
    u32 unk2C;
} Track;

extern void *func_02030734(u16 heap, u32 size, u32 flag, const void *file, u32 line);
extern const char d_021DDA28[];

void func_0218EEFC(int n, u32 x, u32 flags, u32 heap, u8 *a)
{
    if (*(u32 *)(a + 0x1c) != 0) {
        int i = 0;
        Track *t = func_02030734(heap, sizeof(Track), 0, d_021DDA28, 0x6aa);
        t->bufA = func_02030734(heap, n * sizeof(Vec3), 0, d_021DDA28, 0x6ab);
        t->bufB = func_02030734(heap, n * sizeof(Vec3), 0, d_021DDA28, 0x6ac);
        for (; i < n; i++) {
            Vec3 *v = &t->bufA[i];
            v->x = 0;
            v->y = 0;
            v->z = 0;
            v = &t->bufB[i];
            v->x = 0;
            v->y = 0;
            v->z = 0;
        }
        t->count = n;
        t->unk0C = x;
        t->unk10 = 0;
        t->unk04 = 0;
        t->unk08 = x;
        t->flag1 = 0;
        t->flag2 = 0;
        t->flag4 = 0;
        if (flags & 1)
            t->flag1 = 1;
        if (flags & 2)
            t->flag2 = 1;
        if (flags & 4)
            t->flag4 = 1;
        t->unk28 = 1;
        t->unk2C = 0;
        *(Track **)(a + 0xec) = t;
    }
}
