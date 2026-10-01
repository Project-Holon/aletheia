/*
 * function: func_021C5A60
 * address: 0x021C5A60
 * packet: pkt_ov127_021C5A60
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: MATCH*
 * blocker: ARM9 0x0204B09C has no outside witness; Ilias owns it.
 * blocker: verified EXACT ARM leaf, 44 bytes (scratch blocker-r1.log):
 *   typedef unsigned char u8; typedef unsigned int u32; typedef signed short s16;
 *   struct Item { int x; int y; u8 pad_08[0x40]; };
 *   struct Owner { u8 pad_00[0x98]; struct Item *items; };
 *   struct Pt { s16 x; s16 y; };
 *   void sub_0204B09C(struct Owner *owner,u32 index,struct Pt *in) {
 *       int x=in->x; int y=in->y; struct Item *it=owner->items; struct Item *p;
 *       it[index].x=x<<12; p=&it[index]; p->y=y<<12;
 *   }
 * symbols:
 *   func_021C59E4 0x021C59E4 thumb ov127
 *   func_021C59EC 0x021C59EC thumb ov127
 *   func_021C5B0C 0x021C5B0C thumb ov127
 *   func_0204B09C 0x0204B09C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
extern int func_021C59E4(void *);
extern int func_021C59EC(void *);
extern void func_0204B09C(void *,int,void *);
extern void func_021C5B0C(void *,int,int);
void func_021C5A60(char *p,void *q)
{
    int y,x;
    struct { s16 x,y; } pos;
    y=func_021C59E4(q);
    x=func_021C59EC(q);
    pos.x=x;
    pos.y=y;
    if(*(int *)(p+16)==0) func_0204B09C(*(void **)p,0,&pos);
    else { pos.y+=192; func_0204B09C(*(void **)p,1,&pos); }
    func_021C5B0C(p,x,y);
}
