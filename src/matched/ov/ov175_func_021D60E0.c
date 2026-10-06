/*
 * function: func_021D60E0
 * address: 0x021D60E0
 * packet: pkt_ov175_021D60E0
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E8738 0x021E8738 thumb ov177
 *   func_021E8AB4 0x021E8AB4 thumb ov177
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_021E8844 0x021E8844 thumb ov177
 *   func_021E8AB8 0x021E8AB8 thumb ov177
 *   func_021D6550 0x021D6550 thumb ov175
 *   func_021D65DC 0x021D65DC thumb ov175
 *   func_021D65C8 0x021D65C8 thumb ov175
 *   func_021D6048 0x021D6048 thumb ov175
 *   func_021D61CC 0x021D61CC thumb ov175
 */
typedef unsigned int u32;
extern void func_021E8738(int *p, int a, int b, int c);
extern void func_021E8AB4(u32,u32);
extern void func_021E8AA0(int *p, int v);
extern int func_021E8844(const int *p);
extern void func_021E8AB8(u32);
extern void func_021D6550(u32 *,int);
extern int func_021D65DC(char *);
extern void func_021D65C8(char *obj);
extern void func_021D6048(unsigned sys, int *state, int *p);
extern void func_021D61CC(void *a, u32 **pp, char *p);
void func_021D60E0(u32 sys,int *state,u32 *p)
{
    u32 *ctx=(u32 *)p[16];
    int result;
    switch(*state) {
    case 0:
        func_021E8738((int *)p[9],p[4],39,1); *state=5; func_021E8AB4(sys,1); break;
    case 1: func_021D6550(p,0); *state=2; break;
    case 2:
        result=func_021D65DC((char *)p);
        if(result!=-1) {
            func_021D65C8((char *)p);
            switch(result) {
            case 0: ctx[1]=0; *state=3; break;
            case 1: func_021E8AA0((int *)sys,(int)func_021D6048); break;
            }
        }
        break;
    case 3: func_021E8738((int *)p[9],p[4],43,2); *state=5; func_021E8AB4(sys,4); break;
    case 4: func_021E8AA0((int *)sys,(int)func_021D61CC); break;
    case 5: if(func_021E8844((const int *)p[9])) func_021E8AB8(sys); break;
    }
}
