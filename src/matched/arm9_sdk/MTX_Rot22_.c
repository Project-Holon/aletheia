/*
 * function: MTX_Rot22_
 * address:  0x0207AD64
 * packet:   pkt_0207AD64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef signed int fx32;

typedef struct {
    fx32 _00, _01;
    fx32 _10, _11;
} MtxFx22;

asm void MTX_Rot22_(MtxFx22 *dst, fx32 sin, fx32 cos)
{
    str r2, [r0]
    str r1, [r0, #4]
    neg r1, r1
    str r1, [r0, #8]
    str r2, [r0, #0xc]
    bx lr
}
