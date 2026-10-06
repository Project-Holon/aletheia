/*
 * function: func_0217C2A0
 * address:  0x0217C2A0
 * packet:   pkt_ov018_0217C2A0
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The const on the entry pointer is what lets the bitfield loads be
 * scheduled above the outgoing stack-argument stores (48 bytes otherwise).
 * symbols:
 *   func_0204A1BC  0x0204A1BC  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02012944  0x02012944  thumb
 *   func_02008530  0x02008530  thumb
 *   func_020186C8  0x020186C8  thumb
 *   func_020173F0  0x020173F0  thumb
 *   func_02017588  0x02017588  thumb
 *   func_02018A00  0x02018A00  thumb
 *   func_02017988  0x02017988  thumb
 *   func_0201808C  0x0201808C  thumb
 *   func_020180F4  0x020180F4  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct {
    u32 species : 11;
    u32 move : 10;
    u32 f21 : 2;
    u32 f23 : 6;
    u32 f29 : 3;
} Entry;

extern int func_0204A1BC(int a0, int a1, int a2, int a3);
extern u32 func_020307B0(void *p);
struct Mon;
extern u8 *func_02012944(void *p);
struct Sub0200852CObj;
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern u32 func_020186C8(u32 a0, int a1, int a2, int a3, int a4, int a5);
extern void *func_020173F0(u16, u16, u64, int);
extern void func_02017588(struct Mon *p, u16 species, u16 level, unsigned long long id, u32 pow, unsigned long long rnd);
extern void func_02018A00(void *p, u32 a, u32 b);
extern u32 func_02017988(void *p, u32 a);
extern u16 func_0201808C(void *, u16);
extern void func_020180F4(void *, u16);

void *func_0217C2A0(int heap, void *a1, const Entry *e)
{
    u8 *tbl;
    u8 lvl;
    u32 id;
    u32 pid;
    void *mon;

    tbl = (u8 *)func_0204A1BC(0xE3, 0, 0, heap);
    lvl = tbl[e->species];
    func_020307B0(tbl);
    id = func_02008530((const struct Sub0200852CObj *)func_02012944(a1));
    pid = func_020186C8(id, (u16)e->species, (u16)e->f23, e->f21, 0, 0);
    mon = func_020173F0(e->species, lvl, -1, heap);
    func_02017588(mon, e->species, lvl, id, -1, pid);
    func_02018A00(mon, e->species, e->f23);
    func_02017988(mon, (u16)e->f23);
    if (e->move != 0) {
        if (func_0201808C(mon, e->move) == 0xFFFF)
            func_020180F4(mon, e->move);
    }
    return mon;
}
