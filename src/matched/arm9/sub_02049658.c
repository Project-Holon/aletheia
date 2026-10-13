/*
 * function: ARC_UTIL_UploadBgCharFromHandle
 * address:  0x02049658
 * packet:   pkt_0204961C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sub_0204A380   0x0204A380  arm
 *   ARC_UTIL_UploadBgChar   0x0204968C  arm
 *
 * Seven-argument entry point of the text-printing layer: resolve a handle
 * through sub_0204A380 from the first two arguments and the last two, then
 * hand that handle plus the middle arguments to ARC_UTIL_UploadBgChar.
 *
 * The sixth argument is read from the caller's stack slot twice, once as
 * sub_0204A380's third argument and once as ARC_UTIL_UploadBgChar's fifth: the
 * compiler will not keep it in a callee-saved register across the first
 * call, because re-reading the incoming slot is free
 * (docs/idioms/keeping-a-cursor-in-a-named-local-costs-a-callee-saved-register.md).
 * The seventh is read with `ldrh`, which is what names it u16.  The third
 * and fourth arguments are parked in r5/r4 because they are live across
 * the first call.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ARC_UTIL_UploadBgCharFromHandle.c \
 *       --func ARC_UTIL_UploadBgCharFromHandle --addr 0x02049658 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void *sub_0204A380(void *a0, u32 a1, u32 a2, u32 a3);
extern u32 ARC_UTIL_UploadBgChar(void *buf, u32 a1, u32 a2, u32 a3, u32 unused);

u32 ARC_UTIL_UploadBgCharFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g)
{
    return ARC_UTIL_UploadBgChar((void *)((u32)sub_0204A380(a, b, f, g)), c, d, e, f);
}
