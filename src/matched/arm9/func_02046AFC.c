/*
 * function: G3D_SYSTEM_GetLookAt
 * address:  0x02046AFC
 * packet:   pkt_02046858
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   _G3dSystem   0x02146A5C  data
 *
 * Copy three twelve-byte groups out of the context: +0x5c to the caller's
 * +0, +0x68 to +0xc and +0x74 to +0x18.  Each group is one nested struct
 * assignment, which this compiler emits as a paired ldm/stm of three words
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md) - three separate field
 * copies would be nine loads and nine stores.
 *
 * The context is read once: the three assignments are not separated by any
 * call, so the pointer stays live in ip, and the calling argument is kept in
 * lr while the first two destinations are built into r0/r3.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/G3D_SYSTEM_GetLookAt.c \
 *       --func G3D_SYSTEM_GetLookAt --addr 0x02046AFC --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Tri {
    u32 a;
    u32 b;
    u32 c;
};

extern u8 *_G3dSystem;

void G3D_SYSTEM_GetLookAt(u8 *dst)
{
    *(struct Tri *)(dst + 0x00) = *(struct Tri *)(_G3dSystem + 0x5c);
    *(struct Tri *)(dst + 0x0c) = *(struct Tri *)(_G3dSystem + 0x68);
    *(struct Tri *)(dst + 0x18) = *(struct Tri *)(_G3dSystem + 0x74);
}
