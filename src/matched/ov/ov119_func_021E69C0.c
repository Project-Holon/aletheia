/*
 * function: func_021E69C0
 * address: 0x021E69C0
 * packet: pkt_ov119_021E69C0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * output: 0204B454 writes both halfwords via 0204B53C and 0204CF74/0204B0C8.
 * interface: 02040618 forwards legacy r3 only to 02042360, whose full body
 *            has three inputs and does not read it; caller supplies r0-r2.
 * symbols:
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 *   func_02040618 0x02040618 arm
 */
typedef struct { short x,y; } Pt;
extern void func_0204B454(void *,Pt *,unsigned int);
extern void func_0204B404(void *,const Pt *,unsigned int);
extern void func_02040618(int,int,int);
int func_021E69C0(char *p)
{
    Pt a,b,c;
    int i;
    if(*(short *)(p+0x11de)<128) *(short *)(p+0x11de)+=4;
    else return 1;
    for(i=0;i<8;i++) {
        func_0204B454(*(void **)(p+i*4+0x10cc),&a,1);
        if(i/4) a.x+=4; else a.x-=4;
        func_0204B404(*(void **)(p+i*4+0x10cc),&a,1);
    }
    for(i=0;i<3;i++) {
        if(*(void **)(p+i*4+0x1008)) {
            func_0204B454(*(void **)(p+i*4+0x1008),&b,1);
            b.x-=4;
            func_0204B404(*(void **)(p+i*4+0x1008),&b,1);
        }
    }
    for(i=0;i<3;i++) {
        if(*(void **)(p+i*4+0x1014)) {
            func_0204B454(*(void **)(p+i*4+0x1014),&c,1);
            c.x+=4;
            func_0204B404(*(void **)(p+i*4+0x1014),&c,1);
        }
    }
    func_02040618(5,0,-*(short *)(p+0x11de));
    func_02040618(4,0,*(short *)(p+0x11de)-128);
    return 0;
}
