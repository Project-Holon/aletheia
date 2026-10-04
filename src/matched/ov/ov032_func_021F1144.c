/*
 * function: func_021F1144
 * address:  0x021F1144
 * packet:   pkt_ov032_021F1144
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02165CE4  0x02165CE4  thumb  ov010
 *   func_02165D08  0x02165D08  thumb  ov010
 *   func_02165C34  0x02165C34  thumb  ov010
 *   func_0204581C  0x0204581C  arm
 *   func_02165D50  0x02165D50  thumb  ov010
 *   func_021F10D8  0x021F10D8  thumb  ov032
 *   func_021F0F74  0x021F0F74  thumb  ov032
 *   func_021F1004  0x021F1004  thumb  ov032
 *   func_02165E24  0x02165E24  thumb  ov010
 *   func_02165D6C  0x02165D6C  thumb  ov010
 *   func_02165D8C  0x02165D8C  thumb  ov010
 *   func_021F1070  0x021F1070  thumb  ov032
 *   func_021F1E40  0x021F1E40  thumb  ov032
 *   func_021F1080  0x021F1080  thumb  ov032
 */
#include "../include/Obj00007.h"
#include "../include/Obj00225.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Rec;
struct U16Vec;
extern u16 func_02165CE4(u8 *r);
extern u8 func_02165D08(struct Rec *r);
extern void func_02165C34(struct Rec *r, void *buf);
extern void func_0204581C(struct U16Vec *vec);
struct Strbuf;
extern void func_02165D50(struct Rec *r, struct Strbuf *buf);
extern void func_021F10D8(u8 *p, u8 *q, void *r);
extern void func_021F0F74(u8 *p, u8 *q, void *r);
extern void func_021F1004(u8 *p, u8 *q, void *r);
extern int func_02165E24(int a0);
extern void func_02165D6C(void *r, void *buf);
extern void func_02165D8C(void *r, void *buf);
extern void func_021F1070(u8 *p, u8 *q, void *buf, int t);
extern void func_021F1E40(u8 *p, u8 *q, void *r, int flag);
extern void func_021F1080(u8 *p, u8 *q, int r, int t);

void func_021F1144(u8 *p, u8 *q, void *r, int mode, int skip, int t)
{
    ((struct Obj00225 *)q)->f6 = func_02165CE4(r);
    q[4] = func_02165D08(r);
    func_02165C34(r, ((struct Obj00225 *)q)->f24);
    func_0204581C(((struct Obj00225 *)q)->f20);
    func_02165D50(r, ((struct Obj00225 *)q)->f20);
    func_021F10D8(p, q, r);
    func_021F0F74(p, q, r);
    func_021F1004(p, q, r);
    if (skip != 0)
        return;
    switch (mode) {
    case 0:
        switch (func_02165E24((int)r)) {
        case 0x18:
            func_02165D6C(r, ((struct Obj00007 *)p)->f118);
            func_021F1070(p, q, ((struct Obj00007 *)p)->f118, t);
            break;
        case 0x31:
            func_02165D8C(r, ((struct Obj00007 *)p)->f118);
            func_021F1070(p, q, ((struct Obj00007 *)p)->f118, t);
            break;
        }
        func_021F1E40(p, q, r, 0);
        break;
    case 1:
        func_021F1070(p, q, ((struct Obj00225 *)q)->f20, t);
        func_021F1E40(p, q, r, 1);
        break;
    case 2:
        func_021F1080(p, q, 1, t);
        break;
    }
}
