/*
 * function: MUSICAL_STAGE_SYS_Init
 * address:  0x02156CE0
 * packet:   pkt_ov010_02156CE0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Builds the ov010 stage: four members with their records, the ov112 deal
 * and its split. First draft plus two levers: the pooled 0x70 is ov112_id,
 * and the three colour masks come from one `mask` local shifted.
 *
 * symbols:
 *   MUSICAL_STAGE_SYS_Create  0x02156F68  thumb  ov010
 *   MUSICAL_STAGE_SYS_CreateNpcPerformer  0x02156FD0  thumb  ov010
 *   MUSICAL_STAGE_SYS_SetPerformerProp  0x0215700C  thumb  ov010
 *   MUSICAL_PROGRAM_Create  0x02157028  thumb  ov010
 *   MUSICAL_PROGRAM_SplitBonus  0x02157174  thumb  ov010
 *   MUSICAL_MCSS_AllocSmall  0x021F685C  thumb  ov112
 *   MUSICAL_MCSS_LoadDistSave  0x021F68BC  thumb  ov112
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   func_02034AC4  0x02034AC4  arm
 *   ov112_id       0x00000070  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

typedef struct Member {
    u8 pad00[0x4A];
    u16 total;          /* 0x4A */
} Member;

typedef struct Stage {
    void *f00;          /* 0x00 */
    Member *f04[4];     /* 0x04 */
    void *f14;          /* 0x14 */
    void *f18;          /* 0x18 */
    u8 pad1c[0x20 - 0x1C];
} Stage;

typedef struct Work {
    Stage *stage;       /* 0x00 */
    u32 f04;
    u32 f08;
} Work;

extern void GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);
struct Proc;
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
typedef signed int     s32;
struct Deal;
struct Src;
extern int func_02034AC4(s32 handle);
extern u8 ov112_id[];
extern Stage *MUSICAL_STAGE_SYS_Create(u32 heap, void *p);
extern void MUSICAL_STAGE_SYS_CreateNpcPerformer(Stage *s, u8 idx, u16 id, u8 v, u32 w, u16 x, u16 y);
extern void MUSICAL_STAGE_SYS_SetPerformerProp(Stage *s, u8 idx, u8 j, u16 id, s16 a, u8 b);
extern struct Deal *MUSICAL_PROGRAM_Create(u32 heap, struct Src *src, u16 lim);
struct Party;
extern void MUSICAL_PROGRAM_SplitBonus(u32 heap, struct Deal *d, struct Party *party);
extern void *MUSICAL_MCSS_AllocSmall(u32 a);
extern void MUSICAL_MCSS_LoadDistSave(u8 *p, u32 unused, void *sys, u8 kind, u16 heap);

int MUSICAL_STAGE_SYS_Init(void *proc, void *unused, Stage *prev)
{
    Work *w;
    u32 mask;

    GFL_HEAP_CreateChildHeap(1, 0x2E, 0xA8000);
    w = PROCSYS_AllocProcWork(proc, sizeof(Work), 0x2E);
    if (prev == 0) {
        func_02034AC4((u32)ov112_id);
        w->stage = MUSICAL_STAGE_SYS_Create(0x2E, 0);
        mask = 0xFF000000;
        MUSICAL_STAGE_SYS_CreateNpcPerformer(w->stage, 0, 0x147, 0, mask, 60, 0x2E);
        MUSICAL_STAGE_SYS_CreateNpcPerformer(w->stage, 1, 0x147, 0, mask >> 8, 120, 0x2E);
        MUSICAL_STAGE_SYS_CreateNpcPerformer(w->stage, 2, 0x147, 0, mask >> 16, -3, 0x2E);
        MUSICAL_STAGE_SYS_CreateNpcPerformer(w->stage, 3, 0x147, 0, 0x000000FF, -1, 0x2E);
        MUSICAL_STAGE_SYS_SetPerformerProp(w->stage, 0, 7, 0x13, 0, 0);
        MUSICAL_STAGE_SYS_SetPerformerProp(w->stage, 0, 8, 0x13, 0, 1);
        MUSICAL_STAGE_SYS_SetPerformerProp(w->stage, 0, 2, 0x10, 0, 2);
        MUSICAL_STAGE_SYS_SetPerformerProp(w->stage, 1, 1, 0x07, 0, 0);
        MUSICAL_STAGE_SYS_SetPerformerProp(w->stage, 1, 5, 0x09, 0, 1);
        MUSICAL_STAGE_SYS_SetPerformerProp(w->stage, 1, 7, 0x18, 0, 2);
        MUSICAL_STAGE_SYS_SetPerformerProp(w->stage, 1, 8, 0x2B, 0, 3);
        MUSICAL_STAGE_SYS_SetPerformerProp(w->stage, 2, 7, 0x1F, 0, 0);
        MUSICAL_STAGE_SYS_SetPerformerProp(w->stage, 2, 8, 0x1E, 0, 1);
        MUSICAL_STAGE_SYS_SetPerformerProp(w->stage, 2, 2, 0x0F, 0, 2);
        MUSICAL_STAGE_SYS_SetPerformerProp(w->stage, 3, 7, 0x1E, 0, 0);
        MUSICAL_STAGE_SYS_SetPerformerProp(w->stage, 3, 8, 0x1E, 0, 1);
        MUSICAL_STAGE_SYS_SetPerformerProp(w->stage, 3, 2, 0x15, 0, 2);
        *(u32 *)w->stage->f04[1] = 0;
        GFL_HEAP_CreateChildHeap(1, 0x802C, 0x80000);
        w->stage->f18 = MUSICAL_MCSS_AllocSmall(1);
        MUSICAL_MCSS_LoadDistSave(w->stage->f18, 0, 0, 0, 0x2C);
        w->stage->f14 = MUSICAL_PROGRAM_Create(0x2E, w->stage->f18, 0);
        MUSICAL_PROGRAM_SplitBonus(0x2E, w->stage->f14, (struct Party *)w->stage);
        w->stage->f04[0]->total = 75;
        w->stage->f04[1]->total = 45;
        w->stage->f04[2]->total = 30;
        w->stage->f04[3]->total = 0;
    } else {
        w->stage = prev;
    }
    return 1;
}
