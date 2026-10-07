/*
 * file:     unit_021C6180_p06.c
 * unit:     yes
 * function: func_021C7694, func_021C76BC, func_021C76F0
 * address:  0x021C7694
 * region:   ov128
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021CA3E8 0x021CA3E8 thumb ov128
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_020456F8 0x020456F8 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0201283C 0x0201283C thumb
 *   func_02009A1C 0x02009A1C thumb
 *   func_021C7ACC 0x021C7ACC thumb ov128
 */
#include "../../matched/include/Obj14037.h"
#include "../../matched/include/Obj23079.h"

struct Descriptor;
struct BigObj;
struct Sub020097BCObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

extern void func_021CA3E8(int);
extern void func_0201F7A8(void *,u32);
extern void func_020456F8(struct Descriptor *d);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32);
extern u32 func_0201283C(const struct BigObj *p);
extern int func_02009A1C(struct Sub020097BCObj *obj, u32 i);
extern void func_021C7ACC(u8 *,u8 *,u8 *,u32);
void func_021C7694(u8 *p, void *ctx);
int func_021C76BC(int *p,u8 *q);
void func_021C76F0(u8 *p,u8 *q,u8 *ctx,u32 value);

void func_021C7694(u8 *p, void *ctx) {void *q;func_021CA3E8(1);func_0201F7A8(((struct Obj14037 *)p)->f1C,0);q=((struct Obj14037 *)p)->f1C;func_020456F8(q);func_02041B6C(func_02045730(q));}

int func_021C76BC(int *p,u8 *q) {int i;void *v;if(*p==1) {v=(void *)func_0201283C(((struct Obj23079 *)q)->f4);for(i=0;i<32;i++) {if(func_02009A1C(v,i)==0) return 1;}}else return 1;return 0;}

/*
 * leaf: sole unresolved overlay blocker of handed 021C76F8.
 */
void func_021C76F0(u8 *p,u8 *q,u8 *ctx,u32 value)
{
    func_021C7ACC(p,q,ctx,value);
}
