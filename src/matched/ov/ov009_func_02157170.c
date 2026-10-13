/*
 * function: DWC_RAPCOMMON_HandleNetError
 * address:  0x02157170
 * packet:   pkt_ov009_02157170
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * blocker: every concrete byte matches (MATCH*, 270 of 272, the tail is
 * padding); the three THM_CALL sites to GFL_NET_ERR_RaiseFatal stay wildcarded
 * because 0x0200FB4C is an unlabelled arm9 Thumb leaf (it prints as .word
 * data after func_0200FB38), so no class attests it. The leaf verifies
 * EXACT (literal x2) as pkt_0200FB4C / src/matched/arm9/GFL_NET_ERR_RaiseFatal.c
 * with this body, outside this lane's write set:
 *
 *   typedef struct State { u8 pad00[0x2C]; int f2C; u8 pad30[0x29];
 *                          u8 f59; u8 f5A; u8 pad5B[5]; int f60; } State;
 *   extern State gNetErrWork;           symbols: 0x0214617C data a4
 *   void GFL_NET_ERR_RaiseFatal(int x)
 *   {
 *       if (gNetErrWork.f2C != 2) {
 *           gNetErrWork.f60 = x;
 *           gNetErrWork.f5A = 1;
 *           gNetErrWork.f59 = 1;
 *           gNetErrWork.f2C = 2;
 *       }
 *   }
 *
 * Filing that leaf makes this file (and ov135 func_022010BC) EXACT.
 *
 * symbols:
 *   func_0203CD98  0x0203CD98  arm
 *   GFL_NET_STATE_GetError  0x0203CA98  arm
 *   func_0200FB24  0x0200FB24  thumb
 *   DWC_RAPCOMMON_ClearNetError  0x02157160  thumb  ov009
 *   GFL_NET_ERR_ShowSimpleScreen  0x0200F83C  thumb
 *   func_0200FBA0  0x0200FBA0  thumb
 *   func_02059F18  0x02059F18  arm
 *   func_0200FB38  0x0200FB38  thumb
 *   GFL_NET_ERR_RaiseFatal  0x0200FB4C  thumb
 *   func_0200F7C0  0x0200F7C0  thumb
 *   func_0200FAAC  0x0200FAAC  thumb
 *   GFL_NET_STATE_WifiDisconnect  0x0203C554  arm
 *   GFL_NET_STATE_SetWifiError  0x0203CA04  arm
 *   GFL_NET_STATE_ClearErrorMode  0x0203C968  arm
 */

typedef struct Status {
    int f0;
    int f4;
    int f8;
    int fC;
} Status;

extern int func_0203CD98(void);
typedef unsigned int   u32;
extern u32 GFL_NET_STATE_GetError(void);
extern u32 func_0200FB24(void);
extern void DWC_RAPCOMMON_ClearNetError(void);
extern void GFL_NET_ERR_ShowSimpleScreen(void);
extern void func_0200FBA0(void);
extern void func_02059F18(void);
extern void func_0200FB38(void);
extern void GFL_NET_ERR_RaiseFatal(unsigned int x);
extern void func_0200F7C0(u32 value);
extern void func_0200FAAC(void);
extern void GFL_NET_STATE_WifiDisconnect(u32 a);
extern void GFL_NET_STATE_SetWifiError(void);
extern void GFL_NET_STATE_ClearErrorMode(void);

int DWC_RAPCOMMON_HandleNetError(int a0, int a1)
{
    Status *st;
    int v;

    if (func_0203CD98() != 0) {
        st = (Status *)GFL_NET_STATE_GetError();
        if (func_0200FB24() != 0) {
            switch (st->f4) {
            case 0:
                break;
            case 1:
            case 2:
                if (a0 == 0) {
                    DWC_RAPCOMMON_ClearNetError();
                    GFL_NET_ERR_ShowSimpleScreen();
                    func_0200FBA0();
                    return 1;
                }
                func_02059F18();
            case 3:
            case 4:
            case 5:
                func_0200FB38();
                GFL_NET_ERR_RaiseFatal(13);
                return 2;
            case 6:
                func_0200FB38();
                return 2;
            case 7:
                func_0200F7C0(15);
                return 3;
            }
        }
        v = st->fC;
        if (v == 0x3F0 || v == 0x3F1) {
            if (a1 != 0) {
                func_0200FAAC();
                DWC_RAPCOMMON_ClearNetError();
                GFL_NET_STATE_WifiDisconnect(1);
                GFL_NET_ERR_ShowSimpleScreen();
                func_0200FBA0();
                return 4;
            }
            GFL_NET_STATE_SetWifiError();
            func_0200FBA0();
            GFL_NET_STATE_ClearErrorMode();
            GFL_NET_STATE_WifiDisconnect(1);
            return 0;
        }
        if (v == 0x3F2 || v == 0x3F3 || v == 0x3F4 || v == 0x3F6) {
            if (a0 == 0) {
                DWC_RAPCOMMON_ClearNetError();
                GFL_NET_ERR_ShowSimpleScreen();
                func_0200FBA0();
                return 1;
            }
            func_0200FB38();
            GFL_NET_ERR_RaiseFatal(13);
            return 2;
        }
        if (v == 0x3EE || v == 0x3F7) {
            func_0200FB38();
            GFL_NET_ERR_RaiseFatal(13);
            return 2;
        }
    }
    return 0;
}
