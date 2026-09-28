/*
 * function: func_021D5888
 * address:  0x021D5888
 * packet:   pkt_ov118_021D5888
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02015EB0  0x02015EB0  thumb
 *   func_02015C48  0x02015C48  thumb
 *   func_02015E04  0x02015E04  thumb
 *   func_02015C94  0x02015C94  thumb
 *   func_02015CAC  0x02015CAC  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;

typedef struct {
    s32 x, y, z;
} Vec;

extern void func_02015EB0(u32);
extern void func_02015C48(u32, Vec *);
extern void func_02015E04(u32);
extern void func_02015C94(u32, Vec *);
extern void func_02015CAC(u32, Vec *);

void func_021D5888(u8 *p, int idx)
{
    u32 *obj = (u32 *)(p + 0x844);
    Vec v;

    func_02015EB0(obj[idx]);
    v.x = 0;
    v.y = -0x17000;
    v.z = 0xA000;
    func_02015C48(obj[idx], &v);
    func_02015E04(obj[idx]);
    func_02015C94(obj[idx], &v);
    if (v.x < 0) {
        v.x = -0x10000;
    } else {
        v.x = 0x10000;
    }
    v.y = 0x10000;
    v.z = 0x1000;
    func_02015CAC(obj[idx], &v);
}
