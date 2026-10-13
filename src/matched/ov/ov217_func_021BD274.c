/*
 * function: func_021BD274
 * address: 0x021BD274
 * packet: pkt_ov217_021BD274
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status:   EXACT
 *
 * Same lever as 021BD178: u32 base local cast per use, colour a | (c | b).
 *
 * symbols:
 *   _s32_div_f 0x0209C0A4 arm
 *   BMP_CreateFromArchive 0x0204384C arm
 *   BMP_Blit 0x020439A0 arm
 *   BMP_Delete 0x020437AC arm
 *   func_02045EC0 0x02045EC0 arm
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   d_021C32D8 0x021C32D8 data a4
 *   d_021C34C8 0x021C34C8 data a4
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
extern u32 func_020307B0(void *p);
struct S { char pad0[8]; u16 h8; char pad1[2]; u32 f0c; u32 arr[0x148 / 4 - 4]; void *f148; };
extern int _s32_div_f(int, int);
extern const struct Tab d_021C32D8;
extern const struct G d_021C34C8;
extern struct Bmp *BMP_CreateFromArchive(u32 arc, u32 member, u32 heap2, u32 heap);
extern void BMP_Blit(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);
extern void BMP_Delete(struct Obj020437AC *p);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void PRINTSYS_PrintColor(void *x, s16 y, s16 z, void *s, void *w, u16 v);

#define G ((const struct G *)gb)
void func_021BD274(struct S *p)
{
    u32 gb = (u32)&d_021C34C8;
    struct Tab tab = d_021C32D8;
    int i;
    int j;
    void *heap;
    void *res;
    u16 color;
    heap = BMP_CreateFromArchive(G->f20, G->f24, 0, p->h8);
    for (i = 0; i < 3; i++) {
        int y = i * 8;
        for (j = 0; j < 10; j++) {
            BMP_Blit(heap, p->f148, (tab.v[i][j] % 3) * 8, (tab.v[i][j] / 3) * 8, j * 8, y, 8, 8, 0);
        }
    }
    BMP_Delete(heap);
    color = (G->f1e & 0x1f) | (((G->f1c & 0x1f) << 10) | ((G->f1d & 0x1f) << 5));
    res = func_02045EC0((void *)p->arr[G->f0c], G->f10);
    PRINTSYS_PrintColor(p->f148, (s16)G->f14, (s16)G->f18, res, (void *)p->f0c, color);
    func_020307B0(res);
}
