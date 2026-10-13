/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x02005EE0
 * packet:   pkt_02005E64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: GFL_USE_SetBgmTrackParams
 *
 * symbols:
 *   GFL_USE_GetCurrentSndHandle   0x0200590C  thumb
 *   NNS_SndHandleSetTrackPitch  0x02073018  arm
 *   NNS_SndHandleSetTrackPan  0x02073038  arm
 *   NNS_SndHandleStop  0x02073098  arm
 *
 * Three optional fields of a request, each skipped when the caller passes
 * -1.  The -1 is rebuilt with `movs`/`mvns` before each of the three tests
 * rather than held in a register across them, which is what an inline
 * constant in three separate comparisons looks like: a variable would have
 * been allocated a register once.
 */

typedef unsigned int u32;

extern u32 *GFL_USE_GetCurrentSndHandle(void);
struct Obj;
extern void NNS_SndHandleSetTrackPitch(struct Obj *o, u32 v, u32 w);
extern void NNS_SndHandleSetTrackPan(struct Obj *o, u32 v, u32 w);
extern void NNS_SndHandleStop(struct Obj *o, u32 v);

void GFL_USE_SetBgmTrackParams(u32 a, u32 b, u32 c, u32 d)
{
    u32 *req = GFL_USE_GetCurrentSndHandle();

    if (b != -1) {
        NNS_SndHandleStop((struct Obj *)req, b);
    }
    if (c != -1) {
        NNS_SndHandleSetTrackPitch((struct Obj *)req, a, c);
    }
    if (d != -1) {
        NNS_SndHandleSetTrackPan((struct Obj *)req, a, d);
    }
}
