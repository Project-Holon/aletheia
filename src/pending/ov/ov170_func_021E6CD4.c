/*
 * function: func_021E6CD4
 * address: 0x021E6CD4
 * packet: pkt_ov170_021E6CD4
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: MATCH
 * blocker: ARM9 0x020260F0 has no outside code-start witness. Scratch one EXACT.
 *   unsigned func_020260F0(unsigned char *p) { return *(unsigned *)(p+4); }
 * symbols:
 *   func_021EBA70 0x021EBA70 thumb ov170
 *   func_021DD14C 0x021DD14C thumb ov170
 *   func_020260F0 0x020260F0 thumb
 *   func_021EC000 0x021EC000 thumb ov170
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021EBA70(char *,int);
extern void func_021DD14C(char *);
extern u32 func_020260F0(void *);
extern void func_021EC000(char *,int,int);
int func_021E6CD4(u8 *p){func_021EBA70(*(char **)(p+0x2c),24);func_021DD14C((char *)p);if(func_020260F0(*(void **)(*(char **)(p+0x2c)+0x70))==1)func_021EC000(*(char **)(p+0x2c),4,1);return 64;}
