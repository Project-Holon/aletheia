/*
 * file:     card_spi.c
 * unit:     yes
 * function: CARD_SPI_RunCommand, CARD_SPI_WaitNotBusy, CARD_SPI_SetControl, CARD_SPI_ExchangeByte, CARD_SPI_ReceiveByte, CARD_SPI_CheckCardId
 * address:  0x02180820
 * region:   ov231
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Card SPI access: AUXSPICNT/AUXSPIDATA (0x040001A0/0x040001A2) byte exchange
 * under OS_LockCard, with a ~60 ms timeout loop between control writes. The
 * entry sends command 0x42 and returns the byte read back; CARD_SPI_CheckCardId is
 * the caller-visible check (card response == 0xAA).
 *
 * symbols:
 *   _ull_mul  0x0209C054  arm
 *   _ll_udiv  0x0209C00C  arm
 *   OS_GetTick  0x020870D0  arm
 *   CARD_LockBackup  0x02075E9C  arm
 *   OS_LockCard  0x02084DF4  arm
 *   OS_UnLockCard  0x02084E2C  arm
 *   CARD_UnlockBackup  0x02075EAC  arm
 *   d_02180A20  0x02180A20  data  a4
 *   d_02180A20_b  0x02180A20  data  a4
 *   d_02180A30  0x02180A30  data  a1
 *   d_02180A00  0x02180A00  data  a2
 *
 * note: the byte-exchange cursors live in the arm9 object d_02180A20
 *   (struct CardSpiTransfer: txCursor at +4, rxCursor at +8). d_02180A20_b is
 *   the same object under its second name.
 * note: the *64 step is a named call to the runtime multiply _ull_mul(d, 64);
 *   every C operator form folds or strength-reduces it, so the call form is
 *   kept (user decision 2026-10-05, same practice as _u32_div_f elsewhere).
 */

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned long long u64;

typedef struct {
    int pad00;
    u8 *txCursor;
    u8 *rxCursor;
} CardSpiTransfer;

extern u64 OS_GetTick(void);
extern void CARD_LockBackup(u16 a);
extern int OS_LockCard(unsigned short lockID);
extern void OS_UnLockCard(u16 a);
extern void CARD_UnlockBackup(u16 a);
extern u64 _ull_mul(u64 a, u64 b);
int CARD_SPI_RunCommand(void);
void CARD_SPI_WaitNotBusy(void);
void CARD_SPI_SetControl(u16 v);
u8 CARD_SPI_ExchangeByte(CardSpiTransfer *xfer);
void CARD_SPI_ReceiveByte(CardSpiTransfer *xfer);
int CARD_SPI_CheckCardId(void);
extern CardSpiTransfer d_02180A20;
extern CardSpiTransfer d_02180A20_b;
extern u8 d_02180A30;
extern u16 d_02180A00;


int CARD_SPI_RunCommand(void)
{
    u8 response;
    u64 start;
    u64 d;

    d_02180A20.txCursor = &d_02180A30;
    d_02180A20.rxCursor = &response;
    d_02180A30 = 8;
    CARD_LockBackup(d_02180A00);
    OS_LockCard(d_02180A00);
    start = OS_GetTick();
    do {
        d = OS_GetTick() - start;
    } while (_ull_mul(d, 64) * 1000 / 33514 < 60);
    CARD_SPI_WaitNotBusy();
    CARD_SPI_SetControl(0x42);
    response = CARD_SPI_ExchangeByte(&d_02180A20_b);
    start = OS_GetTick();
    do {
        d = OS_GetTick() - start;
    } while (_ull_mul(d, 64) * 1000 / 33514 < 60);
    CARD_SPI_SetControl(2);
    CARD_SPI_ReceiveByte(&d_02180A20_b);
    CARD_SPI_WaitNotBusy();
    OS_UnLockCard(d_02180A00);
    CARD_UnlockBackup(d_02180A00);
    return response;
}


void CARD_SPI_WaitNotBusy(void)
{
    while (*(volatile u16 *)0x040001A0 & 0x80)
        ;
}


void CARD_SPI_SetControl(u16 v)
{
    *(volatile u16 *)0x040001A0 = v | 0xA000;
}


u8 CARD_SPI_ExchangeByte(CardSpiTransfer *xfer)
{
    u64 start;
    volatile u16 v;

    start = OS_GetTick();
    while ((OS_GetTick() - start) * 64000 / 33514 < 50)
        ;
    *(volatile u16 *)0x040001A2 = *xfer->txCursor;
    xfer->txCursor += 1;
    CARD_SPI_WaitNotBusy();
    v = *(volatile u16 *)0x040001A2;
    return v;
}


/*
 * volatile: SPI data register 040001A2 written at 021809BC and read at 021809C2.
 */
void CARD_SPI_ReceiveByte(CardSpiTransfer *xfer)
{
    u64 start;
    start=OS_GetTick();
    while((OS_GetTick()-start)*64000/33514<50) ;
    *(volatile u16 *)0x040001A2=0;
    CARD_SPI_WaitNotBusy();
    *xfer->rxCursor=*(volatile u16 *)0x040001A2;
    xfer->rxCursor+=1;
}


int CARD_SPI_CheckCardId(void)
{
    CARD_SPI_RunCommand();
    return CARD_SPI_RunCommand() == 0xaa;
}
