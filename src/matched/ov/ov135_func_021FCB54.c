/*
 * function: func_021FCB54
 * address:  0x021FCB54
 * packet:   pkt_021FCB54
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020185F0  0x020185F0  thumb
 *   func_0202D6F4  0x0202D6F4  thumb
 *   func_020862F0  0x020862F0  arm
 *   func_0207E780  0x0207E780  arm
 *   func_020307B0  0x020307B0  arm
 *   func_0202D060  0x0202D060  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017EAC  0x02017EAC  thumb
 *   func_0202D0D4  0x0202D0D4  thumb
 *   func_02049B40  0x02049B40  arm
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad0[0x14];
    void *data;
} PalFile;

extern void *func_020185F0(void);
extern void *func_0202D6F4(PalFile **out, void *src, u32 a2, u32 heap);
extern void func_020862F0(void *p, u32 n);
extern void func_0207E780(void *src, u32 dst, u32 n);
extern void func_020307B0(void *p);
extern u32 func_0202D060(void);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern u32 func_02017EAC(void *mon);
extern u32 func_0202D0D4(u32 h, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);

void func_021FCB54(void *mon)
{
    PalFile *pal;
    void *h;
    u32 arc;
    u32 species;
    u32 form;
    u32 shiny;
    u32 id;

    h = func_0202D6F4(&pal, func_020185F0(), 0, 0x48);
    func_020862F0(pal->data, 0x1200);
    func_0207E780(pal->data, 0x3F80, 0x1200);
    func_020307B0(h);
    arc = func_0202D060();
    species = func_02017E1C(mon, 5, 0);
    form = func_02017E1C(mon, 0x6F, 0);
    shiny = func_02017E1C(mon, 0x6E, 0);
    id = func_0202D0D4(arc, species, form, shiny, func_02017EAC(mon), 0, 0);
    func_02049B40(func_0202D060(), id, 1, 0x1A0, 0x20, 0x48);
}
