/*
 * function: func_021BD764
 * address: 0x021BD764
 * packet: pkt_ov208_021BD764
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 126 code bytes, then two zero alignment bytes at 021BD7E2.
 * symbols:
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_02035D20 0x02035D20 arm
 *   func_020355D8 0x020355D8 arm
 *   func_020362DC 0x020362DC arm
 */

typedef unsigned int u32;
extern unsigned func_0204B3F4(void *);
extern int func_02035D20(unsigned *,unsigned *);
extern void func_020355D8(int);
extern u32 func_020362DC(void);
int func_021BD764(char *p)
{
    unsigned x,y;
    int hit=0;
    if(func_0204B3F4(*(void **)p)&*(unsigned *)(p+4)) {
        if(func_02035D20(&x,&y) && x-*(short *)(p+0x18)<=*(unsigned short *)(p+0x1c) && y-*(short *)(p+0x1a)<=24) {
            hit=1;
            func_020355D8(1);
        }
        if(*(unsigned *)(p+0x2c) && (func_020362DC()&*(unsigned *)(p+0x2c))) {
            func_020355D8(0);
            hit=1;
        }
        if(*(int *)(p+0x34)) {
            func_020355D8(0);
            hit=1;
        }
        if(hit) {
            (*(void (**)(char *))(p+0xc))(p);
            return 1;
        }
    }
    return 0;
}
