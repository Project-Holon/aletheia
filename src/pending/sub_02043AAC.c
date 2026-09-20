/*
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 *
 * function: func_02043AAC
 * address:  0x02043AAC
 * packet:   pkt_0204384C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * note:     re-verified 2026-09-20: MATCH; see verify output
 *
 * symbols:
 *   func_0204427C  0x0204427C  arm
 *
 * bmp.c's ten-argument forwarder onto 0x0204427C.  The first four arguments
 * pass through in their registers; the six stacked ones are copied down to
 * the outgoing frame, and the last two are re-read narrow: the ninth with a
 * plain `ldrh` (the parameter and the callee's are both halfwords, so the
 * load is the declared width and nothing else is needed) and the tenth with
 * `ldrh` plus `and ip, ip, #0xff`, which is a halfword parameter narrowed to
 * the callee's byte one.  A word parameter narrowed to a byte would have
 * been a single `ldrb` off the home slot, so the `ldrh` is what names the
 * incoming width.
 *
 * Every one of the 72 concrete bytes is reproduced.  The single relocation
 * stays wildcarded: 0x0204427C is called from here and from nowhere else in
 * the image, so the `label` class has no witness outside the compared range,
 * it is not in the manifest, and a one-function range admits no cut.  It
 * closes when 0x0204427C is matched.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_02043AAC.c \
 *       --func func_02043AAC --addr 0x02043AAC --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Bmp {
    u8  pad00[8];
    u16 unk08;
    u16 unk0A;
};

extern void func_0204427C(struct Bmp *dst, u32 a2, u32 a3, u32 a4, u32 a5,
                          u32 a6, u32 a7, u32 a8, u16 a9, u8 a10);

void func_02043AAC(struct Bmp *dst, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6,
                   u32 a7, u32 a8, u16 a9, u16 a10)
{
    func_0204427C(dst, a2, a3, a4, a5, a6, a7, a8, a9, a10);
}
