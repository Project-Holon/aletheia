/*
 * function: func_021DB940
 * address: 0x021DB940
 * packet: pkt_ov183_021DB940
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note 2026-10-05: re-run, bytes identical to the original; the only unresolved relocation is the BL to arm9 0x0200B98C (Thumb, 64 bytes, no code-start label, no asm/arm9 witness). Integrator: seed a label at 0x0200B98C; no source change needed.
 * lever: shared state-flag store and distinct case-5 null path preserve the original switch layout.
 * blocker: ARM9 0200B98C lacks outside code-start witness, call +014E wildcard; TU --suggest-split leaves caller out.
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
 *   func_021F9B9C 0x021F9B9C thumb ov186
 *   func_021FD6D8 0x021FD6D8 thumb ov186
 *   func_021FD760 0x021FD760 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021DBFB0 0x021DBFB0 thumb ov183
 *   func_021DC4FC 0x021DC4FC thumb ov183
 *   func_021DBC68 0x021DBC68 thumb ov183
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02025538 0x02025538 thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_0200B928 0x0200B928 thumb
 *   func_0200B910 0x0200B910 thumb
 *   func_0200B98C 0x0200B98C thumb
 */
typedef unsigned int u32;
extern unsigned func_021F9B9C(char *);
extern char *func_0203159C(int *,unsigned,unsigned);
extern void func_02082BCC(void *,int,unsigned);
extern void *func_02025538(unsigned,void *),*func_0201C440(unsigned);
extern void *func_021FD6D8(void *,void *,unsigned);
extern char *func_021FD760(unsigned,char *,int,int);
extern void func_021FD73C(int *,int);
extern void func_021DBFB0(void),func_021DC4FC(void),func_021DBC68(void);
extern char *func_0200B928(void),*func_0200B910(void);
extern unsigned long long func_0200B98C(void *,int,int);
int func_021DB940(int *task,int *state,char *q)
{
    char *p,*s;
    int i;
    p=func_0203159C(task,0xe8,func_021F9B9C(*(char **)(q+0x14)));
    func_02082BCC(p,0,0xe8);
    *(unsigned short *)(p+0xb4)=func_021F9B9C(*(char **)(q+0x14));
    *(int *)(p+0xb0)=0;
    *(char **)(p+0xd0)=q;
    *(void **)p=func_02025538(*(unsigned short *)(p+0xb4),*(void **)(q+0x18));
    *(void **)(p+4)=func_0201C440(*(unsigned short *)(p+0xb4));
    *(void **)(p+8)=func_021FD6D8(p,0,*(unsigned short *)(p+0xb4));
    for(i=0;i<2;i++) *(char **)(p+i*4+0xc)=func_021FD760(*(unsigned *)(q+0x18),*(char **)(q+0x10),i,*(unsigned short *)(p+0xb4));
    switch(*(int *)(*(char **)(p+0xd0)+8)) {
    case 4:
        s=*(char **)(*(char **)(p+0xd0)+0x30);
        *(char **)(p+0xc4)=s+*(int *)(s+0x171c)*0xc4+0x80;
        s=*(char **)(*(char **)(p+0xd0)+0x30);
        *(char **)(p+0xc0)=s+*(int *)(s+0x171c)*0xc4;
        *(int *)(p+0xcc)=1;
        if(**(int **)(*(char **)(p+0xd0)+0x3c) && *(int *)(*(char **)(p+0xd0)+0x34)) {
            s=*(char **)(*(char **)(p+0xd0)+0x30);
            *(s+*(int *)(s+0x171c)+0x16f8)=1;
        }
        s=*(char **)(*(char **)(p+0xd0)+0x30);
        *(int *)(p+0xc8)=*(unsigned char *)(s+*(int *)(s+0x171c)+0x16f8);
        break;
    case 0:
        *(char **)(p+0xc4)=func_0200B928();*(char **)(p+0xc0)=func_0200B910();
        *(int *)(p+0xc8)=1;i=0;goto set_cc;
    case 1: case 2: case 3:
        *(char **)(p+0xc4)=func_0200B928();*(char **)(p+0xc0)=func_0200B910();
        *(int *)(p+0xc8)=func_0200B98C(*(void **)(p+0xc4),5,0);*(int *)(p+0xcc)=0;break;
    case 5:
        if(*(int *)(*(char **)(p+0xd0)+0x34)==0) {
            *(int *)(p+0xc4)=0;*(int *)(p+0xc0)=0;
        }else {
            *(char **)(p+0xc4)=func_0200B928();*(char **)(p+0xc0)=func_0200B910();
            *(int *)(p+0xc8)=**(int **)(*(char **)(p+0xd0)+0x3c);
        }
        i=1;
    set_cc:
        *(int *)(p+0xcc)=i;
        break;
    }
    if(*(int *)(*(char **)(p+0xd0)+8)==5) {
        if(*(int *)(*(char **)(p+0xd0)+0x34)==0)func_021FD73C(*(int **)(p+8),(int)func_021DBFB0);
        else func_021FD73C(*(int **)(p+8),(int)func_021DBC68);
    }else if((u32)(*(int *)(*(char **)(p+0xd0)+8)-1)<=2 && *(int *)(*(char **)(p+0xd0)+0x34) && **(int **)(*(char **)(p+0xd0)+0x3c) && *(int *)(p+0xc8)==0) {
        func_021FD73C(*(int **)(p+8),(int)func_021DC4FC);
    }else func_021FD73C(*(int **)(p+8),(int)func_021DBC68);
    return 1;
}
