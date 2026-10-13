/*
 * function: func_01FF8020
 * address:  0x01FF8020
 * packet:   pkt_01FF8020
 * region:   arm9_autoload0_ITCM
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   OS_DisableInterrupts    0x02087988  arm
 *   OS_RestoreInterrupts    0x0208799C  arm
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef volatile u32 vu32;

extern int OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(int);

typedef union
{
    u32 b32;
    u16 b16;
} MIiDmaClearSrc;

void func_01FF8020(u32 dmaNo, u32 src, u32 dest, u32 ctrl, u32 mode)
{
    int enabled;
    vu32 *p;

    if (!(mode & 1))
    {
        enabled = OS_DisableInterrupts();
    }

    p = (vu32 *)(0x040000B0 + dmaNo * 12);

    if (mode & 0x10)
    {
        MIiDmaClearSrc *srcp = (MIiDmaClearSrc *)(0x040000E0 + dmaNo * 4);
        srcp->b32 = src;
        src = (u32)srcp;
    }
    else if (mode & 0x20)
    {
        MIiDmaClearSrc *srcp = (MIiDmaClearSrc *)(0x040000E0 + dmaNo * 4);
        srcp->b16 = (u16)src;
        src = (u32)srcp;
    }

    *p = (vu32)src;
    *(p + 1) = (vu32)dest;
    *(p + 2) = (vu32)ctrl;

    if (mode & 2)
    {
        {
            u32 dummy = *(volatile u32 *)0x040000B0;
        }
        {
            u32 dummy = *(volatile u32 *)0x040000B0;
        }

        if (!(mode & 4))
        {
            if (dmaNo == 0)
            {
                *p = 0;
                *(p + 1) = 0;
                *(p + 2) = 0x81400001;
            }
        }
    }

    if (!(mode & 1))
    {
        OS_RestoreInterrupts(enabled);
    }

    if (mode & 2)
    {
        {
            u32 dummy = *(volatile u32 *)0x040000B0;
        }
        {
            u32 dummy = *(volatile u32 *)0x040000B0;
        }
    }
}
