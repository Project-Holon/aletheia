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
 * blocker: front-end behaviour difference, ~8 bytes + 1 dead instruction.
 *          lane03 (2026-09-30) applied the adr-hoist (`k=cur*3`,
 *          `unsigned char *adr`), dropping to 535 concrete bytes.
 *          lane08 (2026-09-30) confirmed the two residual sites are the
 *          front end's choices, not a source shape:
 *           (a) else arm polarity: the object predicates the void return and
 *               branches the Ldefault path (`popeq {r3,r4,r5,r6,r7,pc};
 *               b Ldefault`), but 1.1p1 always emits the mirror
 *               (`bne Ldefault; pop {r3,r4,r5,r6,r7,pc}`).  Tried and
 *               rejected: separate `if (p==0) return;` (merges to a bottom
 *               `ble` block, 696 B); `else if (p==0) return;` (same merge);
 *               `else if (p!=0) goto Ldefault; else return;`; `if (p>0)
 *               goto Lswitch; if (p==0) return; goto Ldefault;`.
 *               The closest is `if (p<=0){ if(p==0) return; goto Ldefault; }
 *               switch(...)` (700 B, correct `bgt` at 0x1C), which still
 *               yields the mirror `bne; pop` in place of aspect (a).
 *           (b) a dead `pop {r3,r4,r5,r6,r7,pc}` at 0x021C7418 between the
 *               switch jump table and case 0x10, which 1.1p1 never emits
 *               (4 of the 8 remaining bytes).  A `default: return;` arm does
 *               not produce it either.
 *          Everything else (26/26 relocations, all other bytes) reproduces
 *          once the 4-byte dead pop is accounted for; the gap is purely the
 *          two codegen choices above.
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
    if (p <= 0)
    {
        if (p == 0)
            return;
        goto Ldefault;
    }
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

Ldefault:
    if (MemSsea->cur == 3 && isOver(0x1a))
        goto Lend;
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
Lend:
    drawAddress();
    dispCaret();
}
