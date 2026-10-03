/*
 * function: func_021FBAF8
 * address: 0x021FBAF8
 * packet: pkt_ov094_021FBAF8
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_0201134C 0x0201134C thumb
 *   func_021FCF2C 0x021FCF2C thumb ov094
 *   func_0207C768 0x0207C768 arm
 *   func_02030DA8 0x02030DA8 arm
 *   func_021F896C 0x021F896C thumb ov094
 *   func_021FE594 0x021FE594 thumb ov094
 *   func_021FE690 0x021FE690 thumb ov094
 *   d_0220AE68 0x0220AE68 data ov094 a1
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern char d_0220AE68[];
extern int *func_02030734(u16, u32, int, const char *, u16);
extern u32 func_0201134C(void *);
extern int func_021FCF2C(int, int);
extern u32 func_0207C768(u32 a, u32 b);
extern void *func_02030DA8(void *, void (*)(void *, int *), int *, int);
extern void func_021F896C(void *h, void (*cb)(void *), int arg);
extern void func_021FE594(void *, int *);
extern void func_021FE690(void *);
extern float _fflt(int);
extern float _fadd(float, float);
extern float _fsub(float, float);
extern int _ffix(float);
int func_021FBAF8(void *a, char *s)
{
    int *p;
    int x;
    int y;
    int diff;
    float f;
    float g;
    p = func_02030734((*(u16 *)(s + 0x238) & 0x7fff) | 0x8000, 0x38, 0, d_0220AE68, 0xf17);
    p[0] = (int)s;
    p[1] = func_0201134C(a);
    p[2] = func_0201134C(a);
    p[3] = 2;
    x = func_021FCF2C((int)a, func_0201134C(a));
    y = func_021FCF2C((int)a, func_0201134C(a));
    p[4] = (x & 1) ? 127 : -128;
    p[5] = (y & 1) ? 127 : -128;
    p[8] = func_0201134C(a);
    p[9] = func_0201134C(a);
    p[10] = p[9];
    p[11] = 0;
    p[12] = func_0201134C(a);
    p[13] = func_0201134C(a) * 2;
    if (p[2] == 1 && p[13] == 0) p[13] = 2;
    if (p[4] > 0) p[6] = _ffix(_fadd(0.5f, _fflt(p[4] << 12)));
    else p[6] = _ffix(_fsub(_fflt(p[4] << 12), 0.5f));
    if (p[9] > 0) f = _fadd(0.5f, _fflt(p[9] << 12));
    else f = _fsub(_fflt(p[9] << 12), 0.5f);
    diff = p[5] - p[4];
    if (diff > 0) g = _fadd(0.5f, _fflt(diff << 12));
    else g = _fsub(_fflt(diff << 12), 0.5f);
    x = _ffix(g);
    y = _ffix(f);
    p[7] = func_0207C768(x, y);
    func_021F896C(func_02030DA8(*(void **)(s + 8), func_021FE594, p, 0), func_021FE690, 1);
    *(u32 *)s |= 8;
    return *(int *)(s + 0x23c);
}
