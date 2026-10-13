/*
 * function: WIPE_SYS_ExeEnd
 * address:  0x020221B8
 * packet:   pkt_02022174
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Shutdown of the dual-screen text cluster, the counterpart of WIPE_SYS_Start.
 * It drops both entries of the callback block at +0x74, forces each live screen
 * into state 2, unpublishes both sub-objects through the same WIPE_SYS_MainPanel
 * slot writer the setup used, clears the live counter and the two delegate
 * flags at +0x14C/+0x14E/+0x14F, and releases the object.
 *
 * Every pool word here is g_wipeSys with a different displacement (+0x74,
 * +0x00, +0x04, +0x14, +0x08, +0x44, +0x140), one symbol and not seven
 * objects; see
 * docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md.
 *
 * symbols:
 *   g_wipeSys     0x021467A4  data
 *   WIPE_ClearHBlankSlot  0x020224DC  thumb
 *   WIPE_SYS_MainPanel  0x02022390  thumb
 *   WIPE_SUB_ClearSys  0x020226A0  thumb
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SYS_ExeEnd.c \
 *       --func WIPE_SYS_ExeEnd --addr 0x020221B8 --cc 1.1p1 --thumb
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Sub {
    u8  pad00[0x0C];
    u32 f0C;
    u8  pad10[0x20];
};

struct G {
    u8          pad00[4];
    void       *f04;
    void       *f08;
    void       *f0C;
    void       *f10;
    struct Sub  f14;
    struct Sub  f44;
    u8          f74[0x18];
    u8          f8C[0xC0];
    u16         f14C;
    u8          f14E;
    u8          f14F;
};

extern struct G g_wipeSys;

struct Slots;
extern void WIPE_ClearHBlankSlot(struct Slots *p, u32 idx);
extern void WIPE_SYS_MainPanel(u32 *obj, void *arg);
extern void WIPE_SUB_ClearSys(u8 *p);

void WIPE_SYS_ExeEnd(void)
{
    WIPE_ClearHBlankSlot((struct Slots *)g_wipeSys.f74, 0);
    WIPE_ClearHBlankSlot((struct Slots *)g_wipeSys.f74, 1);
    if (g_wipeSys.f04 != 0)
        g_wipeSys.f14.f0C = 2;
    if (g_wipeSys.f08 != 0)
        g_wipeSys.f44.f0C = 2;
    WIPE_SYS_MainPanel((u32 *)(&g_wipeSys.f04), &g_wipeSys.f14);
    WIPE_SYS_MainPanel((u32 *)(&g_wipeSys.f08), &g_wipeSys.f44);
    g_wipeSys.f14C = 0;
    g_wipeSys.f14E = 0;
    g_wipeSys.f14F = 0;
    WIPE_SUB_ClearSys((u8 *)(&g_wipeSys));
}
