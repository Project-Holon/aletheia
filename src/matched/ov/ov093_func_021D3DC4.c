/*
 * function: func_021D3DC4
 * address:  0x021D3DC4
 * packet:   pkt_ov093_021D3DC4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021EFF74  0x021EFF74  data  a1
 *   func_021B9B94  0x021B9B94  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021D805C  0x021D805C  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D7B60  0x021D7B60  thumb  ov093
 *   func_021D3E70  0x021D3E70  thumb  ov093
 *   func_021D3EC8  0x021D3EC8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 d_021EFF74[];
struct Q1;
struct Unk021D62A8;
extern u8 func_021B9B94(struct Q1 *p);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern u32 func_021D805C(void *p, u32 n);
extern int func_021D59B4(u8 *p, int k);
extern u32 func_021D7B60(void *p, u32 b);
extern int func_021D3E70(void *s, void *m);
extern int func_021D3EC8(void *s, struct Unk021D62A8 *m);

u32 func_021D3DC4(u8 *a, void *b, void *c)
{
    u32 i;
    u32 r;
    u32 v;
    u32 lim;
    u32 off;
    u8 *t;

    lim = func_021B9B94(c);
    if (func_021D62C4(b, 0x13) != 0)
        return 0;
    for (i = 0; i < 4; i++) {
        if (d_021EFF74[i] < lim)
            break;
        off = i * 2;
        if (*(u16 *)(a + off + 0xe8) != 0) {
            r = 0;
            if (func_021D805C((void *)(u32)*(u16 *)(a + off + 0xe8), 0x29) != 0) {
                r = func_021D59B4(b, 0xd);
                if (r > func_021D7B60(b, 4))
                    continue;
                r = 1;
            } else {
                if (func_021D3E70((void *)(u32)*(u16 *)(a + off + 0xe8), b) != 0)
                    r = 1;
                else if (func_021D3EC8((void *)(u32)*(u16 *)(a + off + 0xe8), b) != 0)
                    r = 1;
            }
            if (r != 0) {
                t = a + 0xe8;
                v = *(u16 *)(t + off);
                *(u16 *)(t + off) = 0;
                return v;
            }
        }
    }
    return 0;
}
