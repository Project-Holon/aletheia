/*
 * function: CTVT_CAMVIEW_Create
 * address: 0x021B6EE0
 * packet: pkt_ov172_021B6EE0
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   ARC_UTIL_LoadHandleMember 0x0204A380 arm
 *   COMM_TVT_SYS_GetArc 0x021BE010 thumb ov172
 *   COMM_TVT_SYS_IsNetIdle 0x021BE100 thumb ov172
 *   CTVT_CAMERA_Create 0x021B6100 thumb ov172
 *   CTVT_CAMERA_SetSize 0x021B6950 thumb ov172
 *   CTVT_CAMERA_SelectCamera 0x021B69BC thumb ov172
 *   CTVT_CAMERA_AllocFrames 0x021B674C thumb ov172
 *   CTVT_CAMERA_SetFrameCallback 0x021B6744 thumb ov172
 *   CTVT_CAMERA_StartCapture 0x021B6814 thumb ov172
 *   CTVT_CAMVIEW_SetWindowCurRect 0x021B7888 thumb ov172
 *   CTVT_CAMVIEW_SetWindowTargetRect 0x021B78A0 thumb ov172
 *   CTVT_CAMVIEW_OnCameraFrame 0x021B75AC thumb ov172
 *   d_021C71E0 0x021C71E0 data a4
 */
#include "../include/Obj00439.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void GFL_HEAP_CreateChildHeap(unsigned int, unsigned int, unsigned int);
extern void *ARC_UTIL_LoadHandleMember(void *, u32, u32, u32);
extern u32 COMM_TVT_SYS_GetArc(void *);
extern int COMM_TVT_SYS_IsNetIdle(void);
extern char *CTVT_CAMERA_Create(int);
extern void CTVT_CAMERA_SetSize(char *, int);
extern void CTVT_CAMERA_SelectCamera(void *p, u32 v);
extern void CTVT_CAMERA_AllocFrames(char *, int, u16);
extern void CTVT_CAMERA_SetFrameCallback(void *p, u32 a, u32 b);
extern void CTVT_CAMERA_StartCapture(void *a0);
extern void CTVT_CAMVIEW_SetWindowCurRect(void *p, u16 a, u16 b, u16 c, u16 d);
extern void CTVT_CAMVIEW_SetWindowTargetRect(void *p, u16 a, u16 b, u16 c, u16 d);
extern void CTVT_CAMVIEW_OnCameraFrame(char *src, void *p);
extern const char d_021C71E0[];

char *CTVT_CAMVIEW_Create(void *a, u16 b)
{
    char *p;
    u32 r6;
    void *r0;
    char *q;
    u8 i;
    int off;

    p = func_02030734(b, 0xB4, 1, d_021C71E0, 0x67);
    r6 = COMM_TVT_SYS_GetArc(a);
    if (COMM_TVT_SYS_IsNetIdle() == 1) {
        ((struct Obj00439 *)p)->f0 = 0x6E;
        GFL_HEAP_CreateChildHeap(1, 0x6E, 0x80000);
        *(char * *)&((struct Obj00439 *)p)->fA4 = CTVT_CAMERA_Create(((struct Obj00439 *)p)->f0);
        CTVT_CAMERA_SetSize(*(char * *)&((struct Obj00439 *)p)->fA4, 5);
        CTVT_CAMERA_SelectCamera(*(char * *)&((struct Obj00439 *)p)->fA4, 1);
        CTVT_CAMERA_AllocFrames(*(char * *)&((struct Obj00439 *)p)->fA4, 2, (u16)((((struct Obj00439 *)p)->f0 & 0x7FFF) | 0x8000));
        CTVT_CAMERA_SetFrameCallback(*(char * *)&((struct Obj00439 *)p)->fA4, (u32)((void *)CTVT_CAMVIEW_OnCameraFrame), (u32)a);
        CTVT_CAMERA_StartCapture(*(char * *)&((struct Obj00439 *)p)->fA4);
        ((struct Obj00439 *)p)->fA8 = func_02030734((u16)((((struct Obj00439 *)p)->f0 & 0x7FFF) | 0x8000), 0xC000, 1, d_021C71E0, 0x76);
        ((struct Obj00439 *)p)->fAC = func_02030734((u16)((((struct Obj00439 *)p)->f0 & 0x7FFF) | 0x8000), 0xC000, 1, d_021C71E0, 0x77);
        ((struct Obj00439 *)p)->fB0 = func_02030734((u16)((((struct Obj00439 *)p)->f0 & 0x7FFF) | 0x8000), 0xC000, 1, d_021C71E0, 0x78);
        ((struct Obj00439 *)p)->f8 = ARC_UTIL_LoadHandleMember((void *)r6, 0x19, 0, ((struct Obj00439 *)p)->f0);
        r0 = ARC_UTIL_LoadHandleMember((void *)r6, 0x1A, 0, ((struct Obj00439 *)p)->f0);
    } else {
        ((struct Obj00439 *)p)->f8 = ARC_UTIL_LoadHandleMember((void *)r6, 0x19, 0, b);
        r0 = ARC_UTIL_LoadHandleMember((void *)r6, 0x1A, 0, b);
    }
    ((struct Obj00439 *)p)->fC = r0;
    i = 0;
    ((struct Obj00439 *)p)->f10 = i;
    ((struct Obj00439 *)p)->f2C = i;
    ((struct Obj00439 *)p)->f14 = i;
    ((struct Obj00439 *)p)->f2D = 0xC0;
    ((struct Obj00439 *)p)->f18 = i;
    ((struct Obj00439 *)p)->f1C = i;
    ((struct Obj00439 *)p)->f20 = i;
    ((struct Obj00439 *)p)->f30 = i;
    ((struct Obj00439 *)p)->f24 = i;
    ((struct Obj00439 *)p)->f28 = i;
    ((struct Obj00439 *)p)->f4 = func_02030734((u16)((b & 0x7FFF) | 0x8000), 0x18000, 1, d_021C71E0, 0x8C);
    q = p + 0x34;
    for (i = 0; i < 4; i++) {
        off = i * 0x1C;
        CTVT_CAMVIEW_SetWindowCurRect(q + off, 0, 0, 0, 0);
        CTVT_CAMVIEW_SetWindowTargetRect(q + off, 0, 0, 0, 0);
        *(int *)(p + off + 0x34) = 0;
        *(int *)(p + off + 0x38) = 1;
        *(int *)(p + off + 0x3C) = 1;
    }
    return p;
}
