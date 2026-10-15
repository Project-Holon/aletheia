/*
 * function: BOX2_UI_HitTableTrg
 * address: 0x021EF048
 * packet: pkt_ov170_021EF048
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F0020 0x021F0020 data a4
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 */
typedef struct { unsigned char a,b,c,d; } Bytes;
typedef struct { Bytes first, second; } Object;
extern const Bytes d_021F0020;
extern int TOUCHPANEL_HitTrg(const void *);
int BOX2_UI_HitTableTrg(const char *p, unsigned n)
{
    Object obj;
    unsigned i;
    obj.second=d_021F0020;
    for(i=0;i<n;i++) {
        obj.first=*(Bytes *)(p+i*12+8);
        if(TOUCHPANEL_HitTrg(&obj)!=-1) return i;
    }
    return -1;
}
