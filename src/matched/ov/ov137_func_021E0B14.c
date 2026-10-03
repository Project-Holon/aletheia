/*
 * function: func_021E0B14
 * address: 0x021E0B14
 * packet: pkt_ov137_021E0B14
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E0B38 0x021E0B38 thumb ov137
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021E0B38(char *,char *,int);
void func_021E0B14(char *p,char *q) { char *r; int offset; r=p+0x664; offset=*(int *)(q+0x10)*0x7c; *(int *)(r+offset)=1; *(char **)(r+offset+0x78)=q; func_021E0B38(p,r+offset,0); }
