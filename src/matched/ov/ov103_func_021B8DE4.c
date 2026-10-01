/*
 * function: func_021B8DE4
 * address: 0x021B8DE4
 * packet: pkt_ov103_021B8DE4
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Line pointer temporary plus split y subtraction before x subtraction
 *   fixes the 14-byte coordinate copy/register scheduling residue.
 * behavior: ref.origin/end/a/b are assigned before every read; unused tail
 *   words are never read or passed. 8BC0 fills all 216 cur bytes; 8F00 reads
 *   only pairs 0..9 of each initialized 12-pair line. dy is assigned before
 *   subtraction, dx before multiplication; arithmetic stays unsigned 32-bit.
 * symbols:
 *   func_021B8BC0 0x021B8BC0 thumb ov103
 *   func_021B8F00 0x021B8F00 thumb ov103
 *   _u32_div_f 0x0209C2B0 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct {int x,y;} Pair;
typedef struct {Pair point[12];} Line;
typedef struct {Pair origin,end;Line a,b;} Record;
typedef struct {Pair origin,end;Line a,b;u32 tail[2];} Block;
extern void func_021B8BC0(u8 *,Block *);
extern u8 func_021B8F00(const Pair *,Pair *,const Pair *,Pair *);
u8 func_021B8DE4(u8 *p)
{
    Block ref;
    Block cur;
    Pair rp,cp;
    u32 dx,dy,dist;
    u32 score;
    u32 first,second,part1,part2;
    Line *tmp;
    ref.origin=*(Pair *)(p+0xa3c);
    tmp=(Line *)(p+0xa4c);
    ref.end=*(Pair *)(p+0xa44);
    ref.a=*tmp;
    ref.b=*(Line *)(p+0xaac);
    func_021B8BC0(p+0x75c,&cur);
    rp=ref.origin;
    cp=cur.origin;
    dy=(u32)rp.y;
    dy=dy-(u32)cp.y;
    dx=(u32)rp.x-(u32)cp.x;
    dist=dx*dx+dy*dy;
    if(dist>0 && dist<=64)score=100;
    else if(dist>64 && dist<=256)score=80;
    else if(dist>256 && dist<=576)score=50;
    else if(dist>576 && dist<=1024)score=30;
    else if(dist>1024 && dist<=1600)score=10;
    else score=0;
    first=func_021B8F00(ref.a.point,ref.a.point,cur.a.point,cur.a.point);
    second=func_021B8F00(ref.b.point,ref.b.point,cur.b.point,cur.b.point);
    return (score*40u)/100u+(first*40u)/100u+(second*20u)/100u;
}
