/*
 * function: PM_VOICE_Start
 * address:  0x02006A64
 * packet:   pkt_02006948
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_02140488  0x02140488  data
 *   PM_VOICE_StartChannels  0x02006868  thumb
 *   PM_VOICE_Stop  0x02006948  thumb
 *
 * Free voice `idx`: 0x34-byte entries off the global at 0x02140488.  The
 * index is scaled into the parameter rather than into a pointer local, and
 * the base + index expression is recomputed for the second call, so the
 * source wrote the address expression twice.  The test is on the *word* at
 * +0 of the entry (`[r0]` through the same base register), not on the call
 * result.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PM_VOICE_Start.c \
 *       --func PM_VOICE_Start --addr 0x02006A64 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern char g_02140488[];
struct Sub02006544Entry;
extern int  PM_VOICE_StartChannels(struct Sub02006544Entry *voice);
struct Sub02006948;
extern void PM_VOICE_Stop(struct Sub02006948 *voice);

int PM_VOICE_Start(u32 idx)
{
    if (PM_VOICE_StartChannels((struct Sub02006544Entry *)(g_02140488 + 0x34 * idx)) == 0) {
        PM_VOICE_Stop((struct Sub02006948 *)(g_02140488 + 0x34 * idx));
        return 0;
    }
    return 1;
}
