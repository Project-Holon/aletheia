/*
 * function: func_021B9920
 * address:  0x021B9920
 * packet:   pkt_ov217_021B9920
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * note 2026-10-02: all but 4 bytes match. Original keeps 0x20 hoisted in r7
 *   but rematerialises the final block's `movs r0,#5` for the 20409B4 call;
 *   we hoist it into r6 (movs r6,#5 before the 2041090 call). Tried separate
 *   handle local, int/u32/u8 first-arg prototypes.
 */

typedef unsigned int u32;

extern void *func_020490F4(u32 id, u32 heap);
extern void *func_02049250(void *arc, u32 idx, u32 heap);
extern void func_02062A98(void *, char **);
extern void func_02062A4C(void *, char **);
extern void func_02062B30(void *, char **);
extern void func_02040E78(int, int, int, int);
extern void func_02040B1C(int, int, int, int);
extern void func_02041090(int, char *, int, int, int, int);
extern void func_020409B4(int);
extern void func_020307B0(void *);
extern void func_02049238(void *);

void func_021B9920(u32 heap)
{
    void *arc = func_020490F4(0xc0, heap);
    void *h, *h4;
    char *p1, *p2, *p3, *p4;

    h = func_02049250(arc, 9, heap);
    func_02062A98(h, &p1);
    func_02040E78(4, *(int *)(p1 + 0xc), 0x200, 0);
    func_020307B0(h);

    h = func_02049250(arc, 0xa, heap);
    func_02062A4C(h, &p2);
    func_02040B1C(4, *(int *)(p2 + 0x14), *(int *)(p2 + 0x10), 0);
    func_020307B0(h);

    h = func_02049250(arc, 0xb, heap);
    func_02062B30(h, &p3);
    func_02041090(4, p3 + 0xc, 0, 0, 0x20, 0x18);
    func_020409B4(4);
    func_020307B0(h);

    h4 = func_02049250(arc, 0xc, heap);
    func_02062B30(h4, &p4);
    func_02041090(5, p4 + 0xc, 0, 0, 0x20, 0x18);
    func_020409B4(5);
    func_020307B0(h4);

    func_02049238(arc);
}
