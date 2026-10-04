/*
 * function: func_021C088C
 * address: 0x021C088C
 * packet: pkt_ov110_021C088C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: DIFF
 * note: 2026-10-04 (wD1 lane17): DIFF. Sibling of 021BD348 (same lerp). Params (u16 *ang, u16 *out, struct{u16 x,y,c,d} *recs, u8 count) and the head up to the loop match. In the loop orig holds the record pointer in r7 (recs+i*8) and i*2 in ip; ours keeps i*2 in r7 and rebuilds the record pointer in r0. Combine order is bh | ((g<<5)|r) with blue, red, green lerps in that order. Tried: extraction order, combine order, u8 count/i.
 * symbols:
 *   func_02061CA4 0x02061CA4 arm
 *   tbl_020A1B38 0x020A1B38 data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
struct Rec { u16 x, y, c, d; };
extern s16 tbl_020A1B38[];
extern void func_02061CA4(u32 a, u32 b, void *src, u32 n);
void func_021C088C(u16 *ang, u16 *out, struct Rec *recs, u8 count)
{
    u8 i;
    s16 t;
    int a = *ang;
    if (a + 0x400 >= 0x10000)
        *ang = a - 0xFC00;
    else
        *ang = a + 0x400;
    i = 0;
    t = (tbl_020A1B38[(*ang >> 4) * 2 + 1] + 0x1000) / 2;
    for (i = 0; i < count; i++) {
        struct Rec *r = &recs[i];
        int c = r->c;
        u8 cg = (c & 0x3E0) >> 5;
        u8 cr = c & 0x1F;
        int d = r->d;
        u8 cb = (c & 0x7C00) >> 10;
        u8 db = (d & 0x7C00) >> 10;
        u8 dr = d & 0x1F;
        u8 dg = (d & 0x3E0) >> 5;
        u32 bh = (u8)(cb + (((db - cb) * t) >> 12)) << 10;
        u8 rr = cr + (((dr - cr) * t) >> 12);
        u8 g = cg + (((dg - cg) * t) >> 12);
        out[i] = bh | ((g << 5) | rr);
        func_02061CA4(15, (recs[i].x << 5) + (r->y << 1), &out[i], 2);
    }
}
