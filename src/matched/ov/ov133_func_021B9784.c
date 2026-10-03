/*
 * function: func_021B9784
 * address: 0x021B9784
 * packet: pkt_ov133_021B9784
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: 148-byte lead; unlabelled follower 021B9818 is parked at docs/notes/pkt_ov133_021B9818.c.txt.
 * symbols:
 *   func_0204B404 0x0204B404 arm
 *   func_020413B0 0x020413B0 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef short s16;
typedef struct {s16 x,y;} Pos;
extern void func_0204B404(void *,const Pos *,unsigned);
extern void func_020413B0(unsigned,u8,u8,u8,u8,u8);
extern void func_02041B6C(unsigned);
void func_021B9784(u8 *p)
{
    Pos pos;
    u8 pal;
    pos.x=32;
    pos.y=p[0x18c0]*2+160;
    if(pos.y>=224) pos.y=224;
    func_0204B404(*(void **)(p+0x184c),&pos,0);
    pos.x=224;
    pos.y=p[0x18c0]*2+160;
    if(pos.y>=224) pos.y=224;
    func_0204B404(*(void **)(p+0x1850),&pos,0);
    pal=p[0x18c0]*24/60+4;
    if(pal>=11) pal=3;
    func_020413B0(2,10,44,12,12,pal);
    func_02041B6C(2);
}
