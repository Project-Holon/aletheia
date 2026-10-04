/*
 * function: func_021DB3C4
 * address: 0x021DB3C4
 * packet: pkt_ov183_021DB3C4
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: enum-valued one-bit mask preserves the original call/mask scheduling, as in sibling 021DB594.
 * abi: 02035C60 returns a full word consumed by the original caller's comparison.
 * symbols:
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_021FD938 0x021FD938 thumb ov186
 *   func_021FC6A4 0x021FC6A4 thumb ov186
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FC754 0x021FC754 thumb ov186
 *   func_021FE794 0x021FE794 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021FC734 0x021FC734 thumb ov186
 *   func_021FEE24 0x021FEE24 thumb ov186
 *   func_021F9BF4 0x021F9BF4 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021FC830 0x021FC830 thumb ov186
 *   func_021DB690 0x021DB690 thumb ov183
 *   func_020061E4 0x020061E4 thumb
 *   func_02035C60 0x02035C60 arm
 *   func_020409B4 0x020409B4 arm
 */
extern void func_021FD860(int,int,int *);
extern int func_021FD938(char *);
extern void *func_021FC6A4(unsigned short,unsigned,unsigned short,unsigned short,unsigned char,unsigned char,void *,unsigned short);
extern int func_021FC20C(char *),func_021FC214(char *);
extern void func_021FC754(char *,void *,void *,void *,unsigned short);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_021FE794(char *p, u32 index, u32 a, u32 b, u32 c);
extern int func_021FE7B0(int *);
extern void func_021FC734(void *);
extern void func_021FEE24(char *p);
extern int func_021FC830(u8 *p);
extern void func_021F9BF4(unsigned *,unsigned);
extern void func_021FD73C(int *,int);
extern void func_021DB690(int *task);
extern void func_020061E4(int),func_020409B4(int);
extern int func_02035C60(void);
void func_021DB3C4(int *task,int *state,char *p)
{
    int a,b;
    switch(*state) {
    case 0: {int args[2];args[0]=128;args[1]=96;func_021FD860(*(int *)(p+0x14),2,args);func_020061E4(0x700);*state=1;break;}
    case 1: if(func_021FD938(*(char **)(p+0x14)))*state=2;break;
    case 2: {int args[2];args[0]=128;args[1]=-8;func_021FD860(*(int *)(p+0x18),3,args);*state=3;break;}
    case 3: if(func_021FD938(*(char **)(p+0x18)))*state=4;break;
    case 4:
        *(void **)(p+8)=func_021FC6A4(4,8,16,16,2,14,*(void **)(p+0xc),*(unsigned short *)(p+4));
        a=func_021FC20C(*(char **)(*(char **)(p+0x1c)+0xc));
        b=func_021FC214(*(char **)(*(char **)(p+0x1c)+0xc));
        func_021FC754(*(char **)(p+8),(void *)b,(void *)228,(void *)a,0x440);
        func_021FE794((char *)(*(int *)(*(char **)(p+0x1c)+8)),3,15,1,4);*state=5;break;
    case 5: if(func_021FE7B0(*(int **)(*(char **)(p+0x1c)+8)))*state=6;break;
    case 6: func_021FE794((char *)(*(int *)(*(char **)(p+0x1c)+8)),3,15,0,4);*state=7;break;
    case 7: if(func_021FE7B0(*(int **)(*(char **)(p+0x1c)+8)))*state=8;break;
    case 8: if(func_02035C60()) {func_020061E4(0x6ff);func_021FC734(*(void **)(p+8));*(int *)(p+8)=0;func_020409B4(4);*state=9;}break;
    case 9: func_021FE794((char *)(*(int *)(*(char **)(p+0x1c)+8)),3,3,0,48);func_021FEE24((char *)(*(int *)(*(char **)(p+0x1c)+0x14)));*state=10;break;
    case 10: {enum {ONE=1} mask=ONE;if(func_021FE7B0(*(int **)(*(char **)(p+0x1c)+8))&mask) {func_021FD860(*(int *)(p+0x18),8,0);*state=11;}break;}
    case 11: func_021FE794((char *)(*(int *)(*(char **)(p+0x1c)+8)),2,3,1,1);*state=12;break;
    case 12: if(func_021FE7B0(*(int **)(*(char **)(p+0x1c)+8)))*state=13;break;
    case 13: if(func_021FD938(*(char **)(p+0x18))) {func_021F9BF4(*(unsigned **)(*(char **)(p+0x1c)+0x10),1);func_021FD73C(task,(int)func_021DB690);}break;
    }
    if(*(void **)(p+8))func_021FC830(*(void **)(p+8));
}
