/*
 * file:     btl_server_p133.c
 * unit:     yes
 * function: func_021CE068, func_021CE08C, func_021CE0BC, func_021CE0E0, func_021CE0F8, func_021CE150, func_021CE160
 * address:  0x021CE068
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F8504 0x021F8504 thumb ov094
 *   func_021F8524 0x021F8524 thumb ov094
 *   func_021B8588  0x021B8588  thumb  ov093
 *   func_021EAF18  0x021EAF18  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021EAF50  0x021EAF50  thumb  ov093
 *   func_021EAF78  0x021EAF78  thumb  ov093
 */
#include "../../matched/include/Obj01892.h"
#include "../../matched/include/Obj21134.h"
#include "../../matched/include/Obj13355.h"

struct L;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern void func_021F8504(u32,u32,u32);
extern int func_021F8524(int);
extern u32 func_021B8588(void **p);
extern void func_021EAF18(struct L *p, int kind, int id);
extern u8 func_021D5440(u8 *p);
extern void func_021EAF50(struct L *p, u32 val);
extern void func_021EAF78(u8 *o, u8 v);
void func_021CE068(u8 *p);
int func_021CE08C(u8 *p);
int func_021CE0BC(u8 *p,void *q);
void func_021CE0E0(u8 *p);
void func_021CE0F8(u8 *p, u8 *q, u8 *o);
void func_021CE150(u8 *p, void *q);
/* 021CE160 the receiver pointer is also the FIRST argument: the image keeps * r0 = p, puts p+0xd4 in r1 and the slot from [p+0xd0] in r2. */ void func_021CE160(u8 *p);

void func_021CE068(u8 *p) { if(((struct Obj01892 *)p)->fE4) { func_021F8504(1,1,1); p[0x1ad]=0; } }

/*
 * note 2026-10-05 (D8 lane16): re-verified MATCH. Same blocker as 021CDDA0: ov094 0x021F8524 needs a label/witness.
 */
int func_021CE08C(u8 *p) { if(*(u16 *)(p+0xe4)!=0) { if(p[0x1ad]==0) { if(func_021F8524(1)) p[0x1ad]=1; } return p[0x1ad]; } return 0; }

int func_021CE0BC(u8 *p,void *q) { if(func_021CE08C(p)) { if(q) func_021CE150(p,q); return 1; } return 0; }

void func_021CE0E0(u8 *p) { if(((struct Obj21134 *)p)->fE4!=0) func_021F8504(1,0,0); }


void func_021CE0F8(u8 *p, u8 *q, u8 *o)
{
    if (func_021B8588(*(void ** *)&((struct Obj13355 *)p)->f0) != 3) {
        func_021EAF18((struct L *)o, 1, 0x45);
        func_021EAF50((struct L *)o, func_021D5440(q));
        func_021EAF78(o, 0);
    } else {
        func_021EAF18((struct L *)o, 1, 0x46);
        func_021EAF50((struct L *)o, p[0x1a6]);
        func_021EAF78(o, 0);
    }
}

void func_021CE150(u8 *p, void *q) { ((struct Obj01892 *)p)->fD0=q; ((struct Obj01892 *)p)->fD4=0; }


/* 021CE160  the receiver pointer is also the FIRST argument: the image keeps
 * r0 = p, puts p+0xd4 in r1 and the slot from [p+0xd0] in r2. */
/*
 * Leaf with no calls and no pool; 8 instructions, 16 bytes: push {r3, lr}; adds r2, r0, #0; adds r2, #0xd0; adds r1, r0, #0; ldr r2, [r2]; adds r1, #0xd4; blx r2; pop {r3, pc}.
 */
void func_021CE160(u8 *p)
{
    ((void (*)(u8 *, u8 *)) * (u32 *)(p + 0xd0))(p, p + 0xd4);
}
