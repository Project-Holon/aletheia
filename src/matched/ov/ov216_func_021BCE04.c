/*
 * function: func_021BCE04
 * address: 0x021BCE04
 * packet: pkt_ov216_021BCE04
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02165DAC 0x02165DAC thumb ov010
 *   func_02165DF0 0x02165DF0 thumb ov010
 *   func_02165DBC 0x02165DBC thumb ov010
 *   func_02165D28 0x02165D28 thumb ov010
 */
struct Bits;
extern unsigned func_02165DAC(const char *);
extern unsigned short func_02165DF0(const char *);
extern unsigned short func_02165DBC(const char *);
extern unsigned short func_02165D28(const struct Bits *);
typedef unsigned short u16;
typedef unsigned int   u32;
struct WordSet;
extern u32 func_02013E4C(u32 id);
extern void func_0201EE60(struct WordSet *p, u32 i, u16 v);
extern void func_0201F104(struct WordSet *p, u32 i, u32 a);
extern void func_0201F134(struct WordSet *p, u32 i, u32 v);
extern void func_0201F158(struct WordSet *p, u32 i, u32 v);
void func_021BCE04(void *p,void *q)
{
    switch(func_02165DAC(p)) {
    case 0: case 1:
        func_0201EE60(q,0,func_02165DF0(p)); break;
    case 2: {
        unsigned a=func_02165DBC(p);
        func_0201F104(q,0,a); func_0201F134(q,1,a); break;
    }
    case 3: case 4: break;
    default: {
        unsigned a=func_02165D28(p);
        if(a>=427) a=317;
        func_0201F158(q,0,func_02013E4C(a)); break;
    }
    }
}
