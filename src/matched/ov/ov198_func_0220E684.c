/*
 * function: func_0220E684
 * address: 0x0220E684
 * packet: pkt_ov198_0220E684
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B294 0x0204B294 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {short x,y,z; u8 a,b;} Point;
extern unsigned func_0204B294(unsigned,unsigned,unsigned,unsigned,Point *,u16,u16);
unsigned func_0220E684(char *p,const int *q)
{
    Point point;
    point.x=0;
    point.y=0;
    point.z=0;
    point.a=q[4];
    point.b=q[3];
    return func_0204B294(*(unsigned *)(p+0x1eb8),*(unsigned *)(p+q[0]*4+0x24a4),*(unsigned *)(p+q[1]*4+0x250c),*(unsigned *)(p+q[2]*4+0x2524),&point,1,*(u16 *)(*(char **)p+0x10));
}
