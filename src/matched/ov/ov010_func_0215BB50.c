/*
 * function: SCRCMD_PROC_AddMonToPartySimple
 * address:  0x0215BB50
 * packet:   pkt_ov010_0215BB50
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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
    void *p0;
    void *p1;
    void *p2;
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
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *, void *);
extern int SCRCMD_PROC_AddMonToParty(void *a, void *b);

int SCRCMD_PROC_AddMonToPartySimple(void *a0, void *a1)
{
    void *h;
    u16 n;
    u16 *out;
    void *t1;
    void *t2;
    void *t3;
    Req r;

    SCRCMD_WORK_GetGameSystem(a1);
    h = SCRCMD_WORK_GetGameData(a1);
    n = SCRCMD_WORK_GetHeapId(a1);
    GAME_DATA_GetMyParty(h);
    GAME_DATA_GetMyStatus(h);
    out = SCRIPT_WORK_ReadWorkPointer(a0, a1);
    t1 = (void *)SCRIPT_WORK_ReadWorkValue(a0, a1);
    t2 = (void *)SCRIPT_WORK_ReadWorkValue(a0, a1);
    t3 = (void *)SCRIPT_WORK_ReadWorkValue(a0, a1);
    r.h = n;
    r.p0 = t1;
    r.p1 = t2;
    r.p2 = t3;
    r.z = 0;
    r.c0 = 2;
    r.c1 = 2;
    r.c2 = 2;
    r.c3 = 4;
    *out = SCRCMD_PROC_AddMonToParty(h, &r);
    return 0;
}
