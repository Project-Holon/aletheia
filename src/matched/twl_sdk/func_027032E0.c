/*
 * function: NWM_Connect
 * address:  0x027032E0
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
 *   func_020862D4  0x020862D4  arm twl
 *   NWMi_SetCallbackTable  0x02703A34  arm twl
 *   MI_CpuCopy8  0x02082D44  arm twl
 *   NWMi_SendCommandDirect  0x02703B24  arm twl
 *   DAT_027341cc   0x027341cc  data twl
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct TwlWork {
    u8 pad[0x2278];
    u8 *busy;
} TwlWork;

typedef struct TwlMsg {
    u16 len;
    u8 idx;
    u8 pad;
    u32 buf;
} TwlMsg;

extern u32 NWMi_CheckState(u32, u32);
extern TwlWork *NWMi_GetSystemWork(void);
extern void func_020862B8(u8 *, u32);
extern void func_020862D4(const void *, u32);
extern void NWMi_SetCallbackTable(u32, u32);
extern void MI_CpuCopy8(const void *, void *, u32);
extern u32 NWMi_SendCommandDirect(void *, u32);
extern u32 DAT_027341cc[];

u32 NWM_Connect(u32 a0, u32 a1, const u16 *a2) {
    u32 r;
    u32 busy;
    u32 len;
    TwlWork *w;
    TwlMsg msg;

    r = NWMi_CheckState(1, 3);
    if (r != 0 && r != 2) {
        return r;
    }
    w = NWMi_GetSystemWork();
    if (w != 0) {
        func_020862B8(w->busy + 8, 1);
        busy = (w->busy[8] == 1);
    } else {
        busy = 0;
    }
    if (busy == 1) {
        return 3;
    }
    if (a2 == 0) {
        return 5;
    }
    len = a2[0];
    if (len > 0x200) {
        return 5;
    }
    if (a1 >= 3) {
        return 5;
    }
    if (a2[5] == 0) {
        return 5;
    }
    func_020862D4(a2, len * 2);
    NWMi_SetCallbackTable(8, a0);
    msg.buf = (u32)DAT_027341cc;
    msg.len = 8;
    msg.idx = a1;
    MI_CpuCopy8(a2, DAT_027341cc, a2[0]);
    func_020862D4((void *)msg.buf, 0x200);
    func_020862D4(&msg, 8);
    r = NWMi_SendCommandDirect(&msg, 8);
    if (r == 0 || r == 2) {
        r = 2;
    }
    return r;
}
