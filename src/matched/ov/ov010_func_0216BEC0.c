/*
 * function: SCRCMD_EVENT_MON_CmdClearEventMonFlag
 * address:  0x0216BEC0
 * packet:   pkt_ov010_0216BEC0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   func_0202F488  0x0202F488  thumb
 *   func_0202F630  0x0202F630  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetGameData(void *a0);
struct BigObj;
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern int func_0202F488(int a0, int a1);
extern void func_0202F630(u32 a, u32 b);

int SCRCMD_EVENT_MON_CmdClearEventMonFlag(int c, int vm)
{
    void *r7;
    int k;
    int m;
    int t;
    void *obj;

    r7 = GAME_DATA_GetMyParty(SCRCMD_WORK_GetGameData((void *)vm));
    k = SCRIPT_WORK_ReadWorkValue((void *)c, (void *)vm);
    m = SCRIPT_WORK_ReadWorkValue((void *)c, (void *)vm);
    switch (k) {
    case 0xFB:
        t = 0;
        break;
    case 0xF3:
    case 0xF4:
    case 0xF5:
        t = 2;
        break;
    case 0xF6:
    case 0xF7:
    case 0xF8:
    case 0xF9:
    case 0xFA:
    default:
        return 0;
    }
    obj = POKEPARTY_GetMember((void *)r7, m);
    if (func_0202F488((int)obj, t) == 0) {
        return 0;
    }
    func_0202F630((u32)obj, t);
    return 0;
}
