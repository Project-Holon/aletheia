/*
 * function: func_021B9A6C
 * address: 0x021B9A6C
 * packet: pkt_ov223_021B9A6C
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020480E4 0x020480E4 arm
 *   func_021B9600 0x021B9600 thumb ov223
 *   func_02011558 0x02011558 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Ctx;struct IcaAnime;extern void func_020480E4(struct Ctx *,u32);extern void func_021B9600(void *);extern void func_02011558(struct IcaAnime *);
void func_021B9A6C(char *p) {func_020480E4(*(struct Ctx **)(p+40),*(u16 *)(p+46));func_021B9600(*(void **)(p+60));*(u16 *)(p+58)=0;func_02011558(*(struct IcaAnime **)(p+64));}
