/*
 * function: TOUCHPANEL_GetTrgSys
 * address:  0x02035C48
 * packet:   pkt_02035C60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   TOUCHPANEL_GetWork  0x02035750  arm
 *   TOUCHPANEL_ReadTrg  0x020357C0  arm
 *
 * Hands the same context to both halves of the teardown pair.  The
 * argument is kept in a callee-saved register across the first call
 * rather than reloaded, which is what says it is one parameter passed
 * twice and not two different values.
 *
 * Decompiled to unstick src/pending/TOUCHPANEL_GetTrg.c, whose only blocking
 * relocation was this address: 0x02035C48 is reached by exactly one
 * branch image-wide (the `bl` at 0x02035C68 inside that caller), so class
 * `label` was unavailable and only an EXACT entry here could attest it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TOUCHPANEL_GetTrgSys.c \
 *       --func TOUCHPANEL_GetTrgSys --addr 0x02035C48 --cc 1.1p1 --arm
 */

struct Ctx02035C48;

extern int TOUCHPANEL_GetWork(void);
typedef unsigned short u16;
struct Kind;
extern u16 TOUCHPANEL_ReadTrg(struct Kind *p);

u16 TOUCHPANEL_GetTrgSys(struct Ctx02035C48 *ctx)
{
    TOUCHPANEL_GetWork();
    return TOUCHPANEL_ReadTrg((struct Kind *)ctx);
}
