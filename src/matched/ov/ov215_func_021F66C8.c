/*
 * function: func_021F66C8
 * address: 0x021F66C8
 * packet: pkt_ov215_021F66C8
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_0207ADC4 0x0207ADC4 arm
 *   d_021F73F4 0x021F73F4 data a1
 */
typedef unsigned short u16;
typedef struct { int tag,x,y,z,sx,sy,sz,matrix[9],tail; } Record;
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern void func_0207ADC4(void *);
extern const char d_021F73F4[];
Record *func_021F66C8(unsigned heap,unsigned count)
{
    Record *p;
    u16 i;
    p=func_02030734(heap,68*count,1,d_021F73F4,283);
    for(i=0;i<count;i++) {
        p[i].x=0;p[i].y=0;p[i].z=0;
        p[i].sx=4096;p[i].sy=4096;p[i].sz=4096;
        func_0207ADC4(p[i].matrix);
    }
    return p;
}
