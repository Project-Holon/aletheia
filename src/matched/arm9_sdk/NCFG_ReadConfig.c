/*
 * function: NCFG_ReadConfig
 * address:  0x0205FAA8
 * packet:   pkt_0205FAA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0205FFC4 0x0205FFC4 arm
 */

typedef unsigned int u32;
typedef struct NCFGConfig NCFGConfig;
extern int func_0205FFC4(NCFGConfig *config);

u32 NCFG_ReadConfig(NCFGConfig *config)
{
    return func_0205FFC4(config) ? 0 : 0xFFFFFFFF;
}
