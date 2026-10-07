/*
 * file:     unit_02175C40_p07.c
 * unit:     yes
 * function: func_02176258, func_02176280
 * address:  0x02176258
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0217620C 0x0217620C thumb ov011
 *   func_02026478 0x02026478 thumb
 *   func_02012B58 0x02012B58 thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045994  0x02045994  arm
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_02045808  0x02045808  arm
 */
struct BigObj;
struct Strbuf;
struct U16Vec;
struct WordSet;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

extern int func_0217620C(u8 *p, int key);
extern u32 func_02026478(void *p);
extern u8 func_02012B58(const struct BigObj *p);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045994(struct Strbuf *o, const u16 *src, u32 len);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void func_02045808(struct U16Vec *vec);
int func_02176258(u8 *p);
void func_02176280(void *win, u32 slot, void *src, u32 size, u16 heap, u32 a);

/*
 * extent: two alignment bytes at 0217627E.
 */
int func_02176258(u8 *p)
{
    if (func_0217620C(p + 0x1ac, func_02012B58((const void *)func_02026478(((void **)p)[1]))) == 1) return 1;
    return 0;
}


void func_02176280(void *win, u32 slot, void *src, u32 size, u16 heap, u32 a)
{
    void *buf;

    buf = func_020457B0(size, heap);
    func_02045994(buf, src, size);
    func_0201EE0C(win, slot, buf, a, 1, 2);
    func_02045808(buf);
}
