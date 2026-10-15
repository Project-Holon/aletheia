/*
 * function: func_021B95B0
 * address: 0x021B95B0
 * region: ov223
 * isa: thumb
 * packet: pkt_ov223_021B95B0
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MTX_Identity33_ 0x0207ADC4 arm
 *   site 0x021BCB00 data a4
 */
typedef unsigned int u32;
typedef unsigned short u16;
struct Record { u16 id,pad; u32 translation[3],scale[3],matrix[9],flag; };
extern const char site[];
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void MTX_Identity33_(void *);
struct Record *func_021B95B0(u32 heap,u32 count)
{
    struct Record *p;
    u16 i;
    p=func_02030734(heap,count*sizeof(struct Record),1,site,654);
    for(i=0;i<count;i++) {
        p[i].translation[0]=0;
        p[i].translation[1]=0;
        p[i].translation[2]=0;
        p[i].scale[0]=4096;
        p[i].scale[1]=4096;
        p[i].scale[2]=4096;
        MTX_Identity33_(p[i].matrix);
    }
    return p;
}
