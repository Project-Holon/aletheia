/*
 * function: func_021C5334
 * address: 0x021C5334
 * packet: pkt_ov127_021C5334
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C4AC4 0x021C4AC4 thumb ov127
 *   func_021C49A4 0x021C49A4 thumb ov127
 *   func_021C4CE4 0x021C4CE4 thumb ov127
 */
typedef unsigned short u16;
typedef unsigned char u8;
struct pair {u16 a,b;};
extern struct pair func_021C4AC4(char *);
extern int func_021C49A4(u8 *,unsigned);
extern void func_021C4CE4(char *,struct pair,int);
void func_021C5334(char *p) { struct pair v=func_021C4AC4(p); func_021C4CE4(p,v,func_021C49A4((u8 *)p,6)); }
