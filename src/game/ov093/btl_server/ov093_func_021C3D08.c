/*
 * function: func_021C3D08
 * address: 0x021C3D08
 * packet: pkt_ov093_021C3D08
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *  func_021C3DFC 0x021C3DFC thumb ov093
 *  func_021C3E0C 0x021C3E0C thumb ov093
 *  func_021C4034 0x021C4034 thumb ov093
 *  func_021CC8D8 0x021CC8D8 thumb ov093
 *  func_021C88E4 0x021C88E4 thumb ov093
 *  func_021C4304 0x021C4304 thumb ov093
 *  func_021CD64C 0x021CD64C thumb ov093
 *  func_021CC95C 0x021CC95C thumb ov093
 */
#include "../../../matched/include/Obj03191.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 pad[5]; u8 a:1,b:1,c:6; } Flag;
typedef struct { u8 a:4,b:1,c:3; } ByteFlag;
extern int func_021C3DFC(u8 *);
extern void func_021C3E0C(u8 *, u8 *, u8 *);
extern int func_021C4034(u8 *, u8 *);
extern u32 func_021CC8D8(void *, int);
extern int func_021C88E4(u8 *p);
extern int func_021C4304(u8 *, u16 *, u8 *, u8 *, int *);
extern void func_021CD64C(void *w, u8 id, ...);
extern void func_021CC95C(u32 *p, u32 v, int line);
void func_021C3D08(u8 *p, u16 *b, u8 *a, u8 *c)
{
    int out;
    u32 s, r;
    Flag *f;
    if (func_021C3DFC(c) != 0) return;
    switch (*b) {
    case 0x11d:
        func_021C3E0C(p, a, c);
        return;
    case 0xa4:
        if (func_021C4034(p, a)) {
            f = *(Flag * *)&((struct Obj03191 *)p)->f4A8;
            if (f->a == 0) {
                f->a = 1;
                f->b = 1;
            }
        }
        return;
    default:
        s = func_021CC8D8(p + 0x1d74, 9087);
        r = func_021C88E4(p);
        if (func_021C4304(p, b, a, c, &out)) {
            r = func_021C88E4(p);
            if (r == 2) {
                f = *(Flag * *)&((struct Obj03191 *)p)->f4A8;
                if (f->a == 0) f->a = 1;
            }
        }
        if (r <= 1 && out != 0 && ((ByteFlag *)(p + 0x78a))->b == 0) {
            func_021CD64C(((struct Obj03191 *)p)->fC, 0x5a, 0x47, 0xffff0000);
        }
        func_021CC95C((u32 *)(p + 0x1d74), s, 9113);
    }
}
