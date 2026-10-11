/*
 * file:     unit_021AEB20.c
 * unit:     yes
 * function: func_021AEB20, func_021AEB78, func_021AEB7C, func_021AEC74, func_021AECC4, func_021AED08, func_021AED30, func_021AEDEC, func_021AEE14, func_021AEF44, func_021AEF6C, func_021AF124, func_021AF13C, func_021AF18C, func_021AF1A0, func_021AF210, func_021AF238, func_021AF2AC, func_021AF30C, func_021AF340, func_021AF494, func_021AF628, func_021AFABC, func_021AFFE4, func_021B01FC, func_021B043C, func_021B04A8, func_021B0508, func_021B0600, func_021B0614, func_021B074C, func_021B07F8, func_021B0904, func_021B0B48, func_021B0C64, func_021B0CD8
 * address:  0x021AEB20
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0208B24C  0x0208B24C  arm
 *   func_0208B8B0  0x0208B8B0  arm
 *   func_0208BEF0  0x0208BEF0  arm
 *   func_0208BF38  0x0208BF38  arm
 *   func_021B0CD8  0x021B0CD8  arm ov013
 *   func_020726D0  0x020726D0  arm
 *   func_020737C0  0x020737C0  arm
 *   func_02082AC0  0x02082AC0  arm
 *   func_021B0D08  0x021B0D08  arm ov013
 *   d_021B3C80     0x021B3C80  data ov013
 *   func_02082BCC  0x02082BCC  arm
 *   func_0202EB0C  0x0202EB0C  thumb
 *   func_0208B2BC  0x0208B2BC  arm
 *   func_0208B4C8  0x0208B4C8  arm
 *   func_0208B4B8  0x0208B4B8  arm
 *   func_021B0B48  0x021B0B48  arm ov013
 *   func_021B07F8  0x021B07F8  arm ov013
 *   func_021B1F2C  0x021B1F2C  arm ov013
 *   func_021B20B0  0x021B20B0  arm ov013
 *   func_021B1F54  0x021B1F54  arm ov013
 *   func_021B2180  0x021B2180  arm ov013
 *   func_021B0614  0x021B0614  arm ov013
 *   func_021AEDEC  0x021AEDEC  thumb ov013
 *   func_021B074C  0x021B074C  arm ov013
 *   func_02156400  0x02156400  thumb ov009
 *   func_020870D0  0x020870D0  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   func_021B386C  0x021B386C  arm ov013
 *   func_0216B838  0x0216B838  arm ov009
 *   func_021AEC74  0x021AEC74  thumb ov013
 *   func_021AECC4  0x021AECC4  thumb ov013
 *   func_021B38B0  0x021B38B0  arm ov013
 *   func_02156F5C  0x02156F5C  thumb ov009
 *   func_021AEB20  0x021AEB20  thumb ov013
 *   func_02073838  0x02073838  arm
 *   func_02073AD0  0x02073AD0  arm
 *   func_020738C0  0x020738C0  arm
 *   func_021AEB7C  0x021AEB7C  thumb ov013
 *   func_02034714  0x02034714  arm
 *   func_021AED08  0x021AED08  thumb ov013
 *   func_021AED30  0x021AED30  thumb ov013
 *   func_021B370C  0x021B370C  arm ov013
 *   func_021B0C64  0x021B0C64  arm ov013
 *   func_021AF124  0x021AF124  thumb ov013
 *   func_02073A60  0x02073A60  arm
 *   func_0208B480  0x0208B480  arm
 *   func_0208B528  0x0208B528  arm
 *   func_02073AB4  0x02073AB4  arm
 *   func_02073898  0x02073898  arm
 *   func_021B3844  0x021B3844  arm ov013
 *   func_02156FDC  0x02156FDC  thumb ov009
 *   func_021B3064  0x021B3064  arm ov013
 *   func_021B21A4  0x021B21A4  arm ov013
 *   func_021B2254  0x021B2254  arm ov013
 *   d_021B3A0C     0x021B3A0C  data ov013 a1
 *   d_021B3A1C     0x021B3A1C  data ov013 a2
 *   d_021B3A04     0x021B3A04  data ov013 a1
 *   d_021B3A00     0x021B3A00  data ov013 a1
 *   d_021B3C84     0x021B3C84  data ov013 a4
 *   d_021B3C24     0x021B3C24  data ov013 a4
 *   d_021B60D8     0x021B60D8  data ov013 a4
 *   d_021B3AD0     0x021B3AD0  data ov013 a1
 *   d_021B42C0     0x021B42C0  data ov013 a4
 *   d_021B3CB0     0x021B3CB0  data ov013 a4
 *   d_021B3CBC     0x021B3CBC  data ov013 a4
 *   func_02087170  0x02087170  arm
 *   func_021B3250  0x021B3250  arm ov013
 *   func_021B16E4  0x021B16E4  arm ov013
 *   func_021B19BC  0x021B19BC  arm ov013
 *   func_021B12FC  0x021B12FC  arm ov013
 *   func_021B3364  0x021B3364  arm ov013
 *   func_021B3018  0x021B3018  arm ov013
 *   func_021B1A48  0x021B1A48  arm ov013
 *   func_021B1720  0x021B1720  arm ov013
 *   func_021B133C  0x021B133C  arm ov013
 *   func_02082B0C  0x02082B0C  arm
 *   _ll_udiv       0x0209C00C  arm
 *   func_021B19AC  0x021B19AC  arm ov013
 *   func_021B190C  0x021B190C  arm ov013
 *   func_021B2FE4  0x021B2FE4  arm ov013
 *   func_021B1A74  0x021B1A74  arm ov013
 *   d_021B3E78     0x021B3E78  data ov013 a4
 *   func_021B0904  0x021B0904  arm ov013
 *   func_021B3624  0x021B3624  arm ov013
 *   func_021B33E0  0x021B33E0  arm ov013
 *   MIi_CpuClearFast 0x02082AC0  arm
 *   g_021B60D8     0x021B60D8  data a4
 *   g_021B3AD0     0x021B3AD0  data a1
 *   g_021B3C84     0x021B3C84  data a4
 */
#include "../../matched/include/G_Work.h"
#include "../../matched/include/G_Ctx42C0.h"
#include "../../matched/include/G_021B3C84.h"
#include "../../matched/include/G_Sess.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;

/* Request node handed around by the mic session code and the TCV slots. */
struct Node {
    u32 f0;
    u8 pad4;
    u8 f5;
    u8 pad6[2];
    u32 f8;
    int fC;
};

struct S;
struct A;
struct Slot;
struct X;

typedef void (*NodeCb)(int unused, int code, struct Node *p);
typedef void (*MicCb)(int mode, u32 n, void **bufs, u32 size, int unused, u32 arg6);

typedef struct WorkerParam {
    void *state;
    int mode;
    int one;
    u8 kind;
    void *buf;
    u32 size;
    NodeCb cb;
    int zero;
} WorkerParam;

extern struct Work *d_021B3C80;

extern void func_0208B24C(void);
extern void func_0208B8B0(void);
extern unsigned int func_0208BEF0(unsigned int status);
extern unsigned int func_0208BF38(unsigned int gain);
extern void func_020726D0(void);
extern void func_020737C0(struct S *p);
extern void func_02082AC0(int v, void *p, u32 n);
extern void func_02082BCC(void *p, int v, u32 n);
extern u32 func_0202EB0C(void);
extern int func_0208B2BC(void *param, void (*cb)(void), void *arg);
extern int func_0208B4C8(void *param, void (*cb)(void), void *arg);
extern u32 func_0208B4B8(void);
extern int func_0208B480(void);
extern int func_0208B528(void);
extern struct Node *func_021B1F2C(unsigned int i);
extern int func_021B20B0(int p, int x);
extern int func_021B1F54(struct Node *p);
extern int func_021B2180(int a, int b);
extern void func_02156400(void);
extern u64 func_020870D0(void);
extern void func_021B386C(void);
extern u8 func_0216B838(void);
extern int func_021B38B0(int a, int b, int c);
extern u32 func_02156F5C(u32 a, u32 b, u32 c);
extern int func_02073838(u8 *o, int n, u8 *src);
extern void func_02073AD0(struct Slot *s, s32 v);
extern int func_020738C0(void *ch, int fmt, void *buf, u32 len, int rate,
                         int x, MicCb cb, void *arg);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_021B370C(WorkerParam *p);
extern void func_02073A60(struct A *p);
extern void func_02073AB4(void *p);
extern void func_02073898(struct X *x);
extern void func_021B3844(void);
extern void func_02156FDC(u32 a, void *p, int b);
extern void func_021B3064(void *);
extern int func_021B21A4(u8 i);
extern int func_021B2254(int a);
extern void func_021B0CD8(int x);
extern void func_021B0D08(int x);
extern int func_021B0B48(void *a, u32 b, int *out);
extern int func_021B07F8(const u8 *src, u32 n);
extern int func_021B0C64(int x);
extern int func_021B0614(struct Node *p);
extern void func_021B074C(struct Node *p);

void func_021AEB20(void);
void func_021AEB78(void);
void func_021AEB7C(int mode, u32 n, void **bufs, u32 size, int unused, u32 arg6);
int func_021AEC74(int i);
int func_021AECC4(int x);
void func_021AED08(int unused, int code, struct Node *p);
void func_021AED30(int unused, int code, struct Node *p);
void func_021AEDEC(struct Node *p);
void func_021AEE14(int input);
int func_021AEF44(int a, int b, int c);
void func_021AEF6C(void *heap, int arg1, int mode);
void func_021AF124(void);
void func_021AF13C(void);
void func_021AF18C(void (*cb)(void));
void func_021AF1A0(void);
int func_021AF210(void);
int func_021AF238(u32 mask, int n);
int func_021AF2AC(int n);
void func_021AF30C(int a);

typedef signed char s8;
typedef short s16;

typedef struct AdpcmState {
    s16 pred;
    u8 index;
} AdpcmState;

typedef struct AdpcmHdr {
    s16 pred;
    u8 index;
    u8 zero;
} AdpcmHdr;

/* Shared TCV state at 0x021B3C84. */
typedef struct {
    u16 f0;
    u8 pad2[2];
    u32 f4;
    u8 pad8[4];
    u32 fC;
    u16 f10;
    u8 f12;
    u8 pad13;
    int f14;
    u32 f18;
    int f1C;
    int f20;
    u32 f24;
} Ctx3C84;

typedef struct {
    u8 pad0[0x10];
    int f10;
} Ctx60D8;


typedef struct Pkt {
    u8 pad0[0x10];
    u8 f10;
    u8 pad11[7];
    u32 f18;
    u8 pad1C[0x45C - 0x1C];
    int f45C;
    u8 pad460[4];
    u64 f464;
    u64 f46C;
    void *f474;
} Pkt;

typedef struct Slot {
    u32 f0;
    u8 pad4[4];
    int f8;
    u8 padC[8];
    int f14;
    u8 pad18[8];
    int f20;
    u8 pad24[4];
    u32 f28;
    u32 f2C;
    u8 pad30[0xC];
    Pkt *f3C;
    u8 pad40[0x18];
    u32 f58;
    u8 pad5C[0x14];
    int f70;
    u8 pad74[0x20];
} Slot;

typedef struct {
    u8 a;
    u8 b;
} Pair;

typedef struct {
    u32 magic;
    u8 f4;
    u8 pad5;
    u16 f6;
    u32 f8;
} PacketHeader;

extern u16 func_02087170(void);
extern void func_021B3250(void);
extern void func_021B16E4(u32 i);
extern void func_021B19BC(char *p, int i, int a2);
extern void func_021B12FC(void);
extern void func_021B3364(void);
extern void func_02082B0C(const void *src, void *dst, u32 n);
extern int func_021B19AC(u32 idx);
extern void *func_021B190C(unsigned int i);
extern void func_021B2FE4(Pkt *p);
extern int func_021B1A74(Slot *s, Pkt *p);
extern void func_021B1A48(char *p);
extern void func_021B1720(u32 i);
extern void func_021B133C(u32 i);
extern void func_021B3018(void);
extern void func_021B3624(s16 *a, s16 *b, s16 *d, u32 len);
extern void func_021B33E0(void *a, u32 b);
extern void func_02082AC0(int x, void *a, u32 b);
extern void MIi_CpuClearFast(int x, void *a, u32 b);

void func_021AF340(const u8 *src, s16 *dst, u32 n, AdpcmState *st);
void func_021AF494(u8 *dst, s16 *src, u32 n, AdpcmState *st);
void func_021AF628(const u8 *src, s16 *dst, u32 n, AdpcmState *st);
void func_021AFABC(u8 *dst, s16 *src, u32 n, AdpcmState *st);
void func_021AFFE4(const u8 *src, s16 *dst, u32 n, AdpcmState *st);
void func_021B01FC(u8 *dst, s16 *src, u32 n, AdpcmState *st);
void func_021B043C(AdpcmState *hdr, void *dst, int n, int mode);
void func_021B04A8(AdpcmHdr *out, void *a, int n, AdpcmState *st, int mode);
int func_021B0508(void);
void func_021B0600(void);
int func_021B0614(struct Node *p);
void func_021B074C(struct Node *p);
int func_021B07F8(const u8 *src, u32 n);
int func_021B0904(void *dst, u32 size, u32 idx, u32 *mask);
int func_021B0B48(void *a, u32 b, int *out);
int func_021B0C64(int x);
void func_021B0CD8(int a);

extern const s8 d_021B3A0C[16];
extern const s16 d_021B3A1C[89];
extern const s8 d_021B3A04[8];
extern const s8 d_021B3A00[4];
extern Ctx3C84 d_021B3C84;
extern int d_021B3C24;
extern Ctx60D8 d_021B60D8;
extern const Pair d_021B3AD0[];
extern struct Ctx42C0 d_021B42C0;
extern struct Node *d_021B3CB0[3];
extern Slot d_021B3CBC[3];
extern u8 d_021B3E78[];
extern struct Sess g_021B60D8;
extern const u8 g_021B3AD0[5][2];
extern struct G_021B3C84 g_021B3C84;

void func_021AEB20(void)
{
    func_0208B24C();
    func_0208B8B0();
    func_0208BEF0(1);
    func_0208BF38(3);
    func_021B0CD8(1);
    func_020726D0();
    func_020737C0((struct S *)(((u8 *)d_021B3C80) + 0x19B8));
    func_02082AC0(0, ((u8 *)d_021B3C80) + 0x1104, 0x880);
    *(u32 *)(((u8 *)d_021B3C80) + 0x1A44) = 0;
    func_021B0D08(1);
}


/*
 * Unlabelled leaf (no lr save, so disasm.py never labels it); its address
 * is taken as a completion callback by func_021AEB7C.
 */
void func_021AEB78(void)
{
}



/*
 * Microphone sampling step: with mode 0 clears the n buffers; otherwise
 * stops the pending auto-sampling (param block at G+0x1A20, busy flag
 * G+0x1A4B), picks the sample window, processes each buffer and, unless
 * G+0x19B0 is set, analyses the window. Callback is the empty leaf
 * func_021AEB78.
 */
void func_021AEB7C(int mode, u32 n, void **bufs, u32 size, int unused, u32 arg6)
{
    u8 *addr;
    u32 i;

    addr = (u8 *)arg6;

    if (mode == 0) {
        for (i = 0; i < n; i++) {
            func_02082BCC(bufs[i], 0, size);
        }
        return;
    }
    if (func_0202EB0C() == 0) {
        if (((u8 *)d_021B3C80)[0x1A4B] != 0) {
            func_0208B2BC(((u8 *)d_021B3C80) + 0x1A20, func_021AEB78, 0);
            ((u8 *)d_021B3C80)[0x1A4B] = 0;
        }
    } else {
        if (((u8 *)d_021B3C80)[0x1A4B] != 0) {
            func_0208B4C8(((u8 *)d_021B3C80) + 0x1A20, func_021AEB78, 0);
            ((u8 *)d_021B3C80)[0x1A4B] = 0;
        }
    }
    if ((u32)(func_0208B4B8() - (u32)addr) < size) {
        addr = addr + size;
    }
    if (((*(volatile u16 *)0x02FFFFA8 & 0x8000) >> 15) != 0
        || *(u16 *)(((u8 *)d_021B3C80) + 0x19B2) != 0) {
        addr = ((u8 *)d_021B3C80) + 0x1104;
    }
    for (i = 0; i < n; i++) {
        func_021B0B48(bufs[i], size, 0);
    }
    if (*(u16 *)(((u8 *)d_021B3C80) + 0x19B0) == 0) {
        func_021B07F8(addr, size);
    }
    ((u8 *)d_021B3C80)[0x1A4A] = 2;
}



/*
 * note: 2026-10-05 the call to func_021B20B0 is written in each arm of the
 *   null test (new allocation, existing node); the compiler cross-jumps the
 *   shared tail and the first arm uses the call result register directly.
 */
int func_021AEC74(int i)
{
    struct Node *p = d_021B3C80->f1A1C;
    int r;

    if (p == 0) {
        p = func_021B1F2C(i);
        if (p == 0) {
            return 0;
        }
        r = func_021B20B0((int)p, 0);
    } else {
        r = func_021B20B0((int)p, 0);
    }
    if (r != 0) {
        func_021B1F54(p);
        d_021B3C80->f1A1C = 0;
        return 0;
    }
    d_021B3C80->f1A1C = p;
    return 1;
}



int func_021AECC4(int x)
{
    struct Node *p = d_021B3C80->f1A1C;
    int r;

    if (p != 0 && p->fC == 4) {
        r = 0;
        if (func_021B2180((int)p, 0) != 0) {
            return r;
        }
        if (func_021B0614(d_021B3C80->f1A1C) != 0) {
            r = 1;
        }
        return r;
    }
    return 0;
}


void func_021AED08(int unused, int code, struct Node *p)
{
    switch(code) {
    case 9: func_021AEDEC(p); break;
    case 7: func_021B0614(p); break;
    case 12: func_021AEDEC(p); break;
    }
}


void func_021AED30(int unused, int code, struct Node *p)
{
    switch (code) {
    case 1:
        if (d_021B3C80->f1A1C != 0) {
            func_021B2180((int)p, 3);
            func_021B1F54(p);
            return;
        }
        d_021B3C80->f1A1C = p;
        return;
    case 8:
        func_021B2180((int)p, 0);
        func_021AEDEC(p);
        return;
    case 9:
        func_021AEDEC(p);
        return;
    case 4:
        func_021B2180((int)p, 4);
        func_021AEDEC(p);
        return;
    case 7:
        if (p->f0 != d_021B3C80->f19A8) {
            func_021AEDEC(p);
            return;
        }
        if (func_021B0614(p) != 0) {
            d_021B3C80->f19AC = 2;
            return;
        }
        break;
    case 2:
        func_021AEDEC(p);
        return;
    case 3:
    case 11:
    case 12:
        func_021AEDEC(p);
        break;
    }
}


void func_021AEDEC(struct Node *p)
{
    func_021B074C(p);
    func_021B1F54(p);
    *(int *)(((u8 *)d_021B3C80) + 0x1A1C) = 0;
    func_02156400();
}



/*
 * Frame step: records the input halfword at G+0x19B0, accumulates the
 * elapsed microseconds past one 60 Hz frame (16666 us) at G+0x1A44 since
 * the tick stamped at G+0x1A3C, runs func_021B386C once per whole frame
 * owed, then advances the state machine at G+0x19AC unless G+0x19A8 is 3.
 */
void func_021AEE14(int input)
{
    u64 tick;

    d_021B3C80->f19B0 = input;
    tick = func_020870D0();
    d_021B3C80->f1A44 +=
        (s32)(((u32)tick - (u32)d_021B3C80->f1A3C) * 64000 / 33514) - 16666;
    if (d_021B3C80->f1A44 < -10000) {
        d_021B3C80->f1A44 = 0;
    }
    d_021B3C80->f1A3C = tick;
    func_021B386C();
    while (d_021B3C80->f1A44 >= 16666) {
        func_021B386C();
        d_021B3C80->f1A44 -= 16666;
    }
    if (d_021B3C80->f19A8 == 3) {
        return;
    }
    switch (d_021B3C80->f19AC) {
    case 0:
        if (func_0216B838() == 0) {
            if (func_021AEC74(1) != 0) {
                d_021B3C80->f19AC = 1;
                d_021B3C80->f1A48 = 60;
            }
        } else if (func_0216B838() == 1) {
            if (func_021AECC4(0) != 0) {
                d_021B3C80->f19AC = 2;
            }
        }
        break;
    case 1:
        d_021B3C80->f1A48 -= 1;
        if (d_021B3C80->f1A48 == 0) {
            d_021B3C80->f19AC = 0;
        }
        break;
    case 2:
        break;
    }
}

/*
 * Narrow first callee argument follows the explicit lsls/lsrs at 021AEF52;
 * the other two inputs stay live from entry for the three-input callee.
 */
int func_021AEF44(int a, int b, int c)
{
    if (d_021B3C80 == 0) return 0;
    if (func_021B38B0((unsigned char)a, b, c) != 0) return 1;
    return 0;
}


void func_021AEF6C(void *heap, int arg1, int mode)
{
    WorkerParam param;
    u8 vals[3] = {0, 0, 0};

    if (d_021B3C80 == 0) {
        d_021B3C80 = (struct Work *)func_02156F5C((u32)heap, sizeof(struct Work), 0x20);
        func_02082BCC(d_021B3C80, 0, sizeof(struct Work));
        d_021B3C80->f880 = (void *)func_02156F5C((u32)heap, mode * 0x23C0 + 0x20, 0x20);
        d_021B3C80->f1984 = 0;
        func_021AEB20();
    }
    d_021B3C80->mic_type = 3;
    d_021B3C80->mic_buffer = d_021B3C80;
    d_021B3C80->mic_size = 0x880;
    if (func_0202EB0C() == 0) {
        d_021B3C80->mic_rate = 0x1040;
    } else {
        d_021B3C80->mic_rate = 0x1001;
    }
    d_021B3C80->mic_loop = 1;
    d_021B3C80->mic_callback = 0;
    d_021B3C80->mic_arg = 0;
    d_021B3C80->f1A4B = 1;
    func_02073838(d_021B3C80->f19B8, 1, vals);
    func_02073AD0((struct Slot *)d_021B3C80->f19B8, 0);
    if (func_020738C0(d_021B3C80->f19B8, 1, d_021B3C80->f884, 0x880,
                      func_0202EB0C() ? 0x40 : 0x41, 2, func_021AEB7C,
                      d_021B3C80) == 0) {
        func_02034714((void *)0x021B3C20, 0, (void *)0x021B3C20);
    }
    d_021B3C80->f19AC = 0;
    d_021B3C80->f1A1C = 0;
    d_021B3C80->f19A8 = param.one = 1;
    param.state = d_021B3C80->pad_1988;
    param.mode = mode;
    param.kind = func_0216B838();
    if (param.kind == -1) {
        func_02034714((void *)0x021B3C20, 0, (void *)0x021B3C20);
    }
    if (d_021B3C80->f19A8 == 3) {
        param.cb = func_021AED08;
    } else {
        param.cb = func_021AED30;
    }
    param.zero = 0;
    param.buf = d_021B3C80->f880;
    param.size = mode * 0x23C0 + 0x20;
    func_021B370C(&param);
    d_021B3C80->f19B0 = 0;
    func_021B0C64(arg1);
    func_021AF124();
    func_021B0D08(1);
}


void func_021AF124(void) { func_02073A60((struct A *)(((u8 *)d_021B3C80) + 0x19B8)); }


void func_021AF13C(void)
{
    if (d_021B3C80->f1A1C == 0 || d_021B3C80->f19AC == 0) {
        func_02156400();
        return;
    }
    if (d_021B3C80->f19AC == 1) {
        if (func_021B20B0((int)d_021B3C80->f1A1C, 2)) {
            func_02156400();
            return;
        }
    }
    if (func_021B20B0((int)d_021B3C80->f1A1C, 1)) {
        func_02156400();
    }
}


void func_021AF18C(void (*cb)(void))
{
    *(void (**)(void))(((u8 *)d_021B3C80) + 0x1984) = cb;
}



void func_021AF1A0(void)
{
    void (*cb)(void);

    if (d_021B3C80 == 0) {
        return;
    }
    cb = d_021B3C80->f1984;
    if (func_0202EB0C() == 0) {
        func_0208B480();
    } else {
        func_0208B528();
    }
    func_02073AB4(d_021B3C80->f19B8);
    func_02073898((struct X *)d_021B3C80->f19B8);
    func_021B3844();
    func_0208BEF0(0);
    func_02156FDC(0, d_021B3C80->f880, 0);
    func_02156FDC(0, d_021B3C80, 0);
    d_021B3C80 = 0;
    if (cb) {
        cb();
    }
}


int func_021AF210(void)
{
    int a[4];
    if (d_021B3C80 != 0) {
        func_021B3064(a);
        if (a[1] > 2) return a[0];
    }
    return 0;
}



int func_021AF238(u32 mask, int n)
{
    int i;

    if (d_021B3C80 == 0 || d_021B3C80->f19A8 != 3) {
        return 0;
    }
    for (i = 0; i < 2; i++) {
        if (i == n) {
            continue;
        }
        if (!(mask & (1 << i))) {
            continue;
        }
        if (d_021B3C80->a[i] == 1) {
            continue;
        }
        if (func_021B21A4(i)) {
            return 0;
        }
        d_021B3C80->a[i] = 1;
    }
    return 1;
}



int func_021AF2AC(int n)
{
    int i;

    if (d_021B3C80 == 0 || d_021B3C80->f19A8 != 3) {
        return 0;
    }
    for (i = 0; i < 2; i++) {
        if (i == n) {
            continue;
        }
        if (d_021B3C80->a[i] != 1) {
            continue;
        }
        if (func_021B2254((u8)i)) {
            return 0;
        }
        d_021B3C80->a[i] = 0;
    }
    return 1;
}

void func_021AF30C(int a)
{
    if (((u8 *)d_021B3C80) != 0) {
        *(u16 *)(((u8 *)d_021B3C80) + 0x19B2) = a;
        if (*(void **)(((u8 *)d_021B3C80) + 0x1A1C) != 0) {
            if (a != 0) func_021B074C(*(void **)(((u8 *)d_021B3C80) + 0x1A1C));
            else func_021B0614(d_021B3C80->f1A1C);
        }
    }
}

#pragma thumb off

#define ADPCM_ENCODE(code, step, p, idx, diff, vp, np, sample) \
    idx = st->index;                                           \
    p = st->pred;                                              \
    step = d_021B3A1C[idx];                                    \
    diff = (sample) - p;                                       \
    if (diff < 0) {                                            \
        code = 8;                                              \
        diff = -diff;                                          \
    } else {                                                   \
        code = 0;                                              \
    }                                                          \
    if (diff >= step) {                                        \
        code |= 4;                                             \
        diff -= step;                                          \
    }                                                          \
    if (diff >= (step >> 1)) {                                 \
        code |= 2;                                             \
        diff -= step >> 1;                                     \
    }                                                          \
    if (diff >= (step >> 2)) {                                 \
        code |= 1;                                             \
    }                                                          \
    vp = step >> 3;                                            \
    if (code & 4) {                                            \
        vp += step;                                            \
    }                                                          \
    if (code & 2) {                                            \
        vp += step >> 1;                                       \
    }                                                          \
    if (code & 1) {                                            \
        vp += step >> 2;                                       \
    }                                                          \
    if (code & 8) {                                            \
        vp = -vp;                                              \
    }                                                          \
    np = p + vp;                                               \
    if (np < -32768) {                                         \
        np = -32768;                                           \
    }                                                          \
    if (np > 32767) {                                          \
        np = 32767;                                            \
    }                                                          \
    idx += d_021B3A0C[code];                                   \
    if (idx < 0) {                                             \
        idx = 0;                                               \
    } else if (idx > 88) {                                     \
        idx = 88;                                              \
    }                                                          \
    st->pred = (s16)np;                                        \
    st->index = idx

static inline s16 AdpcmDecodeNibble(AdpcmState *st, int code)
{
    int pred;
    int idx;
    int step;
    int diff;

    idx = st->index;
    pred = st->pred;
    step = d_021B3A1C[idx];
    diff = step >> 3;
    if (code & 4) {
        diff += step;
    }
    if (code & 2) {
        diff += step >> 1;
    }
    if (code & 1) {
        diff += step >> 2;
    }
    if (code & 8) {
        pred -= diff;
        if (pred < -32768) {
            pred = -32768;
        }
    } else {
        pred += diff;
        if (pred > 32767) {
            pred = 32767;
        }
    }
    idx += d_021B3A0C[code];
    if (idx < 0) {
        idx = 0;
    } else if (idx > 88) {
        idx = 88;
    }
    st->index = idx;
    st->pred = (s16)pred;
    return (s16)pred;
}




/*
 * IMA ADPCM decoder: n source bytes, low nibble first, to 2n s16 samples,
 * with the predictor and step index carried in *st. Index table (s8[16])
 * at 0x021B3A0C, step table (s16[89]) at 0x021B3A1C.
 */
void func_021AF340(const u8 *src, s16 *dst, u32 n, AdpcmState *st)
{
    u32 i;

    for (i = 0; i < n; i++) {
        *dst++ = AdpcmDecodeNibble(st, *src & 0xF);
        *dst++ = AdpcmDecodeNibble(st, (*src >> 4) & 0xF);
        src++;
    }
}





/*
 * IMA ADPCM encoder: n s16 samples to n/2 bytes, first sample in the low
 * nibble, predictor and step index carried in *st. Index table (s8[16])
 * at 0x021B3A0C, step table (s16[89]) at 0x021B3A1C. Same tables and
 * state struct as the decoders func_021AF340 and func_021AF628.
 *
 * pass 6 2026-10-06 P6L06: closed with the register colouring capture
 * (scratchpad tools6/regalloc_trace.py). The colouring is round 1 (round 0
 * spills the hoisted constants). Simplify sweeps vregs in ascending order,
 * so the image needs vreg(step1) < vreg(half) < vreg(pred1, idx1, code1).
 * With an inline helper the copy of its locals is one block below all outer
 * locals, so half can never fall inside it. The encoder is a macro over
 * per-sample function locals; outer locals are numbered in reverse
 * declaration order, so the sample-1 locals are declared before half and
 * step1/sample1 after it.
 */
void func_021AF494(u8 *dst, s16 *src, u32 n, AdpcmState *st)
{
    u32 i;
    u8 lo;
    u8 hi;
    int np1, vp1, code1, diff1, idx1, pred1;
    u32 half;
    int step1, sample1;
    int np2, vp2, code2, diff2, idx2, pred2;
    int step2, sample2;

    half = n / 2;
    for (i = 0; i < half; i++) {
        sample1 = *src++;
        ADPCM_ENCODE(code1, step1, pred1, idx1, diff1, vp1, np1, sample1);
        lo = code1;
        sample2 = *src++;
        ADPCM_ENCODE(code2, step2, pred2, idx2, diff2, vp2, np2, sample2);
        hi = code2;
        *dst++ = lo | (u8)(hi << 4);
    }
}




static inline s16 Adpcm3DecodeCode(AdpcmState *st, int code)
{
    int pred;
    int idx;
    int step;
    int diff;
    idx = st->index;
    pred = st->pred;
    step = d_021B3A1C[idx];
    diff = step >> 2;
    if (code & 2) diff += step;
    if (code & 1) diff += step >> 1;
    if (code & 4) {
        pred -= diff;
        if (pred < -32768) pred = -32768;
    } else {
        pred += diff;
        if (pred > 32767) pred = 32767;
    }
    idx += d_021B3A04[code];
    if (idx < 0) idx = 0;
    else if (idx > 88) idx = 88;
    st->index = idx;
    st->pred = (s16)pred;
    return (s16)pred;
}




/*
 * Byte locals for all three packed input bytes reproduce the spilled step
 * temporaries; fixed dst indexes and explicit pointer steps reproduce the tail.
 * 3-bit ADPCM decoder, eight samples per three input bytes, high bits first.
 */
void func_021AF628(const u8 *src, s16 *dst, u32 n, AdpcmState *st)
{
    u32 i;
    u8 a;
    u8 b;
    u8 c;
    for (i = 0; i < n / 3; i++) {
    a = src[0];
    b = src[1];
    c = src[2];
    dst[0] = Adpcm3DecodeCode(st, a >> 5);
    dst[1] = Adpcm3DecodeCode(st, (a >> 2) & 7);
    dst[2] = Adpcm3DecodeCode(st, ((a << 1) & 7) | (b >> 7));
    dst[3] = Adpcm3DecodeCode(st, (b >> 4) & 7);
    dst[4] = Adpcm3DecodeCode(st, (b >> 1) & 7);
    dst[5] = Adpcm3DecodeCode(st, ((b << 2) & 7) | (c >> 6));
    dst[6] = Adpcm3DecodeCode(st, (c >> 3) & 7);
    dst[7] = Adpcm3DecodeCode(st, c & 7);
        src += 3;
        dst += 8;
    }
}



static inline u8 Adpcm3EncodeSample(AdpcmState *st, int sample)
{
    int delta;
    int pred;
    int step;
    int idx;
    int diff;
    int code;
    int np;
    idx = st->index;
    pred = st->pred;
    diff = sample - pred;
    if (diff < 0) {
        code = 4;
        diff = -diff;
    } else {
        code = 0;
    }
    step = d_021B3A1C[idx];
    if (diff >= step) {
        code |= 2;
        diff -= step;
    }
    if (diff >= (step >> 1)) {
        code |= 1;
    }
    delta = step >> 2;
    if (code & 2) delta += step;
    if (code & 1) delta += step >> 1;
    if (code & 4) delta = -delta;
    np = pred + delta;
    if (np < -32768) np = -32768;
    if (np > 32767) np = 32767;
    idx += d_021B3A04[code];
    if (idx < 0) idx = 0;
    else if (idx > 88) idx = 88;
    st->pred = (s16)np;
    st->index = idx;
    return code;
}




/*
 * 3-bit ADPCM encoder (twin of the decoder func_021AF628): n/8 groups of eight
 * s16 samples to three bytes each, high bits first. Predictor and step index
 * are carried in *st.
 * pass 6 2026-10-06 P6L07: EXACT (was 352 B off; EXACT in --lang c99 and --lang c). Found with a
 * capture of the mwccarm register allocator (SelectColors at 0x5269d0) and an exact replay model of
 * its simplify/select passes. Levers: (1) the step table read once after the sign if/else (join form);
 * (2) helper locals declared delta, pred, step, idx, diff, code, np (each inline copy numbers its
 * locals in declaration order, and steady and reloaded samples are simplified in different passes);
 * (3) one u8 accumulator reused for all three output bytes (the second and third live ranges become
 * new, late-numbered webs, so they take r6 as in the original).
 */
void func_021AFABC(u8 *dst, s16 *src, u32 n, AdpcmState *st)
{
    u32 i;
    u8 a;
    u8 c2, c5;
    for (i = 0; i < n / 8; i++) {
        a = Adpcm3EncodeSample(st, *src++) << 5;
        a |= Adpcm3EncodeSample(st, *src++) << 2;
        c2 = Adpcm3EncodeSample(st, *src++);
        *dst++ = a | (c2 >> 1);
        a = Adpcm3EncodeSample(st, *src++) << 4;
        a |= Adpcm3EncodeSample(st, *src++) << 1;
        c5 = Adpcm3EncodeSample(st, *src++);
        *dst++ = a | (c2 << 7) | (c5 >> 2);
        a = Adpcm3EncodeSample(st, *src++) << 3;
        a |= Adpcm3EncodeSample(st, *src++);
        *dst++ = a | (c5 << 6);
    }
}




static inline s16 Adpcm2DecodeCode(AdpcmState *st, int code)
{
    int pred;
    int idx;
    int diff;

    idx = st->index;
    pred = st->pred;
    diff = d_021B3A1C[idx];
    if (!(code & 1)) {
        diff = 0;
    }
    if (code & 2) {
        pred -= diff;
        if (pred < -32768) {
            pred = -32768;
        }
    } else {
        pred += diff;
        if (pred > 32767) {
            pred = 32767;
        }
    }
    idx += d_021B3A00[code];
    if (idx < 0) {
        idx = 0;
    } else if (idx > 88) {
        idx = 88;
    }
    st->index = idx;
    st->pred = (s16)pred;
    return (s16)pred;
}




/*
 * 2-bit ADPCM decoder: n source bytes, low pair first, to 4n s16 samples,
 * with the predictor and step index carried in *st (the 4-bit IMA twin is
 * func_021AF340). Index table (s8[4]) at 0x021B3A00, step table (s16[89])
 * at 0x021B3A1C.
 */
void func_021AFFE4(const u8 *src, s16 *dst, u32 n, AdpcmState *st)
{
    u32 i;

    for (i = 0; i < n; i++) {
        *dst++ = Adpcm2DecodeCode(st, *src & 3);
        *dst++ = Adpcm2DecodeCode(st, (*src >> 2) & 3);
        *dst++ = Adpcm2DecodeCode(st, (*src >> 4) & 3);
        *dst++ = Adpcm2DecodeCode(st, (*src >> 6) & 3);
        src++;
    }
}



static inline u8 Adpcm2EncodeSample(AdpcmState *st, int sample)
{
    int pred;
    int idx;
    int diff;
    int code;
    int delta;
    int np;
    idx = st->index;
    pred = st->pred;
    diff = sample - pred;
    if (diff < 0) {
        code = 2;
        diff = -diff;
    } else {
        code = 0;
    }
    if (diff >= d_021B3A1C[idx]) {
        code |= 1;
    }
    delta = d_021B3A1C[idx];
    if (!(code & 1)) delta = 0;
    if (code & 2) delta = -delta;
    np = pred + delta;
    if (np < -32768) np = -32768;
    if (np > 32767) np = 32767;
    idx += d_021B3A00[code];
    if (idx < 0) idx = 0;
    else if (idx > 88) idx = 88;
    st->pred = (s16)np;
    st->index = idx;
    return code;
}



/*
 * 2-bit ADPCM encoder (twin of the decoder func_021AFFE4): n/4 groups of four
 * s16 samples to one byte, low pair first.
 * final push 2026-10-05 G9L9: closed. Four changes from the old draft, all needed.
 * (1) No named step local: the table is read twice, in the compare and again for
 * the delta (`delta = d_021B3A1C[idx]`); with a `step` local the preheader loaded
 * the index table first. (2) The new predictor is its own local `np`, so the add
 * does not write back into `pred`. (3) `src` is not const: with const the idx store
 * sinks below the orr. (4) The samples are read as `*src++`: that moves the src
 * increment into the last sample's slot (add r1,r1,#8 early).
 */
void func_021B01FC(u8 *dst, s16 *src, u32 n, AdpcmState *st)
{
    u32 i;
    u8 a;
    for (i = 0; i < n / 4; i++) {
        a = Adpcm2EncodeSample(st, *src++);
        a |= Adpcm2EncodeSample(st, *src++) << 2;
        a |= Adpcm2EncodeSample(st, *src++) << 4;
        a |= Adpcm2EncodeSample(st, *src++) << 6;
        *dst++ = a;
    }
}




void func_021B043C(AdpcmState *hdr, void *dst, int n, int mode)
{
    AdpcmState st;

    st.pred = hdr->pred;
    st.index = hdr->index;
    switch (mode) {
    case 2:
        func_021AFFE4((u8 *)hdr + 4, dst, n - 4, &st);
        break;
    case 3:
        func_021AF628((u8 *)hdr + 4, dst, n - 4, &st);
        break;
    case 4:
        func_021AF340((u8 *)hdr + 4, dst, n - 4, &st);
        break;
    }
}




void func_021B04A8(AdpcmHdr *out, void *a, int n, AdpcmState *st, int mode)
{
    out->pred = st->pred;
    out->index = st->index;
    out->zero = 0;
    switch (mode) {
    case 2:
        func_021B01FC((u8 *)out + 4, a, n, st);
        break;
    case 3:
        func_021AFABC((u8 *)out + 4, a, n, st);
        break;
    case 4:
        func_021AF494((u8 *)out + 4, a, n, st);
        break;
    }
}



static inline u32 pairValue(u32 k)
{
    const Pair *p;
    u32 a;
    a = d_021B3AD0[k].a;
    p = &d_021B3AD0[k];
    return a * 0x44 + p->b + 0xC;
}


/*
 * Initialize TCV session state, six counters and three request slots.
 * final push 2026-10-05 G7L7: closed. Two changes from the old draft. The f1C store is written in
 * each arm of the mode if/else (the join no longer splits the 3C84 pointer, f1C goes through the
 * first load). The pair table read takes a = d[k].a first and then p = &d[k] for p->b, which
 * gives the later-born address temp the lower register (r1) and the table base r2, so the table
 * load stays below the f1C store.
 */
int func_021B0508(void)
{
    u32 i;
    u32 k;

    d_021B3C84.f0 = func_02087170();
    d_021B3C24 = 1;
    d_021B3C84.f20 = 0;
    d_021B3C84.f4 = 0;
    k = 0;
    if (d_021B60D8.f10 != 1) {
        k = 4;
        d_021B3C84.f1C = k;
    } else {
        d_021B3C84.f1C = k;
    }
    d_021B3C84.f24 = 0x440;
    d_021B3C84.fC = pairValue(k);
    d_021B42C0.f8C0 = 0;
    d_021B42C0.f8C4 = 0;
    d_021B42C0.f8CC = 0;
    d_021B42C0.f8C8 = 0;
    d_021B42C0.f8D0 = 0;
    d_021B42C0.f8D4 = 0;
    func_021B3250();
    for (i = 0; (i < 3) ? 1 : 0; i++) {
        d_021B3CB0[i] = 0;
        func_021B16E4(i);
        func_021B19BC((char *)&d_021B3CBC[i], i, -1);
    }
    func_021B12FC();
    func_021B3364();
    return 1;
}


void func_021B0600(void) { ((int *)&d_021B3C84)[8] = 0; }


#pragma opt_lifetimes off
int func_021B0614(struct Node *p)
{
    u32 i;

    if (p == 0) {
        return 0;
    }
    if (d_021B3C84.f20 == 3) {
        return 0;
    }
    if (p->fC != 2 && p->fC != 3) {
        return 0;
    }
    for (i = 0; (i < 3) ? 1 : 0; i++) {
        if (d_021B3CB0[i] == p) {
            return 1;
        }
    }
    for (i = 0; (i < 3) ? 1 : 0; i++) {
        if (d_021B3CB0[i] == 0) {
            d_021B3CB0[i] = p;
            break;
        }
    }
    d_021B3C84.f20++;
    d_021B3C84.f4 |= p->f8;
    func_021B19BC((char *)&d_021B3CBC[i], i, p->f5);
    func_021B16E4(i);
    if (p->fC != 2) {
        return 1;
    }
    if (d_021B3C84.f20 == 1) {
        func_021B3018();
        d_021B3C84.f0 = func_02087170();
        d_021B3C84.f10 = 0;
        d_021B3C84.f12 = 0;
        d_021B3C84.f14 = 1;
        d_021B42C0.f8C0 = 0;
        d_021B42C0.f8C4 = 0;
        d_021B42C0.f8CC = 0;
        d_021B42C0.f8C8 = 0;
        d_021B42C0.f8D0 = 0;
        d_021B42C0.f8D4 = 0;
    }
    return 1;
}
#pragma opt_lifetimes reset


#pragma opt_propagation off
void func_021B074C(struct Node *p)
{
    u32 i;
    int n;
    struct Node *z;
    i = 0;
    do {
        if(d_021B3CB0[i]==p) {
            z = 0;
            n = d_021B3C84.f20;
            d_021B3CB0[i]=z;
            d_021B3C84.f20 = n - 1;
            func_021B1A48((char *)&d_021B3CBC[i]);
            func_021B1720(i);
            func_021B133C(i);
            d_021B3C84.f4 &= ~p->f8;
            break;
        }
        i++;
    } while(i<3);
    if(d_021B3C84.f20==0) {
        d_021B3C84.f14=1;
        func_021B3018();
        d_021B3C84.f4=0;
    }
}
#pragma opt_propagation reset


#pragma opt_propagation off

/*
 * pass 3 2026-10-06 P3L09: closed. The mode field is read through a const pointer to the shared
 * state (`const Ctx3C84 *ctx = &d_021B3C84; if (ctx->f1C >= 2)`). A const load has no memory
 * dependence on the header magic store, so the scheduler issues moveq before the f1C load
 * (idiom a-load-scheduled-above-an-unrelated-store-reads-through-a-const-pointer). The rest is the
 * G7L4 form: opt_propagation off, `(i < 3) ? 1 : 0` while loop, magic and divisor as named locals.
 */
int func_021B07F8(const u8 *src, u32 n)
{
  PacketHeader *hdr;
  u32 i;
  u8 divisor;
  u32 off;
  u8 found;
  u16 seq;
  u32 magic;
  const Ctx3C84 *ctx;
  found = 0;
  if (n != d_021B3C84.f24)
  {
    return 0;
  }
  if (d_021B3C84.f20 == 0)
  {
    return 0;
  }
  i = 0;
  while ((i < 3) ? (1) : (0))
  {
    if ((0 != d_021B3CB0[i]) && (d_021B3CB0[i]->fC == 2))
    {
      found = 1;
      break;
    }
    i++;
  }
  if (found == 0)
  {
    return 0;
  }
  off = (d_021B42C0.f8C4 & 1) ? 0 : 0x460;
  hdr = (PacketHeader *) ((u8 *) &d_021B42C0 + off);
  magic = 0x5F564354;
  hdr->magic = magic;
  ctx = &d_021B3C84;
  if (ctx->f1C >= 2)
  {
    func_02082B0C(src, ((u8 *) hdr) + 0x10, n);
  }
  else
  {
    func_02082B0C(src, ((u8 *) hdr) + 0xC, n);
  }
  divisor = 0x40;
  hdr->f4 = divisor;
  seq = d_021B3C84.f0;
  d_021B3C84.f0 = d_021B3C84.f0 + 1;
  hdr->f6 = seq;
  hdr->f8 = (u32) (func_020870D0() / (u32)divisor);
  d_021B42C0.f8C4++;
  return 1;
}

#pragma opt_propagation reset


/*
 * Take one queued packet for slot idx (0x94-byte slots at 0x021B3CBC).
 * Compares the packet's u64 time at +0x46C against the tick count: more
 * than 0x34 ahead falls back to the slot's held packet at +0x3C, more
 * than 0x8B4C behind is released and the loop retries; otherwise it
 * counts sequence gaps (+0x14), updates +0x28/+0x2C/+0 from the tick
 * difference to +0x464, copies +0x474 to dst and sets bit (+0x10) in
 * *mask.
 * func_021B1A74 is void in its own file, but this caller loops on the
 * r0 it leaves behind (mov r4, r0 after each call), so it is declared
 * int here.
 */
int func_021B0904(void *dst, u32 size, u32 idx, u32 *mask)
{
    int n;
    Pkt *pkt;
    Slot *slot;
    int first;
    u64 now;
    u32 d;
    u32 diff;

    slot = &d_021B3CBC[idx];
    first = 1;
    n = func_021B19AC(idx);
    while (n != 0) {
        now = func_020870D0();
        pkt = func_021B190C(idx);
        if (pkt != 0) {
            if (pkt->f46C > now + 0x34) {
                if (pkt->f45C == 0 && slot->f3C != 0) {
                    slot->f20++;
                    func_02082B0C(slot->f3C->f474, dst, size);
                    func_021B2FE4(slot->f3C);
                    slot->f3C = 0;
                    if (mask != 0) {
                        *mask |= 1 << pkt->f10;
                    }
                    return 1;
                }
                return 0;
            }
            if (now > pkt->f46C + 0x8B4C) {
                slot->f58 = pkt->f18;
                n = func_021B1A74(slot, pkt);
                func_021B190C(idx);
                first = 0;
                continue;
            }
            if (slot->f58 + 1 != pkt->f18 && slot->f58 != 0 && slot->f58 <= pkt->f18) {
                if (pkt->f45C == 0) {
                    slot->f14++;
                }
            }
            slot->f58 = pkt->f18;
            if (first != 0 && slot->f70 != 0) {
                n = func_021B1A74(slot, pkt);
                func_021B190C(idx);
                slot->f70--;
                continue;
            }
            d = (u32)(now - pkt->f464);
            diff = d - slot->f28;
            slot->f28 = d;
            slot->f2C = slot->f28 + ((diff - slot->f28) >> 4);
            slot->f0 = slot->f2C;
            func_02082B0C(pkt->f474, dst, size);
            func_021B1A74(slot, pkt);
            if (mask != 0) {
                *mask |= 1 << pkt->f10;
            }
            return 1;
        } else {
            slot->f8 = n;
            return 0;
        }
    }
    if (slot->f3C != 0) {
        func_021B2FE4(slot->f3C);
        slot->f3C = 0;
    }
    return 0;
}


/*
 * The two MIi_CpuClearFast calls (found==0 arm, failed-guard arm) are
 * kept apart in the original; under one extern name 1.1p1 cross-jumps the
 * two `bl`s into one (4 bytes short, see docs/notes/pkt_ov013_021B0B48.c.txt).
 * Two extern names for 0x02082AC0 give two independent call sites, the
 * call-site form of
 * docs/idioms/a-duplicated-pool-word-is-a-second-extern-name-for-the-same-address.md.
 * `j = i + 1; if (j == 3) ret = 1; else for (...)` is what gives the
 * original's `cmp sb,#3; moveq r4,#1; beq; bhs`.
 */
int func_021B0B48(void *a, u32 b, int *out)
{
    int ret;
    u32 i;
    u32 j;

    if (out != 0)
        *out = 0;

    ret = 0;
    if (b == d_021B3C84.f24 && d_021B3C84.f20 != 0) {
        for (i = 0; i < 3; i++) {
            if (func_021B0904(a, b, i, (u32 *)out) == 1) {
                ret = 1;
                break;
            }
        }
        if (ret != 0) {
            j = i + 1;
            if (j == 3) {
                ret = 1;
            } else {
                for (; j < 3; j++) {
                    if (func_021B0904(d_021B3E78, b, j, (u32 *)out) == 1)
                        func_021B3624(a, (s16 *)d_021B3E78, a, b);
                }
            }
        } else {
            MIi_CpuClearFast(0, a, b);
        }
    } else {
        ret = 0;
        func_02082AC0(ret, a, b);
    }

    if (d_021B3C84.f18 != 0)
        func_021B33E0(a, b);
    return ret;
}


int func_021B0C64(int x)
{
    if (x >= 5) {
        return 0;
    }
    if (g_021B60D8.f10 != 1 && (unsigned)x <= 1) {
        return 0;
    }
    g_021B3C84.fC = g_021B3AD0[x][0] * 0x44 + g_021B3AD0[x][1] + 0xC;
    g_021B3C84.f1C = x;
    g_021B3C84.f10 = 0;
    g_021B3C84.f12 = 0;
    return 1;
}

void func_021B0CD8(int a)
{
    d_021B3C24 = a;
    func_021B3018();
    if (a == 0) ((int *)&d_021B3C84)[2] = 1;
}
