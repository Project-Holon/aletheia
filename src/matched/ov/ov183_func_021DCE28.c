/*
 * function: func_021DCE28
 * address: 0x021DCE28
 * packet: pkt_ov183_021DCE28
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FD640 0x021FD640 thumb ov186
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
extern void func_021FD640(int *);
void func_021DCE28(char *p,char *unused) { if(*(int *)(p+220) && *(int **)(p+68)) { func_021FD640(*(int **)(p+68)); *(int *)(p+68)=0; *(int *)(p+220)=0; } }
