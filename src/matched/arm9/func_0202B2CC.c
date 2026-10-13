/*
 * function: ISS_DUNGEON_SYS_ApplyTrack
 * address:  0x0202B2CC
 * packet:   pkt_0202B2CC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocker ISS_DUNGEON_SYS_ApplyTrack.c is now a manifest entry (matched class)
 *
 * Indexed-eighth-of-a-word helper: a u16 lane at 0xc+2i and a signed u16 lane
 * at 4+2i of the same record, fed to the tile/VRAM helpers.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/ISS_DUNGEON_SYS_ApplyTrack.c \
 *       --func ISS_DUNGEON_SYS_ApplyTrack --addr 0x0202B2CC --thumb --cc 1.1p1
 *
 * symbols:
 *   GFL_USE_GetBgmHandle  0x02005C3C  thumb
 *   GFL_USE_SetBgmTrackParams  0x02005EE0  thumb
 *   NNS_SndHandleSetTrackPitch  0x02073018  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void GFL_USE_SetBgmTrackParams(u32 a, u32 b, u32 c, u32 d);
struct Obj;
extern u32 *GFL_USE_GetBgmHandle(void);
extern void NNS_SndHandleSetTrackPitch(struct Obj *o, u32 v, u32 w);

void ISS_DUNGEON_SYS_ApplyTrack(u8 *p, u32 idx)
{
    u32 off = idx << 1;

    GFL_USE_SetBgmTrackParams(0xffff, *(u16 *)(p + 0xc + off), 0xffffffff, 0);
    NNS_SndHandleSetTrackPitch((struct Obj *)GFL_USE_GetBgmHandle(), 0xfcff, (u32)*(short *)(p + 4 + off));
}
