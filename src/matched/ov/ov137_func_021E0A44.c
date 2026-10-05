/*
 * function: func_021E0A44
 * address: 0x021E0A44
 * packet: pkt_ov137_021E0A44
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: (pass 2 2026-10-06 P2L40) i zeroed before the angle statement, the row offset
 *   count*10 in a named local as in the twin func_021DEE4C, and a separate local for the
 *   insertion-sort value in the third loop.
 * history: wave P12 lane A8 33 of 208 bytes off; final push G7L3 26 (initialised declarations
 *   count, table, base); pass 2 P2L40: early i 13, separate sort-value local 6, named row 0.
 * symbols:
 *   d_021E1FDC 0x021E1FDC data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern const u16 d_021E1FDC[];
typedef struct {u8 pad[0x2c]; int index,count;} Obj;
void *func_021E0A44(Obj *p)
{
    int distance[5],indices[5];
    int angle,i,j,key,value,delta,dist,row;
    long count=p->count;
    const u8 *base=(const u8 *)p+0x1a0;
    i=0;
    row=count*10;
    angle=*(const u16 *)((unsigned)d_021E1FDC+row+p->index*2)<<12;
    do {indices[i]=i;distance[i]=65535;i++;} while(i<count);
    for(i=0;i<count;i++) {
        value=*(int *)(base+i*0xb4+0x15c);
        delta=angle-value;
        if(delta<0)delta=angle+0x168000-value;
        distance[i]=delta/4096;
    }
    for(i=1;i<count;i++) {
        key=indices[i];dist=distance[key];
        j=i-1;
        while(j>=0 && distance[indices[j]]>dist) {indices[j+1]=indices[j];j--;}
        indices[j+1]=key;
    }
    return (void *)(base+0x140+indices[0]*0xb4);
}
