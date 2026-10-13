/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * function: WIH_DWC_Create
 * address:  0x02010360
 * packet:   pkt_02010360
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     rewritten 2026-09-23 (wave 14): every concrete byte right, 11 of
 *           12 relocation sites resolved.
 *
 * blocker:  label/overlay 0x0217963C.  The `bl` at +0x56 targets an unlabelled
 *           Thumb leaf in ov014 (wih.c): 0x0217963C decodes as
 *           `ldr r1,[pc,#8]; ldr r2,[r1]; ldr r1,[pc,#8]; str r0,[r2,r1];
 *           bx lr`, a setter of word +0x1E88 of the object behind 0x021797A8
 *           (the same shape as the labelled WIH_SetConnectCallback just before it,
 *           which sets +0x1E84).  asm/overlays/ov014.s prints it as .word
 *           data, so attest_overlay_label() has no label to accept.  SEED
 *           REQUEST for the integrator: `ov014 0x0217963C thumb`, evidence
 *           the bl at arm9 0x020103B6 (this function) and 0x020103FE
 *           (WIH_DWC_Delete).  Once seeded, 0x020103FE is an outside witness
 *           for this file and 0x020103B6 for WIH_DWC_Delete: both go EXACT
 *           with no C change.
 *
 * symbols:
 *   gWihDwc     0x021461E0  data
 *   sWihDwcAssertArg        0x020A7240  data
 *   sWihDwcFile    0x020A7244  data
 *   func_02034714  0x02034714  arm
 *   GFL_NET_AllocAligned  0x0203D7C8  arm
 *   DWC_GetParseWMBssDescWorkSize  0x0205D010  arm
 *   func_02034AC4  0x02034AC4  arm
 *   WIH_SetBeaconFoundCallback  0x0217963C  thumb  ov014
 *   WIH_DWC_AddBeacon  0x0201045C  thumb
 *   ov015_id       0x0000000F  data
 *
 * wih_dwc.c constructor: allocates the 0x328-byte object (line 0x49), stores
 * the index at +0x310, allocates a second buffer sized by DWC_GetParseWMBssDescWorkSize
 * (line 0x4C) into +0x300, registers WIH_DWC_AddBeacon as the ov014 receive
 * callback, publishes the object in the global and copies the global's
 * second word into +0x304.  WIH_DWC_Delete is its destructor.
 * Two readings corrected from the previous file: the pool word is
 * 0x021461E0 (not 0x020461E0), and 0x0201045D is the Thumb address of
 * WIH_DWC_AddBeacon, a function pointer, not data.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/WIH_DWC_Create.c \
 *       --func WIH_DWC_Create --addr 0x02010360 --thumb
 */
#include "../include/Obj07083.h"
#include "../include/G_WihCtx.h"
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern struct WihCtx gWihDwc;
extern u8 sWihDwcAssertArg;
extern u8 sWihDwcFile[];
extern u8 ov015_id[];

extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *GFL_NET_AllocAligned(u32 heap, u32 size, const char *file, u16 line);
extern u32  DWC_GetParseWMBssDescWorkSize(void);
extern int func_02034AC4(int id);
extern void WIH_SetBeaconFoundCallback(u32 v);
extern void WIH_DWC_AddBeacon(const void *src);

u8 *WIH_DWC_Create(int idx, void *heap)
{
    u8 *p;

    if (idx > 4) {
        func_02034714((const char *)(&sWihDwcAssertArg), 0, (const char *)(&sWihDwcAssertArg));
    }
    if (gWihDwc.f0 != 0) {
        func_02034714((const char *)(&sWihDwcAssertArg), 0, (const char *)(&sWihDwcAssertArg));
    }
    p = GFL_NET_AllocAligned((u32)heap, 0x328, (const char *)sWihDwcFile, 0x49);
    ((struct Obj07083 *)p)->f310 = idx;
    *(u8 * *)&((struct Obj07083 *)p)->f300 = GFL_NET_AllocAligned((u32)heap, DWC_GetParseWMBssDescWorkSize(), (const char *)sWihDwcFile, 0x4C);
    WIH_SetBeaconFoundCallback((u32)WIH_DWC_AddBeacon);
    gWihDwc.f0 = p;
    *(u8 * *)&((struct Obj07083 *)p)->f304 = gWihDwc.f4;
    func_02034AC4((int)ov015_id);
    return p;
}
