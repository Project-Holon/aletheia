/*
 * function: func_021ED6E4
 * address:  0x021ED6E4
 * packet:   pkt_ov170_021ED6E4
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B838 0x0204B838 arm
 *   func_0204B864 0x0204B864 arm
 *   func_021EC000 0x021EC000 thumb
 *   func_021EC030 0x021EC030 thumb
 *   func_021EC048 0x021EC048 thumb
 */

extern int func_0204B838(int a);
extern unsigned func_0204B864(int a);
extern void func_021EC000(char *p, int i, int v);
extern void func_021EC030(char *p, int i, int c);
extern void func_021EC048(char *p, int i, int c);

void func_021ED6E4(char **p, int v)
{
    int j;
    for (j = 0; j < 8u; j++) {
        if (*(int *)(p[11] + j * 4 + 0x9FD4) != 0) {
            func_021EC000(p[11], j + 0x58, v);
            if (v == 1 && ((unsigned char *)p)[0x16] != 0xFF) {
                unsigned char k = *(unsigned char *)(p[11] + ((unsigned char *)p)[0x16] + 0x3DD2);
                func_021EC048(p[11], j + 0x58, func_0204B838(*(int *)(p[11] + k * 4 + 0x9E74)) + 1);
                func_021EC030(p[11], j + 0x58, func_0204B864(*(int *)(p[11] + k * 4 + 0x9E74)));
            }
        }
    }
}
