/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * function: WIH_DWC_FindSlotByKey
 * address:  0x020107FC
 * packet:   pkt_020107FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * blocker:  label/overlay 0x02177B80.  The `bl` at +0x1E targets an
 *           unlabelled Thumb function in ov014 (wih.c); asm/overlays/ov014.s
 *           prints 0x02177B80 as .word data (0x680B4909, `ldr r1,[pc,#0x24];
 *           ldr r3,[r1]`...), and this call is the only branch to it in the
 *           image.  SEED REQUEST: `ov014 0x02177B80 thumb`, evidence the bl at
 *           arm9 0x0201081A.  Once labelled, `sole-ref/code` (or `label`, if a
 *           second referrer turns up in ov014) can carry the site.
 *           The MATCH is also starred: the listing extent runs to 0x02010888
 *           over three unlabelled leaves, filed as src/matched/unit_02010848.c.
 *
 * symbols:
 *   GFL_NET_GetRunState     0x0203CD98  arm
 *   GFL_NET_GetInitParam     0x0203D798  arm
 *   OS_GetMacAddress  0x02087C6C  arm
 *   GFL_NET_GetScanResult     0x0203CF10  arm
 *   NET_WHPIPE_GetEntryBeaconKind     0x02177B80  thumb  ov014
 *   sub_0202E8D8      0x0202E8D8  thumb
 *
 * wih_dwc.c: find the first of 16 slots whose ov014 state is 0x20 and whose
 * GFL_NET_GetScanResult record COMM_PLAYER_SUPPORT_FindPeerRecord accepts against (key, own MAC address);
 * -1 when none, or when GFL_NET_GetRunState reports the layer inactive.  The
 * closing lever over docs/notes/pkt_020107CC.c.txt was the wrapping `if`
 * instead of an early return (the original's guard branches forward over
 * the whole body to the shared -1 exit) plus the two loop tests joined by &&.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/WIH_DWC_FindSlotByKey.c \
 *       --func WIH_DWC_FindSlotByKey --addr 0x020107FC --thumb
 */

typedef unsigned char u8;

extern int  GFL_NET_GetRunState(void);
extern void *GFL_NET_GetInitParam(void);
extern void OS_GetMacAddress(u8 *mac);
typedef unsigned int   u32;
extern u32 GFL_NET_GetScanResult(u32 a);
extern u8 NET_WHPIPE_GetEntryBeaconKind(int i);
extern int sub_0202E8D8(char *a0, int a1, char *a2);

int WIH_DWC_FindSlotByKey(void *key)
{
    u8 mac[8];
    int i;

    if (GFL_NET_GetRunState() != 0) {
        GFL_NET_GetInitParam();
        OS_GetMacAddress(mac);
        for (i = 0; i < 0x10; i++) {
            if (NET_WHPIPE_GetEntryBeaconKind(i) == 0x20 && sub_0202E8D8((void *)GFL_NET_GetScanResult(i), (int)key, (char *)mac) != 0) {
                return i;
            }
        }
    }
    return -1;
}
