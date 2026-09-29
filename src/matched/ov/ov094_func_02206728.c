/*
 * function: func_02206728
 * address:  0x02206728
 * packet:   pkt_ov094_02206728
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020457B0  0x020457B0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045808  0x02045808  arm
 *   func_0201EC64  0x0201EC64  thumb
 *   func_0201DE00  0x0201DE00  thumb
 *   func_0201DD78  0x0201DD78  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   func_02204C98  0x02204C98  thumb  ov094
 *   func_021F88F4  0x021F88F4  thumb  ov094
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021F88F4(void);
extern int func_0201EC64(int a);
extern void *func_020457B0(u32 size, u32 heap);
extern void *func_02045EC0(void *bank, u32 index);
extern void func_02045808(void *p);
extern void func_0201DE00(u8 *a, u8 *b, u8 *c);
extern void func_0201DD78(int a, int b, int c);
extern void func_0201EFA4(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void func_0201F250(int a, void *b, void *c);
extern void func_02204C98(void *a, int b, int *c, int *d);
extern void func_0201C7A4(int a, short b, int c, void *d, int e);
extern void func_0201ED04(int a);

void func_02206728(char *s, char *b)
{
    int h;
    void *v;
    void *w;
    int v18;
    int v14;
    u8 c[3];

    if (func_021F88F4() == 0)
        return;
    h = func_0201EC64(*(u16 *)(s + 0x240));
    v = func_020457B0(6, *(u16 *)(s + 0x240));
    w = func_02045EC0(*(void **)(s + 0x5c), 8);
    func_0201DE00(&c[2], &c[1], &c[0]);
    func_0201DD78(1, 2, 0);
    func_0201EFA4(h, 0, *(u8 *)(b + 0xc4), 2, 0, 1);
    func_0201F250(h, v, w);
    func_02204C98(v, *(int *)(s + 0x224), &v18, &v14);
    func_0201C7A4(*(int *)(s + 0x234), 12 - v18 / 2, 0, v, *(int *)(s + 0x224));
    func_0201DD78(c[2], c[1], c[0]);
    func_0201ED04(h);
    func_02045808(w);
    func_02045808(v);
}
