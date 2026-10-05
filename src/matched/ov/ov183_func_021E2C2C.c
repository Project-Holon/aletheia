/*
 * function: func_021E2C2C
 * address: 0x021E2C2C
 * packet: pkt_ov183_021E2C2C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * 2026-10-05 (D8 lane19): re-verified, status unchanged; sole blocker is arm9 callee 0x0200B98C (no witness outside the caller). Needs a label seed. Source is byte-correct; no C change possible.
 * lever: Write the zero halfwords in source order p+0x40 then p+0x42; the reversed spelling exchanged those two store addresses.
 * blocker: ARM9 0200B98C lacks outside code-start witness at +0104. TU --suggest-split leaves caller out. Scratch B98C-one.log EXACT 172 bytes, terminal exit 0.
 * blocker-symbols: func_0200B98C_Table 0x0209DDCC data a4
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned long long u64;
 * extern const u16 func_0200B98C_Table[];
 * u64 func_0200B98C(char *p,int selector,int index) {
 *     int i;
 *     u16 v;
 *     switch(selector) {
 *     case 0: v=((u16 *)p)[index];if(v>0x289)return 0;return v;
 *     case 1: return *(u8 *)(p+index+0x18)&0x7f;
 *     case 2: v=*(u16 *)(p+0x24);if(v>0x270f)return 0x270f;return v;
 *     case 3: for(i=0;i<0x29;i++)if(*(u16 *)(p+0x26)==func_0200B98C_Table[i])return i;return 0;
 *     case 4: return *(u64 *)(p+0x38);
 *     case 5: return *(u8 *)(p+0x2a);
 *     case 6: return (*(u8 *)(p+index+0x18)&0x80)>>7;
 *     case 7: return *(u8 *)(p+0x2b);
 *     default:return 0;
 *     }
 * }
 * symbols:
 *   func_021FD12C 0x021FD12C thumb ov186
 *   func_021FD170 0x021FD170 thumb ov186
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021D7540 0x021D7540 thumb ov125
 *   func_02082BCC 0x02082BCC arm
 *   func_0200B928 0x0200B928 thumb
 *   func_0200B98C 0x0200B98C thumb
 *   func_021FF54C 0x021FF54C thumb ov186
 *   func_021FF648 0x021FF648 thumb ov186
 *   func_02035C60 0x02035C60 arm
 *   func_02035D20 0x02035D20 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021FD15C 0x021FD15C thumb ov186
 *   func_021FD744 0x021FD744 thumb ov186
 */
typedef unsigned short u16;
typedef unsigned long long u64;
typedef struct Pair {int x,y;} Pair;
typedef union Config {u64 wide;Pair pair;} Config;
extern void *func_021FD12C(int,int,u16);
extern void func_021FD170(void *,int,int),func_021FD860(int,int,Pair *),func_021FE784(int,int,int,int);
extern int func_021FE7B0(int *),func_021D7540(int,int,unsigned char,u16 *,int,u16);
extern void func_02082BCC(void *,int,unsigned);
extern void *func_0200B928(void);
extern u64 func_0200B98C(void *,int,int);
extern void func_021FF54C(char *,int,Config *);
extern int func_021FF648(char *),func_02035C60(void),func_02035D20(int *,int *);
extern void func_020061E4(int),func_021FD15C(void *,int);
extern int func_021FD744(int);
void func_021E2C2C(int task,unsigned *state,char *p)
{
    Pair initial;
    Config cfg;
    int x,y;
    Pair pair;
    int r;
    switch(*state) {
    case 0:
        if(!*(void **)(p+8)) *(void **)(p+8)=func_021FD12C(*(int *)(*(char **)(p+0x3c)+8),*(int *)(p+4),*(u16 *)(p+0x38));
        func_021FD170(*(void **)(p+8),*(int *)(*(char **)(p+0x3c)+8),0x13d);
        initial.x=0x80;initial.y=0x60;
        func_021FD860(*(int *)(p+0x30),4,&initial);
        func_021FE784(**(int **)(p+0x3c),2,3,0);++*state;break;
    case 1:if(func_021FE7B0(**(int ***)(p+0x3c))) ++*state;break;
    case 2:
        *(int *)(p+0x44)=0;
        *(u16 *)(p+0x40)=0;*(u16 *)(p+0x42)=0;
        ++*state;break;
    case 3:
        r=func_021D7540(*(int *)(*(char **)(p+0x3c)+0x14),*(int *)(p+0x10)+1,*(int *)(*(char **)(p+0x3c)+0x24),(u16 *)(p+0x40),(int)(p+0x42),*(u16 *)(p+0x38));
        if((unsigned)(r-2)<=1) {
            *(int *)(*(char **)(p+0x3c)+0x28)=1;
            *(int *)(*(char **)(p+0x3c)+0x2c)=*(int *)(p+0x10)+1;
            ++*state;
        }
        ++*(int *)(p+0x44);break;
    case 4:
        func_02082BCC(&cfg,0,8);
        cfg.wide=func_0200B98C(func_0200B928(),4,0);
        func_021FF54C(*(char **)(*(char **)(p+0x3c)+12),8,&cfg);
        func_021FD170(*(void **)(p+8),*(int *)(*(char **)(p+0x3c)+8),0x13f);
        *(int *)(p+0x48)=0;++*(int *)(p+0x44);++*state;break;
    case 5:
        ++*(unsigned *)(p+0x44);++*(unsigned *)(p+0x48);
        if(func_021FF648(*(char **)(*(char **)(p+0x3c)+12)) && *(unsigned *)(p+0x44)>0x60 && *(unsigned *)(p+0x48)>0x3c) {
            func_021FD860(*(int *)(p+0x30),0,0);
            func_021FD170(*(void **)(p+8),*(int *)(*(char **)(p+0x3c)+8),0x140);
            ++*state;
        }break;
    case 6:
        if(func_02035C60()) {
            func_02035D20(&x,&y);pair.x=x;pair.y=y;
            func_021FD860(*(int *)(p+0x34),1,&pair);
            func_020061E4(0x703);++*state;
        }break;
    case 7:func_021FE784(**(int **)(p+0x3c),2,3,1);++*state;break;
    case 8:if(func_021FE7B0(**(int ***)(p+0x3c))) ++*state;break;
    case 9:
        if(*(void **)(p+8)) {func_021FD15C(*(void **)(p+8),*(int *)(*(char **)(p+0x3c)+8));*(int *)(p+8)=0;}
        func_021FD744(task);break;
    }
}
