/*
 * function: func_021EEFA4
 * address: 0x021EEFA4
 * packet: pkt_ov170_021EEFA4
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021F1418 0x021F1418 data a1
 *   _u32_div_f 0x0209C2B0 arm
 */
typedef struct {
    unsigned char x,y,dx,dy;
    unsigned negx:1;
    unsigned negy:1;
    unsigned steps:30;
} Motion;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern const char d_021F1418[];
void func_021EEFA4(char *p, unsigned char x, unsigned char y, unsigned char tx, unsigned char ty)
{
    Motion *s;
    s=func_02030734(0x4c,8,0,d_021F1418,0x98f);
    s->steps=4;
    s->x=x;
    s->y=y;
    if(x>=tx) { s->dx=x-tx; s->negx=0; }
    else { s->dx=tx-x; s->negx=1; }
    if(y>=ty) { s->dy=y-ty; s->negy=0; }
    else { s->dy=ty-y; s->negy=1; }
    s->dx=((unsigned)(s->dx<<8)/(unsigned)s->steps)>>8;
    s->dy=((unsigned)(s->dy<<8)/(unsigned)s->steps)>>8;
    *(Motion **)(p+0x60)=s;
}
