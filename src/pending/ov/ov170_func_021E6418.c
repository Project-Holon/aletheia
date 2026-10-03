/*
 * function: func_021E6418
 * address: 0x021E6418
 * packet: pkt_ov170_021E6418
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: MATCH
 * blocker: ARM9 0x020260E4 has no outside code-start witness. Scratch one EXACT.
 *   void func_020260E4(unsigned char *p, unsigned value) {
 *       p[13] = value; p[14] = 255; p[15] = 255;
 *   }
 * symbols:
 *   func_020260E4 0x020260E4 thumb
 *   func_021EE3E4 0x021EE3E4 thumb ov170
 *   func_021ED55C 0x021ED55C thumb ov170
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_020260E4(void *,u8);
extern void func_021EE3E4(char **,unsigned);
extern void func_021ED55C(char **,int);
int func_021E6418(u8 *p){int sel;sel=37;if(*(u16 *)(*(char **)(p+0x2c)+0xa16c)!=0)sel=36;func_020260E4(*(void **)(*(char **)(p+0x2c)+0x70),sel);func_021EE3E4((char **)p,sel);func_021ED55C((char **)p,1);return 57;}
