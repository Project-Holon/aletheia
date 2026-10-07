/*
 * function: func_0689C7A4
 * address:  0x0689C7A4
 * packet:   pkt_ov095_0689C7A4
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0689C7F8  0x0689C7F8  thumb
 *   func_0689C808  0x0689C808  thumb
 *   func_0689C818  0x0689C818  thumb
 *   func_0689C828  0x0689C828  thumb
 *   func_0689C838  0x0689C838  thumb
 *   func_0689C848  0x0689C848  thumb
 *   func_0689C858  0x0689C858  thumb
 */

int func_0689C7F8(int a, int b);
int func_0689C808(int a, int b);
int func_0689C818(int a);
char *func_0689C828(int a, int b, int c);
void func_0689C838(char *a, int b, int c);
void func_0689C848(char *a, int b);
void func_0689C858(int a, char *b);

void func_0689C7A4(int p, int x)
{
    int n;
    char *q;

    if (func_0689C7F8(x, 0x15) && func_0689C808(0x41, 1)) {
        n = func_0689C818(x);
        q = func_0689C828(p, 4, n);
        func_0689C838(q + 4, 2, 0x2e6);
        func_0689C848(q + 4, n);
        func_0689C858(p, q);
    }
}
