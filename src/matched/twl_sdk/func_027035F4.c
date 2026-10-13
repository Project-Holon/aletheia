/*
 * function: NWM_SetPowerSaveMode
 * address:  0x027035F4
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

typedef unsigned char u8;

typedef struct TwlWork {
    u8 pad[0x2278];
    u8 *busy;
} TwlWork;

extern u32 NWMi_CheckState(u32, u32, u32);
extern TwlWork *NWMi_GetSystemWork(void);
extern void func_020862B8(u8 *, u32);
extern void NWMi_SetCallbackTable(u32, u32);
extern u32 NWMi_SendCommand(u32, u32, u32);

u32 NWM_SetPowerSaveMode(u32 a0, u32 a1) {
    u32 r;
    u32 busy;
    TwlWork *w;

    r = NWMi_CheckState(2, 3, 4);
    if (r != 0 && r != 2) {
        return r;
    }
    w = NWMi_GetSystemWork();
    if (w != 0) {
        func_020862B8(w->busy + 14, 1);
        busy = (w->busy[14] == 1);
    } else {
        busy = 0;
    }
    if (busy == 1) {
        return 3;
    }
    NWMi_SetCallbackTable(14, a0);
    NWMi_GetSystemWork();
    r = NWMi_SendCommand(14, 1, a1);
    if (r == 0 || r == 2) {
        r = 2;
    }
    return r;
}
