/*
 * file:     ctvt_comm.c
 * unit:     yes
 * function: func_021B7BA8, func_021B7DCC, func_021B7E34, func_021B8050, func_021B8084, func_021B80CC, func_021B80DC, func_021B80E4, func_021B80EC, func_021B8108, func_021B8118, func_021B811C, func_021B8120, func_021B8130, func_021B8154, func_021B8448, func_021B8454, func_021B85D0, func_021B8614, func_021B8628, func_021B8720, func_021B8740, func_021B8770, func_021B891C, func_021B8954, func_021B8978, func_021B8A14, func_021B8A98, func_021B8AD4, func_021B8B00, func_021B8B20, func_021B8B34, func_021B8B48, func_021B8B5C, func_021B8B68, func_021B8B74, func_021B8B7C, func_021B8B84, func_021B8B8C, func_021B8B94, func_021B8B9C, func_021B8BA4, func_021B8BAC, func_021B8BB8, func_021B8BFC, func_021B8C14, func_021B8C20, func_021B8C34
 * address:  0x021B7BA8
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from draw_system.c, ctvt_comm.c, ctvt_draw.c by tools/splitfile.py.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   GFL_NET_AllocAligned 0x0203D7C8 arm
 *   GFL_NET_FreeAligned  0x0203D7FC  arm
 *   func_020307B0  0x020307B0  arm
 *   COMM_TVT_SYS_IsNetIdle 0x021BE100 thumb ov172
 *   COMM_TVT_SYS_GetHalfRes 0x021BE078 thumb ov172
 *   func_021B8B8C 0x021B8B8C thumb ov172
 *   func_021B8BAC 0x021B8BAC thumb ov172
 *   func_02082A7C 0x02082A7C arm
 *   COMM_TVT_SYS_GetCamView 0x021BDFDC thumb ov172
 *   COMM_TVT_SYS_GetMessageActive 0x021BE0AC thumb ov172
 *   MIi_CpuCopy32 0x02082A90 arm
 *   COMM_TVT_SYS_GetCameraBusy 0x021BE0F8 thumb ov172
 *   COMM_TVT_SYS_SetCameraBusy 0x021BE0FC thumb ov172
 *   func_021B8BA4 0x021B8BA4 thumb ov172
 *   COMM_TVT_SYS_IsLaunchModeCall 0x021BE0D8 thumb ov172
 *   SSP_GetJpegEncoderBufferSize 0x021C1A80 arm ov172
 *   COMM_TVT_SYS_GetLaunchParams 0x021BE004 thumb ov172
 *   func_02012944 0x02012944 thumb
 *   MYSTATUS_Copy 0x02008494 thumb
 *   GFL_NET_LOWER_DATA_Init 0x0203E5F8 arm
 *   d_021C71F4 0x021C71F4 data a4
 *   GFL_NET_LOWER_DATA_Exit 0x0203E6C0 arm
 *   COMM_TVT_SYS_GetHeapId 0x021BE00C thumb ov172
 *   GFL_NET_SetWaitMode 0x0203D644 arm
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   GFL_NET_BeaconScanStart 0x0203D010 arm
 *   GFL_NET_StartByNetType 0x0203D01C arm
 *   WIH_SetJudgeAcceptFunc 0x02179328 thumb ov014
 *   GFL_NET_ConnectMacAddressParent 0x0203CFF0 arm
 *   GFL_NET_HANDLE_CheckNegotiation 0x02039ACC arm
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_IsNegotiationDone 0x020399B8 arm
 *   GFL_NET_COMMAND_AddCommandTable 0x0203A574 arm
 *   d_021C6ED4 0x021C6ED4 data a4
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   GFL_NET_Exit 0x0203CEAC arm
 *   GFL_NET_IsSessionNull 0x0203CDBC arm
 *   GFL_NET_COMMAND_DeleteCommandTable 0x0203A5E4 arm
 *   func_0200FB24 0x0200FB24 thumb
 *   GFL_NET_StartSession  0x0203CBAC  arm
 *   GFL_NET_SetLoginOption  0x0203D7BC  arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   GFL_NET_GetNegotiationNum 0x0203D1B4 arm
 *   GFL_NET_LOWER_DATA_IsSendFinished 0x0203EA54 arm
 *   GFL_NET_LOWER_DATA_SetSendData 0x0203E758 arm
 *   SSP_StartJpegEncoder 0x021C2B74 arm ov172
 *   CTVT_CAMVIEW_StartLayoutChange 0x021B7740 thumb ov172
 *   COMM_TVT_SYS_ClearNameWindows 0x021BE1A4 thumb ov172
 *   CTVT_CAMVIEW_GetWindowHeight 0x021B77B8 thumb ov172
 *   WIH_SetScanWaitFrames 0x02179650 thumb ov014
 *   GFL_NET_IsConnectMember 0x0203D1C0 arm
 *   GFL_NET_LOWER_DATA_CreatePostWork 0x0203E808 arm
 *   GFL_NET_LOWER_DATA_DeletePostWork 0x0203E8C8 arm
 *   COMM_TVT_SYS_SetMemberCount 0x021BE058 thumb ov172
 *   COMM_TVT_SYS_SetSelfSlot 0x021BE0A8 thumb ov172
 *   COMM_TVT_SYS_SavePeerRecord 0x021BE2F0 thumb ov172
 *   GFL_NET_LOWER_DATA_IsPostComplete 0x0203EA70 arm
 *   CTVT_CAMVIEW_ClearWindowDirty 0x021B7724 thumb ov172
 *   GFL_NET_LOWER_DATA_GetPostBuffer 0x0203E96C arm
 *   GFL_NET_LOWER_DATA_GetPostRecvSize 0x0203E9DC arm
 *   SSP_StartJpegDecoder 0x021BFFC4 arm ov172
 *   CTVT_CAMVIEW_MarkWindowDirty 0x021B7714 thumb ov172
 *   GFL_NET_SendData 0x0203D3F8 arm
 *   COMM_TVT_SYS_PlaceSlotMarker 0x021BE210 thumb ov172
 *   COMM_TVT_SYS_GetTalkStatus 0x021BDFEC thumb ov172
 *   COMM_TVT_SYS_HideSlotMarker 0x021BE2E0 thumb ov172
 *   func_021BA234 0x021BA234 thumb ov172
 *   COMM_TVT_SYS_GetSprites 0x021BDFFC thumb ov172
 *   DRAW_SYSTEM_SetQueueIndex 0x021B6EA8 thumb ov172
 *   COMM_TVT_SYS_SetInputLocked 0x021BE0CC thumb ov172
 *   COMM_TVT_SYS_SetHalfRes 0x021BE0A0 thumb ov172
 *   func_021BA1E8 0x021BA1E8 thumb ov172
 *   COMM_TVT_SYS_SetEndRequested 0x021BE0D4 thumb ov172
 *   CTVT_ADPCM_ResetDecoder 0x021B69F0 thumb ov172
 *   func_021BA194 0x021BA194 thumb ov172
 *   d_021C6EC0 0x021C6EC0 data a2
 *   DRAW_SYSTEM_PushStroke 0x021B6E88 thumb ov172
 *   func_021B8084  0x021B8084  thumb  ov172
 *   func_021B8740  0x021B8740  thumb  ov172
 *   func_021B8B34  0x021B8B34  thumb  ov172
 *   func_021B8B48  0x021B8B48  thumb  ov172
 *   func_021B8BB8  0x021B8BB8  thumb  ov172
 *   func_021B8BFC  0x021B8BFC  thumb  ov172
 *   func_021B80E4  0x021B80E4  thumb  ov172
 *   func_021B80DC  0x021B80DC  thumb  ov172
 *   func_021B80EC  0x021B80EC  thumb  ov172
 *   func_021B8B7C  0x021B8B7C  thumb  ov172
 *   func_021B8C14  0x021B8C14  thumb  ov172
 *   func_021B8C20  0x021B8C20  thumb  ov172
 *   func_021B8108  0x021B8108  thumb  ov172
 *   func_021B85D0  0x021B85D0  thumb  ov172
 *   func_021B7BA8 0x021B7BA8 thumb ov172
 *   func_021B7DCC 0x021B7DCC thumb ov172
 *   func_021B7E34  0x021B7E34  thumb  ov172
 *   func_021B80CC  0x021B80CC  thumb
 *   func_021B8B94 0x021B8B94 thumb ov172
 *   func_021B8B68 0x021B8B68 thumb ov172
 *   func_021B8720 0x021B8720 thumb ov172
 *   CTVT_CAMVIEW_GetWindowWidth 0x021B77E8 thumb ov172
 *   CTVT_CAMVIEW_GetOwnSlotBuffer 0x021B7818 thumb ov172
 *   CTVT_CAMVIEW_GetSlotBuffer 0x021B7830 thumb ov172
 *   CTVT_CAMVIEW_GetSlotBufferStep 0x021B785C thumb ov172
 *   CTVT_CAMVIEW_RequestWindowAnimation 0x021B7B20 thumb ov172
 */
#include "../../matched/include/Obj00386.h"
#include "../../matched/include/Obj06559.h"
#include "../../matched/include/Obj00289.h"
#include "../../matched/include/Obj03853.h"
#include "../../matched/include/Obj24075.h"
#include "../../matched/include/Obj24076.h"
#include "../../matched/include/Obj24077.h"
#include "../../matched/include/Obj24080.h"
#include "../../matched/include/Obj04551.h"
#include "../../matched/include/Obj00593.h"
#include "../../matched/include/Obj08258.h"
#include "../../matched/include/Obj24084.h"
#include "../../matched/include/Obj10663.h"
#include "../../matched/include/Obj03854.h"
#include "../../matched/include/Obj05444.h"
#include "../../matched/include/Obj06560.h"
#include "../../matched/include/Obj24086.h"
#include "../../matched/include/Obj24087.h"
#include "../../matched/include/Obj24088.h"
#include "../../matched/include/Obj24089.h"
#include "draw_system_shared_types.h"

extern u32 func_020307B0(void *p);

extern int COMM_TVT_SYS_IsNetIdle(void);

extern u32 COMM_TVT_SYS_GetHalfRes(void *p);

#define W(o) (*(int *)(b + (o)))

#define B(o) (*(u8 *)(b + (o)))

struct Entry;

struct Link;

struct Req;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
} Flags;

typedef struct {
    u32 w[0x1c];
} Blob;

typedef struct { u8 x[0x21]; } S21;

typedef struct { u16 a[9]; } Table;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern int COMM_TVT_SYS_IsLaunchModeCall(void *p);

extern void *GFL_NET_AllocAligned(u32 heap, u32 size, const char *file, u16 line);

extern unsigned long SSP_GetJpegEncoderBufferSize(unsigned long width, unsigned long height, unsigned long sampling, unsigned long option);

extern u32 COMM_TVT_SYS_GetLaunchParams(void *p);

extern u8 *func_02012944(void *p);

extern void MYSTATUS_Copy(void *src, void *dst);

extern void GFL_NET_LOWER_DATA_Init(int a0, int a1);

extern void GFL_NET_LOWER_DATA_Exit(void);

extern void GFL_NET_FreeAligned(void *);

extern u16 COMM_TVT_SYS_GetHeapId(u16 *p);

extern void GFL_NET_SetWaitMode(int a);

extern int GFL_NET_GetRunState(void);

extern void GFL_NET_BeaconScanStart(void);

extern void GFL_NET_StartByNetType(void);

extern void WIH_SetJudgeAcceptFunc(void *v);

extern void GFL_NET_ConnectMacAddressParent(void *p);

extern int GFL_NET_HANDLE_CheckNegotiation(void);

extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);

extern u32 GFL_NET_HANDLE_IsNegotiationDone(u8 *p);

extern void GFL_NET_COMMAND_AddCommandTable(u32 a, u32 b, u32 c, u32 d);

extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *p, u32 a, u32 b);

extern u32 GFL_NET_HANDLE_IsTimingSyncRange(struct Link *p, u32 a, u32 b);

extern int GFL_NET_Exit(int a0);

extern int GFL_NET_IsSessionNull(void);

extern void GFL_NET_COMMAND_DeleteCommandTable(u32 key);

extern u32 func_0200FB24(void);

extern void GFL_NET_StartSession(struct Req *req, u32 a2, u32 a3);

extern void GFL_NET_SetLoginOption(u8 a0);

extern u32 GFL_NET_GetHandleNetID(struct Link *p);

extern int GFL_NET_GetNegotiationNum(void);

extern int GFL_NET_LOWER_DATA_IsSendFinished(void);

extern void GFL_NET_LOWER_DATA_SetSendData(int, int, int, int);

extern void MIi_CpuCopy32(const void *, void *, u32);

extern unsigned long SSP_StartJpegEncoder(void *src, unsigned char *dst, int limit, unsigned char *wrk, unsigned long width, unsigned long height, unsigned long quality, unsigned long sampling, unsigned long option);

extern u32 COMM_TVT_SYS_GetCamView(void *);

extern void CTVT_CAMVIEW_StartLayoutChange(void *, char *, int, int);

extern void COMM_TVT_SYS_ClearNameWindows(char *p);

extern u32 COMM_TVT_SYS_GetCameraBusy(void *);

extern void COMM_TVT_SYS_SetCameraBusy(void *, u32);

extern u32 COMM_TVT_SYS_GetMessageActive(void *);

extern u32 CTVT_CAMVIEW_GetWindowHeight(void *, u32);

extern void WIH_SetScanWaitFrames(u16 v);

extern u32 GFL_NET_IsConnectMember(u32 index);

extern void GFL_NET_LOWER_DATA_CreatePostWork(u32 a, int b, u32 c, u32 d);

extern void GFL_NET_LOWER_DATA_DeletePostWork(int a);

extern void COMM_TVT_SYS_SetMemberCount(void *p, u32 v);

extern void COMM_TVT_SYS_SetSelfSlot(void *p, u32 v);

extern void COMM_TVT_SYS_SavePeerRecord(u32 *p, void *q);

extern int GFL_NET_LOWER_DATA_IsPostComplete(unsigned int idx);

extern void CTVT_CAMVIEW_ClearWindowDirty(void *a, char *b, int c);

extern int GFL_NET_LOWER_DATA_GetPostBuffer(unsigned int idx);

extern int GFL_NET_LOWER_DATA_GetPostRecvSize(unsigned int idx);

extern int SSP_StartJpegDecoder(unsigned char *data, unsigned long size, void *dst,
                         short *width, short *height, unsigned long option);

extern void CTVT_CAMVIEW_MarkWindowDirty(void *a, char *b, int c);

extern u32 GFL_NET_SendData(u32, u32, u32, u32, u32, u32, u32, u32);

extern void COMM_TVT_SYS_PlaceSlotMarker(void *a, u32 b);

extern int COMM_TVT_SYS_GetTalkStatus(void *p);

extern void COMM_TVT_SYS_HideSlotMarker(void *p);

extern void func_021BA234(void *p);

extern u32 COMM_TVT_SYS_GetSprites(void *p);

extern void DRAW_SYSTEM_SetQueueIndex(void *p, u16 v);

extern void COMM_TVT_SYS_SetInputLocked(void *p, u32 v);

extern void COMM_TVT_SYS_SetHalfRes(void *p, u32 v);

extern int func_021BA1E8(int *self, char *buf, unsigned n, int vol, int freq);

extern void COMM_TVT_SYS_SetEndRequested(void *p, u32 v);

extern void func_02082A7C();

extern void CTVT_ADPCM_ResetDecoder(void);

extern int func_021BA194(int unused, int a, void *buf, unsigned n);

extern void DRAW_SYSTEM_PushStroke(char *p, void *q);

extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);

extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *a, u32 b, u32 c);

extern u32 GFL_NET_HANDLE_IsTimingSyncRange(struct Link *a, u32 b, u32 c);

u32 CTVT_CAMVIEW_GetWindowWidth(void *p, u32 unused);

u32 CTVT_CAMVIEW_GetOwnSlotBuffer(void *p, void *q);

int CTVT_CAMVIEW_GetSlotBuffer(void *a0, char *a1, int a2);

u32 CTVT_CAMVIEW_GetSlotBufferStep(void *p, u32 unused);

void CTVT_CAMVIEW_RequestWindowAnimation(int unused, char *base, int i);

char *func_021B7BA8(void *p, u16 heap);

void func_021B7DCC(void *p, char *q);

void func_021B7E34(void *p, char *q);

void func_021B8050(void *a, void *b);

void func_021B8084(void *a, char *q);

u32 func_021B80CC(int unused, char *p);

void func_021B80DC(int unused, char *p, u32 v);

u32 func_021B80E4(int unused, char *p);

void func_021B80EC(int unused, char *p, const u8 *src);

int func_021B8108(void *unused, void *p);

u8 *func_021B8118(u8 *p);

int func_021B811C(void);

int func_021B8120(int a, int b);

int func_021B8130(void *a0, u8 *a1);

void func_021B8154(void *a, char *b);

void func_021B8448(void *p, char *q);

void func_021B8454(void *a, char *q);

int func_021B85D0(unsigned char *p, unsigned char *q);

void func_021B8614(int unused, int unused2, void *p);

void func_021B8628(void *a, int b, int *t, int c);

void func_021B8720(void *a0, u32 *a1, u32 a2);

u32 func_021B8740(int a, int b, u8 c, u32 d);

void func_021B8770(int id, int size, u32 *msg, char *q);

int func_021B891C(void *a, char *q, u16 *p);

int func_021B8954(void *p, char *q);

void func_021B8978(int a, int b, int c, char *q);

u32 func_021B8A14(int unused, char *q);

void func_021B8A98(int a, u32 b, char *list, char *q);

int func_021B8AD4(int unused, char *base);

void func_021B8B00(int i, void *a, void *b, char *q);

char *func_021B8B20(int i, char *q);

void func_021B8B34(void *p, u32 a, u32 b);

int func_021B8B48(void *p, u32 a, u32 b);

u32 func_021B8B5C(void *unused, u32 unused2);

u32 func_021B8B68(int unused, char *p);

int func_021B8B74(void *ctx, u8 *rec);

u8 *func_021B8B7C(void *c, u8 *x);

u32 func_021B8B84(int unused, char *p);

u32 func_021B8B8C(int unused, char *base, int i);

char *func_021B8B94(int unused, char *base, int i);

char *func_021B8B9C(int unused, char *base);

u32 func_021B8BA4(int unused, char *base, int i);

u8 func_021B8BAC(void *unused, char *base, int i);

int func_021B8BB8(int a, unsigned char *p, int *out);

void func_021B8BFC(int unused, u8 *p);

void func_021B8C14(void *c, u8 *x);

u32 func_021B8C20(void *c, u8 *x);

u32 func_021B8C34(void *ctx, u8 *rec);

extern const char d_021C71F4[];

extern u8 d_021C6ED4[];

extern const Table d_021C6EC0;

char *func_021B7BA8(void *p, u16 heap)
{
    char *q;
    u8 i;
    u8 j;
    q = func_02030734(heap, 0x3e0, 1, d_021C71F4, 0xf4);
    ((struct Obj00386 *)q)->f3DC = p;
    ((struct Obj00386 *)q)->f8 = 0;
    ((struct Obj00386 *)q)->f4 = 1;
    ((struct Obj00386 *)q)->f183 = 0;
    ((struct Obj00386 *)q)->f174 = 0;
    ((struct Obj00386 *)q)->f178 = 0;
    ((struct Obj00386 *)q)->f3D0 = 0;
    for (i = 0; i < 4; i++)
        func_021B8614((int)p, (int)q, q + 0x64 + i * 0x40);
    for (i = 0; i < 3; i++) {
        if (COMM_TVT_SYS_IsLaunchModeCall(p) == 0 || i == 0)
            *(void **)(q + 0x164 + i * 4) = GFL_NET_AllocAligned(heap, 3 << 14, d_021C71F4, 0x107);
    }
    ((struct Obj00386 *)q)->f188 = GFL_NET_AllocAligned(heap, SSP_GetJpegEncoderBufferSize(0x80, 0xc0, 1, 4), d_021C71F4, 0x10c);
    ((struct Obj00386 *)q)->f18C = GFL_NET_AllocAligned(heap, 0xc000, d_021C71F4, 0x10e);
    ((struct Obj00386 *)q)->f190 = GFL_NET_AllocAligned(heap, 0xc000, d_021C71F4, 0x10f);
    ((struct Obj00386 *)q)->f170 = 0;
    ((struct Obj00386 *)q)->f182 = 0;
    ((struct Obj00386 *)q)->f184 = 0;
    ((struct Obj00386 *)q)->f194 = 0;
    ((struct Obj00386 *)q)->f198 = 0;
    ((struct Obj00386 *)q)->f1A4 = func_02030734(heap, 0x208, 1, d_021C71F4, 0x116);
    ((struct Obj00386 *)q)->f1A8 = func_02030734(heap, 0xc800, 1, d_021C71F4, 0x117);
    ((struct Obj00386 *)q)->f1AC = 0;
    ((struct Obj00386 *)q)->f1AD = 0;
    ((struct Obj00386 *)q)->f3AE = 0xff;
    ((struct Obj00386 *)q)->f3B0 = 0;
    ((struct Obj00386 *)q)->f3B4 = 0;
    ((struct Obj00386 *)q)->f3B8 = 0;
    ((struct Obj00386 *)q)->f3BC = 0;
    ((struct Obj00386 *)q)->f3D4 = 0;
    ((struct Obj00386 *)q)->f3C0 = 1;
    ((struct Obj00386 *)q)->f3C4 = 0;
    ((struct Obj00386 *)q)->f3C8 = 1;
    ((struct Obj00386 *)q)->f3CC = 0;
    ((struct Obj00386 *)q)->f3D8 = 0xff;
    MYSTATUS_Copy(func_02012944((void *)(*((u32 *)COMM_TVT_SYS_GetLaunchParams(p)))), q + 0xc);
    ((struct Obj00386 *)q)->f2C = 1;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 6; j++)
            *(u8 *)(q + i * 6 + j + 0x2e) = 0xff;
    ((Flags *)(q + 0x2d))->b0 = COMM_TVT_SYS_IsNetIdle();
    ((Flags *)(q + 0x2d))->b1 = 0;
    MYSTATUS_Copy(func_02012944((void *)(*((u32 *)COMM_TVT_SYS_GetLaunchParams(p)))), q + 0x40);
    ((struct Obj00386 *)q)->f60 = COMM_TVT_SYS_IsNetIdle();
    ((struct Obj00386 *)q)->f0 = 1;
    GFL_NET_LOWER_DATA_Init(heap, 0);
    return q;
}

void func_021B7DCC(void *p, char *q)
{
    u8 i;
    GFL_NET_LOWER_DATA_Exit();
    func_020307B0(((struct Obj06559 *)q)->f1A8);
    func_020307B0(((struct Obj06559 *)q)->f1A4);
    GFL_NET_FreeAligned(((struct Obj06559 *)q)->f18C);
    GFL_NET_FreeAligned(((struct Obj06559 *)q)->f190);
    GFL_NET_FreeAligned(((struct Obj06559 *)q)->f188);
    for (i = 0; i < 3; i++) {
        if (COMM_TVT_SYS_IsLaunchModeCall(p) == 0 || i == 0)
            GFL_NET_FreeAligned(*(void **)(q + i * 4 + 0x164));
    }
    func_020307B0(q);
}

void func_021B7E34(void *p, char *q)
{
    u32 h;
    u8 i;
    u8 j;
    COMM_TVT_SYS_GetHeapId(p);
    switch (((struct Obj00289 *)q)->f8) {
    case 0:
        if (((struct Obj00289 *)q)->f178 == 0)
            break;
        if (((struct Obj00289 *)q)->f178 == 5) {
            GFL_NET_SetWaitMode(0);
            ((struct Obj00289 *)q)->f8 = 5;
            ((struct Obj00289 *)q)->f174 = ((struct Obj00289 *)q)->f178;
        } else {
            ((struct Obj00289 *)q)->f8 = 1;
        }
        break;
    case 1:
        func_021B8050(p, q);
        ((struct Obj00289 *)q)->f8 = 2;
        break;
    case 2:
        if (GFL_NET_GetRunState() != 1)
            break;
        switch (((struct Obj00289 *)q)->f178) {
        case 2:
            GFL_NET_BeaconScanStart();
            ((struct Obj00289 *)q)->f8 = 7;
            break;
        case 3:
            GFL_NET_StartByNetType();
            WIH_SetJudgeAcceptFunc(func_021B8130);
            ((struct Obj00289 *)q)->f8 = 3;
            break;
        case 4:
            if (((struct Obj00289 *)q)->f174 == 2)
                func_021B8614((int)p, (int)q, q + 0x64);
            GFL_NET_ConnectMacAddressParent(q + 0x17c);
            ((struct Obj00289 *)q)->f8 = 3;
            break;
        }
        ((struct Obj00289 *)q)->f174 = ((struct Obj00289 *)q)->f178;
        break;
    case 3:
        if (GFL_NET_HANDLE_CheckNegotiation() == 1)
            ((struct Obj00289 *)q)->f8 = 4;
        if (((struct Obj00289 *)q)->f174 != ((struct Obj00289 *)q)->f178)
            ((struct Obj00289 *)q)->f8 = 8;
        break;
    case 4:
        if (GFL_NET_HANDLE_IsNegotiationDone((u8 *)GFL_NET_HANDLE_GetCurrentHandle()) == 1)
            ((struct Obj00289 *)q)->f8 = 7;
        if (((struct Obj00289 *)q)->f174 != ((struct Obj00289 *)q)->f178)
            ((struct Obj00289 *)q)->f8 = 8;
        break;
    case 5:
        h = (u32)GFL_NET_HANDLE_GetCurrentHandle();
        GFL_NET_COMMAND_AddCommandTable(0x2000, (u32)d_021C6ED4, 4, (u32)q);
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)h, 8, 0x20);
        ((struct Obj00289 *)q)->f8 = 6;
        break;
    case 6:
        if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 8, 0x20) == 1)
            ((struct Obj00289 *)q)->f8 = 7;
        break;
    case 7:
        func_021B8154(p, q);
        if (((struct Obj00289 *)q)->f174 != ((struct Obj00289 *)q)->f178)
            ((struct Obj00289 *)q)->f8 = 8;
        if (((struct Obj00289 *)q)->f174 == 2)
            func_021B8448(p, q);
        break;
    case 8:
        GFL_NET_Exit(0);
        ((struct Obj00289 *)q)->f8 = 11;
        break;
    case 11:
        if (GFL_NET_IsSessionNull() != 1)
            break;
        if (((struct Obj00289 *)q)->f178 == 1)
            ((struct Obj00289 *)q)->f8 = 12;
        else
            ((struct Obj00289 *)q)->f8 = 1;
        break;
    case 9:
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 9, 0x20);
        ((struct Obj00289 *)q)->f8 = 10;
        break;
    case 10:
        if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 9, 0x20) == 1) {
            GFL_NET_COMMAND_DeleteCommandTable(0x2000);
            ((struct Obj00289 *)q)->f8 = 12;
        }
        if (func_0200FB24() != 0) {
            GFL_NET_COMMAND_DeleteCommandTable(0x2000);
            ((struct Obj00289 *)q)->f8 = 12;
        }
        break;
    }
    if (((struct Obj00289 *)q)->f3D0 != 0) {
        (((struct Obj00289 *)q)->f3D0)--;
        if (((struct Obj00289 *)q)->f3D0 == 0) {
            for (i = 0; i < 3; i++)
                for (j = 0; j < 6; j++)
                    *(u8 *)(q + i * 6 + j + 0x2e) = 0xff;
            ((Flags *)(q + 0x2d))->b1 = 0;
        }
    }
}

void func_021B8050(void *a, void *b)
{
    Blob s = *(Blob *)0x021C6EF4;

    COMM_TVT_SYS_GetHeapId(a);
    GFL_NET_StartSession((struct Req *)(&s), 0, (u32)b);
    GFL_NET_SetLoginOption(0);
}

/*
 * Chooses the +8 state from the +0x174 code and latches +0x178.
 *
 * Addresses are Black-image addresses.
 */
void func_021B8084(void *a, char *q)
{
    if (((struct Obj03853 *)q)->f4 <= 1) {
        if (((struct Obj03853 *)q)->f174 == 5) {
            ((struct Obj03853 *)q)->f8 = 0xc;
            GFL_NET_COMMAND_DeleteCommandTable(0x2000);
        } else {
            GFL_NET_Exit(0);
            ((struct Obj03853 *)q)->f8 = 0xb;
        }
    } else {
        if (((struct Obj03853 *)q)->f174 == 5) {
            ((struct Obj03853 *)q)->f8 = 9;
        } else {
            ((struct Obj03853 *)q)->f8 = 8;
        }
    }
    ((struct Obj03853 *)q)->f178 = 1;
}

u32 func_021B80CC(int unused, char *p)
{
    if (((struct Obj24075 *)p)->f8 == 12)
        return 1;
    return 0;
}

void func_021B80DC(int unused, char *p, u32 v)
{
    ((struct Obj24076 *)p)->f178 = v;
}

u32 func_021B80E4(int unused, char *p)
{
    return ((struct Obj24077 *)p)->f174;
}

void func_021B80EC(int unused, char *p, const u8 *src)
{
    u8 i;
    for (i = 0; i < 6; i++)
        p[0x17c + i] = src[i];
}

/*
 * Test the u32 at +0x08 against 7.
 *
 * Addresses are Black-image addresses.
 */
int func_021B8108(void *unused, void *p)
{
    if (((struct Obj24080 *)p)->f8 == 7) {
        return 1;
    }
    return 0;
}

u8 *func_021B8118(u8 *p)
{
    return p + 12;
}

int func_021B811C(void)
{
    return 52;
}

int func_021B8120(int a, int b)
{
    if (b == 0x20 || b == 3) {
        return 1;
    }
    return 0;
}

/*
 * When bit 1 of a1[0x2d] is set, hands the two sub-objects (a1+0xc and
 * a0+0xa) to func_021B85D0; otherwise there is nothing to do and it returns 1.
 * The test is the shift pair (v << 30) >> 31, not an AND against 2, and the
 * shifted value has to be unsigned or the image's `lsrs` comes out `asrs`.
 *
 * Addresses are Black-image addresses.
 */
int func_021B8130(void *a0, u8 *a1)
{
    if ((((u32)a1[0x2d] << 30) >> 31) == 0)
        return 1;
    return func_021B85D0(a1 + 0xc, (u8 *)a0 + 0xa);
}

/*
 * note 2026-10-05 wD4 lane05: EXACT*. Three source fixes: the 0x21-byte copy b+0x40 -> b+0x80 is a struct copy
 *   (one-member u8[0x21] struct); the slot stores go in offset order (0x74 = 0, 0x78 = 0xff, 0x7c = 0);
 *   in the j loop `hit = 1` comes before the slot store.
 */
void func_021B8154(void *a, char *b)
{
    int busy;
    u8 i;
    u8 cur;
    u8 j;
    u32 r7;
    u32 s18, s1c, s20, s24;
    int res;
    int hit;
    busy = GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle());
    if (W(0x174) == 2) {
        if (W(0x64) == 0) {
            u32 v = COMM_TVT_SYS_GetCamView(a);
            W(0x64) = 1;
            W(0x68) = 1;
            W(0x6c) = 1;
            W(0x70) = 1;
            W(0x74) = 0;
            B(0x78) = 0xff;
            W(0x7c) = 0;
            *(S21 *)(b + 0x80) = *(S21 *)(b + 0x40);
            B(0x2c) = 1;
            B(4) = 1;
            CTVT_CAMVIEW_StartLayoutChange(a, (char *)v, 0, 0);
        }
    } else {
        cur = GFL_NET_GetNegotiationNum();
        if (B(4) != cur) {
            func_021B8454(a, b);
            COMM_TVT_SYS_ClearNameWindows(a);
            if (B(4) < cur && busy == 0) {
                W(0x3b8) = 1;
                W(0x3bc) = COMM_TVT_SYS_GetHalfRes(a);
            }
            W(0x3b4) = 1;
            B(4) = cur;
            B(0x2c) = cur;
        }
    }
    for (i = 0; i < 4; i++) func_021B8628(a, (int)b, (int *)(b + 0x64 + i * 0x40), i);
    if (B(4) > 1) {
        if (W(0x184) == 1) {
            if (GFL_NET_LOWER_DATA_IsSendFinished() == 1) W(0x184) = 0;
        } else {
            u8 c1 = B(0x182);
            u8 c2 = B(0x183);
            if (c1 == (c1 & c2) && c1 != 0) {
                if (COMM_TVT_SYS_GetCameraBusy(a) == 0) {
                    COMM_TVT_SYS_SetCameraBusy(a, 1);
                    if (COMM_TVT_SYS_GetMessageActive(a) == 0) {
                        r7 = COMM_TVT_SYS_GetCamView(a);
                        s18 = CTVT_CAMVIEW_GetOwnSlotBuffer(a, (void *)r7);
                        s1c = CTVT_CAMVIEW_GetSlotBufferStep(a, r7);
                        MIi_CpuCopy32((void *)s18, (void *)W(0x18c), s1c);
                        s20 = CTVT_CAMVIEW_GetWindowHeight(a, r7);
                        s24 = CTVT_CAMVIEW_GetWindowWidth(a, r7);
                        res = SSP_StartJpegEncoder((void *)W(0x18c), (unsigned char *)W(0x190), s1c, (unsigned char *)W(0x188), s20, s24, 0x46, 1, 4);
                        if (res != 0) {
                            GFL_NET_LOWER_DATA_SetSendData(W(0x190), res, B(0x182), 0);
                            B(0x183) = 0;
                            W(0x184) = 1;
                        }
                    }
                    COMM_TVT_SYS_SetCameraBusy(a, 0);
                }
            }
        }
        if (B(0x1ac) != B(0x1ad)) {
            if (W(0x3c0) == 1) func_021B8A14((int)a, b);
        }
        if (W(0x3c4) == 1) {
            if (func_021B8740((int)a, (int)b, 4, 0) == 1) W(0x3c4) = 0;
        }
        if (W(0x3cc) == 1) {
            if (func_021B8740((int)a, (int)b, 5, 0) == 1) W(0x3cc) = 0;
        }
        if (W(0x3b4) == 1) {
            if (func_021B8AD4((int)a, b) == 1) W(0x3b4) = 0;
        }
    }
    if (busy == 0) {
        if (W(0x3b8) == 1) {
            if (func_021B8740((int)a, (int)b, 2, W(0x3bc)) == 1) W(0x3b8) = 0;
        }
        if (W(0x3b0) == 1) {
            hit = 0;
            for (j = 0; j < 4; j++) {
                if (*(int *)(b + j * 64 + 0x74) == 1) {
                    if (B(0x3d8) == 0xff) B(0x3d8) = j;
                    hit = 1;
                    *(int *)(b + j * 64 + 0x74) = 0;
                }
            }
            if (hit == 0) B(0x3d8) = 0xff;
            if (B(0x3d8) != B(0x3ae)) W(0x3d4) = 1;
            W(0x3b0) = 0;
        }
        cur = B(0x3d8);
        if (cur != 0xff) {
            if (*(int *)(b + cur * 64 + 0x64) == 0) {
                B(0x3d8) = 0xff;
                W(0x3d4) = 1;
                W(0x3b0) = 0;
            }
        }
        if (W(0x3d4) == 1) {
            if (func_021B8740((int)a, (int)b, 1, B(0x3d8)) == 1) W(0x3d4) = 0;
        }
    }
}

/*
 * note (2026-10-05, wD4 lane17): still MATCH, only the ov014 leaf 02179650 (pengy range, no label) is unresolved.
 * note 2026-10-04 wD2 lane01: still MATCH. Symbols line already has `thumb ov014`; match.py still says no witness (ov009/ov014 overlap, 021797A8-area leaf WIH_SetScanWaitFrames unlabelled in pengy's ov014). Needs a matched/labelled leaf at 0x02179650 in ov014 (pengy range, not touched).
 * note 2026-10-02: byte-correct. Only open relocation: the tail-call target 0x02179650 (pool word 0x02179651)
 *   is an unlabelled thumb leaf in ov014 ("ldr r1, =g_021797A8; ldr r2, [r1]; ldr r1, =0x1EC2; strh r0, [r2, r1]; bx lr").
 *   ov014 is outside this lane (pengy range); seeding 0x02179650 there closes this one.
 * note 2026-10-05 (wD8 lane06): re-run, still MATCH. Only blocker: WIH_SetScanWaitFrames, an unlabelled Thumb leaf in ov014
 *   (pengy's overlay, not same-overlay, so the witness exception does not apply). Seeding that label closes this.
 */
void func_021B8448(void *p, char *q)
{
    WIH_SetScanWaitFrames(5);
}

/*
 * note 2026-10-05 wD4 lane05: EXACT. w is a u32 local (callee keeps its real u16 return) declared
 *   between me and base: declaration order me, w, base, e gives slots 0x10, 0xC, 8, 4.
 */
void func_021B8454(void *a, char *q)
{
    u32 count = 0;
    int flag = 0;
    u8 i;
    u32 me;
    u32 w;
    u32 base;
    char *e;

    me = GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle());
    w = COMM_TVT_SYS_GetHeapId((u16 *)a);
    for (i = 0; i < 4; i++) {
        if (GFL_NET_IsConnectMember(i) == 1) {
            e = q + i * 64;
            if (*(u32 *)(e + 0x64) == 0) {
                base = COMM_TVT_SYS_GetCamView(a);
                *(u32 *)(e + 0x64) = 1;
                if (i == me) {
                    *(u32 *)(e + 0x70) = 1;
                } else {
                    u8 j;
                    for (j = 0; j < 3; j++) {
                        u32 m = 1 << j;
                        if (!(m & *(u8 *)(q + 0x170))) {
                            GFL_NET_LOWER_DATA_CreatePostWork(0xC000, i, w, *(u32 *)(q + j * 4 + 0x164));
                            *(u8 *)(q + 0x170) |= (u8)m;
                            *(u8 *)(e + 0x78) = j;
                            break;
                        }
                    }
                    *(u8 *)(q + 0x182) |= (u8)(1 << i);
                    *(u32 *)(e + 0x7C) = 1;
                }
                CTVT_CAMVIEW_RequestWindowAnimation((int)a, (char *)base, i);
                flag = 1;
            }
            count = (u8)(count + 1);
        } else {
            u32 off = i << 6;
            char *e2 = q + off;
            if (*(u32 *)(e2 + 0x64) == 1) {
                *(u32 *)(e2 + 0x64) = 0;
                if (*(u32 *)(e2 + 0x70) == 0) {
                    GFL_NET_LOWER_DATA_DeletePostWork(i);
                    *(u8 *)(q + 0x170) -= (u8)(1 << *(u8 *)(e2 + 0x78));
                }
                if (*(u8 *)(q + 0x3AE) == i)
                    *(u32 *)(q + 0x194) = 0;
                flag = 1;
                *(u8 *)(q + 0x182) -= (u8)(flag << i);
                func_021B8614((int)a, (int)q, q + 0x64 + off);
            }
        }
    }
    if (flag == 1) {
        COMM_TVT_SYS_SetMemberCount(a, count);
        COMM_TVT_SYS_SetSelfSlot(a, me);
    }
    CTVT_CAMVIEW_StartLayoutChange(a, (char *)COMM_TVT_SYS_GetCamView(a), 0, 1);
}

/*
 * True when one of three 6-byte records at +0x22 matches the probe string.
 *
 * Addresses are Black-image addresses.
 */
int func_021B85D0(unsigned char *p, unsigned char *q)
{
    unsigned char i;

    for (i = 0; i < 3; i++) {
        unsigned char j;
        int ok = 1;

        for (j = 0; j < 6; j++) {
            if (p[i * 6 + j + 0x22] != q[j]) {
                ok = 0;
                break;
            }
        }
        if (ok == 1) {
            return 1;
        }
    }
    return 0;
}

void func_021B8614(int unused, int unused2, void *p)
{
    ((struct Obj04551 *)p)->fC = 0;
    ((struct Obj04551 *)p)->f0 = 0;
    ((struct Obj04551 *)p)->f4 = 0;
    ((struct Obj04551 *)p)->f8 = 0;
    ((struct Obj04551 *)p)->f10 = 0;
    ((struct Obj04551 *)p)->f14 = 0xff;
    ((struct Obj04551 *)p)->f18 = 0;
}

void func_021B8628(void *a, int b, int *t, int c)
{
    char *r;
    int x, data;
    short dims[2];
    r = (char *)COMM_TVT_SYS_GetCamView(a);
    if (t[0] != 0 && t[3] != 1) {
        if (t[2] == 0 && t[1] == 1) {
            if (COMM_TVT_SYS_IsLaunchModeCall(a) == 0)
                COMM_TVT_SYS_SavePeerRecord((u32 *)a, t + 7);
            t[2] = 1;
        }
        switch (t[6]) {
        case 0:
        case 4:
            break;
        case 1:
            if (func_021B8740((int)a, b, 0, 0) == 1)
                t[6] = 2;
            break;
        case 2:
            if (GFL_NET_LOWER_DATA_IsPostComplete(c) == 0) {
                CTVT_CAMVIEW_ClearWindowDirty(a, r, c);
                t[6] = 3;
            }
            break;
        case 3:
            if (GFL_NET_LOWER_DATA_IsPostComplete(c) == 1) {
                x = CTVT_CAMVIEW_GetSlotBuffer(a, r, c);
                dims[1] = CTVT_CAMVIEW_GetWindowHeight(a, (u32)r);
                dims[0] = CTVT_CAMVIEW_GetWindowWidth(a, (u32)r);
                data = GFL_NET_LOWER_DATA_GetPostBuffer(c);
                SSP_StartJpegDecoder((unsigned char *)data, GFL_NET_LOWER_DATA_GetPostRecvSize(c), (void *)x, &dims[1], &dims[0], 0);
                CTVT_CAMVIEW_MarkWindowDirty(a, r, c);
                t[6] = 1;
            }
            break;
        }
    }
}

/*
 * Registers a 1-word/1-word record at a1[0xee..0xef] when the helper rejects the
 * request.
 *
 * Addresses are Black-image addresses.
 */
void func_021B8720(void *a0, u32 *a1, u32 a2)
{
    if (func_021B8740((int)a0, (int)a1, 2, a2) == 0) {
        a1[0xee] = 1;
        a1[0xef] = a2;
    }
}

u32 func_021B8740(int a, int b, u8 c, u32 d)
{
    struct { u32 w; u8 b; } buf;
    u32 entry;
    entry = (u32)GFL_NET_HANDLE_GetCurrentHandle();
    buf.b = c;
    buf.w = d;
    return GFL_NET_SendData(entry, 255, 0x2000, 8, (u32)&buf, 1, 0, 0);
}

void func_021B8770(int id, int size, u32 *msg, char *q)
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
            func_021BA234(r);
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
            func_021BA1E8(r, *(char * *)&((struct Obj00593 *)q)->f1A4, ((struct Obj00593 *)q)->f19C, 0, ((struct Obj00593 *)q)->f1A0);
        else
            func_021BA1E8(r, *(char * *)&((struct Obj00593 *)q)->f1A4, ((struct Obj00593 *)q)->f19C, 0x7f, ((struct Obj00593 *)q)->f1A0);
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

int func_021B891C(void *a, char *q, u16 *p)
{
    u32 entry;
    int r;
    entry = (u32)GFL_NET_HANDLE_GetCurrentHandle();
    r = GFL_NET_SendData(entry, 255, 0x2001, *p + 8, (u32)p, 1, 0, 1);
    if (r != 0)
        ((struct Obj24084 *)q)->f194 = 1;
    return r;
}

/*
 * Sets the +0x194 flag, refills the +0x1a4 block and returns it.
 *
 * Addresses are Black-image addresses.
 */
int func_021B8954(void *p, char *q)
{
    ((struct Obj10663 *)q)->f194 = 1;
    func_02082A7C(0, ((struct Obj10663 *)q)->f1A4, 0x208);
    return ((struct Obj10663 *)q)->f1A4;
}

void func_021B8978(int a, int b, int c, char *q)
{
    void *p;
    char *data, *input;
    Table table;
    p = (void *)COMM_TVT_SYS_GetTalkStatus(((struct Obj03854 *)q)->f3DC);
    data = *(char * *)&((struct Obj03854 *)q)->f1A4;
    input = data + 8;
    GFL_NET_GetHandleNetID((struct Link *)((u32)GFL_NET_HANDLE_GetCurrentHandle()));
    if (((struct Obj05444 *)data)->f5 == 0) {
        CTVT_ADPCM_ResetDecoder();
        func_02082A7C(0, (int)(((struct Obj03854 *)q)->f1A8), 0xc800);
    }
    func_021BA194((int)p, (int)input, *(char * *)&((struct Obj03854 *)q)->f1A8 + (((struct Obj05444 *)data)->f5 << 11), ((struct Obj05444 *)data)->f0);
    if (((struct Obj05444 *)data)->f4 == 1) {
        table = d_021C6EC0;
        ((struct Obj03854 *)q)->f1A0 = table.a[((struct Obj05444 *)data)->f6];
        ((struct Obj03854 *)q)->f198 = 1;
        ((struct Obj03854 *)q)->f19C = ((struct Obj05444 *)data)->f2;
    }
    ((struct Obj03854 *)q)->f194 = 0;
}

u32 func_021B8A14(int unused, char *q)
{
    u32 entry, result;
    u8 available, write, read;
    entry = (u32)GFL_NET_HANDLE_GetCurrentHandle();
    write = ((struct Obj06560 *)q)->f1AC;
    read = ((struct Obj06560 *)q)->f1AD;
    if (read > write) available = 64 - read;
    else available = write - read;
    if (available > 8) available = 8;
    if (available != 0) {
        result = GFL_NET_SendData(entry, 255, 0x2002, available * 8, (u32)(q + 0x1ae + read * 8), 1, 1, 0);
        if (result != 0) {
            ((struct Obj06560 *)q)->f1AD += available;
            if (((struct Obj06560 *)q)->f1AD >= 64) ((struct Obj06560 *)q)->f1AD -= 64;
        }
        return result;
    }
    return 1;
}

void func_021B8A98(int a, u32 b, char *list, char *q)
{
    char *p;
    u8 n, i;
    p = (char *)COMM_TVT_SYS_GetSprites(((struct Obj24086 *)q)->f3DC);
    n = (b >> 3) & 0xff;
    GFL_NET_GetHandleNetID((struct Link *)((u32)GFL_NET_HANDLE_GetCurrentHandle()));
    for (i = 0; i < n; i++)
        DRAW_SYSTEM_PushStroke(p, list + i * 8);
}

int func_021B8AD4(int unused, char *base)
{
    char *p = func_021B8B9C(unused, base);
    return GFL_NET_SendData((int)GFL_NET_HANDLE_GetCurrentHandle(), 0xFF, 0x2003, 0x21, (u32)p, 1, 1, 1);
}

/*
 * Claims the +0x68 slot of record i and releases the +0x3dc block once.
 *
 * Addresses are Black-image addresses.
 */
void func_021B8B00(int i, void *a, void *b, char *q)
{
    u32 *p = (u32 *)(q + 0x68) + (i << 4);

    if (*p == 0) {
        *p = 1;
        COMM_TVT_SYS_ClearNameWindows(*(char * *)&((struct Obj24087 *)q)->f3DC);
    }
}

char *func_021B8B20(int i, char *q)
{
    return func_021B8B94((int)((struct Obj24087 *)q)->f3DC, q, (u8)i);
}

/*
 * arm9 call whose result is the first argument of the second call.
 *
 * Addresses are Black-image addresses.
 */
void func_021B8B34(void *p, u32 a, u32 b)
{
    GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), b, 0x20);
}

int func_021B8B48(void *p, u32 a, u32 b)
{
    return GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), b, 0x20);
}

u32 func_021B8B5C(void *unused, u32 unused2)
{
    return GFL_NET_GetHandleNetID((struct Link *)((u32)GFL_NET_HANDLE_GetCurrentHandle()));
}

/*
 * Field getter, u8 at +0x3ae of the second argument.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021B8B68(int unused, char *p)
{
    return ((struct Obj24088 *)p)->f3AE;
}

int func_021B8B74(void *ctx, u8 *rec)
{
    return *(u32 *)(rec + 0x194);
}

u8 *func_021B8B7C(void *c, u8 *x)
{
    return x + 0xc;
}

/*
 * Field getter, u32 at +0x1a4 of the second argument.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021B8B84(int unused, char *p)
{
    return ((struct Obj24089 *)p)->f1A4;
}

/*
 * Field getter, u32 at +0x68 of record i (stride 0x40).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021B8B8C(int unused, char *base, int i)
{
    return *(u32 *)(base + (i << 6) + 0x68);
}

/*
 * Record address, +0x80, stride 0x40.
 *
 * Addresses are Black-image addresses.
 */
char *func_021B8B94(int unused, char *base, int i)
{
    return base + 0x80 + (i << 6);
}

char *func_021B8B9C(int unused, char *base)
{
    return base + 0x40;
}

/*
 * Field getter, u32 at +0x64 of record i (stride 0x40).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021B8BA4(int unused, char *base, int i)
{
    return *(u32 *)(base + (i << 6) + 0x64);
}

/*
 * Field getter, u8 at +0xa0 of record i (stride 0x40).
 *
 * Addresses are Black-image addresses.
 */
u8 func_021B8BAC(void *unused, char *base, int i)
{
    return *(u8 *)(base + (i << 6) + 0xa0);
}

/*
 * Wraps the +0x1ac cursor; on a mismatch returns the +0x1ae slot base.
 *
 * Addresses are Black-image addresses.
 */
int func_021B8BB8(int a, unsigned char *p, int *out)
{
    unsigned char v = (unsigned char)(p[0x1ac] + 1);

    (void)a;
    if (v >= 0x40) {
        v -= 0x40;
    }
    if (v == p[0x1ad]) {
        *out = 1;
        return 0;
    }
    *out = 0;
    return (int)(p + 0x1ae + p[0x1ac] * 8);
}

void func_021B8BFC(int unused, u8 *p)
{
    p[0x1ac] += 1;
    if (p[0x1ac] >= 0x40) {
        p[0x1ac] -= 0x40;
    }
}

void func_021B8C14(void *c, u8 *x)
{
    *(u16 *)(x + 0x3d0) = 0x4b0;
}

u32 func_021B8C20(void *c, u8 *x)
{
    if (*(u16 *)(x + 0x3d0) == 0)
        return 1;
    return 0;
}

/*
 * Return the word at +0x3C8 of the record. Filed as the call witness for
 * ov172 func_021B97AC.
 */
u32 func_021B8C34(void *ctx, u8 *rec)
{
    return *(u32 *)(rec + 0x3C8);
}
