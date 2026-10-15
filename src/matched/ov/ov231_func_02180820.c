/*
 * function: CARD_SPI_RunCommand
 * address:  0x02180820
 * packet:   pkt_ov231_02180820
 * region:   ov231
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 2026-10-05 (user decision): the named _ull_mul call is accepted as real source (55 matched game files call runtime helpers by name).
 * note (2026-10-05, wD9r lane08): EXACT. The *64 step is a named call to the runtime
 *   multiply _ull_mul(d, 64) (the original passes 0x40 and a hoisted 0 to 0x0209C054; every
 *   C operator form strength-reduces *64 to shifts or folds it into 64000). The *1000 and
 *   /33514 steps stay C operators. Same practice as the named _u32_div_f/_s32_div_f calls
 *   in other matched files.
 * note 2026-10-05 (wD9r lane ov231): natural spellings tried, all DIFF in c99 and c (the compiler
 *   folds *64*1000 into 64000, 212 B, or shifts, 228 B; the original keeps 0x40/0 in r7/r4 and calls
 *   0x0209C054 twice): d*64*1000/33514; (d*64)*1000/33514; 64ULL/1000ULL/33514ULL literals;
 *   (d<<6)*1000/33514 (228 B); (u64)(d) cast macro; static inline and static non-inline helper
 *   TUS(t); d*64/33514*1000; u64 local k1=64; signed long long d. No operator form keeps the
 *   multiply by 64. File stays here with the _ull_mul call form.
 * symbols:
 *   _ull_mul  0x0209C054  arm
 *   _ll_udiv  0x0209C00C  arm
 *   func_020870D0  0x020870D0  arm
 *   func_02075E9C  0x02075E9C  arm
 *   OS_LockCard  0x02084DF4  arm
 *   OS_UnLockCard  0x02084E2C  arm
 *   CARD_UnlockBackup  0x02075EAC  arm
 *   CARD_SPI_WaitNotBusy  0x02180904  thumb  ov231
 *   CARD_SPI_SetControl  0x02180914  thumb  ov231
 *   CARD_SPI_ExchangeByte  0x02180924  thumb  ov231
 *   CARD_SPI_ReceiveByte  0x02180984  thumb  ov231
 *   d_02180A20  0x02180A20  data  a4
 *   d_02180A20_b  0x02180A20  data  a4
 *   d_02180A30  0x02180A30  data  a1
 *   d_02180A00  0x02180A00  data  a2
  * note 2026-10-05 (integrator): parked in pending although it verifies EXACT. It closes only by
 * calling the runtime helper _ull_mul by name, where the C operator folds or shifts. Waiting for the
 * user to accept or reject that form.
 */

#include "../include/G_Buf.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef struct {
    int f0;
    u8 *f4;
    u8 *f8;
} Buf;
extern struct Buf d_02180A20;
extern struct Buf d_02180A20_b;
extern u8 d_02180A30;
extern u16 d_02180A00;
extern u64 func_020870D0(void);
extern void func_02075E9C(u16 a);
extern int OS_LockCard(unsigned short lockID);
extern void OS_UnLockCard(u16 a);
extern void CARD_UnlockBackup(u16 a);
extern void CARD_SPI_WaitNotBusy(void);
extern void CARD_SPI_SetControl(u16 v);
extern u8 CARD_SPI_ExchangeByte(char *p);
extern void CARD_SPI_ReceiveByte(u8 *p);


extern u64 _ull_mul(u64 a, u64 b);

int CARD_SPI_RunCommand(void)
{
    u8 result;
    u64 start;
    u64 d;

    d_02180A20.f4 = &d_02180A30;
    d_02180A20.f8 = &result;
    d_02180A30 = 8;
    func_02075E9C(d_02180A00);
    OS_LockCard(d_02180A00);
    start = func_020870D0();
    do {
        d = func_020870D0() - start;
    } while (_ull_mul(d, 64) * 1000 / 33514 < 60);
    CARD_SPI_WaitNotBusy();
    CARD_SPI_SetControl(0x42);
    result = CARD_SPI_ExchangeByte((char *)(&d_02180A20_b));
    start = func_020870D0();
    do {
        d = func_020870D0() - start;
    } while (_ull_mul(d, 64) * 1000 / 33514 < 60);
    CARD_SPI_SetControl(2);
    CARD_SPI_ReceiveByte((u8 *)(&d_02180A20_b));
    CARD_SPI_WaitNotBusy();
    OS_UnLockCard(d_02180A00);
    CARD_UnlockBackup(d_02180A00);
    return result;
}
