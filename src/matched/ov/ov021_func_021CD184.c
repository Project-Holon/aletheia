/*
 * function: func_021CD184
 * address:  0x021CD184
 * packet:   pkt_ov021_021CD184
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Selector 0 or 1 path of func_021CCF60: applies the +4 or +8 entry, then refreshes the two per-selector views.
 *
 * symbols:
 *   func_021CD050  0x021CD050  thumb  ov021
 *   func_021CCBE0  0x021CCBE0  thumb  ov021
 *   func_021CCE48  0x021CCE48  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

typedef struct {
    void *f0;
    void *f4;
    void *f8;
} Obj;

extern void func_021CD050(Obj *o, void *e);
typedef unsigned char  u8;
extern void func_021CCBE0(u8 *s, int flag);
extern void func_021CCE48(u8 *s, int flag);

void func_021CD184(Obj *o, u32 sel)
{
    func_021CD050(o, sel == 0 ? o->f4 : o->f8);
    func_021CCBE0((u8 *)o, sel);
    func_021CCE48((u8 *)o, sel);
}
