/*
 * file:     nns_snd_player_10.c
 * unit:     yes
 * function: NNS_SndHandleSetSweep, NNS_SndHandleReadTrackInfo
 * address:  0x020730DC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
struct SNDTrackInfo;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct SndSeqPlayer {
    u8  pad00[0x2c];
    u8  state;
    u8  pad2d[0x34 - 0x2d];
    u16 sweepMode;
    u16 pad36;
    u16 sweepPitch;
    u16 sweepFrames;
    u8  playerNo;
} SndSeqPlayer;

typedef struct SndHandle { SndSeqPlayer * volatile player; } SndHandle;

extern int func_02072894(int playerNo, int trackNo, struct SNDTrackInfo *trackInfo);


/*
 * Three statements that each re-read o->p, so `volatile` on the pointer field
 *  * is load-bearing here too: it is what keeps the three loads. The three
 *  * statements also keep the early `bxeq lr`; the two-statement sibling
 *  * func_020730B8, byte for byte otherwise, is if-converted instead (see
 *  * docs/notes/pkt_02072EA8.c.txt).
 */
void NNS_SndHandleSetSweep(SndHandle *handle, u32 pitch, u32 frames)
{
    if (handle->player == 0) return;
    handle->player->sweepMode = 2;
    handle->player->sweepPitch = pitch;
    handle->player->sweepFrames = frames;
}


/*
 * Returns 0 to the caller when the guarded pointer is null, and forwards its
 *  * own v and w to the callee (they are already in r1/r2, so the call sets only
 *  * r0).
 */
int NNS_SndHandleReadTrackInfo(SndHandle *handle, int trackNo, struct SNDTrackInfo *trackInfo)
{
    if (handle->player == 0) return 0;
    return func_02072894(handle->player->playerNo, trackNo, trackInfo);
}
