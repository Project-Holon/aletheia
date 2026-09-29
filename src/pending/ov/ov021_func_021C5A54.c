/*
 * function: func_021C5A54
 * address:  0x021C5A54
 * packet:   pkt_ov021_021C5A54
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Blocked (MATCH, every concrete byte right): the pooled word 0x000000C2 is a
 * pooled small constant (abs_id_C2, R_ARM_ABS32) passed as the third argument
 * to func_020146F8 / func_02014728, neither of which is in match.py's
 * OVERLAY_ID_CONSUMERS, and no other pool word image-wide holds 0x000000C2,
 * so no evidence class attests it.  d_021F5580 resolves with the ov075 token.
 *
 * symbols:
 *   func_020146F8  0x020146F8  thumb
 *   func_02014728  0x02014728  thumb
 *   func_02012374  0x02012374  thumb
 *   abs_id_C2      0x000000C2  data
 *   d_021F5580     0x021F5580  data  ov075  a4
 */

extern char d_021F5580;
extern unsigned char abs_id_C2[];

extern int func_020146F8(int a, int b, const void *id, const char *file, int e);
extern int func_02014728(int a, int b, const void *id, const char *file, int e);
extern void func_02012374(int a, int b);

int func_021C5A54(int a, int *st, int *c)
{
    int r;

    switch (*st) {
    case 0:
        if (c[3] != 0) {
            r = func_020146F8(c[0], c[1], abs_id_C2, &d_021F5580, c[2]);
        } else {
            r = func_02014728(c[0], c[1], abs_id_C2, &d_021F5580, c[2]);
        }
        func_02012374(a, r);
        (*st)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}
