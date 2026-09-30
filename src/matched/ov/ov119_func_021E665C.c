/*
 * function: func_021E665C
 * address: 0x021E665C
 * packet: pkt_ov119_021E665C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 *   func_021E66E8 0x021E66E8 thumb ov119
 *   func_021E729C 0x021E729C thumb ov119
 */
typedef struct { short x,y; } Pt;
extern void func_0204B454(int,Pt *,unsigned int);
extern void func_0204B404(int,const Pt *,unsigned int);
extern void func_021E66E8(void *);
extern void func_021E729C(void *);
int func_021E665C(char *p) {
    Pt pos;
    if (*(short *)(p+0x11dc)) {
        --*(short *)(p+0x11dc);
        if (!*(short *)(p+0x11dc)) return 1;
        func_0204B454(*(int *)(p+0xf20),&pos,1);
        if (pos.y<0) *(short *)(p+0x11dc)=1;
        if (*(short *)(p+0x11dc)==1) func_021E66E8(p);
        else {
            func_021E729C(p+0x1190);
            pos.x=*(int *)(p+0x1190)/4096;
            pos.y=*(int *)(p+0x1194)/4096;
            func_0204B404(*(int *)(p+0xf20),&pos,1);
        }
    }
    return 0;
}
