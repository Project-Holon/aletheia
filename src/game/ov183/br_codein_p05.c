/*
 * file:     br_codein_p05.c
 * unit:     yes
 * function: func_021DBFB0, func_021DC228, func_021DC4FC
 * address:  0x021DBFB0
 * region:   ov183
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021DCEE4 0x021DCEE4 thumb ov183
 *   func_021DC8EC 0x021DC8EC thumb ov183
 *   func_021DD0AC 0x021DD0AC thumb ov183
 *   func_021DD0F4 0x021DD0F4 thumb ov183
 *   func_021FD170 0x021FD170 thumb ov186
 *   func_02082BCC 0x02082BCC arm
 *   func_021FF54C 0x021FF54C thumb ov186
 *   func_021FF648 0x021FF648 thumb ov186
 *   func_021FF72C 0x021FF72C thumb ov186
 *   func_021FF698 0x021FF698 thumb ov186
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_02035C60 0x02035C60 arm
 *   func_02035D20 0x02035D20 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021FD744 0x021FD744 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021F9BA0 0x021F9BA0 thumb ov186
 *   func_021DBD7C 0x021DBD7C thumb ov183
 *   func_021DCE28 0x021DCE28 thumb ov183
 *   func_021DCE48 0x021DCE48 thumb ov183
 *   func_021DD054 0x021DD054 thumb ov183
 *   func_0200B98C 0x0200B98C thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200B938 0x0200B938 thumb
 *   func_021F9C50 0x021F9C50 thumb ov186
 *   func_02006254 0x02006254 thumb
 *   func_021DBC68 0x021DBC68 thumb ov183
 *   func_021D7630 0x021D7630 thumb ov125
 *   d_021E3960 0x021E3960 data a1
 *   func_02034714 0x02034714 arm
 *   func_0200B490 0x0200B490 thumb
 */
struct Big;
typedef unsigned int u32;

typedef unsigned long long u64;

typedef struct S S;

typedef unsigned char  u8;

typedef unsigned short u16;

extern void func_021FE784(int a, int b, int c, int d);
extern int func_021FE7B0(int *);
extern void func_021DCEE4(char *,char *),func_021DC8EC(char *,char *);
extern void func_021DD0AC(char *,char *),func_021DD0F4(char *,char *);
extern void func_021FD170(char *p, char *q, void *text);
extern void func_02082BCC(void *,int,u32);
extern void func_021FF54C(char *p, int kind, const int *values);
extern int func_021FF648(char *p);
extern int func_021FF72C(char *p, int *out);
extern int func_021FF698(char *,int,int *);
extern void func_021FD860(int,int,int *);
extern void func_021F9BA0(unsigned *ctx);
extern int func_02035C60(void);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern void func_020061E4(u32 a);
extern int func_021FD744(int *a);
extern int *func_021FD73C(int *p, int v);
extern void func_021DBD7C(int *,int *,char *);
extern void func_021DCE28(char *,char *),func_021DCE48(char *,char *),func_021DD054(char *,char *);
extern unsigned long long func_0200B98C(u8 *p, int selector, int index);
extern void *func_02012EBC(struct Big *p);
extern void func_0200B938(const void *,const void *,const void *,unsigned int);
extern void func_021F9C50(S *);
extern int func_02006254(u32 a);
extern void func_021DBC68(int a, int b, char *p);
extern int func_021D7630(void *a, int x, u16 *state, u16 *b, u16 c);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_0200B490(void);
void func_021DBFB0(int *a,int *state,char *p);
void func_021DC228(int *a,int *state,char *p);
void func_021DC4FC(int *a,int *state,char *p);
extern char d_021E3960[];

/*
 * note 2026-10-05: shape copied from matched twin ov183_func_021DC228.c (same state machine, same callees). v1 was 4 bytes off (stack slots of source and index swapped); declaring source before index fixed it. Older draft docs/notes/pkt_ov183_021DBFB0.c.txt (167 B off) superseded.
 */
void func_021DBFB0(int *a,int *state,char *p)
{
    u64 t;
    int message;
    char *source;
    int index;
    u32 x,y;
    int args[2];
    switch(*state) {
    case 0:
        func_021DD0AC(p,*(char **)(p+0xd0));
        func_021FD170(*(void **)(p+0x18),(char *)(*(int *)(*(char **)(p+0xd0)+0x10)),(void *)0x14b);*state=1;break;
    case 1: func_021FE784((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,0);*state=2;break;
    case 2: if(func_021FE7B0(*(int **)(*(char **)(p+0xd0)+12))) *state=3;break;
    case 3:
        func_02082BCC(&t,0,8);
        t=*(u64 *)(*(char **)(p+0xd0)+0x1c);
        func_021FF54C(*(void **)(*(char **)(p+0xd0)+0x24),3,(const int *)(&t));
        *(int *)(p+0xbc)=0;*state=4;break;
    case 4:
        ++*(int *)(p+0xbc);
        if(func_021FF648(*(void **)(*(char **)(p+0xd0)+0x24)) && *(u32 *)(p+0xbc)>96) {
            func_021FD860(*(int *)(p+12),0,0);*state=5;
        }
        break;
    case 5:
        if(!func_021FF72C(*(void **)(*(char **)(p+0xd0)+0x24),&message)) {
            if(func_021FF698(*(char **)(*(char **)(p+0xd0)+0x24),(int)&source,&index)) {
                *(char **)(p+0xc0)=source;
                *(char **)(p+0xc4)=source+0x80;*state=6;
            } else {
                func_021FD170(*(void **)(p+0x18),(char *)(*(int *)(*(char **)(p+0xd0)+0x10)),(void *)0x114);*state=11;
            }
        } else {
            func_021FD170(*(void **)(p+0x18),(char *)(*(int *)(*(char **)(p+0xd0)+0x10)),(void *)message);*state=11;
        }
        break;
    case 11:
        if(func_02035C60()) {
            func_02035D20(&x,&y);args[0]=x;args[1]=y;
            func_021FD860(*(int *)(p+0x10),1,args);func_020061E4(0x703);
            func_021F9BA0((unsigned int *)(*(S **)(*(char **)(p+0xd0)+0x14)));*state=12;
        }
        break;
    case 6: func_021FE784((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,1);*state=7;break;
    case 7:
        if(func_021FE7B0(*(int **)(*(char **)(p+0xd0)+12))) {
            func_021DD0F4(p,*(char **)(p+0xd0));
            func_021DCEE4(p,*(char **)(p+0xd0));
            func_021DC8EC(p,*(char **)(p+0xd0));*state=8;
        }
        break;
    case 8: func_021FE784((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,0);*state=9;break;
    case 9: if(func_021FE7B0(*(int **)(*(char **)(p+0xd0)+12))) *state=10;break;
    case 10: func_021FD73C(a,(int)func_021DBD7C);break;
    case 12: func_021FE784((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,1);*state=13;break;
    case 13: if(func_021FE7B0(*(int **)(*(char **)(p+0xd0)+12))) *state=14;break;
    case 14: func_021DD0F4(p,*(char **)(p+0xd0));func_021FD744((int *)a);break;
    }
}

/*
 * note 2026-10-05: re-run, bytes identical to the original; the only unresolved relocation is the BL to arm9 0x0200B98C (Thumb, 64 bytes, no code-start label, no asm/arm9 witness). Integrator: seed a label at 0x0200B98C; no source change needed.
 * diagnostic: ov186 0x021FF648 +013C resolved through a sibling's new shard in the TU; only ARM9 remains. TU --suggest-split leaves caller out.
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
 * abi: B938 retains caller-loaded r3; DD0AC/DD0F4 retain caller-loaded r1; 35C60 return is consumed.
 */
void func_021DC228(int *a,int *state,char *p)
{
    u64 t;
    int message;
    int index;
    char *source;
    u32 x,y;
    int args[2];
    switch(*state) {
    case 0: func_021FE784((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,1);*state=1;break;
    case 1: if(func_021FE7B0(*(int **)(*(char **)(p+0xd0)+12))) *state=2;break;
    case 2:
        if(*(int *)(p+0xb0)) func_021DCE28(p,*(char **)(p+0xd0));
        else func_021DCE48(p,*(char **)(p+0xd0));
        func_021DD054(p,*(char **)(p+0xd0));
        func_021DD0AC(p,*(char **)(p+0xd0));
        func_021FD170(*(void **)(p+0x18),(char *)(*(int *)(*(char **)(p+0xd0)+0x10)),(void *)0x14b);
        *state=3;break;
    case 3: func_021FE784((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,0);*state=4;break;
    case 4: if(func_021FE7B0(*(int **)(*(char **)(p+0xd0)+12))) *state=5;break;
    case 5:
        func_02082BCC(&t,0,8);
        t=func_0200B98C(*(void **)(p+0xc4),4,0);
        func_021FF54C(*(void **)(*(char **)(p+0xd0)+0x24),3,(const int *)(&t));
        *(int *)(p+0xbc)=0;*state=6;break;
    case 6:
        ++*(int *)(p+0xbc);
        if(func_021FF648(*(void **)(*(char **)(p+0xd0)+0x24)) && *(u32 *)(p+0xbc)>96) {
            func_021FD860(*(int *)(p+12),0,0);*state=7;
        }
        break;
    case 7:
        if(!func_021FF72C(*(void **)(*(char **)(p+0xd0)+0x24),&message)) {
            if(func_021FF698(*(char **)(*(char **)(p+0xd0)+0x24),(int)&source,&index)) {
                func_0200B938(source,source+0x80,source+0xc4,(unsigned int)func_02012EBC(*(void **)(*(char **)(p+0xd0)+0x28)));
                **(long long **)(*(char **)(p+0xd0)+0x2c)=index;
                **(int **)(p+0xd0)=1;
                func_021F9C50(*(S **)(*(char **)(p+0xd0)+0x14));*state=8;
            } else {
                func_021FD170(*(void **)(p+0x18),(char *)(*(int *)(*(char **)(p+0xd0)+0x10)),(void *)0x114);*state=11;
            }
        } else {
            func_021FD170(*(void **)(p+0x18),(char *)(*(int *)(*(char **)(p+0xd0)+0x10)),(void *)message);*state=11;
        }
        break;
    case 11:
        if(func_02035C60()) {
            func_02035D20(&x,&y);args[0]=x;args[1]=y;
            func_021FD860(*(int *)(p+0x10),1,args);func_020061E4(0x703);*state=12;
        }
        break;
    case 8: func_021FE784((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,1);*state=9;break;
    case 9: if(func_021FE7B0(*(int **)(*(char **)(p+0xd0)+12))) *state=10;break;
    case 10:
        if(!func_02006254(0x701)) {func_021DD0F4(p,*(char **)(p+0xd0));func_021FD744((int *)(*(int *)(p+8)));}
        break;
    case 12: func_021FE784((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,1);*state=13;break;
    case 13: if(func_021FE7B0(*(int **)(*(char **)(p+0xd0)+12))) *state=14;break;
    case 14: func_021DD0F4(p,*(char **)(p+0xd0));func_021FD73C(a,(int)func_021DBC68);break;
    }
}

/*
 * note 2026-10-05: re-run, bytes identical to the original; the only unresolved relocation is the BL to arm9 0x0200B98C (Thumb, 64 bytes, no code-start label, no asm/arm9 witness). Integrator: seed a label at 0x0200B98C; no source change needed.
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
 */
void func_021DC4FC(int *a,int *state,char *p)
{
    switch(*state) {
    case 0:
        func_021DD0AC(p,*(char **)(p+0xd0));
        func_021FD170(*(void **)(p+0x18),(char *)(*(int *)(*(char **)(p+0xd0)+0x10)),(void *)0x152);
        func_021FE784((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,0);
        *state=1;break;
    case 1: if(func_021FE7B0(*(int **)(*(char **)(p+0xd0)+12))) *state=2;break;
    case 2: *state=3;break;
    case 3: *(u16 *)(p+0xb6)=0;*(u16 *)(p+0xb8)=0;*state=4;break;
    case 4:
        if(*(int *)(*(char **)(p+0xd0)+8)>3) func_02034714(d_021E3960,0,d_021E3960);
        if(func_021D7630((void *)(*(int *)(*(char **)(p+0xd0)+0x28)),*(int *)(*(char **)(p+0xd0)+8),(u16 *)(p+0xb6),(u16 *)(p+0xb8),*(u16 *)(p+0xb4))==2) {
            func_0200B490();
            *(int *)(p+0xc8)=(int)func_0200B98C(*(void **)(p+0xc4),5,0);
            *state=5;
        }
        break;
    case 5: func_021FE784((int)(*(int **)(*(char **)(p+0xd0)+12)),2,3,1);*state=6;break;
    case 6: if(func_021FE7B0(*(int **)(*(char **)(p+0xd0)+12))) *state=7;break;
    case 7: func_021DD0F4(p,*(char **)(p+0xd0));func_021FD73C(a,(int)func_021DBC68);break;
    }
}
