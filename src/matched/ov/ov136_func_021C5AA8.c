/*
 * function: func_021C5AA8
 * address: 0x021C5AA8
 * packet: pkt_ov136_021C5AA8
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STRBUF_Delete 0x02045808 arm
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 */
#include "../include/Obj08201.h"
#include "../include/Obj23519.h"
#include "../include/Obj23520.h"
#include "../include/Obj23521.h"
typedef unsigned char u8;
struct TaskMenuState;
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec);
typedef unsigned int   u32;
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
void func_021C5AA8(u8 *p)
{
    int i;
    for (i = 0; i < 4; i++)
        STRBUF_Delete(*(void **)(*(u8 * *)&((struct Obj08201 *)p)->f8 + 0x314 + i * 12));
    STRBUF_Delete(((struct Obj23519 *)(*(u8 * *)&((struct Obj08201 *)p)->f8))->f344);
    STRBUF_Delete(((struct Obj23520 *)(*(u8 * *)&((struct Obj08201 *)p)->f8))->f350);
    APP_TASKMENU_RES_Delete(((struct Obj23521 *)(*(u8 * *)&((struct Obj08201 *)p)->f8))->f30C);
}
