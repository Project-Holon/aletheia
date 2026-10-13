/*
 * file:     unit_02082198.c
 * function: MI_InitWramManager
 * address:  0x02082198
 * packet:   pkt_02082198
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02085D3C 0x02085D3C arm
 *   MIi_InitWramManager 0x02730468 arm twl
 */

extern int func_02085D3C(void);
extern void MIi_InitWramManager(void);

void MI_InitWramManager(void)
{
    if (func_02085D3C()) {
        MIi_InitWramManager();
    }
}
