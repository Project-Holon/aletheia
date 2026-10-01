/*
 * function: func_021F366C
 * address: 0x021F366C
 * packet: pkt_ov194_021F366C
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * volatile: 021F3676 and 021F3696 re-read the mode word at +0x100.
 * symbols:
 *   func_021F3358 0x021F3358 thumb ov194
 *   func_021F25F8 0x021F25F8 thumb ov194
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_021F26F0 0x021F26F0 thumb ov194
 */
extern int func_021F3358(int,int,unsigned char);extern void func_021F25F8(int *,int,void *);
extern int func_02045770(int);extern void func_02043B5C(int,unsigned);
extern void func_021F26F0(char *,void *,int,int,unsigned short);
void func_021F366C(char *p,int index,int variant) {
 int selected;
 if(*(volatile int *)(p+0x100)!=3)return;
 if(*(unsigned char *)(p+0x108)==variant && *(int *)(p+0x104)==index)return;
 selected=func_021F3358(*(volatile int *)(p+0x100),index,variant);
 func_021F25F8((int *)p,selected,*(void **)(p+0x12C));
 func_02043B5C(func_02045770(*(int *)(p+0xE0)),0);
 func_021F26F0(p,p+0xEC,*(int *)(p+0xF8),*(int *)(p+0xF4),*(unsigned short *)(p+0xFE));
 *(int *)(p+0x104)=index;*(unsigned char *)(p+0x108)=variant;
}
