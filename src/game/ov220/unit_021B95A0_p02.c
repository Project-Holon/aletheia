/*
 * file:     unit_021B95A0_p02.c
 * unit:     yes
 * function: func_021BA01C, func_021BA068
 * address:  0x021BA01C
 * region:   ov220
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   d_021BA3A8 0x021BA3A8 data a2
 */
struct Cfg;
struct Descriptor;
struct PrintSys;
typedef struct Obj {
    unsigned char pad00[0x10];
    void *f10;
    unsigned char pad14[0x60 - 0x14];
    void *ptr[4];
    int done[4];
} Obj;

typedef unsigned int   u32;

typedef unsigned char  u8;

struct Record { unsigned short a,b,c,level,d,e; };

extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(unsigned int bit);
void func_021BA01C(Obj *o);
unsigned char func_021BA068(unsigned value);
extern const struct Record d_021BA3A8[];


void func_021BA01C(Obj *o)
{
    unsigned char i;

    for (i = 0; i < 4; i++) {
        if (o->done[i] == 0) {
            if (func_0201C6C4(o->f10, func_02045770(o->ptr[i])) == 0) {
                void *p = o->ptr[i];
                func_02045334(p);
                func_02045374(p);
                func_02041B6C(func_02045730(p));
                o->done[i] = 1;
            }
        }
    }
}

unsigned char func_021BA068(unsigned value)
{
    unsigned level;
    unsigned char i;
    if(value>=6000) level=6;
    else if(value>=5000) level=5;
    else if(value>=4000) level=4;
    else if(value>=3000) level=3;
    else if(value>=2000) level=2;
    else if(value>=1000) level=1;
    else level=0;
    for(i=0;i<7;i++) if(level==d_021BA3A8[i].level) return i;
    return 0;
}
