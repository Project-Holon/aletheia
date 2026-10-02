/*
 * function: func_021B468C
 * address:  0x021B468C
 * packet:   pkt_ov021_021B468C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02020D0C 0x02020D0C thumb
 *   func_020202FC 0x020202FC thumb
 *   func_0204B404 0x0204B404 arm
 *   func_021B4264 0x021B4264 thumb ov021
 *   func_021B3D60 0x021B3D60 thumb ov021
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern char *func_02020D0C(void *p);
extern void func_020202FC(u32 a, u16 *b, u16 *c);
extern void func_0204B404(u32 a, u16 *b, u32 c);
extern void func_021B4264(char *w, u32 a);
extern void func_021B3D60(char *w, u32 a);

void func_021B468C(u32 a, u32 idx)
{
    u16 v[4];
    char *w;
    char *t;

    w = func_02020D0C((void *)a);
    func_020202FC(a, &v[1], &v[0]);
    v[2] = 0xAC;
    v[3] = v[0] * 16 + 0x16;
    func_0204B404(*(u32 *)(w + 0x1C0), &v[2], 0);
    if (idx < 0x28) {
        t = w + 0x20;
        func_021B4264(w, *(u16 *)(t + idx * 8));
        func_021B3D60(w, *(u16 *)(t + idx * 8));
    } else {
        func_021B4264(w, 0xFFFF);
        func_021B3D60(w, 0xFFFF);
    }
}
