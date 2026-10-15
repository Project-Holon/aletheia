/*
 * function: CTVT_COMM_UpdatePeerSlot
 * address: 0x021B8628
 * packet: pkt_ov172_021B8628
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   COMM_TVT_SYS_GetCamView 0x021BDFDC thumb ov172
 *   COMM_TVT_SYS_IsLaunchModeCall 0x021BE0D8 thumb ov172
 *   COMM_TVT_SYS_SavePeerRecord 0x021BE2F0 thumb ov172
 *   CTVT_COMM_SendCommand 0x021B8740 thumb ov172
 *   GFL_NET_LOWER_DATA_IsPostComplete 0x0203EA70 arm
 *   CTVT_CAMVIEW_ClearWindowDirty 0x021B7724 thumb ov172
 *   CTVT_CAMVIEW_GetSlotBuffer 0x021B7830 thumb ov172
 *   CTVT_CAMVIEW_GetWindowHeight 0x021B77B8 thumb ov172
 *   CTVT_CAMVIEW_GetWindowWidth 0x021B77E8 thumb ov172
 *   GFL_NET_LOWER_DATA_GetPostBuffer 0x0203E96C arm
 *   GFL_NET_LOWER_DATA_GetPostRecvSize 0x0203E9DC arm
 *   SSP_StartJpegDecoder 0x021BFFC4 arm ov172
 *   CTVT_CAMVIEW_MarkWindowDirty 0x021B7714 thumb ov172
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 COMM_TVT_SYS_GetCamView(void *p);
extern int COMM_TVT_SYS_IsLaunchModeCall(void *p);
extern void COMM_TVT_SYS_SavePeerRecord(u32 *p, void *q);
extern u32 CTVT_COMM_SendCommand(int a, int b, u8 c, u32 d);
extern int GFL_NET_LOWER_DATA_IsPostComplete(unsigned int idx);
extern void CTVT_CAMVIEW_ClearWindowDirty(void *a, char *b, int c);
extern int CTVT_CAMVIEW_GetSlotBuffer(void *a0, char *a1, int a2);
extern u32 CTVT_CAMVIEW_GetWindowHeight(void *p, char *q);
extern u32 CTVT_CAMVIEW_GetWindowWidth(void *p, char *q);
extern int GFL_NET_LOWER_DATA_GetPostBuffer(unsigned int idx);
extern int GFL_NET_LOWER_DATA_GetPostRecvSize(unsigned int idx);
extern int SSP_StartJpegDecoder(unsigned char *data, unsigned long size, void *dst,
                         short *width, short *height, unsigned long option);
extern void CTVT_CAMVIEW_MarkWindowDirty(void *a, char *b, int c);
void CTVT_COMM_UpdatePeerSlot(void *a, int b, int *t, int c)
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
            if (CTVT_COMM_SendCommand((int)a, b, 0, 0) == 1)
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
                dims[1] = CTVT_CAMVIEW_GetWindowHeight(a, r);
                dims[0] = CTVT_CAMVIEW_GetWindowWidth(a, r);
                data = GFL_NET_LOWER_DATA_GetPostBuffer(c);
                SSP_StartJpegDecoder((unsigned char *)data, GFL_NET_LOWER_DATA_GetPostRecvSize(c), (void *)x, &dims[1], &dims[0], 0);
                CTVT_CAMVIEW_MarkWindowDirty(a, r, c);
                t[6] = 1;
            }
            break;
        }
    }
}
