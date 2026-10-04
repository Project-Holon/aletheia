/*
 * function: func_021D62A4
 * address: 0x021D62A4
 * packet: pkt_ov175_021D62A4
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02012944 0x02012944 thumb
 *   func_021E5548 0x021E5548 thumb ov177
 *   func_02082BCC 0x02082BCC arm
 *   func_0200DFD8 0x0200DFD8 thumb
 *   func_02008554 0x02008554 thumb
 *   func_021E5C20 0x021E5C20 thumb ov177
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef struct { u32 kind; u16 count,pad; u32 name,total; u16 a,b; } Desc;
typedef unsigned char  u8;
struct Sub0200852CObj;
extern u8 *func_02012944(void *p);
extern int func_021E5548(int *);
extern void func_02082BCC(void *,int,u32);
extern u32 func_0200DFD8(u32,u32,u32);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern u32 func_021E5C20(Desc *,int,u32,int,u32,u32,u32,u32,u32,int);
#define CTX ((u32 *)p[16])
#define REC ((u32 *)CTX[2])
void func_021D62A4(u32 *p,int mode)
{
    u32 sys;
    int base,flag;
    Desc desc;
    if(p[6]==0) {
        sys=(u32)func_02012944((void *)REC[0]);
        base=func_021E5548((int *)p[0]);
        func_02082BCC(&desc,0,20);
        if(mode==0) {
            desc.kind=REC[1]; flag=1;
            desc.count=func_0200DFD8(CTX[4],REC[1]+5,0);
            desc.a=func_0200DFD8(CTX[4],REC[1]+5,1);
            desc.b=func_0200DFD8(CTX[4],REC[1]+5,2);
            desc.total=desc.a+desc.b;
            if(desc.count==0 && desc.total==0) desc.count=1500;
        } else if(mode==1) {
            desc.kind=REC[1]; flag=0; desc.count=0;
            desc.a=func_0200DFD8(CTX[4],REC[1],1);
            desc.b=func_0200DFD8(CTX[4],REC[1],2);
            desc.total=desc.a+desc.b;
        }
        desc.name=func_02008554((const struct Sub0200852CObj *)sys);
        p[6]=func_021E5C20(&desc,flag,sys,base,p[1],p[2],p[3],p[4],p[5],87);
    }
}
