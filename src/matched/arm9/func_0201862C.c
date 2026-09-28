/*
 * function: func_0201862C
 * address:  0x0201862C
 * packet:   pkt_0201862C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020185F8  0x020185F8  thumb
 *   func_02019C54  0x02019C54  thumb
 *   func_0201AE1C  0x0201AE1C  thumb
 *   func_0201AF6C  0x0201AF6C  thumb
 *
 * Force a personality value's shininess against trainer id a0: with a5 set,
 * a fresh value from func_020185F8 whose high half is made to xor to the
 * id's key; otherwise an all-0xFF00 construction plus the species' stage
 * byte.  Bit 16 is then forced to a4.  Wave 11, 2026-09-23.
 *
 * The 9-byte residue of 2026-09-22 (permuter floor, `commute(^)`) closed by
 * naming the id key as a block-scoped local, `k = hi(a0) ^ (u16)a0`, and
 * writing `k ^ (u16)v`: the key is computed first into r2 and the chain
 * stays in r1/r2, as the image has it.  No inline form of the same xor
 * reached it (docs/notes/pkt_0201862C.c.txt).
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_020185F8(int a0, int a1, int a2);
extern int func_02019C54(int a0, int a1);
extern int func_0201AE1C(int a0, int a1);
extern int func_0201AF6C(int a0);

u32 func_0201862C(u32 a0, int a1, int a2, int a3, u8 a4, int a5)
{
    if (a5 != 0) {
        u32 v = func_020185F8(a1, a2, a3);

        {
            u32 k = ((a0 & 0xFFFF0000u) >> 16) ^ (u16)a0;

            a0 = v | ((k ^ (u16)v) << 16);
        }
        if ((a0 & 0x10000u) != ((u32)a4 << 16)) {
            a0 ^= 0x10000u;
        }
    } else {
        u8 b = (u8)func_0201AE1C(func_02019C54(a1, a2), 0x14);

        a0 = (0xFF00u ^ ((((a0 & 0xFFFF0000u) >> 16) ^ (u16)a0) & 0xFF00u)) << 16;
        if ((a0 & 0x10000u) != ((u32)a4 << 16)) {
            a0 ^= 0x10000u;
        }
        if (func_0201AF6C(b) == 1) {
            goto done;
        }
        a0 |= b;
        if (a3 == 1) {
            a0 -= 1;
        }
    }
done:
    return a0;
}
