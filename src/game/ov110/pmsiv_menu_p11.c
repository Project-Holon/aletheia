/*
 * file:     pmsiv_menu_p11.c
 * unit:     yes
 * function: func_021BD764, func_021BD7A0, func_021BD808
 * address:  0x021BD764
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
 *   func_02024224 0x02024224 thumb
 *   func_02051C6C 0x02051C6C arm
 *   func_021B9B20 0x021B9B20 thumb ov110
 *   func_02030DA4 0x02030DA4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_021B95F4 0x021B95F4 thumb ov110
 *   func_021BAF4C 0x021BAF4C thumb ov110
 *   func_020315D4 0x020315D4 arm
 *   func_021BD894 0x021BD894 thumb ov110
 *   func_021BD8A8 0x021BD8A8 thumb ov110
 *   func_021BE4C0 0x021BE4C0 thumb ov110
 *   func_021BD8B8 0x021BD8B8 thumb ov110
 *   func_021BEDEC 0x021BEDEC thumb ov110
 *   func_021BD8C8 0x021BD8C8 thumb ov110
 *   func_021BAE24 0x021BAE24 thumb ov110
 *   func_021BAE94 0x021BAE94 thumb ov110
 *   func_021BAED0 0x021BAED0 thumb ov110
 *   func_02035C38 0x02035C38 arm
 *   func_0203630C 0x0203630C arm
 */
#include "../../matched/include/Obj00012.h"

struct S020315D4;
typedef unsigned char u8;

typedef signed char s8;

typedef unsigned short u16;

typedef short s16;

typedef unsigned int u32;

typedef int (*Handler)(u8 *,void *);

extern void func_02024224(void *,void *);
extern void func_02051C6C(void *);
extern void func_021B9B20(u8 *);
extern void func_02030DA4(void *);
extern u32 func_020307B0(void *p);
extern void func_021B95F4(char *);
extern void func_021BAF4C(unsigned);
extern void func_020315D4(struct S020315D4 *p);
extern int func_021BD894(u8 *,void *);
extern int func_021BE4C0(u8 *,void *);
extern int func_021BEDEC(u8 *,void *);
extern int func_021BD8A8(u8 *p);
extern int func_021BD8B8(u8 *p);
extern int func_021BD8C8(u8 *p);
extern void func_021BAE24(u8 *p, u8 *a1, void *a2);
extern void func_021BAE94(u8 *p, u8 *q, void *a2);
extern void func_021BAED0(u8 *p, u8 *a1, void *a2);
extern int func_02035C38(void);
extern unsigned int func_0203630C(void);
void func_021BD764(u8 *p,void *a);
void func_021BD7A0(u8 *p,Handler fn);
int func_021BD808(u8 *p,void *q);

void func_021BD764(u8 *p,void *a)
{
    func_02024224(*(void **)p,*(void **)(p+0x70));
    func_02051C6C(*(void **)(p+0x44));
    func_021B9B20(*(u8 **)(p+0x14));
    func_02030DA4(*(void **)(p+0x7c));
    func_020307B0(*(void **)(p+0x78));
    func_021B95F4(*(char **)(p+0x18));
    func_021BAF4C(*(u32 *)(p+0x1c));
    func_020315D4(a);
}

void func_021BD7A0(u8 *p,Handler fn) {
 *(Handler *)&((struct Obj00012 *)p)->f24=fn; ((struct Obj00012 *)p)->f20=0;
 if(fn==func_021BD894) { func_021BAE24(((struct Obj00012 *)p)->f14,p,((struct Obj00012 *)p)->f18); *(Handler *)&((struct Obj00012 *)p)->f74=(Handler)func_021BD8A8; }
 else if(fn==func_021BE4C0) { func_021BAE94(((struct Obj00012 *)p)->f14,p,((struct Obj00012 *)p)->f18); *(Handler *)&((struct Obj00012 *)p)->f74=(Handler)func_021BD8B8; }
 else if(fn==func_021BEDEC) { func_021BAED0(((struct Obj00012 *)p)->f14,p,((struct Obj00012 *)p)->f18); *(Handler *)&((struct Obj00012 *)p)->f74=(Handler)func_021BD8C8; }
 else *(Handler *)&((struct Obj00012 *)p)->f74=0;
}

int func_021BD808(u8 *p,void *q) {
 void (*cb)(u8 *,void *);
 if(((struct Obj00012 *)p)->f70==1) {
  if(func_02035C38()) return 0;
  if(func_0203630C()) { cb=*(void (**)(u8 *,void *))(p+0x74); ((struct Obj00012 *)p)->f70=0; if(cb) cb(p,q); return 1; }
 } else {
  if(func_0203630C()) return 0;
  if(func_02035C38()) { cb=*(void (**)(u8 *,void *))(p+0x74); ((struct Obj00012 *)p)->f70=1; if(cb) cb(p,q); return 1; }
 }
 return 0;
}
