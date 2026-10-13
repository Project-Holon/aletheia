/*
 * function: SCRCMD_PROC_GetBoxMonCount
 * address:  0x0215B994
 * packet:   pkt_ov010_0215B994
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetBoxManager  0x0201293C  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   func_02007984  0x02007984  thumb
 *   func_020079A0  0x020079A0  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
struct BigObj;
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern void *SCRCMD_WORK_GetGameData(void *a0);
extern u32 GAME_DATA_GetBoxManager(const struct BigObj *p);
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern int func_02007984(void *);
extern int func_020079A0(void *);

int SCRCMD_PROC_GetBoxMonCount(void *a0, void *a1)
{
    u16 *out = SCRIPT_WORK_ReadWorkPointer(a0, a1);
    int sel = SCRIPT_WORK_ReadWorkValue(a0, a1);
    void *h = SCRCMD_WORK_GetGameData(a1);
    void *d = (void *)GAME_DATA_GetBoxManager(h);
    int r;

    GAME_DATA_GetMyParty(h);
    switch (sel) {
    case 0:
        r = func_02007984(d);
        break;
    case 1:
    case 2:
        r = func_020079A0(d);
        break;
    case 3:
        r = func_02007984(d) - func_020079A0(d);
        break;
    case 5: {
        int v = func_02007984(d);
        if (v > 720) {
            r = 0;
        } else {
            r = 720 - v;
        }
        break;
    }
    default:
        r = 0;
        break;
    }
    *out = r;
    return 0;
}
