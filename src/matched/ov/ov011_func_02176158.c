/*
 * function: func_02176158
 * address: 0x02176158
 * packet: pkt_ov011_02176158
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Lever: split the offset arithmetic and the memset pointer calculation.
 * Once-300 permuter found this semantically unchanged spelling at candidate 74.
 * The three-iteration bound proves i stays 0..2; all call inputs are explicit.
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`offset = i;` before `offset = i;`). Game code has no line table, so
 * these were stand-ins. The plain single assignment gives EXACT in --lang
 * c99 and --lang c: the output bytes do not change. Older text in this
 * header that asks for the double assignment is superseded.
 *
 * symbols:
 *   func_02173E6C 0x02173E6C thumb ov011
 *   memset 0x02082BCC arm
 */
typedef unsigned char u8;
extern int func_02173E6C(int a, int b, int c);
extern void *memset(void *p, int value, unsigned int size);
void func_02176158(int a, u8 *p)
{
    unsigned int offset;
    int i;
    u8 *tmp;
    for (i = 0; i < 3; i++) {
        do {
            offset = i;
            offset = offset * 0x38;
            if (p[0xe8 + offset] != 0) {
                if (func_02173E6C(a, (int)((p + 0xe8) + offset), i) == 1) {
                    tmp = p + 0xe8;
                    tmp = tmp + offset;
                    memset(tmp, 0, 0x38);
                }
            }
        } while (0);
    }
}
