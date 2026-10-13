/*
 * function: WcmNwmcbScanEx
 * address:  0x027323A8
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   WCMi_GetSystemWork  0x021657C8  arm  ov009
 *   WCMi_SetPhase  0x02165A4C  arm  ov009
 *   func_021659B4  0x021659B4  arm  ov009
 *   func_021659F8  0x021659F8  arm  ov009
 *   WCMi_EntryApList  0x02165D04  arm  ov009
 *   WCMi_GetNextScanChannel  0x02165918  arm  ov009
 *   func_020862B8  0x020862B8  arm  twl
 *   func_020862D4  0x020862D4  arm  twl
 *   func_02080D24  0x02080D24  arm
 *   _u32_div_f  0x0209C2B0  arm
 *   NWM_StartScanEx  0x02703088  arm  twl
 *   WcmNwmReset  0x02731F14  arm  twl
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct NetWork {
    u8 pad0[0x12d4];
    u32 flags;
    u8 pad1[0x12da - 0x12d8];
    u16 phase;
    u8 pad2[2];
    u8 state;
    u8 pad3[0x43a0 - 0x12df];
    u32 sendBuf;
    u16 sendLen;
    u16 sendMask;
    u8 pad4[0x43e0 - 0x43a8];
    u32 sendCount;
} NetWork;

typedef struct SendPkt {
    u16 pad0;
    u16 kind;
    u32 len;
    u16 pad1;
    u16 count;
    u8 pad2[4];
    u32 ptr[32];
    u16 size[32];
} SendPkt;

static inline unsigned long clz32(unsigned long x)
{
    asm { clz x, x }
    return x;
}

extern NetWork *WCMi_GetSystemWork(void);
extern void WCMi_SetPhase(unsigned char phase);
extern void func_021659B4(u32 a, void *b, u32 c, u32 d);
extern void func_021659F8(u32 a, u32 b, u32 c, void *d, u32 e);
extern void WCMi_EntryApList(u32 a, u32 b);
extern u16 WCMi_GetNextScanChannel(u16 a);
extern void func_020862B8(u32 buf, u32 len);
extern void func_020862D4(u32 buf, u32 len);
extern u32 func_02080D24(u32 x);
extern int NWM_StartScanEx(void *cb, void *buf);
extern void WcmNwmReset(void);
void WcmNwmcbScanEx(SendPkt *p);

void WcmNwmcbScanEx(SendPkt *p)
{
    int status = 13;
    NetWork *w = WCMi_GetSystemWork();
    int i;

    switch (p->kind) {
    case 0:
        if (w->state == 5) {
            WCMi_SetPhase(6);
            func_021659B4(0, 0, 0, 931);
        }
        switch (w->state) {
        case 6:
            w->phase = 7;
            if (p->count != 0) {
                func_020862B8(w->sendBuf, w->sendLen);
                for (i = 0; i < p->count; i++) {
                    WCMi_EntryApList(p->ptr[i], p->size[i]);
                    func_021659F8(7, 0, p->ptr[i], p, 953);
                }
            }
            if ((w->flags & 0xc00000) == 0xc00000) {
                u32 n = func_02080D24(w->flags & 0x3ffe);
                if (n != 0 && w->sendCount % n == 0) {
                    func_021659F8(8, 0, w->sendCount, 0, 967);
                }
            }
            w->sendMask = (1 << WCMi_GetNextScanChannel(32 - clz32(p->len))) >> 1;
            func_020862D4(w->sendBuf, w->sendLen);
            w->sendCount++;
            status = NWM_StartScanEx(WcmNwmcbScanEx, &w->sendBuf);
            break;
        case 7:
            status = 2;
            WCMi_SetPhase(3);
            func_021659B4(0, 0, 0, 983);
            break;
        case 13:
            WcmNwmReset();
            return;
        }
        switch (status) {
        case 2:
            return;
        case 6:
            WCMi_SetPhase(12);
            func_021659B4(1, 0, 0, 1011);
            return;
        case 3:
        default:
            WCMi_SetPhase(11);
            func_021659B4(7, 0, 0, 1020);
            return;
        }
    case 1:
        WcmNwmReset();
        return;
    case 2:
    case 3:
    case 4:
    default:
        WCMi_SetPhase(11);
        func_021659B4(7, 0, 0, 1037);
        return;
    }
}
