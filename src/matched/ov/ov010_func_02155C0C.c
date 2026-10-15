/*
 * function: MUSICAL_EVENT_Main
 * address:  0x02155C0C
 * packet:   pkt_ov010_02155C0C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The ov010 link sequence: a 27-state machine over s->state that runs the
 * wireless exchange through the ov132 session object (s->link->sess),
 * loads the three sub-procs through GAMESYSTEM_CallProc, and returns 1 once
 * the heap is torn down in state 10.
 *
 * symbols:
 *   MUSICAL_EVENT_CheckNetError  0x02156BAC  thumb  ov010
 *   MUSICAL_EVENT_SpawnSeatEffect  0x021567D8  thumb  ov010
 *   MUSICAL_EVENT_CreateLocalPerformer  0x02155F24  thumb  ov010
 *   MUSICAL_EVENT_ShowMessage  0x02156888  thumb  ov010
 *   MUSICAL_EVENT_RunEnterSequence  0x02156770  thumb  ov010
 *   MUSICAL_EVENT_CreateDressupParam  0x02155F9C  thumb  ov010
 *   MUSICAL_EVENT_SendLocalPerformer  0x02155FB4  thumb  ov010
 *   MUSICAL_EVENT_RunLeaveSequence  0x02156710  thumb  ov010
 *   MUSICAL_EVENT_CreateStage  0x02155FC8  thumb  ov010
 *   MUSICAL_EVENT_ScorePerformers  0x02156074  thumb  ov010
 *   MUSICAL_EVENT_CreateShowRecord  0x0215611C  thumb  ov010
 *   MUSICAL_EVENT_RollProgramRewards  0x02156530  thumb  ov010
 *   MUSICAL_EVENT_ApplyResults  0x02156420  thumb  ov010
 *   MUSICAL_EVENT_Free  0x02155F4C  thumb  ov010
 *   MUSICAL_EVENT_SpawnExitEffect  0x02156824  thumb  ov010
 *   MUSICAL_EVENT_ReceiveShowProgram  0x02156B74  thumb  ov010
 *   MUSICAL_PROGRAM_Create  0x02157028  thumb  ov010
 *   MUSICAL_PROGRAM_PackBonus  0x02157260  thumb  ov010
 *   MUSICAL_PROGRAM_PackPicks  0x02157298  thumb  ov010
 *   func_021FD908  0x021FD908  thumb  ov132
 *   func_021FD904  0x021FD904  thumb  ov132
 *   func_021FD918  0x021FD918  thumb  ov132
 *   func_021FD8D4  0x021FD8D4  thumb  ov132
 *   func_021FD8EC  0x021FD8EC  thumb  ov132
 *   func_021FCE28  0x021FCE28  thumb  ov132
 *   func_021FD83C  0x021FD83C  thumb  ov132
 *   func_0200A81C  0x0200A81C  thumb
 *   MISC_SAVEDATA_GetBlock44  0x0200ED48  thumb
 *   MISC_SAVEDATA_InsertRecentValue  0x0200ED54  thumb
 *   func_02008530  0x02008530  thumb
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   GFL_NET_ERR_RequestScreen  0x0200FB38  thumb
 *   func_02030B50  0x02030B50  arm
 *   func_020306F0  0x020306F0  arm
 *   MUSICAL_DRESSUP_SYS_ProcTable     0x02172724  data
 *   MUSICAL_STAGE_SYS_ProcTable     0x02172748  data
 *   d_021F8360     0x021F8360  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Link {
    u32 f00;
    void *sess;         /* 0x04 */
};

typedef struct Seq {
    void *f00;          /* 0x00 */
    u32 f04;
    struct Link *link;  /* 0x08 */
    u32 state;          /* 0x0C */
    u8 f10;             /* 0x10 */
    u8 pad11[0x1C - 0x11];
    void *f1c;          /* 0x1C */
    u32 f20;
    void *f24;          /* 0x24 */
    u32 f28;
    void *f2c;          /* 0x2C */
    void *f30;          /* 0x30 */
    void *f34;          /* 0x34 */
    void *f38;          /* 0x38 */
    u32 f3c;
    void *f40;          /* 0x40 */
    u8 f44[4];          /* 0x44 */
    u32 f48;
    u8 f4c;             /* 0x4C */
    u8 pad4d[3];
    u32 f50;            /* 0x50 */
} Seq;

extern u8 MUSICAL_DRESSUP_SYS_ProcTable[];
extern u8 MUSICAL_STAGE_SYS_ProcTable[];
extern u8 d_021F8360[];

struct Big;
struct Ctx;
struct Deal;
struct IcaAnime;
struct L0200ED54;
struct Src;
struct Sub0200852CObj;
struct Work;
extern void MUSICAL_EVENT_CheckNetError(void *p);
extern void MUSICAL_EVENT_SpawnSeatEffect(void *evt, Seq *s);
extern void MUSICAL_EVENT_CreateLocalPerformer(int *p);
extern void MUSICAL_EVENT_ShowMessage(void *a0, void *a1, int a2);
extern int MUSICAL_EVENT_RunEnterSequence(void *evt, Seq *s);
struct Obj;
extern struct Obj *MUSICAL_EVENT_CreateDressupParam(int a0);
extern void MUSICAL_EVENT_SendLocalPerformer(struct Work *w);
extern int MUSICAL_EVENT_RunLeaveSequence(void *evt, Seq *s);
extern void MUSICAL_EVENT_CreateStage(struct Work *w);
extern void MUSICAL_EVENT_ScorePerformers(struct Work *w);
extern void MUSICAL_EVENT_CreateShowRecord(struct Work *w);
extern void MUSICAL_EVENT_RollProgramRewards(struct Work *w);
extern void MUSICAL_EVENT_ApplyResults(struct Work *w);
extern int MUSICAL_EVENT_Free(int a0);
extern void MUSICAL_EVENT_SpawnExitEffect(void *evt, Seq *s);
extern void MUSICAL_EVENT_ReceiveShowProgram(struct Work *w);
extern struct Deal *MUSICAL_PROGRAM_Create(u32 heap, struct Src *src, u16 lim);
extern u32 MUSICAL_PROGRAM_PackBonus(const u8 *p);
extern u32 MUSICAL_PROGRAM_PackPicks(const u8 *p);
extern u32 func_021FD908(u8 *p);
extern int func_021FD904(int *p);
extern void func_021FD918(char *p, u32 a, int b);
extern u32 func_021FD8D4(char *p);
extern u8 func_021FD8EC(char *p, int index);
extern int func_021FCE28(char *p, u32 index);
extern u32 func_021FD83C(char *p);
extern u16 func_0200A81C(struct Big *p);
extern void *MISC_SAVEDATA_GetBlock44(void *p);
extern void MISC_SAVEDATA_InsertRecentValue(struct L0200ED54 *l, u32 val);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void GAMESYSTEM_CallProc(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 GAMESYSTEM_GetProcStatus(const struct Ctx *p);
extern void GFL_NET_ERR_RequestScreen(void);
extern void func_02030B50(void *p);
extern void func_020306F0(u32 heap);

int MUSICAL_EVENT_Main(void *evt, void *unused, Seq *s)
{
    MUSICAL_EVENT_CheckNetError(s);
    switch (s->state) {
    case 11:
        if (func_021FD908(s->link->sess) == 1) {
            u32 lo = 0;
            u32 hi = 0;
            void *list;
            u8 i;

            if (func_021FD904(s->link->sess) == 1) {
                s->f38 = MUSICAL_PROGRAM_Create(4, s->f24, func_0200A81C(s->f40));
                lo = MUSICAL_PROGRAM_PackBonus(s->f38);
                hi = MUSICAL_PROGRAM_PackPicks(s->f38);
            }
            func_021FD918(s->link->sess, lo, hi);
            s->state = 12;
            list = MISC_SAVEDATA_GetBlock44(s->f1c);
            for (i = 0; i < 4; i++) {
                if (func_021FD8D4(s->link->sess) != func_021FD8EC(s->link->sess, i)) {
                    void *p = (void *)func_021FCE28(s->link->sess, i);
                    if (p != 0)
                        MISC_SAVEDATA_InsertRecentValue(list, func_02008530(p));
                }
            }
        } else if (s->f50 == 1) {
            s->state = 0x17;
        }
        break;
    case 12:
        if (func_021FD83C(s->link->sess) == 1) {
            u8 i;

            s->state = 13;
            for (i = 0; i < 4; i++)
                s->f44[i] = func_021FD8EC(s->link->sess, i);
            s->f4c = func_021FD8D4(s->link->sess);
            MUSICAL_EVENT_ReceiveShowProgram((struct Work *)s);
        } else if (s->f50 == 1) {
            s->state = 0x17;
        }
        break;
    case 13:
        MUSICAL_EVENT_SpawnSeatEffect(evt, s);
        s->state = 14;
        break;
    case 14:
        MUSICAL_EVENT_CreateLocalPerformer((int *)s);
        MUSICAL_EVENT_ShowMessage(evt, s, 3);
        s->state = 0;
        break;
    case 0:
        if (s->f50 == 1 && s->f10 == 0) {
            s->state = 0x17;
        } else if (MUSICAL_EVENT_RunEnterSequence(evt, s) == 1) {
            s->f10 = 0;
            s->state = 1;
        }
        break;
    case 1:
        s->state = 3;
        break;
    case 3:
        MUSICAL_EVENT_CreateDressupParam((int)s);
        GAMESYSTEM_CallProc(s->f00, ~0u, MUSICAL_DRESSUP_SYS_ProcTable, s->f2c);
        s->state = 4;
        break;
    case 4:
        if (GAMESYSTEM_GetProcStatus(s->f00) == 0) {
            MUSICAL_EVENT_SendLocalPerformer((struct Work *)s);
            s->state = 0x10;
        }
        break;
    case 16:
        if (MUSICAL_EVENT_RunLeaveSequence(evt, s) == 1) {
            s->f10 = 0;
            s->state = 0x11;
            if (s->f50 == 1)
                s->state = 0x17;
        }
        break;
    case 17:
        MUSICAL_EVENT_ShowMessage(evt, s, 4);
        s->state = 0x12;
        break;
    case 18:
        if (s->f50 == 1 && s->f10 == 0) {
            s->state = 0x17;
        } else if (MUSICAL_EVENT_RunEnterSequence(evt, s) == 1) {
            s->f10 = 0;
            s->state = 5;
        }
        break;
    case 5:
        MUSICAL_EVENT_CreateStage((struct Work *)s);
        GAMESYSTEM_CallProc(s->f00, ~0u, MUSICAL_STAGE_SYS_ProcTable, s->f30);
        s->state = 6;
        break;
    case 6:
        if (GAMESYSTEM_GetProcStatus(s->f00) == 0) {
            MUSICAL_EVENT_ScorePerformers((struct Work *)s);
            s->state = 7;
            if (s->f50 == 1)
                s->state = 0x16;
        }
        break;
    case 7:
        MUSICAL_EVENT_CreateShowRecord((struct Work *)s);
        GAMESYSTEM_CallProc(s->f00, ~0u, d_021F8360, s->f34);
        s->state = 8;
        break;
    case 8:
        if (GAMESYSTEM_GetProcStatus(s->f00) == 0) {
            s->state = 0x13;
            if (s->f50 == 1)
                s->state = 0x16;
        }
        break;
    case 19:
        if (MUSICAL_EVENT_RunLeaveSequence(evt, s) == 1) {
            s->f10 = 0;
            s->state = 0x14;
            MUSICAL_EVENT_RollProgramRewards((struct Work *)s);
            MUSICAL_EVENT_ApplyResults((struct Work *)s);
        }
        break;
    case 20:
        MUSICAL_EVENT_ShowMessage(evt, s, 5);
        s->state = 2;
        break;
    case 2:
        if (s->f50 == 1) {
            s->state = 0x17;
        } else {
            MUSICAL_EVENT_Free((int)s);
            MUSICAL_EVENT_SpawnExitEffect(evt, s);
            s->state = 9;
        }
        break;
    case 9:
        MUSICAL_EVENT_ShowMessage(evt, s, 0x28CC);
        s->state = 10;
        break;
    case 10:
        func_02030B50((void *)4);
        func_020306F0(0x2C);
        return 1;
    case 22:
        if (MUSICAL_EVENT_RunLeaveSequence(evt, s) == 1)
            s->state = 0x17;
        break;
    case 23:
        GFL_NET_ERR_RequestScreen();
        s->state = 0x18;
        break;
    case 24:
        MUSICAL_EVENT_Free((int)s);
        MUSICAL_EVENT_SpawnExitEffect(evt, s);
        s->state = 0x19;
        break;
    case 25:
        s->state = 0x1A;
        break;
    case 26:
        MUSICAL_EVENT_ShowMessage(evt, s, 0x28CD);
        s->state = 10;
        break;
    }
    return 0;
}
