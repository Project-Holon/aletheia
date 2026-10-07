/*
 * file:     zukan_info_p05.c
 * unit:     yes
 * function: func_021BB23C, func_021BB2C4, func_021BB2D4
 * address:  0x021BB23C
 * region:   ov206
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B800 0x0204B800 arm
 *   func_0204B688 0x0204B688 arm
 *   func_0201AE1C 0x0201AE1C thumb
 *   func_0204B604 0x0204B604 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B3DC 0x0204B3DC arm
 */
#include "../../matched/include/Obj00790.h"
#include "../../matched/include/Obj25404.h"

struct Obj;
struct Actor;
struct Node;
struct Personal;
typedef struct { short x,y,z,w; } Pos;

typedef unsigned int   u32;

extern void func_02082BCC(void *,int,int);
extern struct Obj *func_0204B294(void *,unsigned int,unsigned int,unsigned int,const void *,unsigned short,unsigned short);
extern void func_0204B800(struct Node *node, u32 val);
extern void func_0204B688(struct Actor *actor, u32 value);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0204B604(struct Actor *actor, u32 which, u32 set);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204B3DC(struct Obj *p, u32 v);
void func_021BB23C(char *p,int x,int y,int index);
void func_021BB2C4(char *p, int i);
void func_021BB2D4(char *p);

void func_021BB23C(char *p,int x,int y,int index)
{
    int flag=0;
    Pos pos;
    if (((struct Obj00790 *)p)->f1C) flag=1;
    func_02082BCC(&pos,0,8);
    pos.x=x;
    pos.y=y;
    *(int *)(p+0xac+index*4)=(int)func_0204B294((void *)((struct Obj00790 *)p)->f24,*(int *)(p+0x94+index*4),*(int *)(p+0x9c+index*4),*(int *)(p+0xa4+index*4),&pos,flag,((struct Obj00790 *)p)->f0);
    func_0204B800((struct Node *)(*(int *)(p+0xac+index*4)),0);
    if(((struct Obj00790 *)p)->f18==2) func_0204B688((struct Actor *)(*(int *)(p+0xac+index*4)),1);
    if(func_0201AE1C((const struct Personal *)(((struct Obj00790 *)p)->f26C),34)==0) func_0204B604((struct Actor *)(*(int *)(p+0xac+index*4)),1,1);
}

void func_021BB2C4(char *p, int i)
{
    func_0204B3B4(*(void **)(p + i * 4 + 0xac));
}

void func_021BB2D4(char *p)
{
    unsigned char i;
    for (i = 0; i < 2; i++) {
        if (i != ((struct Obj25404 *)p)->fB4 && *(void **)(p + i * 4 + 0xac) != 0) {
            func_0204B3DC(*(void **)(p + i * 4 + 0xac), 0);
        }
    }
}
