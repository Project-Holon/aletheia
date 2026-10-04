/*
 * function: func_0215C2D0
 * address:  0x0215C2D0
 * packet:   pkt_ov010_0215C2D0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: add a level-1 Pokemon egg of the given species and
 * form to the party (hatch counter from the personal data, the egg name
 * from message 0x28A), writing 1 to the result word, or 0 when the
 * party is full. First draft.
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02012934  0x02012934  thumb
 *   func_02012944  0x02012944  thumb
 *   func_0201AA14  0x0201AA14  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_020173F0  0x020173F0  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02008510  0x02008510  thumb
 *   func_02045808  0x02045808  arm
 *   func_0201ADE4  0x0201ADE4  thumb
 *   func_0201AE1C  0x0201AE1C  thumb
 *   func_0201AE14  0x0201AE14  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_020185C4  0x020185C4  thumb
 *   func_0202F190  0x0202F190  thumb
 *   func_0201A98C  0x0201A98C  thumb
 *   func_020307B0  0x020307B0  arm
 *   g_020A7370     0x020A7370  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

extern void *func_0215A5DC(void *vm);
extern void *func_0215A5E4(void *vm);
struct BigObj;
struct Party;
struct PartyMon;
extern u16 func_0215A5CC(void *a0);
extern u16 *func_02159AE8(void *c, void *vm);
extern u16 func_02159B10(void *c, void *vm);
extern void *func_02012934(const struct BigObj *p);
extern u8 *func_02012944(void *p);
extern int func_0201AA14(void *party);
extern u32 func_0201AA18(void *party);
extern void *func_020173F0(u32 species, u32 level, u64 id, u32 heap);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern u32 func_02008510(void *my, u32 heap);
extern void func_02045808(u32 buf);
extern void *func_0201ADE4(unsigned int species, int form, unsigned int heap);
extern u32 func_0201AE1C(u32 h, u32 k);
extern void func_0201AE14(u32 h);
extern u32 func_02045EC0(void *bank, u32 index);
extern void func_020185C4(void *mon);
extern void func_0202F190(void *mon, u32 a1, void *a2, u32 a3, u32 heap);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern void func_020307B0(void *p);
extern void *g_020A7370;

int func_0215C2D0(void *c, void *vm)
{
    void *sys;
    u32 heap;
    void *party;
    void *my;
    u16 *res;
    u16 species;
    u16 form;
    void *mon;
    u32 t;
    u32 info;
    u32 v;

    func_0215A5DC(vm);
    sys = func_0215A5E4(vm);
    heap = func_0215A5CC(vm);
    party = func_02012934(sys);
    my = func_02012944(sys);
    res = func_02159AE8(c, vm);
    species = func_02159B10(c, vm);
    form = func_02159B10(c, vm);
    if (func_0201AA14(party) <= (int)func_0201AA18(party)) {
        *res = 0;
        return 0;
    }
    mon = func_020173F0(species, 1, (u64)-1, heap);
    func_02017E40(mon, 0x6F, form);
    t = func_02008510(func_02012944(sys), heap);
    func_02017E40(mon, 0x8D, t);
    func_02045808(t);
    info = (u32)func_0201ADE4((u16)func_02017E1C(mon, 5, 0), (u16)func_02017E1C(mon, 0x6F, 0), heap);
    v = func_0201AE1C(info, 0x15);
    func_0201AE14(info);
    func_02017E40(mon, 9, v);
    func_02017E40(mon, 0x4C, 1);
    t = func_02045EC0(g_020A7370, 0x28A);
    func_02017E40(mon, 0x73, t);
    func_02045808(t);
    func_020185C4(mon);
    func_0202F190(mon, 5, my, 0xEA63, heap);
    func_0201A98C(party, mon);
    func_020307B0(mon);
    *res = 1;
    return 0;
}
