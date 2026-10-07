/*
 * file:     btl_server_p47.c
 * unit:     yes
 * function: func_021C15D4, func_021C15E8
 * address:  0x021C15D4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021C1624 0x021C1624 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021D59B4(u8 *p, int k);
extern u32 func_021CC8D8(void *, int);
extern void func_021C1624(u8 *p, u8 *a, u8 *b, u16 *c);
extern void func_021CC95C(u32 *p, u32 v, int line);
u32 func_021C15D4(void *p, u32 n);
void func_021C15E8(u8 *p, u8 *a, u8 *b, u16 *c);


u32 func_021C15D4(void *p, u32 n)
{
    u32 v = func_021D59B4(p, 13);
    if (n > v) n = v;
    return n;
}


/*
 * interface: Complete lock word returned in r0 at 021CC900; restore
 * 021CC95C stores the unchanged full r1 word. Scalar u32 preserves all bits.
 */
void func_021C15E8(u8 *p, u8 *a, u8 *b, u16 *c)
{
    u32 s = func_021CC8D8(p + 0x1d74, 6570);
    func_021C1624(p, a, b, c);
    func_021CC95C((u32 *)(p + 0x1d74), s, 6570 + 4);
}
