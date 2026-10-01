/*
 * function: func_021BA560
 * address: 0x021BA560
 * packet: pkt_ov217_021BA560
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C09C8 0x021C09C8 thumb ov217
 *   func_021C09CC 0x021C09CC thumb ov217
 *   func_021BA3B0 0x021BA3B0 thumb ov217
 *   func_021BA3B4 0x021BA3B4 thumb ov217
 */
extern unsigned func_021C09C8(void *);
extern unsigned func_021C09CC(void *);
extern void func_021BA3B0(void *,unsigned);
extern unsigned func_021BA3B4(unsigned,unsigned);
void func_021BA560(char *p)
{
    void *owner=*(void **)p;
    unsigned a=func_021C09C8(owner),b=func_021C09CC(owner);
    if(a!=0 && b==0) {
        unsigned mode;
        switch(a) {case 2:default:mode=0;break;case 3:mode=1;break;}
        func_021BA3B0(p,mode);
    } else {
        if(func_021BA3B4((unsigned)p,0)!=0) func_021BA3B0(p,0);
        else func_021BA3B0(p,1);
    }
}
