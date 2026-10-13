/*
 * function: SAVE_CONTROL_StepExtraSaveWrite
 * address:  0x020073B0
 * packet:   pkt_02007374
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  02031C30 (arm) reached only by the `blx` inside this function
 *
 * symbols:
 *   g_020A7064     0x020A7064  data
 *   func_02034714  0x02034714  arm
 *   BACKUP_SYSTEM_MainLinkedSave  0x02031C30  arm
 *
 * The shortest member of the 0x14-stride handle-table family: guard, then
 * one call taking the object's +0x10 word and the table entry.  Same
 * double-named guard pointer as SAVE_CONTROL_BeginExtraSaveWrite and SAVE_CONTROL_EraseExtraSave.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SAVE_CONTROL_StepExtraSaveWrite.c \
 *       --func SAVE_CONTROL_StepExtraSaveWrite --addr 0x020073B0 --cc 1.1p1 --thumb
 */
#include "../include/Obj15569.h"

typedef unsigned int u32;

extern char g_020A7064[];
extern void func_02034714(const char *expr, u32 line, const char *file);
struct Obj;
extern int BACKUP_SYSTEM_MainLinkedSave(struct Obj *a, struct Obj *b);

int SAVE_CONTROL_StepExtraSaveWrite(char *a0, u32 a1)
{
    u32 *slot = (u32 *)(a0 + 0x14);

    if (slot[a1] == 0) {
        func_02034714(g_020A7064, 0, g_020A7064);
    }
    return BACKUP_SYSTEM_MainLinkedSave((struct Obj *)((struct Obj15569 *)a0)->f10, (struct Obj *)slot[a1]);
}
