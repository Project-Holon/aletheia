/*
 * function: NWM_SetWEPKey
 * address:  0x027034C0
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
 *   func_02082D44  0x02082D44  arm twl
 *   NWMi_SendCommandDirect  0x02703B24  arm twl
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
    u16 w2;
    u16 w4;
    u16 w6;
    u8 data[0x50];
} TwlMsg;

extern u32 NWMi_CheckState(u32, u32);
extern TwlWork *NWMi_GetSystemWork(void);
extern void func_020862B8(u8 *, u32);
extern void func_020862D4(const void *, u32);
extern void NWMi_SetCallbackTable(u32, u32);
extern void func_02082D44(const void *, void *, u32);
extern u32 NWMi_SendCommandDirect(void *, u32);

u32 NWM_SetWEPKey(u32 a0, u32 a1, u32 a2, const u8 *a3, u16 a4) {
    u32 r;
    u32 busy;
    u32 kind;
    TwlWork *w;
    TwlMsg msg;

    r = NWMi_CheckState(1, 3);
    if (r != 0 && r != 2) {
        return r;
    }
    w = NWMi_GetSystemWork();
    if (w != 0) {
        func_020862B8(w->busy + 13, 1);
        busy = (w->busy[13] == 1);
    } else {
        busy = 0;
    }
    if (busy == 1) {
        return 3;
    }
    switch (a1) {
    case 0:
        kind = 0;
        break;
    case 1:
        kind = 5;
        break;
    case 2:
        kind = 13;
        break;
    case 3:
        kind = 16;
        break;
    default:
        return 5;
    }
    func_020862D4(a3, 0x50);
    NWMi_SetCallbackTable(13, a0);
    msg.len = 13;
    msg.w4 = a2;
    msg.w6 = kind;
    msg.w2 = a4;
    func_02082D44(a3, msg.data, 0x50);
    r = NWMi_SendCommandDirect(&msg, 0x58);
    if (r == 0 || r == 2) {
        r = 2;
    }
    return r;
}
