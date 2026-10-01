/*
 * unit: yes
 * function: func_02211034,func_022110A4
 * address: 0x02211034
 * packet: pkt_ov198_02211034
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_02212138 0x02212138 data a4
 * Lead 112 bytes includes two pool words; follower 022110A4 is a
 * 20-byte independent push/pop swap leaf. No padding remains.
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 d_02212138[][6];
void func_02211034(u8 *p)
{
    unsigned i;
    if(*(int *)(*(u8 **)p+24)==1) {
        for(i=0;i<6;i++) (p+i)[0x1CC]=d_02212138[(*(u8 **)p)[28]][i];
    } else {
        for(i=0;i<6;i++) (p+i)[0x1CC]=i;
    }
    for(i=0;i<3;i++) (*(u8 **)p+i)[72]=255;
    for(i=0;i<2;i++) {
        *(u16 *)(p+i*4+0x249C)=255;
        *(u16 *)(p+i*4+0x249E)=255;
    }
}
void func_022110A4(u8 *p,unsigned a,unsigned b)
{
    u8 *q=p+0x1CC;
    u8 t=q[a];
    q[a]=q[b];
    q[b]=t;
}
