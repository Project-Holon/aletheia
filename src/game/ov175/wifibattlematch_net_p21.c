/*
 * file:     wifibattlematch_net_p21.c
 * unit:     yes
 * function: func_021DB7C0, func_021DBA00, func_021DBB00
 * address:  0x021DB7C0
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021DD044 0x021DD044 thumb ov175
 *   func_0203F028 0x0203F028 arm
 *   d_021E2F4C 0x021E2F4C data a4
 *   d_021E2F60 0x021E2F60 data a4
 *   d_021E2F7C 0x021E2F7C data a4
 *   d_021E2F70 0x021E2F70 data a4
 *   func_02082D44 0x02082D44 arm
 *   d_021E2F8C 0x021E2F8C data a4
 */
#include "../../matched/include/Obj00922.h"
#include "../../matched/include/Obj05461.h"
#include "../../matched/include/Obj14343.h"

typedef unsigned long u32;

struct Field_021DB7C0 { const char *name; u32 type; u32 value; u32 pad; };

typedef unsigned char u8;

struct Blob { const void *data; u32 size; };

union Payload { u32 value; struct Blob blob; };

struct Field_021DBA00 { const char *name;u32 type;union Payload payload; };

extern int func_021DD044(int);
extern int func_0203F028(const char *,const char *);
extern void func_02082D44(const void *,void *,unsigned long);
void func_021DB7C0(int count,struct Field_021DB7C0 **fields,char *p,int n);
void func_021DBA00(int count,struct Field_021DBA00 **fields,u8 *p,int n);
void func_021DBB00(int count, char **rows, int *out, int width);
extern const char d_021E2F4C[],d_021E2F60[],d_021E2F7C[],d_021E2F70[];
extern const char d_021E2F7C[],d_021E2F8C[];

void func_021DB7C0(int count,struct Field_021DB7C0 **fields,char *p,int n) {
    int i,j;
    struct Field_021DB7C0 *f;
    for(i=0;i<count;i++) {
        for(j=0;j<n;j++) {
            f=&fields[i][j];
            if(!func_0203F028(f->name,(const char *)func_021DD044(9))) ((struct Obj00922 *)p)->f40=f->value;
            else if(!func_0203F028(f->name,(const char *)func_021DD044(10))) ((struct Obj00922 *)p)->f3C=f->value;
            else if(!func_0203F028(f->name,(const char *)func_021DD044(12))) ((struct Obj00922 *)p)->f28=f->value;
            else if(!func_0203F028(f->name,(const char *)func_021DD044(11))) ((struct Obj00922 *)p)->f24=f->value;
            else if(!func_0203F028(f->name,(const char *)func_021DD044(13))) ((struct Obj00922 *)p)->f30=f->value;
            else if(!func_0203F028(f->name,(const char *)func_021DD044(14))) ((struct Obj00922 *)p)->f2C=f->value;
            else if(!func_0203F028(f->name,(const char *)func_021DD044(15))) ((struct Obj00922 *)p)->f48=f->value;
            else if(!func_0203F028(f->name,(const char *)func_021DD044(16))) ((struct Obj00922 *)p)->f44=f->value;
            else if(!func_0203F028(f->name,(const char *)func_021DD044(17))) ((struct Obj00922 *)p)->f38=f->value;
            else if(!func_0203F028(f->name,(const char *)func_021DD044(18))) ((struct Obj00922 *)p)->f34=f->value;
            else if(!func_0203F028(f->name,(const char *)func_021DD044(19))) ((struct Obj00922 *)p)->fC=f->value;
            else if(!func_0203F028(f->name,(const char *)func_021DD044(20))) ((struct Obj00922 *)p)->f0=f->value;
            else if(!func_0203F028(f->name,(const char *)func_021DD044(21))) ((struct Obj00922 *)p)->f4=f->value;
            else if(!func_0203F028(f->name,(const char *)func_021DD044(22))) ((struct Obj00922 *)p)->f10=f->value;
            else if(!func_0203F028(f->name,(const char *)func_021DD044(23))) ((struct Obj00922 *)p)->f8=f->value;
            else if(!func_0203F028(f->name,(const char *)func_021DD044(3))) ((struct Obj00922 *)p)->f20=f->value;
            else if(!func_0203F028(f->name,(const char *)func_021DD044(24))) ((struct Obj00922 *)p)->f18=f->value;
            else if(!func_0203F028(f->name,d_021E2F4C)) ((struct Obj00922 *)p)->f4C=f->value;
            else if(!func_0203F028(f->name,d_021E2F60)) ((struct Obj00922 *)p)->f50=f->value;
            else if(!func_0203F028(f->name,d_021E2F7C)) ((struct Obj00922 *)p)->f54=f->value;
            else if(!func_0203F028(f->name,d_021E2F70)) ((struct Obj00922 *)p)->f58=f->value;
        }
    }
}

void func_021DBA00(int count,struct Field_021DBA00 **fields,u8 *p,int n)
{
    int i,j;
    const struct Field_021DBA00 *f;
    for(i=0;i<count;i++) {
        for(j=0;j<n;j++) {
            f=&fields[i][j];
            if(func_0203F028(f->name,(const char *)func_021DD044(0x25))==0) ((struct Obj05461 *)p)->f8=f->payload.value;
            else if(func_0203F028(f->name,(const char *)func_021DD044(0x26))==0) ((struct Obj05461 *)p)->fC=f->payload.value;
            else if(func_0203F028(f->name,(const char *)func_021DD044(0x24))==0) ((struct Obj05461 *)p)->f10=f->payload.value;
            else if(func_0203F028(f->name,(const char *)func_021DD044(0x28))==0) ((struct Obj05461 *)p)->f4=f->payload.value;
            else if(func_0203F028(f->name,(const char *)func_021DD044(0x27))==0) ((struct Obj05461 *)p)->f0=f->payload.value;
            else if(func_0203F028(f->name,d_021E2F7C)==0) ((struct Obj05461 *)p)->f14=f->payload.value;
            else if(func_0203F028(f->name,d_021E2F8C)==0) {
                const struct Blob *blob=&f->payload.blob;
                func_02082D44(blob->data,p+24,blob->size);
            }
        }
    }
}

void func_021DBB00(int count, char **rows, int *out, int width)
{
    int i, j;
    char *record;
    for (i = 0; i < count; i++) {
        for (j = 0; j < width; j++) {
            record = rows[i] + j * 16;
            if (func_0203F028(*(char * *)&((struct Obj14343 *)record)->f0, d_021E2F70) == 0)
                *out = ((struct Obj14343 *)record)->f8;
        }
    }
}
