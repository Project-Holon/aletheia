/*
 * function: FLD3D_CI_FreeSequence
 * address:  0x021C2734
 * packet:   pkt_ov021_021C2734
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Frees the four optional buffers (EXACT*: trailing pad).
 */

typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void FLD3D_CI_FreeSequence(void **p)
{
    if (p[2] != 0)
        func_020307B0(p[2]);
    if (p[3] != 0)
        func_020307B0(p[3]);
    if (p[1] != 0)
        func_020307B0(p[1]);
    if (p[0] != 0)
        func_020307B0(p[0]);
}
