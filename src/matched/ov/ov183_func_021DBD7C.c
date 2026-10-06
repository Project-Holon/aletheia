/*
 * function: func_021DBD7C
 * address: 0x021DBD7C
 * packet: pkt_ov183_021DBD7C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note 2026-10-05: re-run, bytes identical to the original; the only unresolved relocation is the BL to arm9 0x0200B98C (Thumb, 64 bytes, no code-start label, no asm/arm9 witness). Integrator: seed a label at 0x0200B98C; no source change needed.
 * lever: decode each callback literal from its actual PC-relative pool slot; repeated shared loads obscure distinct callback targets.
 * blocker: ARM9 0200B98C lacks outside code-start witness, call +00B6 wildcard; TU --suggest-split leaves caller out.
 * blocker-C: copied prior verified Thumb EXACT from ov183_func_021DF838.c header, blocker-r2.log; table 0x0209DDCC data a4.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned long long u64;
 * extern const u16 func_0200B98C_Table[];
 * u64 func_0200B98C(char *p,int selector,int index) {
 *   int i;u16 v;
 *   switch(selector) {
 *   case 0: v=((u16 *)p)[index];if(v>0x289)return 0;return v;
 *   case 1: return *(u8 *)(p+index+0x18)&0x7f;
 *   case 2: v=*(u16 *)(p+0x24);if(v>0x270f)return 0x270f;return v;
 *   case 3: for(i=0;i<0x29;i++)if(*(u16 *)(p+0x26)==func_0200B98C_Table[i])return i;return 0;
 *   case 4: return *(u64 *)(p+0x38);
 *   case 5: return *(u8 *)(p+0x2a);
 *   case 6: return (*(u8 *)(p+index+0x18)&0x80)>>7;
 *   case 7: return *(u8 *)(p+0x2b);
 *   default:return 0;
 *   }
 * }
 * symbols:
 *   func_02035D20 0x02035D20 arm
 *   func_021DD27C 0x021DD27C thumb ov183
 *   func_021DD2BC 0x021DD2BC thumb ov183
 *   func_021FB4B4 0x021FB4B4 thumb ov186
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_021F9BA0 0x021F9BA0 thumb ov186
 *   func_021F9BF4 0x021F9BF4 thumb ov186
 *   func_021F9C50 0x021F9C50 thumb ov186
 *   func_0200B98C 0x0200B98C thumb
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021DBEB0 0x021DBEB0 thumb ov183
 *   func_021DBCF4 0x021DBCF4 thumb ov183
 *   func_021DC228 0x021DC228 thumb ov183
 *   func_021DC638 0x021DC638 thumb ov183
 */
typedef unsigned int u32;
typedef unsigned long long u64;
typedef struct {char pad[0x4c];char saved[0x18];int count;void *ptr;} S;
extern u32 func_02035D20(u32 *,u32 *);
extern int func_021DD27C(char *,int,int),func_021DD2BC(char *,int,int);
extern int func_021FB4B4(int,int,int);
extern void func_021FD860(int,int,int *);
typedef unsigned char  u8;
extern void func_021F9BA0(unsigned *ctx);
extern void func_021F9BF4(unsigned *,unsigned);
extern void func_021F9C50(S *);
extern unsigned long long func_0200B98C(u8 *p, int selector, int index);
extern void func_021FD73C(int *,int);
extern void func_021DBEB0(int *task, int *state, char *p);
extern void func_021DBCF4(int *task, int *state, char *p);
extern void func_021DC228(int *a, int *state, char *p);
extern void func_021DC638(int *a, int *state, char *p);
void func_021DBD7C(int *task,int *state,char *p)
{
    u32 x,y;
    if(func_02035D20(&x,&y)) {
        if(func_021DD27C(p,x,y)) {
            *(int *)(p+0xb0)^=1;
            func_021FD73C(task,(int)func_021DBEB0);
        }
        if(func_021FB4B4(*(int *)(p+0x1c),x,y)) {
            int args[2];
            args[0]=x;args[1]=y;
            func_021FD860(*(int *)(p+0x10),1,args);
            **(int **)(p+0xd0)=0;
            func_021F9BA0(*(void **)(*(char **)(p+0xd0)+0x14));
            func_021FD73C(task,(int)func_021DBCF4);
        }
        if(*(int *)(p+0x20) && func_021FB4B4(*(int *)(p+0x20),x,y)) {
            int args[2];
            args[0]=x;args[1]=y;
            func_021FD860(*(int *)(p+0x10),1,args);
            func_021F9BF4(*(unsigned **)(*(char **)(p+0xd0)+0x14),10);
            *(u64 *)(*(char **)(p+0xd0)+0x1c)=func_0200B98C(*(void **)(p+0xc4),4,0);
            func_021FD73C(task,(int)func_021DBCF4);
        }
        if(func_021DD2BC(p,x,y)) {
            if((u32)(*(u32 *)(*(char **)(p+0xd0)+8)-4)<=1)func_021FD73C(task,(int)func_021DC228);
            else if(*(int *)(p+0xc8)==0)func_021FD73C(task,(int)func_021DC638);
            else {
                **(int **)(p+0xd0)=1;
                func_021F9C50(*(S **)(*(char **)(p+0xd0)+0x14));
                func_021FD73C(task,(int)func_021DBCF4);
            }
        }
    }
}
