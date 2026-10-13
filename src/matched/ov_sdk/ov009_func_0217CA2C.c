/*
 * function: func_0217CA2C
 * address:  0x0217CA2C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Calls gsiDeleteCriticalSection on the block sixteen bytes into the result.
 *
 * symbols:
 *   gsiCoreGetManager  0x0217CA20  arm
 *   gsiDeleteCriticalSection  0x0217F120  arm

 */

extern char *gsiCoreGetManager(void);
extern void gsiDeleteCriticalSection(void *p);

void func_0217CA2C(void)
{
    gsiDeleteCriticalSection(gsiCoreGetManager() + 0x10);
}

