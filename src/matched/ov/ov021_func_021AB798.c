/*
 * function: FLD_SCENEAREA_RunCheck
 * address:  0x021AB798
 * packet:   pkt_ov021_021AB798
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLD_SCENEAREA_HasCheck  0x021AB768  thumb
 */

typedef int (*Fn)(int a, int b, int c);

typedef struct {
    Fn *f0;
    Fn *f4;
} S;

typedef unsigned int   u32;
extern int FLD_SCENEAREA_HasCheck(u32 a, u32 b);

int FLD_SCENEAREA_RunCheck(S *s, int i, int a, int b, int c)
{
    if (FLD_SCENEAREA_HasCheck((u32)s, i)) {
        return s->f0[i](a, b, c);
    }
    return 0;
}
