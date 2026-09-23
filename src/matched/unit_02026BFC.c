/*
 * unit:     yes
 * function: sub_02026BFC
 * address:  0x02026BFC
 * packet:   pkt_0202685C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Five unlabelled leaves between func_02026A60 and func_02026CA0
 * (0x02026BFC..0x02026CA0), tu-verified: two ring-slot accessors, their
 * g_GameBeacon tail-call wrappers, and the +0xBA8 count getter.
 *   sub_02026BFC  slot n of the ring if n is below the s8 at +0xBAE
 *   sub_02026C1C  sub_02026BFC(g_GameBeacon, n)
 *   sub_02026C30  the slot n records back from the hi cursor, wrapped at 30;
 *                 the zero test on count - n is `c - n == 0` (a `subs`),
 *                 not `c == n` (a `cmp`)
 *   sub_02026C78  sub_02026C30(g_GameBeacon, n)
 *   sub_02026C8C  the +0xBA8 insert count
 * None has an lr save, so the integrator should seed all five starts.
 *
 * symbols:
 *   g_GameBeacon  0x02146940  data
 */
typedef signed char    s8;
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 *g_GameBeacon;

void *sub_02026BFC(u8 *base, int n)
{
    int c = *(s8 *)(base + 0xBAE);
    if (c == 0 || c - n <= 0)
        return 0;
    return base + 0x64 + n * 0x60;
}

void *sub_02026C1C(int n)
{
    return sub_02026BFC(g_GameBeacon, n);
}

void *sub_02026C30(u8 *base, int n)
{
    u32 c = *(u32 *)(base + 0xBA8);
    int j;
    if (c == 0 || c - n == 0)
        return 0;
    j = *(s8 *)(base + 0xBAD) - (int)(c - 1 - n);
    if ((j < 0 ? -j : j) >= 30)
        return 0;
    if (j < 0)
        j += 30;
    return base + 0x64 + j * 0x60;
}

void *sub_02026C78(int n)
{
    return sub_02026C30(g_GameBeacon, n);
}

u32 sub_02026C8C(void)
{
    return *(u32 *)(g_GameBeacon + 0xBA8);
}
