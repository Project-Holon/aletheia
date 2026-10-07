/*
 * file:     unit_021E5440_p04.c
 * unit:     yes
 * function: func_021E58F4, func_021E5A44, func_021E5A70, func_021E5A90
 * address:  0x021E58F4
 * region:   ov178
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   ov067_id 0x00000043 data a1
 *   ov114_id 0x00000072 data a1
 *   ov175_id 0x000000AF data a1
 *   func_0203CD98 0x0203CD98 arm
 *   func_02157170 0x02157170 thumb
 *   func_020399A8 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_02034AC4 0x02034AC4 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_021D9DC8 0x021D9DC8 thumb ov175
 *   func_021DC200 0x021DC200 thumb ov175
 *   func_021DC240 0x021DC240 thumb ov175
 *   func_021D9EA0 0x021D9EA0 thumb ov175
 *   func_0217E00C  0x0217E00C  thumb  ov176
 *   ov176_id       0x000000B0  data
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0200FB38 0x0200FB38 thumb
 *   func_0217E258 0x0217E258 thumb ov176
 *   func_0217E298 0x0217E298 thumb ov176
 *   func_0217E074 0x0217E074 thumb ov176
 */
#include "../../matched/include/Obj02890.h"

struct Entry;
struct Link;
typedef unsigned short u16;

typedef unsigned long u32_021E58F4;

typedef unsigned char  u8;

typedef unsigned int u32_021E5A44;

typedef signed int     s32;

typedef unsigned int u32_021E5A70;

typedef unsigned int   u32_021E5A90;

extern int func_0203CD98(void),func_02157170(void *,void *);
extern struct Entry *func_020399A8(void);
extern void func_02039C68(struct Link *,unsigned int,unsigned int);
extern unsigned int func_02039CB4(struct Link *,unsigned int,unsigned int);
extern int func_02034AC4(int);
extern void func_02034A5C(int);
extern char *func_021D9DC8(u32_021E58F4,void *,u32_021E58F4,u16);
extern u32_021E58F4 func_021DC200(char *,u32_021E58F4),func_021DC240(char *,u32_021E58F4);
extern void func_021D9EA0(u8 *p);
extern void *func_0217E00C(int unused, int heap);
extern u32_021E5A90 func_0200FB24(void);
extern void func_0200FB38(void);
extern int func_0217E258(int unused, int arg);
extern int func_0217E298(u8 *p, const void *q);
extern void func_0217E074(void *);
int func_021E58F4(char **out,u32_021E58F4 *ctx,u32_021E58F4 *state);
void func_021E5A44(void **pp, u32_021E5A44 *c);
void func_021E5A70(u32_021E5A70 *out, u32_021E5A70 **pp, u32_021E5A70 v);
unsigned func_021E5A90(void **d,unsigned *c,unsigned *state);
extern unsigned char ov067_id[],ov114_id[],ov175_id[];
extern u8 ov114_id[];
extern u8 ov067_id[];
extern u8 ov176_id[];

int func_021E58F4(char **out,u32_021E58F4 *ctx,u32_021E58F4 *state)
{
    if(func_0203CD98()) {
        switch(func_02157170((void *)1,(void *)1)) {
        case 0:break;
        case 1:case 4:ctx[2]=3;return 1;
        case 2:case 3:default:ctx[2]=1;return 1;
        }
    }
    switch(*state) {
    case 0:func_02039C68((struct Link *)func_020399A8(),16,36);++*state;break;
    case 1:if(func_02039CB4((struct Link *)func_020399A8(),16,36))++*state;break;
    case 2:func_02034AC4((int)ov067_id);func_02034AC4((int)ov114_id);func_02034AC4((int)ov175_id);
        *out=func_021D9DC8(ctx[5],**(void ** *)&((struct Obj02890 *)ctx)->f0,0,88);++*state;break;
    case 3:func_02039C68((struct Link *)func_020399A8(),17,36);++*state;break;
    case 4:if(func_02039CB4((struct Link *)func_020399A8(),17,36))++*state;break;
    case 5:if(func_021DC200(*out,ctx[3]))++*state;break;
    case 6:if(func_021DC240(*out,ctx[4]))++*state;break;
    case 7:func_02039C68((struct Link *)func_020399A8(),18,36);++*state;break;
    case 8:if(func_02039CB4((struct Link *)func_020399A8(),18,36))++*state;break;
    case 9:func_021D9EA0((u8 *)((u32_021E58F4)*out));*out=0;
        func_02034A5C((int)ov175_id);func_02034A5C((int)ov114_id);func_02034A5C((int)ov067_id);++*state;break;
    case 10:func_02039C68((struct Link *)func_020399A8(),19,36);++*state;break;
    case 11:if(func_02039CB4((struct Link *)func_020399A8(),19,36))return 1;break;
    }
    return 0;
}


void func_021E5A44(void **pp, u32_021E5A44 *c)
{
    if (*pp == 0)
        return;
    func_021D9EA0((u8 *)((u32_021E5A44)*pp));
    func_02034A5C((u32_021E5A44)ov175_id);
    func_02034A5C((u32_021E5A44)ov114_id);
    func_02034A5C((u32_021E5A44)ov067_id);
}


void func_021E5A70(u32_021E5A70 *out, u32_021E5A70 **pp, u32_021E5A70 v)
{
    func_02034AC4((u32_021E5A70)ov176_id);
    *out = (u32_021E5A70)func_0217E00C(*(u32_021E5A70 *)*pp, v);
}

unsigned func_021E5A90(void **d,unsigned *c,unsigned *state)
{
 if(func_0200FB24()!=0){func_0200FB38();c[2]=2;return 1;}
 switch(*state) {
 case 0:++*state;break;
 case 1:func_02039C68((struct Link *)func_020399A8(),0x11,0x1F);++*state;break;
 case 2:if(func_02039CB4((struct Link *)func_020399A8(),0x11,0x1F)!=0)++*state;break;
 case 3:if(func_0217E258((int)(*d),c[3])!=0)++*state;break;
 case 4:if(func_0217E298(*d,(const void *)c[4])!=0)++*state;break;
 case 5:return 1;
 }
 func_0217E074(*d);return 0;
}
