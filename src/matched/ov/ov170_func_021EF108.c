/*
 * function: func_021EF108
 * address: 0x021EF108
 * packet: pkt_ov170_021EF108
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F0020 0x021F0020 data a4
 *   TOUCHPANEL_HitPoint 0x02035D40 arm
 */
typedef struct { unsigned char a,b,c,d; } Bytes;
typedef struct { Bytes first, second; } Object;
extern const Bytes d_021F0020;
typedef unsigned int   u32;
struct Ctx;
extern u32 TOUCHPANEL_HitPoint(struct Ctx *ctx, u32 a, u32 b);
int func_021EF108(const char *p, unsigned n, int a, int b)
{
    Object obj;
    unsigned i;
    obj.second=d_021F0020;
    for(i=0;i<n;i++) {
        obj.first=*(Bytes *)(p+i*12+8);
        if(TOUCHPANEL_HitPoint((struct Ctx *)(&obj),a,b)!=-1) return i;
    }
    return -1;
}
