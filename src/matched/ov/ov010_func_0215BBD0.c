/*
 * function: SCRCMD_PROC_AddMonToPartyDetailed
 * address:  0x0215BBD0
 * packet:   pkt_ov010_0215BBD0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sibling of SCRCMD_PROC_AddMonToPartySimple (same request record, eight reads instead of
 * three, three of them clamped to 2), and of SCRCMD_PROC_AddMonToBoxDetailed: the u16 locals
 * are what make the second clamp reload its value from the spill slot.
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRCMD_WORK_GetHeapId  0x0215A5CC  thumb  ov010
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_PROC_AddMonToParty  0x0215C510  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 h;
    int p0;
    int p1;
    int p2;
    int z;
    int c0;
    int c1;
    int c2;
    int c3;
} Req;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern u16 SCRCMD_WORK_GetHeapId(void *);
struct BigObj;
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern u16 SCRIPT_WORK_ReadWorkValue(void *, void *);
extern int SCRCMD_PROC_AddMonToParty(void *a, void *b);

int SCRCMD_PROC_AddMonToPartyDetailed(void *a0, void *a1)
{
    void *h;
    u16 n;
    u16 *out;
    u16 t1;
    u16 t2;
    u16 t3;
    u16 t4;
    u16 t5;
    u16 t6;
    u16 t7;
    u16 t8;
    Req r;

    SCRCMD_WORK_GetGameSystem(a1);
    h = SCRCMD_WORK_GetGameData(a1);
    n = SCRCMD_WORK_GetHeapId(a1);
    GAME_DATA_GetMyParty(h);
    GAME_DATA_GetMyStatus(h);
    out = SCRIPT_WORK_ReadWorkPointer(a0, a1);
    t1 = SCRIPT_WORK_ReadWorkValue(a0, a1);
    t2 = SCRIPT_WORK_ReadWorkValue(a0, a1);
    t3 = SCRIPT_WORK_ReadWorkValue(a0, a1);
    t4 = SCRIPT_WORK_ReadWorkValue(a0, a1);
    t5 = SCRIPT_WORK_ReadWorkValue(a0, a1);
    t6 = SCRIPT_WORK_ReadWorkValue(a0, a1);
    t7 = SCRIPT_WORK_ReadWorkValue(a0, a1);
    t8 = SCRIPT_WORK_ReadWorkValue(a0, a1);
    r.h = n;
    r.p0 = t1;
    r.p1 = t2;
    r.p2 = t3;
    r.z = t7;
    r.c0 = t4;
    if (r.c0 >= 3)
        r.c0 = 2;
    r.c1 = t5;
    if (r.c1 >= 3)
        r.c1 = 2;
    r.c2 = t6;
    if (r.c2 >= 3)
        r.c2 = 2;
    r.c3 = t8;
    *out = SCRCMD_PROC_AddMonToParty(h, &r);
    return 0;
}
