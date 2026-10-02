/*
 * function: func_021D9490
 * address: 0x021D9490
 * packet: pkt_ov129_021D9490
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021DA798 0x021DA798 data a2
 *   func_021D958C 0x021D958C thumb ov129
 *   func_02051B84 0x02051B84 arm
 */
typedef unsigned char u8;
typedef short s16;
typedef struct { s16 a,b,c,d; } Rect;
typedef struct { Rect rows[12]; } Rects;
extern const Rects d_021DA798;
extern void func_021D958C(unsigned,int,unsigned);
extern void *func_02051B84(u8 *,int,int,int);
void func_021D9490(char *p)
{
    int i;
    Rects t;
    for(i=0;i<12;i++) *(void **)(p+i*28+16)=p+0x298+i*4;
    t=d_021DA798;
    for(;i<24;i++) {
        *(u8 *)(p+i*4+0x298)=t.rows[i-12].b-t.rows[i-12].d;
        *(u8 *)(p+i*4+0x29a)=t.rows[i-12].a-t.rows[i-12].c;
        *(u8 *)(p+i*4+0x299)=t.rows[i-12].b+t.rows[i-12].d;
        *(u8 *)(p+i*4+0x29b)=t.rows[i-12].a+t.rows[i-12].c;
    }
    *(u8 *)(p+0x2f8)=255;
    *(void **)(p+0x294)=func_02051B84((u8 *)(p+0x298),(int)func_021D958C,(int)p,50);
}
