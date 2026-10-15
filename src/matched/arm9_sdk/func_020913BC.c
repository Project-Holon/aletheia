/*
 * function: MSL_C_LIB_PrependResourceSet
 * address:  0x020913BC
 * packet:   pkt_020913BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     env_system.o ENV_PrependResourceSet; target named OS_ReferentSize by libmatch.
 *
 * symbols:
 *   ENV_InsertResourceSet  0x02086C54  arm
 */

typedef unsigned int u32;

u32 ENV_InsertResourceSet(void *prev, void *resSet);

u32 MSL_C_LIB_PrependResourceSet(void *resSet)
{
    return ENV_InsertResourceSet(0, resSet);
}
