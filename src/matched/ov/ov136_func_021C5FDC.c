/*
 * function: func_021C5FDC
 * address: 0x021C5FDC
 * packet: pkt_ov136_021C5FDC
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   func_021C5F80 0x021C5F80 thumb ov136
 */
#include "../include/Obj23548.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_021C5F80(void *, void *, u8 *, void *, int, int, u32, u16, int);
void func_021C5FDC(u8 *p, void *bank, int i, u32 message, int x, int y, u32 mode, u16 color, int align)
{
    void *text;
    text = func_02045EC0(bank, message);
    func_021C5F80(*(void **)(p + 0x44 + i * 4), text, p + 0xc4 + i * 8, ((struct Obj23548 *)p)->f1C4, x, y, mode, color, align);
    STRBUF_Delete(text);
}
