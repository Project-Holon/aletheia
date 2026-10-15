/*
 * function: CARD_SPI_ExchangeByte
 * address:  0x02180924
 * packet:   pkt_ov231_02180924
 * region:   ov231
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020870D0  0x020870D0  arm
 *   CARD_SPI_WaitNotBusy  0x02180904  thumb  ov231
 *   _ull_mul  0x0209C054  arm
 *   _ll_udiv  0x0209C00C  arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long long u64;
extern u64 func_020870D0(void);
extern void CARD_SPI_WaitNotBusy(void);

u8 CARD_SPI_ExchangeByte(char *p)
{
    u64 start;
    volatile u16 v;

    start = func_020870D0();
    while ((func_020870D0() - start) * 64000 / 33514 < 50)
        ;
    *(volatile u16 *)0x040001A2 = **(u8 **)(p + 4);
    *(u8 **)(p + 4) += 1;
    CARD_SPI_WaitNotBusy();
    v = *(volatile u16 *)0x040001A2;
    return v;
}
