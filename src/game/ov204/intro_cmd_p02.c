/*
 * file:     intro_cmd_p02.c
 * unit:     yes
 * function: func_021BE970, func_021BE984, func_021BEB00, func_021BEBEC, func_021BED6C, func_021BEDB8, func_021BEE5C, func_021BEEF0, func_021BEF08
 * address:  0x021BE970
 * region:   ov204
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BFBA0 0x021BFBA0 thumb ov204
 *   func_020411E8 0x020411E8 arm
 *   func_02040588 0x02040588 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02041300 0x02041300 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02008550 0x02008550 thumb
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_021BDD78 0x021BDD78 thumb ov204
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   init 0x021BFFCC data a2
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_0204B688 0x0204B688 arm
 *   func_0204B6E4 0x0204B6E4 arm
 *   func_021BF55C 0x021BF55C thumb ov204
 *   func_0201F02C 0x0201F02C thumb
 */
#include "../../matched/include/Obj25376.h"
#include "../../matched/include/Obj00550.h"
#include "../../matched/include/Obj06672.h"
#include "../../matched/include/Obj08383.h"
#include "../../matched/include/Obj14616.h"
#include "../../matched/include/Obj14617.h"
#include "../../matched/include/Obj25378.h"
#include "../../matched/include/Obj14618.h"

struct Obj;
struct Sub0200852CObj;
struct Actor;
struct WordSet;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct S { u8 pad[0xA8]; u8 data[4096]; };

typedef struct {u16 v[12];} Init;

typedef signed int     s32;

extern int func_021BFBA0(int *p);
extern void func_020411E8(u32,u32,u32,u32,u8,u32,u8,u8,u8,u8);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02041B6C(u32);
extern void func_02041300(u32,int,int,int,u8,u8,u8);
extern void *func_020490F4(u32 id, u32 heap);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
extern unsigned func_021BDD78(char *p);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204A8D4(unsigned);
extern void func_0204ADA4(unsigned);
extern void func_0204AFD8(unsigned);
extern void func_0204B3B4(struct Obj *p);
extern void func_0207D63C(volatile void *, int, int, int, int);
extern void func_0204B688(struct Actor *actor, u32 value);
extern u32 func_0204B6E4(const struct Actor *actor);
extern int func_021BF55C(u8 *p);
extern void func_0201F02C(struct WordSet*,u32,void*);
int func_021BE970(u8*p);
int func_021BE984(struct S *p,u32 *q);
int func_021BEB00(void *p,u32 *q);
int func_021BEBEC(char *p);
int func_021BED6C(char *p);
int func_021BEDB8(char *p, unsigned *state, unsigned *q);
int func_021BEE5C(char *p, unsigned *state, unsigned *q);
int func_021BEEF0(u8*p);
void func_021BEF08(u8*p,u32 a);
extern const Init init;

int func_021BE970(u8*p){if(func_021BFBA0((int *)(*(char* *)&((struct Obj25376 *)p)->fC)))return 1;return 0;}

/*
 * lever: unsigned integer p+0xA8 at the first paired call, member address
 *   at the second, keeps equivalent addresses apart; pointer-only was 364
 *   bytes/275 different, this spelling EXACT380 (existing distinct-arithmetic idiom).
 */
int func_021BE984(struct S *p,u32 *q)
{
    switch (*q) {
    case 0:
        func_02040588(2,1);
        func_020411E8(2,0,8,64,2,(u32)p->data,0,8,64,32);
        func_02041B6C(2);
        (*q)++;
        break;
    case 1:
        func_020411E8(2,0,7,64,1,(u32)p+0xA8,0,7,64,32);
        func_020411E8(2,0,10,64,1,(u32)p->data,0,10,64,32);
        func_02041B6C(2);
        (*q)++;
        break;
    case 2:
        func_020411E8(2,0,6,64,1,(u32)p+0xA8,0,6,64,32);
        func_020411E8(2,0,11,64,1,(u32)p->data,0,11,64,32);
        func_02041B6C(2);
        (*q)++;
        break;
    case 3:
        func_020411E8(2,0,5,64,1,(u32)p+0xA8,0,5,64,32);
        func_020411E8(2,0,12,64,1,(u32)p->data,0,12,64,32);
        func_02041B6C(2);
        (*q)++;
        break;
    case 4:
        func_020411E8(2,0,4,64,1,(u32)p+0xA8,0,4,64,32);
        func_020411E8(2,0,13,64,1,(u32)p->data,0,13,64,32);
        func_02041B6C(2);
        *q=0;
        return 1;
    }
    return 0;
}

/*
 * extent: two bytes of zero alignment at 0x021BEBEA.
 */
int func_021BEB00(void *p,u32 *q)
{
    switch (*q) {
    case 0:
        func_02041300(2,0,0,7,64,1,0);
        func_02041300(2,0,0,16,64,1,0);
        func_02041B6C(2);
        (*q)++;
        break;
    case 1:
        func_02041300(2,0,0,8,64,1,0);
        func_02041300(2,0,0,15,64,1,0);
        func_02041B6C(2);
        (*q)++;
        break;
    case 2:
        func_02041300(2,0,0,6,64,1,0);
        func_02041300(2,0,0,14,64,1,0);
        func_02041B6C(2);
        (*q)++;
        break;
    case 3:
        func_02041300(2,0,0,5,64,1,0);
        func_02041300(2,0,0,13,64,1,0);
        func_02041B6C(2);
        (*q)++;
        break;
    case 4:
        func_02040588(2,0);
        *q=0;
        return 1;
    }
    return 0;
}

int func_021BEBEC(char *p)
{
    Init local;
    void *arc;
    u32 i;
    char *row;
    arc=func_020490F4(170,((struct Obj00550 *)p)->f0);
    if(func_02008550(**(void ** *)&((struct Obj00550 *)p)->f4)==0){
        ((struct Obj00550 *)p)->f10B4=(void *)func_0204A6C8(arc,6,0,0,((struct Obj00550 *)p)->f0);
        ((struct Obj00550 *)p)->f10C0=(void *)func_0204ABF0(arc,7,0,0,((struct Obj00550 *)p)->f0);
        ((struct Obj00550 *)p)->f10CC=(void *)func_0204AF28(arc,5,4,((struct Obj00550 *)p)->f0);
    }else{
        ((struct Obj00550 *)p)->f10B4=(void *)func_0204A6C8(arc,10,0,0,((struct Obj00550 *)p)->f0);
        ((struct Obj00550 *)p)->f10C0=(void *)func_0204ABF0(arc,11,0,0,((struct Obj00550 *)p)->f0);
        ((struct Obj00550 *)p)->f10CC=(void *)func_0204AF28(arc,9,8,((struct Obj00550 *)p)->f0);
    }
    ((struct Obj00550 *)p)->f10B8=(void *)func_0204A6C8(arc,17,0,0,((struct Obj00550 *)p)->f0);
    ((struct Obj00550 *)p)->f10C4=(void *)func_0204ABF0(arc,18,0,32,((struct Obj00550 *)p)->f0);
    ((struct Obj00550 *)p)->f10D0=(void *)func_0204AF28(arc,16,15,((struct Obj00550 *)p)->f0);
    ((struct Obj00550 *)p)->f10BC=(void *)func_0204A6C8(arc,21,0,0,((struct Obj00550 *)p)->f0);
    ((struct Obj00550 *)p)->f10C8=(void *)func_0204ABF0(arc,22,0,64,((struct Obj00550 *)p)->f0);
    ((struct Obj00550 *)p)->f10D4=(void *)func_0204AF28(arc,20,19,((struct Obj00550 *)p)->f0);
    func_02049238(arc);
    local=init;
    for(i=0;i<3;i++){
        row=p+i*4;
        ((struct Obj06672 *)row)->f10A8=func_0204B294((void *)func_021BDD78(((struct Obj00550 *)p)->f14),(unsigned int)((struct Obj06672 *)row)->f10B4,(unsigned int)((struct Obj06672 *)row)->f10C0,(unsigned int)((struct Obj06672 *)row)->f10CC,(char *)&local+i*8,0,((struct Obj00550 *)p)->f0);
        func_0204B3DC(((struct Obj06672 *)row)->f10A8,0);
    }
    return 1;
}

int func_021BED6C(char *p)
{
    unsigned i;
    for (i = 0; i < 3; i++) {
        char *q = p + i * 4;
        func_0204A8D4(((struct Obj08383 *)q)->f10B4);
        func_0204ADA4(((struct Obj08383 *)q)->f10C0);
        func_0204AFD8(((struct Obj08383 *)q)->f10CC);
        func_0204B3B4(((struct Obj08383 *)q)->f10A8);
    }
    return 1;
}

static inline void change_alpha(int a, int b)
{
    *(volatile unsigned short *)0x04000052 = (unsigned short)(a | (b << 8));
}

int func_021BEDB8(char *p, unsigned *state, unsigned *q)
{
    unsigned i;
    switch (*state) {
    case 0:
        func_0207D63C((volatile void *)0x04000050, 0, 12, 0, 16);
        func_0204B688(*(void **)(p + 0x10a8 + q[0] * 4), 1);
        func_0204B3DC(*(void **)(p + 0x10a8 + q[0] * 4), 1);
        ++*state;
        break;
    case 16:
        for (i = 0; i < 3; i++) {
            char *row = p + i * 4;
            if (func_0204B6E4(((struct Obj14616 *)row)->f10A8) == 1)
                func_0204B688(((struct Obj14616 *)row)->f10A8, 0);
        }
        *state = 0;
        return 1;
    default:
        ++*state;
        change_alpha(*state, 16 - *state);
        break;
    }
    return 0;
}

/*
 * volatile: hardware BLDALPHA write at 021BEEDC.
 */
int func_021BEE5C(char *p, unsigned *state, unsigned *q)
{
    unsigned i;
    switch (*state) {
    case 0:
        func_0207D63C((volatile void *)0x04000050, 0, 12, 16, 0);
        for (i = 0; i < 3; i++)
            func_0204B688(*(void **)(p + 0x10a8 + i * 4), 1);
        ++*state;
        break;
    case 16:
        for (i = 0; i < 3; i++) {
            char *row = p + i * 4;
            func_0204B688(((struct Obj14617 *)row)->f10A8, 0);
            func_0204B3DC(((struct Obj14617 *)row)->f10A8, 0);
        }
        *state = 0;
        return 1;
    default:
        ++*state;
        change_alpha(16 - *state, *state);
        break;
    }
    return 0;
}

int func_021BEEF0(u8*p){if(!func_02008550(**(struct Sub0200852CObj** *)&((struct Obj25378 *)p)->f4))return 1;return 0;}

void func_021BEF08(u8*p,u32 a){struct WordSet*q=(struct WordSet *)func_021BF55C(*(u8* *)&((struct Obj14618 *)p)->f18);func_0201F02C(q,a,**(void** *)&((struct Obj14618 *)p)->f4);}
