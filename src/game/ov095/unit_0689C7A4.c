/*
 * file:     unit_0689C7A4.c
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
 *   func_021C8838  0x021C8838  thumb
 *   func_021C8860  0x021C8860  thumb
 *   func_021C88A4  0x021C88A4  thumb
 *   func_021C88C8  0x021C88C8  thumb
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb
 */

int BTL_POKEPARAM_HasSick(int a, int b);
int BTL_EVENT_OverwriteVar(int a, int b);
int BTL_POKEPARAM_GetPokeId(int a);
char *func_021C88A4(int a, int b, int c);
void func_021C8838(char *a, int b, int c);
void func_021C8860(char *a, int b);
void func_021C88C8(int a, char *b);

void func_0689C7A4(int p, int x)
{
    int n;
    char *q;

    if (BTL_POKEPARAM_HasSick(x, 0x15) && BTL_EVENT_OverwriteVar(0x41, 1)) {
        n = BTL_POKEPARAM_GetPokeId(x);
        q = func_021C88A4(p, 4, n);
        func_021C8838(q + 4, 2, 0x2e6);
        func_021C8860(q + 4, n);
        func_021C88C8(p, q);
    }
}
