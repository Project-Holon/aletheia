/*
 * function: GFL_NET_ERR_CheckNetError
 * address:  0x0200F734
 * packet:   pkt_0200F6D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  wave 14 (2026-09-23): ONE site, the THM_CALL at +0x74 to
 *           DWC_RAP_GetErrorMessageClass.  It is now a traced Thumb label in ov009 (ov010
 *           overlaps with non-code there, hence the ov009 hint below), but
 *           the call at 0x0200F7A8 is the only branch image-wide that
 *           reaches it, so the overlay `label` class refuses (no outside
 *           branch) and sole-ref/code does not cover overlay addresses.
 *           Needs a tool-side sole-ref/code rule for overlay labels, or a
 *           matched ov009 entry covering 0x02156460.  GFL_NET_ClearBeaconCallbacks now
 *           resolves.
 *
 * symbols:
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   GFL_NET_CheckError  0x0203D880  arm
 *   GFL_NET_SYSTEM_IsError  0x020393D0  arm
 *   GFL_NET_STATE_GetErrorMode  0x0203C990  arm
 *   GFL_NET_ClearBeaconCallbacks  0x0203D864  arm
 *   func_0200FAAC  0x0200FAAC  thumb
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   GFL_NET_STATE_GetError  0x0203CA98  arm
 *   DWC_RAP_GetErrorMessageClass  0x02156460  thumb  ov009
 *
 * A gated status update: bails out early if the module-wide object at
 * 0x0214617C already has its +0x2c flag set, or if GFL_NET_GetRunState does not
 * report state 1, or if none of three link-state probes says yes. Once
 * past the gate it re-derives a status byte from GFL_NET_GetInitParam's returned
 * object at offset +0x65 (only 1, 2 or 6 continue), then compares a field
 * of the object GFL_NET_STATE_GetError returns against two small windows and stores
 * a fixed error code into the global's +0x60 for either, falling through
 * to a real computation (DWC_RAP_GetErrorMessageClass on the object's first two words)
 * otherwise.
 *
 * Every concrete byte matches; GFL_NET_ClearBeaconCallbacks and DWC_RAP_GetErrorMessageClass are each
 * called from exactly this one site in the whole ROM, so both stay
 * unresolved relocations under the honesty rule.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_ERR_CheckNetError.c \
 *       --func GFL_NET_ERR_CheckNetError --addr 0x0200F734 --cc 1.1p1
 *
 * The `matched` class does not reach it: neither GFL_NET_ClearBeaconCallbacks nor
 * DWC_RAP_GetErrorMessageClass is matched, so no EXACT entry covers either address.  Both live
 * outside the matched region so far.
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern int GFL_NET_GetRunState(void);
extern u32  GFL_NET_CheckError(void);
extern int GFL_NET_SYSTEM_IsError(void);
extern u32  GFL_NET_STATE_GetErrorMode(void);
extern void GFL_NET_ClearBeaconCallbacks(void);
extern void func_0200FAAC(void);
extern void *GFL_NET_GetInitParam(void);
extern u32 GFL_NET_STATE_GetError(void);
extern int DWC_RAP_GetErrorMessageClass(int err, int kind);

void GFL_NET_ERR_CheckNetError(void)
{
    u32 *g = (u32 *)0x0214617C;

    if (g[0x2c / 4] != 0) {
        return;
    }
    if (GFL_NET_GetRunState() != 1) {
        return;
    }
    if (GFL_NET_CheckError() == 0 && GFL_NET_SYSTEM_IsError() == 0 && GFL_NET_STATE_GetErrorMode() == 0) {
        return;
    }

    GFL_NET_ClearBeaconCallbacks();
    func_0200FAAC();

    {
        u8 *p = GFL_NET_GetInitParam();
        u8 v = p[0x65];
        if (v != 1 && v != 2 && v != 6) {
            return;
        }
    }

    {
        u32 *obj = (u32 *)GFL_NET_STATE_GetError();
        u32 field = obj[0xc / 4];

        if (field - 0x3f0 <= 1) {
            g[0x60 / 4] = 0x28;
            return;
        }
        if (field - 0x3f2 <= 4) {
            g[0x60 / 4] = 0xe;
            return;
        }

        g[0x60 / 4] = DWC_RAP_GetErrorMessageClass(obj[0], obj[1]);
    }
}
