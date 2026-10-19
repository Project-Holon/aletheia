/*
 * function: MUSICAL_EVENT_Create
 * address:  0x02155A98
 * packet:   pkt_ov010_02155A98
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Creates the ov010 link sequence task (MUSICAL_EVENT_Main over a Seq) and
 * either starts the wireless exchange (state 11) or shuffles the four
 * member slots and deals locally (state 13). The owner back-pointer is
 * stored through s->link while the session is read through the
 * parameter: storing through the parameter enregisters it instead.
 *
 * symbols:
 *   MUSICAL_EVENT_Main  0x02155C0C  thumb  ov010
 *   GAME_BEACON_SEARCH_SetNamedEvent  0x0216576C  thumb  ov010
 *   MUSICAL_PROGRAM_Create  0x02157028  thumb  ov010
 *   MUSICAL_MCSS_AllocDistSave  0x021F685C  thumb  ov112
 *   MUSICAL_MCSS_LoadDistSave  0x021F68BC  thumb  ov112
 *   STA_NET_GetRole  0x021FD904  thumb  ov132
 *   MUS_COMM_FUNC_InitWork  0x021FC848  thumb  ov132
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   GAME_DATA_GetSaveBlock2A  0x02012F44  thumb
 *   MUSICAL_SAVE_GetScriptSetting  0x0200A7C8  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   POKE_TOOL_CastToBoxParam  0x020185F0  thumb
 *   MUSICAL_SAVE_GetFanPoints  0x0200A81C  thumb
 *   func_02005728  0x02005728  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Seq;

struct Link {
    struct Seq *owner;  /* 0x00 */
    void *sess;         /* 0x04 */
};

typedef struct Seq {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    struct Link *link;  /* 0x08 */
    u32 state;          /* 0x0C */
    u8 f10;             /* 0x10 */
    u8 pad11[3];
    u32 f14;            /* 0x14 */
    void *f18;          /* 0x18 */
    void *f1c;          /* 0x1C */
    void *f20;          /* 0x20 */
    void *f24;          /* 0x24 */
    void *f28;          /* 0x28 */
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

typedef u32 (*TaskFn)(void *task, u32 *state, Seq *work);

extern void GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);
struct Big;
struct BigObj;
struct Deal;
struct Desc;
struct Obj;
struct Src;
struct U16Vec;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
struct Ctx;
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern void *POKEPARTY_GetMember(void *list, u32 i);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern void GAME_BEACON_SEARCH_SetNamedEvent(void *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void *GAME_DATA_GetSaveBlock2A(void *h);
extern void *MUSICAL_MCSS_AllocDistSave(u32 heap);
extern int STA_NET_GetRole(int *p);
extern u8 MUSICAL_SAVE_GetScriptSetting(struct Big *p);
extern void MUSICAL_MCSS_LoadDistSave(u8 *p, u32 unused, void *sys, u8 kind, u16 heap);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void *POKE_TOOL_CastToBoxParam(void *p);
extern void MUS_COMM_FUNC_InitWork(u8 *p, void *a, void *b, int unused, void *d, u16 heap);
extern u16 MUSICAL_SAVE_GetFanPoints(struct Big *p);
extern u32 func_02005728(u32 n);
extern struct Deal *MUSICAL_PROGRAM_Create(u32 heap, struct Src *src, u16 lim);
extern int MUSICAL_EVENT_Main(void *evt, void *unused, struct Seq *s);

void *MUSICAL_EVENT_Create(void *a, void *b, u8 c, u32 d, struct Link *link)
{
    void *task;
    Seq *s;
    void *tmp;

    GFL_HEAP_CreateChildHeap(1, 0x802C, 0x42000);
    task = func_020122C0(a, 0, MUSICAL_EVENT_Main, sizeof(Seq));
    s = func_020124E8(task);
    s->f00 = a;
    s->f04 = b;
    s->f14 = d;
    s->f1c = GAME_DATA_GetSaveControl(b);
    s->f20 = (void *)GAMESYSTEM_GetGameComm(a);
    s->link = link;
    s->link->owner = s;
    s->f28 = link->sess;
    s->f50 = 0;
    s->f38 = 0;
    tmp = STRBUF_Create(11, 4);
    s->f18 = POKEPARTY_GetMember(GAME_DATA_GetMyParty(s->f04), c);
    POKE_TOOL_GetPartyValue(s->f18, 0x73, (u32)tmp);
    GAME_BEACON_SEARCH_SetNamedEvent(tmp);
    STRBUF_Delete(tmp);
    s->f2c = 0;
    s->f30 = 0;
    s->f34 = 0;
    s->f40 = GAME_DATA_GetSaveBlock2A(b);
    s->f24 = MUSICAL_MCSS_AllocDistSave(4);
    if (s->f14 == 0 || STA_NET_GetRole(s->link->sess) == 1)
        MUSICAL_MCSS_LoadDistSave(s->f24, (u32)s->f1c, s->f04, MUSICAL_SAVE_GetScriptSetting(s->f40), 0x2C);
    if (s->f14 == 1) {
        s->state = 11;
        s->f10 = 0;
        MUS_COMM_FUNC_InitWork(s->f28, GAME_DATA_GetMyStatus(s->f04), POKE_TOOL_CastToBoxParam(s->f18), (int)s->f20, s->f24, 4);
    } else {
        u16 lim = MUSICAL_SAVE_GetFanPoints(s->f40);
        u8 i;
        u8 j;
        u8 k;
        u8 t;

        for (i = 0; i < 4; i++)
            s->f44[i] = i;
        for (i = 0; i < 10; i++) {
            for (j = 0; j < 4; j++) {
                k = func_02005728(4);
                t = s->f44[j];
                s->f44[j] = s->f44[k];
                s->f44[k] = t;
            }
        }
        s->f4c = s->f44[0];
        s->f38 = MUSICAL_PROGRAM_Create(4, s->f24, lim);
        s->state = 13;
        s->f10 = 0;
    }
    return task;
}
