/*
 * function: func_021FC34C
 * address: 0x021FC34C
 * packet: pkt_ov132_021FC34C
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F9DD4 0x021F9DD4 thumb ov132
 *   func_021FAE4C 0x021FAE4C thumb ov132
 *   func_021F6EF4 0x021F6EF4 thumb ov112
 *   func_021FADF8 0x021FADF8 thumb ov132
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cursor; struct Comm;
extern void *func_021F9DD4(void *);
extern int func_021FAE4C(char *,int *);
extern void func_021F6EF4(void *,u32 *,const u32 *);
extern void func_021FADF8(char *,char *);
void func_021FC34C(int unused,char *p) { int pos[3]; void *ctx; int result; ctx=func_021F9DD4(*(void **)(p+4)); result=func_021FAE4C(p+4,pos); func_021F6EF4(ctx,*(u32 **)p,(u32 *)pos); if(result==1) func_021FADF8(*(char **)(p+0x30),*(char **)(p+0x34)); }
