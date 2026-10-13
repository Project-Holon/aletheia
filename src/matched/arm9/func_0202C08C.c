/*
 * function: ISS_SWITCH_SYS_Delete
 * address:  0x0202C08C
 * packet:   pkt_0202BE00
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocker ISS_SYS_DeleteSwitch.c is now a manifest entry (matched class)
 *
 * Runs ISS_SWITCH_SYS_DeleteSets then ISS_SWITCH_SYS_Free over the object.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_SWITCH_SYS_Delete.c \
 *       --func ISS_SWITCH_SYS_Delete --addr 0x0202C08C --thumb --cc 1.1p1
 *
 * symbols:
 *   ISS_SWITCH_SYS_Free  0x0202C140  thumb
 *   ISS_SWITCH_SYS_DeleteSets  0x0202C198  thumb
 */

typedef unsigned char u8;

extern void ISS_SWITCH_SYS_DeleteSets(u8 *p);
extern void ISS_SWITCH_SYS_Free(void *ptr);

void ISS_SWITCH_SYS_Delete(u8 *p)
{
    ISS_SWITCH_SYS_DeleteSets(p);
    ISS_SWITCH_SYS_Free(p);
}
