/*
 * function: DIGITALCARDCHECK_InitRecord
 * address: 0x0217DC28
 * packet: pkt_ov176_0217DC28
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Note 2026-10-04 (wD2 lane12): byte-correct. Unresolved: MISC_SAVEDATA_GetStatsBase and MISC_SAVEDATA_GetRecordBase (witness). Filed src/matched/arm9/MISC_SAVEDATA_GetStatsBase.c and MISC_SAVEDATA_GetRecordBase.c (EXACT) this wave; they need a manifest/shard, then this file re-verifies as EXACT with no C change.
 * blockers: ARM9 0200EA00 and 0200EA08 have no outside witness; the integrator owns filing.
 * blocker: 0x0200EA00 Thumb EXACT (scratch one, fixed flags)
 *   unsigned char *MISC_SAVEDATA_GetStatsBase(unsigned char *p) { return p + 0x5a; }
 * blocker: 0x0200EA08 Thumb EXACT (scratch one, fixed flags)
 *   unsigned char *MISC_SAVEDATA_GetRecordBase(unsigned char *p) { return p; }
 * Lever: explicit unsigned left/right shifts pack the low bytes in 568 bytes;
 * byte casts followed by placement shifts compile to 584 bytes.
 * AE14's empty body leaves its incoming pointer in r0; caller saves it.
 * symbols:
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BATTLE_COMPETITION_GetFromSave 0x0200B358 thumb
 *   REGULATION_GetCard 0x0200B1D4 thumb
 *   REGULATION_GetParty 0x0200B204 thumb
 *   REGULATION_NoOp 0x0200AE14 thumb
 *   MISC_SAVEDATA_GetBlock3C 0x0200E9F4 thumb
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   WIFIBATTLEMATCH_GRAPHIC_GetCamera 0x021E5548 thumb ov177
 *   MI_CpuFill8 0x02082BCC arm
 *   REGULATION_Card_GetCupName 0x0200B074 thumb
 *   MI_CpuCopy8 0x02082D44 arm
 *   MISC_SAVEDATA_GetStatsBase 0x0200EA00 thumb
 *   BSUBWAY_SAVEDATA_GetStat 0x0200DFD8 thumb
 *   func_02008554 0x02008554 thumb
 *   REGULATION_Card_GetValue 0x0200B078 thumb
 *   WIFIBATTLEMATCH_VIEW_CreateStatusWindow 0x021E5D68 thumb ov177
 *   MISC_SAVEDATA_GetRecordBase 0x0200EA08 thumb
 *   func_0200E918 0x0200E918 thumb
 *   REGULATION_GetRuleValue 0x0200AE54 thumb
 *   WIFIBATTLEMATCH_VIEW_CreateDateWindow 0x021E6118 thumb ov177
 *   LIVEBATTLEMATCH_IRC_ToggleSe 0x0217DFF0 thumb ov176
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef u16 Row[3];
struct Big; struct Reg; struct Rec160; struct RecBig; struct Rec1E; struct Reg2;
typedef struct {
    u8 data[0x92]; u16 pad92;
    u32 color0, color1; u8 *user;
    u16 a0, a2;
    union { u32 total; struct { u16 a4, a6; } h; } v;
    u16 a8, aa;
} Rec;
extern void *GAME_DATA_GetSaveControl(struct Big *);
extern void *BATTLE_COMPETITION_GetFromSave(void *);
extern struct Rec160 *REGULATION_GetCard(struct Rec160 *, u32);
extern struct Rec1E *REGULATION_GetParty(struct RecBig *, u32);
extern struct Reg *REGULATION_NoOp(struct Reg2 *);
extern void *MISC_SAVEDATA_GetBlock3C(void *);
extern u8 *GAME_DATA_GetMyStatus(void *);
extern int WIFIBATTLEMATCH_GRAPHIC_GetCamera(int *);
extern void MI_CpuFill8(void *, int, u32);
extern u8 *REGULATION_Card_GetCupName(struct Reg2 *);
extern void MI_CpuCopy8(const void *, void *, u32);
struct Sub0200852CObj;
extern int MISC_SAVEDATA_GetStatsBase(int p);
extern u16 BSUBWAY_SAVEDATA_GetStat(Row *, int, int);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern int REGULATION_Card_GetValue(struct Reg2 *, u32);
extern char *WIFIBATTLEMATCH_VIEW_CreateStatusWindow(char *info, u32 a, void *b, void *owner, void *table, int c, void *d, void *e, void *f, void *record, int mode, u16 heap);
extern int MISC_SAVEDATA_GetRecordBase(int p);
extern u8 func_0200E918(const u8 *, u32);
extern u32 REGULATION_GetRuleValue(struct Reg *, u32);
extern char *WIFIBATTLEMATCH_VIEW_CreateDateWindow(char *info, void *a, void *owner, void *table, int b, void *c, void *d, void *e, void *record, int mode, u16 heap);
extern int LIVEBATTLEMATCH_IRC_ToggleSe(int, int);
void DIGITALCARDCHECK_InitRecord(int *p)
{
    void *save, *stats;
    struct Rec160 *base;
    struct Reg2 *obj;
    struct Rec1E *sub;
    struct Reg *reg;
    u8 *win;
    int flag;
    if (p[2] == 0) {
        save = GAME_DATA_GetSaveControl((struct Big *)p[12]);
        base = BATTLE_COMPETITION_GetFromSave(GAME_DATA_GetSaveControl((struct Big *)p[12]));
        obj = (struct Reg2 *)REGULATION_GetCard(base, p[5]);
        sub = REGULATION_GetParty((struct RecBig *)base, p[5]);
        reg = REGULATION_NoOp(obj);
        stats = MISC_SAVEDATA_GetBlock3C(save);
        win = GAME_DATA_GetMyStatus((void *)p[12]);
        flag = WIFIBATTLEMATCH_GRAPHIC_GetCamera((int *)p[11]);
        if (p[5] == 0) {
            Rec rec;
            Row *table;
            int total, a, b, c, d;
            MI_CpuFill8(&rec, 0, 0xac);
            MI_CpuCopy8(REGULATION_Card_GetCupName(obj), &rec, 0x92);
            table = (u16 (*)[3])MISC_SAVEDATA_GetStatsBase((int)stats);
            rec.a0 = BSUBWAY_SAVEDATA_GetStat(table, 10, 0);
            total = BSUBWAY_SAVEDATA_GetStat(table, 10, 1);
            rec.v.total = total + BSUBWAY_SAVEDATA_GetStat(table, 10, 2);
            rec.user = (u8 *)func_02008554((const struct Sub0200852CObj *)win);
            a = REGULATION_Card_GetValue(obj, 6); b = REGULATION_Card_GetValue(obj, 5); c = REGULATION_Card_GetValue(obj, 4);
            rec.color0 = ((u32)c << 24) | (((u32)b << 24) >> 8) | (((u32)a << 24) >> 16);
            a = REGULATION_Card_GetValue(obj, 9); b = REGULATION_Card_GetValue(obj, 8); d = REGULATION_Card_GetValue(obj, 7);
            rec.color1 = ((u32)d << 24) | (((u32)b << 24) >> 8) | (((u32)a << 24) >> 16);
            rec.aa = REGULATION_Card_GetValue(obj, 11);
            p[2] = (int)WIFIBATTLEMATCH_VIEW_CreateStatusWindow((char *)(&rec), 0, win, (void *)flag, (void *)p[10], p[7], (void *)p[9], (void *)p[0], (void *)p[1], sub, 1, *(u16 *)((char *)p + 0x34));
        } else {
            Rec rec;
            const u8 *table;
            int a, b, c, d;
            MI_CpuFill8(&rec, 0, 0xac);
            MI_CpuCopy8(REGULATION_Card_GetCupName(obj), &rec, 0x92);
            table = (const u8 *)MISC_SAVEDATA_GetRecordBase((int)stats);
            rec.a0 = func_0200E918(table, 1); rec.a2 = func_0200E918(table, 2);
            rec.v.h.a4 = func_0200E918(table, 0);
            rec.v.h.a6 = REGULATION_GetRuleValue(reg, 22);
            rec.user = (u8 *)func_02008554((const struct Sub0200852CObj *)win);
            a = REGULATION_Card_GetValue(obj, 6); b = REGULATION_Card_GetValue(obj, 5); c = REGULATION_Card_GetValue(obj, 4);
            rec.color0 = ((u32)c << 24) | (((u32)b << 24) >> 8) | (((u32)a << 24) >> 16);
            a = REGULATION_Card_GetValue(obj, 9); b = REGULATION_Card_GetValue(obj, 8); d = REGULATION_Card_GetValue(obj, 7);
            rec.color1 = ((u32)d << 24) | (((u32)b << 24) >> 8) | (((u32)a << 24) >> 16);
            rec.a8 = REGULATION_Card_GetValue(obj, 11);
            p[2] = (int)WIFIBATTLEMATCH_VIEW_CreateDateWindow((char *)(&rec), win, (void *)flag, (void *)p[10], p[7], (void *)p[9], (void *)p[0], (void *)p[1], sub, 1, *(u16 *)((char *)p + 0x34));
        }
        LIVEBATTLEMATCH_IRC_ToggleSe((int)p, 0);
    }
}
