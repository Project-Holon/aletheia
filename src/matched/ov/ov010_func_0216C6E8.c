/*
 * function: NAMEIN_SETUP_StartNameBalloonFromRecord
 * address:  0x0216C6E8
 * packet:   pkt_ov010_0216C6E8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker: ARM9 0x02045CAC at +0080 has no outside witness. integrator-owned
 * unit_02045C44.c omits MSGDATA_ReadString from function:. Singleton TU split
 * leaves this caller OUT. No overlay leaves filed.
 * blocker: C below copied from ov122_func_021D5004.c, previously verified
 * EXACT 344 bytes through the ov070 blocker evidence; not recompiled here.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned int u32;
 * struct MsgEntry { u32 off; u16 len; u16 pad_06; };
 * struct MsgFile {
 *     u16 langCount; u16 count; u32 unk_04; u32 unk_08; u32 langOff[1];
 * };
 * struct MsgBank {
 *     const struct MsgFile *file;
 *     void *base;
 *     struct MsgEntry cache;
 *     u32 origin;
 *     void *stream;
 *     u16 heapId;
 *     u8 langIndex;
 *     u8 resident;
 * };
 * extern char MSGDATA_AllocSite[];
 * extern void *GFL_HEAP_Alloc(u32,u32,int,const char *,u16);
 * extern void func_020307B0(void *);
 * extern void ARC_TOOL_ReadHandle(void *,u32,void *);
 * extern void func_0204960C(void *,u32);
 * extern void STRBUF_Clear(void *);
 * extern void STRBUF_SetChars(void *,const void *,u16);
 * extern void func_02045E04(void *,u32);
 * extern void func_02046180(struct MsgBank *);
 * void MSGDATA_ReadString(struct MsgBank *bank,u32 index,void *dest)
 * {
 *     u32 size;
 *     struct MsgEntry *e;
 *     if (index >= bank->file->count) {
 *         STRBUF_Clear(dest);
 *         return;
 *     }
 *     func_02046180(bank);
 *     if (bank->resident == 0) {
 *         u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *         func_0204960C(bank->stream,pos + (index * 8 + 4));
 *         ARC_TOOL_ReadHandle(bank->stream,8,&bank->cache);
 *         e = &bank->cache;
 *     } else {
 *         e = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
 *     }
 *     if (bank->resident == 0) {
 *         void *buf;
 *         size = e->len * 2;
 *         buf = GFL_HEAP_Alloc((u16)((bank->heapId & 0x7fff) | 0x8000),size,
 *                            0,MSGDATA_AllocSite,0xd6);
 *         if (buf != 0) {
 *             func_0204960C(bank->stream,
 *                           e->off + (bank->origin
 *                               + bank->file->langOff[bank->langIndex]));
 *             ARC_TOOL_ReadHandle(bank->stream,size,buf);
 *             STRBUF_SetChars(dest,buf,e->len);
 *             func_020307B0(buf);
 *         }
 *     } else {
 *         STRBUF_SetChars(dest,(u8 *)bank->base + e->off,e->len);
 *     }
 *     func_02045E04(dest,index);
 * }
 * lever: task, ctx, x, proc declaration order restores pointer spill slots.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   MSGDATA_CreateFromArchive   0x02045B38  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   PMSI_PARAM_ToString  0x0202435C  thumb
 *   GAME_DATA_GetOccupyInfo  0x02012964  thumb
 *   FLDMMDL_SysSearchObjId  0x0216DE94  thumb  ov010
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELD_CAMERA_GetG3dCamera  0x0218EC2C  thumb  ov021
 *   SCRCMD_MSGWIN_GetBalloonOffset  0x021B09D8  thumb
 *   SCRCMD_MSGWIN_GetBalloonTailParams  0x021B09EC  thumb
 *   FIELD_MSGBG_AddTalkWin  0x0219129C  thumb  ov021
 *   NAMEIN_SETUP_RunNameBalloonEvent  0x0216C680  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef s32 fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct Spawn {
    void *sys;          /* 0x00 */
    u8 pad04[4];
    VecFx32 pos;        /* 0x08 */
    void *obj;          /* 0x14 */
    void *name;         /* 0x18 */
    u16 id;             /* 0x1C */
} Spawn;

typedef u32 (*TaskFn)(void *task, u32 *state, Spawn *work);

struct Actor;
struct Ctx;
struct Desc;
struct MsgBank;
struct Obj;
struct Rec;
struct U16Vec;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
struct BigObj;
struct Ent;
extern u32 FIELDMAP_GetMsgBg(u8 *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void *PMSI_PARAM_ToString(void *slots, unsigned int heap);
extern u32 GAME_DATA_GetOccupyInfo(const struct BigObj *p);
extern void *FLDMMDL_SysSearchObjId(void *p, u32 id);
extern void FLDMMDL_GetPos(const struct Actor *a, struct VecFx32 *out);
extern void *FIELDMAP_GetCamera(void *proc);
extern u32 FIELD_CAMERA_GetG3dCamera(u8 *p);
extern void SCRCMD_MSGWIN_GetBalloonOffset(VecFx32 *pos, VecFx32 *ofs, u32 a, void *m, u8 dir);
extern void SCRCMD_MSGWIN_GetBalloonTailParams(u8 dir, u32 *a, u32 *b);
extern struct Ent *FIELD_MSGBG_AddTalkWin(u8 *base, int idx, u32 c, u32 d, u32 f, u32 g);
extern int NAMEIN_SETUP_RunNameBalloonEvent(int a, int *st, int *o, u32 a3);

void *NAMEIN_SETUP_StartNameBalloonFromRecord(u8 *d, void *sys, u32 idx, u16 id, u8 dir)
{
    VecFx32 ofs;
    u32 a;
    u32 b;
    void *task;
    void *ctx;
    void *x;
    void *proc;
    Spawn *t;
    void *bank;
    void *m;
    u16 n;

    ctx = GAMESYSTEM_GetGameData(sys);
    proc = GAMESYSTEM_GetFieldMap(sys);
    x = (void *)FIELDMAP_GetMsgBg(proc);
    task = func_020122C0(sys, 0, NAMEIN_SETUP_RunNameBalloonEvent, 0xD8);
    t = func_020124E8(task);
    t->sys = sys;
    t->id = id;
    if (*(u16 *)((u32)d + 0xA0 + idx * 0x120) == 0xFFFF) {
        t->name = STRBUF_Create(0x300, 4);
        bank = MSGDATA_CreateFromArchive(0, 2, 0xB8, 4);
        n = *(u16 *)((u32)d + 0xA2 + idx * 0x120);
        if (n >= 0x3AE)
            n = 0;
        MSGDATA_ReadString(bank, n, t->name);
        MSGDATA_Delete(bank);
    } else {
        t->name = PMSI_PARAM_ToString((u16 *)((u32)d + 0xA0 + idx * 0x120), 4);
    }
    FLDMMDL_GetPos(FLDMMDL_SysSearchObjId((void *)GAME_DATA_GetOccupyInfo(ctx), t->id), &t->pos);
    m = FIELDMAP_GetCamera(proc);
    SCRCMD_MSGWIN_GetBalloonOffset(&t->pos, &ofs, FIELD_CAMERA_GetG3dCamera(m), m, dir);
    t->pos.x += ofs.x;
    t->pos.y += ofs.y;
    t->pos.z += ofs.z;
    SCRCMD_MSGWIN_GetBalloonTailParams(dir, &a, &b);
    t->obj = FIELD_MSGBG_AddTalkWin(x, a, (u32)(&t->pos), (u32)t->name, 0, b);
    return task;
}
