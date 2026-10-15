/*
 * os_system_work_types.h: the arm9 system work block at 0x02FFFC00.
 *
 * One owner for OSSystemWork.  os_entropy.c reads the vblank, MAC, system,
 * clock and entropy counters; pxi_fifo.c reads the PXI handle checker at
 * +0x388.  Both live in this single object, so the two former private copies
 * are folded here.  Raw types keep the layout independent of each file's base
 * typedefs; the field offsets are the ones both files already relied on.
 */
#ifndef OS_SYSTEM_WORK_TYPES_H
#define OS_SYSTEM_WORK_TYPES_H

typedef struct OSSystemWork {
    unsigned char  padBeforeVblankCount[0x3C];
    unsigned int   vblankCount;                     /* +0x03C */
    unsigned char  padBeforeMacAddress[0xF4 - 0x40];
    unsigned char  macAddress[6];                   /* +0x0F4 */
    unsigned char  padBeforeSystemCounter[0x1E8 - 0xFA];
    unsigned int   systemCounterLow;                /* +0x1E8 */
    unsigned int   systemCounterHigh;               /* +0x1EC */
    unsigned char  padBeforePxiHandleChecker[0x388 - 0x1F0];
    unsigned int   pxiHandleChecker[2];             /* +0x388 */
    unsigned int   clockCounterLow;                 /* +0x390 */
    unsigned short clockCounterHigh;                /* +0x394 */
    unsigned short padAfterClockCounter;
    unsigned short inputCounterHigh;                /* +0x398 */
    unsigned char  padBeforeEntropyCounter[0x3AA - 0x39A];
    unsigned short entropyCounterHigh;              /* +0x3AA */
    unsigned short entropyCounterLow;               /* +0x3AC */
} OSSystemWork;

#endif
