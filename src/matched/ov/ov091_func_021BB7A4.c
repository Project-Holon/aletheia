/*
 * function: func_021BB7A4
 * address: 0x021BB7A4
 * packet: pkt_ov091_021BB7A4
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0202F038 0x0202F038 thumb
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_020452E8 0x020452E8 arm
 *   func_0201C6EC 0x0201C6EC thumb
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct Descriptor;
struct PrintSys;
extern void func_0202F038(u8 *p);
extern void func_0201F7A8(void *desc, u32 kind);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_0201C6EC(struct PrintSys *p);
void func_021BB7A4(void *p,u32 *s) { if(s[0]!=4) { if(s[13]!=0) {func_0202F038((u8 *)s[13]);s[13]=0;} func_0201F7A8((void *)s[1],1); func_020452E8((struct Descriptor *)s[1]); func_0201C6EC((struct PrintSys *)s[10]); s[0]=4; } }
