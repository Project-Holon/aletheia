/*
 * function: func_021876E0
 * address:  0x021876E0
 * packet:   pkt_ov020_021876E0
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02187CEC  0x02187CEC  thumb  ov020
 *   func_02187A10  0x02187A10  thumb  ov020
 *   func_02187CFC  0x02187CFC  thumb  ov020
 *   func_020362DC  0x020362DC  arm
 *   func_02187D20  0x02187D20  thumb  ov020
 *   func_02187D28  0x02187D28  thumb  ov020
 *   func_02187CCC  0x02187CCC  thumb  ov020
 */

extern void func_02187CEC(char *o);
extern void func_02187A10(char *o, int k);
extern void func_02187CFC(char *o);
extern int func_020362DC(void);
extern int func_02187D20(char *o);
extern void func_02187D28(char *o);
extern void func_02187CCC(char *o, int *s);

int func_021876E0(void *unused, int *s, char *o)
{
    switch (*s) {
    case 0: func_02187CEC(o); break;
    case 1: case 3: break;
    case 2: func_02187A10(o, *s); break;
    case 4: func_02187A10(o, *s); break;
    case 5: func_02187CFC(o); return 1;
    }
    if (func_020362DC() & 1) { if (func_02187D20(o) == 0) func_02187D28(o); }
    *(int *)(o + 0x18) = *(int *)(o + 0x18) + 1;
    func_02187CCC(o, s);
    return 0;
}
