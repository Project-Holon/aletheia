/*
 * function: SCRCMD_PALPARK_CallPalParkProc
 * address:  0x021CC570
 * packet:   pkt_ov021_021CC570
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Launches overlay 0x6B (107) over an 8-byte record with the ov107 process
 * table at 0x021F6D78, parks the result in the script slot.
 *
 * MATCH, bytes exact. Blocker: the two pooled ABS32 words ov107_id (0x6B)
 * and d_021F6D78 (ov107 data, contested/no witness) have no witness, and
 * FIELD_STATUS_CreateSubProcNoFadeCallbackEvent is not in match.py OVERLAY_ID_CONSUMERS, so the overlay-id
 * class refuses both. Dropping the ov107 token (data a4) does not help.
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   func_02030734  0x02030734  arm
 *   FIELD_STATUS_CreateSubProcNoFadeCallbackEvent  0x02014840  thumb
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   d_021DE5A8     0x021DE5A8  data
 *   ov107_id       0x0000006B  data
 *   d_021F6D78     0x021F6D78  data  ov107
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Rec {
    u8 f0;
    u8 pad1[3];
    void *f4;
} Rec;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *SCRCMD_WORK_GetGameData(void *a0);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *FIELD_STATUS_CreateSubProcNoFadeCallbackEvent(char *a0, int a1, int a2, int a3, int a4, int a5, int a6);
extern void SCRIPT_SYS_CallEvent(void *a, void *b);
extern const char d_021DE5A8[];
extern const u8 d_021F6D78[];
extern u8 ov107_id[];

int SCRCMD_PALPARK_CallPalParkProc(u32 unused, u32 a)
{
    void *s;
    void *sys;
    void *v;
    void *x;
    Rec *r;

    s = SCRCMD_WORK_GetScriptWork((void *)a);
    sys = SCRCMD_WORK_GetGameSystem((void *)a);
    v = SCRCMD_WORK_GetGameData((void *)a);
    x = GAMESYSTEM_GetFieldMap((void *)sys);
    r = func_02030734(4, 8, 0, d_021DE5A8, 0x44);
    r->f0 = 0;
    r->f4 = v;
    SCRIPT_SYS_CallEvent(s, FIELD_STATUS_CreateSubProcNoFadeCallbackEvent(sys, (int)x, (u32)ov107_id, (int)d_021F6D78, (int)r, 0, (int)r));
    return 1;
}
