/*
 * function: func_021C61D4
 * address: 0x021C61D4
 * packet: pkt_ov136_021C61D4
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: trailing 021C622E halfword is alignment padding.
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_02045924 0x02045924 arm
 *   func_02045808 0x02045808 arm
 *   func_02008F84 0x02008F84 thumb
 *   func_02008F9C 0x02008F9C thumb
 */
#include "../include/Obj00127.h"
#include "../include/Obj23558.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
struct Strbuf;
struct Sub02008F80Obj;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u16 *func_02008F84(void *);
extern u8 func_02008F9C(const struct Sub02008F80Obj *obj);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern void func_0201EE0C(void *, u32, const void *, u32, u32, u32);
extern void func_02045808(struct U16Vec *vec);
void func_021C61D4(u8 *p)
{
    void *entry;
    void *text;
    u32 n;
    entry = *(void **)(*(u8 * *)&((struct Obj00127 *)p)->f8 + 0x298 + p[0x1f] * 4);
    text = func_020457B0(16, 102);
    func_02008F84(entry);
    func_02045924(text, func_02008F84(entry));
    n = func_02008F9C(entry);
    func_0201EE0C(((struct Obj23558 *)(*(u8 * *)&((struct Obj00127 *)p)->f8))->f1D4, 0, text, n, 1, 2);
    func_02045808(text);
}
