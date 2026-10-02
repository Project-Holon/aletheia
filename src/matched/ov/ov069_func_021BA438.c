/*
 * function: func_021BA438
 * address: 0x021BA438
 * packet: pkt_ov069_021BA438
 * region: ov069
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: Two bytes of alignment padding follow.
 * lever: Inline the getter result into the sum; a named result reverses
 * the final adds operands (one concrete byte).
 * symbols:
 *   func_021BA384 0x021BA384 thumb ov069
 *   func_021BA480 0x021BA480 thumb ov069
 *   func_020260E0 0x020260E0 thumb
 *   func_021B9FF0 0x021B9FF0 thumb ov069
 */
extern void func_021BA384(char *o, int i, int n);
extern void func_021BA480(void *o);
extern int func_020260E0(void *o);
extern void func_021B9FF0(void *p, void *list, int idx);
void func_021BA438(char *p, int i)
{
    *(unsigned short *)(p + 0x160) = i;
    func_021BA384(p, i, *(unsigned short *)(p + 0x162));
    func_021BA480(p);
    func_021B9FF0(p, *(void **)(p + 8), *(unsigned short *)(p + 0x160) * 10 + func_020260E0(*(void **)(p + 0x14C)));
}
