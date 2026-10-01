/*
 * function: func_021BA780
 * address: 0x021BA780
 * packet: pkt_ov100_021BA780
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * arity: original entry R0 is preserved at 0201DD68; that callee's full
 *   matched body ignores it. 021BA028 likewise ignores the supplied context,
 *   but the original explicitly supplies it, so the caller retains it.
 * symbols:
 *   func_0201DD68 0x0201DD68 thumb
 *   func_0201EC74 0x0201EC74 thumb
 *   func_021BA624 0x021BA624 thumb ov100
 *   func_021BA028 0x021BA028 thumb ov100
 *   func_020457B0 0x020457B0 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   func_02049990 0x02049990 arm
 *   func_02049238 0x02049238 arm
 *   func_0201F5DC 0x0201F5DC thumb
 *   func_0204E720 0x0204E720 arm
 *   func_021BA668 0x021BA668 thumb ov100
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_021BA1C8 0x021BA1C8 thumb ov100
 *   func_0201C440 0x0201C440 thumb
 *   func_02027F60 0x02027F60 thumb
 *   func_021B96EC 0x021B96EC thumb ov100
 *   func_021B974C 0x021B974C thumb ov100
 *   func_02043534 0x02043534 arm
 *   func_020435F4 0x020435F4 arm
 *   func_02049F78 0x02049F78 arm
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021BAA9C 0x021BAA9C thumb ov100
 *   d_020A1448 0x020A1448 data a4
 *   d_021BB6F0 0x021BB6F0 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u32 d_020A1448[],d_021BB6F0[];
extern void func_0201DD68(char *),func_021BA624(char *),func_021BA028(char *),func_021BA668(char *),func_021BA1C8(void),func_021BAA9C(char *),func_021B96EC(char *),func_021B974C(int,int,int,int,int),func_021B95B8(char *,u32);
extern int func_0201EC74(u32,u32,u32),func_020457B0(u32,u32),func_0201D7EC(int,int,int,int,u32),func_02045B38(u32,u32,u32,u32),func_02049740(u32,u32,u32,u32,u32,u16),func_02049990(u32,u32,u32,u32,u16,u32,u32,u16),func_0201F5DC(int,u32,u32,u32),func_0204B100(int,u8,u32),func_020056A0(u32,u32,u32),func_0201C440(u32),func_02027F60(u16,u16,u32,u32,u16);
extern void *func_020490F4(void *,u32),*func_02049F78(void *,u32,void **,u32);
extern void func_02049B68(u32,u32,u32,u32,u32,u16),func_02049238(void *),func_0204E720(u32,int,int,int),func_0204A48C(const void *,u32,u32),func_02043534(int),func_020435F4(int),func_02082D44(const void *,void *,u32),func_020307B0(void *);
void func_021BA780(char *p) {
 void *owner;
 void *raw;
 void *resource;
 int i;
 func_0201DD68(p);
 *(int *)(p+0x28c)=func_0201EC74(11,200,*(u16 *)(p+0x278));
 func_021BA624(p);func_021BA028(p);
 *(int *)(p+0x298)=func_020457B0(200,*(u16 *)(p+0x278));
 *(int *)(p+0x294)=func_020457B0(200,*(u16 *)(p+0x278));
 *(int *)(p+0x290)=func_0201D7EC(23,0,0,0,*(u16 *)(p+0x278));
 *(int *)(p+0x288)=func_02045B38(0,2,46,*(u16 *)(p+0x278));
 owner=func_020490F4((void *)28,*(u16 *)(p+0x278));
 func_02049B68((u32)owner,1,0,0,0,*(u16 *)(p+0x278));
 *(int *)(p+0x2fc)=func_02049740((u32)owner,6,0,0,0,*(u16 *)(p+0x278));
 if(*(int *)(p+0x24c)!=5) func_02049990((u32)owner,13,1,0,*(int *)(p+0x2fc),0,0,*(u16 *)(p+0x278));
 else {func_02049990((u32)owner,13,0,0,*(int *)(p+0x2fc),0,0,*(u16 *)(p+0x278));func_02049990((u32)owner,14,1,0,*(int *)(p+0x2fc),0,0,*(u16 *)(p+0x278));}
 func_02049238(owner);
 owner=func_020490F4((void *)29,*(u16 *)(p+0x278));
 func_02049B68((u32)owner,1,4,0,0,*(u16 *)(p+0x278));
 *(int *)(p+0x308)=func_02049740((u32)owner,4,4,0,0,*(u16 *)(p+0x278));
 func_02049990((u32)owner,9,4,0,*(int *)(p+0x308),0,0,*(u16 *)(p+0x278));func_02049238(owner);
 *(int *)(p+0x304)=func_0201F5DC(5,14,0,*(u16 *)(p+0x278));
 func_0204E720(3,16,0,2);func_021BA668(p);
 func_0204A48C(d_020A1448,(u32)d_021BB6F0,*(u16 *)(p+0x278));
 *(int *)(p+0x2b4)=func_0204B100(40,0,*(u16 *)(p+0x278));
 *(int *)(p+0x2b0)=func_020056A0((u32)func_021BA1C8,(u32)p,0);
 *(int *)(p+0xcb8)=func_0201C440(*(u16 *)(p+0x278));
 *(int *)(p+0xcc4)=func_02027F60(6,9,*(int *)(p+0x290),*(int *)(p+0xcb8),*(u16 *)(p+0x278));
 func_021B96EC(p);
 if(*(int *)(p+0x24c)!=5) {
  func_021B974C((int)p,57,154,2,10);func_021B974C((int)p,128,113,4,2);func_021B974C((int)p,200,38,0,11);func_021B974C((int)p,128,77,5,3);
 } else {
  func_021B974C((int)p,57,154,0,4);func_021B974C((int)p,198,154,1,5);func_021B974C((int)p,200,38,2,6);func_021B974C((int)p,55,38,3,7);func_021B974C((int)p,152,146,6,0);func_021B974C((int)p,103,146,7,1);func_021B974C((int)p,152,46,4,0);func_021B974C((int)p,103,46,5,1);
 }
 func_02043534(19);func_020435F4(23);
 *(u16 *)(p+0x242)=*(u16 *)(p+0x278);
 owner=func_020490F4((void *)28,*(u16 *)(p+0x242));
 raw=func_02049F78(owner,2,&resource,*(u16 *)(p+0x242));
 func_02082D44(*(void **)((char *)resource+12),p,0x120);
 for(i=0;i<9;i++) func_02082D44(p+(8-i)*32,p+(i+9)*32,32);
 func_020307B0(raw);func_02049238(owner);func_021B95B8(p,(u32)func_021BAA9C);
}
