/*
 * function: WIFICLUB_StateWaitSaveNotice
 * address: 0x021BED3C
 * packet: pkt_ov099_021BED3C
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   KEY_GetTrg 0x020362DC arm
 *   func_02009A34 0x02009A34 thumb
 *   WIFICLUB_ShowStreamedMessage 0x021BAAB8 thumb ov099
 *   WIFICLUB_BuildOwnStatus 0x021BE6F0 thumb ov099
 *   WIFICLUB_RefreshVisibleList 0x021BE788 thumb ov099
 *   WIFICLUB_BeginIdle 0x021BE4F0 thumb ov099
 *   WIFICLUB_DeleteWindow 0x021BA8BC thumb ov099
 */
#include "../include/Obj01051.h"

typedef unsigned int u32;
extern u32 KEY_GetTrg(void);
struct Sub020097BCObj;
extern u32 func_02009A34(struct Sub020097BCObj *obj);
extern void WIFICLUB_ShowStreamedMessage(char *, int, int);
extern void WIFICLUB_BuildOwnStatus(char *, int, int);
extern int WIFICLUB_RefreshVisibleList(char *);
extern int WIFICLUB_BeginIdle(char *, int);
extern int WIFICLUB_DeleteWindow(void *p);
int WIFICLUB_StateWaitSaveNotice(char *p, int ret)
{
    if (KEY_GetTrg() & 3) {
        if (!func_02009A34(((struct Obj01051 *)p)->f4)) {
            WIFICLUB_ShowStreamedMessage(p, 0x1a, 1);
            ((struct Obj01051 *)p)->f1CC = 0x33;
            ((struct Obj01051 *)p)->f1E0 = 1;
        } else {
            WIFICLUB_BuildOwnStatus(p, 1, 2);
            WIFICLUB_RefreshVisibleList(p);
            ((struct Obj01051 *)p)->f1CC = WIFICLUB_BeginIdle(p, 0);
            ((struct Obj01051 *)p)->f19C = (void *)WIFICLUB_DeleteWindow(((struct Obj01051 *)p)->f19C);
        }
    }
    return ret;
}
