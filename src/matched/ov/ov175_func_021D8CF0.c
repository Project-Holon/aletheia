/*
 * function: func_021D8CF0
 * address: 0x021D8CF0
 * packet: pkt_ov175_021D8CF0
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Lever: the two-value tail dispatch is a switch; if (v==1 || v==2) folds into a range and compiles 316/320 bytes.
 * symbols:
 *   func_021E8738 0x021E8738 thumb ov177
 *   func_021E8AB4 0x021E8AB4 thumb ov177
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_021E8844 0x021E8844 thumb ov177
 *   func_021E8AB8 0x021E8AB8 thumb ov177
 *   func_021D9F04 0x021D9F04 thumb ov175
 *   func_021D9A1C 0x021D9A1C thumb ov175
 *   func_021D9A30 0x021D9A30 thumb ov175
 *   func_021D9064 0x021D9064 thumb ov175
 *   func_021D7E18 0x021D7E18 thumb ov175
 *   func_021D8E30 0x021D8E30 thumb ov175
 *   func_021D9344 0x021D9344 thumb ov175
 *   func_021D8EC8 0x021D8EC8 thumb ov175
 *   func_021D98E4 0x021D98E4 thumb ov175
 *   func_021D9A08 0x021D9A08 thumb ov175
 *   func_021D99F4 0x021D99F4 thumb ov175
 *   func_02040588 0x02040588 arm
 */
typedef unsigned long u32;
typedef unsigned char  u8;
struct Obj;
extern void func_021E8738(int *p, int a, int b, int c);
extern void func_021E8AB4(u32,u32);
extern void func_021E8AA0(int *p, int v);
extern void func_021E8AB8(u32);
extern int func_021E8844(const int *p);
extern int func_02012DAC(int a0);
extern int func_021D9D50(char *,u32 *);
extern int func_021D9F04(char *,void *,void *);
extern void func_021D9A1C(char *,void *);
extern u32 func_021D9A30(char *);
extern void func_021D8EC8(u32 sys, int *state, char *p);
extern void func_021D9064(void *obj, int unused, u8 *p);
extern void func_021D9090(u32 sys, int *state, char *p);
extern void func_02040588(u32,u32);
extern void func_021D98E4(char *,u32),func_021D99F4(char *);
extern int func_021D9A08(char *);
extern void func_021D7E18(u32 sys, int *state, struct Obj *obj);
extern void func_021D8E30(u32 sys, int *state, char *ctx);
extern void func_021D9344(u32 sys, int *state, char *p);
void func_021D8CF0(u32 sys,int *state,char *p)
{
    int v;
    switch(*state) {
    case 0:
        switch(func_021D9F04(*(char **)(p+52),0,(void *)1)) {
        case 0:case 1:case 4:*state=1;break;
        case 2:func_021E8AA0((int *)sys,(int)func_021D9064);break;
        }break;
    case 1:func_02040588(0,1);
        func_021E8738((int *)(*(u32 *)(p+44)),*(u32 *)(p+20),92,1);
        *state=7;func_021E8AB4(sys,2);break;
    case 2:func_021D98E4(p,4);*state=3;break;
    case 3:v=func_021D9A08(p);
        if(v!=-1) {
            func_021D99F4(p);
            switch(v) {
            case 0:func_021E8AA0((int *)sys,(int)func_021D7E18);break;
            case 1:*state=4;break;
            case 2:func_021E8AA0((int *)sys,(int)func_021D8E30);break;
            }
        }break;
    case 4:func_021D9A1C(p,func_021D9344);*state=5;break;
    case 5:v=func_021D9A30(p);
        if(v==1 || v==2) *state=1;
        else if(v==0) *state=6;
        v=func_021D9F04(*(char **)(p+52),0,0);
        switch(v) {
        case 1:case 2:func_021E8AA0((int *)sys,(int)func_021D9064);break;
        }
        break;
    case 6:func_021E8AA0((int *)sys,(int)func_021D8EC8);break;
    case 7:if(func_021E8844((const int *)(*(u32 *)(p+44))))func_021E8AB8(sys);break;
    }
}
