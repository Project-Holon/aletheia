/*
 * function: func_0217B55C
 * address: 0x0217B55C
 * packet: pkt_ov176_0217B55C
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0217B93C 0x0217B93C thumb ov176
 *   func_0217B964 0x0217B964 thumb ov176
 *   func_0217B4A0 0x0217B4A0 thumb ov176
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 */
extern void func_0217B93C(int *,int);
extern int func_0217B964(int *);
extern void func_0217B4A0(void);
extern void func_021E8AA0(int,int);
void func_0217B55C(int p,int *state,int *q)
{
    switch(*state) {
    case 0: func_0217B93C(q,8); *state=1; break;
    case 1: if(func_0217B964(q)==1) func_021E8AA0(p,(int)func_0217B4A0); break;
    }
}
