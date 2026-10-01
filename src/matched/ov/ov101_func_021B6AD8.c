/*
 * function: func_021B6AD8
 * address: 0x021B6AD8
 * packet: pkt_ov101_021B6AD8
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: full own C20 body reads/forwards fourth int arg; original r3=p
 *   remains live into all three calls, preserved as the same full-word payload.
 * symbols:
 *   func_021B6C20 0x021B6C20 thumb ov101
 *   func_021B6A3C 0x021B6A3C thumb ov101
 *   func_021B6A7C 0x021B6A7C thumb ov101
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021B6C20(int *,int,int,int);
extern void func_021B6A3C(u8 *,u32);
extern void func_021B6A7C(u8 *,u16 *);
void func_021B6AD8(u8 *p,u16 *state)
{
    switch(*state) {
    case 0:
        p[0x2e]=0;
        p[0x2c]=0;
        *state=1;
        break;
    case 1:
        if(func_021B6C20((int *)(p+4),2,0x3a,(int)p)) *state=2;
        break;
    case 2:
        if(*(int *)(p+0x28)==0) *state=3;
        else if(*(int *)(p+0x28)==2) {
            p[0x2e]=0;
            p[0x2c]=0;
            *state=5;
        } else *state=6;
        break;
    case 3:
        if(func_021B6C20((int *)(p+4),1,0x3a,(int)p)) *state=4;
        break;
    case 4:
        if(*(int *)(p+0x24)==0) *state=5;
        else if(*(int *)(p+0x24)==2) {
            p[0x2e]=0;
            p[0x2c]=0;
            *state=5;
        } else *state=6;
        break;
    case 5:
        if(func_021B6C20((int *)(p+4),3,0x3a,(int)p)) *state=6;
        break;
    case 6:
        func_021B6A3C(p,(u32)func_021B6A7C);
        break;
    }
}
