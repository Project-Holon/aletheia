/*
 * function: func_021F9730
 * address: 0x021F9730
 * packet: pkt_ov132_021F9730
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021F9754 0x021F9754 thumb ov132
 */
typedef unsigned char u8;
typedef unsigned int   u32;
extern void func_021F9754(char *p, u32 i, int v);
void func_021F9730(char *p,int value){if(!**(int **)(p+0x30))func_021F9754(p,*(u8 *)(p+0xa),value);else{*(int *)(p+0x15c)=1;*(int *)(p+0x160)=value;}}
