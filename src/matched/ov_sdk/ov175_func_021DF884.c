/*
 * function: sciInterfaceInit
 * address:  0x021DF884
 * packet:   pkt_021DF884
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sciWsInit  0x021E06DC  arm
 *   MSL_C_LIB_MemsetPtr  0x020923B0  arm
 *
 * Activation probe: sciWsInit reports on the owner, and a report is
 * returned as-is.  Otherwise clear the two 0x28-byte parameter blocks and
 * mark the owner live at +0x50.
 */

typedef int s32;
typedef unsigned int u32;

extern s32 sciWsInit(char *p, u32 v);
extern void *MSL_C_LIB_MemsetPtr(void *p, int c, u32 n);

s32 sciInterfaceInit(char *p)
{
    s32 e = sciWsInit(p, (u32)p);

    if (e != 0)
        return e;
    MSL_C_LIB_MemsetPtr(p + 0x5c, 0, 0x28);
    MSL_C_LIB_MemsetPtr(p + 0x84, 0, 0x28);
    *(u32 *)(p + 0x50) = 1;
    return 0;
}
