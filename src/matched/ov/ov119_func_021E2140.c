/*
 * function: func_021E2140
 * address: 0x021E2140
 * packet: pkt_ov119_021E2140
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E2070 0x021E2070 thumb ov119
 *   d_021E7954 0x021E7954 data a4
 *   d_021E7964 0x021E7964 data a4
 */
typedef unsigned short u16;
typedef struct { int a,b,c,d; } Quad;
extern const Quad d_021E7954,d_021E7964;
extern void func_021E2070(void *,int,Quad *);
void func_021E2140(char *p,int a)
{
    if(*(u16 *)(p+0x1098)) {
        Quad t;
        t=d_021E7954;
        func_021E2070(p,a,&t);
        *(u16 *)(p+0x1098)=0;
    } else {
        Quad t;
        t=d_021E7964;
        func_021E2070(p,a,&t);
        *(u16 *)(p+0x1098)=1;
    }
}
