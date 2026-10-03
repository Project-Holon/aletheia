/*
 * function: func_021DA6A4
 * address: 0x021DA6A4
 * packet: pkt_ov131_021DA6A4
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * semantics: u8 loop indices bound multiplication to 255*24; no signed
 * overflow. Descriptor fields are initialized before the call. BAD0 reads
 * offsets 0,4,6,8,12,16,17,18,20; trailing padding is never read.
 * symbols:
 *   d_021DC2C2 0x021DC2C2 data a1
 *   func_020450F0 0x020450F0 arm
 *   func_02045798 0x02045798 arm
 *   func_02043678 0x02043678 arm
 *   func_021D9EE8 0x021D9EE8 thumb ov131
 *   func_021DB7D4 0x021DB7D4 thumb ov131
 *   func_021D614C 0x021D614C thumb ov131
 *   func_021DBAD0 0x021DBAD0 thumb ov131
 *   func_021DBCA4 0x021DBCA4 thumb ov131
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct { void *bmp; s16 x,y; void *resource; u32 value; u8 a,b; u16 c; u32 d; } Descriptor;
extern const u8 d_021DC2C2[];
extern void *func_020450F0(u32,u32,u32,u32,u8,u8,u8);
struct Bmp;
struct Descriptor;
extern void func_02045798(struct Descriptor *p, u8 v);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u32 heap);
extern void func_021D9EE8(u8 *,u8 *);
extern void func_021DB7D4(u8 *p, u8 *q, u8 *entry);
extern void func_021D614C(u8 *,int,int,int,s16,u16);
extern u8 *func_021DBAD0(void *,Descriptor *);
extern void func_021DBCA4(u8 *,int);
void func_021DA6A4(u8 *a,u8 *p)
{
    u8 i;
    Descriptor desc;
    for(i=0;i<13;i++) {
        *(void **)(p+0x5c+i*4)=func_020450F0(4,d_021DC2C2[i*4],d_021DC2C2[i*4+1],d_021DC2C2[i*4+2],d_021DC2C2[i*4+3],14,1);
    }
    func_02045798(*(void **)(p+0x60),13);
    func_021D9EE8(a,p);
    for(i=0;i<p[43];i++) func_021DB7D4(a,p,p+0xb0+i*24);
    if(p[43]==5) {
        *(void **)(p+0xa8)=func_02043678(11,4,32,*(u16 *)a);
        func_021D614C(a,*(int *)(p+0xa8),193,5,9,1088);
        desc.x=32;
        desc.y=160;
        desc.resource=*(void **)(a+0xb8);
        desc.value=0;
        desc.a=0;
        desc.b=0;
        desc.c=0;
        desc.d=0;
        desc.bmp=*(void **)(p+0xa8);
        *(u8 **)(p+0xac)=func_021DBAD0(*(void **)(p+0xa4),&desc);
        func_021DBCA4(*(u8 **)(p+0xac),0);
    }
    p[41]=255;
    *(u32 *)p=1;
    *(u32 *)(p+32)=0;
    p[40]=0;
}
