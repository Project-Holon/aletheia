/*
 * file:     unit_0689C6E4.c
 * function: func_0689C6E4
 * address:  0x0689C6E4
 * packet:   pkt_ov095_0689C6E4
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb
 */

int BTL_POKEPARAM_HasSick(int a, int b);
void BTL_EVENT_OverwriteVar(int a, int b);

void func_0689C6E4(int unused, int x)
{
    if (BTL_POKEPARAM_HasSick(x, 0x15))
        BTL_EVENT_OverwriteVar(0x41, 1);
    if (BTL_POKEPARAM_HasSick(x, 0x1f))
        BTL_EVENT_OverwriteVar(0x41, 1);
    if (BTL_POKEPARAM_HasSick(x, 0x20) || BTL_POKEPARAM_HasSick(x, 0x1e))
        BTL_EVENT_OverwriteVar(0x51, 1);
}
