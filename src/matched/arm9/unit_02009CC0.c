/*
 * unit:     yes
 * function: func_02009CC0
 * address:  0x02009CC0
 * packet:   pkt_02009CC0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020598EC    0x020598EC  arm
 *
 * Compared as a unit rather than as a single function because the packet's
 * range runs two bytes past the last instruction: `match.py one` sees the
 * original as 36 bytes against the compiler's 34 and reports EXACT*, while
 * `tu` lays the section out and reproduces the linker's two-byte filler.
 */

typedef unsigned char u8;

extern void *func_02009860(void *p);
extern void  func_02009CB0(void *p, void *buf);
struct DWCstAccUserData;
extern int func_020598EC(struct DWCstAccUserData *userdata, void *frienddata);

void func_02009CC0(void *a0)
{
    u8 buf[12];
    void *h = func_02009860(a0);

    func_02009CB0(a0, buf);
    func_020598EC(h, buf);
}
