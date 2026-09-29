/*
 * function: func_021EEA58
 * address:  0x021EEA58
 * packet:   pkt_ov093_021EEA58
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_02030734   0x02030734  arm
 *   d_021F6388     0x021F6388  data  ov093  a4
 *   d_021F3AE8     0x021F3AE8  data  ov093  a4
 *   d_021F6384     0x021F6384  data  ov093  a4
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

typedef struct {
    u32 f00;
    u8 pad[8];
    u8 lo : 4;
    u8 hi : 4;
    u8 idx;
    u8 e;
    u8 f;
} Obj;

extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern Obj *d_021F6388[];
extern const char d_021F3AE8[];
extern int d_021F6384;

Obj *func_021EEA58(u32 a, int idx, u32 v, u32 heap)
{
    Obj *o;

    o = 0;
    if (d_021F6388[idx] == 0) {
        o = sub_02030734(heap, 0xbd0, 1, d_021F3AE8, 0x7e);
        o->f00 = a;
        o->idx = idx;
        o->hi = (u8)v;
        o->e = 0;
        o->f = 0;
        o->lo = 0;
    }
    if (d_021F6384 == 0) {
        if (d_021F6388[idx] == 0)
            d_021F6388[idx] = o;
        return d_021F6388[idx];
    }
    d_021F6388[idx] = o;
    return o;
}
