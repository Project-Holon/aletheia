/*
 * function: FIELD_WFBC_DATA_LOCAL_CreatePersonTalkEvent
 * address:  0x021870C4
 * packet:   pkt_ov020_021870C4
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   INTRUDE_COMM_GetReturnSlots  0x02158434  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   FIELD_WFBC_DATA_LOCAL_PersonTalkEventMain  0x021871F8  thumb  ov020
 *   func_020124E8  0x020124E8  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   func_02045B38  0x02045B38  arm
 *   func_0201EC64  0x0201EC64  thumb
 *   func_020127D0  0x020127D0  thumb
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb  ov021
 *   FIELD_G3D_MAPPER_GetWfbc  0x0218DC70  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   GAME_DATA_GetMysteryRecvFlagB  0x020127F0  thumb
 *   FIELD_PLAYER_GetFrontGridPos  0x021A3460  thumb  ov021
 *   FLDMMDL_SysSearchGridPos  0x0216DDC0  thumb  ov010
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FIELD_WFBC_DATA_LOCAL_GetPersonIndexFromMmdl  0x02186090  thumb  ov020
 *   FIELD_WFBC_GetPeople  0x0219390C  thumb  ov021
 */
#include "../include/Obj01343.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;

typedef unsigned int   u32;
struct Ctx;
struct Desc;
struct Obj;
u16 FIELDMAP_GetHeapId(u8 *p);
u32 FIELDMAP_GetMsgBg(u8 *p);
void *GAMESYSTEM_GetGameData(const struct Ctx *p);
unsigned int GAMESYSTEM_GetGameComm(const struct Ctx *p);
struct MsgBank;
struct U16Vec;
struct WordSet;
int INTRUDE_COMM_GetWorkIfRunning(int a0);
void *INTRUDE_COMM_GetReturnSlots(char *p);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
int FIELD_WFBC_DATA_LOCAL_PersonTalkEventMain(void *a, int *st, char *o);
struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
struct WordSet *func_0201EC64(u32 heap);
u8 *func_020127D0(u8 *o, u32 idx);
u32 FIELDMAP_GetG3dMapper(u8 *p);
void *FIELD_G3D_MAPPER_GetWfbc(u8 *p);
struct Obj00020;
void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
void *FIELDMAP_GetMmdlSys(u8 *p);
int GAME_DATA_GetMysteryRecvFlagB(int a0);
int FIELD_PLAYER_GetFrontGridPos(u32 a, u32 b, u32 c, u32 d);
void *FLDMMDL_SysSearchGridPos(u32 a, u32 b, u32 c, u32 d);
struct Actor;
struct VecFx32;
void FLDMMDL_GetPos(const struct Actor *a, struct VecFx32 *b);
int FIELD_WFBC_DATA_LOCAL_GetPersonIndexFromMmdl(void *p);
void *FIELD_WFBC_GetPeople(void *a, unsigned int b);

void *FIELD_WFBC_DATA_LOCAL_CreatePersonTalkEvent(void *a0, void *a1)
{
    int n;
    int c54;
    void *h;
    void *w;
    void *ret;
    void *b;
    s16 v[3];
    char *o;
    void *a;
    void *c;
    int d;
    int e;
    void *x;

    n = FIELDMAP_GetHeapId(a1);
    c54 = FIELDMAP_GetMsgBg(a1);
    h = GAMESYSTEM_GetGameData(a0);
    w = (void *)INTRUDE_COMM_GetWorkIfRunning((int)((void *)GAMESYSTEM_GetGameComm(a0)));
    if (w == 0)
        return 0;
    w = INTRUDE_COMM_GetReturnSlots(w);
    ret = func_020122C0(a0, 0, FIELD_WFBC_DATA_LOCAL_PersonTalkEventMain, 0x58);
    o = func_020124E8(ret);
    ((struct Obj01343 *)o)->f0 = a0;
    ((struct Obj01343 *)o)->f4 = a1;
    ((struct Obj01343 *)o)->f20 = (int)STRBUF_Create(0x100, n);
    ((struct Obj01343 *)o)->f24 = (int)STRBUF_Create(0x100, n);
    ((struct Obj01343 *)o)->f18 = (int)func_02045B38(0, 3, 0x142, n);
    ((struct Obj01343 *)o)->f1C = (int)func_0201EC64(n);
    ((struct Obj01343 *)o)->fC = c54;
    ((struct Obj01343 *)o)->f40 = w;
    ((struct Obj01343 *)o)->f56 = 1;
    ((struct Obj01343 *)o)->f8 = (n & 0x7FFF) | 0x8000;
    ((struct Obj01343 *)o)->f44 = (int)func_020127D0(h, 1);
    ((struct Obj01343 *)o)->f48 = (int)func_020127D0(h, 0);
    a = FIELD_G3D_MAPPER_GetWfbc((u8 *)FIELDMAP_GetG3dMapper(a1));
    b = FIELDMAP_GetFieldPlayer(a1);
    c = FIELDMAP_GetMmdlSys(a1);
    GAME_DATA_GetMysteryRecvFlagB((int)GAMESYSTEM_GetGameData(a0));
    FIELD_PLAYER_GetFrontGridPos((u32)b, (u32)(&v[2]), (u32)(&v[1]), (u32)(&v[0]));
    d = (int)FLDMMDL_SysSearchGridPos((u32)c, v[2], v[0], 0);
    FLDMMDL_GetPos((const struct Actor *)d, (struct VecFx32 *)(o + 0x34));
    e = FIELD_WFBC_DATA_LOCAL_GetPersonIndexFromMmdl((void *)d);
    x = FIELD_WFBC_GetPeople(a, e);
    ((struct Obj01343 *)o)->f28 = a;
    ((struct Obj01343 *)o)->f2C = x;
    ((struct Obj01343 *)o)->f30 = d;
    ((struct Obj01343 *)o)->f4C = e;
    return ret;
}
