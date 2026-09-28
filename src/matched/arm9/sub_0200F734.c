/*
 * function: sub_0200F734
 * address:  0x0200F734
 * packet:   pkt_0200F6D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  wave 14 (2026-09-23): ONE site, the THM_CALL at +0x74 to
 *           func_02156460.  It is now a traced Thumb label in ov009 (ov010
 *           overlaps with non-code there, hence the ov009 hint below), but
 *           the call at 0x0200F7A8 is the only branch image-wide that
 *           reaches it, so the overlay `label` class refuses (no outside
 *           branch) and sole-ref/code does not cover overlay addresses.
 *           Needs a tool-side sole-ref/code rule for overlay labels, or a
 *           matched ov009 entry covering 0x02156460.  func_0203D864 now
 *           resolves.
 *
 * symbols:
 *   func_0203CD98  0x0203CD98  arm
 *   func_0203D880  0x0203D880  arm
 *   func_020393D0  0x020393D0  arm
 *   func_0203C990  0x0203C990  arm
 *   func_0203D864  0x0203D864  arm
 *   func_0200FAAC  0x0200FAAC  thumb
 *   func_0203D798  0x0203D798  arm
 *   func_0203CA98  0x0203CA98  arm
 *   func_02156460  0x02156460  thumb  ov009
 *
 * A gated status update: bails out early if the module-wide object at
 * 0x0214617C already has its +0x2c flag set, or if func_0203CD98 does not
 * report state 1, or if none of three link-state probes says yes. Once
 * past the gate it re-derives a status byte from func_0203D798's returned
 * object at offset +0x65 (only 1, 2 or 6 continue), then compares a field
 * of the object func_0203CA98 returns against two small windows and stores
 * a fixed error code into the global's +0x60 for either, falling through
 * to a real computation (func_02156460 on the object's first two words)
 * otherwise.
 *
 * Every concrete byte matches; func_0203D864 and func_02156460 are each
 * called from exactly this one site in the whole ROM, so both stay
 * unresolved relocations under the honesty rule.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200F734.c \
 *       --func sub_0200F734 --addr 0x0200F734 --cc 1.1p1
 *
 * The `matched` class does not reach it: neither func_0203D864 nor
 * func_02156460 is matched, so no EXACT entry covers either address.  Both live
 * outside the matched region so far.
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u32  func_0203CD98(void);
extern u32  func_0203D880(void);
extern u32  func_020393D0(void);
extern u32  func_0203C990(void);
extern void func_0203D864(void);
extern void func_0200FAAC(void);
extern u8  *func_0203D798(void);
extern u32 *func_0203CA98(void);
extern u32  func_02156460(u32 a, u32 b);

void sub_0200F734(void)
{
    u32 *g = (u32 *)0x0214617C;

    if (g[0x2c / 4] != 0) {
        return;
    }
    if (func_0203CD98() != 1) {
        return;
    }
    if (func_0203D880() == 0 && func_020393D0() == 0 && func_0203C990() == 0) {
        return;
    }

    func_0203D864();
    func_0200FAAC();

    {
        u8 *p = func_0203D798();
        u8 v = p[0x65];
        if (v != 1 && v != 2 && v != 6) {
            return;
        }
    }

    {
        u32 *obj = func_0203CA98();
        u32 field = obj[0xc / 4];

        if (field - 0x3f0 <= 1) {
            g[0x60 / 4] = 0x28;
            return;
        }
        if (field - 0x3f2 <= 4) {
            g[0x60 / 4] = 0xe;
            return;
        }

        g[0x60 / 4] = func_02156460(obj[0], obj[1]);
    }
}
