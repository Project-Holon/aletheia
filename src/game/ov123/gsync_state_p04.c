/*
 * file:     gsync_state_p04.c
 * unit:     yes
 * function: func_021D57B8, func_021D57D0, func_021D580C, func_021D584C
 * address:  0x021D57B8
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02045CAC  0x02045CAC  arm
 *   func_021D56FC  0x021D56FC  thumb
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_020456F8 0x020456F8 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../../matched/include/Obj01933.h"
#include "../../matched/include/Obj04496.h"
#include "../../matched/include/Obj03265.h"

struct MsgBank;
struct WordSet;
struct Ctx;
struct Rec3;
struct Blk;
struct Descriptor;
typedef unsigned int u32;

typedef signed int     s32;

typedef unsigned char  u8;

extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021D56FC(char *, int);
extern void func_0201EEF4(struct WordSet *,u32,void *);
extern void func_0201EFA4(struct WordSet *,u32,u32,u32,u32,u32);
extern void func_0201F250(struct WordSet *,void *,void *);
extern void func_020286C4(struct Ctx *ctx, void *p, void *cell);
extern s32 func_02028484(struct Blk *blk, void *h);
extern void func_0201CE48(struct Rec3 *p);
extern void func_0202F038(u8 *p);
extern void func_0201F7A8(void *desc, u32 kind);
extern void func_020456F8(struct Descriptor *d);
extern void func_02041B6C(u32 bit);
void func_021D57B8(char *p, int a);
void func_021D57D0(void *p, int msg, int n, void *mon);
int func_021D580C(char *p);
void func_021D584C(char *p);


/*
 * Addresses are Black-image addresses.
 */
void func_021D57B8(char *p, int a)
{
    func_02045CAC(((struct Obj01933 *)p)->f20, a, ((struct Obj01933 *)p)->f2C);
    func_021D56FC(p, 0);
}

void func_021D57D0(void *p, int msg, int n, void *mon) {
func_02045CAC(*(void **)((unsigned)p+0x20),msg,*(void **)((unsigned)p+0x30));
func_0201EEF4(*(void **)((unsigned)p+0x24),0,mon);
func_0201EFA4(*(void **)((unsigned)p+0x24),1,n,3,1,1);
func_0201F250(*(void **)((unsigned)p+0x24),*(void **)((unsigned)p+0x2c),*(void **)((unsigned)p+0x30));
}

int func_021D580C(char *p)
{
    if (((struct Obj04496 *)p)->f80) {
        func_020286C4(((struct Obj04496 *)p)->f40, ((struct Obj04496 *)p)->f80, ((struct Obj04496 *)p)->f44);
        if (!func_02028484((struct Blk *)(p+0xa8), ((struct Obj04496 *)p)->f80)) return 0;
        func_0201CE48(((struct Obj04496 *)p)->f80);
        ((struct Obj04496 *)p)->f80=0;
    }
    return 1;
}

void func_021D584C(char *p)
{
    if (((struct Obj03265 *)p)->f7C) {
        func_0202F038(((struct Obj03265 *)p)->f7C);
        ((struct Obj03265 *)p)->f7C=0;
    }
    if (((struct Obj03265 *)p)->f80) {
        func_0201CE48(((struct Obj03265 *)p)->f80);
        ((struct Obj03265 *)p)->f80=0;
    }
    if (((struct Obj03265 *)p)->f44) {
        func_0201F7A8(((struct Obj03265 *)p)->f44,2);
        func_020456F8(((struct Obj03265 *)p)->f44);
        func_02041B6C(5);
    }
}
