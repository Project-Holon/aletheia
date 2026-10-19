/*
 * function: WIFIBATTLEMATCH_NET_GdbCopyFieldsB
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
 *   WIFIBATTLEMATCH_NET_LookupFieldEntry 0x021DD044 thumb ov175
 *   GF_STANDARD_CompareString 0x0203F028 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   d_021E2F7C 0x021E2F7C data a4
 *   d_021E2F8C 0x021E2F8C data a4
 */
#include "../include/Obj05461.h"
typedef unsigned char u8;
typedef unsigned long u32;
struct Blob { const void *data; u32 size; };
union Payload { u32 value; struct Blob blob; };
struct Field { const char *name;u32 type;union Payload payload; };
extern int WIFIBATTLEMATCH_NET_LookupFieldEntry(int);
extern int GF_STANDARD_CompareString(const char *,const char *);
extern void MI_CpuCopy8(const void *,void *,unsigned long);
extern const char d_021E2F7C[],d_021E2F8C[];
void WIFIBATTLEMATCH_NET_GdbCopyFieldsB(int count,struct Field **fields,u8 *p,int n)
{
    int i,j;
    const struct Field *f;
    for(i=0;i<count;i++) {
        for(j=0;j<n;j++) {
            f=&fields[i][j];
            if(GF_STANDARD_CompareString(f->name,(const char *)WIFIBATTLEMATCH_NET_LookupFieldEntry(0x25))==0) ((struct Obj05461 *)p)->f8=f->payload.value;
            else if(GF_STANDARD_CompareString(f->name,(const char *)WIFIBATTLEMATCH_NET_LookupFieldEntry(0x26))==0) ((struct Obj05461 *)p)->fC=f->payload.value;
            else if(GF_STANDARD_CompareString(f->name,(const char *)WIFIBATTLEMATCH_NET_LookupFieldEntry(0x24))==0) ((struct Obj05461 *)p)->f10=f->payload.value;
            else if(GF_STANDARD_CompareString(f->name,(const char *)WIFIBATTLEMATCH_NET_LookupFieldEntry(0x28))==0) ((struct Obj05461 *)p)->f4=f->payload.value;
            else if(GF_STANDARD_CompareString(f->name,(const char *)WIFIBATTLEMATCH_NET_LookupFieldEntry(0x27))==0) ((struct Obj05461 *)p)->f0=f->payload.value;
            else if(GF_STANDARD_CompareString(f->name,d_021E2F7C)==0) ((struct Obj05461 *)p)->f14=f->payload.value;
            else if(GF_STANDARD_CompareString(f->name,d_021E2F8C)==0) {
                const struct Blob *blob=&f->payload.blob;
                MI_CpuCopy8(blob->data,p+24,blob->size);
            }
        }
    }
}
