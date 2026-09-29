/*
 * function: input
 * address:  0x021C73D0
 * packet:   pkt_ov016_021C73D0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * blocker: dwcutil sceneseteditaddr object is stamped Metrowerks C/C++ for ARM
 *          4.0.0.1025, which no tools/mwccarm build writes (dsi/1.1p1 ==
 *          4.0.0.1024).  Body is otherwise fully reconstructed and matches
 *          704-byte-aligned control flow; two residual codegen diffs remain:
 *          (a) the p==0 early return compiles as `bne Ldefault; pop` here but
 *          is the predicated `popeq {..,pc}; b Ldefault` in the object, and
 *          (b) the object carries a dead `pop {r3,r4,r5,r6,r7,pc}` at
 *          0x021C7418 (between the jump table and case 0x10) that 1.1p1 never
 *          emits.  Both point at the unavailable 1025 front end.
 *
 * sdk:      input (libdwcutil.TWL.HYB.a(sceneseteditaddr))
 *
 * symbols:
 *   DWCi_KB10lGet                    0x021BF6E0  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   MI_CpuFill8                      0x02082BCC  arm
 *   DWCi_KB10lSetErase               0x021BF6F4  arm
 *   DWCi_KB10lSetInput               0x021BF708  arm
 *   DWCi_KB10lSetShift               0x021BF71C  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   isCorrect                        0x021C7B34  arm
 *   dispCaret                        0x021C7960  arm
 *   arrangeAddress                   0x021C7ABC  arm
 *   isOver                           0x021C7690  arm
 *   drawAddress                      0x021C78A0  arm
 *   MemSsea                          0x021DE5E4  data
 *   endScene                         0x021C771C  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Scene Scene;
struct Scene {
    u8 _00[4];
    volatile u32 *reg;
    u8 buf[12];
    u8 cur;
    u8 state;
};

extern Scene *MemSsea;
extern int DWCi_KB10lGet(void);
extern void DWCi_SNDlPlay(int);
extern void MI_CpuFill8(void *, u8, u32);
extern void DWCi_KB10lSetErase(int);
extern void DWCi_KB10lSetInput(int);
extern void DWCi_KB10lSetShift(int);
extern void DWCi_ChangeScene(void (*)(void));
extern int isCorrect(void);
extern void dispCaret(void);
extern void arrangeAddress(void);
extern int isOver(int);
extern void drawAddress(void);
extern void endScene(void);

static void input(void)
{
    int p;
    char *adr;

    p = DWCi_KB10lGet();
    if (p > 0)
    {
    switch (p)
    {
        case 0x10:
            if (MemSsea->cur == 0 && MemSsea->buf[2] == 0)
                goto Lend;
            DWCi_SNDlPlay(3);
            if (MemSsea->buf[MemSsea->cur * 3 + 2] == 0)
                MemSsea->cur--;
            MI_CpuFill8(&MemSsea->buf[MemSsea->cur * 3], 0, 3);
            if (MemSsea->cur == 0 && MemSsea->buf[2] == 0)
                DWCi_KB10lSetErase(0);
            DWCi_KB10lSetInput(1);
            DWCi_KB10lSetShift(0);
            goto Lend;
        case 0x11:
            if (MemSsea->cur >= 3)
                goto Lend;
            if (MemSsea->buf[MemSsea->cur * 3 + 2] == 0)
                goto Lend;
            DWCi_SNDlPlay(1);
            MemSsea->cur++;
            DWCi_KB10lSetShift(0);
            goto Lend;
        case 0x12:
            MemSsea->state = 0;
            DWCi_SNDlPlay(7);
            DWCi_ChangeScene(endScene);
            return;
        case 0x13:
            if (isCorrect())
            {
                DWCi_SNDlPlay(6);
                MemSsea->state = 1;
            }
            else
            {
                MemSsea->state = 2;
                DWCi_SNDlPlay(9);
            }
            MemSsea->cur = 3;
            *MemSsea->reg = (*MemSsea->reg & 0xC1FFFCFF) | 0x200;
            dispCaret();
            arrangeAddress();
            DWCi_ChangeScene(endScene);
            return;
        default:
            break;
    }
    }
    else
    {
        if (p == 0)
            return;
    }

Ldefault:
    if (MemSsea->cur == 3 && isOver(0x1a))
        goto Lend;
    DWCi_SNDlPlay(1);
    adr = (char *)MemSsea + 8;
    if (adr[MemSsea->cur * 3 + 2] == 0)
    {
        adr[MemSsea->cur * 3 + 2] = p;
    }
    else
    {
        if (adr[MemSsea->cur * 3 + 1] == 0)
        {
            adr[MemSsea->cur * 3 + 1] = adr[MemSsea->cur * 3 + 2];
            adr[MemSsea->cur * 3 + 2] = p;
            if (!isOver(0x1a))
                goto L7628;
        }
        else
        {
            adr[MemSsea->cur * 3] = adr[MemSsea->cur * 3 + 1];
            adr[MemSsea->cur * 3 + 1] = adr[MemSsea->cur * 3 + 2];
            adr[MemSsea->cur * 3 + 2] = p;
        }
        if (MemSsea->cur < 3)
            MemSsea->cur++;
    }
L7628:
    DWCi_KB10lSetErase(1);
    if (MemSsea->cur < 3)
        DWCi_KB10lSetShift(1);
    else
        DWCi_KB10lSetShift(0);
    if (MemSsea->cur == 3 && isOver(0x1a))
        DWCi_KB10lSetInput(0);
Lend:
    drawAddress();
    dispCaret();
}
