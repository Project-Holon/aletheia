/*
 * file:     unit_021BC388_p06.c
 * unit:     yes
 * function: func_021BE010, func_021BE1B8, func_021BE25C, func_021BE29C, func_021BE34C, func_021BE43C, func_021BE4A8, func_021BE51C, func_021BE588, func_021BE5D4
 * address:  0x021BE010
 * region:   ov209
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C940C 0x021C940C thumb ov212
 *   func_0204BA20 0x0204BA20 arm
 *   func_0204B688 0x0204B688 arm
 *   func_021BD908 0x021BD908 thumb ov209
 *   func_021BD8D8 0x021BD8D8 thumb ov209
 *   d_021BE9A4 0x021BE9A4 data a4
 *   func_020490F4 0x020490F4 arm
 *   func_0201BABC 0x0201BABC thumb
 *   func_02049E74 0x02049E74 arm
 *   func_0204B7F0 0x0204B7F0 arm
 *   func_0204AA94 0x0204AA94 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049238 0x02049238 arm
 *   func_0201BB5C 0x0201BB5C thumb
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_021BD8F4 0x021BD8F4 thumb
 *   func_0200CC40 0x0200CC40 thumb
 *   func_021BD890 0x021BD890 thumb ov209
 *   func_021BD934 0x021BD934 thumb ov209
 *   func_021BD958 0x021BD958 thumb ov209
 *   func_021BD8B0 0x021BD8B0 thumb ov209
 *   func_021B8AE4 0x021B8AE4 thumb ov067
 *   func_021B93B0 0x021B93B0 thumb ov067
 *   func_021B93B8 0x021B93B8 thumb ov067
 *   func_021B93C0 0x021B93C0 thumb ov067
 */
#include "../../matched/include/Obj25578.h"
#include "../../matched/include/Obj25579.h"
#include "../../matched/include/Obj08411.h"
#include "../../matched/include/Obj08412.h"
#include "../../matched/include/Obj00088.h"

struct Obj;
struct Actor;
struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct R { u16 f0; u16 f2; u32 f4; u32 f8; u32 fC; u32 f10; u16 f14; u16 f16; };

struct Out { char pad[20]; void *f14; };

enum Position { POSITION_ZERO=0 };

typedef signed short   s16;

extern struct Obj *func_021C940C(u32 bank, const u8 *t, u16 heap);
extern void func_0204BA20(struct Actor *a, u32 v);
extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_021BD908(char *, u32, u32);
extern void func_021BD8D8(char *, u32, u32);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern u32 func_0201BABC(u32 species, u32 form, u32 gender, u32 isEgg);
extern void *func_02049E74(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern u16 func_0204B7F0(u8 *);
extern void func_0204AA94(int,void *,unsigned,int,int);
extern u32 func_020307B0(void *p);
extern void func_02049238(void *);
extern unsigned func_0201BB5C(unsigned,unsigned,unsigned,unsigned);
extern void func_0204B6F4(struct Obj *,unsigned,unsigned);
extern u32 func_021BD8F4(char *p, u32 idx);
extern void func_0200CC40(u8 *p, u16 id, u32 *out1, u32 *out2, u32 *outForm, u16 a5);
extern void func_021BD890(char *,int,int);
extern void func_021BD934(char *,int,short,short,u16);
extern void func_021BD958(char *p, u32 idx, s16 *x, s16 *y, u16 space);
extern int func_021BD8B0(char *,int);
extern int func_021B8AE4(struct S *s, unsigned int v);
extern int func_021B93B0(char *);
extern int func_021B93B8(char *);
extern int func_021B93C0(char *);
void func_021BE010(char *p);
void func_021BE1B8(char *p, int index, unsigned species, u16 form, u16 half, int mode);
int func_021BE25C(int p, int t);
void func_021BE29C(char *p,u16 species,enum Position pos,int mode);
void func_021BE34C(char *p, int delta);
void func_021BE43C(char *p);
void func_021BE4A8(char *p);
void func_021BE51C(char *p,int index);
void func_021BE588(char *p);
void func_021BE5D4(char *p,int flag);
extern const struct R d_021BE9A4;

void func_021BE010(char *p) {
    struct R a;
    struct R b;
    u32 *pb;
    u32 i;
    u32 j;
    u32 k;
    a = d_021BE9A4;
    b = d_021BE9A4;
    b.fC = *(u32 *)(p + 0xBF4);
    b.f10 = *(u32 *)(p + 0xC0C);
    for (i = 0; i < 16; i++) {
        b.f2 = i * 0x18 + 8;
        b.f8 = *(u32 *)(p + i * 4 + 0xB64);
        *(u32 *)(p + i * 4 + 0xA9C) = (u32)func_021C940C(*(u32 *)(p + 0xA70), (const u8 *)(&b), 0x6b);
        func_0204BA20((struct Actor *)(*(u32 *)(p + i * 4 + 0xA9C)), 0);
    }
    b = a;
    b.fC = *(u32 *)(p + 0xBF8);
    b.f10 = *(u32 *)(p + 0xC10);
    for (j = 0; j < 16; j++) {
        b.f2 = j * 0x18 + 0x20;
        b.f8 = *(u32 *)(p + j * 4 + 0xBA4);
        b.f16 = 1;
        *(u32 *)(p + j * 4 + 0xADC) = (u32)func_021C940C(*(u32 *)(p + 0xA70), (const u8 *)(&b), 0x6b);
        func_0204BA20((struct Actor *)(*(u32 *)(p + j * 4 + 0xADC)), 0);
        func_021BD908(p, j + 0x1a, 1);
        pb = (u32 *)(p + 0xA70);
        *(u32 *)(p + j * 4 + 0xB1C) = (u32)func_021C940C(*pb, (const u8 *)(&b), 0x6b);
        func_0204BA20((struct Actor *)(*(u32 *)(p + j * 4 + 0xB1C)), 0);
        func_0204B688((struct Actor *)(*(u32 *)(p + j * 4 + 0xB1C)), 2);
    }
    for (k = 0; k < 16; k++) func_021BD8D8(p, k + 0xa, 0);
    for (i = 0; i < 16; i++) {
        func_021BD8D8(p, i + 0x1a, 0);
        func_021BD8D8(p, i + 0x2a, 0);
    }
}

void func_021BE1B8(char *p, int index, unsigned species, u16 form, u16 half, int mode)
{
    void *owner;
    void *data;
    struct Out *out;
    struct Obj **slot;
    unsigned saved;
    owner=func_020490F4(7,0x806b);
    saved=half;
    data=func_02049E74((void *)((unsigned)owner),func_0201BABC(species,form,saved,0),0,(unsigned)&out,0x806b);
    if (mode==1) {
        slot=(struct Obj **)(p+0xa74+index*4);
        func_0204AA94(func_0204B7F0((u8 *)*slot),out->f14,1024,0,0);
    } else {
        slot=(struct Obj **)(p+0xa74+index*4);
        func_0204AA94(func_0204B7F0((u8 *)*slot),out->f14,1024,0,1);
    }
    func_020307B0(data);
    func_02049238(owner);
    func_0204B6F4(*slot,func_0201BB5C(species,form,saved,0),1);
}


int func_021BE25C(int p, int t)
{
    unsigned int i;

    if (t == 1) {
        for (i = 0xa; i < 0x1a; i++) {
            if (func_021BD8F4((char *)p, i) == 0) {
                return i;
            }
        }
    } else {
        for (i = 0x1a; i < 0x2a; i++) {
            if (func_021BD8F4((char *)p, i) == 0) {
                return i;
            }
        }
    }
    return 0;
}

/*
 * Enum position preserves the full-width update and repeated signed-halfword argument conversions.
 */
void func_021BE29C(char *p,u16 species,enum Position pos,int mode)
{
    unsigned out1,outForm,out2;
    int index;
    func_0200CC40(*(u8 * *)&((struct Obj25579 *)(*(char * *)&((struct Obj25578 *)p)->f0))->f4,species,&out1,&out2,&outForm,0x806b);
    index=func_021BE25C((int)p,mode);
    func_021BE1B8(p,index,species,outForm,out1,mode);
    func_021BD8D8(p,index,1);
    func_021BD890(p,index,0);
    if (mode==1) {
        pos+=8;
        func_021BD934(p,index,112,pos,0);
        return;
    }
    pos+=8;
    func_021BD934(p,index,112,pos,1);
    func_021BD934(p,index+16,112,pos,1);
    index+=16;
    func_021BD8D8(p,index,1);
}

void func_021BE34C(char *p, int delta)
{
    unsigned i;
    short pos[2];
    for (i = 10; i < 26; i++) {
        if (func_021BD8F4((char *)p, i) != 0) {
            func_021BD958(p, i, &pos[1], &pos[0], 0);
            func_021BD934(p, (unsigned)i, (short)pos[1], (short)(pos[0] + delta), 0);
            if (pos[0] + delta <= -16 || pos[0] + delta >= 200)
                func_021BD8D8(p, i, 0);
        }
    }
    for (i = 26; i < 42; i++) {
        if (func_021BD8F4((char *)p, i) != 0) {
            func_021BD958(p, i, &pos[1], &pos[0], 1);
            func_021BD934(p, (unsigned)i, (short)pos[1], (short)(pos[0] + delta), 1);
            func_021BD934(p, (unsigned)(i + 16), (short)pos[1], (short)(pos[0] + delta), 1);
            if (pos[0] + delta <= -16 || pos[0] + delta >= 200) {
                func_021BD8D8(p, i, 0);
                func_021BD8D8(p, i + 16, 0);
            }
        }
    }
}

void func_021BE43C(char *p)
{
    unsigned i;
    ((struct Obj08411 *)p)->fC28=0;
    ((struct Obj08411 *)p)->fC2A=0;
    for(i=10;i<26;i++)if(func_021BD8F4((char *)((int)p),i))((struct Obj08411 *)p)->fC28|=(u16)(1<<(i-10));
    for(i=26;i<42;i++)if(func_021BD8F4((char *)((int)p),i))((struct Obj08411 *)p)->fC2A|=(u16)(1<<(i-26));
}

void func_021BE4A8(char *p)
{
    unsigned i;
    for(i=10;i<26;i++)if(((struct Obj08412 *)p)->fC28&(1<<(i-10)))func_021BD8D8(p,i,0);
    for(i=26;i<42;i++)if(((struct Obj08412 *)p)->fC2A&(1<<(i-26))){func_021BD8D8(p,i,0);func_021BD8D8(p,i+16,0);}
    ((struct Obj08412 *)p)->fC28=0;
    ((struct Obj08412 *)p)->fC2A=0;
}

/*
 * Row expression assigned back to index keeps the entry register; 021BE586 is two zero alignment bytes.
 */
void func_021BE51C(char *p,int index)
{
    unsigned i;
    short pos[2];
    index=index*24+8;
    for(i=10;i<26;i++){
        if(func_021BD8F4((char *)p,i)==0)func_021BD890(p,i,0);
        else{
            func_021BD958(p,i,&pos[1],&pos[0],0);
            if(index==pos[0]){if(func_021BD8B0(p,i)!=1)func_021BD890(p,i,1);}
            else func_021BD890(p,i,0);
        }
    }
}

void func_021BE588(char *p)
{
    short pos[2];
    unsigned value;
    func_021BD958(p,0,&pos[1],&pos[0],0);
    value=func_021B8AE4(*(struct S * *)&((struct Obj00088 *)p)->fC2C,pos[0]);
    if(value<12)value=12;else if(value>156)value=156;
    func_021BD934(p,0,(short)252,(short)value,0);
}

void func_021BE5D4(char *p,int flag)
{
    int n=func_021B93B0(*(char * *)&((struct Obj00088 *)p)->fC2C);
    if (func_021BD8B0(p,7)!=12 || flag==0) {
        if (func_021B93B8(*(char * *)&((struct Obj00088 *)p)->fC2C)==0 && n==0)
            func_021BD890(p,7,18);
        else func_021BD890(p,7,4);
    }
    if (func_021BD8B0(p,6)!=13 || flag==0) {
        if (func_021B93C0(*(char * *)&((struct Obj00088 *)p)->fC2C)==0 && n==((struct Obj00088 *)p)->fC34-1) {
            func_021BD890(p,6,19);
            return;
        }
        else func_021BD890(p,6,5);
    }
}
