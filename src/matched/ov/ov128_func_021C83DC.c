/*
 * function: func_021C83DC
 * address: 0x021C83DC
 * packet: pkt_ov128_021C83DC
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two zero padding bytes at 0x021C846E precede labelled 021C8470.
 * symbols:
 *   func_021C87A0 0x021C87A0 thumb ov128
 *   func_021C8388 0x021C8388 thumb ov128
 *   GAME_DATA_GetWifiList  0x0201283C  thumb  arm9
 *   APP_TASKMENU_OpenMenu  0x02027778  thumb  arm9
 */
#include "../include/Obj08130.h"
#include "../include/Obj10485.h"
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned long long u64;
typedef struct TextConfig {int heap; u8 count; u8 pad[3]; void *entries; int mode; u8 x,y,a,b;} TextConfig;
struct BigObj;
extern unsigned int GAME_DATA_GetWifiList(const struct BigObj *p);
typedef unsigned int   u32;
struct Sub020097BCObj;
extern u32 func_02009864(const struct Sub020097BCObj *obj, u32 i, u32 field);
extern int func_021C87A0(s16 *);
extern unsigned long long func_021C8388(s16 *p, u8 *q);
struct TaskMenu;
struct TaskMenuTmpl;
extern struct TaskMenu *APP_TASKMENU_OpenMenu(struct TaskMenuTmpl *tmpl, void *arg1);
void func_021C83DC(u8 *p, u8 *a, void *unused, int heap)
{
    TextConfig config;
    void *q = (void *)GAME_DATA_GetWifiList(((struct Obj10485 *)a)->f4);
    int result = func_02009864(q, (a + func_021C87A0((s16 *)p))[24], 9);
    config.heap = heap;
    config.count = 4;
    if (result == 2) {
        config.entries = p + (func_021C8388((s16 *)p, a) != 0 ? 0x148 : 0x118);
        ((struct Obj08130 *)p)->f198 = 1;
    } else {
        config.entries = p + 0x118;
        ((struct Obj08130 *)p)->f198 = 0;
    }
    config.mode = 1;
    config.x = 32; config.y = 24; config.a = 17; config.b = 3;
    ((struct Obj08130 *)p)->f194 = APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(&config), ((struct Obj08130 *)p)->f190);
}
