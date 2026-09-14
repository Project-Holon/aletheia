/*
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 *
 * unit:     yes
 * address:  0x0201F094
 * packet:   pkt_0201F020
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * function: func_0201F094
 *
 * A wordset.c setter that maps a caller value to a message id through
 * func_02025B94 and renders it.  Every concrete byte is reproduced; the one
 * unresolved relocation is the call to 0x02025B94, and the call at 0x0201F09E
 * inside this function is the only branch to that address anywhere in the
 * image, so neither a cut nor the `matched` class reaches it until 0x02025B94
 * itself is matched.  That is why the wordset.c setter run is committed as
 * src/matched/unit_0201F020.c and src/matched/unit_0201F0F8.c with this
 * function left out between them.
 *
 * Verified with:
 *   python tools/match.py tu --src src/pending/sub_0201F094.c  *       --addr 0x0201F094 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void *func_02045B38(u32 a, u32 b, u16 c, u16 d);
extern void  func_02045C04(void *s);
extern void  func_02045CAC(void *s, u32 v, void *buf);
extern u32   func_02045F50(void *s);
extern void  sub_02008500(void *a, void *b);
extern u32   func_02025B94(u32 a);
extern u32   func_0202A230(u32 a, u32 b);
extern void  func_0200785C(u32 a, u32 b, void *buf);

struct Tag;

struct Entry {
    u8 tag[5];
    void *str;
};

struct WordSet {
    u32 count;
    u32 heap;
    struct Entry *entries;
    void *buf;
};

extern void func_0201ED64(struct WordSet *p, u32 i);
extern void func_0201ED84(struct WordSet *p, u32 i, const void *src,
                          const struct Tag *tag);
extern void func_0201EDD0(struct WordSet *p, u32 i, u32 id, u32 v);
extern void func_0201F0F8(struct WordSet *p, u32 i, u32 v);

void func_0201F094(struct WordSet *p, u32 i, u32 a, u32 n)
{
    u32 id = func_02025B94(a);
    void *s;

    if (id != 0 && n != 0) {
        s = func_02045B38(0, 2, id, p->heap);
        if (s != 0) {
            if (n < func_02045F50(s)) {
                func_02045CAC(s, n, p->buf);
                func_0201ED84(p, i, p->buf, 0);
                func_02045C04(s);
                return;
            }
            func_02045C04(s);
        }
    }
    func_0201ED64(p, i);
}
