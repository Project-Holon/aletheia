/*
 * function: SCRIPT_COMMAND_CmdSetActorFlag
 * address: 0x021FB5EC
 * packet: pkt_ov132_021FB5EC
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: STA_ACT_LIGHT_CallElemC is called with a u8 third parameter (its matched unit declares unsigned int; the narrowing is loop-invariant and hoisted).
 * note: older draft in docs/notes/pkt_ov132_021FB5EC.c.txt (DIFF6) is superseded.
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   SCRIPT_COMMAND_GetActorMask 0x021FB1F4 thumb ov132
 *   STA_ACTING_GetActorSystem 0x021F9DA0 thumb ov132
 *   STA_ACTING_GetActor 0x021F9DA4 thumb ov132
 *   STA_ACT_LIGHT_CallElemC 0x021F80C8 thumb ov112
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern int SCRIPT_COMMAND_GetActorMask(char *, int);
extern void *STA_ACTING_GetActorSystem(char *);
extern void *STA_ACTING_GetActor(char *, u32);
extern void STA_ACT_LIGHT_CallElemC(int, void *, u8);
int SCRIPT_COMMAND_CmdSetActorFlag(int unused, char *p)
{
    char *obj;
    int mask;
    int value;
    char *ctx;
    u8 i;
    obj = *(char **)p;
    mask = SCRIPT_COMMAND_GetActorMask(p, VM_GetU32(*(void **)(p + 4)));
    value = VM_GetU32(*(void **)(p + 4));
    ctx = STA_ACTING_GetActorSystem(*(char **)(obj + 0x34));
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            STA_ACT_LIGHT_CallElemC((int)ctx, STA_ACTING_GetActor(*(char **)(obj + 0x34), i), value);
        }
    }
    return 0;
}
