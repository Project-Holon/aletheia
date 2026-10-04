/*
 * function: func_021FC3E0
 * address: 0x021FC3E0
 * packet: pkt_ov135_021FC3E0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02200BAC 0x02200BAC thumb ov135
 *   tbl_0220351C 0x0220351C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u32 x,y,w,h;} WinDef;
typedef struct {
    u8 pad0[0xD40];
    u32 frame;
    u8 padD44[12];
    u32 side;
    u8 padD54[0x3C];
    u32 item[14];
} Menu;
extern const WinDef tbl_0220351C[];
extern u32 func_020450F0(u32,u8,u8,u8,u8,u8,u16);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
struct Cfg;
struct CharBuf;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32);
extern void func_02200BAC(void *,u32);
void func_021FC3E0(Menu *p)
{
    int i;
    u32 w;
    p->frame=func_020450F0(2,2,21,27,2,13,1);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->frame)),0);
    w=p->frame;
    func_02045334((struct Descriptor *)w);
    func_02045374((struct Cfg *)w);
    func_020409B4(func_02045730((struct Descriptor *)w));
    p->side=func_020450F0(2,21,15,10,4,13,1);
    w=p->side;
    func_02045334((struct Descriptor *)w);
    func_02045374((struct Cfg *)w);
    func_020409B4(func_02045730((struct Descriptor *)w));
    for(i=0;i<14;i++) {
        p->item[i]=func_020450F0(3,tbl_0220351C[i].x,tbl_0220351C[i].y,tbl_0220351C[i].w,tbl_0220351C[i].h,13,1);
        func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->item[i])),0);
        w=p->item[i];
        func_02045334((struct Descriptor *)w);
        func_02045374((struct Cfg *)w);
        func_020409B4(func_02045730((struct Descriptor *)w));
    }
    func_02200BAC(p,2);
}
