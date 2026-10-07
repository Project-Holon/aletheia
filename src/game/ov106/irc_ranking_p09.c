/*
 * file:     irc_ranking_p09.c
 * unit:     yes
 * function: func_021B9198, func_021B91A8
 * address:  0x021B9198
 * region:   ov106
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02045738 0x02045738 arm
 *   func_02045740 0x02045740 arm
 *   func_02045770 0x02045770 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045808 0x02045808 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201D42C 0x0201D42C thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201F02C 0x0201F02C thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201ED04 0x0201ED04 thumb
 */
struct Descriptor;
struct StrObj;
struct WordSet;
struct U16Vec;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16;

extern u8 func_02045738(struct Descriptor *);
extern u8 func_02045740(struct Descriptor *);
extern void *func_02045770(struct Descriptor *);
extern struct U16Vec *func_020457B0(u32,u32);
extern void func_02045808(struct U16Vec *);
extern u32 func_0201D304(struct StrObj *,u32,u32);
extern u32 func_0201D42C(struct StrObj *,void *);
extern void func_0201C7A4(void *,s16,s16,void *,void *);
extern struct WordSet *func_0201EC64(u32);
extern void func_0201F02C(struct WordSet *,u32,void *);
extern void func_0201F250(struct WordSet *,void *,void *);
extern u32 func_0201ED04(struct WordSet *p);
int func_021B9198(int *p);
void func_021B91A8(struct Descriptor *desc,struct StrObj *text,void *value,u32 font);

/*
 * trailing: two-byte alignment padding, no follower.
 */
int func_021B9198(int *p) { if(p[2]) return 1; else return 0; }

void func_021B91A8(struct Descriptor *desc,struct StrObj *text,void *value,u32 font) {
 u16 x,y; struct WordSet *set; struct U16Vec *expanded;
 if(!value) {
  x=func_02045738(desc)*4;
  y=func_02045740(desc)*4;
  x-=(u16)(func_0201D304(text,font,0)>>1);
  y-=(u16)(func_0201D42C(text,(void *)font)>>1);
  func_0201C7A4(func_02045770(desc),(s16)x,(s16)y,text,(void *)font);
 } else {
  set=func_0201EC64(0x8043);
  expanded=func_020457B0(128,0x8043);
  func_0201F02C(set,0,value);
  func_0201F250(set,expanded,text);
  x=func_02045738(desc)*4;
  y=func_02045740(desc)*4;
  x-=(u16)(func_0201D304((struct StrObj *)expanded,font,0)>>1);
  y-=(u16)(func_0201D42C((struct StrObj *)expanded,(void *)font)>>1);
  func_0201C7A4(func_02045770(desc),(s16)x,(s16)y,expanded,(void *)font);
  func_02045808(expanded);
  func_0201ED04(set);
 }
}
