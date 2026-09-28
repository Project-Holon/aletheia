/*
 * function: func_021C56E8
 * address:  0x021C56E8
 * packet:   pkt_ov111_021C56E8
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C5008  0x021C5008  thumb  ov111
 *   func_021C555C  0x021C555C  thumb  ov111
 *   func_021C5B80  0x021C5B80  thumb  ov111
 *   func_021C567C  0x021C567C  thumb  ov111
 *   func_021C5054  0x021C5054  thumb  ov111
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

typedef struct {
    u8 pad0[0x3060];
    int mode;
} Work;

extern int func_021C5008(Work *p);
extern void func_021C555C(Work *p);
extern void func_021C5B80(Work *p);
extern int func_021C567C(Work *p);
extern int func_021C5054(Work *p);

int func_021C56E8(Work *p)
{
    func_021C5008(p);
    func_021C555C(p);
    func_021C5B80(p);
    if (p->mode == 1) {
        return func_021C567C(p);
    }
    return func_021C5054(p);
}
