/*
 * function: GAMESYSTEM_Setup
 * address:  0x02011FB8
 * packet:   pkt_02011F28
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_Init     0x02011F28  thumb
 *   GAME_BEACON_Setup     0x020267BC  thumb
 *   PALANM_StopTimer     0x02021438  thumb
 *
 * The object goes through GAMESYSTEM_Init with r0-r2 untouched, then one field
 * destructor and a global call.
 *
 * blocker:  label.  Two calls with no outside witness: 0x02011F28 at +0x04
 *           (its only caller in the image is this function) and 0x020267BC at
 *           +0x0A.  Both are byte-correct here; the range cannot be cut to
 *           free them because the call is inside the only function that makes
 *           it.  Folding 0x02011F28 into the same unit would take the packet
 *           to 0x02011F28.. and is possible - see the note in
 *           docs/notes/pkt_02011F28.c.txt.
 * Verified with:
 *   python tools/match.py one --src src/pending/GAMESYSTEM_Setup.c \
 *       --func GAMESYSTEM_Setup --addr 0x02011FB8 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct IcaAnime {
    u8  pad00[0x08];
    u32 f8;         /* +0x08 */
    u32 pad0c;      /* +0x0C */
    u32 f10;        /* +0x10 */
    u32 f14;        /* +0x14 */
    u32 pad18;      /* +0x18 */
    u32 f1c;        /* +0x1C */
    u32 f20;        /* +0x20 */
    u32 f24;        /* +0x24 */
    u32 pad28;      /* +0x28 */
    u32 f2c;        /* +0x2C */
};

extern void GAMESYSTEM_Init(struct IcaAnime *p, u16 id, u32 a2);
extern void GAME_BEACON_Setup(u32 v);
extern void PALANM_StopTimer(void);

void GAMESYSTEM_Setup(struct IcaAnime *p, u16 id, u32 a2)
{
    GAMESYSTEM_Init(p, id, a2);
    GAME_BEACON_Setup(p->f1c);
    PALANM_StopTimer();
}
