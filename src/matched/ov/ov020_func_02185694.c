/*
 * function: func_02185694
 * address:  0x02185694
 * packet:   pkt_ov020_02185694
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Blocked (evidence class: none, unresolved callee sites) by two unlabelled arm9
 * leaves inside labelled arm9 functions (the integrator's), each verified EXACT in a
 * scratch file with `one --region arm9 --thumb`:
 *   0x0202B578: int func_0202B578(int *p) { return p[8]; }
 *   0x02029DF4: void func_02029DF4(void) { func_02029EB4(); }   (thumb tail-call
 *               stub, .word 0x02029EB5)
 *
 * symbols:
 *   func_0218562C  0x0218562C  thumb  ov020
 *   func_020120F4  0x020120F4  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012B2C  0x02012B2C  thumb
 *   func_02012134  0x02012134  thumb
 *   func_0202B578  0x0202B578  thumb
 *   func_0202C110  0x0202C110  thumb
 *   func_02012984  0x02012984  thumb
 *   func_02029DF4  0x02029DF4  thumb
 *   func_020298A0  0x020298A0  thumb
 *   func_02012374  0x02012374  thumb
 *   func_020145FC  0x020145FC  thumb
 */

void func_0218562C(int a);
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct BigObj;
struct Ctx;
struct Evt;
struct Rec44;
struct SaveBlock;
void *func_020120F4(const struct Ctx *p);
void *func_020127A4(struct SaveBlock *p);
void func_02012B2C(struct Rec44 *p, u32 v);
u32 func_02012134(u32 *p);
u32 func_0202B578(u32 *p);
void func_0202C110(void *p);
u8 func_02012984(const struct BigObj *p);
unsigned int func_02029DF4(void *a, unsigned int id, unsigned int which);
void *func_020298A0(void *a, u32 b, u32 c, u32 d);
void func_02012374(struct Evt *evt, struct Evt **out);
int func_020145FC(int a);

int func_02185694(int a0, int *st, int *p)
{
    int r;

    switch (st[0]) {
    case 0:
        func_0218562C(p[0]);
        st[0]++;
        break;
    case 1:
        func_02012B2C(func_020127A4(func_020120F4((const struct Ctx *)p[0])), 0);
        func_0202C110((void *)func_0202B578((u32 *)func_02012134((u32 *)p[0])));
        r = func_02029DF4((void *)p[1], ((short *)p)[6], func_02012984((const struct BigObj *)p[1]));
        r = (int)func_020298A0((void *)p[0], r, 0, 0x3c);
        func_02012374((struct Evt *)a0, (struct Evt **)r);
        st[0]++;
        break;
    case 2:
        r = func_020145FC(p[0]);
        func_02012374((struct Evt *)a0, (struct Evt **)r);
        st[0]++;
        break;
    case 3:
        return 1;
    }
    return 0;
}
