/*
 * function: func_02165D50
 * address:  0x02165D50
 * packet:   pkt_02165D50
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   STRBUF_Clear  0x0204581C  arm
 *   func_02045994  0x02045994  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Rec;
struct Strbuf;
struct U16Vec;
extern void STRBUF_Clear(struct U16Vec *vec);
extern void func_02045994(struct Strbuf *o, const u16 *src, u32 len);

void func_02165D50(struct Rec *r, struct Strbuf *buf)
{
    STRBUF_Clear((struct U16Vec *)buf);
    func_02045994(buf, (const u16 *)((char *)r + 0x20), 9);
}
