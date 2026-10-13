/*
 * file:     dsp_process.c
 * unit:     yes
 * function: DSP_StopDSPComponent, DSPi_ShutdownCallback, DSPi_PreSleepCallback, DSPi_MasterInterrupts, DSPi_ReadProcessImage, DSPi_CommitWram, DSPi_MapAndLoadProcessImageCallback, DSP_InitProcessContext, DSP_EnumSections, DSP_SwitchProcessMemory, DSP_MapAndLoadProcessImage, DSP_SetProcessHook, DSP_HookPostStartProcess, DSP_ExecuteProcess, DSP_QuitProcess, DSP_FindProcess, DSP_WriteProcessPipe
 * address:  0x027052B4
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      libdsp.TWL.HYB.a dsp_process.o
 *
 * Hidden functions DSPi_ShutdownCallback and DSPi_PreSleepCallback sit in the pool gaps.
 *
 * symbols:
 *   DAT_027344AC   0x027344AC  data twl
 *   DSPi_ProcList  0x027344AC  data twl
 *   MI_GetWramBankMaster 0x02730388 arm twl
 *   MI_GetWramMapStart 0x02730414 arm twl
 *   MI_GetWramMapStart_B 0x027303C4 arm twl
 *   MI_GetWramMapStart_C 0x027303EC arm twl
 *   func_02088234  0x02088234  arm
 *   DSP_PowerOnCore  0x02704E90  arm
 *   DSP_PowerOffCore  0x02704EE8  arm
 *   DSP_ResetOnCore  0x02704F1C  arm
 *   DSP_ResetOffExCore  0x02704F4C  arm
 *   DSP_SendDataCore  0x0270502C  arm
 *   DSP_RecvDataCore  0x0270505C  arm
 *   DSP_MaskSemaphoreCore  0x027052A4  arm
 *   DSP_InitPipe  0x02706CD4  arm
 *   DSP_LoadPipe  0x02706D44  arm
 *   DSP_WritePipe  0x02706FCC  arm
 *   DSP_HookPipeNotification  0x027070DC  arm
 *   MI_FreeWram  0x02730B04  arm
 *   PMi_InsertPostExitCallbackEx  0x0273156C  arm
 *   OS_IsRunOnTwl  0x02085D3C  arm  arm9
 *   MI_CpuFill8  0x02082BCC  arm  arm9
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int s32;
typedef volatile u16 vu16;
typedef volatile u32 vu32;

/* One DSP process: list link, name, loaded image state, the 19 interrupt
   handlers, 0x150 bytes. */
typedef struct DspProc {
    struct DspProc *next;
    char name[16];
    void *file;
    u16 f18;
    u16 f1a;
    u32 flags;
    u32 busy[2];
    u32 tabA[8];
    u32 tabB[8];
    s32 mask;
    void (*handler[19])(u32);
    u32 arg[19];
    u32 clear[19];
} DspProc;

/* The 0x2C bytes at 0x027344AC: process list and the two exit callbacks. */
typedef struct DspGlobals {
    DspProc *head;
    u32 preInit;
    u32 thrInit;
    void (*thrFn)(void);
    u32 thrArg;
    u32 pad14[2];
    void (*preFn)(void);
    u32 preArg;
} DspGlobals;

typedef struct Shared {
    u8 pad[0x3FF8];
    vu32 flags;
} Shared;
typedef struct Hdr {
    u16 pad0;
    u16 count;
    u32 pad4;
    u32 f8;
    u32 fC;
    u16 base;
} Hdr;
typedef struct Ent {
    u32 name0;
    u32 nameOff;
    u32 f8;
    u32 fC;
    u32 len;
    u32 off;
    u32 pad18[3];
    u32 flags;
} Ent;
/* Pipe control block of the DSP data RAM, 10 bytes. */
typedef struct DspRing {
    u16 base;
    u16 size;
    u16 rd;
    u16 wr;
    u16 id;
} DspRing;

static inline u32 clz32(u32 x)
{
    asm { clz x, x }
    return x;
}

extern DspGlobals DAT_027344AC;
/* The list head again, under its own name: the original code reaches it
   through two symbols (two literal pool entries). */
extern DspProc *DSPi_ProcList;
extern s32 func_0208CD94(const char *a, const char *b);
extern s32 func_0208CC14(char *a, char *b);
extern void func_02082AC0(u32 v, void *dst, u32 n);
extern void MI_CpuFill8(void *p, s32 v, u32 n);
extern void func_0208CADC(void *dst, void *src);
extern s32 func_02087988(void);
extern void func_0208799C(s32);
extern void func_020862F0(void *, u32);
extern s32 OS_IsRunOnTwl(void);
extern int func_0207AD30(void);
extern void func_0207AD04(u32 v);
extern void func_02084774(u32 mask, void (*fn)(void));
extern u32 func_02084968(u32 mask);
extern u32 func_02084998(u32 mask);
extern void PMi_InsertPostExitCallbackEx(void *p, u32 v);
extern void func_0208C848(void *p, u32 v);
extern void func_0208C86C(void *p);
extern void func_02088234(void);
extern void DSP_PowerOnCore(void);
extern void DSP_PowerOffCore(void);
extern void DSP_ResetOnCore(void);
extern void DSP_ResetOffExCore(u32 v);
extern void DSP_MaskSemaphoreCore(u32 v);
extern void DSP_SendDataCore(u32 ch, u32 v);
extern u16 DSP_RecvDataCore(u32 ch);
extern s32 func_02078B44(void *file, u32 a, u32 b);
extern s32 func_02078B70(void *file, void *buf, s32 len);
extern void DSP_InitPipe(void);
extern DspRing *DSP_LoadPipe(DspRing *out, int ch, int dir);
extern void DSP_WritePipe(DspRing *r, void *src, u16 count);
extern void DSP_HookPipeNotification(u32 arg);
extern void *MI_GetWramMapStart_B(void);
extern void *MI_GetWramMapStart_C(void);
extern u32 MI_GetWramMapStart(s32 sel);
extern s32 MI_IsWramSlotUsed(s32 sel, u32 id);
extern s32 MI_GetWramBankMaster(s32 sel, u32 id);
extern s32 MI_FreeWramSlot(s32 sel, u32 id, s32 n, s32 v);
extern s32 MI_AllocWramSlot(s32 sel, u32 id, s32 n, s32 mode);
extern void MI_FreeWram(u32 a, u32 b);

void DSP_StopDSPComponent(void);
void DSPi_ShutdownCallback(void);
void DSPi_PreSleepCallback(void);
void DSPi_MasterInterrupts(void);
u32 DSPi_ReadProcessImage(DspProc *p, u32 a, void *buf, s32 len);
u32 DSPi_CommitWram(DspProc *c, s32 sel, u32 idx, s32 mode);
s32 DSPi_MapAndLoadProcessImageCallback(DspProc *c, Hdr *h, Ent *e);
void DSP_InitProcessContext(DspProc *o, void *src);
u32 DSP_EnumSections(DspProc *c, s32 (*cb)(DspProc *, Hdr *, Ent *));
u32 DSP_SwitchProcessMemory(DspProc *c, s32 sel, u32 start, u32 count, s32 mode);
u32 DSP_MapAndLoadProcessImage(DspProc *c, void *file, u16 a, u16 b);
void DSP_SetProcessHook(DspProc *s, s32 mask, void (*h)(u32), u32 arg);
void DSP_HookPostStartProcess(void);
u32 DSP_ExecuteProcess(DspProc *p, void *a, u16 b, u16 c);
void DSP_QuitProcess(DspProc *p);
DspProc *DSP_FindProcess(const char *name);
void DSP_WriteProcessPipe(u32 a0, int port, void *buf, u32 len);

static inline void *chanPtr(DspProc *c, s32 sel, s32 a)
{
    s32 q = a / 0x4000;
    s32 rem = a - q * 0x4000;
    u32 slot = sel == 1 ? c->tabA[q] : c->tabB[q];
    return (void *)(MI_GetWramMapStart(sel) + (slot << 15) + rem * 2);
}

void DSP_StopDSPComponent(void)
{
    DAT_027344AC.head->mask = 0;
    if (OS_IsRunOnTwl() == 1) {
        DSP_SendDataCore(2, 0x8000);
    }
    if (OS_IsRunOnTwl() == 1) {
        DSP_RecvDataCore(2);
    }
}

/* Hidden function in the pool gap after DSP_StopDSPComponent. */
void DSPi_ShutdownCallback(void)
{
    DspProc *p;
    for (;;) {
        p = DSP_FindProcess(0);
        if (p == 0) {
            return;
        }
        DSP_QuitProcess(p);
    }
}

/* Tail stub: forwards to func_02088234. */
void DSPi_PreSleepCallback(void)
{
    func_02088234();
}

void DSPi_MasterInterrupts(void)
{
    DspProc *s = DAT_027344AC.head;
    u32 pend;
    u32 bit;
    u16 lo, hi;
    Shared *sp;
    if (s != 0) {
        for (;;) {
            lo = *(vu16 *)0x0400431C;
            hi = *(vu16 *)0x0400430C;
            pend = (lo | (((hi >> 10) & 7) << 16));
            pend &= s->mask;
            if (pend == 0) {
                break;
            }
            while (pend != 0) {
                bit = 32 - clz32(~pend & (pend - 1));
                pend &= ~s->clear[bit];
                s->handler[bit](s->arg[bit]);
            }
        }
    }
    sp = (Shared *)0x02FE0000;
    sp->flags |= 0x01000000;
}

u32 DSPi_ReadProcessImage(DspProc *p, u32 a, void *buf, s32 len)
{
    u32 ok = 0;
    if (func_02078B44(p->file, a, 0)) {
        s32 n = func_02078B70(p->file, buf, len);
        if (len == n) {
            ok = 1;
        }
    }
    return ok;
}

u32 DSPi_CommitWram(DspProc *c, s32 sel, u32 idx, s32 mode)
{
    u32 ok;
    u32 id;
    u8 *p;
    if (sel == 1) {
        id = c->tabA[idx];
    } else {
        id = c->tabB[idx];
    }
    ok = 0;
    if (MI_IsWramSlotUsed(sel, id) == 0 || MI_FreeWramSlot(sel, id, 1, MI_GetWramBankMaster(sel, id)) > 0) {
        if (MI_AllocWramSlot(sel, id, 1, mode) != 0) {
            p = (u8 *)(sel == 1 ? 0x04004044 : 0x0400404C);
            if (mode == 0) {
                p[id] = (p[id] & ~0x1c) | (id << 2);
            } else if (mode == 2) {
                p[id] = (p[id] & ~0x1c) | (idx << 2);
            }
            ok = 1;
        }
    }
    return ok;
}

s32 DSPi_MapAndLoadProcessImageCallback(DspProc *c, Hdr *h, Ent *e)
{
    char buf[0x80];
    s32 selv[4];
    u32 sizev[4];
    u32 flagv[4];
    char *name = (char *)e;
    s32 ok = 1;
    s32 n = 0;
    s32 k;
    u32 size;
    s32 f;
    if (*(u32 *)name == 0) {
        u32 pos = h->f8 + h->fC * 0x12;
        if (!DSPi_ReadProcessImage(c, pos + e->nameOff, buf, 0x80)) {
            return n;
        }
        name = buf;
    }
    if (func_0208CD94(name, (char *)0x02732D54) == 0) {
        c->flags |= 1;
    }
    if (e->flags & 8) {
        size = e->f8 * 2;
        f = (e->flags & 0x20) ? 1 : 0;
        if (func_0208CC14(name, (char *)0x02732D64)) {
            selv[n] = 1;
            sizev[n] = size;
            flagv[n] = f;
            n++;
        }
        if (func_0208CC14(name, (char *)0x02732D68)) {
            selv[n] = 1;
            sizev[n] = size + 0x20000;
            flagv[n] = f;
            n++;
        }
    }
    if (e->flags & 0x10) {
        size = e->fC * 2;
        f = (e->flags & 0x40) ? 1 : 0;
        if (func_0208CC14(name, (char *)0x02732D6C)) {
            selv[n] = 2;
            sizev[n] = size;
            flagv[n] = f;
            n++;
        }
        if (func_0208CC14(name, (char *)0x02732D70)) {
            selv[n] = 2;
            sizev[n] = size + 0x20000;
            flagv[n] = f;
            n++;
        }
    }
    for (k = 0; k < n; k++) {
        s32 sel = selv[k];
        s32 pos = sizev[k];
        s32 len = e->len;
        u32 off = e->off;
        while (len > 0) {
            s32 chunk = ((pos + 0x8000) & -0x8000) - pos;
            if (len <= chunk) {
                chunk = len;
            }
            if ((sel == 1 ? c->tabA[pos / 0x8000] : c->tabB[pos / 0x8000]) == (-0x8000 >> 15)) {
                s32 idx = pos / 0x8000;
                u16 *pm = sel == 1 ? &c->f18 : &c->f1a;
                u32 *busy = sel == 1 ? &c->busy[0] : &c->busy[1];
                u32 *tab = sel == 1 ? c->tabA : c->tabB;
                u32 x = *pm;
                s32 bit = 32 - clz32(~x & (x - 1));
                if (bit >= 8) {
                    ok = 0;
                    break;
                }
                tab[idx] = bit;
                *pm &= ~(1 << bit);
                *busy |= 1 << idx;
                if (!DSPi_CommitWram(c, sel, idx, 0)) {
                    ok = 0;
                    break;
                }
                func_02082AC0(0, chanPtr(c, sel, idx << 14), 0x8000);
            }
            if (flagv[k] == 0) {
                if (!DSPi_ReadProcessImage(c, off, chanPtr(c, sel, pos / 2), chunk)) {
                    ok = 0;
                    break;
                }
            }
            off += chunk;
            pos += chunk;
            len -= chunk;
        }
    }
    return ok;
}

void DSP_InitProcessContext(DspProc *o, void *src)
{
    s32 i;
    MI_CpuFill8(o, 0, 0x150);
    o->next = 0;
    o->flags = 0;
    if (src == 0) {
        src = (void *)0x02732D74;
    }
    func_0208CADC(&o->name, src);
    o->file = 0;
    o->busy[0] = 0;
    o->busy[1] = 0;
    for (i = 0; i < 8; i++) {
        o->tabA[i] = -1;
    }
    for (i = 0; i < 8; i++) {
        o->tabB[i] = -1;
    }
    o->mask = 0;
    for (i = 0; i < 19; i++) {
        o->handler[i] = 0;
        o->arg[i] = 0;
        o->clear[i] = 0;
    }
}

u32 DSP_EnumSections(DspProc *c, s32 (*cb)(DspProc *, Hdr *, Ent *))
{
    Hdr h;
    Ent e;
    s32 i = 0;
    if (DSPi_ReadProcessImage(c, 0, &h, 0x14)) {
        u32 base = h.base + 0x14;
        for (; i < h.count; i++) {
            if (!DSPi_ReadProcessImage(c, base + i * 0x28, &e, 0x28)) {
                break;
            }
            if (!(e.flags & 0x80) && e.len != 0 && cb != 0) {
                if (!cb(c, &h, &e)) {
                    break;
                }
            }
        }
        i = i >= h.count;
    }
    return i;
}

u32 DSP_SwitchProcessMemory(DspProc *c, s32 sel, u32 start, u32 count, s32 mode)
{
    u32 end;
    s32 i;
    u32 *tab;
    start <<= 1;
    if (count < 1) {
        count = 1;
    }
    end = start + count * 2 - 1;
    tab = sel == 1 ? &c->busy[0] : &c->busy[1];
    for (i = start >> 15; i <= (s32)(end >> 15); i++) {
        if (*tab & (1 << i)) {
            if (!DSPi_CommitWram(c, sel, i, mode)) {
                return 0;
            }
        }
    }
    return 1;
}

u32 DSP_MapAndLoadProcessImage(DspProc *c, void *file, u16 a, u16 b)
{
    u32 ok;
    c->file = file;
    c->f18 = a;
    c->f1a = b;
    ok = 0;
    if (DSP_EnumSections(c, DSPi_MapAndLoadProcessImageCallback)) {
        func_020862F0(MI_GetWramMapStart_B(), 0x40000);
        func_020862F0(MI_GetWramMapStart_C(), 0x40000);
        if (DSP_SwitchProcessMemory(c, 1, 0, 0x20000, 2)) {
            if (DSP_SwitchProcessMemory(c, 2, 0, 0x20000, 2)) {
                ok = 1;
            }
        }
    }
    return ok;
}

void DSP_SetProcessHook(DspProc *s, s32 mask, void (*h)(u32), u32 arg)
{
    s32 en = func_02087988();
    vu16 *r = (vu16 *)0x04004308;
    s32 i;
    u16 a, b;
    u32 hi, lo;
    for (i = 0; i < 19; i++) {
        if (mask & (1 << i)) {
            s->handler[i] = h;
            s->arg[i] = arg;
            s->clear[i] = mask;
        }
    }
    a = r[0];
    b = r[6];
    hi = ((mask >> 16) & 7) << 9;
    lo = mask & 0xffff;
    if (h != 0) {
        r[0] = a | hi;
        r[6] = b & ~lo;
        s->mask |= mask;
    } else {
        r[0] = a & ~hi;
        r[6] = b | lo;
        s->mask &= ~mask;
    }
    func_0208799C(en);
}

void DSP_HookPostStartProcess(void)
{
}

u32 DSP_ExecuteProcess(DspProc *p, void *a, u16 b, u16 c)
{
    u32 ret = 0;
    u32 irq;
    DspProc **pp;
    u16 i;
    u16 en;
    u16 dis;
    vu16 v;
    if (func_0207AD30() == 0) {
        func_0207AD04(-1);
    }
    DSP_InitPipe();
    func_02084774(0x1000000, DSPi_MasterInterrupts);
    DSP_SetProcessHook(p, 0x48000, DSP_HookPipeNotification, 0);
    func_02084968(0x1000000);
    if (DSP_MapAndLoadProcessImage(p, a, b, c) != 0) {
        irq = func_02087988();
        pp = &DSPi_ProcList;
        while (*pp != 0 && *pp != p) {
            pp = &(*pp)->next;
        }
        *pp = p;
        p->file = 0;
        if (DAT_027344AC.thrInit == 0) {
            DAT_027344AC.thrFn = DSPi_ShutdownCallback;
            DAT_027344AC.thrArg = 0;
            PMi_InsertPostExitCallbackEx(&DAT_027344AC.thrFn, 0x3F2);
            DAT_027344AC.thrInit = 1;
        }
        if (DAT_027344AC.preInit == 0) {
            DAT_027344AC.preFn = DSPi_PreSleepCallback;
            DAT_027344AC.preArg = 0;
            func_0208C848(&DAT_027344AC.preFn, 0x3F2);
            DAT_027344AC.preInit = 1;
        }
        if (OS_IsRunOnTwl() == 1) {
            DSP_PowerOnCore();
        }
        en = (u16)(p->mask >> 16);
        if (OS_IsRunOnTwl() == 1) {
            DSP_ResetOffExCore(en);
        }
        dis = (u16)~p->mask;
        if (OS_IsRunOnTwl() == 1) {
            DSP_MaskSemaphoreCore(dis);
        }
        DSP_HookPostStartProcess();
        if (p->flags & 1) {
            for (i = 0; i < 3; i++) {
                do {
                    v = DSP_RecvDataCore(i);
                } while (v != 1);
            }
        }
        DSPi_MasterInterrupts();
        ret = 1;
        func_0208799C(irq);
    }
    return ret;
}

void DSP_QuitProcess(DspProc *p)
{
    u32 irq;
    DspProc *q;
    DspProc **pp;
    DSP_StopDSPComponent();
    irq = func_02087988();
    if (OS_IsRunOnTwl() == 1) {
        DSP_ResetOnCore();
    }
    if (OS_IsRunOnTwl() == 1) {
        DSP_PowerOffCore();
    }
    func_02084998(0x1000000);
    func_02084774(0x1000000, 0);
    MI_FreeWram(1, 2);
    MI_FreeWram(2, 2);
    q = DAT_027344AC.head;
    pp = &DSPi_ProcList;
    while (q != 0) {
        if (q == p) {
            *pp = q->next;
            break;
        }
        pp = &q->next;
        q = q->next;
    }
    p->next = 0;
    func_0208799C(irq);
    func_0208C86C(&DAT_027344AC.preFn);
    DAT_027344AC.preInit = 0;
}

DspProc *DSP_FindProcess(const char *name)
{
    DspProc *p;
    u32 irq;
    irq = func_02087988();
    p = DAT_027344AC.head;
    if (name != 0) {
        while (p != 0 && func_0208CD94(p->name, name) != 0) {
            p = p->next;
        }
    }
    func_0208799C(irq);
    return p;
}

void DSP_WriteProcessPipe(u32 a0, int port, void *buf, u32 len)
{
    DspRing pipe;
    DSP_LoadPipe(&pipe, port, 1);
    DSP_WritePipe(&pipe, buf, (u16)len);
}
