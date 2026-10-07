/*
 * file:     pmsiv_menu_p08.c
 * unit:     yes
 * function: func_021BCA84, func_021BCAD8
 * address:  0x021BCA84
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BD348 0x021BD348 thumb ov110
 *   func_0204B98C 0x0204B98C arm
 *   func_02045808 0x02045808 arm
 *   func_02028148 0x02028148 thumb
 *   func_0204B3DC 0x0204B3DC arm
 *   func_020409B4 0x020409B4 arm
 */
#include "../../matched/include/Obj06388.h"
#include "../../matched/include/Obj00295.h"

struct Actor;
struct Obj;
struct U16Vec;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef struct { void *s; unsigned short x; unsigned short pad; int flag; } Record;

typedef struct { u8 pad[0x40]; Record records[3]; void *windows[3]; void *items[8]; void *other[2]; } Object;

extern void func_02028178(u8 *p);
extern u32 func_0204B98C(struct Actor *a);
extern void func_021BD348(char *p);
extern void func_02045808(struct U16Vec *vec);
extern void func_02028148(u8 *p);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_020409B4(u32 index);
void func_021BCA84(u8 *p);
void func_021BCAD8(Object *p);

void func_021BCA84(u8 *p)
{
    int i;
    for (i=0;i<3;i++) if (*(void **)(p+0x64+i*4)) func_02028178(*(void **)(p+0x64+i*4));
    switch (((struct Obj06388 *)p)->f2C) {
    case 0: break;
    case 1: ((struct Obj06388 *)p)->f2C=2;
    case 2: if (!func_0204B98C(((struct Obj06388 *)p)->f28)) ((struct Obj06388 *)p)->f2C=3; break;
    case 3: ((struct Obj06388 *)p)->f2C=0; break;
    }
    func_021BD348((char *)p);
}

void func_021BCAD8(Object *p) {
    int i;
    for(i=0;i<3;i++) {
        if(p->records[i].s) { func_02045808(p->records[i].s); p->records[i].s=0; }
        if(p->windows[i]) { func_02028148(p->windows[i]); p->windows[i]=0; }
    }
    for(i=0;i<8;i++) func_0204B3DC(p->items[i],0);
    for(i=0;i<2;i++) func_0204B3DC(p->other[i],0);
    func_020409B4(0);
    func_0204B3DC(((struct Obj00295 *)p)->f28,0);
}
