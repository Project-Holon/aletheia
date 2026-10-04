/*
 * function: func_021C0750
 * address: 0x021C0750
 * packet: pkt_ov099_021C0750
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: enum-based inline address helpers rematerialize 24c/274; evaluating
 *   the third input before the call keeps 274 out of a callee-saved register.
 * prototype-evidence: B9A60 tail-forwards to ov127 C4A8C, returning its byte
 *   consumed as B9A70's third argument. BDD48/54 return bytes through their
 *   full getter bodies; caller explicitly narrows to u16 before comparisons.
 * bounds: selector starts zero and is set only to 1,2,3,4; both tables have five words.
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1E8 0x0203D1E8 arm
 *   func_021B97F4 0x021B97F4 thumb ov099
 *   func_021BE2A8 0x021BE2A8 thumb ov099
 *   func_021B9A60 0x021B9A60 thumb ov099
 *   func_021B9A70 0x021B9A70 thumb ov099
 *   func_021BDD48 0x021BDD48 thumb ov099
 *   func_021BDD54 0x021BDD54 thumb ov099
 *   func_021BA874 0x021BA874 thumb ov099
 *   func_021BDD60 0x021BDD60 thumb ov099
 *   func_021C08F8 0x021C08F8 thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   d_021C3804 0x021C3804 data a4
 *   d_021C3818 0x021C3818 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct W; struct Work; struct Ent; struct S;
typedef struct { int v[5]; } Messages;
typedef enum { K24c = 0x24c } Off;
static inline char *part(char *p) { Off t; t=K24c; t+=0x28; return p+t; }
static inline struct S *state(char *p) { Off t; t=K24c; return (struct S *)(p+t); }
extern Messages d_021C3804, d_021C3818;
struct Entry;
extern struct Entry *func_020399A8(void);
extern void func_0203D1E8(u32, void *);
extern u8 func_021B97F4(struct W *);
extern void *func_021BE2A8(char *, int);
extern int func_021B9A60(char *);
extern void func_021B9A70(void *, struct Ent *, int);
extern u32 func_021BDD48(int, struct S *);
extern u32 func_021BDD54(int, struct S *);
extern void func_021BA874(struct Work *, int);
extern int func_021BDD60(int);
extern int func_021C08F8(char *);
extern void func_021BAAB8(char *, int, int);
int func_021C0750(char *p, int ret)
{
    Messages a, b;
    int selector, n, message, graphic;
    void *q;
    u16 kind, other;
    selector = 0;
    func_0203D1E8((u32)func_020399A8(), 0);
    n = func_021B97F4((struct W *)part(p));
    q = func_021BE2A8(p, n);
    graphic = func_021B9A60(func_021BE2A8(p, 0));
    func_021B9A70(part(p), q, graphic);
    kind = (u16)func_021BDD48((int)p, state(p));
    other = (u16)func_021BDD54((int)p, state(p));
    func_021BA874((struct Work *)p, n - 1);
    if (other == 6) selector = 1;
    else if (other == 5) selector = 2;
    else if (other == 4) selector = 3;
    else if (func_021BDD60(other)) selector = 4;
    switch (kind) {
    case 0:
        message = 0x59;
        break;
    case 1:
        *(int *)(p + 0x1cc) = 11;
        func_021C08F8(p);
        return ret;
    case 2:
        a = d_021C3804;
        message = a.v[selector];
        break;
    case 4:
        b = d_021C3818;
        message = b.v[selector];
        break;
    case 5:
        message = 0x59;
        break;
    case 3:
    default:
        message = 0x59;
        break;
    }
    func_021BAAB8(p, message, 0);
    *(int *)(p + 0x1cc) = 0x23;
    return ret;
}
