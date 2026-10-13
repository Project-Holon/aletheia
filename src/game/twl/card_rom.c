/*
 * file:     card_rom.c
 * unit:     yes
 * function: CARDi_ReadCardWithHash, CARDi_ReadCardWithHashInternalAsync, CARDi_InitRomHash, data_0272EB9C
 * address:  0x0272E9E8
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      libcard.TWL.HYB.a card_rom.o
 *
 * symbols:
 *   data_02732DC4  0x02732DC4  data twl
 *   CARD_ReadRomHashImage  0x0272F740  arm twl
 *   func_020862F0  0x020862F0  arm
 *   func_02077008  0x02077008  arm
 *   CARD_NotifyRomHashReadAsync  0x0272EE2C  arm twl
 *   data_02150200  0x02150200  data
 *   data_02732DA8  0x02732DA8  data twl
 *   func_02086580  0x02086580  arm
 *   func_0208656C  0x0208656C  arm
 *   func_02086774  0x02086774  arm
 *   func_02075E04  0x02075E04  arm
 *   CARD_CalcRomHashBufferLength  0x0272EBDC  arm twl
 *   func_02088234  0x02088234  arm
 *   func_02087B04  0x02087B04  arm
 *   func_02084EB8  0x02084EB8  arm
 *   func_02075E10  0x02075E10  arm
 *   func_02075E80  0x02075E80  arm
 *   func_02084F10  0x02084F10  arm
 *   func_02076E4C  0x02076E4C  arm
 *   CARD_InitRomHashContext  0x0272F0BC  arm twl
 *   data_02732DA0  0x02732DA0  data twl
 *   data_02732DA4  0x02732DA4  data twl
 *   data_02150840  0x02150840  data
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

struct SysState {
    char pad[0x508];
    int state;
};
struct Hook {
    int f0;
    void *callback;
};

struct Request {
    int f0;
    void (*callback)(void *);
    u32 a;
    u32 c;
    u32 b;
    u32 d;
    int f18;
};

extern struct SysState data_02150200;
extern struct Request data_02732DA8;
extern void func_020862F0(u32, u32);
extern void func_02077008(struct Request *);
extern void CARD_NotifyRomHashReadAsync(void *);
extern struct Hook data_02150840;
extern u32 data_02732DA0, data_02732DA4;
extern u8 data_02732DC4[];
extern u32 func_02086580(int arena);
extern u32 func_0208656C(int arena);
extern void func_02086774(int arena, u32 addr);
extern void *func_02075E04(void);
extern u32 CARD_CalcRomHashBufferLength(void *hdr);
extern void func_02088234(void);
extern int func_02087B04(void);
extern int func_02084EB8(void);
extern void func_02075E10(u16 id);
extern void func_02075E80(u16 id);
extern void func_02084F10(u16 id);
extern int func_02076E4C(void *, void *, u32, u32);
extern void CARD_InitRomHashContext(void *, void *, u32, u32, void *, void *, void *);

void CARD_ReadRomHashImage(void *obj, u8 *buf, u32 off, u32 len);

int CARDi_ReadCardWithHash(int a0, int a1, int a2, int a3) {
    CARD_ReadRomHashImage(data_02732DC4, (u8 *)a1, a2, a3);
    return a3;
}

u32 CARDi_ReadCardWithHashInternalAsync(u32 a, u32 b, u32 c, u32 d)
{
    if (data_02150200.state == -1) {
        d = 0;
    } else {
        func_020862F0(b, d);
        data_02732DA8.callback = CARD_NotifyRomHashReadAsync;
        data_02732DA8.a = a;
        data_02732DA8.c = c;
        data_02732DA8.b = b;
        data_02732DA8.d = d;
        data_02732DA8.f0 = 0;
        data_02732DA8.f18 = 0;
        func_02077008(&data_02732DA8);
    }
    return d;
}

void CARDi_InitRomHash(void)
{
    u32 lo = (func_02086580(0) + 0x1f) & ~0x1f;
    u32 hi = func_0208656C(0);
    u32 size;
    u16 lock;

    size = CARD_CalcRomHashBufferLength(func_02075E04());
    if (lo + size > (hi & ~0x1f)) {
        func_02088234();
        return;
    }
    func_02086774(0, lo + size);
    data_02732DA0 = lo;
    data_02732DA4 = size;
    if (func_02087B04() != 1) {
        return;
    }
    if (!(*(u8 *)0x02FFE01C & 1)) {
        return;
    }
    data_02150200.state = -1;
    data_02150840.callback = CARDi_ReadCardWithHash;
    lock = func_02084EB8();
    func_02075E10(lock);
    CARD_InitRomHashContext(data_02732DC4, func_02075E04(), data_02732DA0, data_02732DA4, func_02076E4C, CARDi_ReadCardWithHashInternalAsync, data_02732DC4);
    data_02732DA0 = 0;
    data_02732DA4 = 0;
    func_02075E80(lock);
    func_02084F10(lock);
}

/*
 * 64 bytes of key data inside the code range of this unit
 * (0x0272EB9C..0x0272EBDC), read by CARD_InitRomHashContext as data_0272EB9C. The
 * bytes come from the user's own ROM: tools/gendata.py writes the
 * initializer to build/gen/twl_0272EB9C.inc (gitignored); run it before the
 * build. dcd lays the words out in .text, no prologue or epilogue.
 */
/* hand-written in the original: data words laid out in .text between functions, not compiled code */
asm void data_0272EB9C(void)
{
#include "../../../build/gen/twl_0272EB9C.inc"
}
