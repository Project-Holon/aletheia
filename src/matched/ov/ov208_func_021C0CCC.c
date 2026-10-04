/*
 * function: func_021C0CCC
 * address:  0x021C0CCC
 * packet:   pkt_ov208_021C0CCC
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C0C14  0x021C0C14  thumb  ov208
 *   func_021BBB3C  0x021BBB3C  thumb  ov072
 *   func_0204B404  0x0204B404  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   data_021C8554  0x021C8554  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 x;
    u16 y;
} Pt;

extern const Pt data_021C8554;

extern u8   func_021C0C14(u16 *heap, u8 *p, int key);
extern unsigned short func_021BBB3C(char *p, int a, int b);
extern void func_0204B404(u32 obj, Pt *pos, int n);
struct Obj;
extern void func_0204B3DC(struct Obj *obj, unsigned int on);

#define W(o) (*(u32 *)(p + (o)))

void func_021C0CCC(u16 *heap, u8 *p, int key)
{
    Pt pt = data_021C8554;

    if (p[0x79] == 0xff)
        p[0x79] = func_021C0C14(heap, p, key);
    if (p[0x79] != 0xff) {
        pt.x = func_021BBB3C((char *)W(0x3c8), p[0x79], 2);
        pt.y = func_021BBB3C((char *)W(0x3c8), p[0x79], 3);
    }
    func_0204B404(W(0xcc), &pt, 0);
    func_0204B3DC((struct Obj *)W(0xcc), 1);
}
