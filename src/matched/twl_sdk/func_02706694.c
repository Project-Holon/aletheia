/*
 * function: DSP_StoreData
 * address:  0x02706694
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
 *   DSP_Store8  0x02706530  arm twl a2
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
extern void DSP_SendFifoExCore(u32, u16, u16 *, u16, u16);
extern void DSP_Store8(u32, u32);

void DSP_StoreData(u32 addr, u8 *src, u32 len)
{
    u16 w;
    u32 n;
    u32 ints;

    if (len == 0) {
        return;
    }
    if (addr & 1) {
        DSP_Store8(addr, *src++);
        addr++;
        len--;
    }
    if (((u32)src & 1) == 0) {
        n = len & ~1;
        if (n != 0) {
            ints = OS_DisableInterrupts();
            if (OS_IsRunOnTwl() == 1) {
                DSP_SendFifoExCore(0, addr >> 1, (u16 *)src, n >> 1, 0);
            }
            OS_RestoreInterrupts(ints);
            src += n;
            addr += n;
            len -= n;
        }
    } else {
        while (len >= 2) {
            w = src[0] | (src[1] << 8);
            ints = OS_DisableInterrupts();
            if (OS_IsRunOnTwl() == 1) {
                DSP_SendFifoExCore(0, addr >> 1, &w, 1, 0);
            }
            OS_RestoreInterrupts(ints);
            len -= 2;
            src += 2;
            addr += 2;
        }
    }
    if (len != 0) {
        DSP_Store8(addr, *src);
    }
}
