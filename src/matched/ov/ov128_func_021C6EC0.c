/*
 * function: func_021C6EC0
 * address: 0x021C6EC0
 * packet: pkt_ov128_021C6EC0
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: 2026-10-05 lane P24L6. Bytes equal to the original (632 B function, 640 B listing
 * extent includes the 8 B stub func_021C7138). Only the two func_021C7138 relocations
 * lack a witness: the stub is now filed as src/matched/ov/ov128_func_021C7138.c (EXACT),
 * so this file should become EXACT after the next manifest refresh. Recoup trail: the
 * condition chain on *p (3,4,1) is an if/else-if chain with q[8]=5 repeated in each arm
 * (bne over b); the shared finish block (func_021C7694 with ctx as 2nd argument,
 * func_021CA19C, q[8]=3) is written out in each of its three arms (case 10 arm 0, case 10
 * arm 1, case 11) and case 10 is an inner switch on the menu status. A goto finish form
 * and a return-0 form were each 4 to 70 bytes off. Callee problem: matched func_021C7694
 * takes one parameter but this caller passes two (p, ctx).
 * symbols:
 *   func_021C7138 0x021C7138 thumb ov128
 *   func_021C6EA0 0x021C6EA0 thumb ov128
 *   func_021C72E4 0x021C72E4 thumb ov128
 *   func_021C74C4 0x021C74C4 thumb ov128
 *   func_021CA3A0 0x021CA3A0 thumb ov128
 *   func_021CA3C4 0x021CA3C4 thumb ov128
 *   func_021CA1E0 0x021CA1E0 thumb ov128
 *   func_021C76BC 0x021C76BC thumb ov128
 *   func_021C74E8 0x021C74E8 thumb ov128
 *   func_021C7500 0x021C7500 thumb ov128
 *   func_021C7558 0x021C7558 thumb ov128
 *   func_021CA014 0x021CA014 thumb ov128
 *   func_021C6B50 0x021C6B50 thumb ov128
 *   func_021C7674 0x021C7674 thumb ov128
 *   func_021C6E3C 0x021C6E3C thumb ov128
 *   func_021C6E74 0x021C6E74 thumb ov128
 *   func_021C6460 0x021C6460 thumb ov128
 *   func_021CA084 0x021CA084 thumb ov128
 *   func_021C7694 0x021C7694 thumb ov128
 *   func_021CA19C 0x021CA19C thumb ov128
 *   func_0202208C 0x0202208C thumb
 *   func_020221A4 0x020221A4 thumb
 *   func_0202EA40 0x0202EA40 thumb
 *   func_0204B98C 0x0204B98C arm
 *   func_0200846C 0x0200846C thumb
 *   func_020084E4 0x020084E4 thumb
 *   func_0201F02C 0x0201F02C thumb
 *   func_020307B0 0x020307B0 arm
 *   func_020355C4 0x020355C4 arm
 *   d_021CA4F9 0x021CA4F9 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
extern void func_021C6EA0(u8 *,u8 *,u8 *,u16);
extern void func_021C72E4(u8 *,u8 *,u8 *);
extern int func_021C74C4(u8 *,u8 *,u8 *);
extern void func_021CA3A0(char *);
extern void func_021CA3C4(char *);
extern int func_021CA1E0(u8 *);
extern int func_021C76BC(u8 *,u8 *);
extern void func_021C74E8(u8 *,u8 *);
extern void func_021C7500(u8 *,u8 *);
extern void func_021C7558(u8 *,u8 *,unsigned,unsigned);
extern u64 func_021CA014(void *,int *);
extern void func_021C6B50(void *,u64);
extern int func_021C7674(u8 *,u8 *,u8 *);
extern void *func_021C6E3C(void *,void *,int,int);
extern int func_021C6E74(void *);
extern int func_021C6460(u8 *,void *,u32);
extern int func_021CA084(u8 *);
extern void func_021C7694(u8 *,u8 *);
extern void func_021CA19C(u8 *);
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern u32 func_020221A4(void);
extern void func_0202EA40(void *);
extern u32 func_0204B98C(void *);
extern void *func_0200846C(int);
extern void func_020084E4(void *,void *);
extern void func_0201F02C(void *,u32,void *);
extern void func_020307B0(void *);
extern u8 func_020355C4(void);
extern void func_021C7138(u8 *,u8 *,u8 *);
extern const u8 d_021CA4F9[];
int func_021C6EC0(u8 *p,u8 *q,u8 *ctx,u16 heap)
{
    int result;
    void *text;
    u64 number;
    switch(q[8]) {
    case 0:
        func_021C6EA0(p,q,ctx,52);
        func_021C72E4(p,q,ctx);
        func_0202208C(0,1,1,0,6,1,heap);
        q[8]=1;
        break;
    case 1:
        if(func_020221A4()!=0) q[8]=3;
        break;
    case 2:
        func_021C6EA0(p,q,ctx,52);
        func_021C72E4(p,q,ctx);
        q[8]=3;
        break;
    case 3:
        func_0202EA40(*(void **)(ctx+0x184));
        result=func_021C74C4(p,q,ctx);
        if(result!=0) {
            if(*(u32 *)p==3) func_021CA3A0((char *)ctx);
            else if(*(u32 *)p==4) func_021CA3C4((char *)ctx);
            else *(u16 *)(p+8)=0;
            q[8]=4;
        }
        break;
    case 4:
        if(*(u32 *)p==3) {
            if(func_0204B98C(*(void **)(ctx+0x164))==1) break;
        } else if(*(u32 *)p==4) {
            if(func_0204B98C(*(void **)(ctx+0x168))==1) break;
        } else {
            if(func_021CA1E0(p)==1) break;
        }
        if(func_021C76BC(p,q)==1) {
            func_021C74E8(p,q);
            if(*(u32 *)p==3) q[8]=5;
            else if(*(u32 *)p==4) q[8]=5;
            else if(*(u32 *)p==1) q[8]=5;
            else {
                func_021C7500(p,ctx);
                func_021C7138(p,q,ctx);
                return 1;
            }
        } else {
            func_021C7558(p,ctx,58,heap);
            q[8]=11;
        }
        break;
    case 5:
        func_0202208C(0,0,0,0,6,1,heap);
        q[8]++;
        break;
    case 6:
        if(func_020221A4()==1) {
            func_021C7138(p,q,ctx);
            return 1;
        }
        break;
    case 7:
        func_021C6EA0(p,q,ctx,52);
        func_021C72E4(p,q,ctx);
        func_0202208C(0,1,1,0,6,1,heap);
        q[8]=8;
        break;
    case 8:
        if(func_020221A4()!=0) {
            text=func_0200846C(heap);
            func_020084E4(text,*(void **)(q+0x58));
            func_0201F02C(*(void **)ctx,0,text);
            func_020307B0(text);
            number=func_021CA014(*(void **)(q+0x5C),&result);
            if(result!=0) {
                func_021C6B50(ctx,number);
                func_021C7558(p,ctx,55,heap);
                q[8]=9;
            } else {
                func_021C7558(p,ctx,56,heap);
                q[8]=11;
            }
        }
        break;
    case 9:
        if(func_021C7674(p,q,ctx)!=0) {
            *(void **)(p+0x4C)=func_021C6E3C(p+0x30,p+0x48,1,heap);
            q[8]=10;
        }
        break;
    case 10:
        switch(func_021C6E74(*(void **)(p+0x4C))) {
        case 0:
            {
            int submission;
            *(u32 *)q=func_020355C4();
            submission=func_021C6460(q,*(void **)(q+0x5C),*(u32 *)(q+0x58));
            if(submission==0) {
                func_021C7694(p,ctx);
                func_021CA19C(p);
                q[8]=3;
            } else {
                func_021C7558(p,ctx,d_021CA4F9[submission],heap);
                q[8]=11;
            }
            }
            break;
        case 1:
            *(u32 *)q=func_020355C4();
            func_021C7694(p,ctx);
            func_021CA19C(p);
            q[8]=3;
            break;
        }
        break;
    case 11:
        if(func_021C7674(p,q,ctx)!=0 && func_021CA084(q)==1) {
            func_021C7694(p,ctx);
            func_021CA19C(p);
            q[8]=3;
        }
        break;
    default:
        break;
    }
    return 0;
}
