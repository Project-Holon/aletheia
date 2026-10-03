/*
 * unit: yes
 * function: func_021FC7DC, func_021FC7F8
 * address: 0x021FC7DC
 * packet: pkt_ov132_021FC7DC
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FCAA8 0x021FCAA8 thumb ov132
 *   func_0203CDBC 0x0203CDBC arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cursor; struct Comm;
extern int func_0203CDBC(void);
extern void func_020307B0(void *);
extern void func_021FCAA8(char *);
int func_021FC7DC(int unused,int unused1,void *p) { if(func_0203CDBC()==1) {func_020307B0(p);return 1;} return 0; }
void func_021FC7F8(int unused,int unused1,char *p) { func_021FCAA8(p); }
