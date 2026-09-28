/*
 * function: func_02084E54
 * address:  0x02084E54
 * packet:   pkt_02084E54
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OSi_AllocateCardBus (os_spinlock.o)
 */

typedef unsigned long u32;
typedef long s32;
typedef unsigned short u16;
typedef int BOOL;
typedef u32 OSIntrMode;

typedef struct OSLockWord {
    volatile u32 lockFlag;
    volatile u16 ownerID;
    volatile u16 extension;
} OSLockWord;

extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern OSIntrMode OS_DisableInterrupts_IrqAndFiq(void);
extern OSIntrMode OS_RestoreInterrupts_IrqAndFiq(OSIntrMode state);

void func_02084E54(void)
{
    if (((*(volatile u16 *)0x04004010 & 0xC) >> 2) == 2) {
        *(volatile u32 *)0x040001A4 |= 0x20000000;
    }
    *(volatile u16 *)0x04000204 = (u16)(*(volatile u16 *)0x04000204 & ~0x800);
}
