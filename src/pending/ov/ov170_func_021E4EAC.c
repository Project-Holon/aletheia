/*
 * function: func_021E4EAC
 * address: 0x021E4EAC
 * packet: pkt_ov170_021E4EAC
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
 *   func_021DD530 0x021DD530 thumb ov170
 *   func_021EA1E8 0x021EA1E8 thumb ov170
 *   func_020260E4 0x020260E4 thumb
 *   func_021EE3E4 0x021EE3E4 thumb ov170
 *   func_021EE038 0x021EE038 thumb ov170
 *   func_021EBC58 0x021EBC58 thumb ov170
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021DD530(u8 *);
extern void func_021EA1E8(char *);
extern void func_020260E4(void *,u8);
extern void func_021EE3E4(char **,unsigned);
extern void func_021EE038(char *,int,int,int);
extern void func_021EBC58(u8 *,int,int,int);
int func_021E4EAC(u8 *p){func_021DD530(p);func_021EA1E8((char *)p);func_020260E4(*(void **)(*(char **)(p+0x2c)+0x70),9);func_021EE3E4((char **)p,9);func_021EE038((char *)p,0,0,1);func_021EBC58(p,p[0x16],1,24);return 39;}
