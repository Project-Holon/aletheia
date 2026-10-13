/*
 * function: NWM_LoadDevice
 * address:  0x02702B08
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * Blocker: NWMi_ForceExit (ABS32 at +0xE8) has no witness.  It is a twl bss
 *   object (0x02732DA0..0x02735B40) with no ROM content, so sole-ref/self has
 *   no word to compare, no pool word names it outside this range, and there is
 *   no layout/data_objects.txt row for it.
 *
 * symbols:
 *   NWMi_CheckState  0x027028E4  arm twl
 *   NWMi_GetSystemWork  0x027026DC  arm twl
 *   func_020862B8  0x020862B8  arm twl
 *   NWMi_CheckFirmDataParamIntegrity  0x02703C28  arm twl
 *   NWMi_SetCallbackTable  0x02703A34  arm twl
 *   NWMi_RegisterSleepCallback  0x02702A40  arm twl
 *   PMi_InsertPostExitCallbackEx  0x0273156C  arm twl
 *   NWMi_SendCommand  0x02703A74  arm twl
 *   NWMi_ForceExit  0x02702D7C  arm twl
 *   DAT_027341a8   0x027341a8  data twl
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u32 NWMi_CheckState(u32, ...);
extern u32 NWMi_GetSystemWork(void);
extern void func_020862B8(u32, u32);
extern u32 NWMi_CheckFirmDataParamIntegrity(void);
extern void NWMi_SetCallbackTable(u32, u32);
extern void NWMi_RegisterSleepCallback(void);
extern void PMi_InsertPostExitCallbackEx(u32 *, u32);
extern u32 NWMi_SendCommand(u32, u32, u32, u32, u32, u32);
extern void NWMi_ForceExit(void);
extern u32 DAT_027341a8[];

u32 NWM_LoadDevice(u32 a0, u32 a1) {
    u32 base = NWMi_GetSystemWork();
    u32 st = NWMi_CheckState(1, 1);
    u32 busy;
    u32 ret;
    u32 b2;
    if (st != 0 && st != 2) {
        return st;
    }
    b2 = NWMi_GetSystemWork();
    if (b2 != 0) {
        busy = 1;
        func_020862B8(*(u32 *)(b2 + 0x2278) + 3, busy);
        if (*(u8 *)(*(u32 *)(b2 + 0x2278) + 3) != 1) {
            busy = 0;
        }
    } else {
        busy = 0;
    }
    if (busy == 1) {
        return 3;
    }
    NWMi_CheckFirmDataParamIntegrity();
    NWMi_SetCallbackTable(3, a0);
    NWMi_RegisterSleepCallback();
    DAT_027341a8[0] = (u32)NWMi_ForceExit;
    DAT_027341a8[1] = 0;
    PMi_InsertPostExitCallbackEx(DAT_027341a8, 0xFFFF);
    ret = NWMi_SendCommand(3, 4, *(u32 *)(base + 0x2274), *(u32 *)(base + 0x2278), *(u32 *)(base + 0x227C), 0);
    if (ret == 0 || ret == 2) {
        ret = 2;
    }
    return ret;
}
