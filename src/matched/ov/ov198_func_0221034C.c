/*
 * function: B_PLIST_MAIN_HandleSkipKey
 * address: 0x0221034C
 * packet: pkt_ov198_0221034C
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * remainder: separate conditional follower ov198_func_0221039C.c (28 bytes).
 * symbols:
 *   B_PLIST_MAIN_CheckCancel 0x02211958 thumb ov198
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 */
#include "../include/Obj08362.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 B_PLIST_MAIN_CheckCancel(u8 **);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
extern void BMP_MENUWORK_DrawWindowBorder(void *,u32);
int B_PLIST_MAIN_HandleSkipKey(char *p)
{
    if (B_PLIST_MAIN_CheckCancel((u8 **)p)==1) return 0x1f;
    if ((KEY_GetTrg()&3)!=0 || TOUCHPANEL_GetTrg()==1) {
        if (((struct Obj08362 *)p)->f2193==1) {
            BMP_MENUWORK_DrawWindowBorder(((struct Obj08362 *)p)->f1F68,0);
            ((struct Obj08362 *)p)->f2193=0;
        }
        return ((struct Obj08362 *)p)->f217C;
    }
    return 0x18;
}
