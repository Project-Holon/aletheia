/*
 * function: SCRCMD_PROC_AddMonToBoxDetailed
 * address:  0x0215C200
 * packet:   pkt_ov010_0215C200
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command, sibling of SCRCMD_PROC_AddMonToBoxSimple: reads a destination variable
 * and eight arguments, three of them clamped to 2 when 3 or more, fills
 * the 0x24-byte spec SCRCMD_PROC_AddMonToBox consumes and stores its result.
 *
 * The arguments are u16 (SCRIPT_WORK_ReadWorkValue returns u16): the widening copy
 * into each int field is why the clamp of the spilled one reloads its
 * slot, and comparing the int field (not the u16 local) gives blt.
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRCMD_WORK_GetHeapId  0x0215A5CC  thumb  ov010
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_PROC_AddMonToBox  0x0215C4C8  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Spec {
    u16 f00;            /* 0x00 */
    u16 pad02;
    int f04;            /* 0x04 */
    int f08;            /* 0x08 */
    int f0c;            /* 0x0C */
    int f10;            /* 0x10 */
    int f14;            /* 0x14 */
    int f18;            /* 0x18 */
    int f1c;            /* 0x1C */
    int f20;            /* 0x20 */
} Spec;

extern void *SCRCMD_WORK_GetGameSystem(void *vm);
extern void *SCRCMD_WORK_GetGameData(void *vm);
extern u16 SCRCMD_WORK_GetHeapId(void *vm);
struct BigObj;
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *c, void *vm);
extern u16 SCRIPT_WORK_ReadWorkValue(void *c, void *vm);
extern int SCRCMD_PROC_AddMonToBox(void *a, void *b);

int SCRCMD_PROC_AddMonToBoxDetailed(void *c, void *vm)
{
    void *sys;
    u16 v;
    u16 *dst;
    u16 a;
    u16 b;
    u16 d;
    u16 e;
    u16 f;
    u16 g;
    u16 h;
    u16 i;
    Spec s;

    SCRCMD_WORK_GetGameSystem(vm);
    sys = SCRCMD_WORK_GetGameData(vm);
    v = SCRCMD_WORK_GetHeapId(vm);
    GAME_DATA_GetMyParty(sys);
    GAME_DATA_GetMyStatus(sys);
    dst = SCRIPT_WORK_ReadWorkPointer(c, vm);
    a = SCRIPT_WORK_ReadWorkValue(c, vm);
    b = SCRIPT_WORK_ReadWorkValue(c, vm);
    d = SCRIPT_WORK_ReadWorkValue(c, vm);
    e = SCRIPT_WORK_ReadWorkValue(c, vm);
    f = SCRIPT_WORK_ReadWorkValue(c, vm);
    g = SCRIPT_WORK_ReadWorkValue(c, vm);
    h = SCRIPT_WORK_ReadWorkValue(c, vm);
    i = SCRIPT_WORK_ReadWorkValue(c, vm);
    s.f00 = v;
    s.f04 = a;
    s.f08 = b;
    s.f0c = d;
    s.f10 = h;
    s.f14 = e;
    if (s.f14 >= 3) {
        s.f14 = 2;
    }
    s.f18 = f;
    if (s.f18 >= 3) {
        s.f18 = 2;
    }
    s.f1c = g;
    if (s.f1c >= 3) {
        s.f1c = 2;
    }
    s.f20 = i;
    *dst = SCRCMD_PROC_AddMonToBox(sys, &s);
    return 0;
}
