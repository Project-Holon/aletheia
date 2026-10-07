/*
 * file:     box2_main_p08.c
 * unit:     yes
 * function: func_021DE5F8, func_021DE66C, func_021DE720
 * address:  0x021DE5F8
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021DDEFC 0x021DDEFC thumb ov170
 *   func_021ECBD8 0x021ECBD8 thumb
 *   func_021EC768 0x021EC768 thumb
 */
#include "../../matched/include/Obj00000.h"
#include "../../matched/include/Obj23847.h"
#include "../../matched/include/Obj23848.h"

typedef struct {
    unsigned short idx,slot,f4,f6;
    int vx,vy;
    short dx,dy,x,y;
} Obj;

typedef struct {
    unsigned short id;
    unsigned short slot;
    unsigned short src;
    unsigned short used;
    int vx;
    int vy;
    short dx;
    short dy;
    short x;
    short y;
} Entry;

extern void func_021DDEFC(unsigned char *,Obj *);
extern void func_021ECBD8(unsigned char *p, int i);
extern void func_021EC768(char *p, unsigned i, int flag);
void func_021DE5F8(unsigned char *p,unsigned a);
void func_021DE66C(char *p, Entry *e);
int func_021DE720(void);

void func_021DE5F8(unsigned char *p,unsigned a)
{
    Obj *o;
    unsigned i;
    unsigned slot;
    o=*(Obj * *)&((struct Obj23847 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f60;
    slot=a-30;
    for(i=0;i<6;i++){
        o[i].idx=i+30;
        o[i].slot=i+30;
        o[i].f4=i+30;
        o[i].f6=0;
    }
    o[i].f6=0;
    for(i=slot+1;i<6;i++){
        o[i].slot=i+29;
        o[i].f6=1;
        func_021DDEFC(p,&o[i]);
    }
    o[slot].slot=35;
    o[slot].f6=1;
    func_021DDEFC(p,&o[slot]);
}


void func_021DE66C(char *p, Entry *e)
{
    unsigned char buf[7];
    unsigned short i;
    unsigned short save = 0xFFFF;
    for (i = 0; i < 7; i++) {
        if (e[i].used != 0)
            buf[i] = *(unsigned char *)(*(char * *)&((struct Obj00000 *)p)->f2C + e[i].src + 0x3DD2);
    }
    for (i = 0; i < 7; i++) {
        if (e[i].used == 0)
            continue;
        if (e[i].slot <= 0x24) {
            *(unsigned char *)(*(char * *)&((struct Obj00000 *)p)->f2C + e[i].slot + 0x3DD2) = buf[i];
            if (e[i].id == 0x24)
                save = e[i].slot;
        } else {
            ((struct Obj23848 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f3DF6 = buf[i];
            if (e[i].id == 0x24)
                save = 0x24;
        }
    }
    if (save != 0xFFFF)
        func_021ECBD8((unsigned char *)(*(char * *)&((struct Obj00000 *)p)->f2C), save);
    for (i = 0; i < 0x24; i++)
        func_021EC768(*(char * *)&((struct Obj00000 *)p)->f2C, i, 1);
}

/*
 * Return -1.
 */
int func_021DE720(void)
{
    return -1;
}
