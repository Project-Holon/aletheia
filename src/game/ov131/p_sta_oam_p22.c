/*
 * file:     p_sta_oam_p22.c
 * unit:     yes
 * function: func_021D89FC, func_021D8A2C
 * address:  0x021D89FC
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_021DBC3C 0x021DBC3C thumb ov131
 *   func_020437AC 0x020437AC arm
 *   func_021D8E24 0x021D8E24 thumb ov131
 *   func_020362DC 0x020362DC arm
 *   func_021D5A9C 0x021D5A9C thumb ov131
 *   func_021D8EA8 0x021D8EA8 thumb ov131
 *   func_021D9428 0x021D9428 thumb ov131
 *   func_020061E4 0x020061E4 thumb
 *   func_021D964C 0x021D964C thumb ov131
 *   func_021D949C 0x021D949C thumb ov131
 *   func_021D8AD0 0x021D8AD0 thumb ov131
 *   func_021D8CD0 0x021D8CD0 thumb ov131
 */
#include "../../matched/include/Obj23148.h"
#include "../../matched/include/Obj00091.h"
#include "../../matched/include/Obj00136.h"

struct Obj;
struct Obj020437AC;
typedef unsigned char  u8;

struct E { unsigned char p[0x7c]; void *f7c; void *f80; unsigned char q[0x14 - 0x8]; };

typedef unsigned int u32;

extern void func_0204B3B4(struct Obj *p);
extern void func_021DBC3C(u8 *p);
extern void func_020437AC(struct Obj020437AC *p);
extern int func_021D8E24(void *unused, u8 *p);
extern u32 func_020362DC(void);
extern void func_021D5A9C(char *p, int a);
extern void func_021D8EA8(u8 *,u8 *);
extern unsigned int func_021D9428(unsigned char *p, unsigned int target);
extern void func_020061E4(u32 a);
extern void func_021D964C(u8 *,u8 *);
extern void func_021D949C(u8 *,u8 *);
extern int func_021D8AD0(u8 *,u8 *);
extern void func_021D8CD0(u8 *,u8 *);
void func_021D89FC(void *unused, unsigned char *s);
void func_021D8A2C(u8 *a,u8 *p);

void func_021D89FC(void *unused, unsigned char *s) {
 unsigned char i;
 func_0204B3B4(((struct Obj23148 *)s)->f54);
 for (i = 0; i < 10; i++) {
  struct E *e = (struct E *)(s + i * 20);
  func_021DBC3C(e->f80);
  func_020437AC(e->f7c);
 }
}

/*
 * note (2026-10-02): the p+0x64 store precedes the p+0x58 store; with source order 58/64/68 the
 *   allocator hoists constant 0 into r7 instead.
 */
void func_021D8A2C(u8 *a,u8 *p)
{
    int index;
    if(((struct Obj00136 *)a)->f44==1) {
        if(p[0x10]==0) return;
        index=func_021D8E24(a,p);
        if(func_020362DC()!=1 && index==-1) return;
        ((struct Obj00091 *)p)->f5C=0;
        func_021D5A9C((char *)a,0);
        if(func_020362DC()==1) {
            func_021D8EA8(a,p);
            a[0x1c]=0;
        } else {
            ((struct Obj00091 *)p)->f64=1;
            p[0x58]=(u8)index;
            ((struct Obj00091 *)p)->f68=1;
            p[0x59]=func_021D9428(p,(u8)index);
            func_021D5A9C((char *)a,0);
            a[0x1c]=1;
        }
        func_020061E4(0x54c);
        func_021D964C(a,p);
        func_021D949C(a,p);
    } else {
        if(*(u32 *)&((struct Obj00091 *)p)->f8==0 && func_021D8AD0(a,p)==0) func_021D8CD0(a,p);
    }
}
