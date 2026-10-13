/*
 * unit:     no
 * function: GAMESYSTEM_IsSleepBlocked
 * address:  0x02012264
 * packet:   pkt_02012158
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GFL_NET_IRC_WIRELESS_IsActive  0x0203DA4C  arm
 */

struct Ctx;
extern unsigned int func_02012138(const struct Ctx *p);
extern unsigned int func_0201214C(const struct Ctx *p);

int GAMESYSTEM_IsSleepBlocked(int a0, int a1, int a2, int a3){ int t0, t1, t2, t3, t4; t0 = func_02012138((const struct Ctx *)a0); t1 = func_02026454((int)t0); if ((unsigned int)(t1) != (unsigned int)(0)) { return 1; } else { t2 = GFL_NET_IRC_WIRELESS_IsActive((int)t1); if ((unsigned int)(t2) != (unsigned int)(0)) { return 1; } else { t3 = func_020353B0((int)t2); if ((unsigned int)(t3) != (unsigned int)(0)) { return 0; } else { t4 = func_0201214C((const struct Ctx *)((a0 + 0) + 0)); if ((unsigned int)(t4) != (unsigned int)(0)) { return 1; } else { return 0; } } } } }
