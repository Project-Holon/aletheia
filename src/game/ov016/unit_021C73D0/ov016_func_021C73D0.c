/*
 * function: input
 * address:  0x021C73D0
 * packet:   pkt_ov016_021C73D0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * 2026-10-01: closed. The `bgt; popeq; b default` head and the dead pop after
 * the jump table are one switch with `case 0: return;` (the case-0 block is
 * the dead pop; its beq became the predicated popeq). Cases break to a shared
 * drawAddress/dispCaret tail; the character input is the default arm.
 * `k` has no DWARF entry (likely a macro), kept as the CSE of cur*3.
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
    unsigned char *adr;
    int k;

    p = DWCi_KB10lGet();
    switch (p)
    {
        case 0:
            return;
        case 0x10:
            if (MemSsea->cur == 0 && MemSsea->buf[2] == 0)
                break;
            DWCi_SNDlPlay(3);
            if (MemSsea->buf[MemSsea->cur * 3 + 2] == 0)
                MemSsea->cur--;
            MI_CpuFill8(&MemSsea->buf[MemSsea->cur * 3], 0, 3);
            if (MemSsea->cur == 0 && MemSsea->buf[2] == 0)
                DWCi_KB10lSetErase(0);
            DWCi_KB10lSetInput(1);
            DWCi_KB10lSetShift(0);
            break;
        case 0x11:
            if (MemSsea->cur >= 3)
                break;
            if (MemSsea->buf[MemSsea->cur * 3 + 2] == 0)
                break;
            DWCi_SNDlPlay(1);
            MemSsea->cur++;
            DWCi_KB10lSetShift(0);
            break;
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
            if (MemSsea->cur == 3 && isOver(0x1a))
                break;
            DWCi_SNDlPlay(1);
            adr = (unsigned char *)MemSsea + 8;
            k = MemSsea->cur * 3;
            if (adr[k + 2] == 0)
            {
                adr[k + 2] = p;
            }
            else
            {
                if (adr[k + 1] == 0)
                {
                    adr[k + 1] = adr[k + 2];
                    adr[k + 2] = p;
                    if (!isOver(0x1a))
                        goto L7628;
                }
                else
                {
                    adr[k] = adr[k + 1];
                    adr[k + 1] = adr[k + 2];
                    adr[k + 2] = p;
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
            break;
    }
    drawAddress();
    dispCaret();
}
