/*
 * function: CTVT_COMM_HandleMessage
 * address: 0x021B8770
 * packet: pkt_ov172_021B8770
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   COMM_TVT_SYS_PlaceSlotMarker 0x021BE210 thumb ov172
 *   COMM_TVT_SYS_GetTalkStatus 0x021BDFEC thumb ov172
 *   COMM_TVT_SYS_HideSlotMarker 0x021BE2E0 thumb ov172
 *   CTVT_MIC_StopVoice 0x021BA234 thumb ov172
 *   COMM_TVT_SYS_GetSprites 0x021BDFFC thumb ov172
 *   DRAW_SYSTEM_SetQueueIndex 0x021B6EA8 thumb ov172
 *   COMM_TVT_SYS_SetInputLocked 0x021BE0CC thumb ov172
 *   COMM_TVT_SYS_GetCamView 0x021BDFDC thumb ov172
 *   COMM_TVT_SYS_GetHalfRes 0x021BE078 thumb ov172
 *   COMM_TVT_SYS_SetHalfRes 0x021BE0A0 thumb ov172
 *   CTVT_CAMVIEW_StartLayoutChange 0x021B7740 thumb ov172
 *   CTVT_MIC_PlayVoice 0x021BA1E8 thumb ov172
 *   COMM_TVT_SYS_SetEndRequested 0x021BE0D4 thumb ov172
 */
#include "../include/Obj00593.h"
#include "../include/Obj08258.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
extern void COMM_TVT_SYS_PlaceSlotMarker(char *a, u8 idx);
extern int COMM_TVT_SYS_GetTalkStatus(void *p);
extern void COMM_TVT_SYS_HideSlotMarker(void *p);
extern void CTVT_MIC_StopVoice(void *p);
extern u32 COMM_TVT_SYS_GetSprites(void *p);
extern void DRAW_SYSTEM_SetQueueIndex(void *p, u16 v);
extern void COMM_TVT_SYS_SetInputLocked(void *p, u32 v);
extern u32 COMM_TVT_SYS_GetCamView(void *p);
extern u32 COMM_TVT_SYS_GetHalfRes(void *p);
extern void COMM_TVT_SYS_SetHalfRes(void *p, u32 v);
extern void CTVT_CAMVIEW_StartLayoutChange(void *p, char *q, int a, int b);
extern int CTVT_MIC_PlayVoice(int *self, char *buf, unsigned n, int vol, int freq);
extern void COMM_TVT_SYS_SetEndRequested(void *p, u32 v);
void CTVT_COMM_HandleMessage(int id, int size, u32 *msg, char *q)
{
    u32 self;
    void *r;
    char *base;
    u32 v;
    self = GFL_NET_GetHandleNetID((struct Link *)((u32)GFL_NET_HANDLE_GetCurrentHandle()));
    switch (((struct Obj08258 *)msg)->f4) {
    case 0:
        if (id == self)
            break;
        ((struct Obj00593 *)q)->f183 |= (u8)(1 << id);
        break;
    case 1:
        v = msg[0];
        ((struct Obj00593 *)q)->f3AE = v;
        if (v != 0xff) {
            COMM_TVT_SYS_PlaceSlotMarker((char *)(*(u8 * *)&((struct Obj00593 *)q)->f3DC), (u8)v);
        } else {
            r = (void *)COMM_TVT_SYS_GetTalkStatus(((struct Obj00593 *)q)->f3DC);
            COMM_TVT_SYS_HideSlotMarker(((struct Obj00593 *)q)->f3DC);
            CTVT_MIC_StopVoice(r);
        }
        break;
    case 3:
        DRAW_SYSTEM_SetQueueIndex((void *)COMM_TVT_SYS_GetSprites(((struct Obj00593 *)q)->f3DC), msg[0]);
        COMM_TVT_SYS_SetInputLocked(((struct Obj00593 *)q)->f3DC, 0);
        break;
    case 2:
        base = (char *)COMM_TVT_SYS_GetCamView(((struct Obj00593 *)q)->f3DC);
        v = msg[0];
        if (v == COMM_TVT_SYS_GetHalfRes(((struct Obj00593 *)q)->f3DC))
            break;
        COMM_TVT_SYS_SetHalfRes(((struct Obj00593 *)q)->f3DC, v);
        CTVT_CAMVIEW_StartLayoutChange(((struct Obj00593 *)q)->f3DC, base, 1, 0);
        break;
    case 4:
        if (id == self)
            break;
        ((struct Obj00593 *)q)->f3C0 = 1;
        break;
    case 5:
        if (id == self)
            break;
        ((struct Obj00593 *)q)->f3C8 = 1;
        break;
    case 6:
        if (self != 0)
            break;
        *(u32 *)(q + id * 0x40 + 0x74) = 1;
        ((struct Obj00593 *)q)->f3B0 = 1;
        break;
    case 7:
        r = (void *)COMM_TVT_SYS_GetTalkStatus(((struct Obj00593 *)q)->f3DC);
        if (id == self)
            CTVT_MIC_PlayVoice(r, *(char * *)&((struct Obj00593 *)q)->f1A4, ((struct Obj00593 *)q)->f19C, 0, ((struct Obj00593 *)q)->f1A0);
        else
            CTVT_MIC_PlayVoice(r, *(char * *)&((struct Obj00593 *)q)->f1A4, ((struct Obj00593 *)q)->f19C, 0x7f, ((struct Obj00593 *)q)->f1A0);
        break;
    case 8:
        if (self == 0) {
            *(u32 *)(q + id * 0x40 + 0x74) = 0;
            ((struct Obj00593 *)q)->f3B0 = 1;
        }
        COMM_TVT_SYS_HideSlotMarker(((struct Obj00593 *)q)->f3DC);
        break;
    case 9:
        if (id == ((struct Obj00593 *)q)->f3AE)
            ((struct Obj00593 *)q)->f3B0 = 1;
        COMM_TVT_SYS_HideSlotMarker(((struct Obj00593 *)q)->f3DC);
        break;
    case 10:
        COMM_TVT_SYS_SetEndRequested(((struct Obj00593 *)q)->f3DC, 1);
        break;
    }
}
