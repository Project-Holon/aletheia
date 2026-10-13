/*
 * function: func_021B8770
 * address: 0x021B8770
 * packet: pkt_ov172_021B8770
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   func_021BE210 0x021BE210 thumb ov172
 *   func_021BDFEC 0x021BDFEC thumb ov172
 *   func_021BE2E0 0x021BE2E0 thumb ov172
 *   func_021BA234 0x021BA234 thumb ov172
 *   func_021BDFFC 0x021BDFFC thumb ov172
 *   func_021B6EA8 0x021B6EA8 thumb ov172
 *   func_021BE0CC 0x021BE0CC thumb ov172
 *   func_021BDFDC 0x021BDFDC thumb ov172
 *   func_021BE078 0x021BE078 thumb ov172
 *   func_021BE0A0 0x021BE0A0 thumb ov172
 *   func_021B7740 0x021B7740 thumb ov172
 *   func_021BA1E8 0x021BA1E8 thumb ov172
 *   func_021BE0D4 0x021BE0D4 thumb ov172
 */
#include "../include/Obj00593.h"
#include "../include/Obj08258.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
extern void func_021BE210(char *a, u8 idx);
extern int func_021BDFEC(void *p);
extern void func_021BE2E0(void *p);
extern void func_021BA234(void *p);
extern u32 func_021BDFFC(void *p);
extern void func_021B6EA8(void *p, u16 v);
extern void func_021BE0CC(void *p, u32 v);
extern u32 func_021BDFDC(void *p);
extern u32 func_021BE078(void *p);
extern void func_021BE0A0(void *p, u32 v);
extern void func_021B7740(void *p, char *q, int a, int b);
extern int func_021BA1E8(int *self, char *buf, unsigned n, int vol, int freq);
extern void func_021BE0D4(void *p, u32 v);
void func_021B8770(int id, int size, u32 *msg, char *q)
{
    u32 self;
    void *r;
    char *base;
    u32 v;
    self = GFL_NET_GetHandleNetID((struct Link *)((u32)GFL_NET_HANDLE_GetCurrentHandle()));
    switch (((struct Obj08258 *)msg)->f4) {
    case 0:
        if (id == self)
            break;
        ((struct Obj00593 *)q)->f183 |= (u8)(1 << id);
        break;
    case 1:
        v = msg[0];
        ((struct Obj00593 *)q)->f3AE = v;
        if (v != 0xff) {
            func_021BE210((char *)(*(u8 * *)&((struct Obj00593 *)q)->f3DC), (u8)v);
        } else {
            r = (void *)func_021BDFEC(((struct Obj00593 *)q)->f3DC);
            func_021BE2E0(((struct Obj00593 *)q)->f3DC);
            func_021BA234(r);
        }
        break;
    case 3:
        func_021B6EA8((void *)func_021BDFFC(((struct Obj00593 *)q)->f3DC), msg[0]);
        func_021BE0CC(((struct Obj00593 *)q)->f3DC, 0);
        break;
    case 2:
        base = (char *)func_021BDFDC(((struct Obj00593 *)q)->f3DC);
        v = msg[0];
        if (v == func_021BE078(((struct Obj00593 *)q)->f3DC))
            break;
        func_021BE0A0(((struct Obj00593 *)q)->f3DC, v);
        func_021B7740(((struct Obj00593 *)q)->f3DC, base, 1, 0);
        break;
    case 4:
        if (id == self)
            break;
        ((struct Obj00593 *)q)->f3C0 = 1;
        break;
    case 5:
        if (id == self)
            break;
        ((struct Obj00593 *)q)->f3C8 = 1;
        break;
    case 6:
        if (self != 0)
            break;
        *(u32 *)(q + id * 0x40 + 0x74) = 1;
        ((struct Obj00593 *)q)->f3B0 = 1;
        break;
    case 7:
        r = (void *)func_021BDFEC(((struct Obj00593 *)q)->f3DC);
        if (id == self)
            func_021BA1E8(r, *(char * *)&((struct Obj00593 *)q)->f1A4, ((struct Obj00593 *)q)->f19C, 0, ((struct Obj00593 *)q)->f1A0);
        else
            func_021BA1E8(r, *(char * *)&((struct Obj00593 *)q)->f1A4, ((struct Obj00593 *)q)->f19C, 0x7f, ((struct Obj00593 *)q)->f1A0);
        break;
    case 8:
        if (self == 0) {
            *(u32 *)(q + id * 0x40 + 0x74) = 0;
            ((struct Obj00593 *)q)->f3B0 = 1;
        }
        func_021BE2E0(((struct Obj00593 *)q)->f3DC);
        break;
    case 9:
        if (id == ((struct Obj00593 *)q)->f3AE)
            ((struct Obj00593 *)q)->f3B0 = 1;
        func_021BE2E0(((struct Obj00593 *)q)->f3DC);
        break;
    case 10:
        func_021BE0D4(((struct Obj00593 *)q)->f3DC, 1);
        break;
    }
}
