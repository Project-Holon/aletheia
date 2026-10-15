/*
 * function: WIFIBATTLEMATCH_NET_GdbCopyFieldsA
 * address: 0x021DB7C0
 * packet: pkt_ov175_021DB7C0
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFIBATTLEMATCH_NET_CompareField 0x021DD044 thumb ov175
 *   GF_STANDARD_CompareString 0x0203F028 arm
 *   d_021E2F4C 0x021E2F4C data a4
 *   d_021E2F60 0x021E2F60 data a4
 *   d_021E2F7C 0x021E2F7C data a4
 *   d_021E2F70 0x021E2F70 data a4
 */
#include "../include/Obj00922.h"
typedef unsigned long u32;
struct Field { const char *name; u32 type; u32 value; u32 pad; };
extern int WIFIBATTLEMATCH_NET_CompareField(int);
extern int GF_STANDARD_CompareString(const char *,const char *);
extern const char d_021E2F4C[],d_021E2F60[],d_021E2F7C[],d_021E2F70[];
void WIFIBATTLEMATCH_NET_GdbCopyFieldsA(int count,struct Field **fields,char *p,int n) {
    int i,j;
    struct Field *f;
    for(i=0;i<count;i++) {
        for(j=0;j<n;j++) {
            f=&fields[i][j];
            if(!GF_STANDARD_CompareString(f->name,(const char *)WIFIBATTLEMATCH_NET_CompareField(9))) ((struct Obj00922 *)p)->f40=f->value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)WIFIBATTLEMATCH_NET_CompareField(10))) ((struct Obj00922 *)p)->f3C=f->value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)WIFIBATTLEMATCH_NET_CompareField(12))) ((struct Obj00922 *)p)->f28=f->value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)WIFIBATTLEMATCH_NET_CompareField(11))) ((struct Obj00922 *)p)->f24=f->value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)WIFIBATTLEMATCH_NET_CompareField(13))) ((struct Obj00922 *)p)->f30=f->value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)WIFIBATTLEMATCH_NET_CompareField(14))) ((struct Obj00922 *)p)->f2C=f->value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)WIFIBATTLEMATCH_NET_CompareField(15))) ((struct Obj00922 *)p)->f48=f->value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)WIFIBATTLEMATCH_NET_CompareField(16))) ((struct Obj00922 *)p)->f44=f->value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)WIFIBATTLEMATCH_NET_CompareField(17))) ((struct Obj00922 *)p)->f38=f->value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)WIFIBATTLEMATCH_NET_CompareField(18))) ((struct Obj00922 *)p)->f34=f->value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)WIFIBATTLEMATCH_NET_CompareField(19))) ((struct Obj00922 *)p)->fC=f->value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)WIFIBATTLEMATCH_NET_CompareField(20))) ((struct Obj00922 *)p)->f0=f->value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)WIFIBATTLEMATCH_NET_CompareField(21))) ((struct Obj00922 *)p)->f4=f->value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)WIFIBATTLEMATCH_NET_CompareField(22))) ((struct Obj00922 *)p)->f10=f->value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)WIFIBATTLEMATCH_NET_CompareField(23))) ((struct Obj00922 *)p)->f8=f->value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)WIFIBATTLEMATCH_NET_CompareField(3))) ((struct Obj00922 *)p)->f20=f->value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)WIFIBATTLEMATCH_NET_CompareField(24))) ((struct Obj00922 *)p)->f18=f->value;
            else if(!GF_STANDARD_CompareString(f->name,d_021E2F4C)) ((struct Obj00922 *)p)->f4C=f->value;
            else if(!GF_STANDARD_CompareString(f->name,d_021E2F60)) ((struct Obj00922 *)p)->f50=f->value;
            else if(!GF_STANDARD_CompareString(f->name,d_021E2F7C)) ((struct Obj00922 *)p)->f54=f->value;
            else if(!GF_STANDARD_CompareString(f->name,d_021E2F70)) ((struct Obj00922 *)p)->f58=f->value;
        }
    }
}
