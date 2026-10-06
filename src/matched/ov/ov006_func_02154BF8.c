/*
 * function: func_02154BF8
 * address:  0x02154BF8
 * packet:   pkt_ov006_02154BF8
 * region:   ov006
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_02154B08  0x02154B08  thumb  ov006
 *   func_021544F0  0x021544F0  thumb  ov006
 */

typedef unsigned int   u32;
struct Desc;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void func_02154B08(void *obj_in, void *p, int a, int b);
int func_021544F0(void *evt, u32 *state, char *obj);

int func_02154BF8(int a, int b, int c)
{
    int h;

    h = (int)func_020122C0((void *)a, 0, func_021544F0, 0x174);
    func_02154B08((void *)h, (void *)a, b, c);
    return h;
}
