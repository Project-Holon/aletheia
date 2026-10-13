/*
 * function: BACKUP_SYSTEM_Create
 * address:  0x0203192C
 * packet:   pkt_020315F0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   BACKUP_SYSTEM_CreateCore  0x0203174C  arm
 *
 * backup_system.c.  A one-line forwarder: its two arguments go straight
 * through to 0x0203174C together with three zero/one flags, the fifth landing
 * on the stack.  The two zero arguments cost a single `mov r2, #0` plus the
 * `mov r3, r2` copy the compiler makes instead of a second move, and the `1`
 * is materialised into `ip` because an ARM `str` has no immediate form.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BACKUP_SYSTEM_Create.c \
 *       --func BACKUP_SYSTEM_Create --addr 0x0203192C --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct Blk;
struct In;
extern struct Blk *BACKUP_SYSTEM_CreateCore(const struct In *in, u32 heap, u32 c, u32 d, u32 e);

u32 BACKUP_SYSTEM_Create(void *a, void *b)
{
    return (u32)BACKUP_SYSTEM_CreateCore(a, (u32)b, 0, 0, 1);
}
