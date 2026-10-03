/*
 * function: func_021FBF74
 * address: 0x021FBF74
 * packet: pkt_ov132_021FBF74
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021F9DAC 0x021F9DAC thumb ov132
 *   func_021FAE4C 0x021FAE4C thumb ov132
 *   func_021F6B9C 0x021F6B9C thumb ov112
 *   func_021FADF8 0x021FADF8 thumb ov132
 */
struct Cursor;
extern unsigned int func_0201134C(struct Cursor *);
extern void *func_021F9DAC(void *);
extern int func_021FAE4C(char *,int *);
extern void func_021F6B9C(void *,unsigned int *,unsigned int *);
extern void func_021FADF8(void *,void *);
void func_021FBF74(int unused,char *p) { int pos[3]; void *ctx; int result;ctx=func_021F9DAC(*(void **)(p+4));result=func_021FAE4C(p+4,pos);func_021F6B9C(ctx,*(unsigned int **)p,(unsigned int *)pos);if(result==1)func_021FADF8(*(void **)(p+0x30),*(void **)(p+0x34));}
