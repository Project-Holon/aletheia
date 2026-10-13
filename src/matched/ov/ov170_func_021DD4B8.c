/*
 * function: func_021DD4B8
 * address: 0x021DD4B8
 * packet: pkt_ov170_021DD4B8
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: declaring m before box selects r7 for m and r6 for box.
 * symbols:
 *   func_021DD684 0x021DD684 thumb ov170
 *   func_021DD8A8 0x021DD8A8 thumb ov170
 *   func_021DD314 0x021DD314 thumb ov170
 *   func_021EDAB0 0x021EDAB0 thumb ov170
 *   func_021EDB34 0x021EDB34 thumb ov170
 *   func_0201AB28 0x0201AB28 thumb
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   POKE_TOOL_ChangeForm 0x02017988 thumb
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_0200CFA0 0x0200CFA0 thumb
 *   POKE_TOOL_GetBoxParam 0x020185F4 thumb
 *   func_0200752C 0x0200752C thumb
 */
extern int func_021DD684(unsigned char *,unsigned);
extern void func_021DD8A8(unsigned char *,unsigned);
extern void func_021DD314(char **p, int a, unsigned b);
extern void func_021EDAB0(char *p, int i);
extern void func_021EDB34(char *p, int a);
extern void *func_0201AB28(void *,unsigned);
extern unsigned POKE_TOOL_GetPartyValue(void *,unsigned,unsigned);
typedef unsigned int   u32;
struct Blk37;
struct Sub02007454Entry;
extern u32 POKE_TOOL_ChangeForm(void *p, u32 a);
extern void *func_0200CA1C(void *);
extern void func_0200CFA0(struct Blk37 *p, void *m);
extern void *POKE_TOOL_GetBoxParam(void *);
extern int func_0200752C(void **save, u32 box, const struct Sub02007454Entry *src);
void func_021DD4B8(unsigned char *p,unsigned a,unsigned b)
{
    void *m;
    unsigned box;
    box=func_021DD684(p,b);
    m=func_0201AB28((*(void ***)p)[2],a-30);
    if(POKE_TOOL_GetPartyValue(m,5,0)==492){
        POKE_TOOL_ChangeForm(m,0);
        func_021DD8A8(p,a);
        func_0200CFA0(func_0200CA1C((*(void ***)p)[0]),m);
    }
    func_0200752C((*(void ***)p)[1],box,POKE_TOOL_GetBoxParam(m));
    func_021DD314((char **)p,p[0x14],a);
    func_021EDAB0((char *)p,box);
    func_021EDB34((char *)p,box);
}
