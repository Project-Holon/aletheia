/*
 * function: func_021BC23C
 * address: 0x021BC23C
 * packet: pkt_ov110_021BC23C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes zero alignment padding at 0x021BC31E.
 * symbols:
 *   func_021BC0CC 0x021BC0CC thumb ov110
 *   func_021BF6D8 0x021BF6D8 thumb ov110
 *   func_021BC58C 0x021BC58C thumb ov110
 *   func_021BF6F0 0x021BF6F0 thumb ov110
 *   func_021BC5BC 0x021BC5BC thumb ov110
 *   func_021BC340 0x021BC340 thumb ov110
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef struct { s16 x,y; } Pair;
typedef struct { void *root; u8 *state; int pad; void *desc[2]; u8 gap0[8]; void *items[2][2]; u8 gap[12]; Pair pos[2]; int pad40; int count; } Obj;
extern void func_021BC0CC(u8 *p);
typedef unsigned int   u32;
struct CharBuf;
struct Descriptor;
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern unsigned func_021BF6D8(u8 *);
extern void func_021BC58C(void *,Pair *);
extern u32 func_021BF6F0(u8 *p, u32 i);
struct Vec2;
extern void func_021BC5BC(u8 *p, struct Descriptor *window, const struct Vec2 *input, u32 id, struct Obj *sprite);
extern int func_021BC340(Obj *,void *,u8);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void func_02041B6C(unsigned);
void func_021BC23C(Obj *p)
{
    int i,j;
    func_021BC0CC((u8 *)p);
    for(i=0;i<2;i++) {
        for(j=0;j<2;j++) {
            if(p->items[j][i]) func_0204B3DC(p->items[j][i],0);
        }
        BMP_Clear(func_02045770(p->desc[i]),15);
        switch(func_021BF6D8(p->state)) {
        case 0:
            func_021BC58C(p->desc[i],&p->pos[0]);
            func_021BC5BC((u8 *)p,p->desc[i],(const struct Vec2 *)(&p->pos[0]),func_021BF6F0(p->state,0),p->items[0][i]);
            break;
        case 1:
            func_021BC58C(p->desc[i],&p->pos[0]);
            func_021BC58C(p->desc[i],&p->pos[1]);
            func_021BC5BC((u8 *)p,p->desc[i],(const struct Vec2 *)(&p->pos[0]),func_021BF6F0(p->state,0),p->items[0][i]);
            func_021BC5BC((u8 *)p,p->desc[i],(const struct Vec2 *)(&p->pos[1]),func_021BF6F0(p->state,1),p->items[1][i]);
            break;
        case 2:
            p->count=func_021BC340(p,p->desc[i],i);
            break;
        }
        BMP_WIN_TransferChars(p->desc[i]);
    }
    func_02041B6C(0);
    func_02041B6C(4);
}
