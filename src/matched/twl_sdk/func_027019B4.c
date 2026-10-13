/*
 * function: CameraSendPxiCommand
 * address:  0x027019B4
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_02732FC8  0x02732FC8  data twl a2
 *   OS_DisableInterrupts  0x02087988  arm twl a2
 *   OS_RestoreInterrupts  0x0208799C  arm twl a2
 *   OS_SpinWaitSysCycles  0x02087A04  arm twl a2
 *   PXI_SendWordByFifo  0x02088610  arm twl a2
 */

typedef unsigned int u32;
typedef signed int s32;
typedef unsigned short u16;
typedef unsigned char u8;
#define reg_04004004 (*(volatile u16 *)0x04004004)
typedef void (*CamPxiCallback)(u32 result, u32 arg);
typedef struct CamPxiCmd {
    u32 busy;
    CamPxiCallback callback;
    u32 f08;
    u32 arg;
    s32 command;
    s32 type;
    u8 index;
    u8 total;
    u8 pad[2];
    u8 *buf;
    u32 len;
    u32 pend0;
    u32 pend1;
    u32 pend2;
} CamPxiCmd;
extern u32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32);
extern void OS_SpinWaitSysCycles(u32);
extern int PXI_SendWordByFifo(u32, u32, u32);
extern CamPxiCmd data_02732FC8;

int CameraSendPxiCommand(u32 a0, u32 a1, u32 a2) {
    u32 word = ((a0 << 8) & 0x7f00) | 0x2000000 | ((a1 << 16) & 0xff0000) | (a2 & 0xff);
    u32 irq = OS_DisableInterrupts();
    u16 old = reg_04004004;
    s32 had;
    reg_04004004 = old | 0x100;
    OS_RestoreInterrupts(irq);
    had = old & 0x100;
    if (had == 0) {
        OS_SpinWaitSysCycles(0x14);
    }
    data_02732FC8.pend0 = had >> 8;
    if (PXI_SendWordByFifo(0x15, word, 0) < 0) {
        if (data_02732FC8.pend0 == 0) {
            u32 irq2 = OS_DisableInterrupts();
            reg_04004004 = reg_04004004 & ~0x100;
            OS_RestoreInterrupts(irq2);
        }
        return 0;
    }
    return 1;
}
