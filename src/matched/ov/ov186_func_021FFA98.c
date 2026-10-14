/*
 * packet: pkt_ov186_021FFA98
 * function: BR_NET_StepMarkVideo, BR_NET_OnUploadEntry, BR_NET_OnDownloadEntries, BR_NET_OnUploadVideo, BR_NET_OnSearchVideos, BR_NET_OnGetVideo, BR_NET_OnMarkVideo
 * unit: yes
 * address: 0x021FFA98
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * region: ov186
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GDS_RAP_RequestMarkVideo 0x021D6A08 thumb ov125
 *   func_02034714 0x02034714 arm
 *   BR_NET_SetStep 0x021FFB68 thumb ov186
 *   BR_NET_StepWaitRequest 0x021FF8E4 thumb ov186
 *   gBrNetAssertString 0x02200D98 data a1
 */
#include "../include/Obj14483.h"
#include "../include/Obj24867.h"
#include "../include/Obj24868.h"
#include "../include/Obj24869.h"
#include "../include/Obj24870.h"
#include "../include/Obj24871.h"
#include "../include/Obj24872.h"
typedef unsigned int   u32;
extern int GDS_RAP_RequestMarkVideo(char *p, int a, int b);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void BR_NET_SetStep(char *, int);
extern void BR_NET_StepWaitRequest(void *, int, int);
extern const char gBrNetAssertString[];
void BR_NET_StepMarkVideo(char *p, int unused, char *q)
{
    if (!GDS_RAP_RequestMarkVideo(q, ((struct Obj14483 *)q)->f5B0, ((struct Obj14483 *)q)->f5B4))
        func_02034714(gBrNetAssertString, 0, gBrNetAssertString);
    BR_NET_SetStep(p, (int)BR_NET_StepWaitRequest);
}
void BR_NET_OnUploadEntry(char *p) { ((struct Obj24867 *)p)->f5B8 = 1; }
void BR_NET_OnDownloadEntries(char *p) { ((struct Obj24868 *)p)->f5BC = 1; }
void BR_NET_OnUploadVideo(char *p) { ((struct Obj24869 *)p)->f5C0 = 1; }
void BR_NET_OnSearchVideos(char *p) { ((struct Obj24870 *)p)->f5C8 = 1; }
void BR_NET_OnGetVideo(char *p) { ((struct Obj24871 *)p)->f5C4 = 1; }
void BR_NET_OnMarkVideo(char *p) { ((struct Obj24872 *)p)->f5D8 = 1; }
