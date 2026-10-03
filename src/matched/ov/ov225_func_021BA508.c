/*
 * function: func_021BA508
 * address: 0x021BA508
 * packet: pkt_ov225_021BA508
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_0203633C 0x0203633C arm
 *   func_020355D8 0x020355D8 arm
 *   func_02035D20 0x02035D20 arm
 *   func_0204B878 0x0204B878 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_0204B98C 0x0204B98C arm
 *   d_021BBF14 0x021BBF14 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj; struct Actor;
struct Entry { u32 first; u16 normal,pad6; u8 left,right,top,bottom; u32 active,mask,sound,last; };
extern const struct Entry d_021BBF14[];
extern u32 func_0204B3F4(struct Obj *);
extern u32 func_0203633C(void);
extern void func_020355D8(u8);
extern u32 func_02035D20(u32 *,u32 *);
extern void func_0204B878(struct Obj *,u16);
extern void func_020061E4(u32);
extern u32 func_0204B98C(struct Actor *);
void func_021BA508(char *p)
{
 u8 i;
 u32 found,x,y;
 const struct Entry *row;
 switch(*(u32 *)(p+0x44)) {
 case 0:
  found=0;
  for(i=0;i<2;i++) {
   if(func_0204B3F4(*(struct Obj **)(p+i*4+0x38))) {
    row=&d_021BBF14[i];
    if(func_0203633C()&row->mask) {
     *(u8 *)(p+0x40)=i;
     func_020355D8(0);
     found=1;
     break;
    }
    if(func_02035D20(&x,&y)) {
     if(row->left<=x && x<=row->right && row->top<=y && y<=row->bottom) {
      *(u8 *)(p+0x40)=i;
      found=1;
      func_020355D8(1);
      break;
     }
    }
   }
  }
  if(found) {
   func_0204B878(*(struct Obj **)(p+*(u8 *)(p+0x40)*4+0x38),d_021BBF14[*(u8 *)(p+0x40)].active);
   if(d_021BBF14[*(u8 *)(p+0x40)].sound) func_020061E4(d_021BBF14[*(u8 *)(p+0x40)].sound);
   *(u32 *)(p+0x44)=1;
  }
  break;
 case 1: *(u32 *)(p+0x44)=2; break;
 case 2:
  if(!func_0204B98C(*(struct Actor **)(p+*(u8 *)(p+0x40)*4+0x38))) {
   func_0204B878(*(struct Obj **)(p+*(u8 *)(p+0x40)*4+0x38),d_021BBF14[*(u8 *)(p+0x40)].normal);
   *(u32 *)(p+0x44)=3;
  }
  break;
 case 3: *(u32 *)(p+0x44)=0; *(u8 *)(p+0x40)=255; break;
 }
}
