/*
 * function: func_021D8C5C
 * address: 0x021D8C5C
 * packet: pkt_ov129_021D8C5C
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020221A4 0x020221A4 thumb
 *   func_021D9760 0x021D9760 thumb ov129
 *   func_02051C88 0x02051C88 arm
 *   func_021D8FA0 0x021D8FA0 thumb ov129
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
extern unsigned func_020221A4(void);
extern void func_021D9760(char *);
typedef signed int     s32;
struct Ctx;
extern s32 func_02051C88(struct Ctx *c);
extern void func_021D8FA0(char *);
int func_021D8C5C(char *p) {if(*(int *)(p+564)==0){if(func_020221A4()==1)*(int *)(p+564)+=1;}else {func_021D9760(p);func_02051C88(*(void **)(p+660));func_021D8FA0(p);}return 0;}
