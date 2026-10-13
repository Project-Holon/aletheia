/*
 * function: GFL_USE_SetBgmTrackVolume
 * address:  0x02005F24
 * packet:   pkt_02005F24
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  02072FE8 (arm) reached only by the `blx` inside this function
 *
 * symbols:
 *   NNS_SndHandleSetTrackVolume  0x02072FE8  arm
 *   GFL_USE_GetCurrentSndHandle  0x0200590C  thumb
 *
 * Forward two arguments onto one event of the current connection slot:
 * `slot` is the result of GFL_USE_GetCurrentSndHandle (0x0200590C, matched) and stays in r0
 * across the two parameter moves, which is why the two `adds rN, rN, #0`
 * copies appear after the call rather than before it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_USE_SetBgmTrackVolume.c \
 *       --func GFL_USE_SetBgmTrackVolume --addr 0x02005F24 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern u32 *GFL_USE_GetCurrentSndHandle(void);
struct Obj;
extern void   NNS_SndHandleSetTrackVolume(struct Obj *slot, u32 a, int b);

void GFL_USE_SetBgmTrackVolume(u32 a0, u32 a1)
{
    NNS_SndHandleSetTrackVolume((struct Obj *)GFL_USE_GetCurrentSndHandle(), a0, (int)a1);
}
