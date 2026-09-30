/*
 * function: func_021DA1BC
 * address: 0x021DA1BC
 * packet: pkt_ov121_021DA1BC
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: b is u16; const descriptor input and an element slot pointer reproduce scheduling.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021D99A4 0x021D99A4 thumb ov121
 *   func_021D9B2C 0x021D9B2C thumb ov121
 *   func_021D9B28 0x021D9B28 thumb ov121
 *   func_021D9AC8 0x021D9AC8 thumb ov121
 *   func_021D9A64 0x021D9A64 thumb ov121
 *   d_021DFBA0 0x021DFBA0 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern char d_021DFBA0[];
extern void *func_02030734(u16,int,int,const char *,int);
extern void func_02082BCC(void *,int,int);
extern void *func_021D99A4(void *,u16,u8,u8,u8,u8,u16,u16,u16);
extern void func_021D9B2C(void *,s16,s16,int);
extern void func_021D9B28(void *,u16);
extern void func_021D9AC8(void *,int,int);
extern void func_021D9A64(void *,u16,int,int);
void *func_021DA1BC(void *a,const char *desc,u32 n,u16 b,u16 c,u16 d,u16 e,int f,u16 heap)
{
    u32 i;
    int size=n*4+16;
    char *out=func_02030734(heap,size,0,d_021DFBA0,0x374);
    func_02082BCC(out,0,size);
    *(const char **)out=desc;
    *(u32 *)(out+4)=n;
    *(int *)(out+8)=f;
    *(u32 *)(out+12)=e;
    for(i=0;i<*(u32 *)(out+4);i++) {
        const char *v=desc+i*24;
        char *slot=out+i*4;
        void *q=func_021D99A4(a,b,*(u8 *)v,*(u8 *)(v+1),*(u8 *)(v+2),*(u8 *)(v+3),c,d,heap);
        *(void **)(slot+16)=q;
        func_021D9B2C(q,*(s16 *)(v+16),*(s16 *)(v+18),*(int *)(v+12));
        func_021D9B28(*(void **)(slot+16),*(u16 *)(v+20));
        if(*(int *)(v+8)) func_021D9AC8(*(void **)(slot+16),*(int *)(v+8),*(int *)(out+8));
        else func_021D9A64(*(void **)(slot+16),e,*(int *)(v+4),*(int *)(out+8));
    }
    return out;
}
