/*
 * file:     bsubway_scr_p21.c
 * unit:     yes
 * function: func_021CA4C0, func_021CA544, func_021CA57C, func_021CA598
 * address:  0x021CA4C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
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
 *   func_02011330  0x02011330  thumb
 *   func_02158F54  0x02158F54  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021C9934  0x021C9934  thumb  ov021
 *   func_021C9924  0x021C9924  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012ED8  0x02012ED8  thumb
 *   func_021C9B24  0x021C9B24  thumb  ov021
 */
#include "../../matched/include/Obj00116.h"

struct Blk1AC;
struct Stream;
struct Big;
struct Ctx;
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
extern void func_0200DC50(struct Blk1AC *p, u32 which, const void *src);
extern u32 func_020307B0(void *p);
extern void *func_0215A5F4(void *p);
extern int func_02158F58(int a0);
extern void *func_02158F54(void *p);
extern u16 func_02011330(struct Stream *s);
extern unsigned int func_02159B10(void *a, void *b);
extern void func_021C9934(u32 a, u32 b, u32 c);
extern int func_021C9924(u32 a);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012ED8(struct Big *p);
extern void func_021C9B24(u32 a, u8 *p);
void func_021CA4C0(u8 *p, u32 unused, int flag);
int func_021CA544(u32 a, u32 b);
int func_021CA57C(u32 a, u32 b);
int func_021CA598(u32 a, u32 b);
extern const char d_021DE58C[];


/*
 * Packs the three selected party members into a scratch buffer from bsubway_scr.c and hands it to the +0x74 object.
 *
 * Addresses are Black-image addresses.
 */
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

int func_021CA544(u32 a, u32 b)
{
    void *h = func_0215A5F4((void *)b);
    u32 x, y;
    func_02158F58((int)h);
    x = (u32)func_02158F54(h);
    y = func_02011330((struct Stream *)a);
    func_021C9934(x, y, func_02159B10((void *)a, (void *)b));
    return 0;
}

int func_021CA57C(u32 a, u32 b)
{
    void *h = func_0215A5F4((void *)b);
    func_02158F58((int)h);
    func_021C9924((u32)func_02158F54(h));
    return 0;
}

int func_021CA598(u32 a, u32 b)
{
    void *h = func_0215A5F4((void *)b);
    u32 x;
    func_02158F58((int)h);
    x = (u32)func_02158F54(h);
    func_021C9B24(x, func_02012ED8(func_020120F4((const struct Ctx *)x)));
    return 0;
}
