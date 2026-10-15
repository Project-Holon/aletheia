/*
 * function: WIFI_BSUBWAY_StartHttpRequest
 * address: 0x021D6E50
 * packet: pkt_ov116_021D6E50
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   NHTTP_RAP_Create 0x021B9800 thumb ov114
 *   DWC_RAP_SetErrorCallback 0x02156DC4 thumb ov009
 *   NHTTP_RAP_AllocPostData 0x021B98A0 thumb ov114
 *   NHTTP_RAP_AppendPostData 0x021B98D8 thumb ov114
 *   NHTTP_RAP_CreatePostRequest 0x021B98F8 thumb ov114
 *   NHTTP_RAP_StartConnection 0x021B9748 thumb ov114
 *   WIFI_BSUBWAY_ResetUpload 0x021D7258 thumb ov116
 *   WIFI_BSUBWAY_OnHttpError 0x021D6E3C thumb ov116
 */
#include "../include/Obj04470.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Sub0200852CObj;
extern u32 func_0200853C(const struct Sub0200852CObj *obj);
extern u8 *NHTTP_RAP_Create(int,int,int);
extern void DWC_RAP_SetErrorCallback(int a0, int a1);
extern void NHTTP_RAP_AllocPostData(u8 *,int,int,int);
extern void NHTTP_RAP_AppendPostData(u8 *p, int a, int n);
extern int NHTTP_RAP_CreatePostRequest(u8 *p);
extern int NHTTP_RAP_StartConnection(u8 *);
extern void WIFI_BSUBWAY_ResetUpload(u8 *);
extern void WIFI_BSUBWAY_OnHttpError(unsigned char *a);
void WIFI_BSUBWAY_StartHttpRequest(u8 *p,u8 *q,int a,int b) {
    *(u8 * *)&((struct Obj04470 *)p)->f168=NHTTP_RAP_Create(b,func_0200853C(((struct Obj04470 *)p)->f218),a);
    DWC_RAP_SetErrorCallback((int)WIFI_BSUBWAY_OnHttpError,(int)p);
    NHTTP_RAP_AllocPostData(*(u8 * *)&((struct Obj04470 *)p)->f168,b,180,4);
    NHTTP_RAP_AppendPostData(*(u8 * *)&((struct Obj04470 *)p)->f168,(int)(p+0x70),180);
    ((struct Obj04470 *)p)->f16C=3;
    NHTTP_RAP_CreatePostRequest(*(u8 * *)&((struct Obj04470 *)p)->f168);
    NHTTP_RAP_StartConnection(*(u8 * *)&((struct Obj04470 *)p)->f168);
    WIFI_BSUBWAY_ResetUpload(q);
}
