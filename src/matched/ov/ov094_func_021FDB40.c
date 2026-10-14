/*
 * function: BTLV_EFFVM_PlaySeWithParams
 * address:  0x021FDB40
 * packet:   pkt_ov094_021FDB40
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   GFL_USE_GetSeSlot  0x02006148  thumb
 *   GFL_USE_PlaySeInSlot  0x0200616C  thumb
 *   GFL_USE_GetSeHandle  0x02006138  thumb
 *   GFL_USE_SetSeSlotParams  0x02006268  thumb
 *   NNS_SndHandleSetVolume  0x02072F34  arm
 *   NNS_SndHandleSetTrackModDepth  0x02073058  arm
 *   NNS_SndHandleSetTrackModSpeed  0x02073078  arm
 */
typedef unsigned int u32;
typedef unsigned short u16;

extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern int GFL_USE_GetSeSlot(u32 a);
struct Obj;
extern void GFL_USE_PlaySeInSlot(void *arg, int i);
extern u32 *GFL_USE_GetSeHandle(int i);
extern void GFL_USE_SetSeSlotParams(int i, u32 a, u32 b, u32 c);
extern void NNS_SndHandleSetVolume(char *p, unsigned int v);
extern void NNS_SndHandleSetTrackModDepth(struct Obj *o, u32 v, u32 w);
extern void NNS_SndHandleSetTrackModSpeed(struct Obj *o, u32 v, u32 w);

void BTLV_EFFVM_PlaySeWithParams(u32 a0, int m, int a2, int a3, unsigned int e, unsigned int f, unsigned int g)
{
    if (m == 5) {
        GFL_USE_PlaySeDefaultVolume(a0);
        m = GFL_USE_GetSeSlot(a0);
    } else {
        GFL_USE_PlaySeInSlot((void *)a0, m);
    }
    NNS_SndHandleSetVolume((char *)GFL_USE_GetSeHandle(m), e);
    GFL_USE_SetSeSlotParams(m, -1, -1, a2);
    GFL_USE_SetSeSlotParams(m, -1, a3, -1);
    if (f) {
        NNS_SndHandleSetTrackModDepth((struct Obj *)GFL_USE_GetSeHandle(m), 0xffff, f);
        NNS_SndHandleSetTrackModSpeed((struct Obj *)GFL_USE_GetSeHandle(m), 0xffff, g);
    }
}
