/*
 * file:     p_sta_oam_p05.c
 * unit:     yes
 * function: func_021D60A4, func_021D60D4
 * address:  0x021D60A4
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
 *   func_0201AB28 0x0201AB28 thumb
 *   func_021D6064 0x021D6064 thumb ov131
 */
#include "../../matched/include/Obj00112.h"

struct Sav;
typedef unsigned int u32;

struct Src { int v; int pad[2]; unsigned char kind; };

extern void *func_0201AB28(void *p, u32 idx);
extern void *func_021D6064(unsigned char *p);
extern u32 func_02017D30(struct Sav *p);
extern u32 func_02017D70(struct Sav *p, u32 f);
extern u32 func_02017DBC(struct Sav *p);
extern u32 func_02017DE4(struct Sav *p, u32 f);
int func_021D60A4(char *p);
void func_021D60D4(unsigned char *p,int a);

int func_021D60A4(char *p)
{
    struct Src *s = *(struct Src * *)&((struct Obj00112 *)p)->f8;
    switch (s->kind) {
    case 0:
        return s->v;
    case 1:
        return (int)func_0201AB28((void *)s->v, ((struct Obj00112 *)p)->f18);
    case 2:
        return *(int *)&((struct Obj00112 *)p)->f258;
    default:
        return 0;
    }
}

void func_021D60D4(unsigned char *p,int a) {
 void *m;
 switch((*(unsigned char **)(p+8))[12]) {
 case 0:
 m=**(void ** *)&((struct Obj00112 *)p)->f8;
 if(a==1) func_02017D30(m); else func_02017D70(m,1);
 break;
 case 1:
 m=func_0201AB28(**(void ** *)&((struct Obj00112 *)p)->f8,((struct Obj00112 *)p)->f18);
 if(a==1) func_02017D30(m); else func_02017D70(m,1);
 break;
 case 2:
 m=func_021D6064(p);
 if(a==1) {func_02017D30(((struct Obj00112 *)p)->f258);func_02017DBC(m);}
 else {func_02017D70(((struct Obj00112 *)p)->f258,1);func_02017DE4(m,1);}
 break;
 }
}
