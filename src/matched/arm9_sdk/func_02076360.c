/*
 * function: CARDi_DCInvalidateSmart
 * address:  0x02076360
 * packet:   pkt_02076360
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CARDi_DCInvalidateSmart (libcard.TWL.HYB.a card_utility.o)
 *
 * symbols:
 *   DC_FlushAll  0x02086284  arm
 *   DC_StoreRange  0x020862D4  arm
 *   DC_InvalidateRange  0x020862B8  arm
 *   DC_WaitWriteBufferEmpty  0x02086314  arm
 */

typedef unsigned char u8;
typedef unsigned long u32;

extern void DC_FlushAll(void);
extern void DC_StoreRange(void *startAddr, u32 nBytes);
extern void DC_InvalidateRange(void *startAddr, u32 nBytes);
extern void DC_WaitWriteBufferEmpty(void);

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
