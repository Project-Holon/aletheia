/*
 * function: NAMEIN_GRAPHIC_PickCandidate
 * address: 0x021F23FC
 * packet: pkt_ov194_021F23FC
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: read Group values through ((u16 *)((char *)&group+2))[i] to hoist its member base.
 * symbols:
 *   NAMEIN_GRAPHIC_PickTableE 0x021F4E58 thumb ov194
 *   NAMEIN_GRAPHIC_PickTable8 0x021F4E18 thumb ov194
 *   NAMEIN_GRAPHIC_FindTableIndex 0x021F4ED8 thumb ov194
 *   NAMEIN_GRAPHIC_AppendChar 0x021F2190 thumb ov194
 *   NAMEIN_GRAPHIC_Backspace 0x021F2150 thumb ov194
 *   NAMEIN_GRAPHIC_CopyTableEntries 0x021F4DDC thumb ov194
 *   NAMEIN_GRAPHIC_PickTable14 0x021F4E98 thumb ov194
 *   STRBUF_GetEosChar 0x02045A98 arm
 */
#include "../include/Obj01574.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {u8 count,pad;u16 values[4];} Group;
extern int NAMEIN_GRAPHIC_PickTableE(int,int,u16 *,int,u8 *),NAMEIN_GRAPHIC_PickTable8(int,int,u16 *,int,u8 *);
typedef unsigned int   u32;
extern u16 NAMEIN_GRAPHIC_FindTableIndex(const char *p, const u16 *b);
extern int NAMEIN_GRAPHIC_AppendChar(char *,u16),NAMEIN_GRAPHIC_Backspace(u8 *);
extern void NAMEIN_GRAPHIC_CopyTableEntries(const char *p, int i, u16 *dst, u32 n, u8 *count);
extern int NAMEIN_GRAPHIC_PickTable14(char *,int,u16 *,unsigned,u8 *);
extern u16 STRBUF_GetEosChar(void);
int NAMEIN_GRAPHIC_PickCandidate(u8 *p,int direction)
{
 Group group;
 int (*pick)(int,int,u16 *,int,u8 *);
 int i,j;
 u16 index;
 pick=direction?NAMEIN_GRAPHIC_PickTableE:NAMEIN_GRAPHIC_PickTable8;
 for(i=0;i<((struct Obj01574 *)p)->f20;i++){
  index=NAMEIN_GRAPHIC_FindTableIndex(((struct Obj01574 *)p)->f8C,(u16 *)(p+0x16+i*2));
  if(index==0xffff)continue;
  for(j=0;j<i;j++)NAMEIN_GRAPHIC_AppendChar((char *)p,*(u16 *)(p+0x16+j*2));
  for(j=0;j<i;j++)NAMEIN_GRAPHIC_Backspace(p);
  if(pick(*(int *)&((struct Obj01574 *)p)->f8C,index,group.values,4,&group.count)){
   for(i=0;i<group.count;i++)NAMEIN_GRAPHIC_AppendChar((char *)p,*((u16 *)((char *)&group+2)+i));
   NAMEIN_GRAPHIC_CopyTableEntries(((struct Obj01574 *)p)->f8C,index,group.values,4,&group.count);
   for(i=0;i<group.count;i++)NAMEIN_GRAPHIC_Backspace(p);
   NAMEIN_GRAPHIC_PickTable14(*(char * *)&((struct Obj01574 *)p)->f8C,index,group.values,4,&group.count);
   for(i=0;i<group.count;i++){
    *(u16 *)(p+0x16+((struct Obj01574 *)p)->f20*2)=*((u16 *)((char *)&group+2)+i);
    ((struct Obj01574 *)p)->f20+=1;
    *(u16 *)(p+0x16+((struct Obj01574 *)p)->f20*2)=STRBUF_GetEosChar();
   }
   return 1;
  }
 }
 return 0;
}
