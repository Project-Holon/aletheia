/*
 * function: CARDi_GetDmaInterface
 * address:  0x020762F4
 * packet:   pkt_020762F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CARDi_GetDmaInterface (libcard.TWL.HYB.a card_utility.o)
 *
 * symbols:
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   OS_Terminate  0x02088234  arm
 *   CARDiDmaUsingFormer  0x020A19BC  data
 *   CARDiDmaUsingNew  0x0272E9E0  data
 */

typedef unsigned long u32;
typedef int BOOL;

typedef struct CARDDmaInterface CARDDmaInterface;

extern CARDDmaInterface CARDiDmaUsingFormer;
extern CARDDmaInterface CARDiDmaUsingNew;
extern BOOL OS_IsRunOnTwl(void);
extern void OS_Terminate(void);

CARDDmaInterface *CARDi_GetDmaInterface(u32 channel)
{
    CARDDmaInterface *retval = 0;
    BOOL isNew = (channel & 0x10) != 0;

    channel &= ~0x10;
    if (channel <= 3)
    {
        if (!isNew)
        {
            retval = &CARDiDmaUsingFormer;
        }
        else if (OS_IsRunOnTwl())
        {
            retval = &CARDiDmaUsingNew;
        }
        else
        {
            OS_Terminate();
        }
    }
    return retval;
}
