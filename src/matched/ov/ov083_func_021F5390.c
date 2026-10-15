/*
 * function: GPOWER_EVENT_InitListWork
 * address:  0x021F5390
 * packet:   pkt_ov083_021F5390
 * region:   ov083
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte-correct. Only blocker: GPOWER_LoadPowerTable (arm9, thumb, unlabelled tail-call
 * stub, 0x02010F7C..0x02010F8C; the integrator's leaf). Its verified body (EXACT with
 * symbols: ARC_TOOL_LoadMember  0x02048F60  arm):
 *     extern int ARC_TOOL_LoadMember(int a, int b, int c);
 *     int GPOWER_LoadPowerTable(int a) { return ARC_TOOL_LoadMember(0x26, 0, a); }
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   GPOWER_LoadPowerTable  0x02010F7C  thumb
 *   func_02045B38  0x02045B38  arm
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   FLDMMDL_SysPauseMove  0x0216D9A0  thumb  ov010
 */

typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    int f8;
    int fC;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
    int f24;
    int f28;
    int f2C;
    int f30;
    int f34;
    int f38;
} Work;

typedef unsigned char  u8;
struct Ctx;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u32 FIELDMAP_GetMsgBg(u8 *p);
extern void *FIELDMAP_GetMmdlSys(u8 *p);
extern void *GPOWER_LoadPowerTable(u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void FLDMMDL_SysPauseMove(void *map);

void GPOWER_EVENT_InitListWork(Work *p, int a1, int a2)
{
    p->f2 = 0x15;
    p->f4 = (p->f2 & 0x7FFF) | 0x8000;
    p->f10 = a2;
    p->f8 = a1;
    p->fC = (int)GAMESYSTEM_GetGameData((const struct Ctx *)a1);
    p->f14 = FIELDMAP_GetMsgBg((u8 *)p->f10);
    p->f1C = (int)FIELDMAP_GetMmdlSys((u8 *)p->f10);
    p->f30 = (int)GPOWER_LoadPowerTable(p->f2);
    p->f28 = (int)func_02045B38(0, 3, 0x108, p->f2);
    p->f2C = (int)WORDSET_CreateDefault(p->f2);
    p->f34 = (int)STRBUF_Create(0x81, p->f2);
    p->f38 = (int)STRBUF_Create(0x81, p->f2);
    FLDMMDL_SysPauseMove((void *)p->f1C);
}
