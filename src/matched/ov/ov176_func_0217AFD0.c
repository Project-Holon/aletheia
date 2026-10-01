/*
 * function: func_0217AFD0, func_0217B00C
 * address: 0x0217AFD0
 * packet: pkt_ov176_0217AFD0
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * unit: yes
 * status: EXACT
 * symbols:
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_021E8AA8 0x021E8AA8 thumb ov177
 *   func_0217B0C8 0x0217B0C8 thumb ov176
 *   func_0217B1BC 0x0217B1BC thumb ov176
 */
extern void func_021E8AA0(void *,void *);
extern void func_021E8AA8(void *);
extern void func_0217B0C8(void *,int,char *);
extern void func_0217B1BC(void *,int,char *);
void func_0217AFD0(void *a,int b,char *p)
{
    switch(*(unsigned *)(*(char **)(p+0x28)+4)){
    case 0: case 1: case 2:
        func_021E8AA0(a,func_0217B0C8); break;
    case 3: case 4: case 5: case 6:
        func_021E8AA0(a,func_0217B1BC); break;
    }
}
void func_0217B00C(void *a)
{
    func_021E8AA8(a);
}
