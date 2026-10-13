/*
 * function: INTRUDE_COMM_BuildLocalProfile
 * address:  0x02175648
 * packet:   pkt_ov011_02175648
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_0200BF70  0x0200BF70  thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_02012FCC  0x02012FCC  thumb
 *   func_0200BFA4  0x0200BFA4  thumb
 *   func_0200BF94  0x0200BF94  thumb
 *   func_0200BF54  0x0200BF54  thumb
 */

typedef unsigned char      u8;
typedef unsigned int       u32;
typedef unsigned long long u64;

typedef struct Out {
    u32 f00;
    u64 f04;
    u8  f0c[2];
    u8  f0e;
} Out;

typedef unsigned short u16;
struct Big;
struct BigObj;
struct Rec1B0;
extern void *func_02012EBC(struct Big *p);
extern u16 *func_0200BE48(void *sys);
extern void  MI_CpuFill8(void *dst, u8 val, u32 size);
extern u32 func_0200BF70(struct Rec1B0 *p);
extern int func_02012B70(const struct BigObj *p);
extern int func_02012FCC(int p0);
extern unsigned long long func_0200BFA4(u8 *p, void *q, u32 mode);
extern unsigned long long func_0200BF94(struct Rec1B0 *p);
extern void func_0200BF54(struct Rec1B0 *p, u8 *dest, u32 n);

void INTRUDE_COMM_BuildLocalProfile(void *sv, Out *o)
{
    void *q;

    q = func_0200BE48(func_02012EBC(sv));
    MI_CpuFill8(o, 0, 0x10);
    o->f00 = func_0200BF70(q);
    if (func_02012B70(sv) == 1) {
        o->f04 = func_0200BFA4(q, (void *)func_02012FCC((int)sv), 2);
    } else {
        o->f04 = func_0200BF94(q);
    }
    func_0200BF54(q, o->f0c, 2);
    o->f0e = 1;
}
