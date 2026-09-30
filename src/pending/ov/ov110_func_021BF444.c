/*
 * function: func_021BF444
 * address: 0x021BF444
 * packet: pkt_ov110_021BF444
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: MATCH
 * blocker: ARM9 0x020245A0 Thumb; no witness outside caller range.
 *   Verified EXACT (blocker-r1.log), 12 bytes:
 *   void func_020245A0(u8 *p,unsigned i,u16 v) {
 *       if(i<2) *(u16 *)(p+4+2*i)=v;
 *   }
 * symbols:
 *   func_021BEDD0 0x021BEDD0 thumb ov110
 *   func_021B99C4 0x021B99C4 thumb ov110
 *   func_021BB1E4 0x021BB1E4 thumb ov110
 *   func_021BABF4 0x021BABF4 thumb ov110
 *   func_020245A0 0x020245A0 thumb
 *   func_021BF680 0x021BF680 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021BEDD0(void *);
extern u16 func_021B99C4(void *,u16,int);
extern u16 func_021BB1E4(void *,int);
extern int func_021BABF4(void *,u16);
extern void func_020245A0(void *,int,u16);
extern int func_021BF680(u8 *);
int func_021BF444(u8 *p) {
    int i=*(u16 *)(p+98);
    u16 v;
    if(i==65535) i=func_021BEDD0(p+84);
    if(p[105]==0) v=func_021B99C4(*(void **)(p+24),*(u16 *)(p+76),i);
    else v=func_021BB1E4(*(void **)(p+28),i);
    switch(*(u32 *)(p+4)) {
    case 0: *(u16 *)(p+16)=v; break;
    case 1: *(u16 *)(p+16+2* *(u16 *)(p+74))=v; break;
    case 2: func_020245A0(p+8,func_021BABF4(*(void **)(p+20),*(u16 *)(p+74)),v); break;
    }
    return func_021BF680(p);
}
