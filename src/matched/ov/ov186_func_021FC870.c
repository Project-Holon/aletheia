/*
 * function: func_021FC870
 * address: 0x021FC870
 * packet: pkt_ov186_021FC870
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes follow the 86-byte function.
 * symbols:
 *   func_020437DC 0x020437DC arm
 *   func_020437E4 0x020437E4 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201D42C 0x0201D42C thumb
 */
typedef struct {int x,y;} Pair;
typedef unsigned int   u32;
struct Bmp;
typedef unsigned short u16;
struct StrObj;
extern u16 func_020437DC(const struct Bmp *bmp);
extern u32 func_020437E4(const struct Bmp *bmp);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D42C(struct StrObj *s, void *font);
void func_021FC870(int mode,Pair *base,const void *bmp,void *text,void *font,Pair *out)
{
    unsigned x,y;
    switch(mode) {
    case 0:*out=*base;break;
    case 1:
        x=(unsigned)func_020437DC(bmp)>>1;y=(unsigned)func_020437E4(bmp)>>1;
        x-=func_0201D304(text,(unsigned)font,0)>>1;
        y-=func_0201D42C(text,font)>>1;
        out->x=x+base->x;out->y=y+base->y;break;
    }
}
