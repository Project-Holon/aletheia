/*
 * function: DSPi_MasterInterrupts
 * address:  0x0270532C
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */


typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef struct Shared { u8 pad[0x3FF8]; vu32 flags; } Shared;
typedef struct Sys {
    u32 pad0[0x1a];
    u32 mask;
    void (*handler[19])(u32);
    u32 arg[19];
    u32 clear[19];
} Sys;
static inline u32 clz32(u32 x)
{
    asm { clz x, x }
    return x;
}
void DSPi_MasterInterrupts(void)
{
    Sys *s = *(Sys **)0x027344AC;
    u32 pend;
    u32 bit;
    u16 lo, hi;
    Shared *sp;
    if (s != 0) {
        for (;;) {
            lo = *(vu16 *)0x0400431C;
            hi = *(vu16 *)0x0400430C;
            pend = (lo | (((hi >> 10) & 7) << 16));
            pend &= s->mask;
            if (pend == 0) {
                break;
            }
            while (pend != 0) {
                bit = 32 - clz32(~pend & (pend - 1));
                pend &= ~s->clear[bit];
                s->handler[bit](s->arg[bit]);
            }
        }
    }
    sp = (Shared *)0x02FE0000;
    sp->flags |= 0x01000000;
}
