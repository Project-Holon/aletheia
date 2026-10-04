/*
 * function: func_021C133C
 * address: 0x021C133C
 * packet: pkt_ov110_021C133C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 Thumb 0x02024910 at caller +0xDE has no witness
 * outside 0x021C133C..0x021C1440; all concrete bytes match, 9/10
 * relocations resolved. Owner-only leaf; no blocker C filed or embedded.
 * Lever: one-bit field at +0x99 gives the original shift pair. Calls in
 * both Boolean arms preserve 355D8's u8 ABI without ternary truncation.
 * Empty switch cases -1 and 7 preserve the original unused comparisons.
 * The original explicitly supplies r0 to the otherwise argument-free
 * 021C0AC0 forwarder; its unused input is retained at this caller.
 * symbols:
 *   func_021C098C 0x021C098C thumb ov110
 *   func_020355D8 0x020355D8 arm
 *   func_021C0AC0 0x021C0AC0 thumb ov110
 *   func_021B6470 0x021B6470 thumb ov067
 *   func_021B6448 0x021B6448 thumb ov067
 *   func_020355C4 0x020355C4 arm
 *   func_021C0F14 0x021C0F14 thumb ov110
 *   func_020061E4 0x020061E4 thumb
 *   func_02024910 0x02024910 thumb
 *   func_02024464 0x02024464 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u8 bit:1; u8 rest:7; } Flag;
extern void func_021C098C(char *);
extern void func_020355D8(u8);
extern void func_021C0AC0(void *);
extern int func_021B6470(u8 *);
extern int func_021B6448(u8 *);
extern u8 func_020355C4(void);
extern int func_021C0F14(u8 *);
extern void func_020061E4(int);
extern void *func_02024910(void *,int);
extern int func_02024464(void *,unsigned);
int func_021C133C(void *unused,u8 *p)
{
    int result=-1;
    int done=0;
    int input;
    func_021C098C((char *)p+0x24);
    if(!*(int *)(p+0x40)) {
        input=0;
        if(!((Flag *)(p+0x99))->bit) {
            if(*(int *)(p+0xa8)) func_020355D8(1);
            else func_020355D8(0);
            func_021C0AC0(*(void **)(p+0x54));
            if(func_021B6470(*(u8 **)(p+0x54))!=-1) *(int *)(p+0xa4)=0;
            result=func_021B6448(*(u8 **)(p+0x54));
            if(result!=-1) *(int *)(p+0xa4)=1;
            *(int *)(p+0xa8)=func_020355C4()==1;
        }
        switch(result) {
        case -1: break;
        case 1:
            *(int *)(*(u8 **)p+4)=1;
            *(int *)(*(u8 **)p+8)=0;
            *(int *)(p+0xa0)=5;
            return 1;
        case 7: break;
        }
        if(*(int *)(p+0xa4)) input=func_021C0F14(p);
        if(input) {
            func_020061E4(1356);
            *(int *)(p+0x40)=1;
        }
    } else {
        if(p[0x44]==16) done=1;
    }
    if(done) {
        if(func_02024464(func_02024910(*(void **)(p+0x20),p[0x95]),*(u16 *)(p+4))) *(int *)(p+0xa0)=8;
        else *(int *)(p+0xa0)=11;
        return 1;
    }
    return 0;
}
