/*
 * function: func_021F23FC
 * address: 0x021F23FC
 * packet: pkt_ov194_021F23FC
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: read Group values through ((u16 *)((char *)&group+2))[i] to hoist its member base.
 * symbols:
 *   func_021F4E58 0x021F4E58 thumb ov194
 *   func_021F4E18 0x021F4E18 thumb ov194
 *   func_021F4ED8 0x021F4ED8 thumb ov194
 *   func_021F2190 0x021F2190 thumb ov194
 *   func_021F2150 0x021F2150 thumb ov194
 *   func_021F4DDC 0x021F4DDC thumb ov194
 *   func_021F4E98 0x021F4E98 thumb ov194
 *   func_02045A98 0x02045A98 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {u8 count,pad;u16 values[4];} Group;
extern int func_021F4E58(int,int,u16 *,int,u8 *),func_021F4E18(int,int,u16 *,int,u8 *);
extern u16 func_021F4ED8(void *,u16 *);
extern int func_021F2190(char *,u16),func_021F2150(u8 *);
extern void func_021F4DDC(void *,u16,u16 *,int,u8 *);
extern int func_021F4E98(char *,int,u16 *,unsigned,u8 *);
extern u16 func_02045A98(void);
int func_021F23FC(u8 *p,int direction)
{
 Group group;
 int (*pick)(int,int,u16 *,int,u8 *);
 int i,j;
 u16 index;
 pick=direction?func_021F4E58:func_021F4E18;
 for(i=0;i<*(u16 *)(p+0x20);i++){
  index=func_021F4ED8(*(void **)(p+0x8c),(u16 *)(p+0x16+i*2));
  if(index==0xffff)continue;
  for(j=0;j<i;j++)func_021F2190((char *)p,*(u16 *)(p+0x16+j*2));
  for(j=0;j<i;j++)func_021F2150(p);
  if(pick(*(int *)(p+0x8c),index,group.values,4,&group.count)){
   for(i=0;i<group.count;i++)func_021F2190((char *)p,*((u16 *)((char *)&group+2)+i));
   func_021F4DDC(*(void **)(p+0x8c),index,group.values,4,&group.count);
   for(i=0;i<group.count;i++)func_021F2150(p);
   func_021F4E98(*(char **)(p+0x8c),index,group.values,4,&group.count);
   for(i=0;i<group.count;i++){
    *(u16 *)(p+0x16+*(u16 *)(p+0x20)*2)=*((u16 *)((char *)&group+2)+i);
    *(u16 *)(p+0x20)+=1;
    *(u16 *)(p+0x16+*(u16 *)(p+0x20)*2)=func_02045A98();
   }
   return 1;
  }
 }
 return 0;
}
