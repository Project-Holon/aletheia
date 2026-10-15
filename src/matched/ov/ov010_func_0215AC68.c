/*
 * function: SCRCMD_WORK_CmdSetMiscFlag
 * address:  0x0215AC68
 * packet:   pkt_ov010_0215AC68
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetMiscSave  0x02012F08  thumb
 *   BEACON_SetFlag  0x0200C248  thumb
 *   GF_STANDARD_SetField00_F4E4  0x0203F4E4  arm
 *   GAME_DATA_GetSaveBlock21  0x02012F5C  thumb
 *   func_02008A7C  0x02008A7C  thumb
 */

typedef struct {
    int a;
    int b;
    int c;
    int d;
} V4;

extern unsigned int SCRIPT_WORK_ReadWorkValue(void *, void *);
extern void *SCRCMD_WORK_GetGameData(void *a0);
typedef unsigned int   u32;
struct Blk34;
struct Sub020089A8Obj;
extern void *GAME_DATA_GetMiscSave(int *p);
extern void BEACON_SetFlag(struct Blk34 *p, u32 bit);
struct RtcDate;
extern void GF_STANDARD_SetField00_F4E4(struct RtcDate *date);
extern void *GAME_DATA_GetSaveBlock21(void **h);
extern void func_02008A7C(struct Sub020089A8Obj *obj, u32 i, u32 a, u32 b, u32 c);

int SCRCMD_WORK_CmdSetMiscFlag(int a, int b)
{
    V4 v;
    int r4 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    void *r5 = SCRCMD_WORK_GetGameData((void *)b);

    BEACON_SetFlag(GAME_DATA_GetMiscSave(r5), r4);
    GF_STANDARD_SetField00_F4E4((struct RtcDate *)(&v));
    func_02008A7C(GAME_DATA_GetSaveBlock21(r5), r4, v.a, v.b, v.c);
    return 0;
}
