/*
 * function: func_021BE7A4
 * address: 0x021BE7A4
 * packet: pkt_ov208_021BE7A4
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * matching: direct byte field access avoids a persistent extracted pointer register.
 * symbols:
 *   func_02040804 0x02040804 arm
 *   func_02041EE4 0x02041EE4 arm
 *   func_021BE9CC 0x021BE9CC thumb ov208
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 */
typedef unsigned short u16;
struct Ov208Icon { u16 heap,pad2; unsigned f4,f8; int fc; unsigned char count,pad11[7]; unsigned f18,f1c,f20,f24,f28,f2c,f30; };
struct PrintSys;
typedef unsigned int   u32;
extern u32 func_02040804(u32 layer);
extern void func_02041EE4(unsigned,unsigned,unsigned);
extern void func_021BE9CC(struct Ov208Icon *);
extern unsigned PRINTSYS_QUE_Main(struct PrintSys *);
void func_021BE7A4(struct Ov208Icon *p)
{
    switch(p->f8) {
    case 0: case 2: break;
    case 1:
        if(p->count==0) {
            if((int)func_02040804(5)<=0) {
                func_02041EE4(5,3,0);p->f8=2;
            } else {func_02041EE4(5,5,3);p->count=0;}
        } else --p->count;
        break;
    case 3:
        if(p->count==0) {
            if((int)func_02040804(5)>=24) {
                func_02041EE4(5,3,24);p->f8=0;
            } else {func_02041EE4(5,4,3);p->count=0;}
        } else --p->count;
        break;
    }
    func_021BE9CC(p);
    PRINTSYS_QUE_Main((struct PrintSys *)p->f2c);
}
