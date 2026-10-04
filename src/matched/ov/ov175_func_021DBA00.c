/*
 * function: func_021DBA00
 * address: 0x021DBA00
 * packet: pkt_ov175_021DBA00
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: a named pointer to the nested Blob union member preserves its
 *   base-plus-eight address and the subsequent size load; flat payload and
 *   nested direct access each gave 252 bytes / 50 differences, pointer EXACT.
 * retry: three runs; prior permuter300 not repeated.
 * symbols:
 *   func_021DD044 0x021DD044 thumb ov175
 *   func_0203F028 0x0203F028 arm
 *   func_02082D44 0x02082D44 arm
 *   d_021E2F7C 0x021E2F7C data a4
 *   d_021E2F8C 0x021E2F8C data a4
 */
#include "../include/Obj05461.h"
typedef unsigned char u8;
typedef unsigned long u32;
struct Blob { const void *data; u32 size; };
union Payload { u32 value; struct Blob blob; };
struct Field { const char *name;u32 type;union Payload payload; };
extern int func_021DD044(int);
extern int func_0203F028(const char *,const char *);
extern void func_02082D44(const void *,void *,unsigned long);
extern const char d_021E2F7C[],d_021E2F8C[];
void func_021DBA00(int count,struct Field **fields,u8 *p,int n)
{
    int i,j;
    const struct Field *f;
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
