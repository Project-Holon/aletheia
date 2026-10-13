/*
 * function: func_021E51A4
 * address: 0x021E51A4
 * packet: pkt_ov119_021E51A4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: pos precedes the integer locals; a typed return-base temporary
 * keeps the row/column byte offsets spilled instead of reusing r7.
 * initialization: the only ov119 calls are D9EEC and D9F5C. D9F24
 * passes p+f80 as outA; D9EBC forwards outA from its only caller DA3BC,
 * where r1=p+f98. Thus all reachable hit paths enter the outA block
 * before reading slot through outSlot. No default value is invented.
 * 0204B454 writes both coordinate halfwords through 0204B53C and then
 * subtracts the origin, itself written through 0204CF74/0204B0C8.
 * symbols:
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   func_021D8AF4 0x021D8AF4 thumb ov119
 *   func_021D8B0C 0x021D8B0C thumb ov119
 */
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct Pt {s16 x,y;} Pt;
typedef struct Object {u8 pad[0xac0];void *actors[12][5];} Object;
struct Actor;
struct PtS;
typedef unsigned short u16;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
extern int func_021D8AF4(int,char *),func_021D8B0C(int,int);
int func_021E51A4(char *p,int x,int y,int *outA,int *outB,int *outSlot,int *outColumn,int *outRow)
{
 Pt pos;
 int column,slot,row;
 Object *tmp;
 for(row=0;row<12;row++) {
  for(column=0;column<5;column++) {
   CLACT_GetActorSurfacePos((struct Actor *)((Object *)p)->actors[row][column],(struct PtS *)&pos,1);
   if(pos.x<=x && x<pos.x+24 && pos.y<=y && y<pos.y+24) {
    if(outA) {
     slot=*(u8 *)(p+0xd90+row*5+column);
     if(slot==255)return 0;
     if(func_021D8B0C(slot,column)!=-1) {
      *outA=func_021D8AF4(slot,p);
      *outB=func_021D8B0C(slot,column);
     } else return 0;
    }
    if(outSlot) {*outSlot=slot;*outColumn=column;*outRow=row;}
    tmp=(Object *)p;
    return (int)tmp->actors[row][column];
   }
  }
 }
 return 0;
}
