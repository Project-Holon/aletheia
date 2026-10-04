/*
 * function: func_0217B014
 * address: 0x0217B014
 * packet: pkt_ov176_0217B014
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_0217AFD0 0x0217AFD0 thumb ov176
 *   func_02034714 0x02034714 arm
 *   d_0217E5E0 0x0217E5E0 data a1
 */
typedef signed int     s32;
typedef unsigned int   u32;
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);
extern void func_021E8AA0(int *p, int v);
extern void func_0217AFD0(void *,int,char *);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern const char d_0217E5E0[];
void func_0217B014(void *a,int *state,char *p)
{
    switch(*state){
    case 0: func_0204E720(3,16,0,0); *state=1; break;
    case 1: if(!func_0204E804()) *state=2; break;
    case 2: func_021E8AA0(a,(int)func_0217AFD0); break;
    default: func_02034714(d_0217E5E0,0,d_0217E5E0); break;
    }
}
