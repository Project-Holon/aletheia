/*
 * function: FLD_SCENEAREA_RunAction
 * address:  0x021AB7C0
 * packet:   pkt_ov021_021AB7C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLD_SCENEAREA_HasAction  0x021AB780  thumb
 */

typedef void (*Fn)(int a, int b, int c);

typedef struct {
    Fn *f0;
    Fn *f4;
} S;

typedef unsigned int   u32;
extern int FLD_SCENEAREA_HasAction(u32 a, u32 b);

void FLD_SCENEAREA_RunAction(S *s, int i, int a, int b, int c)
{
    if (FLD_SCENEAREA_HasAction((u32)s, i)) {
        s->f4[i](a, b, c);
    }
}
