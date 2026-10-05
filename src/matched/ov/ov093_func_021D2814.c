/*
 * function: func_021D2814
 * address: 0x021D2814
 * packet: pkt_ov093_021D2814
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: sole-ref/code cannot attest unlabelled ov094:021F7E94 tail stub; owner Ilias.
 * evidence: Thumb 01 49 02 4b 18 47 c0 46; pools 0x26e and 0x021F7A29. No ARM9/SDK blocker work.
 * symbols:
 *   func_021B8E70 0x021B8E70 thumb ov093
 *   func_021F7E94 0x021F7E94 thumb ov094
 *   func_021F7EB4 0x021F7EB4 thumb ov094
  * note 2026-10-05 (D8 lane16): re-verified MATCH. Callee 0x021F7E94 is an ov094 Thumb tail stub (pool 0x26E, 0x021F7A29); other overlay, not filed. Integrator: seed label.
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 func_021B8E70(void *, u8);
extern void func_021F7E94(u8);
extern int func_021F7EB4(void);
int func_021D2814(char *p, int *state, unsigned int *q)
{
    switch (*state) {
    case 0:
        func_021F7E94(func_021B8E70(*(void **)p, q[0]));
        (*state)++;
        break;
    case 1:
        if (func_021F7EB4() == 0) return 1;
        break;
    }
    return 0;
}
