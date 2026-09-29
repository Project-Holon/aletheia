/*
 * function: func_021F0058
 * address:  0x021F0058
 * packet:   pkt_ov034_021F0058
 * region:   ov034
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F0058 0x021F0058 thumb
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200723C 0x0200723C thumb
 *   _s32_div_f    0x0209C2B0 arm
 */

extern int func_020120F4(int);
extern int func_02012EBC(int);
extern void func_0200723C(int, void *, void *);

void func_021F0058(char *p)
{
    int v;
    int r;

    r = func_02012EBC(func_020120F4(*(int *)p));
    *(int *)(p + 4) = r;
    func_0200723C(r, p + 0x114, p + 0x118);
    v = (*(int *)(p + 0x114) << 9) / 10;
    *(int *)(p + 0x120) = v;
    *(int *)(p + 0x11C) = v;
    *(short *)(p + 0x124) = 0;
    *(short *)(p + 0x126) = 0;
}
