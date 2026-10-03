/*
 * function: func_0215DE58
 * address: 0x0215DE58
 * packet: pkt_ov010_0215DE58
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Padding: two zero alignment bytes after the 150-byte function.
 * Lever: context remains live in r0 across the switch for func_02012A30(p).
 * symbols:
 *   func_020124E4 0x020124E4 thumb
 *   func_020120F4 0x020120F4 thumb
 *   func_02012374 0x02012374 thumb
 *   func_02012A30 0x02012A30 thumb
 *   func_0215DE44 0x0215DE44 thumb ov010
 *   func_0215DE0C 0x0215DE0C thumb ov010
 *   func_02012138 0x02012138 thumb
 *   func_02026454 0x02026454 thumb
 *   func_0203CDBC 0x0203CDBC arm
 *   func_020121CC 0x020121CC thumb
 */
typedef unsigned int u32;
typedef struct { u32 f0; u32 f4; u32 f8; } Ctx;
struct BigObj;
struct Ctx;
struct IcaAnime;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern void *func_020120F4(const struct Ctx *p);
extern void func_02012374(void *, u32);
extern u32 func_02012A30(const struct BigObj *p);
extern void func_0215DE44(int a0);
extern void func_0215DE0C(u32, void *);
extern void *func_02012138(void *);
extern int func_02026454(void *, u32);
extern int func_0203CDBC(void);
extern u32 func_020121CC(struct IcaAnime *p);
int func_0215DE58(void *a, u32 *st, Ctx *c)
{
    void *p;
    p = func_020120F4(func_020124E4(a));
    switch (*st) {
    case 0:
        func_02012374(a, c->f0);
        (*st)++;
        break;
    case 1:
        func_02012A30(p);
        func_0215DE44(c->f4);
        (*st)++;
        break;
    case 2:
        {
            void *q = func_02012138(func_020124E4(a));
            if (c->f8 != 0) {
                if (func_02026454(q, c->f8) != 0)
                    break;
            }
        }
        (*st)++;
        break;
    case 3:
        if (func_0203CDBC() != 1) {
            if (c->f8 != 0)
                break;
        }
        if (c->f8 == 1) {
            func_020121CC(func_020124E4(a));
        }
        func_0215DE0C(c->f4, p);
        (*st)++;
        return 1;
    }
    return 0;
}
