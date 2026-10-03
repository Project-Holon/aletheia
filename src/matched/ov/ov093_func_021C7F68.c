/*
 * function: func_021C7F68
 * address:  0x021C7F68
 * packet:   pkt_ov093_021C7F68
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Named by the parked ov093 file func_021D85F4.c.  Builds a candidate list in
 * a local buffer and copies the accepted entries to `out`.  EXACT*: the
 * completed extent runs into an unlabelled follower.  Three levers: `n` must
 * be volatile (it is spilled/reloaded around the loop calls), the boolean is
 * materialised through a `?:` rather than a bare `&&`, and the `u8` locals
 * are declared `j` before `i` with both initialised in the for-clause.
 *
 * symbols:
 *   func_021B8778   0x021B8778  thumb  ov093
 *   func_021B98A4   0x021B98A4  thumb  ov093
 *   func_021D5B68   0x021D5B68  thumb  ov093
 *   func_021D5440   0x021D5440  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern int func_021B8778(int a, int b, u8 *buf);
extern u8 *func_021B98A4(char *const *q, u8 b);
extern int func_021D5B68(void *p);
extern u8 func_021D5440(u8 *p);

int func_021C7F68(int *p, int b, u8 *out)
{
    u8 buf[8];
    volatile u32 n = (u32)func_021B8778(p[1], b, buf);
    u8 j;
    u8 i;

    for (i = 0, j = 0; i < n; i++) {
        u8 *x = func_021B98A4((char *const *)p[2], buf[i]);
        int ok = (x != 0) ? (func_021D5B68(x) == 0) : 0;

        if (ok)
            out[j++] = func_021D5440(x);
    }
    return j;
}
