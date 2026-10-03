/*
 * function: func_021BED94
 * address: 0x021BED94
 * packet: pkt_ov203_021BED94
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BEDCC 0x021BEDCC thumb ov203
 *   func_02031194 0x02031194 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Owner;struct TcblNode;
typedef struct Config {unsigned words[11];} Config;
extern void func_021BEDCC(int,int,int);
extern void func_02031194(struct TcblNode *);
void func_021BED94(struct TcblNode *p,char *q) { int old;old=*(int *)(q+8);*(int *)(q+8)=old-1;if(old>0){func_021BEDCC(*(u8 *)(q+5),*(u8 *)(q+6),*(int *)(q+20)>>12);*(int *)(q+20)+=*(int *)(q+24);}else {func_021BEDCC(*(u8 *)(q+5),*(u8 *)(q+6),*(int *)(q+16));func_02031194(p);} }
