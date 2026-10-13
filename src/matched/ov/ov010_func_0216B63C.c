/*
 * function: FIELD_G3D_MAP_CmdStartMission
 * address:  0x0216B63C
 * packet:   pkt_ov010_0216B63C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_0200E394  0x0200E394  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   func_0200C334  0x0200C334  thumb
 *   func_0200C344  0x0200C344  thumb
 *   func_0200C358  0x0200C358  thumb
 *   func_0203F524  0x0203F524  arm
 *   func_0200C384  0x0200C384  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;
struct Blk34;
typedef unsigned long long u64;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_0200C0F0(void *sys);
extern void *func_0200E394(void *a0);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern void func_0200C334(struct Blk34 *p, u8 v);
extern void func_0200C344(struct Blk34 *p, u8 i, u8 v);
extern void func_0200C358(struct Blk34 *p, u32 i, int v);
extern u64 func_0203F524();
extern void func_0200C384(struct Blk34 *p, u32 lo, u32 hi);

int FIELD_G3D_MAP_CmdStartMission(int a0, int a1)
{
    void *h;
    u16 s[3];
    int i;
    void *w;
    int k;
    int z;
    u64 t;

    SCRCMD_WORK_GetScriptWork((void *)a1);
    w = GAME_DATA_GetSaveControl((struct Big *)SCRCMD_WORK_GetGameData((void *)a1));
    h = func_0200C0F0(w);
    func_0200E394(w);
    k = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    s[0] = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    s[1] = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    s[2] = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    func_0200C334(h, k);
    z = 0;
    for (i = 0; i < 3; i++) {
        func_0200C344(h, i, s[i]);
        func_0200C358(h, (u8)i, z);
    }
    t = func_0203F524();
    func_0200C384(h, (u32)t, (u32)(t >> 32));
    return z;
}
