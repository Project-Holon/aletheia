/*
 * function: func_02174514
 * address:  0x02174514
 * packet:   pkt_ov011_02174514
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Blocked: MATCH*, two unlabelled arm9 leaves have no witness outside the range (Ilias's):
 *   0x0202E7E0 thumb `int f(int *p) { return *p; }` (ldr r0,[r0]; bx lr)
 *   0x0202E7C4 thumb leaf, ldm/stm struct copy of 0x18 bytes (words at 0202E7C4..0202E7DC)
 * Everything else in the file compiles byte-correct (88 of 90 B listed, tail is pad).
 *
 * symbols:
 *   func_02026478  0x02026478  thumb
 *   func_02012F20  0x02012F20  thumb
 *   func_02012B38  0x02012B38  thumb
 *   func_02014484  0x02014484  thumb
 *   func_0202E7E0  0x0202E7E0  thumb
 *   func_02012950  0x02012950  thumb
 *   func_0202E7C4  0x0202E7C4  thumb
 */

int func_02026478(int a);
int func_02012F20(int a);
void func_02012B38(int a);
int func_02014484(void);
int func_0202E7E0(int a);
int func_02012950(int a, int b);
void func_0202E7C4(int a, int b, int c);

void func_02174514(int a, int b, int *c, char *d)
{
    int p;
    int q;
    int t;

    p = func_02026478(((int *)d)[1]);
    q = func_02012F20(p);
    if ((unsigned char)d[0x8fb] & (1 << a)) {
        func_02012B38(p);
        if (func_02014484() == 1) {
            t = func_0202E7E0(q);
            if (t == 0 || t == 3) {
                func_0202E7C4(q, *c, func_02012950(p, a));
            }
        }
    }
}
