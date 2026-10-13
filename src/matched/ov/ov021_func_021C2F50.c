/*
 * function: FLD3D_CI_CopyName
 * address:  0x021C2F50
 * packet:   pkt_ov021_021C2F50
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Copies a name into a zeroed 16-byte request block (EXACT*: pad).
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern int func_0208CC78(const char *s);

void FLD3D_CI_CopyName(char *dst, const char *src)
{
    int n = func_0208CC78(src);
    u8 i;

    for (i = 0; i < 4; i++)
        ((u32 *)dst)[i] = 0;
    for (i = 0; i < n; i++)
        dst[i] = src[i];
}
