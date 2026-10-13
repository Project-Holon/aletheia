/*
 * function: UNION_MAIN_StepGroupActivity
 * address:  0x021743A4
 * packet:   pkt_ov012_021743A4
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stage machine on *state (20 states), same family as UNION_MAIN_StepPokemonTrade.
 * Pooled small words 0x16/0x17/0x89 are linker overlay ids
 * (ov022/ov023/ov137).
 *
 * symbols:
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02183C3C  0x02183C3C  thumb  ov022
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_02012944  0x02012944  thumb
 *   func_02183B60  0x02183B60  thumb  ov022
 *   func_020399A8  0x020399A8  arm
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   UNION_COMMAND_SendAppQuitRequest  0x02173E1C  thumb  ov012
 *   func_02183F84  0x02183F84  thumb  ov022
 *   UNION_COMMAND_SendAppQuitCancel  0x02173EC8  thumb  ov012
 *   func_0218401C  0x0218401C  thumb  ov022
 *   func_021841A0  0x021841A0  thumb  ov022
 *   UNION_COMMAND_SendAppJoinData  0x02173F90  thumb  ov012
 *   func_0218402C  0x0218402C  thumb  ov022
 *   UNION_COMMAND_SendAppLeaveData  0x02174084  thumb  ov012
 *   func_021840AC  0x021840AC  thumb  ov022
 *   func_021736E0  0x021736E0  thumb  ov012
 *   func_0203D1E8  0x0203D1E8  arm
 *   func_0203D7BC  0x0203D7BC  arm
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   func_02012984  0x02012984  thumb
 *   func_02029DF4  0x02029DF4  thumb
 *   GFL_USE_ChangeBgm  0x02005DA4  thumb
 *   GFL_USE_IsBgmFading  0x02005E50  thumb
 *   func_02183BE0  0x02183BE0  thumb  ov022
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   ov022_id       0x00000016  data   a1
 *   ov023_id       0x00000017  data   a1
 *   ov137_id       0x00000089  data   a1
 *   gOekakiProcData     0x02186B30  data   ov023  a4
 *   gGuru2ProcData     0x021E1A2C  data   ov137  a4
 *
 * evidence: 0x02029DF4 is an unlabelled ARM9 thunk ("ldr r3, =func_02029EB4;
 * bx r3"), seeded in layout/function_starts.txt from the bl sites in ov020
 * and ov021 (0x021AF018 and others), so +0x21E attests as `label`.
 * 0x02005DA4 is an 8-byte ARM9 wrapper ("push {r3, lr}; bl 0x02005F70;
 * pop {r3, pc}") between GFL_USE_CancelChangeAndPlayBgm's pop and GFL_USE_PlayFanfare; the bl at
 * +0x22C is its only reference in the image, so it is seeded from that site;
 * the wrapper is matched EXACT (src/matched/arm9/GFL_USE_ChangeBgm.c), so +0x22C
 * attests as `matched`.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Save {
    u8  pad0[8];
    u32 f8;
} Save;

typedef struct Req {
    void *f0;
    u8    pad4[0x10];
    int   f14;
} Req;

typedef struct Sub {
    u8   pad0[8];
    Req *f8;
} Sub;

typedef struct Local {
    u8    f0;
    u8    pad1[0x59];
    u8    lo5A : 1;
    u8    flag5A : 1;
    u8    hi5A : 6;
    u8    pad5B[5];
} Local;

typedef struct Self {
    Save *f0;
    u8    pad4[0x282c];
    Local l;
    u8    pad2890[0xc98];
    void *f3528;
    u8    pad352C[0x1c];
    Sub   f3548;
} Self;

struct Evt;
extern u32 func_0200FB24(void);
extern void func_02183C3C(u8 *s, u8 *c);
struct BigObj;
struct Ctx;
struct IcaAnime;
struct Rec20;
extern int func_021BE8D4(void *a, int b, int sel, int d);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int FIELD_STATUS_CreateFieldCloseEvent(int a0, int a1);
extern int   func_02034AC4(signed int id);
extern void  func_02034A5C(int id);
extern u8 *func_02012944(void *p);
extern u8 *func_02183B60(u8 *a, int heap, int kind, struct Rec20 *src);
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern void func_02039C68(struct Link *a0, unsigned int a1, unsigned int a2);
extern unsigned int func_02039CB4(struct Link *a0, unsigned int a1, unsigned int a2);
extern u32 UNION_COMMAND_SendAppQuitRequest(void);
extern u8 func_02183F84(u8 *p);
extern int   UNION_COMMAND_SendAppQuitCancel(void);
extern int func_0218401C(u8 *p);
extern unsigned char func_021841A0(unsigned char *p);
extern int   UNION_COMMAND_SendAppJoinData(u8 a, u32 b);
extern int func_0218402C(u8 *p);
extern int   UNION_COMMAND_SendAppLeaveData(u8 a, u32 b);
extern void func_021840AC(u8 *s);
extern void func_021736E0(unsigned int x);
extern void func_0203D1E8(u32 unused, void *arg);
extern void func_0203D7BC(u8 a0);
extern void GAMESYSTEM_CallProc(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 GAMESYSTEM_GetProcStatus(const struct Ctx *p);
extern u8 func_02012984(const struct BigObj *p);
extern unsigned int func_02029DF4(void *a, unsigned int id, unsigned int which);
extern void GFL_USE_ChangeBgm(unsigned int a, unsigned short b, int c, int d);
extern int   GFL_USE_IsBgmFading(void);
extern void  func_02183BE0(void *p);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *a0);

extern char ov022_id[];
extern char ov023_id[];
extern char ov137_id[];
extern u8 gOekakiProcData[];
extern u8 gGuru2ProcData[];

int UNION_MAIN_StepGroupActivity(u32 a0, Self *self, u32 a2, u32 a3, void *obj, u32 a5, u8 *state)
{
    Sub *sub = &self->f3548;
    Local *l = &self->l;
    Req *r;
    int v;

    if (func_0200FB24() != 0 && *state > 2 && *state <= 13)
        *state = 16;
    if (self->f3528 != 0)
        func_02183C3C(self->f3528, (u8 *)self);

    switch (*state) {
    case 0:
        func_02012374(obj, (void *)func_021BE8D4((void *)a0, a2, 0, 0));
        (*state)++;
        break;
    case 1:
        func_02012374(obj, (void *)FIELD_STATUS_CreateFieldCloseEvent(a0, a2));
        (*state)++;
        break;
    case 2:
        func_02034AC4((u32)ov022_id);
        self->f3528 = func_02183B60((u8 *)self, 3, 5, (struct Rec20 *)func_02012944((void *)self->f0->f8));
        if (l->flag5A == 1)
            *state = 5;
        else
            (*state)++;
        break;
    case 3:
        func_02039C68((struct Link *)func_020399A8(), 9, 0x14);
        (*state)++;
        break;
    case 4:
        if (func_02039CB4((struct Link *)func_020399A8(), 9, 0x14) == 1)
            *state = 7;
        break;
    case 5:
        if (UNION_COMMAND_SendAppQuitRequest() == 1)
            (*state)++;
        break;
    case 6:
        if (func_02183F84(self->f3528) == 1)
            *state = 7;
        break;
    case 7:
        if (UNION_COMMAND_SendAppQuitCancel() == 1)
            (*state)++;
        break;
    case 8:
        if (func_0218401C(self->f3528) == 1)
            (*state)++;
        break;
    case 9:
        v = func_021841A0(self->f3528);
        if (UNION_COMMAND_SendAppJoinData(v, (u32)func_02012944((void *)self->f0->f8)) == 1)
            (*state)++;
        break;
    case 10:
        if (func_0218402C(self->f3528) == 1)
            (*state)++;
        break;
    case 11:
        if (l->flag5A == 1) {
            v = func_021841A0(self->f3528);
            if (UNION_COMMAND_SendAppLeaveData(v, (u32)func_02012944((void *)self->f0->f8)) == 1) {
                func_021840AC(self->f3528);
                *state = 13;
            }
        } else {
            func_021736E0(l->f0);
            func_02039C68((struct Link *)func_020399A8(), 10, 0x14);
            *state = 12;
        }
        break;
    case 12:
        if (func_02039CB4((struct Link *)func_020399A8(), 10, 0x14) == 1) {
            func_0203D1E8((u32)func_020399A8(), (void *)1);
            *state = 13;
        }
        break;
    case 13:
        func_0203D7BC(0);
        if (l->f0 == 3) {
            r = sub->f8;
            r->f0 = self->f3528;
            GAMESYSTEM_CallProc((struct IcaAnime *)a0, (u32)ov023_id, gOekakiProcData, r);
        } else {
            r = sub->f8;
            r->f0 = self->f3528;
            GAMESYSTEM_CallProc((struct IcaAnime *)a0, (u32)ov137_id, gGuru2ProcData, r);
        }
        (*state)++;
        break;
    case 14:
        if (GAMESYSTEM_GetProcStatus((const struct Ctx *)a0) != 0)
            break;
        if (l->f0 == 0x19) {
            if (sub->f8->f14 == 1) {
                GFL_USE_ChangeBgm((u16)func_02029DF4((void *)self->f0->f8, 0x1a6, func_02012984((const struct BigObj *)self->f0->f8)), (int)0xffff, 6, 0x3c);
                *state = 15;
            } else {
                *state = 16;
            }
        } else {
            *state = 16;
        }
        break;
    case 15:
        if (GFL_USE_IsBgmFading() == 0)
            *state = 16;
        break;
    case 16:
        if (self->f3528 != 0) {
            func_02183BE0(self->f3528);
            self->f3528 = 0;
            func_02034A5C((int)ov022_id);
        }
        *state = 17;
        break;
    case 17:
        func_02012374(obj, FIELD_STATUS_CreateFieldOpenEvent((void *)a0));
        (*state)++;
        break;
    case 18:
        func_02012374(obj, (void *)func_021BE92C((void *)a0, a2, 0, 0, 1, 0, 0));
        (*state)++;
        break;
    case 19:
    default:
        return 1;
    }
    return 0;
}
