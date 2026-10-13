/*
 * function: FRAME_LIST_GetScrollBarRow
 * address:  0x021B8A44
 * packet:   pkt_ov067_021B8A44
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   TOUCHPANEL_GetPointCont  0x02035CB8  arm
 *   func_0202EDE4  0x0202EDE4  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S {
    u8 _0[0x12];
    u8 f12;
    u8 _13[0x64 - 0x13];
    u16 f64;
    u8 _66[0x7d - 0x66];
    u8 f7d;
    u8 f7e;
    u8 _7f;
    int f80;
};

extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);
extern u32 func_0202EDE4(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);

u32 FRAME_LIST_GetScrollBarRow(struct S *s)
{
    int a;
    int b;

    if (TOUCHPANEL_GetPointCont((u32 *)(&a), (u32 *)(&b)) == 0)
        b = s->f80;
    s->f80 = -1;
    return func_0202EDE4(s->f64, b, s->f7d, s->f7e, s->f12);
}
