/*
 * function: DWC_RAP_Shutdown
 * address: 0x0215677C
 * packet: pkt_ov009_0215677C
 * region: ov009
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   g_021A8264 0x021A8264 data ov009 a4
 *   func_02059F18 0x02059F18 arm
 *   DWC_ShutdownFriendsMatch 0x0216AD50 arm ov009
 *   DWC_CleanupInet 0x0205CC20 arm
 *   DWC_RAP_CleanupVchat 0x02156400 thumb ov009
 *   DWC_RAP_DestroyWork 0x021554A0 thumb ov009
 */
typedef unsigned char u8;
extern u8 *g_021A8264;
extern void func_02059F18(void);
extern void DWC_ShutdownFriendsMatch(void);
extern void DWC_CleanupInet(void);
extern void DWC_RAP_CleanupVchat(void);
extern void DWC_RAP_DestroyWork(void);
void DWC_RAP_Shutdown(void)
{
    if (g_021A8264 != 0) {
        func_02059F18();
        if (g_021A8264[0x7a9] != 0)
            DWC_ShutdownFriendsMatch();
        g_021A8264[0x7a9] = 0;
        DWC_CleanupInet();
        DWC_RAP_CleanupVchat();
        DWC_RAP_DestroyWork();
    }
}
