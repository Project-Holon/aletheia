/*
 * function: SCRCMD_NETWORK_CommProcEventMain
 * address:  0x0215F64C
 * packet:   pkt_ov010_0215F64C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * former blocker: ABS32 0x000000CD (ov_id_00CD) has no witness outside the function (literal pool word only)
 *
 * symbols:
 *   BRIGHTNESS_Set  0x02023F60  thumb
 *   GAME_EVENT_CallProc  0x02012444  thumb
 *   d_021B9EC0     0x021B9EC0  data  a4
 *   ov_id_00CD     0x000000CD  data  a1
 *   EVENT_WIFI_PROC_LoadOv020Task  0x0215FA1C  thumb  ov010
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   SCRIPT_SYS_CallScriptEvent  0x02158780  thumb  ov010
 
 * 2026-10-05 (D8 lane 15): overlay id sites now resolve; all relocations resolved, EXACT.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Evt;
struct Obj;
extern void BRIGHTNESS_Set(u32 a0, u32 a1, u32 mask);
extern void GAME_EVENT_CallProc(struct Obj *obj, u32 a1, u32 a2, u32 a3);
extern u8 d_021B9EC0[];
extern u8 ov_id_00CD[];
extern int EVENT_WIFI_PROC_LoadOv020Task();
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern int SCRIPT_SYS_CallScriptEvent(void *p, u16 b, int c, int d, u16 e);

int SCRCMD_NETWORK_CommProcEventMain(int a0, int *st, int *a2)
{
    switch (*st) {
    case 0:
        BRIGHTNESS_Set(-16, 0x37, 1);
        BRIGHTNESS_Set(-16, 0x3f, 2);
        GAME_EVENT_CallProc((struct Obj *)a0, (u32)ov_id_00CD, (u32)d_021B9EC0, (u32)a2);
        (*st)++;
        break;
    case 1:
        BRIGHTNESS_Set(0, 0x3f, 3);
        GAME_EVENT_CallEvent((struct Evt *)a0, (struct Evt **)EVENT_WIFI_PROC_LoadOv020Task(a2[0]));
        (*st)++;
        break;
    case 2:
        if (a2[1] == 0) {
            SCRIPT_SYS_CallScriptEvent((void *)a0, 3, 0, 0, 0x15);
        } else {
            SCRIPT_SYS_CallScriptEvent((void *)a0, 0x7d1, 0, 0, 0x15);
        }
        (*st)++;
        break;
    case 3:
        return 1;
    }
    return 0;
}
