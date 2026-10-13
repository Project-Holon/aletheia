/*
 * function: ARC_UTIL_UploadPaletteFromArchive
 * address:  0x02049B90
 * packet:   pkt_02049B90
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   ARC_UTIL_LoadMember  0x0204A1BC  arm
 *   ARC_UTIL_UploadPalette  0x02049C28  arm
 *
 * One of two seven-argument entry points on the cell-actor system, an
 * address apart, that differ only in which half of ARC_UTIL_UploadPalette's dispatch
 * they reach first (ARC_UTIL_LoadHandleMember in ARC_UTIL_UploadPaletteFromHandle, 0x0204A1BC here); both
 * then forward into 0x02049C28 itself.
 *
 * The seventh parameter is a u16: it is read off the caller's stack with
 * `ldrh` (a 32-bit parameter would be `ldr`), masked with the pooled 0x7FFF
 * and re-set to the 0x8000 bit before being passed as the fourth argument of
 * the dispatch call.  0x7FFF is not an ARM immediate, which is why it costs a
 * pool word rather than a `mov`.
 *
 * The second call's first argument is the first call's result: no register is
 * written for it, r0 is simply left as the callee returned it.  Declaring the
 * dispatch call's own first argument as a saved parameter instead costs the
 * function a callee-saved register, a 4-byte frame and 16 bytes.
 *
 * Complements ARC_UTIL_UploadPaletteFromHandle, which is a separate file on purpose: 0x02049C28
 * has five branch references image wide and three of them are inside
 * 0x02049C28 itself, so a `tu` spanning both wrappers loses every witness and
 * only the two single-function ranges keep one each.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int ARC_UTIL_LoadMember(int a0, int a1, int a2, int a3);
extern void ARC_UTIL_UploadPalette(void *file, u32 kind, u32 offset, u32 dest, u32 size);

void ARC_UTIL_UploadPaletteFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6)
{
    u32 r = ARC_UTIL_LoadMember(a0, a1, 0, (u16)((a6 & 0x7fff) | 0x8000));
    ARC_UTIL_UploadPalette((void *)r, a2, a3, a4, a5);
}
