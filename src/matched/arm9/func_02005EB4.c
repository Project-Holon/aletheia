/*
 * function: GFL_USE_SetBgmAudibleTracks
 * address:  0x02005EB4
 * packet:   pkt_02005EB4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  02072FC8 (arm) reached only by the `blx` inside this function
 *
 * symbols:
 *   NNS_SndHandleSetTrackPause  0x02072FA8  arm
 *   NNS_SndHandleSetTrackMute  0x02072FC8  arm
 *   GFL_USE_GetCurrentSndHandle  0x0200590C  thumb
 *
 * Unregister one event from the connection slot's event list: the key handed
 * back is the one's complement of the argument, truncated to 16 bits by the
 * `lsls #16`/`lsrs #16` pair the conversion emits.  0xFFFF is a pool word
 * rather than a `movs`-able constant and is reused as the first call's
 * second argument, which is why it is loaded into a callee-saved register
 * before the first call instead of being rematerialised.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_USE_SetBgmAudibleTracks.c \
 *       --func GFL_USE_SetBgmAudibleTracks --addr 0x02005EB4 --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 *GFL_USE_GetCurrentSndHandle(void);
struct Obj;
extern void   NNS_SndHandleSetTrackPause(struct Obj *slot, u32 key, u32 f);
extern void   NNS_SndHandleSetTrackMute(struct Obj *slot, u32 key, u32 f);

void GFL_USE_SetBgmAudibleTracks(u32 a0)
{
    u16 key = (u16)(a0 ^ 0xFFFF);

    NNS_SndHandleSetTrackPause((struct Obj *)GFL_USE_GetCurrentSndHandle(), 0xFFFF, 0);
    if (key != 0) {
        NNS_SndHandleSetTrackMute((struct Obj *)GFL_USE_GetCurrentSndHandle(), key, 1);
    }
}
