/*
 * function: func_021ECF78
 * address: 0x021ECF78
 * packet: pkt_ov170_021ECF78
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0x020275EC has no witness outside this caller.
 * Verified scratch-only with one --thumb, no --region: EXACT, 12 bytes.
 * symbols for blocker: d_0209FCF8 0x0209FCF8 data a1
 * extern const unsigned char d_0209FCF8[];
 * unsigned func_020275EC(unsigned char i) { return d_0209FCF8[i]; }
 * symbols:
 *   d_021EFD34 0x021EFD34 data a4
 *   func_021EBEE0 0x021EBEE0 thumb ov170
 *   func_020275EC 0x020275EC thumb
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_021EC000 0x021EC000 thumb ov170
 */
typedef struct { short x, y; unsigned char pad4[2], b6, b7; int a, b, c; unsigned short e, d; } Desc;
extern const Desc d_021EFD34;
extern void *func_021EBEE0(char *, const Desc *);
typedef unsigned char  u8;
extern u8 func_020275EC(int i);
typedef unsigned int   u32;
struct Obj;
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_021EC000(char *, int, int);
void func_021ECF78(char *p)
{
    Desc d = d_021EFD34;
    unsigned i;
    for (i = 0; i < 0x11; i++) {
        d.a = i + 0x28;
        *(void **)(p + i * 4 + 0x9EE4) = func_021EBEE0(p, &d);
        func_0204B6F4(*(void **)(p + i * 4 + 0x9EE4), (unsigned)func_020275EC((unsigned char)i), 1);
        func_021EC000(p, i + 0x1C, 0);
    }
}
