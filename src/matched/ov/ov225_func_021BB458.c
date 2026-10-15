/*
 * function: MANUAL_COMMON_CreateDialogWindows
 * address: 0x021BB458
 * packet: pkt_ov225_021BB458
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * width: 021BB4B0/021BB4B8 truncate r3 to u8 before 02027FEC; retain u8 fourth extern argument.
 * symbols:
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   APP_TASKMENU_WIN_Create 0x02027FEC thumb
 *   STRBUF_Delete 0x02045808 arm
 *   func_020355C4 0x020355C4 arm
 *   APP_TASKMENU_WIN_SetActive 0x02028218 thumb
 */
#include "../include/Obj01596.h"
#include "../include/Obj26246.h"
#include "../include/Obj26247.h"
#include "../include/Obj26248.h"
#include "../include/Obj26249.h"
#include "../include/Obj26250.h"
#include "../include/Obj26251.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct R;
struct Obj;
struct MsgBank;struct U16Vec;
struct Entry { void *resource; u16 tag; u16 pad; unsigned flags; };
extern struct R *APP_TASKMENU_RES_Create(u16, u16, unsigned, unsigned, u16);
extern void *func_02045EC0(struct MsgBank *, unsigned);
typedef unsigned int   u32;
extern u32 APP_TASKMENU_WIN_Create(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u16 a5);
extern void STRBUF_Delete(struct U16Vec *);
extern u8 func_020355C4(void);
extern void APP_TASKMENU_WIN_SetActive(struct Obj *, unsigned);
void MANUAL_COMMON_CreateDialogWindows(char *p)
{
    struct Entry entries[2];
    u8 i;
    *(struct R * *)&((struct Obj01596 *)p)->f8 = APP_TASKMENU_RES_Create(5, 4, ((struct Obj26246 *)(*(char * *)&((struct Obj01596 *)p)->f4))->fC, ((struct Obj26247 *)(*(char * *)&((struct Obj01596 *)p)->f4))->f14, ((struct Obj26248 *)(*(char * *)&((struct Obj01596 *)p)->f4))->f4);
    entries[0].resource = func_02045EC0(*(struct MsgBank * *)&((struct Obj26249 *)(*(char * *)&((struct Obj01596 *)p)->f4))->f1C, 0);
    entries[0].tag = 0x39e3;
    entries[0].flags = 0;
    entries[1].resource = func_02045EC0(*(struct MsgBank * *)&((struct Obj26250 *)(*(char * *)&((struct Obj01596 *)p)->f4))->f1C, 1);
    entries[1].tag = 0x39e3;
    entries[1].flags = 0;
    for (i = 0; i < 2; i++) {
        *(unsigned *)(p + i * 4 + 0xc) = APP_TASKMENU_WIN_Create(*(unsigned *)&((struct Obj01596 *)p)->f8, (unsigned)&entries[i], 1, (u8)((i + 1) * 3), 30, ((struct Obj26251 *)(*(char * *)&((struct Obj01596 *)p)->f4))->f4);
        STRBUF_Delete(entries[i].resource);
    }
    if (func_020355C4() == 0) APP_TASKMENU_WIN_SetActive(*(struct Obj **)(p + *(u8 *)*(char * *)&((struct Obj01596 *)p)->f0 * 4 + 0xc), 1);
}
