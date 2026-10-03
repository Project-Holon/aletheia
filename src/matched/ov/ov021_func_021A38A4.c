/*
 * function: func_021A38A4
 * address:  0x021A38A4
 * packet:   pkt_ov021_021A38A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D80C  0x0216D80C  thumb  ov010
 *   func_0216D854  0x0216D854  thumb  ov010
 *   func_0216D818  0x0216D818  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D824  0x0216D824  thumb  ov010
 *   func_0216D844  0x0216D844  thumb  ov010
 *   func_0216D85C  0x0216D85C  thumb  ov010
 *   func_0216D874  0x0216D874  thumb  ov010
 *   func_0216D89C  0x0216D89C  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    int x;
    int y;
    int z;
} Vec021A38A4;

u16 func_0216D83C(u32 h);
void func_0216D80C(u32 h, u16 v);
u16 func_0216D854(u32 h);
void func_0216D818(u32 h, u16 v);
u16 func_0216D86C(u32 h);
void func_0216D824(u32 h, u16 v);
void func_0216D844(u32 h, short v);
void func_0216D85C(u32 h, short v);
void func_0216D874(int a0, int a1);
void func_0216D89C(u32 h, Vec021A38A4 *v);

void func_021A38A4(u8 *p, Vec021A38A4 *v)
{
    int x = (v->x >> 4) / 4096;
    int y = (v->y >> 4) / 4096;
    int z = (v->z >> 4) / 4096;
    u32 h = *(u32 *)(p + 0x1C);

    func_0216D80C(h, func_0216D83C(h));
    func_0216D818(h, func_0216D854(h));
    func_0216D824(h, func_0216D86C(h));
    func_0216D844(h, (short)x);
    func_0216D85C(h, (short)y);
    func_0216D874(h, (short)z);
    func_0216D89C(h, v);
}
