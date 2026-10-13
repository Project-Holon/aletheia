/*
 * function: MI_FreeWramSlot
 * address:  0x02730BD8
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   MIi_DoFreeWramSlot 0x02730C2C arm twl
 *   MIi_LockWramManagerDI 0x02731234 arm twl
 *   MIi_UnlockWramManagerRI 0x02731254 arm twl
 */
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 MIi_DoFreeWramSlot(u32 ch, int start, int n, u32 val);
extern u32 MIi_LockWramManagerDI(u16 *p);
extern void MIi_UnlockWramManagerRI(u32 id, u32 irq);

u32 MI_FreeWramSlot(u32 ch, int start, int n, u32 val)
{
    u16 sv;
    u32 irq, r;

    irq = MIi_LockWramManagerDI(&sv);
    r = MIi_DoFreeWramSlot(ch, start, n, val);
    MIi_UnlockWramManagerRI(sv, irq);
    return r;
}
