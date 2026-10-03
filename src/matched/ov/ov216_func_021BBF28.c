/*
 * function: func_021BBF28
 * address: 0x021BBF28
 * packet: pkt_ov216_021BBF28
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BCBA4 0x021BCBA4 thumb ov216
 *   func_0201C6B4 0x0201C6B4 thumb
 */
struct PrintSys;
extern void func_021BCBA4(unsigned char *);
extern unsigned func_0201C6B4(const struct PrintSys *);
int func_021BBF28(unsigned char *p){switch(*(int *)(p+4)){case 0:func_021BCBA4(p);(*(int *)(p+4))++;break;case 1:if(func_0201C6B4(*(struct PrintSys **)(p+0x12c))){*(int *)(p+4)=0;return 1;}break;}return 0;}
