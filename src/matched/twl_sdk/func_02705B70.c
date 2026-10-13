/*
 * function: DSP_SetProcessHook
 * address:  0x02705B70
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm  arm9
 *   OS_RestoreInterrupts  0x0208799C  arm  arm9
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef int s32;
typedef volatile u16 vu16;
typedef struct Sys {
    u32 pad0[0x1a];
    u32 mask;
    void (*handler[19])(u32);
    u32 arg[19];
    u32 clear[19];
} Sys;

extern s32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(s32);

void DSP_SetProcessHook(Sys *s, s32 mask, void (*h)(u32), u32 arg)
{
    s32 en = OS_DisableInterrupts();
    vu16 *r = (vu16 *)0x04004308;
    s32 i;
    u16 a, b;
    u32 hi, lo;
    for (i = 0; i < 19; i++) {
        if (mask & (1 << i)) {
            s->handler[i] = h;
            s->arg[i] = arg;
            s->clear[i] = mask;
        }
    }
    a = r[0];
    b = r[6];
    hi = ((mask >> 16) & 7) << 9;
    lo = mask & 0xffff;
    if (h != 0) {
        r[0] = a | hi;
        r[6] = b & ~lo;
        s->mask |= mask;
    } else {
        r[0] = a & ~hi;
        r[6] = b | lo;
        s->mask &= ~mask;
    }
    OS_RestoreInterrupts(en);
}
