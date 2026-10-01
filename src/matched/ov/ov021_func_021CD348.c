/*
 * function: func_021CD348
 * address:  0x021CD348
 * packet:   pkt_ov021_021CD348
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blocked (MATCH, every concrete byte right): the pooled word 0x000000C2 is a
 * pooled small constant (abs_id_C2, R_ARM_ABS32) passed to func_020146F8, not
 * in match.py's OVERLAY_ID_CONSUMERS; no other pool word holds 0x000000C2
 * outside this range (same blocker as pending ov021_func_021C5A54).
 *
 * symbols:
 *   func_020146F8  0x020146F8  thumb
 *   func_02012374  0x02012374  thumb
 *   func_021CD3A4  0x021CD3A4  thumb  ov021
 *   func_02045808  0x02045808  arm
 *   abs_id_C2      0x000000C2  data
 *   d_021F5580     0x021F5580  data  ov075  a4
 */

typedef unsigned char u8;

extern char d_021F5580;
extern unsigned char abs_id_C2[];

extern int func_020146F8(int a, int b, const void *id, const char *file, void *e);
extern void func_02012374(int a, int b);
extern void func_021CD3A4(u8 *a, u8 *b);
extern void func_02045808(int a);

int func_021CD348(int a, int *st, u8 *c)
{
    int r;

    switch (*st) {
    case 0:
        r = func_020146F8(*(int *)c, *(int *)(c + 0x10), abs_id_C2, &d_021F5580, c + 0x1c);
        func_02012374(a, r);
        (*st)++;
        break;
    case 1:
        func_021CD3A4(c, c + 0x1c);
        func_02045808(*(int *)(c + 0x3c));
        return 1;
    }
    return 0;
}
