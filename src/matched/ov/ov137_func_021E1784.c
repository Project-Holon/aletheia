/*
 * function: func_021E1784
 * address: 0x021E1784
 * packet: pkt_ov137_021E1784
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DCE00 0x021DCE00 thumb ov137
 *   func_0201AB28 0x0201AB28 thumb
 *   func_021DEB10 0x021DEB10 thumb ov137
 *   func_02039338 0x02039338 arm
 *   func_02184180 0x02184180 thumb ov022
 *   func_0202F190 0x0202F190 thumb
 *   func_02019CE0 0x02019CE0 thumb
 */
typedef unsigned char u8;
extern int func_021DCE00(char *p, int i);
extern void *func_0201AB28(void *, unsigned);
typedef unsigned short u16;
struct RecDC;
extern void *func_021DEB10(char *p);
extern u16 func_02039338(void);
extern void *func_02184180(void *, u8);
extern void func_0202F190(void *, int, void *, int, int);
extern void func_02019CE0(const struct RecDC *src, struct RecDC *dest);
void func_021E1784(char *p, int i)
{
    void *party;
    void *other;
    int slot;
    void *a;
    void *b;
    void *q;
    party = *(void **)(p + 0x24);
    other = (void *)func_021DCE00(*(char **)(p + 0xdc), i);
    slot = *(int *)(p + 0x44 + i * 4);
    a = func_0201AB28(party, (*(int **)(p + 0xd8))[1]);
    b = func_0201AB28(other, slot);
    q = func_021DEB10(p);
    func_0202F190(b, 6, func_02184180(q, func_02039338()), 30002, 114);
    func_02019CE0(b, a);
}
