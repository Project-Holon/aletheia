/*
 * function: func_021F3008
 * address: 0x021F3008
 * packet: pkt_ov194_021F3008
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: two zero alignment bytes at 021F31B6 before 31B8.
 * prototype: 256C retains fifth heap input visibly stored by caller; heap forwards use full words without caller-side truncation.
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_02049EB4 0x02049EB4 arm
 *   func_02040AE0 0x02040AE0 arm
 *   func_02040588 0x02040588 arm
 *   func_020409B4 0x020409B4 arm
 *   func_021F19A0 0x021F19A0 thumb ov194
 *   func_021F3358 0x021F3358 thumb ov194
 *   func_021F256C 0x021F256C thumb ov194
 *   func_020450F0 0x020450F0 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_021F26F0 0x021F26F0 thumb ov194
 *   func_020355C4 0x020355C4 arm
 *   func_021F2818 0x021F2818 thumb ov194
 *   func_021F1A1C 0x021F1A1C thumb ov194
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned u32;
typedef struct {int x,y,z,w;} Box;
typedef struct {int x,y;} Pair;
extern void func_02082BCC(void *,int,int);
extern void *func_02049EB4(u32,u32,u32,u32,u32);
extern void func_02040AE0(u32,const void *,u32),func_02040588(u32,u32),func_020409B4(u32);
extern void func_021F19A0(u8 *,void *,void *,u32);
extern int func_021F3358(int,int,u8);
extern void func_021F256C(char *,unsigned,int,void *,u32);
extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
extern void func_02045334(void *),func_02045374(void *);
extern u8 func_02045730(void *);
extern void func_021F26F0(char *,char *,void *,void *,u32);
extern u8 func_020355C4(void);
extern int func_021F2818(char *,Pair *,Box *);
extern void func_021F1A1C(char *,int,const Box *,int,int);
void func_021F3008(u8 *p,int mode,void *font,void *window,void *data,void *palette,u32 heap)
{
 Box box;
 void *bg;
 int index;
 func_02082BCC(p,0,0x130);
 *(int *)(p+0xd8)=0;*(int *)(p+0xdc)=0;
 *(void **)(p+0xf4)=font;*(void **)(p+0xf8)=window;*(u16 *)(p+0xfe)=heap;
 *(int *)(p+0x100)=mode;*(int *)(p+0x114)=mode;*(void **)(p+0x12c)=data;
 *(void **)(p+0x11c)=func_02049EB4(118,10,0,(u32)(p+0x124),heap);
 *(void **)(p+0x120)=func_02049EB4(118,5,0,(u32)(p+0x128),heap);
 if(mode==3){func_02040AE0(1,*(char **)(p+0x124)+12,2048);func_02040588(2,0);}
 else {func_02040AE0(1,*(char **)(p+0x128)+12,2048);func_02040588(2,1);}
 func_020409B4(1);
 func_021F19A0(p+0x24,(void *)mode,palette,heap);
 index=func_021F3358(*(int *)(p+0x100),*(int *)(p+0x104),p[0x108]);
 func_021F256C((char *)p,mode,index,*(void **)(p+0x12c),heap);
 bg=(void *)func_020450F0(3,3,5,26,15,15,1);
 *(void **)(p+0xe0)=bg;
 func_02045334(bg);func_02045374(bg);func_020409B4(func_02045730(bg));
 *(void **)(p+0xec)=*(void **)(p+0xe0);p[0xf0]=0;
 func_021F26F0((char *)p,(char *)p+0xec,window,font,heap);
 if(func_020355C4()==0){
  if(func_021F2818((char *)p,(Pair *)(p+0xd8),&box))func_021F1A1C((char *)p+0x24,1,&box,*(int *)(p+0x104),*(int *)(p+0x100));
 }else {
  if(func_021F2818((char *)p,(Pair *)(p+0xd8),&box))func_021F1A1C((char *)p+0x24,0,&box,*(int *)(p+0x104),*(int *)(p+0x100));
 }
}
