/*
 * function: NWM_Open
 * address:  0x02702F38
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NWMi_CheckEnableFlag  0x027026B4  arm twl
 *   NWMi_CheckState  0x027028E4  arm twl
 *   NWMi_GetSystemWork  0x027026DC  arm twl
 *   func_020862B8  0x020862B8  arm twl
 *   NWMi_SetCallbackTable  0x02703A34  arm twl
 *   NWMi_SendCommand  0x02703A74  arm twl
 */

typedef unsigned int u32;

extern u32 NWMi_CheckEnableFlag(void);
extern u32 NWMi_CheckState(u32, u32);
extern u32 NWMi_GetSystemWork(void);
extern void func_020862B8(u32, u32);
extern void NWMi_SetCallbackTable(u32, u32);
extern u32 NWMi_SendCommand(u32, u32);

u32 NWM_Open(u32 a0) {
    u32 r;
    u32 base;
    u32 busy;
    if (NWMi_CheckEnableFlag() == 0) {
        return 7;
    }
    r = NWMi_CheckState(1, 2);
    if (r != 0 && r != 2) {
        return r;
    }
    base = NWMi_GetSystemWork();
    if (base != 0) {
        u32 ptr = *(u32 *)(base + 0x2278);
        busy = 1;
        func_020862B8(ptr + 5, 1);
        if (*(unsigned char *)(*(u32 *)(base + 0x2278) + 5) != 1) {
            busy = 0;
        }
    } else {
        busy = 0;
    }
    if (busy == 1) {
        return 3;
    }
    NWMi_SetCallbackTable(5, a0);
    NWMi_GetSystemWork();
    r = NWMi_SendCommand(5, 0);
    if (r == 0 || r == 2) {
        r = 2;
    }
    return r;
}
