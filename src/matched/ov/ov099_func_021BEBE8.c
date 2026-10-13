/*
 * function: func_021BEBE8
 * address: 0x021BEBE8
 * packet: pkt_ov099_021BEBE8
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: arm9 0x0203C600 and 0x0203CB00 have no outside witness; ov009
 *   0x02156C98 is an unlabelled leaf. No overlay leaf filed while arm9 blocks.
 * blocker: arm9 0x0203C600 ARM verified EXACT, 40 bytes, blocker-arm_0203C600_12.log.
 *   typedef unsigned int u32;
 *   extern u32 *_pNetState;
 *   extern void GFL_NET_STATE_WifiLoginMain(void);
 *   int GFL_NET_STATE_IsWifiLoginState(void) { return _pNetState[2] == (u32)GFL_NET_STATE_WifiLoginMain; }
 *   symbols: _pNetState 0x021469DC data a4; GFL_NET_STATE_WifiLoginMain 0x0203C0F4 arm.
 * blocker: arm9 0x0203CB00 ARM verified MATCH, 52 bytes, blocker-arm_0203CB00_13.log.
 *   typedef unsigned int u32;
 *   extern u32 *_pNetState;
 *   extern void GFL_NET_STATE_FatalError(void);
 *   int GFL_NET_STATE_IsFatalError(void) {
 *       if (_pNetState != 0 && _pNetState[2] == (u32)GFL_NET_STATE_FatalError) return 1;
 *       return 0;
 *   }
 *   symbols: _pNetState 0x021469DC data a4; GFL_NET_STATE_FatalError 0x0203CADC arm.
 *   0x0203CADC remains an unwitnessed ARM address in the verified blocker.
 * lever: default switch arm precedes cases 0 and 1; else state is the callee result.
 * symbols:
 *   DWC_RAP_IsUserDataChanged 0x02156C84 thumb ov009
 *   func_02012DD0 0x02012DD0 thumb
 *   DWC_RAP_ClearUserDataChanged 0x02156C98 thumb ov009
 *   GFL_NET_STATE_IsWifiLoginState 0x0203C600 arm
 *   func_021BE6F0 0x021BE6F0 thumb ov099
 *   func_021BE788 0x021BE788 thumb ov099
 *   func_021BE4F0 0x021BE4F0 thumb ov099
 *   GFL_NET_STATE_IsFatalError 0x0203CB00 arm
 *   GFL_NET_STATE_GetWifiState 0x0203C3EC arm
 *   func_021BE900 0x021BE900 thumb ov099
 */
typedef unsigned char u8;
extern u8 DWC_RAP_IsUserDataChanged(void);
extern int func_02012DD0(u8 *p);
extern void DWC_RAP_ClearUserDataChanged(int v);
extern int GFL_NET_STATE_IsWifiLoginState(void);
extern void func_021BE6F0(char *p, int a, int b);
extern int func_021BE788(char *p);
extern int func_021BE4F0(char *p, int a);
extern int GFL_NET_STATE_IsFatalError(void);
extern int GFL_NET_STATE_GetWifiState(void);
extern void func_021BE900(char *p);
int func_021BEBE8(char *p, int result)
{
    int v;
    if (DWC_RAP_IsUserDataChanged()) {
        v = func_02012DD0(*(u8 **)(p + 0xc4));
        switch (v) {
        default:
            DWC_RAP_ClearUserDataChanged(v);
            break;
        case 0:
        case 1:
            return result;
        }
    }
    if (GFL_NET_STATE_IsWifiLoginState()) {
        if (*(int *)(p + 0x1e8) != 0) {
            *(int *)(p + 0x1cc) = 7;
        } else {
            func_021BE6F0(p, 1, 2);
            func_021BE788(p);
            *(int *)(p + 0x1cc) = func_021BE4F0(p, 0);
        }
    } else if (GFL_NET_STATE_IsFatalError() || GFL_NET_STATE_GetWifiState() == 3) {
        func_021BE900(p);
    }
    return result;
}
