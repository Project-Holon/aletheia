/*
 * function: func_021F94E4
 * address: 0x021F94E4
 * packet: pkt_ov186_021F94E4
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note: recoup 2026-10-05 wave P16 E1. Real extent 312 bytes (pool ends 0x021F961A); the unlabelled
 *   follower at 0x021F961C (load, cmp #1, store 1 into [r1,#0x18], bx lr) is a separate function, not filed.
 *   Residue 2 bytes: in case 7 the two loads from ctx+0x10 and ctx+0x14 come out in the order 0x14
 *   then 0x10; the original loads 0x10 (r2) then 0x14 (r3). All colours match. Best form puts out[2]=5
 *   first in the case (older draft: 10 bytes). The compiler loads the pair in the reverse of the source
 *   assignment order; swapping assignment order, declaration order, store order, direct reads, int or
 *   unsigned locals, an 8-byte Pair copy (6 to 15 bytes), const on source (235), int *ctx (26),
 *   and each per-function pragma (scheduling, opt_lifetimes, opt_common_subs, peephole: still 2;
 *   opt_propagation, opt_dead_assignments: 6) did not close it. Callee types match matched ov186
 *   siblings (func_021FC4DC returns u32, func_0200B570 returns u32).
 *   recoup 2026-10-05 P29R2: still 2 bytes (case 7 ctx+0x10/0x14 load order). Callees re-checked against
 *   matched definitions (func_021FC4DC u32, func_0200B570 u32, others void or pointer): no change. 17 compiles.
 *   Tried: out[7]/out[2]/out[8] interleaved direct stores (12), out[7],out[8],out[2] (17), out[2] first with
 *   direct stores (12), b read before a (2), out[12]=0 before the loads (8), out[8] stored before out[7] (6),
 *   a/b read then out[7],out[2],out[8] in listing store order (10, both read orders), out[7]=a before
 *   reading b (12), b-first interleaved (13), out[12]=0 then b,a,out[8],out[7] (10), const int *ctx
 *   with array indexing (2), block-local const int *c (2), out[2]=5 last (16). The load pair stays
 *   r3 then r2 whenever the colours match.
 * symbols:
 *   func_021FC4DC 0x021FC4DC thumb ov186
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200B570 0x0200B570 thumb
 *   func_0200B910 0x0200B910 thumb
 *   func_0200D5D0 0x0200D5D0 thumb
 *   func_02034714 0x02034714 arm
 *   d_02200D00 0x02200D00 data a1
 */
typedef unsigned int u32;
extern int func_021FC4DC(int);
extern void *func_02012EBC(void *),*func_0200B910(void);
extern u32 func_0200B570(void *,u32,u32 *,u32);
extern void func_0200D5D0(void *,void *);
extern void func_02034714(const char *,int,const char *);
extern const char d_02200D00[];
void func_021F94E4(int *out,int *source,const char *ctx,int type)
{
    u32 result;
    void *sys;
    unsigned a,b;
    out[4]=source[1];out[3]=source[3];out[5]=source[2];
    out[6]=func_021FC4DC(source[0]);
    out[9]=source[5];
    out[10]=(*(int **)((char *)source[6]+12))[1];
    out[11]=*(int *)((char *)source[6]+8)+0x1720;
    out[13]=0;
    out[14]=*(int *)((char *)source[6]+8)+0x1748;
    out[15]=*(int *)((char *)source[6]+8)+0x17bc;
    switch(type) {
    case 0:case 2:case 3:case 4:case 6:case 8:case 9: goto done;
    default:
        if(type!=-2) return;
        break;
    case 1:
        out[2]=*(int *)(ctx+8);out[12]=0;
        *(int *)(*(char **)((char *)source[6]+8)+0x1744)=out[2];
        sys=*(void **)(*(char **)((char *)source[6]+12)+4);
        func_0200B570(func_02012EBC(sys),0x59,&result,out[2]);
        if(result==1) {if(!out[2]) func_0200D5D0(func_0200B910(),sys);}
        else func_02034714(d_02200D00,0,d_02200D00);
        return;
    case 5:
        out[2]=4;out[12]=*(int *)((char *)source[6]+8);
        *(int *)(*(char **)((char *)source[6]+8)+0x1744)=4;
        return;
    case 7:
        out[2]=5;a=*(int *)(ctx+0x10);b=*(int *)(ctx+0x14);out[7]=a;out[8]=b;out[12]=0;
        *(int *)(*(char **)((char *)source[6]+8)+0x1744)=5;
        return;
    case 10:
        a=*(int *)(*(char **)((char *)source[6]+8)+0x1744);
        b=*(int *)(ctx+0x20);
        out[2]=a;
        out[12]=*(int *)((char *)source[6]+8);
        a=*(int *)(ctx+0x1c);out[8]=b;out[7]=a;out[13]=1;
        return;
    }
    out[2]=*(int *)(*(char **)((char *)source[6]+8)+0x1744);
    out[12]=*(int *)((char *)source[6]+8);out[13]=1;
done:
    return;
}

