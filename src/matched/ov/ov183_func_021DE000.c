/*
 * function: func_021DE000
 * address: 0x021DE000
 * packet: pkt_ov183_021DE000
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0200DBA0 0x0200DBA0 thumb
 *   func_0201296C 0x0201296C thumb
 *   func_020142E8 0x020142E8 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed int     s32;
struct Blk1AC;
extern u32 func_0200DBA0(struct Blk1AC *p, s32 i, u32 op);
struct BigObj;
extern u32 func_0201296C(const struct BigObj *p);
extern u32 func_020142E8(void *,int);
int func_021DE000(void *p,char *q) { u32 a,b; a=func_0200DBA0(p,4,0); b=func_020142E8((void *)func_0201296C((const struct BigObj *)q),0x960); if(a && b) return 1; return 0; }
