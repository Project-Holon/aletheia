/*
 * function: func_021BC014
 * address: 0x021BC014
 * packet: pkt_ov217_021BC014
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * arity: BF28/BF3C forward entry r0/r1 to BF04/BF1C; preserve both, with observed u8 argument truncation.
 * symbols:
 *   func_021BBC50 0x021BBC50 thumb ov217
 *   func_021BC720 0x021BC720 thumb ov217
 *   func_021BBF28 0x021BBF28 thumb ov217
 *   func_021BBF3C 0x021BBF3C thumb ov217
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B92C 0x0204B92C arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
struct Obj;
struct Vec2 { s16 x,y; };
extern u8 func_021BBC50(u8 *p);
extern u32 func_021BC720(void *p,u32 index);
extern int func_021BBF28(unsigned char *p, unsigned int slot);
extern int func_021BBF3C(u8 *p,u8 index);
extern void func_0204B3DC(struct Obj *p,u32 value);
extern void func_0204B404(struct Obj *p,const struct Vec2 *delta,u32 which);
extern void func_0204B92C(struct Obj *p,u32 value);
void func_021BC014(u8 *p)
{
    struct Vec2 point;
    u32 index;
    struct Obj *obj;
    index=func_021BBC50(p);
    obj=(struct Obj *)func_021BC720(p,2);
    if(index==255) {
        func_0204B3DC(obj,0);
        return;
    }
    point.x=func_021BBF28(p,(u8)index);
    point.y=func_021BBF3C(p,index)+10;
    func_0204B404(obj,&point,0);
    func_0204B92C(obj,1);
    func_0204B3DC(obj,1);
}
