/*
 * function: func_021DB740
 * address: 0x021DB740
 * packet: pkt_ov183_021DB740
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * lever: Explicit call arms preserve the original conditional argument branch.
 * symbols:
 *   func_021FBDA4 0x021FBDA4 thumb ov186
 *   func_021F9F48 0x021F9F48 thumb ov186
 *   func_021FD820 0x021FD820 thumb ov186
 *   func_020315D4 0x020315D4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
struct S020315D4;
extern void func_021FBDA4(int,unsigned),func_021F9F48(u8 *),func_021FD820(char *);
extern void func_020315D4(struct S020315D4 *);
int func_021DB740(struct S020315D4 *task,int b,char *q,char *p) { if(*(int *)q<5) func_021FBDA4(*(int *)(q+24),3); else func_021FBDA4(*(int *)(q+24),4); func_021F9F48(*(u8 **)p); func_021FD820(*(char **)(p+4)); func_020315D4(task); return 1; }
