/*
 * function: func_021DA004
 * address: 0x021DA004
 * packet: pkt_ov129_021DA004
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent ends with two bytes of zero alignment padding.
 * Lever: declare the 4-byte-stride pointer before the 28-byte-stride pointer.
 * symbols:
 *   func_0204B878 0x0204B878 arm
 *   func_021D9FF0 0x021D9FF0 thumb ov129
 */
typedef unsigned char u8;
typedef short s16;
extern void func_0204B878(int,unsigned short);
extern void func_021D9FF0(char *,int,int);
void func_021DA004(char *p)
{
    int i;
    char *r,*q;
    s16 x,y;
    for(i=0;i<2;i++) {
        r=p+i*4;
        x=*(u8 *)(r+0x2f2)+20;
        y=(*(u8 *)(r+0x2f0)+*(u8 *)(r+0x2f1))/2;
        y-=7;
        q=p+i*28;
        switch(*(int *)(q+0x1dc)) {
        case 0:
            *(u8 *)(q+0x1f4)=0;
            break;
        case 1:
            *(u8 *)(q+0x1f4)+=1;
            if(*(u8 *)(q+0x1f4)==1) {
                func_0204B878(*(int *)(q+0x1e8),1);
                func_021D9FF0(*(char **)(r+0x304),x,y);
            } else if(*(u8 *)(q+0x1f4)==2) {
                func_0204B878(*(int *)(q+0x1e8),2);
                func_021D9FF0(*(char **)(r+0x304),x,y);
            } else if(*(u8 *)(q+0x1f4)==10) {
                func_0204B878(*(int *)(q+0x1e8),0);
                func_021D9FF0(*(char **)(r+0x304),x,y);
                *(int *)(q+0x1dc)+=1;
            }
            break;
        default:
            func_0204B878(*(int *)(q+0x1e8),0);
            func_021D9FF0(*(char **)(r+0x304),x,y);
            *(int *)(q+0x1dc)=0;
            break;
        }
    }
}
