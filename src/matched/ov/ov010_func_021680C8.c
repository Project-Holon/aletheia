/*
 * function: FLD_BTL_INST_TOOL_CreateTrainerMsgEvent
 * address:  0x021680C8
 * packet:   pkt_ov010_021680C8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   func_02045B38  0x02045B38  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   PMSI_PARAM_ToString  0x0202435C  thumb
 *   GAME_DATA_GetOccupyInfo  0x02012964  thumb
 *   FLDMMDL_SysSearchObjId  0x0216DE94  thumb
 *   FLDMMDL_GetPos  0x0216D88C  thumb
 *   FIELD_MSGBG_AddTalkWin  0x0219129C  thumb ov021
 *   FLD_BTL_INST_TOOL_TrainerMsgEventMain  0x02168174  thumb
 *
 * evidence: 0x0202435C is an unlabelled ARM9 thunk ("ldr r3, =PMSI_PARAM_ToStringWords; movs r2, #2; bx r3") that the
 * prologue sweep misses; its start is seeded in layout/function_starts.txt
 * from the raw bl sites elsewhere in the image (ov069 0x021BA21A, ov093 0x021D1894, ov010 0x0216C778), so the call
 * attests as `label`.
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    u8 pad0[0x18];
    u16 f18;
    u16 f1a;
    u8 pad1c[0x120 - 0x1c];
} E;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
} R;

struct BigObj;
struct Ctx;
struct Desc;
struct Ent;
struct MsgBank;
struct Rec;
struct U16Vec;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern u32 FIELDMAP_GetMsgBg(u8 *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
struct Obj;
extern void *func_020124E8(struct Obj *p);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void *PMSI_PARAM_ToString(void *slots, unsigned int heap);
extern u32 GAME_DATA_GetOccupyInfo(const struct BigObj *p);
extern void *FLDMMDL_SysSearchObjId(void *map, u32 id);
struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *, struct VecFx32 *);
extern struct Ent *FIELD_MSGBG_AddTalkWin(u8 *base, int idx, u32 c, u32 d, u32 f, u32 g);
extern int FLD_BTL_INST_TOOL_TrainerMsgEventMain(int a0, int a1, int a2);

int FLD_BTL_INST_TOOL_CreateTrainerMsgEvent(int a, E *b, int c, int d)
{
    int hd;
    int h;
    int g;
    R *p;
    h = (int)GAMESYSTEM_GetGameData((const struct Ctx *)a);
    g = FIELDMAP_GetMsgBg(GAMESYSTEM_GetFieldMap((void *)a));
    hd = (int)func_020122C0((void *)a, 0, FLD_BTL_INST_TOOL_TrainerMsgEventMain, 0x1c);
    p = func_020124E8((struct Obj *)hd);
    p->f0 = a;
    if (b->f18 == 0xFFFF) {
        int t;
        p->f14 = (int)STRBUF_Create(0x5c, 4);
        t = (int)func_02045B38(0, 2, 0xb8, 4);
        MSGDATA_ReadString((struct MsgBank *)t, b->f1a, (void *)p->f14);
        MSGDATA_Delete((struct Rec *)t);
    } else {
        p->f14 = (int)PMSI_PARAM_ToString(&b[c].f18, 4);
    }
    FLDMMDL_GetPos((const struct Actor *)FLDMMDL_SysSearchObjId((void *)GAME_DATA_GetOccupyInfo((const struct BigObj *)h), d), (struct VecFx32 *)&p->f4);
    p->f10 = (int)FIELD_MSGBG_AddTalkWin((u8 *)g, 1, (u32)(&p->f4), p->f14, 0, 0);
    return hd;
}
