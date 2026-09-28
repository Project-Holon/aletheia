/*
 * function: func_02089CD4
 * address:  0x02089CD4
 * packet:   pkt_02089CD4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SND_WaitForCommandProc (snd_command.o)
 *
 * symbols:
 *   SND_IsFinishedCommandTag  0x02089D6C  arm
 *   SND_RecvCommandReply      0x02089978  arm
 *   RequestCommandProc        0x02089ED8  arm
 */

typedef unsigned long u32;
typedef int BOOL;

extern BOOL SND_IsFinishedCommandTag(u32 tag);
extern const void *SND_RecvCommandReply(u32 flags);
extern void RequestCommandProc(void);

void func_02089CD4(u32 tag)
{
    if (SND_IsFinishedCommandTag(tag)) {
        return;
    }
    while (SND_RecvCommandReply(0) != 0) {
    }
    if (SND_IsFinishedCommandTag(tag)) {
        return;
    }
    RequestCommandProc();
    if (SND_IsFinishedCommandTag(tag)) {
        return;
    }
    do {
        (void)SND_RecvCommandReply(1);
    } while (!SND_IsFinishedCommandTag(tag));
}
