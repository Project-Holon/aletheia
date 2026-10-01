/*
 * unit: yes
 * function: func_021D6F54,func_021D703C
 * address: 0x021D6F54
 * packet: pkt_ov131_021D6F54
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: 021D703C complete reset helper is included; 021D7060 is filed
 *   separately. Reset contains constant stores only, preserving order.
 * semantic: unsigned full-word state dispatch guarded at six by the
 *   original; byte counters compared directly. No signed arithmetic.
 * symbols:
 *   func_021D703C 0x021D703C thumb ov131
 *   func_021D7060 0x021D7060 thumb ov131
 *   func_021D708C 0x021D708C thumb ov131
 *   func_021D7248 0x021D7248 thumb ov131
 *   func_021D72E8 0x021D72E8 thumb ov131
 *   func_02015E4C 0x02015E4C thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021D703C(void *,u8 *);
extern int func_021D7060(void *,u8 *,u8 *);
extern int func_021D708C(u8 *,u8 *);
extern int func_021D7248(u8 *,u8 *);
extern int func_021D72E8(u8 *,u8 *,int);
extern void func_02015E4C(void *);
void func_021D6F54(u8 *p,u8 *q)
{
    switch(*(u32 *)(q+0x5c)) {
    case 0:
        if(q[0x78]>10) {*(u32 *)(q+0x5c)=1;func_021D703C(p,q);}
        if(q[0x80]>10) {*(u32 *)(q+0x5c)=2;func_021D703C(p,q);}
        if(q[0x88]>20) {*(u32 *)(q+0x5c)=3;func_021D703C(p,q);}
        break;
    case 1:
        func_021D708C(p,q);
        if(func_021D7060(p,q,q+0x78)==0) *(u32 *)(q+0x5c)=4;
        break;
    case 4:
        if(func_021D708C(p,q)==1) *(u32 *)(q+0x5c)=0;
        break;
    case 2:
        func_021D7248(p,q);
        if(func_021D7060(p,q,q+0x80)==0) *(u32 *)(q+0x5c)=5;
        break;
    case 5:
        if(func_021D7248(p,q)==1) *(u32 *)(q+0x5c)=0;
        break;
    case 3:
        func_021D72E8(p,q,1);
        if(func_021D7060(p,q,q+0x88)==0) *(u32 *)(q+0x5c)=6;
        break;
    case 6:
        if(func_021D72E8(p,q,0)==1) {
            func_02015E4C(*(void **)q);
            *(u32 *)(q+0x5c)=0;
        }
        break;
    }
}
typedef unsigned short u16;
void func_021D703C(void *unused,u8 *q)
{
    *(u32 *)(q+0x58)=1;
    *(u16 *)(q+0x64)=0;
    *(u16 *)(q+0x68)=0;
    *(u16 *)(q+0x62)=0;
    *(u16 *)(q+0x66)=0;
    *(u16 *)(q+0x60)=0;
}
