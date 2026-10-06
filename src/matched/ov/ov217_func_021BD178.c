/*
 * function: func_021BD178
 * address: 0x021BD178
 * packet: pkt_ov217_021BD178
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status:   EXACT
 *
 * Base address held in a u32 local and cast per use (reloads the pool word at each site); colour expression a | (c | b).
 *
 * symbols:
 *   _s32_div_f 0x0209C0A4 arm
 *   func_0204384C 0x0204384C arm
 *   func_020439A0 0x020439A0 arm
 *   func_020437AC 0x020437AC arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201C7D0 0x0201C7D0 thumb
 *   d_021C3350 0x021C3350 data a4
 *   d_021C349C 0x021C349C data a4
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef unsigned int u32;
struct Tab { int v[3][10]; };
struct G {
    char pad0[0xc];
    u32 f0c;
    u32 f10;
    int f14;
    int f18;
    u8 f1c;
    u8 f1d;
    u8 f1e;
    u8 pad1f;
    u32 f20;
    u32 f24;
};
struct Bmp;
struct MsgBank;
struct Obj020437AC;
extern void func_020307B0(void *p);
struct S { char pad0[8]; u16 h8; char pad1[2]; u32 f0c; u32 arr[0x144 / 4 - 4]; void *f144; };
extern int _s32_div_f(int, int);
extern const struct Tab d_021C3350;
extern const struct G d_021C349C;
extern struct Bmp *func_0204384C(u32 arc, u32 member, u32 heap2, u32 heap);
extern void func_020439A0(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);
extern void func_020437AC(struct Obj020437AC *p);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201C7D0(void *x, s16 y, s16 z, void *s, void *w, u16 v);

#define G ((const struct G *)gb)
void func_021BD178(struct S *p)
{
    u32 gb = (u32)&d_021C349C;
    struct Tab tab = d_021C3350;
    int i;
    int j;
    void *heap;
    void *res;
    u16 color;
    heap = func_0204384C(G->f20, G->f24, 0, p->h8);
    for (i = 0; i < 3; i++) {
        int y = i * 8;
        for (j = 0; j < 10; j++) {
            func_020439A0(heap, p->f144, (tab.v[i][j] % 3) * 8, (tab.v[i][j] / 3) * 8, j * 8, y, 8, 8, 0);
        }
    }
    func_020437AC(heap);
    color = (G->f1e & 0x1f) | (((G->f1c & 0x1f) << 10) | ((G->f1d & 0x1f) << 5));
    res = func_02045EC0((void *)p->arr[G->f0c], G->f10);
    func_0201C7D0(p->f144, (s16)G->f14, (s16)G->f18, res, (void *)p->f0c, color);
    func_020307B0(res);
}
