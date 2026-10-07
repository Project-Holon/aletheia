/*
 * file:     br_btn_p03.c
 * unit:     yes
 * function: func_021FA0A8, func_021FA0FC, func_021FA1DC
 * address:  0x021FA0A8
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_021FACE0 0x021FACE0 thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FB760 0x021FB760 thumb ov186
 *   func_021FB704 0x021FB704 thumb ov186
 *   func_021FB7D0 0x021FB7D0 thumb ov186
 *   func_021FAC20 0x021FAC20 thumb ov186
 *   func_021FAFA0 0x021FAFA0 thumb ov186
 *   func_021FB514 0x021FB514 thumb ov186
 *   func_02045808 0x02045808 arm
 *   func_02034714 0x02034714 arm
 *   d_02200D18 0x02200D18 data a1
 */
#include "../../matched/include/Obj01277.h"
#include "../../matched/include/Obj08328.h"

struct Fields;
struct U16Vec;
struct MsgBank;
typedef struct { unsigned words[17]; } Record;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned u32;

extern void func_02082BCC(void *, int, unsigned);
extern void func_021FACE0(char *p);
extern int func_021FC214(char *);
extern u16 func_021FB760(void *,int);
extern void *func_021FB704(char *ctx, int section, unsigned item);
extern void *func_021FB7D0(unsigned * const *p, void *record, struct MsgBank *archive, unsigned short heap);
extern void func_021FAC20(struct Fields *,unsigned,unsigned,unsigned,void *,const void *,unsigned,u16);
extern int func_021FAFA0(void *,int);
extern void func_021FB514(char *p, short x, int y);
extern void func_02045808(struct U16Vec *vec);
extern void func_02034714(const char *,unsigned,const char *);
int func_021FA0A8(unsigned char *ctx, Record *out);
void func_021FA0FC(u8 *p,int section,const int *pos);
void func_021FA1DC(char *p,int x,int y);
extern char d_02200D18[];

int func_021FA0A8(unsigned char *ctx, Record *out)
{
    if (ctx[0x3b]) {
        ctx[0x3b]--;
        *out = (*(Record **)(ctx + 0x3c))[ctx[0x3b]];
        func_02082BCC(&(*(Record **)(ctx + 0x3c))[ctx[0x3b]], 0, 0x44);
        return 1;
    }
    return 0;
}

void func_021FA0FC(u8 *p,int section,const int *pos)
{
 int i,bank;
 void *rec,*text;
 for(i=0;i<p[0x38];i++)func_021FACE0((char *)(*(u8 * *)&((struct Obj01277 *)p)->f40+i*0x44));
 bank=func_021FC214(*(char * *)&((struct Obj01277 *)p)->f4);
 p[0x39]=func_021FB760(((struct Obj01277 *)p)->f44,section);
 for(i=0;i<p[0x39];i++){
  rec=func_021FB704(*(char * *)&((struct Obj01277 *)p)->f44,section,(u16)i);
  text=func_021FB7D0(*(unsigned *const * *)&((struct Obj01277 *)p)->f44,rec,(struct MsgBank *)bank,(((struct Obj01277 *)p)->f0&0x7fff)|0x8000);
  func_021FAC20((struct Fields *)(*(u8 * *)&((struct Obj01277 *)p)->f40+i*0x44),(u32)rec,((struct Obj01277 *)p)->f8,((struct Obj01277 *)p)->f48,((struct Obj01277 *)p)->f4,text,((struct Obj01277 *)p)->f10,((struct Obj01277 *)p)->f0);
  func_02045808(text);
  func_021FAFA0(*(u8 * *)&((struct Obj01277 *)p)->f40+i*0x44,3);
  if(pos)func_021FB514(*(void **)(*(u8 * *)&((struct Obj01277 *)p)->f40+i*0x44+8),pos[0],(short)pos[1]);
 }
}

void func_021FA1DC(char *p,int x,int y) { if(((struct Obj08328 *)p)->f18>=6)func_02034714(d_02200D18,0,d_02200D18);*(unsigned short *)((unsigned)p+((struct Obj08328 *)p)->f18*4)=x;*(unsigned short *)((unsigned)p+((struct Obj08328 *)p)->f18*4+2)=y;(((struct Obj08328 *)p)->f18)++; }
