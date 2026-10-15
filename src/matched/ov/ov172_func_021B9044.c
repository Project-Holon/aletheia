/*
 * function: CTVT_TALK_Main
 * address: 0x021B9044
 * packet: pkt_ov172_021B9044
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   COMM_TVT_SYS_GetHeapId 0x021BE00C thumb ov172
 *   COMM_TVT_SYS_GetReturnedFromChild 0x021BE02C thumb ov172
 *   COMM_TVT_SYS_SetReturnedFromChild 0x021BE030 thumb ov172
 *   COMM_TVT_SYS_GetCamView 0x021BDFDC thumb ov172
 *   COMM_TVT_SYS_GetComm 0x021BDFE4 thumb ov172
 *   COMM_TVT_SYS_GetMemberCount 0x021BE054 thumb ov172
 *   COMM_TVT_SYS_SetMessageActive 0x021BE0B0 thumb ov172
 *   COMM_TVT_SYS_GetPrintQue 0x021BE044 thumb ov172
 *   COMM_TVT_SYS_CreateTimeIcon 0x021BE318 thumb ov172
 *   COMM_TVT_SYS_DeleteTimeIcon 0x021BE34C thumb ov172
 *   CTVT_CAMVIEW_IsShutterIdle 0x021B7590 thumb ov172
 *   CTVT_CAMVIEW_StopCapture 0x021B7578 thumb ov172
 *   CTVT_CAMVIEW_RequestShutterSound1 0x021B7B80 thumb ov172
 *   CTVT_COMM_StopSession 0x021B8084 thumb ov172
 *   CTVT_COMM_SendCommand 0x021B8740 thumb ov172
 *   CTVT_COMM_SetTimingSync 0x021B8B34 thumb ov172
 *   CTVT_COMM_IsTimingSync 0x021B8B48 thumb ov172
 *   CTVT_COMM_GetHandleNetId 0x021B8B5C thumb ov172
 *   CTVT_COMM_GetMarkerSlot 0x021B8B68 thumb ov172
 *   CTVT_COMM_GetVoiceRecord 0x021B8B84 thumb ov172
 *   CTVT_TALK_HandleInput 0x021B9580 thumb ov172
 *   CTVT_TALK_UpdateVoiceSend 0x021B97AC thumb ov172
 *   CTVT_TALK_UpdateVoiceIcon 0x021B99B4 thumb ov172
 *   CTVT_TALK_ShowMessage 0x021B9C1C thumb ov172
 *   CTVT_TALK_OpenConfirmMenu 0x021B9C9C thumb ov172
 *   CTVT_TALK_UpdateConfirmMenu 0x021B9D04 thumb ov172
 *   CTVT_TALK_CheckEnd 0x021B9DF8 thumb ov172
 *   CTVT_TALK_BeginWaveform 0x021B9E3C thumb ov172
 *   CTVT_TALK_DrawWaveform 0x021B9E5C thumb ov172
 *   CTVT_TALK_HitCenter 0x021B9F4C thumb ov172
 *   CTVT_MIC_Update 0x021BA050 thumb ov172
 *   CTVT_MIC_GetPlayState 0x021BA244 thumb ov172
 *   CTVT_MIC_GetLength 0x021BA248 thumb ov172
 *   CTVT_MIC_GetPlayPos 0x021BA24C thumb ov172
 *   CTVT_MIC_GetPlayRatio 0x021BA254 thumb ov172
 *   WIPE_SYS_Start 0x0202208C thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   KEY_GetCont 0x0203630C arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   KEY_GetTrg 0x020362DC arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02061CA4 0x02061CA4 arm
 *   BMP_Clear 0x02043B5C arm
 *   _u32_div_f 0x0209C2B0 arm
 *   _s32_div_f 0x0209C0A4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

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

typedef signed short   s16;
typedef signed int     s32;
struct Actor;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct Obj;
struct PrintSys;
struct St;
extern u16 COMM_TVT_SYS_GetHeapId(u16 *p);
extern u32 COMM_TVT_SYS_GetReturnedFromChild(void *p);
extern void COMM_TVT_SYS_SetReturnedFromChild(void *p, u32 v);
extern u32 COMM_TVT_SYS_GetCamView(void *p);
extern u32 COMM_TVT_SYS_GetComm(void *p);
extern u8 COMM_TVT_SYS_GetMemberCount(void *p);
extern void COMM_TVT_SYS_SetMessageActive(void *p, u32 v);
extern u32 COMM_TVT_SYS_GetPrintQue(void *p);
extern void COMM_TVT_SYS_CreateTimeIcon(char *a0, void *a1);
extern void COMM_TVT_SYS_DeleteTimeIcon(void *p);
extern int CTVT_CAMVIEW_IsShutterIdle(int x, char *p);
extern void CTVT_CAMVIEW_StopCapture(int x, char *p);
extern void CTVT_CAMVIEW_RequestShutterSound1(int x, char *p);
extern void CTVT_COMM_StopSession(void *a, char *q);
extern u32 CTVT_COMM_SendCommand(int a, int b, u8 c, u32 d);
extern void CTVT_COMM_SetTimingSync(void *p, u32 a, u32 b);
extern int CTVT_COMM_IsTimingSync(void *p, u32 a, u32 b);
extern u32 CTVT_COMM_GetHandleNetId(void *p, u32 base);
extern u8 CTVT_COMM_GetMarkerSlot(int unused, char *p);
extern u32 CTVT_COMM_GetVoiceRecord(int unused, char *p);
extern void CTVT_TALK_HandleInput(u8 *c, u8 *q);
extern void CTVT_TALK_UpdateVoiceSend(void *ctx, struct St *st);
extern void CTVT_TALK_UpdateVoiceIcon(void *a0, char *a1);
extern void CTVT_TALK_ShowMessage(void *p, char *q, int id);
extern void CTVT_TALK_OpenConfirmMenu(void *p, char *q);
extern void CTVT_TALK_UpdateConfirmMenu(int self, int *q);
extern int CTVT_TALK_CheckEnd(void *p, int *out);
extern void CTVT_TALK_BeginWaveform(void *p, char *q);
extern void CTVT_TALK_DrawWaveform(int a0, char *obj, s16 *tbl, u8 a3, int idx, u16 v);
extern int CTVT_TALK_HitCenter(int a, int b, int mode);
extern void CTVT_MIC_Update(u32 *p);
extern u32 CTVT_MIC_GetPlayState(void *p);
extern int CTVT_MIC_GetLength(void *t);
extern int CTVT_MIC_GetPlayPos(void *t);
extern int CTVT_MIC_GetPlayRatio(void *t);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 WIPE_SYS_EndCheck(void);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern u32 KEY_GetCont(void);
extern int TOUCHPANEL_GetTrg(void);
extern u32 KEY_GetTrg(void);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_020409B4(u32 index);
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
extern void BMP_Clear(struct CharBuf *buf, u8 value);

u32 CTVT_TALK_Main(void *p, S *s)
{
    u32 heap;
    u32 a;
    u32 b;

    heap = COMM_TVT_SYS_GetHeapId(p);
    switch (s->state) {
    case 0:
        if (COMM_TVT_SYS_GetReturnedFromChild(p) == 1)
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
        COMM_TVT_SYS_SetReturnedFromChild(p, 0);
        s->state = 4;
        break;
    case 3:
        if (s->f4 == 6 && CLACT_IsActorAnimActive(s->f9C) == 1)
            break;
        a = COMM_TVT_SYS_GetCamView(p);
        if (s->f8 != 0 && CTVT_CAMVIEW_IsShutterIdle((int)p, (char *)a) != 1)
            break;
        WIPE_SYS_Start(0, 0, 0, 0, 6, 1, heap);
        COMM_TVT_SYS_SetReturnedFromChild(p, 1);
        s->state = 4;
        break;
    case 4:
        if (WIPE_SYS_EndCheck() != 1)
            break;
        if (s->f4 == 6)
            return 3;
        return 4;
    case 5:
        CTVT_TALK_HandleInput(p, (u8 *)s);
        break;
    case 6:
        if (CTVT_TALK_CheckEnd(p, (int *)s) != 0)
            break;
        if (CTVT_TALK_HitCenter((int)p, (int)s, 1) == 1 || (KEY_GetCont() & 0x101)) {
            if (CTVT_COMM_SendCommand((int)p, COMM_TVT_SYS_GetComm(p), 6, 0) == 1)
                s->state = 7;
            break;
        }
        s->state = 5;
        break;
    case 7:
        if (CTVT_TALK_CheckEnd(p, (int *)s) != 0)
            break;
        b = COMM_TVT_SYS_GetComm(p);
        a = CTVT_COMM_GetMarkerSlot((int)p, (char *)b);
        b = CTVT_COMM_GetHandleNetId(p, b);
        if (CTVT_TALK_HitCenter((int)p, (int)s, 1) == 1 || (KEY_GetCont() & 0x101)) {
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
        CTVT_TALK_UpdateVoiceSend(p, (struct St *)s);
        break;
    case 9:
        CTVT_TALK_OpenConfirmMenu(p, (char *)s);
        break;
    case 10:
        CTVT_TALK_UpdateConfirmMenu((int)p, (int *)s);
        break;
    case 11:
        if (CTVT_COMM_SendCommand((int)p, COMM_TVT_SYS_GetComm(p), 10, 0) == 1)
            s->state = 12;
    case 12:
        if (COMM_TVT_SYS_GetMemberCount(p) > 1)
            break;
        a = COMM_TVT_SYS_GetCamView(p);
        s->f4 = 7;
        s->state = 3;
        COMM_TVT_SYS_SetMessageActive(p, 1);
        CTVT_CAMVIEW_StopCapture((int)p, (char *)a);
        CTVT_CAMVIEW_RequestShutterSound1((int)p, (char *)a);
        s->f8 = 1;
        break;
    case 13:
        CTVT_COMM_StopSession(p, (char *)COMM_TVT_SYS_GetComm(p));
        COMM_TVT_SYS_SetMessageActive(p, 1);
        CTVT_TALK_ShowMessage(p, (char *)s, 0x24);
        s->state = 14;
        CTVT_CAMVIEW_RequestShutterSound1((int)p, (char *)COMM_TVT_SYS_GetCamView(p));
        s->f8 = 1;
        break;
    case 14:
        if (TOUCHPANEL_GetTrg() == 1 || (KEY_GetTrg() & 3)) {
            s->f4 = 7;
            s->state = 3;
            CTVT_CAMVIEW_StopCapture((int)p, (char *)COMM_TVT_SYS_GetCamView(p));
            s->f8 = 1;
        }
        break;
    case 15:
        if (CTVT_COMM_SendCommand((int)p, COMM_TVT_SYS_GetComm(p), 10, 0) != 1)
            break;
        a = COMM_TVT_SYS_GetCamView(p);
        COMM_TVT_SYS_SetMessageActive(p, 1);
        CTVT_CAMVIEW_RequestShutterSound1((int)p, (char *)a);
        s->state = 18;
        break;
    case 16:
        CTVT_COMM_StopSession(p, (char *)COMM_TVT_SYS_GetComm(p));
        CTVT_TALK_ShowMessage(p, (char *)s, 0x25);
        s->state = 17;
        s->f88 = 0;
        COMM_TVT_SYS_SetMessageActive(p, 1);
        CTVT_CAMVIEW_RequestShutterSound1((int)p, (char *)COMM_TVT_SYS_GetCamView(p));
        s->f8 = 1;
        break;
    case 17:
        s->f88++;
        if (TOUCHPANEL_GetTrg() == 1 || (KEY_GetTrg() & 3) || s->f88 >= 300)
            s->state = 18;
        break;
    case 18:
        CTVT_COMM_SetTimingSync(p, COMM_TVT_SYS_GetComm(p), 0x2F);
        s->state = 19;
        break;
    case 19:
        if (CTVT_COMM_IsTimingSync(p, COMM_TVT_SYS_GetComm(p), 0x2F) != 1)
            break;
        s->f4 = 7;
        s->state = 3;
        COMM_TVT_SYS_DeleteTimeIcon(p);
        COMM_TVT_SYS_SetMessageActive(p, 1);
        CTVT_CAMVIEW_StopCapture((int)p, (char *)COMM_TVT_SYS_GetCamView(p));
        s->f8 = 1;
        break;
    case 20:
        CTVT_COMM_StopSession(p, (char *)COMM_TVT_SYS_GetComm(p));
        CTVT_TALK_ShowMessage(p, (char *)s, 0x26);
        s->state = 21;
        COMM_TVT_SYS_SetMessageActive(p, 1);
        CTVT_CAMVIEW_RequestShutterSound1((int)p, (char *)COMM_TVT_SYS_GetCamView(p));
        s->f8 = 1;
        break;
    case 21:
        if (TOUCHPANEL_GetTrg() == 1 || (KEY_GetTrg() & 3)) {
            s->f4 = 7;
            s->state = 3;
            COMM_TVT_SYS_SetMessageActive(p, 1);
            CTVT_CAMVIEW_StopCapture((int)p, (char *)COMM_TVT_SYS_GetCamView(p));
            s->f8 = 1;
        }
        break;
    }
    CTVT_TALK_UpdateVoiceIcon(p, (char *)s);
    CTVT_MIC_Update(s->f10);
    if (s->f28 == 1) {
        void *h = (void *)COMM_TVT_SYS_GetPrintQue(p);
        if (PRINTSYS_QUE_IsExistTarget(h, BMP_WIN_GetBmp(s->f7C)) == 0) {
            BMP_WIN_TransferChars(s->f7C);
            BMP_WIN_MakeScreen(s->f7C);
            func_020409B4(4);
            s->f28 = 0;
            if (s->f84 == 1) {
                s->f84 = 0;
                COMM_TVT_SYS_CreateTimeIcon(p, s->f7C);
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
    if (s->f8C == 0 && s->state != 8 && s->state < 11 && CTVT_MIC_GetPlayState(s->f10) == 1) {
        CTVT_TALK_BeginWaveform(p, (char *)s);
        s->f8C = 1;
    }
    if (s->f8C == 1) {
        if (CTVT_MIC_GetPlayState(s->f10) == 0) {
            s->f8C = 0;
            BMP_Clear(BMP_WIN_GetBmp(s->f2C), 0);
            BMP_WIN_TransferChars(s->f2C);
        } else {
            short *base = (short *)(CTVT_COMM_GetVoiceRecord((int)p, (char *)COMM_TVT_SYS_GetComm(p)) + 0x800);
            int n = CTVT_MIC_GetPlayPos(s->f10);
            int max = CTVT_MIC_GetPlayRatio(s->f10);
            int w = CTVT_MIC_GetLength(s->f10);
            if (n > max)
                n = max;
            CTVT_TALK_DrawWaveform((int)p, (char *)s, base, 3, (u32)(w * n) / max, w);
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
