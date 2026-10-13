/*
 * function: NNSi_G3dAnmCalcNsBta
 * address:  0x02070904
 * packet:   pkt_0207010C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Blocked on evidence class `matched`: the one PC24 site is the bl to
 * NNSi_G3dAnmGetTexSRTData, and the only branch to that address anywhere in the image is
 * this very call, so no `label` witness exists outside the compared range.
 * Unblocks as soon as 0x02070730 has an EXACT manifest entry.
 *
 * symbols:
 *   NNSi_G3dAnmGetTexSRTData    0x02070730  arm
 *
 * Both struct fields the tail touches are `volatile`; without that on BOTH,
 * mwcc hoists the +0x00 load above the +0x10 store and reallocates.
 *
 * Forwards to the sampler at 0x02070730 with the animation record's frame
 * index (f0 >> 12, arithmetic) and its payload pointer, then rewrites the
 * two-bit state field at +0x10 to 0b01 and sets bit 3 of the flags word.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Anim70904 { u32 f0; u32 f4; void *p8; };
struct Dst70904  { volatile u32 f0; u32 pad04[3]; volatile u32 f10; };


struct Node70730;
struct Out70730;
void NNSi_G3dAnmGetTexSRTData(struct Node70730 *node, u32 idx, u32 t, struct Out70730 *out);

void NNSi_G3dAnmCalcNsBta(struct Dst70904 *dst, struct Anim70904 *a, u32 idx)
{
    NNSi_G3dAnmGetTexSRTData((struct Node70730 *)((struct Dst70904 *)a->p8), (u16)idx, (int)a->f0 >> 12, (struct Out70730 *)dst);
    dst->f10 = (dst->f10 & ~0xc0000000u) | 0x40000000u;
    dst->f0 |= 8;
}
