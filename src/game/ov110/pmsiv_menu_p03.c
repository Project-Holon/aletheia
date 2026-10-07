/*
 * file:     pmsiv_menu_p03.c
 * unit:     yes
 * function: func_021BC340, func_021BC458, func_021BC484, func_021BC490
 * address:  0x021BC340
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
 *   func_021BF708 0x021BF708 thumb ov110
 *   func_021BAC44 0x021BAC44 thumb ov110
 *   func_021BC58C 0x021BC58C thumb ov110
 *   func_021BF6F0 0x021BF6F0 thumb ov110
 *   func_021BC5BC 0x021BC5BC thumb ov110
 *   func_02045770 0x02045770 arm
 *   func_02045808 0x02045808 arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_02045A90 0x02045A90 arm
 *   func_02045994 0x02045994 arm
 *   func_0201D670 0x0201D670 thumb
 *   func_0201D688 0x0201D688 thumb
 */
#include "../../matched/include/Obj05292.h"
#include "../../matched/include/Obj22370.h"
#include "../../matched/include/Obj22372.h"

struct Descriptor;
struct StrObj;
struct U16Vec;
struct Cursor;
struct Obj;
struct Strbuf;
struct Vec2;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef unsigned u32_021BC340;

typedef struct { s16 x,y; } Pair;

typedef struct { void *root; u8 *state; u8 pad[0x14]; void *items[2][2]; u8 gap[12]; Pair pos[2]; u16 ids[2]; int count; u8 parser[12]; u16 id; } Obj;

typedef unsigned int u32_021BC458;

typedef signed char s8;

typedef unsigned int u32_021BC484;

typedef int s32;

typedef unsigned int u32_021BC490;

typedef struct Cursor {
    u32_021BC490 f00;
    u16 *f04;
    u32_021BC490 f08;
    u16 f0c;
} Cursor;

extern void *func_021BF708(u8 *,u32_021BC340);
extern u32_021BC340 func_021BAC44(u8 *);
extern void func_0201DD78(u32_021BC340,u32_021BC340,u32_021BC340);
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C7A4(void *,s16,s16,void *,void *);
extern u32_021BC340 func_0201D304(struct StrObj *s, u32_021BC340 a, u32_021BC340 b);
extern void func_021BC58C(void *,Pair *);
extern u32_021BC340 func_021BF6F0(u8 *p, u32_021BC340 i);
extern void func_021BC5BC(u8 *p, struct Descriptor *window, const struct Vec2 *input, u32_021BC340 id, struct Obj *sprite);
extern void func_02045808(struct U16Vec *vec);
extern u16 *func_02045A90(struct U16Vec *vec);
extern void func_02045994(struct Strbuf *,const u16 *,u32_021BC490);
extern u32_021BC490 func_0201D670(const u16 *,u32_021BC490);
extern u16 *func_0201D688(u16 *);
int func_021BC340(Obj *p,void *desc,u8 bank);
void func_021BC458(u8 *p,u8 *a);
void func_021BC484(u8 *p);
int func_021BC490(Cursor *p,struct Strbuf *out);

int func_021BC340(Obj *p,void *desc,u8 bank)
{
    void *str;
    u16 id;
    int running,count,x,y;
    u32_021BC340 font;
    str=func_021BF708(p->state,42);
    font=func_021BAC44(p->root);
    running=1;
    count=0; y=0; x=0;
    func_021BC458(p->parser,(u8 *)p);
    do {
        switch(func_021BC490((struct Cursor *)p->parser,str)) {
        case 0:
            func_0201DD78(1,2,15);
            func_0201C7A4(func_02045770(desc),x,y,str,(void *)font);
            x+=func_0201D304(str,font,0);
            break;
        case 1: {
            id=p->id;
            p->ids[count]=id;
            p->pos[count].x=x+50;
            p->pos[count].y=y+8;
            func_021BC58C(desc,&p->pos[count]);
            func_021BC5BC((u8 *)p,desc,(const struct Vec2 *)(&p->pos[count]),func_021BF6F0(p->state,id),p->items[count][bank]);
            count++;
            x+=100;
            break;
        }
        case 2: y+=16; x=0; break;
        case 3: running=0; break;
        }
    } while(running);
    func_021BC484(p->parser);
    func_02045808(str);
    return count;
}

/*
 * extent: two bytes of zero alignment padding after return.
 */
void func_021BC458(u8 *p,u8 *a) { ((struct Obj05292 *)p)->f0=func_021BF708(*(u8 * *)&((struct Obj22370 *)a)->f4,42); *(u16 * *)&((struct Obj05292 *)p)->f4=func_02045A90(((struct Obj05292 *)p)->f0); if(**(u16 * *)&((struct Obj05292 *)p)->f4==0xF000) ((struct Obj05292 *)p)->f8=1; else ((struct Obj05292 *)p)->f8=0; }

void func_021BC484(u8 *p) { func_02045808((struct U16Vec *)(((struct Obj22372 *)p)->f0)); }

int func_021BC490(Cursor *p,struct Strbuf *out)
{
    u16 *start;
    int result;
    start=p->f04;
    switch(p->f08) {
    case 0:
        while(p->f08==0) {
            switch(*p->f04) {
            case 0xfffe: p->f08=2; break;
            case 0xffff: p->f08=3; break;
            case 0xf000: p->f08=1; break;
            default: p->f04+=1; break;
            }
        }
        func_02045994(out,start,(p->f04-start)+1);
        return 0;
    case 1:
        p->f0c=func_0201D670(start,0);
        p->f04=func_0201D688(p->f04);
        result=1;
        break;
    case 2:
        p->f04=start+1;
        result=2;
        break;
    case 3:
    default:
        return 3;
    }
    switch(*p->f04) {
    case 0xfffe: p->f08=2; break;
    case 0xffff: p->f08=3; break;
    case 0xf000: p->f08=1; break;
    default: p->f08=0; break;
    }
    return result;
}
