/*
 * function: SCRCMD_WifiListOperation
 * address:  0x021D16D8
 * packet:   pkt_ov021_021D16D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * GAME_DATA_GetGameSync (arm9 Thumb leaf) is filed as src/matched/arm9/GAME_DATA_GetGameSync.c
 * to give the witness.
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   GAME_DATA_GetGameSync  0x02012F8C  thumb
 *   func_02009390  0x02009390  thumb
 *   func_020093D8  0x020093D8  thumb
 *   func_02009418  0x02009418  thumb
 *   func_02009428  0x02009428  thumb
 *   func_020093F0  0x020093F0  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern u32 GAME_DATA_GetGameSync(u32 *p);
struct Sub02009210Ent;
struct Sub02009210Obj;
extern struct Sub02009210Ent *func_02009390(struct Sub02009210Obj *obj, int i);
extern u32 func_020093D8(const struct Sub02009210Obj *obj);
extern u32 func_02009418(const struct Sub02009210Obj *obj);
extern void func_02009428(struct Sub02009210Obj *obj, int value);
extern void func_020093F0(struct Sub02009210Obj *obj, int value);

int SCRCMD_WifiListOperation(u32 a, u32 b)
{
    void *r6;
    u32 r7;
    u32 k1;
    u16 *r4;
    u8 i;
    u16 *e;
    u32 id;

    SCRCMD_WORK_GetScriptWork((void *)b);
    SCRCMD_WORK_GetGameSystem((void *)b);
    r6 = SCRCMD_WORK_GetGameData((void *)b);
    r7 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    k1 = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    r4 = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    id = GAME_DATA_GetGameSync(r6);
    switch (r7) {
    case 0:
        *r4 = 1;
        for (i = 0; i < 5; i++) {
            e = (u16 *)func_02009390((struct Sub02009210Obj *)id, i);
            if (e == 0) {
                *r4 = 0;
            } else if (e[0] == 0x7E || e[0] == 0) {
                *r4 = 0;
            }
        }
        break;
    case 1:
        if (func_020093D8((const struct Sub02009210Obj *)id) == 0x7F) {
            *r4 = 0;
        } else {
            *r4 = 1;
        }
        break;
    case 2:
        if (func_02009418((const struct Sub02009210Obj *)id) == 1) {
            *r4 = 1;
        } else {
            *r4 = 0;
        }
        break;
    case 3:
        func_02009428((struct Sub02009210Obj *)id, 0);
        break;
    case 4:
        func_020093F0((struct Sub02009210Obj *)id, k1);
        break;
    }
    return 0;
}
