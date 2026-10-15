/*
 * function: CTVT_COMM_Update
 * address: 0x021B8154
 * packet: pkt_ov172_021B8154
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note 2026-10-05 wD4 lane05: EXACT*. Three source fixes: the 0x21-byte copy b+0x40 -> b+0x80 is a struct copy
 *   (one-member u8[0x21] struct); the slot stores go in offset order (0x74 = 0, 0x78 = 0xff, 0x7c = 0);
 *   in the j loop `hit = 1` comes before the slot store.
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   GFL_NET_GetNegotiationNum 0x0203D1B4 arm
 *   GFL_NET_LOWER_DATA_IsSendFinished 0x0203EA54 arm
 *   GFL_NET_LOWER_DATA_SetSendData 0x0203E758 arm
 *   MIi_CpuCopy32 0x02082A90 arm
 *   SSP_StartJpegEncoder 0x021C2B74 arm ov172
 *   COMM_TVT_SYS_GetCamView 0x021BDFDC thumb ov172
 *   CTVT_CAMVIEW_StartLayoutChange 0x021B7740 thumb ov172
 *   CTVT_COMM_UpdateMembers 0x021B8454 thumb ov172
 *   COMM_TVT_SYS_ClearNameWindows 0x021BE1A4 thumb ov172
 *   COMM_TVT_SYS_GetHalfRes 0x021BE078 thumb ov172
 *   CTVT_COMM_UpdatePeerSlot 0x021B8628 thumb ov172
 *   COMM_TVT_SYS_GetCameraBusy 0x021BE0F8 thumb ov172
 *   COMM_TVT_SYS_SetCameraBusy 0x021BE0FC thumb ov172
 *   COMM_TVT_SYS_GetMessageActive 0x021BE0AC thumb ov172
 *   CTVT_CAMVIEW_GetOwnSlotBuffer 0x021B7818 thumb ov172
 *   CTVT_CAMVIEW_GetSlotBufferStep 0x021B785C thumb ov172
 *   CTVT_CAMVIEW_GetWindowHeight 0x021B77B8 thumb ov172
 *   CTVT_CAMVIEW_GetWindowWidth 0x021B77E8 thumb ov172
 *   CTVT_COMM_SendStrokeQueue 0x021B8A14 thumb ov172
 *   CTVT_COMM_SendCommand 0x021B8740 thumb ov172
 *   CTVT_COMM_SendPeerStatus 0x021B8AD4 thumb ov172
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Entry;
struct Link;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
extern int GFL_NET_GetNegotiationNum(void);
extern int GFL_NET_LOWER_DATA_IsSendFinished(void);
extern void GFL_NET_LOWER_DATA_SetSendData(int, int, int, int);
extern void MIi_CpuCopy32(const void *, void *, u32);
extern unsigned long SSP_StartJpegEncoder(void *src, unsigned char *dst, int limit, unsigned char *wrk, unsigned long width, unsigned long height, unsigned long quality, unsigned long sampling, unsigned long option);
extern u32 COMM_TVT_SYS_GetCamView(void *);
extern void CTVT_CAMVIEW_StartLayoutChange(void *, char *, int, int);
extern void CTVT_COMM_UpdateMembers(void *, char *);
extern void COMM_TVT_SYS_ClearNameWindows(char *p);
extern u32 COMM_TVT_SYS_GetHalfRes(void *);
extern void CTVT_COMM_UpdatePeerSlot(void *a, int b, int *t, int c);
extern u32 COMM_TVT_SYS_GetCameraBusy(void *);
extern void COMM_TVT_SYS_SetCameraBusy(void *, u32);
extern u32 COMM_TVT_SYS_GetMessageActive(void *);
extern u32 CTVT_CAMVIEW_GetOwnSlotBuffer(void *p, void *q);
extern u32 CTVT_CAMVIEW_GetSlotBufferStep(void *, u32);
extern u32 CTVT_CAMVIEW_GetWindowHeight(void *, u32);
extern u32 CTVT_CAMVIEW_GetWindowWidth(void *, u32);
extern u32 CTVT_COMM_SendStrokeQueue(int unused, char *q);
extern u32 CTVT_COMM_SendCommand(int a, int b, u8 c, u32 d);
extern int CTVT_COMM_SendPeerStatus(int unused, char *base);
typedef struct { u8 x[0x21]; } S21;
#define W(o) (*(int *)(b + (o)))
#define B(o) (*(u8 *)(b + (o)))
void CTVT_COMM_Update(void *a, char *b)
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
            CTVT_COMM_UpdateMembers(a, b);
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
    for (i = 0; i < 4; i++) CTVT_COMM_UpdatePeerSlot(a, (int)b, (int *)(b + 0x64 + i * 0x40), i);
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
            if (W(0x3c0) == 1) CTVT_COMM_SendStrokeQueue((int)a, b);
        }
        if (W(0x3c4) == 1) {
            if (CTVT_COMM_SendCommand((int)a, (int)b, 4, 0) == 1) W(0x3c4) = 0;
        }
        if (W(0x3cc) == 1) {
            if (CTVT_COMM_SendCommand((int)a, (int)b, 5, 0) == 1) W(0x3cc) = 0;
        }
        if (W(0x3b4) == 1) {
            if (CTVT_COMM_SendPeerStatus((int)a, b) == 1) W(0x3b4) = 0;
        }
    }
    if (busy == 0) {
        if (W(0x3b8) == 1) {
            if (CTVT_COMM_SendCommand((int)a, (int)b, 2, W(0x3bc)) == 1) W(0x3b8) = 0;
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
            if (CTVT_COMM_SendCommand((int)a, (int)b, 1, B(0x3d8)) == 1) W(0x3d4) = 0;
        }
    }
}
