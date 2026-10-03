/*
 * function: func_021E0778
 * address: 0x021E0778
 * packet: pkt_ov170_021E0778
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021ED544 0x021ED544 thumb ov170
 *   func_021EC0B0 0x021EC0B0 thumb ov170
 *   func_021EC08C 0x021EC08C thumb ov170
 *   func_020061E4 0x020061E4 thumb
 *   func_021ED7C4 0x021ED7C4 thumb ov170
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_021ED544(u8 *,int);
extern void func_021EC0B0(char *,int,short *,short *,u16);
extern void func_021EC08C(char *,int,short,short,short);
extern void func_020061E4(unsigned);
extern void func_021ED7C4(char *,int);
#define W(p) (*(char **)((p)+0x2C))
int func_021E0778(u8 *p)
{
    char *s=W(p)+0x58;
    short xy[2];
    int k;
    switch(*(u16 *)(s+12)) {
    case 0:
        func_021ED544(p,7);
        (*(u16 *)(s+12))++;
    case 1:
        if(*(u16 *)(s+14)==4) {
            *(u16 *)(s+14)=0;
            (*(u16 *)(s+12))++;
            break;
        }
        func_021EC0B0(W(p),4,&xy[1],&xy[0],0);
        func_021EC08C(W(p),4,xy[1],xy[0]+2,0);
        (*(u16 *)(s+14))++;
        break;
    case 2:
        func_020061E4(0x666);
        func_021ED544(p,8);
        (*(u16 *)(s+12))++;
    case 3:
        if(*(u16 *)(s+14)==4) {
            *(u16 *)(s+14)=0;
            *(u16 *)(s+12)=0;
            return 0;
        }
        func_021EC0B0(W(p),4,&xy[1],&xy[0],0);
        func_021EC08C(W(p),4,xy[1],xy[0]-2,0);
        k=*(u8 *)(W(p)+0x3DF6);
        func_021EC0B0(W(p),k,&xy[1],&xy[0],0);
        func_021EC08C(W(p),k,xy[1],xy[0]-2,0);
        func_021ED7C4(W(p),0x24);
        (*(u16 *)(s+14))++;
        break;
    }
    return 1;
}
