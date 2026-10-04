/*
 * function: func_02187CEC
 * address: 0x02187CEC
 * packet: pkt_ov020_02187CEC
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: unlabelled ov021 func_02189A50 at 0x02189A50, owned by Ilias;
 * sole setter body stores r1 at [r0 + 0x144], then returns. No code-start
 * witness. No owner source or ARM9/SDK matching performed.
 * 2026-10-04 (wD2 lane 02): witness filed: src/matched/ov/ov021_func_02189A50.c (EXACT, 8 bytes, str r1,[r0,#0x144]).
 * The symbols line already carries ov021. Expected EXACT after the integrator's manifest refresh.
 *
 * symbols:
 *   func_02189A50 0x02189A50 thumb ov021
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_02189A50(void *, int);
void func_02187CEC(char *p)
{
    void *q;
    q = *(void **)(p + 4);
    if (q != 0) func_02189A50(q, 1);
}
