/*
 * function: NWM_Close
 * address:  0x02702FE8
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
 */

typedef unsigned int u32;

extern u32 NWMi_CheckState(u32, u32);
extern u32 NWMi_GetSystemWork(void);
extern void func_020862B8(u32, u32);
extern void NWMi_SetCallbackTable(u32, u32);
extern u32 NWMi_SendCommand(u32, u32);

u32 NWM_Close(u32 a0) {
    u32 r = NWMi_CheckState(1, 3);
    u32 base;
    u32 busy;
    if (r != 0 && r != 2) {
        return r;
    }
    base = NWMi_GetSystemWork();
    if (base != 0) {
        u32 ptr = *(u32 *)(base + 0x2278);
        busy = 1;
        func_020862B8(ptr + 6, 1);
        if (*(unsigned char *)(*(u32 *)(base + 0x2278) + 6) != 1) {
            busy = 0;
        }
    } else {
        busy = 0;
    }
    if (busy == 1) {
        return 3;
    }
    NWMi_SetCallbackTable(6, a0);
    NWMi_GetSystemWork();
    r = NWMi_SendCommand(6, 0);
    if (r == 0 || r == 2) {
        r = 2;
    }
    return r;
}
