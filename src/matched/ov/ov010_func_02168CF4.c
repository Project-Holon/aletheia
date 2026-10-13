/*
 * function: FLD_BTL_INST_TOOL_CreateBattleEvent
 * address: 0x02168CF4
 * packet: pkt_ov010_02168CF4
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * accepted 2026-10-05 by the user: the held form (see the notes below) is accepted as plausible original source.
 * recoup 2026-10-05 (P21L10): extent 60 B includes a 2-byte pad (movs r0,r0); code is 58 B.
 * The old draft (12 B off, only the ldr r2 position and the lsls/adds r6 order) closed by
 * dropping const from the record pointer and the byte-pointer casts: EXACT* in c99 and c.
 * Not filed as matched: the Offset enum local (off = KIND_OFF, then off - 4, off - 8) is only
 * there to stop mwcc folding 0x12c into the load offsets. With int k or a plain int typedef,
 * literals, struct fields or a named kind local the compiler folds to a 0x49 base (40 B off).
 * A human reason for the held 0x12c is not known; integrator decides. Callee FLD_BTL_INST_TOOL_CreateBtlSetup
 * has u8 kind/n params in the ov021 twin caller but this caller passes full words (no
 * truncation), so the prototype here is int. pragmas scheduling/peephole/opt_lifetimes off:
 * no change on the old const form (12 B). unsigned kind: 15 B.
 * symbols:
 *   GAMESYSTEM_GetFieldMap 0x0201210C thumb
 *   FLD_BTL_INST_TOOL_CreateBtlSetup 0x021681C8 thumb ov010
 *   EVENT_BATTLE_CreateForcedWinTask 0x0216E910 thumb ov010
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef enum { KIND_OFF = 0x12c } Offset;
typedef struct {
    u8 pad[0x124];
    int count;
    void *save;
    Offset kind;
} Record;
struct Bs;
struct Ctx;
struct Rec;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern struct Bs *FLD_BTL_INST_TOOL_CreateBtlSetup(void *sys, void *partyA, u32 mode0, struct Rec *recA, struct Rec *recB, int n);
extern int EVENT_BATTLE_CreateForcedWinTask(void *, void *, void *);
int FLD_BTL_INST_TOOL_CreateBattleEvent(void *a, Record *p)
{
    void *b;
    Offset kind;
    Offset off;
    b = GAMESYSTEM_GetFieldMap(a);
    off = KIND_OFF;
    kind = (Offset)*(int *)((u8 *)p + off);
    return EVENT_BATTLE_CreateForcedWinTask(a, b, FLD_BTL_INST_TOOL_CreateBtlSetup(a, *(void *const *)((u8 *)p + (off - 4)), kind, (struct Rec *)p, 0, *(int *)((u8 *)p + (off - 8))));
}
