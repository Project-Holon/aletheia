/*
 * file:     nwm_system.c
 * unit:     yes
 * function: NWMi_GetSystemWork, NWMi_ClearFifoRecvFlag, NWMi_ReceiveFifo9, NWM_GetState, NWMi_CheckState, NWM_GetAllowedChannel, NWM_GetDispersionScanPeriod, NWMi_RegisterSleepCallback, NWMi_DeleteSleepCallback, NwmSleepCallback
 * address:  0x027026DC
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      libnwm.TWL.HYB.a nwm_system.o
 *
 * symbols:
 *   NWMi_CheckInitialized  0x02702698  arm
 *   PM_DeletePostExitCallback  0x02731590  arm
 *   MI_CpuFill8  0x02082BCC  arm  arm9
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef char *va_list;

#define va_start(ap, last) ((ap) = (char *)(((u32)&(last)) & ~3) + 4)
#define va_arg(ap, t) (*(t *)(((ap) += 4) - 4))

typedef struct Msg {
    u16 type;
    u16 sub;
    void (*cb)(struct Msg *);
    u32 w08;
    u32 w0c;
    u32 w10;
} Msg;

extern void func_020862B8(u32, u32);
extern void func_020862D4(u32, u32);
extern void PM_DeletePostExitCallback(u32);
extern void MI_CpuFill8(u32, u32, u32);
extern void func_02087C6C(u8 *);
extern void func_0208C848(u32 *, u32);
extern void func_0208C86C(u32 *);
extern void func_02088234(void);
extern u32 data_027341A4[];
extern u32 DAT_027341a8[];
extern u32 data_027341B8[];
extern u32 data_02FFFC3C[];

u32 NWMi_GetSystemWork(void);
void NWMi_ClearFifoRecvFlag(void);
void NWMi_ReceiveFifo9(u32 a0, Msg *msg, u32 a2);
u32 NWM_GetState(void);
u32 NWMi_CheckState(u32 n, ...);
u32 NWM_GetAllowedChannel(void);
u16 NWM_GetDispersionScanPeriod(u32 a0);
void NWMi_RegisterSleepCallback(void);
void NWMi_DeleteSleepCallback(void);
void NwmSleepCallback(void);
extern u32 NWMi_CheckInitialized(void);

u32 NWMi_GetSystemWork(void) {
    return data_027341A4[0];
}

void NWMi_ClearFifoRecvFlag(void) {
    u8 val;
    u8 *r5;
    u32 r4;
    u32 base = data_027341A4[0];
    if (base != 0) {
        r5 = (u8 *)*(u32 *)(base + 0x2274);
        r4 = 1;
        func_020862B8((u32)r5, r4);
        val = r5[0];
        if (val & 1) {
            r5[0] = val & 0xFE;
            func_020862D4((u32)r5, r4);
        }
    }
}

void NWMi_ReceiveFifo9(u32 a0, Msg *msg, u32 a2) {
    u32 base = data_027341A4[0];
    void (*handler)(Msg *);
    u32 type;
    if (base == 0) {
        return;
    }
    if (a2 != 0) {
        return;
    }
    if (msg == 0) {
        return;
    }
    if (msg->type >= 0x14) {
        return;
    }
    func_020862B8(*(u32 *)(base + 0x227C), 0x100);
    func_020862B8(*(u32 *)(base + 0x2278), 0xC0);
    if ((u32)msg != *(u32 *)(base + 0x227C)) {
        func_020862B8((u32)msg, 0x100);
    }
    type = msg->type;
    if ((type == 3 && msg->sub != 0) || (type == 4 && msg->sub == 0) || type == 0x13) {
        NWMi_DeleteSleepCallback();
    }
    if (msg->type == 0xB && msg->sub != 0xC && msg->cb != 0) {
        msg->cb(msg);
    }
    type = msg->type;
    if (type != 0xB) {
        if (type == 4 || type == 0x13 || (type == 3 && msg->sub != 0)) {
            PM_DeletePostExitCallback((u32)DAT_027341a8);
        }
        type = msg->type;
        handler = *(void (**)(Msg *))(base + type * 4 + 0x2284);
        if (type == 7) {
            func_020862B8(msg->w10, msg->w0c);
        }
        if (handler != 0) {
            handler(msg);
        }
    }
    MI_CpuFill8((u32)msg, 0, 0x100);
    func_020862D4((u32)msg, 0x100);
    if (base != 0) {
        NWMi_ClearFifoRecvFlag();
    }
}

u32 NWM_GetState(void) {
    u32 base = NWMi_GetSystemWork();
    u32 r1 = 0;
    if (base != 0) {
        u32 ptr = *(u32 *)(base + 0x2278);
        func_020862B8(ptr, 2);
        r1 = *(u16 *)(ptr + 0x24);
    }
    return r1;
}

/* Returns 0 when the current state is one of the n listed values, 3 when it is not. */
u32 NWMi_CheckState(u32 n, ...) {
    u32 base = NWMi_GetSystemWork();
    u32 st = NWMi_CheckInitialized();
    u32 cur;
    u32 ret;
    va_list ap;
    if (st != 0 && st != 2) {
        return st;
    }
    func_020862B8(*(u32 *)(base + 0x2278) + 0x24, 2);
    cur = *(u16 *)(*(u32 *)(base + 0x2278) + 0x24);
    ret = 3;
    va_start(ap, n);
    while (n != 0) {
        if (va_arg(ap, u32) == cur) ret = 0;
        n--;
    }
    return ret;
}

u32 NWM_GetAllowedChannel(void) {
    u32 base = NWMi_GetSystemWork();
    u32 ptr = *(u32 *)(base + 0x2278);
    return *(u16 *)(ptr + 0x9E);
}

/*
 *   object (0x02732DA0..0x02735B40) with no ROM content, so sole-ref/self has
 *   no word to compare, and no pool word names it outside this range; there is
 *   no layout/data_objects.txt row for it either.
 */
u16 NWM_GetDispersionScanPeriod(u32 a0) {
    u8 mac[6];
    u16 sum;
    int i;
    int v;
    func_02087C6C(mac);
    for (sum = i = 0; i < 6; i++) {
        sum += mac[i];
    }
    sum += (u16)data_02FFFC3C[0];
    v = sum * 13;
    if (a0 == 1) {
        return v % 10 + 0x1E;
    }
    return v % 10 + 0x69;
}

void NWMi_RegisterSleepCallback(void) {
    data_027341A4[5] = (u32)NwmSleepCallback;
    data_027341A4[6] = 0;
    func_0208C848(data_027341B8, 0xFFFF);
}

void NWMi_DeleteSleepCallback(void)
{
    func_0208C86C(data_027341B8);
}

/* Tail stub: forwards to func_02088234. */
void NwmSleepCallback(void)
{
    func_02088234();
}
