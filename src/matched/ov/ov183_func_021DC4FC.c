/*
 * function: func_021DC4FC
 * address: 0x021DC4FC
 * packet: pkt_ov183_021DC4FC
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05: re-run, bytes identical to the original; the only unresolved relocation is the BL to arm9 0x0200B98C (Thumb, 64 bytes, no code-start label, no asm/arm9 witness). Integrator: seed a label at 0x0200B98C; no source change needed.
 * blocker: ARM9 0200B98C lacks code-start witness; own call +00DC unresolved. TU --suggest-split leaves caller out.
 * blocker-C: prior verified Thumb EXACT from ov183_func_021DF838.c header, blocker-r2.log, dsi/1.1p1 -O4,p; table 0x0209DDCC data a4.
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
 * abi: DD0AC/DD0F4 keep the visibly loaded second descriptor argument despite body using only the first.
 * symbols:
 *   func_021DD0AC 0x021DD0AC thumb ov183
 *   func_021DD0F4 0x021DD0F4 thumb ov183
 *   func_021FD170 0x021FD170 thumb ov186
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021D7630 0x021D7630 thumb ov125
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021DBC68 0x021DBC68 thumb ov183
 *   d_021E3960 0x021E3960 data a1
 *   func_02034714 0x02034714 arm
 *   func_0200B490 0x0200B490 thumb
 *   func_0200B98C 0x0200B98C thumb
 */
typedef unsigned short u16;
extern void func_021DD0AC(char *,char *),func_021DD0F4(char *,char *);
extern void func_021FD170(void *,int,int);
extern void func_021FE784(int *,int,int,int);
extern int func_021FE7B0(int *);
extern int func_021D7630(int,int,u16 *,int,u16);
extern void func_021FD73C(int *,int);
extern void func_021DBC68(int *,int *,char *);
extern char d_021E3960[];
extern void func_02034714(void *,int,void *);
extern void func_0200B490(void);
extern long long func_0200B98C(void *,int,long);
void func_021DC4FC(int *a,int *state,char *p)
{
    switch(*state) {
    case 0:
        func_021DD0AC(p,*(char **)(p+0xd0));
        func_021FD170(*(void **)(p+0x18),*(int *)(*(char **)(p+0xd0)+0x10),0x152);
        func_021FE784(*(int **)(*(char **)(p+0xd0)+12),2,3,0);
        *state=1;break;
    case 1: if(func_021FE7B0(*(int **)(*(char **)(p+0xd0)+12))) *state=2;break;
    case 2: *state=3;break;
    case 3: *(u16 *)(p+0xb6)=0;*(u16 *)(p+0xb8)=0;*state=4;break;
    case 4:
        if(*(int *)(*(char **)(p+0xd0)+8)>3) func_02034714(d_021E3960,0,d_021E3960);
        if(func_021D7630(*(int *)(*(char **)(p+0xd0)+0x28),*(int *)(*(char **)(p+0xd0)+8),(u16 *)(p+0xb6),(int)(p+0xb8),*(u16 *)(p+0xb4))==2) {
            func_0200B490();
            *(int *)(p+0xc8)=(int)func_0200B98C(*(void **)(p+0xc4),5,0);
            *state=5;
        }
        break;
    case 5: func_021FE784(*(int **)(*(char **)(p+0xd0)+12),2,3,1);*state=6;break;
    case 6: if(func_021FE7B0(*(int **)(*(char **)(p+0xd0)+12))) *state=7;break;
    case 7: func_021DD0F4(p,*(char **)(p+0xd0));func_021FD73C(a,(int)func_021DBC68);break;
    }
}
