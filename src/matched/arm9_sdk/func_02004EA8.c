/*
 * function: func_02004EA8
 * address:  0x02004EA8
 * packet:   pkt_02004EA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      _start_AutoloadDoneCallback (crt0.HYB.TWL.o; no catalogue row)
 *
 * notes:    a 4-byte `bx lr`; INITi_DoAutoload's crt0 relocation at +0x188
 *           (PC24 _start_AutoloadDoneCallback) is the `b` at 0x02004D3C that
 *           lands here.  Seeded in layout/function_starts.txt.
 */

void func_02004EA8(void)
{
}
