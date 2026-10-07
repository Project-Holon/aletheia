/*
 * file:     townmap_p02.c
 * unit:     yes
 * function: func_021B991C, func_021B9938, func_021B9944
 * address:  0x021B991C
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_021B995C 0x021B995C thumb ov072
 */
typedef struct Callback Callback;

struct Callback { void (*call)(Callback *, int *, int); int state, value, arg; };

extern void func_02082BCC(void *, int, int);
extern void func_021B995C(int *, int);
void func_021B991C(int *p, int a, int b);
void func_021B9938(void *p);
void func_021B9944(Callback *p);

void func_021B991C(int *p, int a, int b) {
    func_02082BCC(p, 0, 16);
    p[3] = a;
    func_021B995C(p, b);
}


void func_021B9938(void *p)
{
    func_02082BCC(p, 0, 0x10);
}

void func_021B9944(Callback *p) {
    if (p->state == 0) p->call(p, &p->value, p->arg);
}
