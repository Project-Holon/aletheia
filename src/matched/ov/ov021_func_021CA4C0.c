/*
 * function: func_021CA4C0
 * address:  0x021CA4C0
 * packet:   pkt_ov021_021CA4C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Packs the three selected party members into a scratch buffer from bsubway_scr.c and hands it to the +0x74 object.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_021CA210  0x021CA210  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_021CA3B4  0x021CA3B4  thumb
 *   func_0200DC50  0x0200DC50  thumb
 *   func_020307B0  0x020307B0  arm
 *   d_021DE58C  0x021DE58C  data ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00116.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 bytes[0x3c];
} Slot;

extern void *func_02030734(u32 heap, u32 size, int align, const char *file, u16 line);
extern void func_02082BCC(void *p, int v, u32 n);
extern void *func_021CA210(u8 *p);
extern void *func_0201AB28(void *p, u32 idx);
extern void func_021CA3B4(Slot *s, u32 m);
struct Blk1AC;
extern void func_0200DC50(struct Blk1AC *p, u32 which, const void *src);
extern void func_020307B0(void *p);
extern const char d_021DE58C[];

void func_021CA4C0(u8 *p, u32 unused, int flag)
{
    Slot *buf;
    int i;
    void *h;

    i = 0;
    buf = func_02030734((u16)(((u16)((struct Obj00116 *)p)->f4 & 0x7fff) | 0x8000), 0xb4, 0, d_021DE58C, 0x89a);
    func_02082BCC(buf, 0, 0xb4);
    h = func_021CA210(p);
    for (; i < 3; i++)
        func_021CA3B4(&buf[i], (u32)func_0201AB28(h, p[0x1e + i]));
    func_0200DC50((struct Blk1AC *)(((struct Obj00116 *)p)->f74), flag, buf);
    func_02082BCC(buf, 0, 0xb4);
    func_020307B0(buf);
}
