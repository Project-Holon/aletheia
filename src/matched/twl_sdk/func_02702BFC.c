/*
 * function: NWM_UnloadDevice
 * address:  0x02702BFC
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NWMi_CheckState  0x027028E4  arm twl
 *   NWMi_GetSystemWork  0x027026DC  arm twl
 *   func_020862B8  0x020862B8  arm twl
 *   NWMi_SetCallbackTable  0x02703A34  arm twl
 *   NWMi_SendCommand  0x02703A74  arm twl
 *   NWM_GetState  0x027028B0  arm
 *   NWMi_ForceUnloadDevice  0x02702CA0  arm
 *   NWMi_ForceExit  0x02702D7C  arm
 *   PM_GetExitFactor  0x0273153C  arm
 *   NWMi_ForceUnloadDeviceCallback  0x02702D68  arm
 */

typedef unsigned int u32;
typedef unsigned char u8;

extern u32 NWMi_CheckState(u32, ...);
extern u32 NWMi_GetSystemWork(void);
extern void func_020862B8(u32, u32);
extern void NWMi_SetCallbackTable(u32, u32);
extern u32 NWMi_SendCommand(u32, u32, u32);
extern u32 PM_GetExitFactor(void);
extern void func_02087A04(u32);
extern void func_02088688(void);
extern u32 NWM_GetState(void);
void NWMi_ForceUnloadDeviceCallback(void);
extern u8 d_027341C8;
u32 NWMi_ForceUnloadDevice(u32 a0);
void NWMi_ForceExit(void);

u32 NWM_UnloadDevice(u32 a0) {
    u32 r = NWMi_CheckState(1, 2);
    u32 base;
    u32 busy;
    if (r != 0 && r != 2) {
        return r;
    }
    base = NWMi_GetSystemWork();
    if (base != 0) {
        u32 ptr = *(u32 *)(base + 0x2278);
        busy = 1;
        func_020862B8(ptr + 4, 1);
        if (*(u8 *)(*(u32 *)(base + 0x2278) + 4) != 1) {
            busy = 0;
        }
    } else {
        busy = 0;
    }
    if (busy == 1) {
        return 3;
    }
    NWMi_SetCallbackTable(4, a0);
    NWMi_GetSystemWork();
    r = NWMi_SendCommand(4, 1, 0);
    if (r == 0 || r == 2) {
        r = 2;
    }
    return r;
}
