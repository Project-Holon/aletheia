/*
 * function: func_021F35A8
 * address: 0x021F35A8
 * packet: pkt_ov194_021F35A8
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021F2608 0x021F2608 thumb ov194
 *   func_021F3358 0x021F3358 thumb ov194
 *   func_021F256C 0x021F256C thumb ov194
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_021F26F0 0x021F26F0 thumb ov194
 *   func_02040AE0 0x02040AE0 arm
 *   func_02040588 0x02040588 arm
 *   func_020409B4 0x020409B4 arm
 *   func_021F2884 0x021F2884 thumb ov194
 */
typedef unsigned int   u32;
extern void func_021F2608(void *p);
extern u32 func_021F3358(u32 a, u32 b, u32 c);
extern void func_021F256C(char *,unsigned,int,void *,unsigned short);
struct Descriptor;
extern void *func_02045770(struct Descriptor *);extern void func_02043B5C(int,unsigned);
extern void func_021F26F0(char *,void *,int,int,unsigned short);
extern void func_02040AE0(unsigned,const void *,unsigned);extern void func_02040588(unsigned,unsigned);extern void func_020409B4(unsigned);
extern void func_021F2884(int *,int,int);
void func_021F35A8(char *p,int mode) {
 int index;
 if(*(int *)(p+0x100)==mode)return;
 func_021F2608(p);
 index=func_021F3358(mode,*(int *)(p+0x104),*(unsigned char *)(p+0x108));
 func_021F256C(p,mode,index,*(void **)(p+0x12C),*(unsigned short *)(p+0xFE));
 func_02043B5C((int)func_02045770((struct Descriptor *)*(int *)(p+0xE0)),0);
 func_021F26F0(p,p+0xEC,*(int *)(p+0xF8),*(int *)(p+0xF4),*(unsigned short *)(p+0xFE));
 if(mode==3) {func_02040AE0(1,*(char **)(p+0x124)+12,2048);func_02040588(2,0);}
 else func_02040AE0(1,*(char **)(p+0x128)+12,2048);
 func_020409B4(1);
 if(mode==3 || *(int *)(p+0x100)==3)func_021F2884((int *)(p+0xD8),*(int *)(p+0x100),mode);
 *(int *)(p+0x100)=mode;
}
