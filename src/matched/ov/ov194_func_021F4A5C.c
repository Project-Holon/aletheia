/*
 * function: func_021F4A5C
 * address: 0x021F4A5C
 * packet: pkt_ov194_021F4A5C
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F3350 0x021F3350 thumb ov194
 *   func_0200C0FC 0x0200C0FC thumb
 *   func_021F462C 0x021F462C thumb ov194
 *   func_021F4634 0x021F4634 thumb ov194
 *   func_021F4AA8 0x021F4AA8 thumb ov194
 */
extern unsigned func_021F3350(char *);
extern void func_0200C0FC(void *, void *, unsigned char);
extern void func_021F462C(unsigned char *, unsigned);
extern void func_021F4634(unsigned char *);
extern void func_021F4AA8(void);
#define OBJ(p) (*(char **)((p) + 0x2C4))
void func_021F4A5C(unsigned char *a, int unused, char *p)
{
    unsigned n;
    if (*(void **)(OBJ(p) + 0x28) != 0) {
        n = func_021F3350(p + 0xFC);
        func_0200C0FC(*(void **)(OBJ(p) + 0x28), *(void **)OBJ(p), n);
    }
    if (*(void **)(OBJ(p) + 0x24) != 0) func_021F462C(a, (unsigned)func_021F4AA8);
    else func_021F4634(a);
}
