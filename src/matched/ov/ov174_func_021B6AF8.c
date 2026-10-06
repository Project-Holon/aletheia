/*
 * function: func_021B6AF8
 * address: 0x021B6AF8
 * packet: pkt_ov174_021B6AF8
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: Write the table element access twice (tbl[idx].b and tbl[idx].c) with no element pointer local; the index shift then schedules before the table load.
 * symbols:
 *   func_021B6704 0x021B6704 thumb ov174
 *   func_021B68F8 0x021B68F8 thumb ov174
 *   func_021B6A04 0x021B6A04 thumb ov174
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201F02C 0x0201F02C thumb
 *   func_02012944 0x02012944 thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct E { u8 a, b; u16 c; };
struct P { u8 pad0[0x40]; struct E *tbl; u8 pad1[0x89 - 0x44]; u8 idx; };
extern void func_021B6704(u8 *p, int index);
extern void func_021B68F8(u8 *p, int a);
extern void func_021B6A04(u8 *p, int a);
struct WordSet;
extern u32 func_0201ED04(struct WordSet *p);
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern u8 *func_02012944(void *p);
void func_021B6AF8(u8 *p)
{
    u32 a = ((struct P *)p)->tbl[((struct P *)p)->idx].b;
    u32 b = (u8)((struct P *)p)->tbl[((struct P *)p)->idx].c;
    p[0x88] = a;
    func_021B6704(p, a);
    if (a < 2) {
        func_021B68F8(p, 1);
    } else {
        func_021B68F8(p, 0);
    }
    if (*(void **)(p + 0x74) != 0) {
        func_0201ED04(*(void **)(p + 0x74));
    }
    *(void **)(p + 0x74) = func_0201EC64(*(u16 *)p);
    func_0201F02C(*(void **)(p + 0x74), 0, func_02012944(*(void **)(*(u8 **)(p + 0x30) + 4)));
    func_021B6A04(p, b);
}
