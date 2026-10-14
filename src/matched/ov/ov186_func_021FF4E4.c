/*
 * function: BR_NET_Destroy
 * address: 0x021FF4E4
 * packet: pkt_ov186_021FF4E4
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DWC_RAP_SetErrorHookCallback 0x02156DE0 thumb ov009
 *   BR_NET_DestroyTask 0x021FFB50 thumb ov186
 *   GDS_PROFILE_Delete 0x0200D5C8 thumb
 *   GDS_RAP_Exit 0x021D6770 thumb ov125
 *   func_020307B0 0x020307B0 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov125_id 0x0000007D data
 */
#include "../include/Obj08336.h"
extern void DWC_RAP_SetErrorHookCallback(int, int);
extern void BR_NET_DestroyTask(void *);
struct GdsProfile;
extern void GDS_PROFILE_Delete(struct GdsProfile *p);
extern void GDS_RAP_Exit(char *p);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void func_02034A5C(int);
extern char ov125_id[];
void BR_NET_Destroy(char *p)
{
    DWC_RAP_SetErrorHookCallback(0, 0);
    BR_NET_DestroyTask(((struct Obj08336 *)p)->f5AC);
    GDS_PROFILE_Delete(((struct Obj08336 *)p)->f5A8);
    if (((struct Obj08336 *)p)->f5A4) {
        GDS_RAP_Exit(p);
        ((struct Obj08336 *)p)->f5A4 = 0;
    }
    func_020307B0(p);
    func_02034A5C((int)ov125_id);
}
