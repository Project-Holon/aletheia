/*
 * file:     pmsiv_menu_p12.c
 * unit:     yes
 * function: func_021BD868, func_021BD894, func_021BD8A8, func_021BD8B8, func_021BD8C8, func_021BD8D8, func_021BDA84
 * address:  0x021BD868
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
 *   func_020061E4 0x020061E4 thumb
 *   func_021BED84 0x021BED84 thumb ov110
 *   func_021BEDEC 0x021BEDEC thumb ov110
 *   func_021B9BEC 0x021B9BEC thumb ov110
 *   d_021C3920 0x021C3920 data a4
 *   func_021BAE24 0x021BAE24 thumb ov110
 *   func_021BAE94 0x021BAE94 thumb ov110
 *   func_021BAED0 0x021BAED0 thumb ov110
 *   func_021B9C74 0x021B9C74 thumb ov110
 *   func_021BF4F8 0x021BF4F8 thumb ov110
 *   func_021BF53C 0x021BF53C thumb ov110
 *   func_021BF608 0x021BF608 thumb ov110
 *   func_021BF82C 0x021BF82C thumb ov110
 *   func_021BF680 0x021BF680 thumb ov110
 *   func_021BD7A0 0x021BD7A0 thumb ov110
 *   func_021BE3B8 0x021BE3B8 thumb ov110
 *   func_021BE4C0 0x021BE4C0 thumb ov110
 *   d_021C3938 0x021C3938 data ov110 a1
 *   func_02035C08 0x02035C08 arm
 */
#include "../../matched/include/Obj13788.h"
#include "../../matched/include/Obj13789.h"
#include "../../matched/include/Obj13790.h"
#include "../../matched/include/Obj13791.h"
#include "../../matched/include/Obj00012.h"

typedef unsigned char u8;

typedef signed char s8;

typedef unsigned short u16;

typedef short s16;

typedef unsigned int u32;

typedef int (*Handler)(u8 *,void *);

extern void func_020061E4(u32);
extern void func_021BED84(u8 *,void *);
extern int func_021BEDEC(u8 *,u32 *);
extern void func_021B9BEC(u8 *,int);
extern int func_021BAE24(void *,u8 *,void *);
extern int func_021BAE94(void *,u8 *,void *);
extern int func_021BAED0(void *,u8 *,void *);
extern int func_021B9C74(unsigned int a);
extern void func_021BF4F8(u8 *,u32);
extern void func_021BF53C(u8 *,u32 *);
extern void func_021BF608(u8 *,u32 *);
extern void func_021BF82C(u8 *);
extern int func_021BF680(u8 *);
extern void func_021BD7A0(u8 *,Handler);
extern int func_021BE3B8(u8 *,u32 *);
extern int func_021BE4C0(u8 *,unsigned *);
extern int func_02035C08(const void *p);
void func_021BD868(u8 *p);
int func_021BD894(u8 *p,void *q);
int func_021BD8A8(u8 *p);
int func_021BD8B8(u8 *p);
int func_021BD8C8(u8 *p);
int func_021BD8D8(u8 *p,u32 *q);
int func_021BDA84(u8 *unused);
extern u8 d_021C3938[];

void func_021BD868(u8 *p)
{
    func_020061E4(1356);
    func_021BED84(p+0x54,p);
    ((struct Obj13788 *)p)->f28=(u32)func_021BEDEC;
    func_021B9BEC(*(u8 * *)&((struct Obj13788 *)p)->f14,12);
}

extern int (*const d_021C3920[])(u8 *,void *);

int func_021BD894(u8 *p,void *q) { return d_021C3920[*(unsigned *)(p+4)](p,q); }

int func_021BD8A8(u8 *p) { return func_021BAE24(((struct Obj13789 *)p)->f14,p,((struct Obj13789 *)p)->f18); }

int func_021BD8B8(u8 *p) { return func_021BAE94(((struct Obj13790 *)p)->f14,p,((struct Obj13790 *)p)->f18); }

int func_021BD8C8(u8 *p) { return func_021BAED0(((struct Obj13791 *)p)->f14,p,((struct Obj13791 *)p)->f18); }

int func_021BD8D8(u8 *p,u32 *q) {
    switch(*q) {
    case 0:
        if(func_021B9C74((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) {
            if(((struct Obj00012 *)p)->f34&64) {
                func_020061E4(1352); ((struct Obj00012 *)p)->f48=1;
                func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,7); *q=1;
            } else if(((struct Obj00012 *)p)->f34&136) {
                func_020061E4(1352); ((struct Obj00012 *)p)->f48=0;
                func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,7); *q=1;
            } else if(((struct Obj00012 *)p)->f34&2) {
                func_020061E4(1361); func_021BF4F8(p,(u32)func_021BF608);
            } else if(((struct Obj00012 *)p)->f34&1) {
                func_020061E4(1356); func_021BF82C(p);
                func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,10); *q=5;
            }
        }
        break;
    case 1:
        if(func_021B9C74((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) {
            if(((struct Obj00012 *)p)->f34&64) {
                func_020061E4(1352);
                if(((struct Obj00012 *)p)->f48) { ((struct Obj00012 *)p)->f48^=1; func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,17); }
                else { func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,9); *q=0; }
            } else if(((struct Obj00012 *)p)->f34&128) {
                func_020061E4(1352);
                if(((struct Obj00012 *)p)->f48) { func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,9); *q=0; }
                else { ((struct Obj00012 *)p)->f48^=1; func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,17); }
            } else if(((struct Obj00012 *)p)->f34&8) {
                func_020061E4(1352); ((struct Obj00012 *)p)->f48=0; func_021B9BEC(*(u8 * *)&((struct Obj00012 *)p)->f14,17);
            } else if(((struct Obj00012 *)p)->f34&1) {
                if(((struct Obj00012 *)p)->f48==0) {
                    if(func_021BF680(p)) func_020061E4(1356); else func_020061E4(1367);
                    *q=2;
                } else { func_020061E4(1361); *q=3; }
            } else if(((struct Obj00012 *)p)->f34&2) { func_020061E4(1361); *q=3; }
        }
        break;
    case 2: *q=4; func_021BF4F8(p,(u32)func_021BF53C); break;
    case 3: *q=4; func_021BF4F8(p,(u32)func_021BF608); break;
    case 4: *q=1; break;
    case 6: if(func_021B9C74((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) func_021BD7A0(p,(Handler)func_021BE3B8); break;
    case 5: if(func_021B9C74((unsigned int)(*(u8 * *)&((struct Obj00012 *)p)->f14))) func_021BD7A0(p,(Handler)func_021BE4C0); break;
    }
    return 0;
}

/*
 * input: caller's incoming pointer in r0 is ignored; stub replaces it with the table.
 */
int func_021BDA84(u8 *unused)
{
    return func_02035C08(d_021C3938);
}
