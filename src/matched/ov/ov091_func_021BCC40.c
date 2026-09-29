/*
 * function: func_021BCC40
 * address:  0x021BCC40
 * packet:   pkt_ov091_021BCC40
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021BB97C  0x021BB97C  thumb  ov091
 *   func_021BB99C  0x021BB99C  thumb  ov091
 *   func_021B9788  0x021B9788  thumb  ov091
 *   func_021BB98C  0x021BB98C  thumb  ov091
 *   func_021B9E44  0x021B9E44  thumb  ov091
 */

extern void func_021BB97C(int, int);
extern void func_021BB99C(int, int, int, int);
extern void func_021B9788(int, int, int, void (*)(int));
extern void func_021BB98C(int, int);
extern void func_021B9E44(int);

void func_021BCC40(int p, int id)
{
    *(int *)(*(int *)(p + 0x280) + 0x40) = 10;
    func_021BB97C(p, *(int *)(p + 0x150));
    func_021BB99C(p, *(int *)(p + 0x150), 0, *(int *)(p + 0x38));
    func_021B9788(p, id, 1, func_021B9E44);
    func_021BB98C(p, *(int *)(p + 0x150));
}
