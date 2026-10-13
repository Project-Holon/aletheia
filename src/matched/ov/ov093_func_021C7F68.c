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
 * Named by the parked ov093 file BTL_CALC_IntimidateOnEnter.c.  Builds a candidate list in
 * a local buffer and copies the accepted entries to `out`.  EXACT*: the
 * completed extent runs into an unlabelled follower.  Three levers: `n` must
 * be volatile (it is spilled/reloaded around the loop calls), the boolean is
 * materialised through a `?:` rather than a bare `&&`, and the `u8` locals
 * are declared `j` before `i` with both initialised in the for-clause.
 *
 * symbols:
 *   BTL_MAIN_DecodeMessageCode   0x021B8778  thumb  ov093
 *   func_021B98A4   0x021B98A4  thumb  ov093
 *   BTL_POKEPARAM_IsFainted   0x021D5B68  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId   0x021D5440  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Unk021B8CB0;
extern u8 BTL_MAIN_DecodeMessageCode(struct Unk021B8CB0 **p, int k, u8 *out);
extern u8 *func_021B98A4(char *const *q, u8 b);
extern int BTL_POKEPARAM_IsFainted(void *p);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);

u8 func_021C7F68(int *p, int b, u8 *out)
{
    u8 buf[8];
    volatile u32 n = (u32)BTL_MAIN_DecodeMessageCode((struct Unk021B8CB0 **)p[1], b, buf);
    u8 j;
    u8 i;

    for (i = 0, j = 0; i < n; i++) {
        u8 *x = func_021B98A4((char *const *)p[2], buf[i]);
        int ok = (x != 0) ? (BTL_POKEPARAM_IsFainted(x) == 0) : 0;

        if (ok)
            out[j++] = BTL_POKEPARAM_GetPokeId(x);
    }
    return j;
}
