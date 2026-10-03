/*
 * function: func_02157AF0
 * address:  0x02157AF0
 * packet:   pkt_ov010_02157AF0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_0203D3F8  0x0203D3F8  arm
 *   func_02157960  0x02157960  thumb
 *   func_02157AC8  0x02157AC8  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;

struct Entry;

extern struct Entry *func_020399A8(void);
extern int func_02039CB4();
extern int func_0203D3F8();
extern void func_02157960();
extern void func_02157AC8(int *p);

void func_02157AF0(int *p)
{
    u8 *b = (u8 *)p;
    if (func_02039CB4(func_020399A8(), 0x18, (u8)p[0]) == 0)
        return;
    if (b[0x675] != 0) {
        if (b[0x676] == 1) {
            int *e = (int *)(b + 8 + b[0x677] * 16);
            int k = 0xFF;
            if (func_0203D3F8(func_020399A8(), 0xFF, (unsigned)(p[0] << 24) >> 16, e[0], e[1], 0, 0, 1) == 0)
                return;
            func_02157960(p, (void *)func_02157AC8, k + 0x2F);
            return;
        }
        func_02157960(p, (void *)func_02157AC8, 0x133);
        return;
    }
    func_02157960(p, (void *)func_02157AC8, 0x137);
}
