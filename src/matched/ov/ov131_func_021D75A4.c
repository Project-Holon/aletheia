/*
 * function: func_021D75A4
 * address: 0x021D75A4
 * packet: pkt_ov131_021D75A4
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: three coordinate pairs (x,y from func_02035CB8) are compared against
 *   byte histories at +0x7A/+0x82/+0x8A and dispatched to func_021D77F8 /
 *   func_021D77E8. direction=0 is written before ++p[0x81] and flag=0 after
 *   ry; this places the r3/r4 zero registers.
 * note 2026-10-02 (lane R5): the rotation x delta is spelled
 *   `rx=p[0x8a]; rx=(s8)(x-rx);`. The byte is loaded into rx's own register
 *   (r1, the register that later holds the s8 result), so the subtraction
 *   reads ldrb r1 / ldr r0,x / subs r0,r0,r1. A separate byte temporary or a
 *   direct (s8)(x-p[0x8a]) put the byte in r0 (3 bytes off).
 * symbols:
 *   func_02035CB8 0x02035CB8 arm
 *   func_021D77E8 0x021D77E8 thumb ov131
 *   func_021D77F8 0x021D77F8 thumb ov131
 *   func_021D7810 0x021D7810 thumb ov131
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef enum { D0,D1,D2,D3,D4 } Direction;
typedef enum { F0,F1 } Flag;
struct hdr { u8 f0,f1,f2,f3; int f4; };
typedef struct { u8 pad[0x94]; u8 ring[5]; u8 f99,f9a; } Ring;
extern u32 func_02035CB8(u32 *,u32 *);
extern void func_021D77E8(u8 *,u32,u32);
extern void func_021D77F8(struct hdr *,u32,u32,int);
extern void func_021D7810(int,Ring *,int);
void func_021D75A4(int a,u8 *p)
{
    u32 x,y;
    int dx,dy,rx,ry;
    Direction direction;
    Flag flag;
    u32 tmp;
    u32 *tmp1;
    func_02035CB8(&x,&y);
    dx=(s8)(x-p[0x7a]);
    dy=(s8)(y-p[0x7b]);
    if ((*(u32 *)(p+0x7c)==0 || *(u32 *)(p+0x7c)==3) && dx>16)
        func_021D77F8((struct hdr *)(p+0x78),x,y,1);
    if (*(u32 *)(p+0x7c)<=1 && dx < -16)
        func_021D77F8((struct hdr *)(p+0x78),x,y,3);
    if (dy>16 || dy < -16 || p[0x79]>20)
        func_021D77E8((u8 *)p+0x78,x,y);
    ++((u8 *)p)[0x79];
    dx=(s8)(x-p[0x82]);
    dy=(s8)(y-p[0x83]);
    if ((*(u32 *)(p+0x84)==0 || *(u32 *)(p+0x84)==4) && dy>16)
        func_021D77F8((struct hdr *)(p+0x80),x,y,2);
    if ((*(u32 *)(p+0x84)==0 || *(u32 *)(p+0x84)==2) && dy < -16)
        func_021D77F8((struct hdr *)(p+0x80),x,y,4);
    if (dx>16 || dx < -16 || p[0x81]>20)
        func_021D77E8((u8 *)p+0x80,x,y);
    direction=0;
    ++((u8 *)p)[0x81];
    rx=p[0x8a];
    rx=(s8)(x-rx);
    ry=(s8)(y-p[0x8b]);
    flag=0;
    if (rx>16) direction=1;
    else if (rx < -16) direction=3;
    else if (ry>16) direction=2;
    else if (ry < -16) direction=4;
    if (direction!=0 && (u32)direction!=*(u32 *)(p+0x8c)) {
        if (*(u32 *)(p+0x8c)+1==(u32)direction ||
            (*(u32 *)(p+0x8c)==4 && direction==1)) {
            tmp=*(u32 *)(p+0x90);
            if (tmp<=1) {
                *(u32 *)(p+0x90)=1;
                func_021D77F8((struct hdr *)(p+0x88),x,y,direction);
                if (*(u32 *)(p+0x8c)==4) flag=1;
            } else {
                *(u32 *)(p+0x90)=0;
                func_021D77E8((u8 *)p+0x88,x,y);
            }
        } else if (*(u32 *)(p+0x8c)-1==(u32)direction ||
            (*(u32 *)(p+0x8c)==1 && direction==4)) {
            tmp1=(u32 *)(p+0x90);
            if (*tmp1==2 || *(u32 *)(p+0x90)==0) {
                *(u32 *)(p+0x90)=2;
                func_021D77F8((struct hdr *)(p+0x88),x,y,direction);
                if (*(u32 *)(p+0x8c)==4) flag=1;
            } else {
                *(u32 *)(p+0x90)=0;
                func_021D77E8((u8 *)p+0x88,x,y);
            }
        } else if (*(u32 *)(p+0x8c)==0) {
            *(u32 *)(p+0x8c)=direction;
        }
    }
    if (p[0x89]>20) {
        *(u32 *)(p+0x90)=0;
        func_021D77E8((u8 *)p+0x88,x,y);
    }
    func_021D7810(a,(Ring *)p,flag);
    ++((u8 *)p)[0x89];
}
