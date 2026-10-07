/*
 * file:     field_gimmick_d06_p03.c
 * unit:     yes
 * function: func_021F3B88, func_021F3BC4, func_021F3C84
 * address:  0x021F3B88
 * region:   ov051
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0216D88C 0x0216D88C thumb ov010
 *   func_02188CD0 0x02188CD0 thumb ov021
 *   func_021C9064 0x021C9064 thumb ov021
 *   func_021C909C 0x021C909C thumb ov021
 *   func_021F3C98 0x021F3C98 thumb ov051
 *   func_02188C98  0x02188C98  thumb
 *   func_0216D83C  0x0216D83C  thumb
 *   func_0216D854  0x0216D854  thumb
 *   func_0216D86C  0x0216D86C  thumb
 *   func_02164240  0x02164240  thumb
 *   func_02163994  0x02163994  thumb
 *   func_02164280  0x02164280  thumb
 *   func_0216D8AC  0x0216D8AC  thumb
 *   func_021AB0D4  0x021AB0D4  thumb
 *   func_021AB0F0  0x021AB0F0  thumb
 *   func_021AB3F8  0x021AB3F8  thumb
 */
struct Actor;
struct VecFx32;
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct { u32 x,y,z; } V;

extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern u32 func_02188CD0(u8 *);
extern u32 func_021C9064(u32, V *, u32);
extern void func_021C909C(u32);
extern int func_021F3C98(int *a, int *b);
extern int func_02188C98(int a);
extern int func_0216D83C(int a);
extern int func_0216D854(int a);
extern int func_0216D86C(int a);
extern void func_02164240(int a, short *b, short *c, int d);
extern int func_02163994(int a, int b, int c, int d, int e);
extern void func_02164280(int a, int b, int *c);
extern int func_0216D8AC(int a);
extern int func_021AB0D4(int a, int *b);
extern int func_021AB0F0(int a);
extern int func_021AB3F8(int a);
void func_021F3B88(int *a, u32 *out, int c);
int func_021F3BC4(int *a, int *bp, int c, unsigned short d, unsigned int *out);
int func_021F3C84(int *a, int *b, int c);

/*
 * note: two-byte alignment padding at 0x021F3BC2 follows the return.
 * note: func_021C9064's result is stored and read by caller; extern preserves r0 despite its void definition.
 */
void func_021F3B88(int *a, u32 *out, int c)
{
    V v;
    out[0]=c;
    func_0216D88C((const struct Actor *)c,(struct VecFx32 *)&v);
    out[1]=func_021C9064(func_02188CD0((u8 *)a[2]),&v,out[0]);
    if(func_021F3C98(a,(int *)out)==1) func_021C909C(out[1]);
}


/*
 * q[3] is padding (four bytes of frame the original carries above q[1]);
 * m[1] keeps the mask in memory (a plain int folds); d as u16 puts the
 * parameter spill first.
 */
int func_021F3BC4(int *a, int *bp, int c, unsigned short d, unsigned int *out)
{
    int r7 = *bp;
    unsigned short i = 0;
    int q[3];
    short pt[2];
    int m[1];
    int found = 0;
    int sp0c;
    int sp8;
    int r;

    sp0c = func_02188C98(a[2]);
    pt[1] = func_0216D83C(r7);
    sp8 = func_0216D854(r7);
    pt[0] = func_0216D86C(r7);
    m[0] = 1;
    do {
        func_02164240(c, &pt[1], &pt[0], 1);
        r = func_02163994(r7, pt[1], sp8, pt[0], c) & ~m[0];
        if (r != 0) {
            if (r & 2) {
                func_02164280(pt[1], pt[0], &q[0]);
                q[1] = func_0216D8AC(r7);
                r = func_021AB0D4(sp0c, q);
                if (r != -1) {
                    if (func_021AB3F8(func_021AB0F0(r)) == 1)
                        found = 1;
                }
            }
            break;
        }
        i = i + 1;
    } while (i < d);
    if (found == 0)
        i = 0;
    *out = i;
    return found;
}

int func_021F3C84(int *a, int *b, int c) { unsigned int out; func_021F3BC4(a,b,c,32,&out); return out; }
