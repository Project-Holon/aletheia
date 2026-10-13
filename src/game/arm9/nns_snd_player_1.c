/*
 * file:     nns_snd_player_1.c
 * unit:     yes
 * function: NNS_SndPlayerSetPlayerVolume, NNS_SndPlayerSetPlayableSeqCount
 * address:  0x02072D98
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_0214E484       0x0214E484  data
 *   g_0214DEC0      0x0214DEC0  data
 *   g_0214E47C      0x0214E47C  data
 *   g_0214E480      0x0214E480  data
 */
typedef unsigned int u32;

typedef unsigned char u8;

void NNS_SndPlayerSetPlayerVolume(u32 playerNo, u32 volume);
void NNS_SndPlayerSetPlayableSeqCount(int playerNo, int playableSeqCount);
extern u8 g_0214E484[];
extern char g_0214E47C[];


/*
 * Byte field of record `idx` in the stride-0x24 table.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_SndPlayerSetPlayerVolume.c \
 *       --func NNS_SndPlayerSetPlayerVolume --addr 0x02072D98 --cc 1.1p1 --arm
 */
void NNS_SndPlayerSetPlayerVolume(u32 playerNo, u32 volume)
{
    g_0214E484[playerNo * 0x24] = volume;
}

void NNS_SndPlayerSetPlayableSeqCount(int playerNo, int playableSeqCount)
{
    *(int *)(g_0214E47C + playerNo * 0x24) = (unsigned short)playableSeqCount;
}
