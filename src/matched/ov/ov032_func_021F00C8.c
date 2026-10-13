/*
 * function: BEACON_VIEW_ShowViewFlagMessage
 * address:  0x021F00C8
 * packet:   pkt_ov032_021F00C8
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte-correct; blocked only by two unlabelled arm9 Thumb leaves (the integrator's,
 * no witness outside this range: label/literal/sole-ref all refuse):
 *   BEACON_STATUS_GetViewFlags (12 bytes, EXACT verified with `one --region arm9 --thumb`):
 *     u16 *BEACON_STATUS_GetViewFlags(int p) { return (u16 *)(p + 0xB0C); }
 *   BEACON_STATUS_GetMessage (12 bytes, EXACT verified likewise):
 *     int BEACON_STATUS_GetMessage(int p) { return *(int *)(p + 0xB08); }
 *
 * note (2026-10-04): wave D2 filed the arm9 leaf witnesses (src/matched/arm9/BEACON_STATUS_GetLog,
 *   AC, B8, D0 EXACT); the tool still reports them unresolved, so the label seeding for
 *   0x020275A8/AC/B8/D0 (asm/layout, not this lane) is the only blocker.
 *
 * symbols:
 *   BEACON_VIEW_ShowViewFlagMessage  0x021F00C8  thumb
 *   BEACON_STATUS_GetViewFlags  0x020275D0  thumb
 *   BEACON_STATUS_GetMessage  0x020275C4  thumb
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_021F18C4  0x021F18C4  thumb  ov032
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern void *BEACON_STATUS_GetViewFlags(char *p);
extern int BEACON_STATUS_GetMessage(void *p);
struct WordSet;
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void func_021F18C4(char *p, int b);

int BEACON_VIEW_ShowViewFlagMessage(char *p)
{
    u16 *f;

    f = BEACON_STATUS_GetViewFlags((char *)(*(int *)(p + 0x34)));
    if (*f == 0)
        return 0;
    *f = 0;
    func_0201EE0C(*(void **)(p + 0x110), 0, (void *)BEACON_STATUS_GetMessage((void *)(*(int *)(p + 0x34))),
                  *(u8 *)(p + 0x30), 1, 2);
    func_021F18C4(p, 0xB);
    return 1;
}
