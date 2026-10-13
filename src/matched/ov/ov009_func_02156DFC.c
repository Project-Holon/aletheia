/*
 * function: DWC_RAPCOMMON_InitDwcWithNotice
 * address:  0x02156DFC
 * packet:   pkt_ov009_02156DFC
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The pooled 0x11 is the overlay id of ov017 (absolute linker symbol, see
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md): load
 * ov017, run ERROR_SCREEN_ShowAndWait there, unload it.
 *
 * symbols:
 *   abs_id_11  0x00000011  data
 *   DWC_RAPCOMMON_RunDwcInit  0x02157108  thumb  ov009
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   ERROR_SCREEN_ShowAndWait  0x021B6100  thumb  ov017
 */

typedef unsigned short u16;

extern unsigned char abs_id_11[];
extern int DWC_RAPCOMMON_RunDwcInit(u16 a);
extern int func_02034AC4(signed int id);
extern void func_02034A5C(int id);
extern void ERROR_SCREEN_ShowAndWait(void);

void DWC_RAPCOMMON_InitDwcWithNotice(int a)
{
    if (DWC_RAPCOMMON_RunDwcInit(a) == 3) {
        func_02034AC4((int)abs_id_11);
        ERROR_SCREEN_ShowAndWait();
        func_02034A5C((int)abs_id_11);
    }
}
