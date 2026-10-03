/*
 * function: func_021B6708
 * address:  0x021B6708
 * packet:   pkt_ov021_021B6708
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_02012934  0x02012934  thumb
 *   func_0201293C  0x0201293C  thumb
 *   func_02012944  0x02012944  thumb
 *   func_021B6850  0x021B6850  thumb  ov021
 *   func_020173EC  0x020173EC  thumb
 *   func_02030734  0x02030734  arm
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0202136C  0x0202136C  thumb
 *   func_02008FEC  0x02008FEC  thumb
 *   func_02008F08  0x02008F08  thumb
 *   func_02009020  0x02009020  thumb
 *   func_0200903C  0x0200903C  thumb
 *   func_02008EAC  0x02008EAC  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02017988  0x02017988  thumb
 *   func_020185C4  0x020185C4  thumb
 *   func_02007A18  0x02007A18  thumb
 *   func_0201747C  0x0201747C  thumb
 *   func_0201AB48  0x0201AB48  thumb
 *   func_020185F0  0x020185F0  thumb
 *   func_020075B0  0x020075B0  thumb
 *   d_021DE270     0x021DE270  data   ov021  a1
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0215A5E4(void *a0);
extern u32 func_0215A5CC(u32 a);
struct BigObj;
struct Party;
struct PartyMon;
struct Sub020075B0Entry;
struct Sub020079BCEntry;
struct Sub02008EACObj;
struct Sub02008F80Obj;
extern void *func_02012934(const struct BigObj *p);
extern void *func_0201293C(void *a);
extern u8 *func_02012944(void *p);
extern int func_021B6850(void *a, u16 b, u16 *c, u16 *d);
extern u32 func_020173EC(void);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_0201AB28(void *p, u32 idx);
extern void func_02082D44(void *src, void *dst, u32 n);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern u32 func_0202136C(u16 v);
extern struct Sub02008F80Obj *func_02008FEC(void *sys);
extern void *func_02008F08(int a0);
extern int func_02009020(void *obj, int v);
extern void func_0200903C(struct Sub02008F80Obj *arr, u32 unused, int i, const struct Sub02008F80Obj *src);
extern void func_02008EAC(struct Sub02008EACObj *obj);
extern void func_02017E40(void *mon, u32 id, void *v);
extern void func_020307B0(void *p);
extern u32 func_02017988(void *p, u32 a);
extern void func_020185C4(void *mon);
extern struct Sub020079BCEntry *func_02007A18(void **save, u32 box, u32 slot);
extern void *func_0201747C(void *p, u32 heap);
extern void func_0201AB48(struct Party *p, u32 idx, const struct PartyMon *src);
extern void *func_020185F0(void *mon);
extern int func_020075B0(void *save, u32 box, u32 slot, const struct Sub020075B0Entry *src);
extern u8 d_021DE270[];

void func_021B6708(u32 a, int idx)
{
    void *sv;
    void *party;
    u32 heap;
    void *save;
    void *mon;
    u32 sz;
    void *o;
    void *buf;
    int i;
    void *m;
    u16 pos[2];

    sv = func_0215A5E4((void *)a);
    party = func_02012934((void *)sv);
    if (func_021B6850(sv, 0x283, &pos[1], &pos[0]) == 0) {
        return;
    }
    heap = func_0215A5CC(a);
    save = func_0201293C(sv);
    mon = func_02030734(heap, func_020173EC(), 1, (const char *)d_021DE270, 0x4c7);
    sz = func_020173EC();
    func_02082D44(func_0201AB28(party, idx), mon, sz);
    if (func_0202136C(func_02017E1C(mon, 6, 0)) == 1) {
        o = func_02008FEC(sv);
        buf = func_02008F08(func_0215A5CC(a));
        i = func_02009020(o, 0);
        func_02017E1C(mon, 0xa7, (u32)buf);
        func_02012944(sv);
        if (i >= 0) {
            func_0200903C(o, 0, i, buf);
        }
        func_02008EAC(buf);
        func_02017E40(mon, 0xa7, buf);
        func_02017E40(mon, 6, 0);
        func_020307B0(buf);
    }
    if (func_02017E1C(mon, 0xab, 0) == 0x1ec) {
        func_02017988(mon, 0);
        func_020185C4(mon);
    }
    m = func_0201747C(func_02007A18(save, pos[1], pos[0]), heap);
    func_0201AB48(party, idx, m);
    func_020307B0(m);
    func_020075B0(save, pos[1], pos[0], func_020185F0(mon));
    func_020307B0(mon);
}
