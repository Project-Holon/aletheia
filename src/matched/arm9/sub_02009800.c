/*
 * function: WIFILIST_Init
 * address:  0x02009800
 * packet:   pkt_02009800
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     wave 17 (overlay_id class): EXACT. The pooled overlay-id sites
 *           ov_id_0D (13) and ov_id_09 (9) resolve as `overlay_id` (a layout
 *           overlay index, loaded by a pc-relative load of this function,
 *           reaching the id register of a known overlay loader), which was
 *           the last blocker.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_02034AC4  0x02034AC4  arm
 *   DWC_RAPCOMMON_InitUserData  0x02157138  thumb ov009
 *   ov_id_09       0x00000009  data
 *   ov_id_0A       0x0000000A  data
 *   ov_id_0B       0x0000000B  data
 *   ov_id_0D       0x0000000D  data
 *
 * The wifilist constructor, diagnosed in the header of
 * src/matched/unit_02009860.c under "NEAR MISS, 0x02009800".  The only
 * branch to DWC_RAPCOMMON_InitUserData (ov009) in the image is the call in this
 * function; since seed round 9 it resolves as `sole-ref` on the seeded
 * ov009 start.
 *
 * The four ids arrive from literal pool words holding 0x09, 0x0A, 0x0B and
 * 0x0D rather than as `movs`, so they are relocations against absolute
 * symbols, not integer literals: see
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.  With
 * the four declared as extern data symbols all four sites resolve and every
 * concrete byte reproduces.
 */

extern void func_02082BCC(void *dst, int val, unsigned n);
extern void func_02034A5C(int handle);
extern int func_02034AC4(int id);
extern void DWC_RAPCOMMON_InitUserData(void *p);

extern unsigned char ov_id_09[];
extern unsigned char ov_id_0A[];
extern unsigned char ov_id_0B[];
extern unsigned char ov_id_0D[];

void WIFILIST_Init(void *p)
{
    func_02082BCC(p, 0, 0x7c4);
    func_02034A5C((int)ov_id_0A);
    func_02034A5C((int)ov_id_0B);
    func_02034AC4((int)ov_id_0D);
    func_02034AC4((int)ov_id_09);
    DWC_RAPCOMMON_InitUserData(p);
    func_02034A5C((int)ov_id_09);
    func_02034A5C((int)ov_id_0D);
    func_02034AC4((int)ov_id_0A);
    func_02034AC4((int)ov_id_0B);
}
