/*
 * function: func_021BC5C4
 * address: 0x021BC5C4
 * packet: pkt_ov216_021BC5C4
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
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
 */
struct Descriptor;
struct Cfg;
struct CharBuf;
typedef struct { struct Descriptor *window; struct CharBuf *buffer; struct Descriptor *copy; unsigned char state; } Window;
extern unsigned func_020450F0(unsigned,unsigned,unsigned,unsigned,unsigned char,unsigned char,unsigned char);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *,unsigned char);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *);
extern unsigned char func_02045730(struct Descriptor *);
extern void func_020409B4(unsigned);
void func_021BC5C4(Window *p,unsigned layer,unsigned char palette,unsigned x,unsigned char y,unsigned char width,unsigned char height)
{
    struct Descriptor *window;
    p->window=(struct Descriptor *)func_020450F0(layer,x,y,width,height,palette,1);
    p->buffer=func_02045770(p->window);
    p->copy=p->window;
    p->state=0;
    func_02043B5C(p->buffer,3);
    window=p->window;
    func_02045334(window);
    func_02045374((struct Cfg *)window);
    func_020409B4(func_02045730(window));
}
