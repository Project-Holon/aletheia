/*
 * function: func_021BCF4C
 * address: 0x021BCF4C
 * packet: pkt_ov208_021BCF4C
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: MATCH
 * symbols:
 *   func_021BD0A8 0x021BD0A8 thumb
 * 2026-10-02: blocked on the relocation to func_021BD0A8, an unlabelled Thumb getter (ldr r0,[r0]; bx lr).
 * Matched as ov208_func_021BD0A8.c, but 0x021BD0A8 is not a function start in layout (figure move).
 */
extern int func_021BD0A8(int *p);
int func_021BCF4C(char *p)
{
    return func_021BD0A8((int *)(p + 4));
}
