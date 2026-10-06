/*
 * function: func_021E467C
 * address:  0x021E467C
 * packet:   pkt_ov119_021E467C
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_0204ACEC 0x0204ACEC arm
 *   func_0201BC78 0x0201BC78 thumb
 *   func_0201BCB4 0x0201BCB4 thumb
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02049238 0x02049238 arm
 */
#include "../include/Obj00252.h"
#include "../include/Obj03781.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u16 x, y, prio; u8 pal, mode; } ObjTmpl;
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int func_0201BC3C(void);
extern int func_0201BC78(void);
extern int func_0201BCB4(void);
typedef signed int     s32;
extern int func_0204ACEC(void *a0, unsigned int a1, unsigned int a2, unsigned int a3, u16 a4);
extern s32 func_0204AF28(void *owner, unsigned int first, unsigned int second, unsigned int mode);
extern s32 func_0204A6C8(void *a, unsigned int b, unsigned int c, unsigned int a3, u16 flags);
struct Obj;
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, u16, u16);
typedef unsigned int   u32;
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_02049238(void *);
void func_021E467C(char *p)
{
    int i, j, z;
    void *arc;
    char *q;
    ObjTmpl t;
    arc = func_020490F4(7, ((struct Obj00252 *)p)->f5F4);
    ((struct Obj00252 *)p)->f87C = (void *)func_0204ACEC(arc, func_0201BC3C(), 1, 0x60, ((struct Obj00252 *)p)->f5F4);
    ((struct Obj00252 *)p)->f8AC = (void *)func_0204AF28(arc, func_0201BC78(), func_0201BCB4(), ((struct Obj00252 *)p)->f5F4);
    for (i = 0; i < 12; i++) {
        for (j = 0; j < 5; j++) {
            z = 0;
            t.x = z;
            t.y = z;
            t.prio = 1;
            t.pal = 0x10;
            t.mode = 3;
            q = p + i * 20 + j * 4;
            ((struct Obj03781 *)q)->f9CC = (void *)func_0204A6C8(arc, 0x51b, z, 1, ((struct Obj00252 *)p)->f5F4);
            ((struct Obj03781 *)q)->fAC0 = func_0204B294(((struct Obj00252 *)p)->f9C4, (unsigned int)((struct Obj03781 *)q)->f9CC,
                (unsigned int)((struct Obj00252 *)p)->f87C, (unsigned int)((struct Obj00252 *)p)->f8AC, &t, 1, ((struct Obj00252 *)p)->f5F4);
            t.prio = z;
            t.pal = 0xf;
            ((struct Obj03781 *)q)->fBB0 = func_0204B294(((struct Obj00252 *)p)->f9C4, (unsigned int)((struct Obj00252 *)p)->f894,
                (unsigned int)((struct Obj00252 *)p)->f880, (unsigned int)((struct Obj00252 *)p)->f8B0, &t, 1, ((struct Obj00252 *)p)->f5F4);
            func_0204B92C(((struct Obj03781 *)q)->fAC0, z);
            func_0204B3DC(((struct Obj03781 *)q)->fAC0, z);
            func_0204B3DC(((struct Obj03781 *)q)->fBB0, z);
            func_0204B92C(((struct Obj03781 *)q)->fBB0, 1);
        }
    }
    func_02049238(arc);
}
