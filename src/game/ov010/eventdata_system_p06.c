/*
 * file:     eventdata_system_p06.c
 * unit:     yes
 * function: func_02162038, func_02162040, func_02162048
 * address:  0x02162038
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02162330 0x02162330 thumb ov010
 *   func_02162358 0x02162358 thumb ov010
 *   func_0216210C  0x0216210C  thumb
 *   func_02162298  0x02162298  thumb
 *   func_0216220C  0x0216220C  thumb
 *   d_0217144C     0x0217144C  data  ov010  a4
 */
typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u32 x;
    u16 b;
    u16 t;
} S;

extern void func_02162330(char *, unsigned);
extern void func_02162358(int a0);
extern int func_0216210C(int a0);
extern int func_02162298(int a0, int a1, int a2);
extern void func_0216220C(u16 *, S *);
void func_02162038(char *p, int index);
void func_02162040(char *p);
void func_02162048(u16 *a, int b, int c);
extern int d_0217144C[];

void func_02162038(char *p, int index)
{
    func_02162330(p, index);
}

/*
 * The full target body overwrites r1/r2 with 0/8 before use; neither
 * caller nor thunk supplies those legacy trailing parameters.
 */
void func_02162040(char *p)
{
    func_02162358((int)p);
}


void func_02162048(u16 *a, int b, int c)
{
    S s;
    int t;

    if (func_0216210C((int)a) == 0) {
        func_02162298((int)a, b, c);
        return;
    }
    t = d_0217144C[c];
    if (t != 4) {
        s.x = *a;
        s.b = b;
        s.t = t;
        func_0216220C(a, &s);
    }
}
