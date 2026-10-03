/*
 * function: func_021B9FD8,func_021BA0AC
 * unit: yes
 * address: 0x021B9FD8
 * packet: pkt_ov218_021B9FD8
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: the task-state call merges a ternary int argument; a narrow prototype emitted an extra truncation pair despite the callee storing a halfword.
 * function_starts: 0x021BA0AC (four-byte return-one follower)
 * ov067 tokens follow same-overlay A138's task-state interface and 9890's 63D0 target.
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   func_021B7AB0 0x021B7AB0 thumb ov067
 *   func_021B93A4 0x021B93A4 thumb ov067
 *   func_021B93B0 0x021B93B0 thumb ov067
 *   func_021B9280 0x021B9280 thumb ov067
 *   func_020061E4 0x020061E4 thumb
 *   func_021B61F8 0x021B61F8 thumb ov067
 *   func_021B9890 0x021B9890 thumb ov218
 *   func_021B6448 0x021B6448 thumb ov067
 *   func_021B9F98 0x021B9F98 thumb ov218
 */
typedef unsigned int u32;
extern u32 func_020362DC(void);
extern int func_021B7AB0(void *),func_021B93A4(char *),func_021B93B0(char *);
extern void func_021B9280(void *,unsigned short,u32);
extern void func_020061E4(u32);
extern void func_021B61F8(unsigned char *,int);
extern void func_021B9890(void *);
extern int func_021B6448(unsigned char *);
extern void func_021B9F98(int *,int);
int func_021B9FD8(unsigned char *task,char *p)
{
    int active=0;
    int selected;
    *(u32 *)(p+0x32c)=0;
    if(func_020362DC()&0x200)active=1;
    else if(func_020362DC()&0x100)active=1;
    if(active) *(u32 *)(p+0x32c)=1;
    if((u32)func_021B7AB0(*(void **)(p+0x2c))<4){
        selected=func_021B93A4(*(char **)(p+0x2c));
        if(*(u32 *)((u32)p+0x34+(u32)selected*4)==1){
            *(int *)(p+0x30)=selected;
            func_021B9280(*(void **)(p+0x2c),func_021B93B0(*(char **)(p+0x2c)),3);
            func_020061E4(1356);
            func_021B61F8(task,**(unsigned char **)(p+0x20)==131-selected ? 2 : 1);
            return 1;
        }
    }
    func_021B9890(*(void **)(p+8));
    switch(func_021B6448(*(unsigned char **)(p+8))){
    case -1:case 0:case 2:case 3:case 4:case 5:break;
    case 1:
        func_021B9F98((int *)p,1);
        func_021B61F8(task,65534);
        return 1;
    }
    return 0;
}
int func_021BA0AC(void) { return 1; }
