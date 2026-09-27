/*
 * function: func_021D74D8
 * address:  0x021D74D8
 * packet:   pkt_ov125_021D74D8
 * region:   ov125
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * Recursive MATCH unblocker: unresolved callee named by the parked
 * func_021FF698 and func_021FF698's host func_021D74D8.  Reads the record at
 * r = func_021D85E8(a0); publishes r+0x10 to *out; when the shadowed pair at
 * +0xc8/+0xcc differs from the live pair at +8/+0xc it refreshes them and
 * re-derives the halfword at *out+0xc0 through 0x0203F1FC(*out+0x80, 0x38).
 *
 * symbols:
 *   func_021D85E8  0x021D85E8  arm
 *   func_0203F1FC  0x0203F1FC  arm
 *
 * Addresses are Black-image addresses.
 */

typedef signed short s16;

extern int *func_021D85E8(int);
extern int func_0203F1FC(int, int);

int func_021D74D8(int a0, int *out)
{
    int *r = func_021D85E8(a0);
    int live0;
    int live1;

    *out = (int)((char *)r + 0x10);
    live0 = r[2];
    live1 = r[3];
    if ((r[0x32] ^ live0) | (r[0x33] ^ live1)) {
        r[0x32] = live0;
        r[0x33] = live1;
        *(s16 *)((char *)*out + 0xc0) =
            func_0203F1FC(*out + 0x80, 0x38);
    }
    return live0;
}
