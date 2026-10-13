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
 *   BMP_WIN_Create 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
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
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
struct Cfg;
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32);
extern void func_02200BAC(u8 *p, u32 k);
void func_021FC3E0(Menu *p)
{
    int i;
    u32 w;
    p->frame=BMP_WIN_Create(2,(u8)2,(u8)21,(u8)27,2,13,(u16)1);
    BMP_Clear((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->frame)),0);
    w=p->frame;
    BMP_WIN_TransferChars((struct Descriptor *)w);
    BMP_WIN_MakeScreen((struct Cfg *)w);
    func_020409B4(func_02045730((struct Descriptor *)w));
    p->side=BMP_WIN_Create(2,(u8)21,(u8)15,(u8)10,4,13,(u16)1);
    w=p->side;
    BMP_WIN_TransferChars((struct Descriptor *)w);
    BMP_WIN_MakeScreen((struct Cfg *)w);
    func_020409B4(func_02045730((struct Descriptor *)w));
    for(i=0;i<14;i++) {
        p->item[i]=BMP_WIN_Create(3,(u8)tbl_0220351C[i].x,(u8)tbl_0220351C[i].y,(u8)tbl_0220351C[i].w,tbl_0220351C[i].h,13,(u16)1);
        BMP_Clear((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->item[i])),0);
        w=p->item[i];
        BMP_WIN_TransferChars((struct Descriptor *)w);
        BMP_WIN_MakeScreen((struct Cfg *)w);
        func_020409B4(func_02045730((struct Descriptor *)w));
    }
    func_02200BAC((u8 *)p,2);
}
