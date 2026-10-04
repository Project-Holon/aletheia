/*
 * function: func_021D6BF4
 * address: 0x021D6BF4
 * packet: pkt_ov175_021D6BF4
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_021DA36C 0x021DA36C thumb ov175
 *   func_021D97D0 0x021D97D0 thumb ov175
 *   func_021D6C54 0x021D6C54 thumb ov175
 *   func_021D8904 0x021D8904 thumb ov175
 *   func_021D8BC4 0x021D8BC4 thumb ov175
 */
typedef unsigned int u32;
extern void func_021E8AA0(int *p, int v);
extern void func_021DA36C(u32);
extern void func_021D97D0(char *);
extern void func_021D6C54(u32 sys, int *state, u32 *p);
extern void func_021D8904(u32 sys, int *state, char *p);
extern void func_021D8BC4(void);
void func_021D6BF4(u32 sys,void *unused,char *p)
{
    switch (((u32 *)*(u32 *)(p+0x104))[3]) {
    case 0: func_021E8AA0((int *)sys,(int)func_021D6C54); break;
    case 2:
        func_021DA36C(*(u32 *)(p+0x34));
    case 1:
        func_021D97D0(p);
        func_021E8AA0((int *)sys,(int)func_021D8904);
        break;
    case 3: func_021D97D0(p); func_021E8AA0((int *)sys,(int)func_021D8BC4); break;
    }
}
