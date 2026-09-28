/*
 * function: KeyValFree
 * address:  0x0219E89C
 * packet:   pkt_ov009_0219E89C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      KeyValFree (sb_server.o)
 *
 * The element is accessed through the parameter cast rather than bound to a
 * local: that keeps the pointer in r5 and reloads `[r5]`/`[r5,#4]` at each use,
 * instead of a `mov r5, r0` plus a single `ldr r5,[r0]` dereference.
 *
 * symbols:
 *   SBReleaseStr  0x0219F920  arm
 */

struct _SBServerList;
struct _SBKeyValuePair {
    char *key;
    char *value;
};

extern void SBReleaseStr(struct _SBServerList *slist, char *str);

static void KeyValFree(void *elem)
{
    SBReleaseStr(0, ((struct _SBKeyValuePair *)elem)->key);
    SBReleaseStr(0, ((struct _SBKeyValuePair *)elem)->value);
}
