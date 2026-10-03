/*
 * function: func_021F9048
 * address: 0x021F9048
 * packet: pkt_ov185_021F9048
 * region: ov185
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_020061E4 0x020061E4 thumb
 * Extent past 021F9088 contains three callback pointers and zero rodata.
 */
extern void func_021FD860(void *,int,int *);
typedef unsigned int   u32;
extern void func_020061E4(u32 a);
int func_021F9048(char *p,unsigned x,unsigned y)
{
    int inside=((unsigned)(x-0xb8)<=0x28)&((unsigned)(y-0x40)<=0x28);
    if(inside) {
        int pair[2];
        pair[0]=x;
        pair[1]=y;
        func_021FD860(*(void **)(p+0x3c),1,pair);
        func_020061E4(0x703);
    }
    return inside;
}
