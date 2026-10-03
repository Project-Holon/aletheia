/*
 * function: func_021E54CC
 * address: 0x021E54CC
 * packet: pkt_ov178_021E54CC
 * region: ov178
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201AB28 0x0201AB28 thumb
 *   func_0201A98C 0x0201A98C thumb
 *   func_021B6108 0x021B6108 thumb ov090
 *   func_02034A5C 0x02034A5C arm
 *   ov090_id 0x0000005A data
 *   func_0203133C 0x0203133C arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 */
extern void *func_0201AB28(void *,unsigned);
typedef signed int     s32;
typedef unsigned int   u32;
struct Party;
struct PartyMon;
struct S020314B8;
struct S020315D4;
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern void func_021B6108(void *);
extern void func_02034A5C(s32 handle);
extern unsigned ov090_id[];
extern void func_0203133C(struct S020314B8 *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned);
int func_021E54CC(void *handle,int unused,char *q,char *p)
{
 unsigned char i;
 for(i=0;i<6;i++) {
 unsigned n=*(unsigned char *)(p+i+0x51);
 if(n!=0)func_0201A98C(*(void **)(q+0x1C),func_0201AB28(*(void **)(q+4),n-1));
 }
 func_021B6108(p+8);func_02034A5C((unsigned)ov090_id);
 func_0203133C(*(void **)(p+0xD0));func_020315D4(handle);func_020306F0(0x58);
 return 1;
}
