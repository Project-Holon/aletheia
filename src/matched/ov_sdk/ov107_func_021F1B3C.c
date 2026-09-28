/*
 * function: MB_CommSetChildStateCallback
 * address:  0x021F1B3C
 * packet:   pkt_ov107_021F1B3C
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: TwlSDK/libmb.TWL.HYB.a(mb_child.o).  Rebuilt from the Rom object's
 * DWARF (decl_line 143, local enabled) and its decoded line map
 * (144/149/151/153/154 at +0x0/+0x8/+0xc/+0x1c/+0x20).
 *
 * symbols:
 *   mbc   0x021F6FA0  data
 */
typedef unsigned long u32;

extern u32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32 enabled);
extern void *mbc;

typedef void (*WMCallback)(u32, void *);

void MB_CommSetChildStateCallback(WMCallback callback)
{
    u32 enabled;

    enabled = OS_DisableInterrupts();
    *(WMCallback *)((char *)mbc + 0x14E4) = callback;
    OS_RestoreInterrupts(enabled);
}
