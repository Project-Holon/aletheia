/*
 * function: BACKUP_SYSTEM_CreateWithWork
 * address:  0x02031948
 * packet:   pkt_02031948
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   BACKUP_SYSTEM_CreateCore 0x0203174C arm
 */

typedef unsigned int   u32;
struct Blk;
struct In;
extern struct Blk *BACKUP_SYSTEM_CreateCore(const struct In *in, u32 heap, u32 c, u32 d, u32 e);

struct Blk *BACKUP_SYSTEM_CreateWithWork(const struct In *in, u32 heap, u32 c, u32 d, u32 e)
{
    return BACKUP_SYSTEM_CreateCore(in, heap, c, d, e);
}
