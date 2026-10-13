/*
 * file:     ctvt_comm.c
 * unit:     yes
 * function: func_021B77E8, func_021B7818, func_021B7830, func_021B785C, func_021B7888, func_021B78A0, func_021B78B8, func_021B792C, func_021B796C, func_021B7B20, func_021B7B30, func_021B7B3C, func_021B7B64, func_021B7B80, func_021B7BA8, func_021B7DCC, func_021B7E34, func_021B8050, func_021B8084, func_021B80CC, func_021B80DC, func_021B80E4, func_021B80EC, func_021B8108, func_021B8118, func_021B811C, func_021B8120, func_021B8130, func_021B8154, func_021B8448, func_021B8454, func_021B85D0, func_021B8614, func_021B8628, func_021B8720, func_021B8740, func_021B8770, func_021B891C, func_021B8954, func_021B8978, func_021B8A14, func_021B8A98, func_021B8AD4, func_021B8B00, func_021B8B20, func_021B8B34, func_021B8B48, func_021B8B5C, func_021B8B68, func_021B8B74, func_021B8B7C, func_021B8B84, func_021B8B8C, func_021B8B94, func_021B8B9C, func_021B8BA4, func_021B8BAC, func_021B8BB8, func_021B8BFC, func_021B8C14, func_021B8C20, func_021B8C34, func_021B8C3C, func_021B8CB0, func_021B8CC8, func_021B8FB8, func_021B9044, func_021B9574, func_021B9580, func_021B97AC, func_021B99B4, func_021B99F4, func_021B9AB8, func_021B9B88, func_021B9C1C, func_021B9C9C, func_021B9D04, func_021B9DF8, func_021B9E3C, func_021B9E5C, func_021B9F4C, func_021B9F98, func_021B9F9C, func_021BA01C, func_021BA050, func_021BA094, func_021BA098, func_021BA0BC, func_021BA114, func_021BA120, func_021BA158, func_021BA15C, func_021BA170
 * address:  0x021B77E8
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BE05C  0x021BE05C  thumb  ov172
 *   func_021BE078  0x021BE078  thumb  ov172
 *   g_021C6EA8     0x021C6EA8  data   ov172
 *   func_021BE0A4  0x021BE0A4  thumb  ov172
 *   g_021C6EB4    0x021C6EB4  data  ov172
 *   func_020061E4 0x020061E4 thumb
 *   func_021BE100  0x021BE100  thumb  ov172
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   func_021B69D0  0x021B69D0  thumb  ov172
 *   func_021B69D8  0x021B69D8  thumb  ov172
 *   func_02030734 0x02030734 arm
 *   func_021BE0D8 0x021BE0D8 thumb ov172
 *   GFL_NET_AllocAligned 0x0203D7C8 arm
 *   func_021C1A80 0x021C1A80 arm ov172
 *   func_021BE004 0x021BE004 thumb ov172
 *   func_02012944 0x02012944 thumb
 *   MYSTATUS_Copy 0x02008494 thumb
 *   GFL_NET_LOWER_DATA_Init 0x0203E5F8 arm
 *   d_021C71F4 0x021C71F4 data a4
 *   GFL_NET_LOWER_DATA_Exit 0x0203E6C0 arm
 *   func_020307B0 0x020307B0 arm
 *   GFL_NET_FreeAligned 0x0203D7FC arm
 *   func_021BE00C 0x021BE00C thumb ov172
 *   GFL_NET_SetWaitMode 0x0203D644 arm
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   GFL_NET_BeaconScanStart 0x0203D010 arm
 *   GFL_NET_StartByNetType 0x0203D01C arm
 *   func_02179328 0x02179328 thumb ov014
 *   GFL_NET_ConnectMacAddressParent 0x0203CFF0 arm
 *   GFL_NET_HANDLE_CheckNegotiation 0x02039ACC arm
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_IsNegotiationDone 0x020399B8 arm
 *   GFL_NET_COMMAND_AddCommandTable 0x0203A574 arm
 *   d_021C6ED4 0x021C6ED4 data a4
 *   func_02039C68 0x02039C68 arm
 *   func_02039CB4 0x02039CB4 arm
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
 *   func_02082A90 0x02082A90 arm
 *   func_021C2B74 0x021C2B74 arm ov172
 *   func_021BDFDC 0x021BDFDC thumb ov172
 *   func_021B7740 0x021B7740 thumb ov172
 *   func_021BE1A4 0x021BE1A4 thumb ov172
 *   func_021BE0F8 0x021BE0F8 thumb ov172
 *   func_021BE0FC 0x021BE0FC thumb ov172
 *   func_021BE0AC 0x021BE0AC thumb ov172
 *   func_021B77B8 0x021B77B8 thumb ov172
 *   WIH_SetScanWaitFrames 0x02179650 thumb ov014
 *   GFL_NET_IsConnectMember 0x0203D1C0 arm
 *   GFL_NET_LOWER_DATA_CreatePostWork 0x0203E808 arm
 *   GFL_NET_LOWER_DATA_DeletePostWork 0x0203E8C8 arm
 *   func_021BE058 0x021BE058 thumb ov172
 *   func_021BE0A8 0x021BE0A8 thumb ov172
 *   func_021BE2F0 0x021BE2F0 thumb ov172
 *   GFL_NET_LOWER_DATA_IsPostComplete 0x0203EA70 arm
 *   func_021B7724 0x021B7724 thumb ov172
 *   GFL_NET_LOWER_DATA_GetPostBuffer 0x0203E96C arm
 *   GFL_NET_LOWER_DATA_GetPostRecvSize 0x0203E9DC arm
 *   func_021BFFC4 0x021BFFC4 arm ov172
 *   func_021B7714 0x021B7714 thumb ov172
 *   GFL_NET_SendData 0x0203D3F8 arm
 *   func_021BE210 0x021BE210 thumb ov172
 *   func_021BDFEC 0x021BDFEC thumb ov172
 *   func_021BE2E0 0x021BE2E0 thumb ov172
 *   func_021BA234 0x021BA234 thumb ov172
 *   func_021BDFFC 0x021BDFFC thumb ov172
 *   func_021B6EA8 0x021B6EA8 thumb ov172
 *   func_021BE0CC 0x021BE0CC thumb ov172
 *   func_021BE0A0 0x021BE0A0 thumb ov172
 *   func_021BA1E8 0x021BA1E8 thumb ov172
 *   func_021BE0D4 0x021BE0D4 thumb ov172
 *   func_02082A7C  0x02082A7C  arm
 *   func_021B69F0 0x021B69F0 thumb ov172
 *   func_021BA194 0x021BA194 thumb ov172
 *   d_021C6EC0 0x021C6EC0 data a2
 *   func_021B6E88 0x021B6E88 thumb ov172
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   func_02082A60 0x02082A60 arm
 *   d_021C7200 0x021C7200 data a4
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_020409B4 0x020409B4 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B92C 0x0204B92C arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   func_021BE010 0x021BE010 thumb ov172
 *   func_021BE018 0x021BE018 thumb ov172
 *   func_021BE024 0x021BE024 thumb ov172
 *   func_021BE0B4 0x021BE0B4 thumb ov172
 *   func_021BDFE4 0x021BDFE4 thumb ov172
 *   func_021BA270 0x021BA270 thumb ov172
 *   APP_TASKMENU_CloseMenu  0x02027858  thumb
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *   func_02045730  0x02045730  arm
 *   func_020452E8  0x020452E8  arm
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   func_020414EC  0x020414EC  arm
 *   func_021BE02C 0x021BE02C thumb ov172
 *   func_021BE030 0x021BE030 thumb ov172
 *   func_021BE054 0x021BE054 thumb ov172
 *   func_021BE0B0 0x021BE0B0 thumb ov172
 *   func_021BE044 0x021BE044 thumb ov172
 *   func_021BE318 0x021BE318 thumb ov172
 *   func_021BE34C 0x021BE34C thumb ov172
 *   func_021B7590 0x021B7590 thumb ov172
 *   func_021B7578 0x021B7578 thumb ov172
 *   func_021BA244 0x021BA244 thumb ov172
 *   func_021BA248 0x021BA248 thumb ov172
 *   func_021BA24C 0x021BA24C thumb ov172
 *   func_021BA254 0x021BA254 thumb ov172
 *   WIPE_SYS_Start 0x0202208C thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   func_0201C6C4 0x0201C6C4 thumb
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   func_0203630C 0x0203630C arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   func_020362DC 0x020362DC arm
 *   func_02061CA4 0x02061CA4 arm
 *   _u32_div_f 0x0209C2B0 arm
 *   _s32_div_f 0x0209C0A4 arm
 *   func_021BE0B8 0x021BE0B8 thumb ov172
 *   func_021B77B4 0x021B77B4 thumb ov172
 *   func_021BE08C 0x021BE08C thumb ov172
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   func_020355D8 0x020355D8 arm
 *   d_021C6F83 0x021C6F83 data a1
 *   d_021C6F77 0x021C6F77 data a1
 *   func_021B69E0 0x021B69E0 thumb ov172
 *   func_021BA174 0x021BA174 thumb ov172
 *   TOUCHPANEL_HitCont 0x02035BA4 arm
 *   func_0200616C 0x0200616C thumb
 *   GFL_USE_SetSeSlotParams 0x02006268 thumb
 *   d_021C6F8F 0x021C6F8F data a1
 *   func_0209BDBC 0x0209BDBC arm
 *   func_0209C95C 0x0209C95C arm
 *   func_0209CB8C 0x0209CB8C arm
 *   func_0209C494 0x0209C494 arm
 *   func_0209C0A4 0x0209C0A4 arm
 *   d_021C6FA0 0x021C6FA0 data a2
 *   d_021C6F66 0x021C6F66 data a2
 *   func_021BE034 0x021BE034 thumb ov172
 *   func_021BE03C 0x021BE03C thumb ov172
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_02045EC0 0x02045EC0 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_021BE11C 0x021BE11C thumb ov172
 *   APP_TASKMENU_UpdateMenu  0x02027974  thumb
 *   APP_TASKMENU_IsFinish  0x020279E8  thumb
 *   APP_TASKMENU_GetCursorPos  0x02027A04  thumb
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_021BE0D0  0x021BE0D0  thumb  ov172
 *   BMP_GetPixels  0x020437D4  arm
 *   d_021C6F6E     0x021C6F6E  data
 *   func_02035D20 0x02035D20 arm
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   func_0208B24C 0x0208B24C arm
 *   func_0208B8B0 0x0208B8B0 arm
 *   func_0208BEF0 0x0208BEF0 arm
 *   func_0208BF54 0x0208BF54 arm
 *   func_021BA1B4 0x021BA1B4 thumb ov172
 *   func_02005654 0x02005654 thumb
 *   d_021C7218 0x021C7218 data a4
 *   d_021C720C 0x021C720C data a4
 *   g_021C88EC 0x021C88EC data a4
 *   veneer_027047C0  0x027047C0  arm
 *   func_0200566C  0x0200566C  thumb
 *   func_021BA1D8  0x021BA1D8  thumb  ov172
 *   func_0208B4B8 0x0208B4B8 arm
 *   NNS_SndWaveOutIsPlaying 0x02072CC4 arm
 *   func_021BA1E4 0x021BA1E4 thumb ov172
 *   func_0208B500 0x0208B500 arm
 *   func_0208B528 0x0208B528 arm
 *   CAMERA_I2CEffectExCore  0x02701248  arm  twl
 *   SNDEXi_SetIirFilter  0x027047C0  arm  twl
 */
#include "../../matched/include/Obj06553.h"
#include "../../matched/include/Obj06554.h"
#include "../../matched/include/Obj06555.h"
#include "../../matched/include/Obj06556.h"
#include "../../matched/include/Obj24071.h"
#include "../../matched/include/Obj14297.h"
#include "../../matched/include/Obj06558.h"
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
#include "../../matched/include/Obj04552.h"
#include "../../matched/include/Obj14301.h"
#include "../../matched/include/Obj02505.h"
#include "../../matched/include/Obj24090.h"
#include "../../matched/include/Obj06561.h"
#include "../../matched/include/Obj00998.h"
#include "../../matched/include/Obj05446.h"
#include "../../matched/include/Obj08259.h"
#include "../../matched/include/Obj10664.h"
#include "../../matched/include/Obj04553.h"
#include "../../matched/include/Obj04554.h"
#include "../../matched/include/Obj08260.h"

#define W(o) (*(int *)(b + (o)))
#define B(o) (*(u8 *)(b + (o)))
struct Entry;
struct Link;
struct Req;
struct Obj;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct TaskMenu;
struct Actor;
struct PrintSys;
struct St;
struct MsgBank;
struct U16Vec;
struct Bmp;
struct O;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef struct {
    int active;
    int anim;
    int busy;
    u16 cur[4];
    u16 tgt[4];
} Ent;

typedef struct {
    u8 pad0[0x20];
    int wide;
    u8 pad24[0x10];
    Ent ent[4];
} Q;

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

struct Rect { u16 x; u16 y; u16 z; u8 a; u8 b; };

typedef struct S {
    int state;
    int f4;
    int f8;
    u8 padC[4];
    void *f10;
    u8 pad14[0x14];
    int f28;
    void *f2C;
    u8 pad30[4];
    int f34;
    u8 f38;
    u8 pad39;
    u8 f3A[0x20];
    u8 f5A[0x20];
    u8 pad7A[2];
    void *f7C;
    u8 pad80[4];
    int f84;
    u16 f88;
    u8 pad8A[2];
    int f8C;
    u8 pad90[8];
    void *f98;
    void *f9C;
} S;

typedef signed short   s16_021B8BB8;

struct Rec {
    u16 h0;
    u16 h2;
    u8 b4;
    u8 b5;
    u8 b6;
};

struct St {
    u32 state;
    u32 sub;
    u8 pad08[5];
    u8 b0d;
    u8 pad0e[2];
    u32 *f10;
    u32 f14;
    u8 b18;
    u8 pad19[7];
    struct Rec *f20;
    void *f24;
    u8 pad28[4];
    void *f2c;
    u8 pad30[0x74];
    u32 fa4;
};

typedef short s16_021B9580;

typedef short          s16;

typedef enum MICResult { MIC_SUCCESS, MIC_BUSY, MIC_ILLEGAL, MIC_SEND_ERROR } MICResult;

typedef struct MICAutoParam {
    int type;
    void *buffer;
    u32 size;
    u32 rate;
    int loop;
    void (*callback)(MICResult, void *);
    void *arg;
} MICAutoParam;

extern int func_021BE05C(void *p);
extern u32 func_021BE078(void *p);
extern u32 func_021BE0A4(void *p);
extern void func_020061E4(unsigned int);
extern int func_021BE100(void);
extern int OS_IsRunOnTwl();
extern void func_021B69D0(void *p);
extern void func_021B69D8(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_021BE0D8(void *p);
extern void *GFL_NET_AllocAligned(u32 heap, u32 size, const char *file, u16 line);
extern unsigned long func_021C1A80(unsigned long width, unsigned long height, unsigned long sampling, unsigned long option);
extern u32 func_021BE004(void *p);
extern u8 *func_02012944(void *p);
extern void MYSTATUS_Copy(void *src, void *dst);
extern void GFL_NET_LOWER_DATA_Init(int a0, int a1);
extern void GFL_NET_LOWER_DATA_Exit(void);
extern u32 func_020307B0(void *p);
extern void GFL_NET_FreeAligned(void *);
extern u16 func_021BE00C(u16 *p);
extern void GFL_NET_SetWaitMode(int a);
extern int GFL_NET_GetRunState(void);
extern void GFL_NET_BeaconScanStart(void);
extern void GFL_NET_StartByNetType(void);
extern void func_02179328(void *v);
extern void GFL_NET_ConnectMacAddressParent(void *p);
extern int GFL_NET_HANDLE_CheckNegotiation(void);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_HANDLE_IsNegotiationDone(u8 *p);
extern void GFL_NET_COMMAND_AddCommandTable(u32 a, u32 b, u32 c, u32 d);
extern void func_02039C68(struct Link *p, u32 a, u32 b);
extern u32 func_02039CB4(struct Link *p, u32 a, u32 b);
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
extern void func_02082A90(const void *, void *, u32);
extern unsigned long func_021C2B74(void *src, unsigned char *dst, int limit, unsigned char *wrk, unsigned long width, unsigned long height, unsigned long quality, unsigned long sampling, unsigned long option);
extern u32 func_021BDFDC(void *);
extern void func_021B7740(void *, char *, int, int);
extern void func_021BE1A4(char *p);
extern u32 func_021BE0F8(void *);
extern void func_021BE0FC(void *, u32);
extern u32 func_021BE0AC(void *);
extern u32 func_021B77B8(void *, u32);
extern void WIH_SetScanWaitFrames(u16 v);
extern u32 GFL_NET_IsConnectMember(u32 index);
extern void GFL_NET_LOWER_DATA_CreatePostWork(u32 a, int b, u32 c, u32 d);
extern void GFL_NET_LOWER_DATA_DeletePostWork(int a);
extern void func_021BE058(void *p, u32 v);
extern void func_021BE0A8(void *p, u32 v);
extern void func_021BE2F0(u32 *p, void *q);
extern int GFL_NET_LOWER_DATA_IsPostComplete(unsigned int idx);
extern void func_021B7724(void *a, char *b, int c);
extern int GFL_NET_LOWER_DATA_GetPostBuffer(unsigned int idx);
extern int GFL_NET_LOWER_DATA_GetPostRecvSize(unsigned int idx);
extern int func_021BFFC4(unsigned char *data, unsigned long size, void *dst,
                         short *width, short *height, unsigned long option);
extern void func_021B7714(void *a, char *b, int c);
extern u32 GFL_NET_SendData(u32, u32, u32, u32, u32, u32, u32, u32);
extern void func_021BE210(void *a, u32 b);
extern int func_021BDFEC(void *p);
extern void func_021BE2E0(void *p);
extern void func_021BA234(void *p);
extern u32 func_021BDFFC(void *p);
extern void func_021B6EA8(void *p, u16 v);
extern void func_021BE0CC(void *p, u32 v);
extern void func_021BE0A0(void *p, u32 v);
extern int func_021BA1E8(int *self, char *buf, unsigned n, int vol, int freq);
extern void func_021BE0D4(void *p, u32 v);
extern void func_02082A7C();
extern void func_021B69F0(void);
extern int func_021BA194(int unused, int a, void *buf, unsigned n);
extern void func_021B6E88(char *p, void *q);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *a, u32 b, u32 c);
extern u32 GFL_NET_HANDLE_IsTimingSyncRange(struct Link *a, u32 b, u32 c);
extern void func_02082A60(const void *, void *, u32);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_0207D63C(void *, u32, u32, u32, u32);
extern void func_020409B4(u32 layer);
extern struct Obj *CLACT_CreateActor(void *, u32, u32, u32, const void *, u16, u16);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B92C(struct Obj *p, u32 v);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern u32 func_021BE010(void *p);
extern u32 func_021BE018(void *p, int i);
extern u32 func_021BE024(void *p);
extern u32 func_021BE0B4(void *p);
extern u32 func_021BDFE4(void *p);
extern int func_021BA270(void *p);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern u8 func_02045730(struct Descriptor *p);
extern u32 func_020452E8(struct Descriptor *d);
extern void CLACT_DeleteActor(struct Obj *p);
extern void func_020414EC(u32 i);
extern u32 func_021BE02C(void *p);
extern void func_021BE030(void *p, u32 v);
extern u8 func_021BE054(void *p);
extern void func_021BE0B0(void *p, u32 v);
extern u32 func_021BE044(void *p);
extern void func_021BE318(char *a0, void *a1);
extern void func_021BE34C(void *p);
extern int func_021B7590(int x, char *p);
extern void func_021B7578(int x, char *p);
extern u32 func_021BA244(void *p);
extern int func_021BA248(void *t);
extern int func_021BA24C(void *t);
extern int func_021BA254(void *t);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 WIPE_SYS_EndCheck(void);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern u32 func_0203630C(void);
extern int TOUCHPANEL_GetTrg(void);
extern u32 func_020362DC(void);
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
extern void func_021BE0B8(void *);
extern u32 func_021B77B4(int unused, void *p);
extern void func_021BE08C(void *);
extern int TOUCHPANEL_HitTrg(const void *);
extern void func_020355D8(u8 v);
extern void func_021B69E0(void);
extern int func_021BA174(int unused, void *a, void *buf, unsigned n);
extern int TOUCHPANEL_HitCont(const void *);
extern void func_0200616C(void *, int);
extern void GFL_USE_SetSeSlotParams(int i, u32 a, u32 b, u32 c);
extern int func_0209BDBC(int a);
extern int func_0209C95C(int a, int b);
extern int func_0209CB8C(int a, int b);
extern int func_0209C494(int a);
extern u32 func_021BE034(void *);
extern u32 func_021BE03C(void *);
extern void func_0201C6EC(struct PrintSys *p);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern u32 func_021BE11C(u8 *p);
extern void APP_TASKMENU_UpdateMenu(void *p);
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *p);
extern void func_0201F7A8(void *desc, u32 kind);
extern u32 func_021BE0D0(void *p);
extern int func_0209C0A4(int a, u16 b);
extern void *BMP_GetPixels(const struct Bmp *bmp);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);
extern void func_0208B24C(void);
extern void func_0208B8B0(void);
extern u32 func_0208BEF0(u32);
extern u32 func_0208BF54(u8);
extern void func_021BA1B4(char *, u32);
extern int func_02005654(int, int);
extern void func_0200566C(void);
extern void func_021BA1D8(void *p);
extern void *func_0208B4B8(void);
extern int NNS_SndWaveOutIsPlaying(struct O *);
extern void func_021BA1E4(void *);
extern MICResult func_0208B500(MICAutoParam *);
extern int func_0208B528(void);
u32 func_021B77E8();
u32 func_021B7818(void *p, void *q);
int func_021B7830(void *a0, char *a1, int a2);
u32 func_021B785C();
void func_021B7888(void *p, u16 a, u16 b, u16 c, u16 d);
void func_021B78A0(void *p, u16 a, u16 b, u16 c, u16 d);
int func_021B78B8(void *p, char *q);
int func_021B792C(void *p, u16 *value, u16 *limit);
void func_021B796C(void *p, char *q, int i);
void func_021B7B20(int unused, char *base, int i);
u32 func_021B7B30(int unused, char *base, int i);
void func_021B7B3C(int x, int y, int z);
void CAMERA_I2CEffectExCore(int a, int b, int c);
void func_021B7B64(int x, char *p);
void func_021B7B80(int x, char *p);
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
char *func_021B8C3C(char *unused, u16 heap);
void func_021B8CB0(void *a0, char *a1);
void func_021B8CC8(void *a, char *p);
void func_021B8FB8(void *a0, char *a1);
u32 func_021B9044(void *p, S *s);
void func_021B9574(int unused, char *p);
void func_021B9580(u8 *c, u8 *q);
void func_021B97AC(void *ctx, struct St *st);
void func_021B99B4(void *a0, char *a1);
void func_021B99F4(void *unused, u8 *q);
void func_021B9AB8(int a0, char *a1, u8 *p, u8 x0, u8 y0, u8 x1, u8 y1, u8 value);
void func_021B9B88(u8 *p, u8 x, u8 y, u8 value);
void func_021B9C1C(void *p, char *q, int id);
void func_021B9C9C(void *p, char *q);
void func_021B9D04(int self, int *q);
int func_021B9DF8(void *p, int *out);
void func_021B9E3C(void *p, char *q);
void func_021B9E5C(int a0, char *obj, s16 *tbl, u8 a3, int idx, u16 v);
int func_021B9F4C(int a, int b, int mode);
int func_021B9F98(int unused, int *p);
void *func_021B9F9C(u32 heap);
void SNDEXi_SetIirFilter(int, void *);
void func_021BA01C(char *p);
void func_021BA050(u32 *p);
void func_021BA094(int v);
void func_021BA098(void);
int func_021BA0BC(u32 *p);
void func_021BA114(MICResult result, void *arg);
int func_021BA120(u32 *p);
u32 func_021BA158(u32 *p);
u32 func_021BA15C(u32 *p);
u32 func_021BA170(u32 *p);
extern u32 g_021C6EA8[];
extern u32 g_021C6EB4[];
extern const char d_021C71F4[];
extern u8 d_021C6ED4[];
extern const Table d_021C6EC0;
extern const char d_021C7200[];
extern const u8 d_021C6F83[];
extern const u8 d_021C6F77[];
extern const u8 d_021C6F8F[];
extern const u16 d_021C6FA0[4], d_021C6F66[4];
extern u8 d_021C6F6E[];
extern const char d_021C7218[], d_021C720C[];
extern void *g_021C88EC;




/*
 * Table lookup at g_021C6EA8; the second arm keeps the low 16 bits of the halved word.
 *
 * Addresses are Black-image addresses.
 */
/* Old-style definition: callers elsewhere in the unit pass a second argument. */
u32 func_021B77E8(p)
void *p;
{
    u32 i = func_021BE05C(p);

    if (func_021BE078(p) == 0)
        return (u16)g_021C6EA8[i];
    return (g_021C6EA8[i] << 15) >> 16;
}




/*
 * Forward three arguments, the third from func_021BE0A4.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021B7818(void *p, void *q)
{
    return func_021B7830(p, q, func_021BE0A4(p));
}




/*
 * Scaled offset: func_021B785C's value times a2 when the state probe passes and a2 is non-zero.
 *
 * Addresses are Black-image addresses.
 */
int func_021B7830(void *a0, char *a1, int a2)
{
    int n = (int)func_021B785C(a0);

    if (func_021BE05C(a0) == 1 && a2 != 0)
        return ((struct Obj06553 *)a1)->f4 + n;
    return ((struct Obj06553 *)a1)->f4 + n * a2;
}




/* Old-style definition: callers elsewhere in the unit pass a second argument. */
u32 func_021B785C(p)
void *p;
{
    u32 i = func_021BE05C(p);
    if (func_021BE078(p) == 0) {
        return g_021C6EB4[i];
    }
    return g_021C6EB4[i] >> 2;
}




/*
 * Store the four u16 arguments at +0xc..+0x12 and the word 1 at +0.
 *
 * Addresses are Black-image addresses.
 */
void func_021B7888(void *p, u16 a, u16 b, u16 c, u16 d)
{
    ((struct Obj06554 *)p)->f0 = 1;
    ((struct Obj06554 *)p)->fC = a;
    ((struct Obj06554 *)p)->fE = b;
    ((struct Obj06554 *)p)->f10 = c;
    ((struct Obj06554 *)p)->f12 = d;
}




void func_021B78A0(void *p, u16 a, u16 b, u16 c, u16 d)
{
    ((struct Obj06555 *)p)->f0 = 1;
    ((struct Obj06555 *)p)->f14 = a;
    ((struct Obj06555 *)p)->f16 = b;
    ((struct Obj06555 *)p)->f18 = c;
    ((struct Obj06555 *)p)->f1A = d;
}



int func_021B78B8(void *p, char *q)
{
    int result, zero;
    if (((struct Obj06556 *)q)->f0 == 1) {
        zero = 0;
        result = 0;
        result |= func_021B792C(p, (u16 *)(q + 12), (u16 *)(q + 20));
        result |= func_021B792C(p, (u16 *)(q + 14), (u16 *)(q + 22));
        result |= func_021B792C(p, (u16 *)(q + 16), (u16 *)(q + 24));
        result |= func_021B792C(p, (u16 *)(q + 18), (u16 *)(q + 26));
        if (result == 0) ((struct Obj06556 *)q)->f0 = zero;
        if (((struct Obj06556 *)q)->f8 == 1) {
            ((struct Obj06556 *)q)->f8 = 0;
            func_020061E4(0x66e);
        }
        ((struct Obj06556 *)q)->f4 = 0;
        return 1;
    }
    return 0;
}




/*
 * Steps a u16 value towards a u16 limit by 4 or 8 (chosen from p->+0x20 == 1),
 * clamping at the limit.  Returns 1 when the value moved, 0 when it already sat
 * on the limit.
 *
 * Addresses are Black-image addresses.
 */
int func_021B792C(void *p, u16 *value, u16 *limit)
{
    unsigned char step = (((struct Obj24071 *)p)->f20 == 1) ? 4 : 8;
    u16 lim = *limit;
    u16 v = *value;

    if (v < lim) {
        if ((int)(v + step) < (int)lim)
            *value = v + step;
        else
            *value = lim;
        return 1;
    }
    if (v > lim) {
        if ((int)(v - step) > (int)lim)
            *value = v - step;
        else
            *value = lim;
        return 1;
    }
    return 0;
}



void func_021B796C(void *p, char *q, int i)
{
    Q *s;
    int sub;
    int mode;
    s = (Q *)q;
    sub = func_021BE05C(p);
    mode = i;
    if (sub == 1 && i != 0)
        mode = 1;
    if (s->wide == 0) {
        s->ent[i].tgt[0] = (mode == 0 || mode == 2) ? 0 : 0x80;
        s->ent[i].tgt[1] = (mode == 0 || mode == 1) ? 0 : 0x60;
        s->ent[i].tgt[2] = 0x80;
        s->ent[i].tgt[3] = (sub == 1) ? 0xc0 : 0x60;
    } else {
        s->ent[i].tgt[0] = (mode == 0 || mode == 2) ? 0 : 0x40;
        s->ent[i].tgt[1] = (mode == 0 || mode == 1) ? 0 : 0x30;
        s->ent[i].tgt[2] = 0x40;
        s->ent[i].tgt[3] = (sub == 1) ? 0x60 : 0x30;
    }
    if (s->ent[i].anim == 0) {
        s->ent[i].cur[0] = s->ent[i].tgt[0];
        s->ent[i].cur[1] = s->ent[i].tgt[1];
        s->ent[i].cur[2] = s->ent[i].tgt[2];
        s->ent[i].cur[3] = s->ent[i].tgt[3];
    } else {
        s->ent[i].busy = 1;
        switch (mode) {
        case 0:
            if (s->wide == 0)
                func_021B7888(&s->ent[i], 0, 0, 0x80, 0);
            else
                func_021B7888(&s->ent[i], 0, 0, 0x40, 0);
            break;
        case 1:
            if (s->wide == 0)
                func_021B7888(&s->ent[i], 0x80, 0, 0, (sub == 1) ? 0xc0 : 0x60);
            else
                func_021B7888(&s->ent[i], 0x40, 0, 0, (sub == 1) ? 0x60 : 0x30);
            break;
        case 2:
            if (s->wide == 0)
                func_021B7888(&s->ent[i], 0, 0x60, 0x80, 0);
            else
                func_021B7888(&s->ent[i], 0, 0x30, 0x40, 0);
            break;
        case 3:
            if (s->wide == 0)
                func_021B7888(&s->ent[i], 0x80, 0x60, 0, 0x60);
            else
                func_021B7888(&s->ent[i], 0x40, 0x30, 0, 0x30);
            break;
        }
    }
    s->ent[i].active = 1;
}




/*
 * Set the two words at +0x38 and +0x3c of record i (stride 0x1c).
 *
 * Addresses are Black-image addresses.
 */
void func_021B7B20(int unused, char *base, int i)
{
    *(u32 *)(base + i * 0x1c + 0x38) = 1;
    *(u32 *)((char *)base + i * 0x1c + 0x3c) = 1;
}




/*
 * Field getter, u32 at +0x34 of record i (stride 0x1c).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021B7B30(int unused, char *base, int i)
{
    return *(u32 *)(base + i * 0x1c + 0x34);
}




void func_021B7B3C(int x, int y, int z)
{
    int r = func_021BE100();
    if (r != 1) {
        return;
    }
    r = OS_IsRunOnTwl(r);
    if (r != 1) {
        return;
    }
    CAMERA_I2CEffectExCore(3, 3, z);
}












/*
 * Guarded flag set at +0x24.
 *
 * Addresses are Black-image addresses.
 */
void func_021B7B64(int x, char *p)
{
    if (func_021BE100() != 1) {
        return;
    }
    func_021B69D0(((struct Obj14297 *)p)->fA4);
    ((struct Obj14297 *)p)->f24 = 1;
}











void func_021B7B80(int x, char *p)
{
    if (func_021BE100() != 1) {
        return;
    }
    if (((struct Obj06558 *)p)->f24 != 1) {
        return;
    }
    if (((struct Obj06558 *)p)->f28 != 0) {
        return;
    }
    func_021B69D8(((struct Obj06558 *)p)->fA4);
    ((struct Obj06558 *)p)->f28 = 1;
}










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
        if (func_021BE0D8(p) == 0 || i == 0)
            *(void **)(q + 0x164 + i * 4) = GFL_NET_AllocAligned(heap, 3 << 14, d_021C71F4, 0x107);
    }
    ((struct Obj00386 *)q)->f188 = GFL_NET_AllocAligned(heap, func_021C1A80(0x80, 0xc0, 1, 4), d_021C71F4, 0x10c);
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
    MYSTATUS_Copy(func_02012944((void *)(*((u32 *)func_021BE004(p)))), q + 0xc);
    ((struct Obj00386 *)q)->f2C = 1;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 6; j++)
            *(u8 *)(q + i * 6 + j + 0x2e) = 0xff;
    ((Flags *)(q + 0x2d))->b0 = func_021BE100();
    ((Flags *)(q + 0x2d))->b1 = 0;
    MYSTATUS_Copy(func_02012944((void *)(*((u32 *)func_021BE004(p)))), q + 0x40);
    ((struct Obj00386 *)q)->f60 = func_021BE100();
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
        if (func_021BE0D8(p) == 0 || i == 0)
            GFL_NET_FreeAligned(*(void **)(q + i * 4 + 0x164));
    }
    func_020307B0(q);
}










void func_021B7E34(void *p, char *q)
{
    u32 h;
    u8 i;
    u8 j;
    func_021BE00C(p);
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
            func_02179328(func_021B8130);
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
        func_02039C68((struct Link *)h, 8, 0x20);
        ((struct Obj00289 *)q)->f8 = 6;
        break;
    case 6:
        if (func_02039CB4((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 8, 0x20) == 1)
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
        func_02039C68((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 9, 0x20);
        ((struct Obj00289 *)q)->f8 = 10;
        break;
    case 10:
        if (func_02039CB4((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 9, 0x20) == 1) {
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

    func_021BE00C(a);
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
            u32 v = func_021BDFDC(a);
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
            func_021B7740(a, (char *)v, 0, 0);
        }
    } else {
        cur = GFL_NET_GetNegotiationNum();
        if (B(4) != cur) {
            func_021B8454(a, b);
            func_021BE1A4(a);
            if (B(4) < cur && busy == 0) {
                W(0x3b8) = 1;
                W(0x3bc) = func_021BE078(a);
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
                if (func_021BE0F8(a) == 0) {
                    func_021BE0FC(a, 1);
                    if (func_021BE0AC(a) == 0) {
                        r7 = func_021BDFDC(a);
                        s18 = func_021B7818(a, (void *)r7);
                        s1c = func_021B785C(a, r7);
                        func_02082A90((void *)s18, (void *)W(0x18c), s1c);
                        s20 = func_021B77B8(a, r7);
                        s24 = func_021B77E8(a, r7);
                        res = func_021C2B74((void *)W(0x18c), (unsigned char *)W(0x190), s1c, (unsigned char *)W(0x188), s20, s24, 0x46, 1, 4);
                        if (res != 0) {
                            GFL_NET_LOWER_DATA_SetSendData(W(0x190), res, B(0x182), 0);
                            B(0x183) = 0;
                            W(0x184) = 1;
                        }
                    }
                    func_021BE0FC(a, 0);
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
    w = func_021BE00C((u16 *)a);
    for (i = 0; i < 4; i++) {
        if (GFL_NET_IsConnectMember(i) == 1) {
            e = q + i * 64;
            if (*(u32 *)(e + 0x64) == 0) {
                base = func_021BDFDC(a);
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
                func_021B7B20((int)a, (char *)base, i);
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
        func_021BE058(a, count);
        func_021BE0A8(a, me);
    }
    func_021B7740(a, (char *)func_021BDFDC(a), 0, 1);
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
    r = (char *)func_021BDFDC(a);
    if (t[0] != 0 && t[3] != 1) {
        if (t[2] == 0 && t[1] == 1) {
            if (func_021BE0D8(a) == 0)
                func_021BE2F0((u32 *)a, t + 7);
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
                func_021B7724(a, r, c);
                t[6] = 3;
            }
            break;
        case 3:
            if (GFL_NET_LOWER_DATA_IsPostComplete(c) == 1) {
                x = func_021B7830(a, r, c);
                dims[1] = func_021B77B8(a, (u32)r);
                dims[0] = func_021B77E8(a, (u32)r);
                data = GFL_NET_LOWER_DATA_GetPostBuffer(c);
                func_021BFFC4((unsigned char *)data, GFL_NET_LOWER_DATA_GetPostRecvSize(c), (void *)x, &dims[1], &dims[0], 0);
                func_021B7714(a, r, c);
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
            func_021BE210((char *)(*(u8 * *)&((struct Obj00593 *)q)->f3DC), (u8)v);
        } else {
            r = (void *)func_021BDFEC(((struct Obj00593 *)q)->f3DC);
            func_021BE2E0(((struct Obj00593 *)q)->f3DC);
            func_021BA234(r);
        }
        break;
    case 3:
        func_021B6EA8((void *)func_021BDFFC(((struct Obj00593 *)q)->f3DC), msg[0]);
        func_021BE0CC(((struct Obj00593 *)q)->f3DC, 0);
        break;
    case 2:
        base = (char *)func_021BDFDC(((struct Obj00593 *)q)->f3DC);
        v = msg[0];
        if (v == func_021BE078(((struct Obj00593 *)q)->f3DC))
            break;
        func_021BE0A0(((struct Obj00593 *)q)->f3DC, v);
        func_021B7740(((struct Obj00593 *)q)->f3DC, base, 1, 0);
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
        r = (void *)func_021BDFEC(((struct Obj00593 *)q)->f3DC);
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
        func_021BE2E0(((struct Obj00593 *)q)->f3DC);
        break;
    case 9:
        if (id == ((struct Obj00593 *)q)->f3AE)
            ((struct Obj00593 *)q)->f3B0 = 1;
        func_021BE2E0(((struct Obj00593 *)q)->f3DC);
        break;
    case 10:
        func_021BE0D4(((struct Obj00593 *)q)->f3DC, 1);
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
    p = (void *)func_021BDFEC(((struct Obj03854 *)q)->f3DC);
    data = *(char * *)&((struct Obj03854 *)q)->f1A4;
    input = data + 8;
    GFL_NET_GetHandleNetID((struct Link *)((u32)GFL_NET_HANDLE_GetCurrentHandle()));
    if (((struct Obj05444 *)data)->f5 == 0) {
        func_021B69F0();
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
    p = (char *)func_021BDFFC(((struct Obj24086 *)q)->f3DC);
    n = (b >> 3) & 0xff;
    GFL_NET_GetHandleNetID((struct Link *)((u32)GFL_NET_HANDLE_GetCurrentHandle()));
    for (i = 0; i < n; i++)
        func_021B6E88(p, list + i * 8);
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
        func_021BE1A4(*(char * *)&((struct Obj24087 *)q)->f3DC);
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





char *func_021B8C3C(char *unused, u16 heap)
{
    char *q;
    u8 i;
    q = func_02030734(heap, 0xac, 1, d_021C7200, 0xd7);
    ((struct Obj04552 *)q)->f10 = func_021B9F9C(heap);
    ((struct Obj04552 *)q)->f1C = func_02030734(heap, 0x808, 1, d_021C7200, 0xda);
    ((struct Obj04552 *)q)->f20 = ((struct Obj04552 *)q)->f1C;
    *(char * *)&((struct Obj04552 *)q)->f24 = *(char * *)&((struct Obj04552 *)q)->f1C + 8;
    ((struct Obj04552 *)q)->fD = 4;
    func_02082A60((void *)0x05000420, q + 0x5a, 32);
    for (i = 0; i < 16; i++) *(u16 *)(q + i * 2 + 0x3a) = 32767;
    return q;
}






void func_021B8CB0(void *a0, char *a1)
{
    func_020307B0(((struct Obj14301 *)a1)->f20);
    func_021BA01C(((struct Obj14301 *)a1)->f10);
    func_020307B0(a1);
}






/*
 * Sets up the BG layers and five OBJ sprites of the screen, then clears the state words.
 * 2026-10-05 (wD8 lane06): closed by statement order of the zero stores. mwcc keeps one constant
 *   of the join block in r7; with the zero stores in the order 0, 8, 0xA4 (address-temp store last)
 *   and 0x38, 0x34, 0x8C, 0xC the constant 1 wins r7 as in the image. Earlier lanes found the
 *   0x15/0x16 if/else for rc.z (holds &rc in r7 for the first block).
 */
void func_021B8CC8(void *a, char *p)
{
    u16 h;
    void *g;
    struct Rect rc;

    h = func_021BE00C(a);
    g = (void *)func_021BE010(a);
    func_02049658(g, 0xB, 6, 0, 0, 0, h);
    func_020498F4(g, 0x11, 6, 0, 0, 0, h);
    func_02049658(g, 0xB, 5, 0, 0x5000, 0, h);
    func_020498F4(g, 0xF, 5, 0, 0, 0, h);
    func_0207D63C((void *)0x04001050, 2, 0x14, 5, 0xF);
    func_020409B4(6);
    func_020409B4(5);
    rc.x = 0x80;
    rc.y = 0x60;
    rc.z = *(u8 *)(p + 0xD) + 0x19;
    rc.a = 0;
    rc.b = 2;
    *(struct Obj **)(p + 0x90) = CLACT_CreateActor((void *)func_021BE024(a), func_021BE018(a, 5), func_021BE018(a, 1), func_021BE018(a, 9), &rc, 1, h);
    func_0204B3DC(*(struct Obj **)(p + 0x90), 1);
    if (func_021BE0B4(a) == 1)
        rc.z = 0x15;
    else
        rc.z = 0x16;
    *(struct Obj **)(p + 0x94) = CLACT_CreateActor((void *)func_021BE024(a), func_021BE018(a, 5), func_021BE018(a, 1), func_021BE018(a, 9), &rc, 1, h);
    func_0204B3DC(*(struct Obj **)(p + 0x94), 1);
    rc.z = 0x14;
    *(struct Obj **)(p + 0x9C) = CLACT_CreateActor((void *)func_021BE024(a), func_021BE018(a, 5), func_021BE018(a, 1), func_021BE018(a, 9), &rc, 1, h);
    func_0204B3DC(*(struct Obj **)(p + 0x9C), 1);
    rc.z = 0x18;
    *(struct Obj **)(p + 0xA0) = CLACT_CreateActor((void *)func_021BE024(a), func_021BE018(a, 5), func_021BE018(a, 1), func_021BE018(a, 9), &rc, 1, h);
    func_0204B3DC(*(struct Obj **)(p + 0xA0), 1);
    rc.x = 0xE8;
    rc.y = 0xA8;
    rc.z = 1;
    rc.a = 0;
    rc.b = 0;
    *(struct Obj **)(p + 0x98) = CLACT_CreateActor((void *)func_021BE024(a), func_021BE018(a, 6), func_021BE018(a, 2), func_021BE018(a, 10), &rc, 1, h);
    func_0204B3DC(*(struct Obj **)(p + 0x98), 1);
    func_0204B92C(*(struct Obj **)(p + 0x98), 1);
    *(u32 *)(p + 0) = 0;
    *(u32 *)(p + 8) = 0;
    *(u32 *)(p + 0xA4) = 0;
    *(u32 *)(p + 0xA8) = 3;
    *(u32 *)(p + 0x2C) = BMP_WIN_Create(4, 8, 3, 0x10, 8, 0xA, 1);
    *(u32 *)(p + 0x7C) = BMP_WIN_Create(4, 1, 1, 0x1E, 4, 0xA, 1);
    BMP_Clear(func_02045770(*(void **)(p + 0x2C)), 0);
    BMP_WIN_MakeScreen(*(void **)(p + 0x2C));
    BMP_WIN_TransferChars(*(void **)(p + 0x2C));
    *(u32 *)(p + 0x80) = 0;
    *(u32 *)(p + 0x84) = 0;
    *(u32 *)(p + 0x28) = 0;
    func_020409B4(4);
    *(u8 *)(p + 0x38) = 0;
    *(u32 *)(p + 0x34) = 0;
    *(u32 *)(p + 0x8C) = 0;
    *(u8 *)(p + 0xC) = 0;
    {
        u32 r = func_021B8B68((int)a, (char *)func_021BDFE4(a));
        if (r != 0xFF) {
            func_021BE210(a, r);
            *(u32 *)(p + 0xA4) = 2;
        }
    }
    if (func_021BA270(*(void **)(p + 0x10)) == 0)
        *(u32 *)(p + 0xA4) = 2;
}






void func_021B8FB8(void *a0, char *a1)
{
    void *p;

    if (((struct Obj02505 *)a1)->f80 != 0)
        APP_TASKMENU_CloseMenu(((struct Obj02505 *)a1)->f80);

    p = ((struct Obj02505 *)a1)->f2C;
    BMP_WIN_ClearScreen(p);
    func_020409B4(func_02045730(p));

    p = ((struct Obj02505 *)a1)->f7C;
    BMP_WIN_ClearScreen(p);
    func_020409B4(func_02045730(p));

    func_020452E8(((struct Obj02505 *)a1)->f2C);
    func_020452E8(((struct Obj02505 *)a1)->f7C);
    CLACT_DeleteActor(((struct Obj02505 *)a1)->f98);
    CLACT_DeleteActor(((struct Obj02505 *)a1)->fA0);
    CLACT_DeleteActor(((struct Obj02505 *)a1)->f9C);
    CLACT_DeleteActor(((struct Obj02505 *)a1)->f94);
    CLACT_DeleteActor(((struct Obj02505 *)a1)->f90);
    func_020414EC(6);
    func_020409B4(6);
    *(u16 *)0x04001050 = 0;
}






u32 func_021B9044(void *p, S *s)
{
    u32 heap;
    u32 a;
    u32 b;

    heap = func_021BE00C(p);
    switch (s->state) {
    case 0:
        if (func_021BE02C(p) == 1)
            WIPE_SYS_Start(0, 1, 1, 0, 6, 1, heap);
        else
            WIPE_SYS_Start((void *)4, 1, 1, 0, 6, 1, heap);
        s->state = 1;
        break;
    case 1:
        if (WIPE_SYS_EndCheck() == 1)
            s->state = 5;
        break;
    case 2:
        WIPE_SYS_Start((void *)4, 0, 0, 0, 6, 1, heap);
        func_021BE030(p, 0);
        s->state = 4;
        break;
    case 3:
        if (s->f4 == 6 && CLACT_IsActorAnimActive(s->f9C) == 1)
            break;
        a = func_021BDFDC(p);
        if (s->f8 != 0 && func_021B7590((int)p, (char *)a) != 1)
            break;
        WIPE_SYS_Start(0, 0, 0, 0, 6, 1, heap);
        func_021BE030(p, 1);
        s->state = 4;
        break;
    case 4:
        if (WIPE_SYS_EndCheck() != 1)
            break;
        if (s->f4 == 6)
            return 3;
        return 4;
    case 5:
        func_021B9580(p, (u8 *)s);
        break;
    case 6:
        if (func_021B9DF8(p, (int *)s) != 0)
            break;
        if (func_021B9F4C((int)p, (int)s, 1) == 1 || (func_0203630C() & 0x101)) {
            if (func_021B8740((int)p, func_021BDFE4(p), 6, 0) == 1)
                s->state = 7;
            break;
        }
        s->state = 5;
        break;
    case 7:
        if (func_021B9DF8(p, (int *)s) != 0)
            break;
        b = func_021BDFE4(p);
        a = func_021B8B68((int)p, (char *)b);
        b = func_021B8B5C(p, b);
        if (func_021B9F4C((int)p, (int)s, 1) == 1 || (func_0203630C() & 0x101)) {
            if (a != 0xFF) {
                if (a == b) {
                    s->state = 8;
                    s->f4 = 0;
                } else {
                    s->state = 5;
                }
            }
        } else {
            s->state = 5;
        }
        break;
    case 8:
        func_021B97AC(p, (struct St *)s);
        break;
    case 9:
        func_021B9C9C(p, (char *)s);
        break;
    case 10:
        func_021B9D04((int)p, (int *)s);
        break;
    case 11:
        if (func_021B8740((int)p, func_021BDFE4(p), 10, 0) == 1)
            s->state = 12;
    case 12:
        if (func_021BE054(p) > 1)
            break;
        a = func_021BDFDC(p);
        s->f4 = 7;
        s->state = 3;
        func_021BE0B0(p, 1);
        func_021B7578((int)p, (char *)a);
        func_021B7B80((int)p, (char *)a);
        s->f8 = 1;
        break;
    case 13:
        func_021B8084(p, (char *)func_021BDFE4(p));
        func_021BE0B0(p, 1);
        func_021B9C1C(p, (char *)s, 0x24);
        s->state = 14;
        func_021B7B80((int)p, (char *)func_021BDFDC(p));
        s->f8 = 1;
        break;
    case 14:
        if (TOUCHPANEL_GetTrg() == 1 || (func_020362DC() & 3)) {
            s->f4 = 7;
            s->state = 3;
            func_021B7578((int)p, (char *)func_021BDFDC(p));
            s->f8 = 1;
        }
        break;
    case 15:
        if (func_021B8740((int)p, func_021BDFE4(p), 10, 0) != 1)
            break;
        a = func_021BDFDC(p);
        func_021BE0B0(p, 1);
        func_021B7B80((int)p, (char *)a);
        s->state = 18;
        break;
    case 16:
        func_021B8084(p, (char *)func_021BDFE4(p));
        func_021B9C1C(p, (char *)s, 0x25);
        s->state = 17;
        s->f88 = 0;
        func_021BE0B0(p, 1);
        func_021B7B80((int)p, (char *)func_021BDFDC(p));
        s->f8 = 1;
        break;
    case 17:
        s->f88++;
        if (TOUCHPANEL_GetTrg() == 1 || (func_020362DC() & 3) || s->f88 >= 300)
            s->state = 18;
        break;
    case 18:
        func_021B8B34(p, func_021BDFE4(p), 0x2F);
        s->state = 19;
        break;
    case 19:
        if (func_021B8B48(p, func_021BDFE4(p), 0x2F) != 1)
            break;
        s->f4 = 7;
        s->state = 3;
        func_021BE34C(p);
        func_021BE0B0(p, 1);
        func_021B7578((int)p, (char *)func_021BDFDC(p));
        s->f8 = 1;
        break;
    case 20:
        func_021B8084(p, (char *)func_021BDFE4(p));
        func_021B9C1C(p, (char *)s, 0x26);
        s->state = 21;
        func_021BE0B0(p, 1);
        func_021B7B80((int)p, (char *)func_021BDFDC(p));
        s->f8 = 1;
        break;
    case 21:
        if (TOUCHPANEL_GetTrg() == 1 || (func_020362DC() & 3)) {
            s->f4 = 7;
            s->state = 3;
            func_021BE0B0(p, 1);
            func_021B7578((int)p, (char *)func_021BDFDC(p));
            s->f8 = 1;
        }
        break;
    }
    func_021B99B4(p, (char *)s);
    func_021BA050(s->f10);
    if (s->f28 == 1) {
        void *h = (void *)func_021BE044(p);
        if (func_0201C6C4(h, func_02045770(s->f7C)) == 0) {
            BMP_WIN_TransferChars(s->f7C);
            BMP_WIN_MakeScreen(s->f7C);
            func_020409B4(4);
            s->f28 = 0;
            if (s->f84 == 1) {
                s->f84 = 0;
                func_021BE318(p, s->f7C);
            }
        }
    }
    if (s->f34 == 1) {
        s->f38++;
        if (s->f38 > 6) {
            s->f34 = 0;
            func_02061CA4((void *)0x1F, 0x20, (u32)s->f5A, 0x20);
        } else if (s->f38 % 12 < 6) {
            func_02061CA4((void *)0x1F, 0x20, (u32)s->f3A, 0x20);
        } else {
            func_02061CA4((void *)0x1F, 0x20, (u32)s->f5A, 0x20);
        }
    }
    if (s->f8C == 0 && s->state != 8 && s->state < 11 && func_021BA244(s->f10) == 1) {
        func_021B9E3C(p, (char *)s);
        s->f8C = 1;
    }
    if (s->f8C == 1) {
        if (func_021BA244(s->f10) == 0) {
            s->f8C = 0;
            BMP_Clear(func_02045770(s->f2C), 0);
            BMP_WIN_TransferChars(s->f2C);
        } else {
            short *base = (short *)(func_021B8B84((int)p, (char *)func_021BDFE4(p)) + 0x800);
            int n = func_021BA24C(s->f10);
            int max = func_021BA254(s->f10);
            int w = func_021BA248(s->f10);
            if (n > max)
                n = max;
            func_021B9E5C((int)p, (char *)s, base, 3, (u32)(w * n) / max, w);
        }
    }
    if (CLACT_IsActorAnimActive(s->f98) == 0) {
        if (s->state == 10)
            CLACT_SetActorAnimSeq(s->f98, 0xF);
        else
            CLACT_SetActorAnimSeq(s->f98, 1);
    }
    return 1;
}






/*
 * Tail call passing the field at +0x10.
 *
 * evidence: func_021BA094 is ov172's own code (a 2-byte "bx lr" right after
 * the "pop {r4, pc}" at 0x021BA092), inside ov172's window, so only ov172 can
 * be resident there when this pool word is used.  Its start is seeded in
 * layout/function_starts.txt from this pointer word, the only reference;
 * it attests as sole-ref/code from ov172's own listing.  The old hint ov217
 * named a different overlay's function mapped over the same address.
 *
 * Addresses are Black-image addresses.
 */
void func_021B9574(int unused, char *p)
{
    func_021BA094(((struct Obj24090 *)p)->f10);
}






/*
 * note 2026-10-05 wD4 lane03: EXACT. The 0xa4 store is written in each arm (= 2, = 2, = 0)
 *   instead of a local x stored once; tail merging then keeps the later x=2 copy and the first
 *   arm becomes the b stub, as in the listing.
 */
void func_021B9580(u8 *c, u8 *q)
{
    u32 a = func_021BDFE4(c);
    u32 b = func_021BE054(c);
    int r6;

    if (func_021B9DF8(c, (int *)q) == 1)
        return;
    if (*(int *)q <= 8 && func_021BE0B4(c) == 0) {
        u32 s = func_021BDFDC(c);
        if (func_020362DC() & 0x40) func_021B7B3C((int)c, s, 0);
        if (func_020362DC() & 0x10) func_021B7B3C((int)c, s, 5);
        if (func_020362DC() & 0x80) func_021B7B3C((int)c, s, 1);
        if (func_020362DC() & 0x20) func_021B7B3C((int)c, s, 3);
    }
    if (b == 1 || func_021BA270((void *)(*(u32 *)(q + 0x10))) == 0) {
        *(int *)(q + 0xa4) = 2;
    } else {
        u32 t = func_021B8B5C(c, a);
        u32 u = func_021B8B68((int)c, (char *)a);
        if (u != 0xff) {
            if (u == t) {
                u32 k = q[0xc];
                if (k) {
                    k--;
                    q[0xc] = k;
                } else if (func_021B8740((int)c, a, 9, 0) == 1) {
                    q[0xc] = 8;
                }
            }
            *(int *)(q + 0xa4) = 2;
        } else {
            u32 r = func_021B9F4C((int)c, (int)q, 0);
            if ((func_020362DC() & 0x101) || r == 1) {
                *(int *)q = 6;
                func_020061E4(0x66C);
                *(int *)(q + 0x34) = 1;
                q[0x38] = 0;
            }
            *(int *)(q + 0xa4) = 0;
        }
    }
    if (*(int *)q == 5) {
        if ((func_020362DC() & 0x400) || (func_020362DC() & 0x400) || TOUCHPANEL_HitTrg(d_021C6F83) != -1) {
            *(int *)q = 3;
            *(int *)(q + 4) = 6;
            CLACT_SetActorAnimSeq(*(struct Obj **)(q + 0x9c), 0x14);
            func_0204B92C(*(struct Obj **)(q + 0x9c), 1);
            func_020061E4(0x66C);
        }
    }
    if (*(int *)q == 5) {
        r6 = TOUCHPANEL_HitTrg(d_021C6F77);
        if (r6 == 0 || (func_020362DC() & 2)) {
            if (r6 == 0) func_020355D8(1); else func_020355D8(0);
            *(int *)q = 9;
            func_020061E4(0x551);
            CLACT_SetActorAnimSeq(*(struct Obj **)(q + 0x98), 9);
        } else if (r6 == 1 || (func_020362DC() & 0xc)) {
            func_021BE0B8(c);
            func_020061E4(0x66F);
            if (func_021BE0B4(c) == 1)
                CLACT_SetActorAnimSeq(*(struct Obj **)(q + 0x94), 0x15);
            else
                CLACT_SetActorAnimSeq(*(struct Obj **)(q + 0x94), 0x16);
        }
    }
    if (func_021BE0A4(c) == 0 && (func_020362DC() & 0x200)) {
        if (func_021B77B4((int)c, (void *)func_021BDFDC(c)) == 0) {
            func_021BE08C(c);
            func_020061E4(0x66C);
        }
    }
    func_021B99F4(c, q);
}






#pragma opt_propagation off





void func_021B97AC(void *ctx, struct St *st)
{
    int mode = func_021B9F4C((int)ctx, (int)st, 1);
    u32 id;
    u32 pos;
    int busy;
    u32 v;
    u32 off;

    if (func_021B9DF8(ctx, (int *)st) == 1)
        return;
    switch (st->sub) {
    case 0:
        if (func_021BA0BC(st->f10) == 1) {
            st->fa4 = 1;
            st->sub = 1;
            st->b18 = 0;
            st->f14 = 0;
            func_021B69E0();
            func_021B9E3C(ctx, (char *)st);
            return;
        }
        break;
    case 1:
        if (mode != 1 && (func_0203630C() & 0x101) == 0)
            func_021BA120(st->f10);
        if (func_021BA158(st->f10) == 0) {
            st->sub = 2;
            st->fa4 = 2;
        }
        v = func_021BA170(st->f10);
        pos = func_021BA15C(st->f10);
        off = 0x800;
        func_021B9E5C((int)ctx, (char *)st, (s16_021B9580 *)(v + off), 9, pos, 0xC000);
    case 2:
        id = func_021BDFE4(ctx);
        if (func_021B8C34(ctx, (u8 *)id) != 1)
            break;
        busy = func_021B8B74(ctx, (u8 *)id);
        pos = func_021BA15C(st->f10);
        if (st->f14 == 0 && busy == 0) {
            if (pos >= (u32)(st->b18 + 1) << 11 || st->sub == 2) {
                int n = func_021BA174((int)st->f10, (u8 *)func_021BA170(st->f10) + (st->b18 << 11), st->f24, 0x800);
                st->f20->b5 = st->b18;
                st->f20->h0 = n;
                st->f20->h2 = pos;
                st->f20->b6 = st->b0d;
                st->f20->b4 = (st->sub == 2 && pos <= (u32)(st->b18 + 1) << 11) ? 1 : 0;
                st->f14 = 1;
            }
        }
        if (st->f14 == 1) {
            if (func_021B891C(ctx, (char *)id, (u16 *)st->f20) == 1) {
                st->b18++;
                st->f14 = 0;
                if (st->f20->b4 == 1) {
                    st->sub = 3;
                    return;
                }
            }
        }
        break;
    case 3:
        id = func_021BDFE4(ctx);
        if (func_021B8B74(ctx, (u8 *)id) != 0)
            break;
        if (func_021B8740((int)ctx, id, 7, 0) == 1) {
            st->sub = 4;
            BMP_Clear(func_02045770(st->f2c), 0);
            BMP_WIN_TransferChars(st->f2c);
            return;
        }
        break;
    case 4:
        if (st->f20->h2 > 0x20) {
            if (func_021BA244((void *)func_021BDFEC(ctx)) == 1) {
                st->sub = 5;
                return;
            }
        } else {
            st->state = 5;
            return;
        }
        break;
    case 5:
        id = func_021BDFE4(ctx);
        if (func_021BA244((void *)func_021BDFEC(ctx)) == 0) {
            if (func_021B8740((int)ctx, id, 8, 0) == 1)
                st->state = 5;
        }
        break;
    }
}






#pragma opt_propagation reset






/*
 * Translates the +0xa4 state into a +0xa0 buffer code, doing nothing when the
 * state already equals the +0xa8 one.
 *
 * Addresses are Black-image addresses.
 */
void func_021B99B4(void *a0, char *a1)
{
    u32 v = ((struct Obj06561 *)a1)->fA4;
    u32 w = ((struct Obj06561 *)a1)->fA8;

    if (v == w)
        return;
    if (v == 1) {
        CLACT_SetActorAnimSeq(((struct Obj06561 *)a1)->fA0, 0x17);
        return;
    }
    if (v == 2) {
        CLACT_SetActorAnimSeq(((struct Obj06561 *)a1)->fA0, 0x23);
        return;
    }
    CLACT_SetActorAnimSeq(((struct Obj06561 *)a1)->fA0, 0x18);
}





void func_021B99F4(void *unused, u8 *q)
{
    u32 a = TOUCHPANEL_HitTrg(d_021C6F8F);
    u32 b = TOUCHPANEL_HitCont(d_021C6F8F);
    int flag = -1;
    int changed = 0;
    if (a != -1) {
        q[15] = 0;
        if (a <= 1) { q[14] = 0; flag = 0; }
        else { q[14] = 1; flag = 1; }
    } else if (b != -1) {
        int agree = 0;
        if (b <= 1) { if (q[14] == 0) agree = 1; }
        else { if (q[14] == 1) agree = 1; }
        if (agree == 1) {
            q[15]++;
            if (*(volatile u8 *)&((struct Obj00998 *)q)->fF >= 25) {
                flag = q[14];
                q[15] = 10;
            }
        } else q[14] = 255;
    } else q[14] = 255;
    if (flag == 0) {
        if (q[13] < 8) {
            changed = 1; q[13]++;
            CLACT_SetActorAnimSeq(*(struct Obj * *)&((struct Obj00998 *)q)->f90, (u16)(*(volatile u8 *)&((struct Obj00998 *)q)->fD + 25));
        }
    } else if (flag == 1) {
        if (q[13] > 0) {
            changed = 1; q[13]--;
            CLACT_SetActorAnimSeq(*(struct Obj * *)&((struct Obj00998 *)q)->f90, (u16)(*(volatile u8 *)&((struct Obj00998 *)q)->fD + 25));
        }
    }
    if (changed == 1) {
        int angle;
        angle = (q[13] - 4) * 64;
        func_0200616C((void *)1644, 1);
        GFL_USE_SetSeSlotParams(1, -1, angle, -1);
    }
}






static inline int Abs(int a)
{
    return a < 0 ? -a : a;
}






/*
 * note: Draws a line from (x0, y0) to (x1, y1) into a 4bpp tile buffer with func_021B9B88, in
 *   n = max(|dx|, |dy|) + 1 fixed-point steps (step = round(d << 12) / n).
 * lever (2026-10-05, wD9r lane157): value is a narrow parameter (u8 colour index) passed straight
 *   to a u8 callee parameter. With int value the stack-argument copy came first at entry; the narrow
 *   type puts the x0 spill store first (str r3; ldr value; str r2; str value), as in ov127 021C5C8C.
 *   Earlier levers kept: u8 x0 (reloaded at each use), Abs as a static inline ternary, y1/y0 copied
 *   into locals after the dx abs, the y0 read `*(u8 *)&y0` before the loop in an explicit
 *   `if (n > 0)` do/while, stepy declared before stepx.
 */
void func_021B9AB8(int a0, char *a1, u8 *p, u8 x0, u8 y0, u8 x1, u8 y1, u8 value)
{
    int stepx, stepy;
    int dx = Abs(x0 - x1);
    int dy;
    int n, i;
    int accx, accy;
    int d, r;
    int ay; int by; int yb;
    by = y1; ay = y0; dy = Abs(ay - by);
    if (dx <= dy)
        dx = dy;
    n = dx + 1;
    d = x1 - x0;
    if (d > 0)
        r = func_0209C95C(0x3f000000, func_0209BDBC(d << 12));
    else
        r = func_0209CB8C(func_0209BDBC(d << 12), 0x3f000000);
    stepx = func_0209C494(r) / n;
    d = by - ay;
    if (d > 0)
        r = func_0209C95C(0x3f000000, func_0209BDBC(d << 12));
    else
        r = func_0209CB8C(func_0209BDBC(d << 12), 0x3f000000);
    stepy = func_0209C494(r) / n;
    accx = 0;
    accy = 0;
    i = 0;
    if (n > 0) {
        yb = *(u8 *)&y0;
        do {
            func_021B9B88(p, x0 + (accx >> 12), yb + (accy >> 12), value);
            accx += stepx;
            accy += stepy;
            i++;
        } while (i < n);
    }
}





/*
 * lever: Explicit weights pointer retains the array base in r1 and cell in r3.
 */
void func_021B9B88(u8 *p, u8 x, u8 y, u8 value)
{
    u8 subx = x % 8;
    u8 shift = subx % 4;
    u16 *cell = (u16 *)(p + (u16)((u32)x / 8 + (u32)y / 8 * 16) * 32 + (subx / 4 + (u8)(y % 8) * 2) * 2);
    u16 weights[4];
    u16 *w = weights;
    weights[0] = d_021C6FA0[0];
    weights[1] = d_021C6FA0[1];
    weights[2] = d_021C6FA0[2];
    weights[3] = d_021C6FA0[3];
    if ((u8 *)cell < p + 4096 && (u8 *)cell >= p)
        *cell = (*cell & d_021C6F66[shift]) + w[shift] * value;
}





void func_021B9C1C(void *p, char *q, int id)
{
    u32 font = func_021BE034(p);
    u32 msgs = func_021BE03C(p);
    u32 sys = func_021BE044(p);
    u32 text;
    func_0201C6EC((struct PrintSys *)sys);
    BMP_Clear((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj05446 *)q)->f7C)), 15);
    text = (u32)func_02045EC0((struct MsgBank *)msgs, id);
    PRINTSYS_PrintQueColor((void *)sys, (u32)func_02045770((struct Descriptor *)((struct Obj05446 *)q)->f7C), 0, 0, text, font, 1088);
    STRBUF_Delete((struct U16Vec *)text);
    BMP_WIN_TransferChars((struct Descriptor *)((struct Obj05446 *)q)->f7C);
    BMP_WIN_MakeScreen((struct Cfg *)(((struct Obj05446 *)q)->f7C));
    func_0201F73C((void *)(((struct Obj05446 *)q)->f7C), 1, 320, 9);
    ((struct Obj05446 *)q)->f28 = 1;
}





void func_021B9C9C(void *p, char *q)
{
    if (func_021B80E4((int)p, (char *)func_021BDFE4(p)) == 5) {
        func_021B9C1C(p, q, 32);
    } else if (func_021BE0A4(p) == 0 && func_021BE054(p) > 1) {
        func_021B9C1C(p, q, 33);
    } else {
        func_021B9C1C(p, q, 32);
    }
    ((struct Obj08259 *)q)->f80 = (void *)func_021BE11C(p);
    ((struct Obj08259 *)q)->f0 = 10;
    if (CLACT_IsActorAnimActive(((struct Obj08259 *)q)->f98) == 0)
        CLACT_SetActorAnimSeq(((struct Obj08259 *)q)->f98, 15);
}






void func_021B9D04(int self, int *q)
{
    int r6;
    u32 r7;

    if (func_021B9DF8((void *)self, q) == 1) {
        APP_TASKMENU_CloseMenu((void *)q[0x20]);
        q[0x20] = 0;
        return;
    }
    APP_TASKMENU_UpdateMenu((void *)q[0x20]);
    if (APP_TASKMENU_IsFinish((void *)q[0x20]) != 1)
        return;
    if (APP_TASKMENU_GetCursorPos((const u8 *)q[0x20]) == 0) {
        if (func_021B80E4(self, (char *)func_021BDFE4((void *)self)) == 5) {
            q[0] = 0xF;
            q[0x21] = 1;
            func_021B9C1C((void *)self, (char *)q, 0x2A);
        } else if (func_021BE0A4((void *)self) == 0 && func_021BE054((void *)self) > 1) {
            q[0] = 0xB;
        } else {
            q[1] = 7;
            q[0] = 3;
            r6 = 1;
            func_021BE0B0((void *)self, 1);
            r7 = func_021BDFDC((void *)self);
            func_021B7578(self, (char *)r7);
            func_021B7B80(self, (char *)r7);
            q[2] = r6;
        }
    } else {
        q[0] = 5;
        func_0201F7A8((void *)q[0x1F], 1);
        BMP_WIN_ClearScreen((struct Descriptor *)q[0x1F]);
        BMP_WIN_MakeScreen((struct Cfg *)q[0xB]);
        func_020409B4(4);
        CLACT_SetActorAnimSeq((struct Obj *)q[0x26], 1);
    }
    APP_TASKMENU_CloseMenu((void *)q[0x20]);
    q[0x20] = 0;
}






/*
 * Maps the +4 state to an output code through the two ARM9 probes.
 *
 * Addresses are Black-image addresses.
 */
int func_021B9DF8(void *p, int *out)
{
    if (func_021BE0D0(p) == 1) {
        int v = func_021B80E4((int)p, (char *)func_021BDFE4(p));

        *out = (v == 5) ? 0x10 : 0xd;
        return 1;
    }
    if (func_021BE054(p) <= 1) {
        *out = 0x14;
        return 1;
    }
    return 0;
}






void func_021B9E3C(void *p, char *q)
{
    q[0x30] = 3;
    q[0x31] = 0x20;
    BMP_Clear((struct CharBuf *)((int)func_02045770((struct Descriptor *)((struct Obj10664 *)q)->f2C)), 0);
}






void func_021B9E5C(int a0, char *obj, s16 *tbl, u8 a3, int idx, u16 v)
{
    u32 n;
    void *dev;
    int flag;
    u8 c;
    int h;
    int x;
    u32 c1;

    if (idx < 0)
        return;
    n = func_0209C0A4(idx * 0x7B, v);
    dev = BMP_GetPixels(func_02045770(((struct Obj04553 *)obj)->f2C));
    flag = 0;
    c = ((struct Obj04553 *)obj)->f30;
    if (c < n) {
        flag = 1;
        while (c < n) {
            c1 = c + 1;
            x = c1 * v;
            h = ((tbl[x / 128 / 2] + 0x8000) << 6) / 0x10000;
            if (c < 0xB) {
                u32 t = 0x20 - d_021C6F6E[c - 3];
                if (h < t)
                    h = t;
            }
            if (c > 0x72) {
                u32 t = 0x20 - d_021C6F6E[(u8)(0x7A - c)];
                if (h < t)
                    h = t;
            }
            func_021B9AB8(a0, obj, dev, c, ((struct Obj04553 *)obj)->f31, (u8)c1, (u8)h, a3);
            ((struct Obj04553 *)obj)->f30 += 1;
            ((struct Obj04553 *)obj)->f31 = (u8)h;
            c = ((struct Obj04553 *)obj)->f30;
        }
    }
    if (flag == 1)
        BMP_WIN_TransferChars((struct Descriptor *)*(int *)&((struct Obj04553 *)obj)->f2C);
}





/*
 * extent: Two bytes of zero alignment padding follow the return.
 */
int func_021B9F4C(int a, int b, int mode)
{
    u32 x, y;
    int dx, dy, d;
    if (mode == 0) func_02035D20(&x, &y);
    else TOUCHPANEL_GetPointCont(&x, &y);
    if (y >= 104) {
        dx = 128 - x;
        dy = 104 - y;
        d = dx * dx + dy * dy;
        if (d > 256 && d < 5184) return 1;
    }
    return 0;
}




int func_021B9F98(int unused, int *p)
{
    return p[4];
}



void *func_021B9F9C(u32 heap)
{
    u32 *p = func_02030734(heap, 36, 1, d_021C7218, 87);
    func_0208B24C();
    func_0208B8B0();
    func_0208BEF0(1);
    func_0208BF54(80);
    if (OS_IsRunOnTwl() == 1) SNDEXi_SetIirFilter(0, (void *)d_021C720C);
    func_021BA1B4((char *)p, heap);
    p[1] = (u32)GFL_NET_AllocAligned(heap, 51200, d_021C7218, 134);
    p[0] = 0;
    p[2] = 0;
    *((u8 *)p + 16) = 0;
    g_021C88EC = p;
    func_02005654((int)func_021BA098, 0);
    return p;
}




void func_021BA01C(char *p)
{
    func_0200566C();
    *(u32 *)0x021C88EC = 0;
    func_021BA120((u32 *)p);
    func_021BA1D8(p);
    func_0208BEF0(0);
    GFL_NET_FreeAligned(((struct Obj04554 *)p)->f4);
    func_020307B0(p);
}


void func_021BA050(u32 *p)
{
    u32 n;
    if (p[2] == 1) {
        n = (u32)func_0208B4B8();
        if (n == 0) p[0] = 0;
        else {
            p[0] = n - p[1] + 4;
            if (p[0] > 51200) p[0] = 51200;
        }
    }
    if (p[3] == 1) {
        if (NNS_SndWaveOutIsPlaying((struct O *)p[8]) == 0) p[3] = 0;
    }
    func_021BA1E4(p);
}


void func_021BA094(int v)
{
}


void func_021BA098(void)
{
    u8 *p = g_021C88EC;
    if (((struct Obj08260 *)p)->fC == 1) (((struct Obj08260 *)p)->f14)++;
    p = g_021C88EC;
    if (p[16] < 180) p[16]++;
}


/*
 * extent: Callback at 021BA114 stores zero at r1+8 and 51200 at r1.
 */
int func_021BA0BC(u32 *p)
{
    MICAutoParam param;
    param.type = 3;
    param.size = 51200;
    param.buffer = (void *)p[1];
    func_02082A7C(0, param.buffer, param.size);
    if (param.size & 31) param.size &= ~31;
    param.callback = func_021BA114;
    param.loop = 0;
    param.rate = 4097;
    param.arg = p;
    if (func_0208B500(&param) == 0) {
        p[2] = 1;
        p[0] = 0;
        return 1;
    }
    return 0;
}


void func_021BA114(MICResult result, void *arg)
{
    u32 *p = arg;
    p[2] = 0;
    p[0] = 51200;
}


int func_021BA120(u32 *p)
{
    if (p[2] == 0) return 1;
    if (func_0208B528() == 0) {
        p[0] = (u32)func_0208B4B8() - p[1] + 4;
        if (p[0] > 51200) p[0] = 51200;
        p[2] = 0;
        return 1;
    }
    return 0;
}


u32 func_021BA158(u32 *p) { return p[2]; }


u32 func_021BA15C(u32 *p)
{
    if (p[0] > 2048) return p[0] - 2048;
    return 0;
}


u32 func_021BA170(u32 *p) { return p[1]; }
