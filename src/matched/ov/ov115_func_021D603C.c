/*
 * function: func_021D603C
 * address: 0x021D603C
 * packet: pkt_ov115_021D603C
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021D4D38 0x021D4D38 thumb ov115
 *   func_021D5984 0x021D5984 thumb ov115
 *   func_021D6134 0x021D6134 thumb ov115
 *   func_021D6150 0x021D6150 thumb ov115
 *   func_021D5CCC 0x021D5CCC thumb ov115
 *   func_0203D34C 0x0203D34C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum { FALSE, TRUE } BOOL;
extern void func_0203064C(u32,u32,u32);
extern u8 *func_0203159C(void *,int,int);
extern void func_02082BCC(void *,int,unsigned);
extern void *func_021D4D38(u16,int,int);
extern u8 *func_021D5984(u32 heap, u32 bank, u32 mode);
extern void func_021D6134(void *,void (*)(void),int);
extern void func_021D6150(u8 *p);
extern void func_021D5CCC(u8 *p, u32 n);
extern void func_02005D90(int,int);
extern void func_0203D34C(u32 a, u32 b);
int func_021D603C(void *ctx,int unused,u8 *q) {
    u8 *p;
    BOOL flag;
    func_0203064C(1,121,0x18000);
    p=func_0203159C(ctx,32,121);
    func_02082BCC(p,0,32);
    *(u8 **)(p+16)=q;
    *(u16 *)(p+20)=121;
    if(*(u32 *)(q+16)==0) *(u32 *)(q+16)=6;
    *(void **)(p+4)=func_021D4D38(*(u16 *)(p+20),*(int *)(q+4),*(int *)(q+8));
    *(void **)(p+8)=func_021D5984(*(u16 *)(p+20),232,*(int *)(q+8));
    func_021D6134(p,(void (*)(void))func_021D6150,173);
    if(*(u32 *)(q+4)==0) {
        func_021D5CCC(*(void **)(p+8),36);
        if(*(u32 *)(q+12)==0) func_02005D90(1153,65535);
    }
    if(*(u32 *)(q+8)==0) flag=FALSE; else flag=TRUE;
    func_0203D34C(flag,*(u16 *)(p+20));
    return 1;
}
