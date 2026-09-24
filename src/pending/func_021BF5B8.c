/*
 * function: func_021BF5B8
 * address:  0x021BF5B8
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   func_021C2270  0x021C2270  arm  ov114
 *
 * blocker:
 *   MATCH: bytes identical; the relocation to 0x02059F38 has no witness -- `bl 0x02059F38` is an
 *   .inst in ov114.s and the address carries no func_ label in asm/arm9/main.s or any overlay.
 *
 * Starts the 0x021C22xx job when the engine is idle; 0 when it is busy.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern int func_02059F38(void);
extern int func_021C2270(void);

int func_021BF5B8(void)
{
    if (func_02059F38() != 0)
        return 0;
    func_021C2270();
    return 1;
}
