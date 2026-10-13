/*
 * function: func_021BB054
 * address: 0x021BB054
 * packet: pkt_ov110_021BB054
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: ov110 loads ov067 at 021C0134; 021BAEDC creates +78 via ov067 021B6C74.
 * lever: id/k clear order and value-before-j declaration; pooled table has alignment-only hint.
 * symbols:
 *   func_021BB00C 0x021BB00C thumb ov110
 *   func_021B99F0 0x021B99F0 thumb ov110
 *   func_021B9A48 0x021B9A48 thumb ov110
 *   func_021B99D8 0x021B99D8 thumb ov110
 *   MSGSEARCH_Search 0x021B6CE0 thumb ov067
 *   STRBUF_Clear 0x0204581C arm
 *   func_02045F50 0x02045F50 arm
 *   d_021C375C 0x021C375C data a2
 */
#include "../include/Obj01391.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned u32;
struct Obj;
struct U16Vec;
extern void STRBUF_Clear(struct U16Vec *vec);
extern void func_021BB00C(void *,void *);
extern u16 func_02045F50(const struct Obj *o);
extern u16 func_021B99F0(int,int,int);
extern int func_021B9A48(u32);
extern u32 func_021B99D8(u32,u32,u32);
extern u32 MSGSEARCH_Search(void *,u32,u32,u32,void *,u32);
extern const u16 d_021C375C[10];
int func_021BB054(u8 *p)
{
    u16 special[265];
    u16 normal[265];
    u32 n,id;
    unsigned i,k,found;
    u32 value;
    unsigned j;
    id=((struct Obj01391 *)p)->fAD4;
    if(id>=27) {
        p[0xaf1]=0;
        return 0;
    }
    STRBUF_Clear(((struct Obj01391 *)p)->fAD0);
    func_021BB00C(p,((struct Obj01391 *)p)->fAD0);
    if(id==26) {
        n=func_02045F50(*(void **)(p+0xc+id*4));
        k=0;
        __builtin__clear(special,sizeof(special));
        for(i=0;i<n;i++) {
            value=func_021B99F0(*(int *)&((struct Obj01391 *)p)->f4,id,i);
            found=0;
            for(j=0;j<10;j++) {
                if(value==d_021C375C[j]) { found=1; break; }
            }
            if(!found) {
                *(u32 *)(p+0x7c+k*8)=id;
                *(u32 *)(p+0x80+k*8)=i;
                special[k]=value;
                k++;
            }
        }
        special[k]=func_021B9A48(((struct Obj01391 *)p)->f4);
        p[0xaf1]=func_021B99D8(((struct Obj01391 *)p)->f4,(u32)special,(u32)(p+0x8bc));
        if(p[0xaf1]) return 1;
        return 0;
    } else {
        __builtin__clear(normal,sizeof(normal));
        n=MSGSEARCH_Search(((struct Obj01391 *)p)->f78,id,0,*(u32 *)&((struct Obj01391 *)p)->fAD0,p+0x7c,264);
        for(i=0;i<n;i++) {
            normal[i]=func_021B99F0(*(int *)&((struct Obj01391 *)p)->f4,id,*(int *)(p+0x80+i*8));
        }
        normal[n]=func_021B9A48(((struct Obj01391 *)p)->f4);
        p[0xaf1]=func_021B99D8(((struct Obj01391 *)p)->f4,(u32)normal,(u32)(p+0x8bc));
        if(p[0xaf1]) return 1;
        return 0;
    }
}
