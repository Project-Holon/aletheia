/*
 * function: func_021C088C
 * address: 0x021C088C
 * packet: pkt_ov110_021C088C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: the RGB555 lerp is a static inline helper (u16 colour params, as ov105 func_021B8734)
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
static inline void lerp(u16 *p, int n, u16 a, u16 b)
{
 u8 r,g,blue; int dr,dg,db;
 g=(a&0x3E0)>>5;
 r=a&31;
 blue=(a&0x7C00)>>10;
 db=((u8)((b&0x7C00)>>10)-blue)*n>>12;
 dr=((u8)(b&31)-r)*n>>12;
 dg=((u8)((b&0x3E0)>>5)-g)*n>>12;
 *p=(u8)(r+dr)|((u8)(g+dg)<<5)|((u8)(blue+db)<<10);
}
void func_021C088C(u16 *ang, u16 *out, struct Rec *recs, u8 count)
{
    u8 i;
    s16 t;
    int a = *ang;
    if (a + 0x400 >= 0x10000)
        *ang = a - 0xFC00;
    else
        *ang = a + 0x400;
    t = (tbl_020A1B38[(*ang >> 4) * 2 + 1] + 0x1000) / 2;
    for (i = 0; i < count; i++) {
        lerp(&out[i], t, recs[i].c, recs[i].d);
        func_02061CA4(15, (recs[i].x << 5) + (recs[i].y << 1), &out[i], 2);
    }
}
