/*
 * file:     card_utility.c
 * unit:     yes
 * function: CARDi_GetDmaInterface, func_02076344, CARDi_DCInvalidateSmart
 * address:  0x020762F4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   OS_Terminate  0x02088234  arm
 *   CARDiDmaUsingFormer  0x020A19BC  data
 *   CARDiDmaUsingNew  0x0272E9E0  data
 *   func_02086320   0x02086320  arm
 *   func_0208632C   0x0208632C  arm
 *   DC_FlushAll  0x02086284  arm
 *   DC_StoreRange  0x020862D4  arm
 *   DC_InvalidateRange  0x020862B8  arm
 *   DC_WaitWriteBufferEmpty  0x02086314  arm
 */
typedef unsigned long u32;

typedef int BOOL;

typedef struct CARDDmaInterface CARDDmaInterface;

typedef unsigned char u8;

extern BOOL OS_IsRunOnTwl(void);
extern void OS_Terminate(void);
extern void func_02086320(void);
extern void func_0208632C(void *p, unsigned int size);
extern void DC_FlushAll(void);
extern void DC_StoreRange(void *startAddr, u32 nBytes);
extern void DC_InvalidateRange(void *startAddr, u32 nBytes);
extern void DC_WaitWriteBufferEmpty(void);
CARDDmaInterface *CARDi_GetDmaInterface(u32 channel);
void CARDi_ICInvalidateSmart(void *p, unsigned int a, unsigned int b);
void CARDi_DCInvalidateSmart(void *buffer, u32 length, u32 threshold);
extern CARDDmaInterface CARDiDmaUsingFormer;
extern CARDDmaInterface CARDiDmaUsingNew;


/*
 * sdk:      CARDi_GetDmaInterface (libcard.TWL.HYB.a card_utility.o)
 */
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


void CARDi_ICInvalidateSmart(void *p, unsigned int a, unsigned int b)
{
    if (a >= b)
        func_02086320();
    else
        func_0208632C(p, a);
}


/*
 * sdk:      CARDi_DCInvalidateSmart (libcard.TWL.HYB.a card_utility.o)
 */
void CARDi_DCInvalidateSmart(void *buffer, u32 length, u32 threshold)
{
    if (length >= threshold)
    {
        DC_FlushAll();
    }
    else
    {
        u32 mod = (u32)buffer & 31;

        if (mod)
        {
            buffer = (u8 *)buffer - mod;
            DC_StoreRange(buffer, 32);
            DC_StoreRange((u8 *)buffer + length, 32);
            length += 32;
        }
        DC_InvalidateRange(buffer, length);
        DC_WaitWriteBufferEmpty();
    }
}
