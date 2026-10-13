/*
 * function: DSP_LoadData
 * address:  0x0270633C
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
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

#define DSP_CTRL (*(volatile u16 *)0x04004308)

void DSP_LoadData(u32 addr, u8 *dst, u32 len)
{
    u16 t8;
    u16 t6;
    u16 t4;
    u32 ints;
    u32 n;
    u32 lo;
    int w;

    if (len == 0) {
        return;
    }
    lo = addr & 1;
    if (lo != 0) {
        ints = OS_DisableInterrupts();
        if (OS_IsRunOnTwl() == 1) {
            DSP_RecvFifoExCore(0, &t8, addr >> 1, 1, 0);
        }
        DSP_CTRL &= 0xFFF1;
        OS_RestoreInterrupts(ints);
        *dst++ = (u8)(t8 >> (lo * 8));
        addr++;
        len--;
    }
    if (((u32)dst & 1) == 0) {
        n = len & ~1;
        if (n != 0) {
            ints = OS_DisableInterrupts();
            if (OS_IsRunOnTwl() == 1) {
                DSP_RecvFifoExCore(0, (u16 *)dst, addr >> 1, n >> 1, 0);
            }
            DSP_CTRL &= 0xFFF1;
            OS_RestoreInterrupts(ints);
            dst += n;
            addr += n;
            len -= n;
        }
    } else {
        while (len >= 2) {
            ints = OS_DisableInterrupts();
            if (OS_IsRunOnTwl() == 1) {
                DSP_RecvFifoExCore(0, &t6, addr >> 1, 1, 0);
            }
            DSP_CTRL &= 0xFFF1;
            OS_RestoreInterrupts(ints);
            w = t6;
            len -= 2;
            dst[0] = (u8)w;
            dst[1] = (u8)(w >> 8);
            dst += 2;
            addr += 2;
        }
    }
    if (len != 0) {
        ints = OS_DisableInterrupts();
        if (OS_IsRunOnTwl() == 1) {
            DSP_RecvFifoExCore(0, &t4, addr >> 1, 1, 0);
        }
        DSP_CTRL &= 0xFFF1;
        OS_RestoreInterrupts(ints);
        *dst = (u8)(t4 >> ((addr & 1) * 8));
    }
}
