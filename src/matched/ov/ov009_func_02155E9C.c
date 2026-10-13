/*
 * function: DWC_RAP_OnConnectionClosed
 * address:  0x02155E9C
 * packet:   pkt_ov009_02155E9C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_021A8264  0x021A8264  data  ov009  a4
 *   DWC_RAP_SetState  0x02155374  thumb  ov009
 *   DWC_RAP_CleanupVchat  0x02156400  thumb  ov009
 *   DWC_GetNumConnectionHost  0x0216B804  arm  ov009
 *   GFL_NET_STATE_GetError  0x0203CA98  arm
 *   GFL_NET_STATE_SetError  0x0203C9AC  arm
 *   GFL_NET_HANDLE_RemoveHandle  0x0203A338  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 *g_021A8264;
extern void DWC_RAP_SetState(int v);
extern void DWC_RAP_CleanupVchat(void);
extern int DWC_GetNumConnectionHost(void);
extern u32 GFL_NET_STATE_GetError(void);
extern void GFL_NET_STATE_SetError(int a, u32 b, u32 c, u32 d);
extern void GFL_NET_HANDLE_RemoveHandle(u32);

void DWC_RAP_OnConnectionClosed(int a, int b, int c, u32 d)
{
    if (d < 2) {
        *(u32 *)(g_021A8264 + 0x760) = 0;
        *(u32 *)(g_021A8264 + 0x78c) = 0;
        *(u32 *)(g_021A8264 + 0x778) = 0;
        if (a == 0) {
            if (g_021A8264[0x7a1] == 1 && DWC_GetNumConnectionHost() == 1) {
                if (*(u32 *)(g_021A8264 + 0x754) != 8) {
                    DWC_RAP_SetState(0x12);
                }
                if (*(u32 *)(g_021A8264 + 0x76c) != 0) {
                    DWC_RAP_CleanupVchat();
                }
            }
            if (b == 0) {
                DWC_RAP_SetState(0x12);
            }
        }
        if (g_021A8264[0x7a3] != 0) {
            u32 *q = (u32 *)GFL_NET_STATE_GetError();
            if (q[3] == 0) {
                GFL_NET_STATE_SetError(q[0], q[1], q[2], 0x3f1);
            }
        }
        GFL_NET_HANDLE_RemoveHandle(d);
        {
            void (*cb)(u32, u32) = *(void (**)(u32, u32))(g_021A8264 + 0x284);
            if (cb != 0) {
                cb(d, *(u32 *)(g_021A8264 + 0x288));
            }
        }
    }
}
