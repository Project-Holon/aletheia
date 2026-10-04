/*
 * function: func_021CBFB0
 * address:  0x021CBFB0
 * packet:   pkt_ov021_021CBFB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02048F88  0x02048F88  arm
 *   func_0200846C  0x0200846C  thumb
 *   func_020084A0  0x020084A0  thumb
 *   func_021CC070  0x021CC070  thumb  ov021
 *   func_02045A38  0x02045A38  arm
 *   func_02045808  0x02045808  arm
 *   func_020084D4  0x020084D4  thumb
 *   func_0200854C  0x0200854C  thumb
 *   d_021DE59C  0x021DE59C  data  ov021
 */
#include "../include/Obj20247.h"
#include "../include/Obj20248.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Obj {
    u16 f0;
    u8 pad2[2];
    u32 f4;
    u8 *f8;
    void *fC;
    int f10;
} Obj;

extern void *func_02030734(u16 heap, u32 size, u32 clear, const char *file, u32 line);
struct U16Vec;
extern void *func_02048F88(u32 archive_id, u32 member, u32 heap, u32 mode, u32 *size_out);
extern void *func_0200846C(int a0);
struct Sub0200852CObj;
extern void func_020084A0(struct Sub0200852CObj *);
extern void *func_021CC070(u32 file, u32 index);
struct U16Vec;
extern void func_02045A38(struct U16Vec *, u16 *, u32);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_020084D4(u32 value, void *dst);
extern void func_0200854C(int, u32);
extern const char d_021DE59C[];

Obj *func_021CBFB0(u32 a, u32 b)
{
    Obj *p;
    int r;
    char buf[0x100];

    p = func_02030734((u16)a, 0x14, 1, d_021DE59C, 0x5d);
    p->f0 = (u16)a;
    p->f4 = b;
    p->f8 = func_02048F88(0xa5, b, (u16)a, 0, (u32 *)0x6c);
    p->fC = func_02030734((u16)a, 0xdc, 0, d_021DE59C, 0x65);
    p->f10 = (int)func_0200846C(a);
    func_020084A0((struct Sub0200852CObj *)p->f10);
    r = (int)func_021CC070(a, ((struct Obj20247 *)(p->f8))->f68);
    func_02045A38((struct U16Vec *)r, (u16 *)buf, 0x80);
    func_02045808((struct U16Vec *)r);
    func_020084D4(p->f10, buf);
    func_0200854C(p->f10, ((struct Obj20248 *)(p->f8))->f50);
    return p;
}
