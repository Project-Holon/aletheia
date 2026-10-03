/*
 * function: func_0202B84C
 * address:  0x0202B84C
 * packet:   pkt_0202B84C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     wave 16: promoted.  0x0209FF8C was never a second table: it is
 *           Data_0209FF88 + 4, the `enter` field of entry v, which the
 *           compiler reaches through its own pool word because a register
 *           offset load has no immediate (docs/idioms/
 *           pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md).
 *           One symbol, one struct with both callbacks; the +4 site then
 *           resolves against the attested 0x0209FF88.
 * symbols:
 *   Data_0209FF88  0x0209FF88  data
 *   func_0202B818  0x0202B818  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct {
    u8   id;
    u8   pad[3];
    void (*enter)(void *);
    void (*leave)(void *);
} Entry;

extern const Entry Data_0209FF88[];
struct Obj;
extern u8 func_0202B818(struct Obj *o);

void func_0202B84C(void *a)
{
    int v = func_0202B818(a);
    int i;

    for (i = 0; i < 9; i++) {
        if (v != Data_0209FF88[i].id && Data_0209FF88[i].leave != 0) {
            Data_0209FF88[i].leave(a);
        }
    }
    if (Data_0209FF88[v].enter != 0) {
        Data_0209FF88[v].enter(a);
    }
}
