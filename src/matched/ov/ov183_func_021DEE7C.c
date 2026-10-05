/*
 * function: func_021DEE7C
 * address: 0x021DEE7C
 * packet: pkt_ov183_021DEE7C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * 2026-10-05 (D8 lane19): re-verified, status unchanged; sole blocker is arm9 callee 0x0200B98C (no witness outside the caller). Needs a label seed. Source is byte-correct; no C change possible.
 * blocker: ARM9 0200B98C thumb +017A has no outside code-start witness; scratch 0200B98C-blocker2.log EXACT. No overlay leaves filed.
 * tu: --suggest-split leaves this caller out (MATCH, 608 bytes, 24/25 resolved); sole unresolved site remains ARM9 0200B98C +017A.
 * blocker-symbols: func_0200B98C_Table 0x0209DDCC data a4
 *   typedef unsigned short u16;
 *   typedef unsigned char u8;
 *   typedef unsigned long long u64;
 *   extern const u16 func_0200B98C_Table[];
 *   u64 func_0200B98C(char *p, int selector, int index)
 *   {
 *       int i;
 *       u16 v;
 *       switch (selector) {
 *       case 0:
 *           v = ((u16 *)p)[index];
 *           if (v > 0x289) return 0;
 *           return v;
 *       case 1:
 *           return *(u8 *)(p + index + 0x18) & 0x7F;
 *       case 2:
 *           v = *(u16 *)(p + 0x24);
 *           if (v > 0x270F) return 0x270F;
 *           return v;
 *       case 3:
 *           for (i = 0; i < 0x29; i++) {
 *               if (*(u16 *)(p + 0x26) == func_0200B98C_Table[i]) return i;
 *           }
 *           return 0;
 *       case 4:
 *           return *(u64 *)(p + 0x38);
 *       case 5:
 *           return *(u8 *)(p + 0x2A);
 *       case 6:
 *           return (*(u8 *)(p + index + 0x18) & 0x80) >> 7;
 *       case 7:
 *           return *(u8 *)(p + 0x2B);
 *       default:
 *           return 0;
 *       }
 *   }
 * checks: 1 three-input u64 ARM9 accessor and caller-read 35C60 return retained; 2 EDB4 twin, eight-byte Pair assignment fixes 4-byte swap; 3 x/y signedness each unchanged; 4 enum offset restores retained 1718 constant and spill; 5 fresh idioms and neighbours, bounded permuter 300 unchanged 608/4 baseline agrees. Aggregate Pair structural check yields MATCH.
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_02034714 0x02034714 arm
 *   func_021FF54C 0x021FF54C thumb ov186
 *   func_021FF648 0x021FF648 thumb ov186
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_021FF72C 0x021FF72C thumb ov186
 *   func_021FF6DC 0x021FF6DC thumb ov186
 *   func_021FF704 0x021FF704 thumb ov186
 *   func_021FF6B4 0x021FF6B4 thumb ov186
 *   func_0200B98C 0x0200B98C thumb
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021DF18C 0x021DF18C thumb ov183
 *   func_021FD170 0x021FD170 thumb ov186
 *   func_02035C60 0x02035C60 arm
 *   func_02035D20 0x02035D20 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021F9BA0 0x021F9BA0 thumb ov186
 *   func_021FD744 0x021FD744 thumb ov186
 *   d_021E3964 0x021E3964 data a1
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;
struct Pair { u32 x,y; };
struct Data { u8 pad[0x1718]; int count; u32 selected; };
extern const char d_021E3964[];
extern void func_02082BCC(void *,int,int),func_02034714(const char *,u32,const char *);
extern void func_021FF54C(void *,int,void *);
extern int func_021FF648(char *),func_021FF72C(void *,int *);
extern int func_021FF6DC(void *,void *,int,void *),func_021FF704(void *,void *,int,void *),func_021FF6B4(void *,void *,int,void *);
extern void func_021FD860(int,int,struct Pair *),func_021FD170(void *,int,int);
extern u64 func_0200B98C(void *,int,int);
extern void func_021FD73C(int *,int),func_021DF18C(void);
extern int func_02035C60(void);
extern u32 func_02035D20(u32 *,u32 *);
extern void func_020061E4(u32),func_021FE784(int,int,int,int);
extern int func_021FE7B0(int *),func_021FD744(int);
extern void func_021F9BA0(void *);
void func_021DEE7C(int *task,u32 *state,char *p)
{
    switch(*state) {
    case 0: {
        struct Pair initial;
        int mode;
        func_02082BCC(&initial,0,8);
        switch(**(u32 **)(p+0x108)) {
        case 0: mode=5; break;
        case 1: mode=6; break;
        case 2: mode=7; break;
        case 3: initial=*(struct Pair *)(*(char **)(p+0x108)+0x20); mode=4; break;
        default: func_02034714(d_021E3964,0,d_021E3964); break;
        }
        func_02082BCC(*(void **)(*(char **)(p+0x108)+0x1c),0,0x1720);
        *(u32 *)(p+0xfc)=0;
        func_021FF54C(*(void **)(*(char **)(p+0x108)+0x18),mode,&initial);
        *state=1; break;
    }
    case 1:
        ++*(u32 *)(p+0xfc);
        if(func_021FF648(*(char **)(*(char **)(p+0x108)+0x18)) && *(u32 *)(p+0xfc)>96) {
            func_021FD860(*(int *)(p+0x1c),0,0); *state=2;
        } break;
    case 2: {
        int message,success,i;
        struct Data *data;
        enum { COUNT_OFFSET=0x1718 } offset;
        data=*(struct Data **)(*(char **)(p+0x108)+0x1c);
        offset=COUNT_OFFSET;
        if(!func_021FF72C(*(void **)(*(char **)(p+0x108)+0x18),&message)) {
            switch(**(u32 **)(p+0x108)) {
            case 0: success=func_021FF6DC(*(void **)(*(char **)(p+0x108)+0x18),data,30,(void *)((u32)data+offset)); break;
            case 1: success=func_021FF6DC(*(void **)(*(char **)(p+0x108)+0x18),data,30,(void *)((u32)data+offset)); break;
            case 2: success=func_021FF704(*(void **)(*(char **)(p+0x108)+0x18),data,30,(void *)((u32)data+offset)); break;
            case 3: success=func_021FF6B4(*(void **)(*(char **)(p+0x108)+0x18),data,30,(void *)((u32)data+offset)); break;
            default: func_02034714(d_021E3964,0,d_021E3964); break;
            }
            if(success) {
                for(i=0;i<(*(struct Data **)(*(char **)(p+0x108)+0x1c))->count;i++) {
                    *(u8 *)(*(char **)(*(char **)(p+0x108)+0x1c)+i+0x16f8)=(u8)func_0200B98C(*(char **)(*(char **)(p+0x108)+0x1c)+i*0xc4+0x80,5,0);
                }
                func_021FD73C(task,(int)func_021DF18C);
            } else {
                if(**(u32 **)(p+0x108)==3) func_021FD170(*(void **)(p+0x24),*(int *)(*(char **)(p+0x108)+0x10),276);
                else func_021FD170(*(void **)(p+0x24),*(int *)(*(char **)(p+0x108)+0x10),339);
                *state=3;
            }
        } else {
            func_021FD170(*(void **)(p+0x24),*(int *)(*(char **)(p+0x108)+0x10),message);
            *state=3;
        } break;
    }
    case 3: {
        u32 x,y;
        struct Pair clicked;
        if(func_02035C60()) {
            func_02035D20(&x,&y);
            clicked.x=x; clicked.y=y;
            func_021FD860(*(int *)(p+0x20),1,&clicked);
            func_020061E4(0x703);
            func_021FE784(*(int *)(*(char **)(p+0x108)+8),2,3,1);
            *state=4;
        } break;
    }
    case 4:
        if(func_021FE7B0(*(int **)(*(char **)(p+0x108)+8))) *state=5;
        break;
    case 5:
        func_021F9BA0(*(void **)(*(char **)(p+0x108)+0x14)); func_021FD744((int)task); break;
    }
}
