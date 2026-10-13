/*
 * function: COLOSSEUM_UpdateCommPlayers
 * address:  0x0217FF78
 * packet:   pkt_ov019_0217FF78
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   COLOSSEUM_UpdateCommPlayers   0x0217FF78  thumb
 *   GFL_NET_HANDLE_GetCurrentHandle   0x020399A8  arm
 *   GFL_NET_GetHandleNetID   0x0203D1A4  arm
 *   func_02008550   0x02008550  thumb
 *   COLOSSEUM_TakePackage   0x021751DC  thumb  ov012
 *   COMM_PLAYER_CheckOccupy   0x021677E4  thumb
 *   COMM_PLAYER_Add   0x021675D0  thumb
 *   COMM_PLAYER_SetPackage   0x02167848  thumb  ov010
 *
 * Up to four entries of the table based at p+0x18 (stride 0x2c), dispatching
 * each through one of two handlers.  Addresses are Black-image addresses.
 *
 * Recursive MATCH unblocker result (wave 9).  Both previously-blocked sites
 * now attest `matched`, so the file reaches EXACT:
 *   +0024 COLOSSEUM_TakePackage ov012 -- already matched by an earlier lane
 *       (src/matched/ov012_func_021751DC.c).
 *   +005C COMM_PLAYER_SetPackage ov010 -- the last blocker; now
 *       src/matched/ov010_func_02167848.c.  It is an unlabelled Thumb leaf
 *       (ov010 emitted it as a `pool_` word run because `push {r4,r5}` saves no
 *       `lr`), so no `func_` label witnesses it and the only reference
 *       image-wide is the call inside this range; a matched EXACT entry is the
 *       only class that can carry it.  See
 *       docs/idioms/a-twelve-byte-aggregate-copy-pins-the-destination-first.md.
 * The `region isa` hints on both symbols lines are correct (`thumb ov012` /
 * `thumb ov010`); the "no image evidence for the ISA" suffix match.py prints
 * for a `matched` overlay site is expected -- isa_evidence only consults the
 * listing's own `func_` labels, which neither unlabelled leaf has.
 */

typedef unsigned int u32;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
extern int COLOSSEUM_TakePackage(u32 *p, int i, u32 *out);
extern int COMM_PLAYER_CheckOccupy(u32 v, int i);
typedef unsigned char  u8;
struct Sub0200852CObj;
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void COMM_PLAYER_Add(u32 v, int i, int mode, u32 *out);
extern void COMM_PLAYER_SetPackage(char *a0, int a1, char *a2);

void COLOSSEUM_UpdateCommPlayers(u32 *p)
{
    int count;
    int i;
    u32 tmp[5];

    count = GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle());

    for (i = 0; i < 4; i++) {
        if (count != i && COLOSSEUM_TakePackage(p, i, tmp) == 1) {
            if (COMM_PLAYER_CheckOccupy(p[0], i) == 0) {
                int v = func_02008550((const struct Sub0200852CObj *)((u32 *)((char *)p + 0x18 + 0x2c * i)));
                int mode = 1;

                if (v)
                    mode = 4;
                COMM_PLAYER_Add(p[0], i, mode, tmp);
            } else {
                COMM_PLAYER_SetPackage((char *)p[0], i, (char *)tmp);
            }
        }
    }
}
