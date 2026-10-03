/*
 * function: func_021C5404
 * address: 0x021C5404
 * packet: pkt_ov127_021C5404
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C49A4 0x021C49A4 thumb ov127
 *   func_021C54EC 0x021C54EC thumb ov127
 *   func_021C5550 0x021C5550 thumb ov127
 *   func_021C5564 0x021C5564 thumb ov127
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_021C49A4(u8 *p, unsigned int i);
extern int func_021C54EC(void *, void *, int);
extern int func_021C5550(void *, void *, int);
extern void func_021C5564(u8 *out, void *p, int kind, int index, int value);
int func_021C5404(void *p, void *q, void *r, const u8 *s, void *t)
{
    int v = func_021C49A4(p, 5);
    if (v == 0 && func_021C54EC(p, q, s[2]) != 1 && func_021C5550(p, r, s[2]) != 1) {
        func_021C5564(t, p, *(u16 *)s, s[3], s[2]);
        return 1;
    }
    if (v == 0 && func_021C49A4(p, 10) >= 8) {
        func_021C5564(t, p, 5, s[3], s[2]);
        return 1;
    }
    return 0;
}
