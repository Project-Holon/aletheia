/*
 * function: func_021E0C44
 * address: 0x021E0C44
 * packet: pkt_ov119_021E0C44
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: MATCH
 * 2026-10-02: byte-correct; only blocker is the wildcarded call to the unlabelled
 * tail-call stub 0x02010934 (inside matched unit_0201088C, no label).
 * symbols:
 *   func_02010904 0x02010904 thumb
 *   func_02010934 0x02010934 thumb
 *   func_021E02E8 0x021E02E8 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021E0C78 0x021E0C78 thumb ov119
 */
extern unsigned func_02010904(void *);
extern void func_02010934(void *);
extern void func_021E02E8(void *);
extern void func_021D8E84(void *, int);
extern void func_021E0C78(void *);
void func_021E0C44(char *p)
{
    if (func_02010904(*(void **)(p + 0xEF8))) {
        func_021E02E8(p);
        func_02010934(*(void **)(p + 0xEF8));
        *(int *)(p + 0xEF8) = 0;
        func_021D8E84(p, (int)func_021E0C78);
    }
}
