/*
 * function: MUSICAL_EVENT_CreateStage
 * address:  0x02155FC8
 * packet:   pkt_ov010_02155FC8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte-correct (first draft). Blocker: 0x021FD4F8 has no func_ label in any
 * overlay listing (ov094/ov132/ov135/ov186 overlap it).
 *
 * 2026-10-05 (D9 lane 02): callee 0x021FD4F8 is a real function in ov132 (not ov186/ov094/ov135, where the address is mid-function). Filed it as the EXACT
 *   witness src/matched/ov/ov132_func_021FD4F8.c (50 bytes, finds the entry with a given id byte); symbols line now names ov132. Bytes unchanged. Stays MATCH only until that file gets its shard.
 *
 * symbols:
 *   MUSICAL_STAGE_SYS_Create  0x02156F68  thumb  ov010
 *   MUSICAL_STAGE_SYS_SetLocalPerformer  0x02156FC4  thumb  ov010
 *   MUSICAL_PROGRAM_CreateNpcPerformer  0x021572E4  thumb  ov010
 *   STA_NET_FindRecValueByKey  0x021FD4F8  thumb  ov132
 *   MUSICAL_STAGE_SYS_SetRemotePerformer  0x02157000  thumb  ov010
 *   MUSICAL_PROGRAM_SplitBonus  0x02157174  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct Stage {
    u8 pad00[0x14];
    void *f14;          /* 0x14 */
    void *f18;          /* 0x18 */
} Stage;

typedef struct Work {
    u8 pad00[0x14];
    u32 f14;            /* 0x14 */
    u8 pad18[0x24 - 0x18];
    void *f24;          /* 0x24 */
    void *f28;          /* 0x28 */
    u8 pad2C[4];
    Stage *f30;         /* 0x30 */
    u8 pad34[4];
    void *f38;          /* 0x38 */
    void *f3C;          /* 0x3C */
    u8 pad40[4];
    u8 f44[4];          /* 0x44 */
} Work;

extern Stage *MUSICAL_STAGE_SYS_Create(u32 heap, void *p);
extern int MUSICAL_STAGE_SYS_SetLocalPerformer(int a0, int a1, int a2);
struct Deal;
struct Party;
extern void MUSICAL_PROGRAM_CreateNpcPerformer(struct Deal *d, void *a, u8 b, u8 slot, u16 y);
struct Ctx;
extern u32 STA_NET_FindRecValueByKey(struct Ctx *p, u8 key);
extern int MUSICAL_STAGE_SYS_SetRemotePerformer(int a0, int a1, int a2);
extern void MUSICAL_PROGRAM_SplitBonus(u32 heap, struct Deal *d, struct Party *party);

void MUSICAL_EVENT_CreateStage(Work *w)
{
    u8 i;
    u8 j;
    u32 r;

    w->f30 = MUSICAL_STAGE_SYS_Create(4, w->f28);
    if (w->f14 == 0) {
        for (i = 0; i < 4; i++) {
            if (i == 0)
                MUSICAL_STAGE_SYS_SetLocalPerformer((int)w->f30, w->f44[i], (int)w->f3C);
            else
                MUSICAL_PROGRAM_CreateNpcPerformer(w->f38, w->f30, w->f44[i], i - 1, 4);
        }
    } else {
        j = 0;
        for (i = 0; i < 4; i++) {
            r = STA_NET_FindRecValueByKey(w->f28, w->f44[i]);
            if (r != 0) {
                MUSICAL_STAGE_SYS_SetRemotePerformer((int)w->f30, w->f44[i], r);
            } else {
                MUSICAL_PROGRAM_CreateNpcPerformer(w->f38, w->f30, w->f44[i], j, 4);
                j++;
            }
        }
    }
    w->f30->f18 = w->f24;
    w->f30->f14 = w->f38;
    MUSICAL_PROGRAM_SplitBonus(4, w->f38, (struct Party *)w->f30);
}
