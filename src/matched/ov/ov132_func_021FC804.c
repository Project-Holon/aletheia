/*
 * function: func_021FC804
 * address: 0x021FC804
 * packet: pkt_ov132_021FC804
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203D378 0x0203D378 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cursor; struct Comm;
extern u32 func_0203D378(void);
void func_021FC804(char *p) { if(func_0203D378()==1) *(int *)(p+0x48)=1; else *(int *)(p+0x48)=2; }
