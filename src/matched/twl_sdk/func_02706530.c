/*
 * function: DSP_Store8
 * address:  0x02706530
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DSP_SendFifoExCore  0x02705088  arm twl a2
 *   DSP_RecvFifoExCore  0x02705150  arm twl a2
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   OS_IsRunOnTwl  0x02085D3C  arm
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int BOOL;
extern u32 OS_DisableInterrupts(void);
extern u32 OS_RestoreInterrupts(u32);
extern BOOL OS_IsRunOnTwl(void);
extern void DSP_RecvFifoExCore(u32, u16 *, u16, u16, u16);
extern void DSP_SendFifoExCore(u32, u16, u16 *, u16, u16);

#define DSP_CTRL (*(volatile u16 *)0x04004308)

void DSP_Store8(u32 addr, u32 val)
{
    u16 ra;
    u16 wa;
    u16 rb;
    u16 wb;
    u32 ints;

    if ((addr & 1) == 0) {
        ints = OS_DisableInterrupts();
        if (OS_IsRunOnTwl() == 1) {
            DSP_RecvFifoExCore(0, &ra, addr >> 1, 1, 0);
        }
        DSP_CTRL &= 0xFFF1;
        OS_RestoreInterrupts(ints);
        wa = (u16)((ra & 0xFF00) | (val & 0xFF));
        ints = OS_DisableInterrupts();
        if (OS_IsRunOnTwl() == 1) {
            DSP_SendFifoExCore(0, addr >> 1, &wa, 1, 0);
        }
        OS_RestoreInterrupts(ints);
    } else {
        ints = OS_DisableInterrupts();
        if (OS_IsRunOnTwl() == 1) {
            DSP_RecvFifoExCore(0, &rb, addr >> 1, 1, 0);
        }
        DSP_CTRL &= 0xFFF1;
        OS_RestoreInterrupts(ints);
        wb = (u16)((rb & 0xFF) | ((val << 8) & 0xFF00));
        ints = OS_DisableInterrupts();
        if (OS_IsRunOnTwl() == 1) {
            DSP_SendFifoExCore(0, addr >> 1, &wb, 1, 0);
        }
        OS_RestoreInterrupts(ints);
    }
}
