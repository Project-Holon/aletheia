/*
 * function: func_021DB938
 * address: 0x021DB938
 * packet: pkt_ov121_021DB938
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021DF86E 0x021DF86E data ov121 a2
 *   func_02041300 0x02041300 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef union Rect { u16 h[4]; u8 b[8]; } Rect;
extern const Rect d_021DF86E[];
extern void func_02041300(u32,u16,u8,u8,u8,u8,u8);
struct CharBuf;
struct Descriptor;
struct Obj;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204ADA4(u32);
extern void func_0204A8D4(u32);
extern void func_0204AFD8(u32);
void func_021DB938(char *p,int a,u16 index)
{
    Rect rect;
    int y,x,tile;
    int yy;
    rect=d_021DF86E[index];
    if((a && *(int *)(p+0xad0)==0) || (a==0 && *(int *)(p+0xad0))) {
        index+=4;
        rect.b[0]+=32;
        rect.b[2]+=32;
    }
    for(y=0;y<7;y++) {
        yy=rect.b[1]+y;
        tile=y*32+384;
        for(x=0;x<12;x++)
            func_02041300(3,(u16)(x+tile),(u8)(rect.b[0]+x),yy,1,1,3);
    }
    func_02043B5C(func_02045770(*(void **)(p+0xb08+index*4)),0);
    func_02045334(*(void **)(p+0xb08+index*4));
    if(*(void **)(p+0xb28+index*4)) {
        func_0204B3B4(*(void **)(p+0xb28+index*4));
        *(void **)(p+0xb28+index*4)=0;
        if(*(u32 *)(p+0xb88+index*4)!=-1) {
            func_0204ADA4(*(u32 *)(p+0xb88+index*4));
            *(u32 *)(p+0xb88+index*4)=-1;
        }
        if(*(u32 *)(p+0xb48+index*4)!=-1) {
            func_0204A8D4(*(u32 *)(p+0xb48+index*4));
            *(u32 *)(p+0xb48+index*4)=-1;
        }
        if(*(u32 *)(p+0xb68+index*4)!=-1) {
            func_0204AFD8(*(u32 *)(p+0xb68+index*4));
            *(u32 *)(p+0xb68+index*4)=-1;
        }
    }
}
