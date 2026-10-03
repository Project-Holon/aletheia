/*
 * function: func_0220D798
 * address: 0x0220D798
 * packet: pkt_ov197_0220D798
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045B38 0x02045B38 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_020457B0 0x020457B0 arm
 */
struct MsgBank;struct WordSet;struct U16Vec;
extern struct MsgBank *func_02045B38(unsigned,unsigned,unsigned,unsigned);
extern struct WordSet *func_0201EC64(unsigned);
extern unsigned func_0201C440(void *);
extern struct U16Vec *func_020457B0(unsigned,unsigned);
void func_0220D798(char *p){*(struct MsgBank **)(p+12)=func_02045B38(0,2,17,*(unsigned short *)(*(char **)p+12));*(struct WordSet **)(p+16)=func_0201EC64(*(unsigned short *)(*(char **)p+12));*(unsigned *)(p+24)=func_0201C440((void *)*(unsigned short *)(*(char **)p+12));*(struct U16Vec **)(p+20)=func_020457B0(512,*(unsigned short *)(*(char **)p+12));}
