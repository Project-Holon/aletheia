/*
 * function: func_021BA7D0
 * address: 0x021BA7D0
 * packet: pkt_ov213_021BA7D0
 * region: ov213
 * compiler: 1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BAC7C 0x021BAC7C thumb ov213
 *   func_021BAC88 0x021BAC88 thumb ov213
 *   func_02050BE8 0x02050BE8 arm
 *   MTX_Identity33_ 0x0207ADC4 arm
 *   func_02048A18 0x02048A18 arm
 *   func_02047A60 0x02047A60 arm
 * arity: 50BE8 has visible p10 input at 021BA7DC despite own void prototype.
 */
typedef unsigned int u32;
typedef struct { u32 x,y,z; } VecFx32;
typedef struct { u32 m[9]; } MtxFx33;
struct Arg { VecFx32 pos,v0c; MtxFx33 m18; };
typedef struct Util Util;
extern void func_021BAC7C(void *p);
extern void func_021BAC88(void *p);
extern void func_02050BE8(void *p);
extern void MTX_Identity33_(MtxFx33 *p);
extern int *func_02048A18(Util *util, unsigned index);
extern void func_02047A60(void *a0, struct Arg *a1);
void func_021BA7D0(unsigned char *p)
{
    struct Arg arg;
    void *object;
    func_021BAC7C(*(void **)p);
    if(*(void **)(p+16)) func_02050BE8(*(void **)(p+16));
    if(p[15]) {
        arg.pos.x=0; arg.pos.y=0; arg.pos.z=0;
        arg.v0c.x=0x1000; arg.v0c.y=0x1000; arg.v0c.z=0x1000;
        MTX_Identity33_(&arg.m18);
        object=func_02048A18(*(Util **)(p+8),*(unsigned short *)(p+12));
        func_02047A60(object,&arg);
    }
    func_021BAC88(*(void **)p);
}
