/*
 * function: func_021F94E4
 * address: 0x021F94E4
 * packet: pkt_ov186_021F94E4
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: final push 2026-10-05 G1L5. Real extent 312 bytes (pool ends 0x021F961A); the unlabelled
 *   follower at 0x021F961C is a separate function, not filed. Case 7 reads the adjacent words ctx+0x10 and
 *   ctx+0x14 as one u64 and splits it into out[7] and out[8] (low word first); this gives the original load
 *   order (r2 from 0x10, then r3 from 0x14). Two int locals, a Pair copy, const, int *ctx and every per-function
 *   pragma left the loads reversed (2 bytes off). A u32 pair read through a pointer or a struct is 101 bytes off.
 *   The u64 read is a judgement call for the integrator: the two words are plausibly one 64-bit field.
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
typedef unsigned char  u8;
struct Big;
struct GdsProfile;
struct ObjC4;
extern u32 func_021FC4DC(u8 *p);
extern void *func_02012EBC(struct Big *p);
extern struct ObjC4 *func_0200B910(void);
extern u32 func_0200B570(void *,u32,u32 *,u32);
extern void func_0200D5D0(struct GdsProfile *p, void *sys);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern const char d_02200D00[];
void func_021F94E4(int *out,int *source,const char *ctx,int type)
{
    u32 result;
    void *sys;
    unsigned a,b;
    out[4]=source[1];out[3]=source[3];out[5]=source[2];
    out[6]=func_021FC4DC((u8 *)source[0]);
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
        if(result==1) {if(!out[2]) func_0200D5D0((struct GdsProfile *)func_0200B910(),sys);}
        else func_02034714(d_02200D00,0,d_02200D00);
        return;
    case 5:
        out[2]=4;out[12]=*(int *)((char *)source[6]+8);
        *(int *)(*(char **)((char *)source[6]+8)+0x1744)=4;
        return;
    case 7:
        out[2]=5;{ unsigned long long v=*(unsigned long long *)(ctx+0x10); out[7]=v; out[8]=v>>32;} out[12]=0;
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

