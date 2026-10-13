/*
 * function: func_021C6284
 * address:  0x021C6284
 * packet:   pkt_ov136_021C6284
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201F250     0x0201F250  thumb
 *   STRBUF_Delete              0x02045808  arm
 *   func_02045EC0        0x02045EC0  arm
 *   func_021C61D4  0x021C61D4  thumb
 *   func_021C6230 0x021C6230 thumb
 */
#include "../include/Obj00127.h"
#include "../include/Obj23563.h"
#include "../include/Obj23564.h"
#include "../include/Obj23565.h"

typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021C61D4(u8 *p, u32 a1);
struct MsgBank;
struct U16Vec;
struct WordSet;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_021C6230(u8 *p);
void func_021C6284(u8 *p)
{
    void *t;
    func_021C61D4(p, 0);
    t = func_02045EC0(((struct Obj23563 *)(*(u8 * *)&((struct Obj00127 *)p)->f8))->f1D0, 9);
    func_0201F250(((struct Obj23564 *)(*(u8 * *)&((struct Obj00127 *)p)->f8))->f1D4, ((struct Obj23565 *)(*(u8 * *)&((struct Obj00127 *)p)->f8))->f1D8, t);
    STRBUF_Delete(t);
    func_021C6230(p);
}
