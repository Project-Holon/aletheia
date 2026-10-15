/*
 * function: func_021FB5EC
 * address: 0x021FB5EC
 * packet: pkt_ov132_021FB5EC
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: func_021F80C8 is called with a u8 third parameter (its matched unit declares unsigned int; the narrowing is loop-invariant and hoisted).
 * note: older draft in docs/notes/pkt_ov132_021FB5EC.c.txt (DIFF6) is superseded.
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   func_021FB1F4 0x021FB1F4 thumb ov132
 *   STA_ACTING_GetActorSystem 0x021F9DA0 thumb ov132
 *   STA_ACTING_GetActor 0x021F9DA4 thumb ov132
 *   func_021F80C8 0x021F80C8 thumb ov112
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern int func_021FB1F4(char *, int);
extern void *STA_ACTING_GetActorSystem(char *);
extern void *STA_ACTING_GetActor(char *, u32);
extern void func_021F80C8(int, void *, u8);
int func_021FB5EC(int unused, char *p)
{
    char *obj;
    int mask;
    int value;
    char *ctx;
    u8 i;
    obj = *(char **)p;
    mask = func_021FB1F4(p, VM_GetU32(*(void **)(p + 4)));
    value = VM_GetU32(*(void **)(p + 4));
    ctx = STA_ACTING_GetActorSystem(*(char **)(obj + 0x34));
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            func_021F80C8((int)ctx, STA_ACTING_GetActor(*(char **)(obj + 0x34), i), value);
        }
    }
    return 0;
}
