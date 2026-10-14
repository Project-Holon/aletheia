/*
 * function: GURU2_MAIN_StateWaitSync5
 * address: 0x021DF6FC
 * packet: pkt_ov137_021DF6FC
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   TIME_ICON_Create 0x0202EE30 thumb
 *   GFL_NET_SetLoginOption 0x0203D7BC arm
 *   GFL_NET_SetAutoExit 0x0203D7B0 arm
 *   GFL_NET_COMMAND_DeleteCommandTable 0x0203A5E4 arm
 *   GURU2_MAIN_GetUnionApp 0x021DEB10 thumb ov137
 *   UNION_APP_RequestReset 0x02184174 thumb ov022
 */
#include "../include/Obj03305.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Entry;
struct Link;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_HANDLE_IsTimingSyncRange(struct Link *p, u32 lo, u32 hi);
extern u8 *TIME_ICON_Create(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);
extern void GFL_NET_SetLoginOption(u8 a0);
extern void GFL_NET_SetAutoExit(u8 a0);
extern void GFL_NET_COMMAND_DeleteCommandTable(unsigned);
extern void *GURU2_MAIN_GetUnionApp(char *p);
extern void UNION_APP_RequestReset(u8 *p);
int GURU2_MAIN_StateWaitSync5(u8 *p)
{
    void *ctx;
    ctx = GFL_NET_HANDLE_GetCurrentHandle();
    if (((struct Obj03305 *)p)->f18 == 0) {
        if (GFL_NET_HANDLE_IsTimingSyncRange(ctx, 206, 40)) {
            ((struct Obj03305 *)p)->fDA8 = TIME_ICON_Create(((struct Obj03305 *)p)->fD98, ((struct Obj03305 *)p)->fCF0, 15, 16, 114);
            GFL_NET_SetLoginOption(0);
            GFL_NET_COMMAND_DeleteCommandTable(10240);
            UNION_APP_RequestReset(GURU2_MAIN_GetUnionApp((char *)p));
            ((struct Obj03305 *)p)->f0 = 49;
        }
    } else {
        ((struct Obj03305 *)p)->fC += 1;
        if (((struct Obj03305 *)p)->fC >= 180) {
            ((struct Obj03305 *)p)->fC = 0;
            if ((*(int **)(p + 220))[15] == 0) GFL_NET_SetAutoExit(0);
            ((struct Obj03305 *)p)->f0 = 49;
        }
    }
    return 0;
}
