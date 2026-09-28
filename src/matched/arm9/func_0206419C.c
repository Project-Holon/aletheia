/*
 * unit:     no
 * function: func_0206419C
 * address:  0x0206419C
 * packet:   pkt_02064178
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_02066ABC  0x02066ABC  arm
 */
extern char *func_02062D40(char *self);
extern int func_0206285C(char *a, int v);
extern void func_02064140(char *p, int v);
extern void func_020640DC(char *p, int a, int b);
extern void func_02064120(char *p, int a, int b);
extern void func_02064100(char *p, int a);
extern void func_02066ABC(int a, int b, int c);

void func_0206419C(char *self)
{
    char *p;
    char *o;
    int kind;
    int q;
    int r;
    int r2;
    if (*(unsigned short *)(*(int *)(self + 4) + 4) == 0)
        return;
    func_02062D40(self);
    p = func_02062D40(self);
    o = *(char **)(self + 0x34);
    *(int *)(self + 0x30) = func_0206285C(o, *(unsigned short *)p);
    kind = *(int *)(*(int *)(self + 0x1c) + 4) & 0xff;
    func_02064140(self + 0x3c, 1);
    switch (kind) {
    case 0:
        break;
    case 2:
        func_020640DC(self + 0x3c, *(short *)(p + 4), *(short *)(p + 6));
        break;
    default:
        func_02064120(self + 0x3c, *(int *)(p + 4), *(int *)(p + 8));
        func_02064100(self + 0x3c, *(unsigned short *)(p + 2));
        func_020640DC(self + 0x3c, *(short *)(p + 0xc), *(short *)(p + 0xe));
        break;
    }
    q = *(int *)(o + 0xc);
    r = !!q;
    if (r == 0) return;
    if (*(volatile int *)(self + 0x38) != -1) r2 = 1; else r2 = 0;
    if (r2 == 0) return;
    {
        int *t = (int *)(*(int *)(q + 4) + *(unsigned short *)p * 8);
        func_02066ABC(*(int *)(self + 0x38), t[0], t[1]);
    }
}
