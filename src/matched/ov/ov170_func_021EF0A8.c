/*
 * function: func_021EF0A8
 * address: 0x021EF0A8
 * packet: pkt_ov170_021EF0A8
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F0020 0x021F0020 data a4
 *   TOUCHPANEL_HitCont 0x02035BA4 arm
 */
typedef struct { unsigned char a,b,c,d; } Bytes;
typedef struct { Bytes first, second; } Object;
extern const Bytes d_021F0020;
extern int TOUCHPANEL_HitCont(const void *);
int func_021EF0A8(const char *p, unsigned n)
{
    Object obj;
    unsigned i;
    obj.second=d_021F0020;
    for(i=0;i<n;i++) {
        obj.first=*(Bytes *)(p+i*12+8);
        if(TOUCHPANEL_HitCont(&obj)!=-1) return i;
    }
    return -1;
}
