/*
 * function: func_021B98A0
 * address: 0x021B98A0
 * packet: pkt_ov133_021B98A0
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9990 0x021B9990 thumb ov133
 *   func_021B9A88 0x021B9A88 thumb ov133
 *   func_021B9AC0 0x021B9AC0 thumb ov133
 *   func_021B987C 0x021B987C thumb ov133
 *   func_0204B404 0x0204B404 arm
 *   func_021B75E0 0x021B75E0 thumb ov133
 *   a1 0x021BA558 data a4
 *   b1 0x021BA560 data a4
 *   a2 0x021BA550 data a4
 *   b2 0x021BA548 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef struct {int x,y;} Pair;
typedef struct {s16 x,y;} Pos;
extern const Pair a1,b1,a2,b2;
extern void func_021B9990(u8 *,u16,int,u16),func_021B9A88(u8 *,u16),func_021B9AC0(u8 *,int *,int *,u16),func_021B987C(u8 *),func_021B75E0(u8 *);
extern void func_0204B404(void *,const Pos *,unsigned);
void func_021B98A0(u8 *p)
{
    Pair firstA,firstB,secondA,secondB;
    Pos pos;
    switch(p[0x1846]) {
    case 0: break;
    case 1: func_021B9990(p,p[0x1847]*4681,p[0x1847]*4681,p[0x1847]*15); break;
    case 2: func_021B9A88(p,30); break;
    case 3: func_021B9990(p,-(u16)(p[0x1847]*4681),-(p[0x1847]*4681),p[0x1847]*15); break;
    case 4: func_021B9A88(p,30); break;
    case 5: firstA=a1; firstB=b1; func_021B9AC0(p,&firstA.x,&firstB.x,60); break;
    case 6: func_021B9A88(p,30); break;
    case 7: secondA=a2; secondB=b2; func_021B9AC0(p,&secondA.x,&secondB.x,60); break;
    case 8: func_021B9A88(p,30); break;
    case 9: func_021B987C(p); return;
    }
    pos.x=*(int *)(p+28); pos.y=*(int *)(p+32);
    func_0204B404(*(void **)(p+0x1854),&pos,0);
    func_021B75E0(p);
}
