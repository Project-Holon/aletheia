/*
 * function: DWC_RAP_OnFriendServerMatched
 * address:  0x02156A58
 * packet:   pkt_ov009_02156A58
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
 *   DWC_RAP_EnterConnected  0x02155D2C  thumb  ov009
 *   GFL_NET_GetUserArg  0x0203D650  arm
 *   DWC_CloseConnectionHardFromServer  0x0216B7E0  arm  ov009
 *   DWC_GetAIDBitmap  0x0216B908  arm  ov009
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 *g_021A8264;
extern void DWC_RAP_SetState(int v);
extern void DWC_RAP_EnterConnected(int);
extern u32 GFL_NET_GetUserArg(void);
extern void DWC_CloseConnectionHardFromServer(u8);
extern int DWC_GetAIDBitmap(void);

void DWC_RAP_OnFriendServerMatched(int a, int b, int c, int d, int e)
{
    int flag = 0;
    *(u32 *)(g_021A8264 + 0x778) = 0;
    if (a == 0) {
        if (b == 0) {
            if (g_021A8264[0x7a4] != 0 && e == -1) {
                flag = 1;
            }
            if (*(u32 *)(g_021A8264 + 0x2a4) != 0) {
                if (((int (*)(int, u32))*(u32 *)(g_021A8264 + 0x2a4))(e, GFL_NET_GetUserArg()) == 0) {
                    flag = 1;
                }
            }
            if (g_021A8264[0x7a0] != 0 || flag != 0) {
                if (e != -1) {
                    DWC_CloseConnectionHardFromServer(e);
                }
            }
            *(int *)(g_021A8264 + 0x770) = e;
            *(u32 *)(g_021A8264 + 0x798) = DWC_GetAIDBitmap();
            if (*(u32 *)(g_021A8264 + 0x798) == 1) {
                DWC_RAP_SetState(8);
                return;
            }
            DWC_RAP_EnterConnected(e);
            return;
        }
        if (c == 0) {
            *(u16 *)(g_021A8264 + 0x780) = e;
            *(int *)(g_021A8264 + 0x774) = flag - 1;
        }
    }
}
