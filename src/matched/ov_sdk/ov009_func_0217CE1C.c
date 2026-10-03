/*
 * function: func_0217CE1C
 * address:  0x0217CE1C
 * packet:   pkt_ov009_0217CE1C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsCoreIsShutdown (gscore.o)
 *
 * symbols:
 *   func_0217CA20                  0x0217CA20  arm ov009
 */

typedef struct GSCoreMgr {
    int a0;
    char pad4[8];
    int b0c;
} GSCoreMgr;

extern void *func_0217CA20(void);

int func_0217CE1C(void)
{
    GSCoreMgr *aCore = func_0217CA20();
    if (aCore->b0c != 0)
        return 1;
    if (aCore->a0 == 0)
        return 2;
    return 0;
}
