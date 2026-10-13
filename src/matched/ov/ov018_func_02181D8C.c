/*
 * function: EVENT_COMM_COMMON_CreateSupportMsgEvent
 * address:  0x02181D8C
 * packet:   pkt_ov018_02181D8C
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  two unlabelled arm9 thumb leaves (the integrator's), no witness outside the range:
 *   0x02008494 (unresolved site +0034), 0x0202E82C (site +002E). Verified EXACT in scratch:
 *     void MYSTATUS_Copy(void *a, void *b) { MI_CpuCopy8(a, b, 0x20); }   (MI_CpuCopy8 arm)
 *     typedef struct { int f00; int f04; } S;
 *     void *COMM_PLAYER_SUPPORT_GetActiveRecord(S *p) { if (p->f04 != 0) return (char *)p + 0x2C; return (char *)p + 0xC; }
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetPmsWork  0x02012F20  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   MYSTATUS_Create  0x0200846C  thumb
 *   COMM_PLAYER_SUPPORT_GetActiveRecord  0x0202E82C  thumb
 *   MYSTATUS_Copy  0x02008494  thumb
 *   EVENT_COMM_COMMON_InitMsgBox  0x0217F2B4  thumb
 *   EVENT_COMM_COMMON_SupportMsgEventMain  0x02181DD4  thumb  ov018
 */

typedef unsigned char u8;

typedef unsigned int   u32;
struct Ctx;
struct Desc;
struct Obj;
struct S;
void *GAMESYSTEM_GetGameData(const struct Ctx *p);
int GAME_DATA_GetPmsWork(int p0);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
void *MYSTATUS_Create(int a0);
void *COMM_PLAYER_SUPPORT_GetActiveRecord(struct S *p);
void MYSTATUS_Copy(void *, void *);
void EVENT_COMM_COMMON_InitMsgBox(void *, void *);
int EVENT_COMM_COMMON_SupportMsgEventMain();

void *EVENT_COMM_COMMON_CreateSupportMsgEvent(void *a, void *b)
{
    void *w;
    void *r;
    u8 *t;

    w = (void *)GAME_DATA_GetPmsWork((int)GAMESYSTEM_GetGameData(a));
    r = func_020122C0(a, 0, EVENT_COMM_COMMON_SupportMsgEventMain, 0x34);
    t = func_020124E8(r);
    *(void **)(t + 0x30) = MYSTATUS_Create((int)b);
    MYSTATUS_Copy(COMM_PLAYER_SUPPORT_GetActiveRecord(w), *(void **)(t + 0x30));
    EVENT_COMM_COMMON_InitMsgBox(t, a);
    return r;
}
