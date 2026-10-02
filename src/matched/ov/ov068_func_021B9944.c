/*
 * unit:     yes
 * function: func_021B9944, func_021B9950, func_021B995C, func_021B9964
 * address:  0x021B9944
 * packet:   pkt_ov068_021B9944
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Four contiguous offset-thunks (0x021B9944..0x021B996C), each loading a
 * callee from its own literal pool and tail-calling it with the incoming
 * pointer adjusted.  Each callee is an unlabelled leaf reproduced EXACT under
 * src/matched/ov068_func_021BA018.c, _021BA020.c, _021B9BFC.c and
 * _021B9D58.c; those entries attest the pool-word sites (`matched`).
 *
 * symbols:
 *   func_021BA018  0x021BA018  thumb  ov068
 *   func_021BA020  0x021BA020  thumb  ov068
 *   func_021B9BFC  0x021B9BFC  thumb  ov068
 *   func_021B9D58  0x021B9D58  thumb  ov068
 */

int func_021B9944(void *p, int i)
{
    int func_021BA018(char *, int);
    return func_021BA018((char *)p + 0x7c, i);
}

void func_021B9950(void *p)
{
    void func_021BA020(void *);
    func_021BA020((char *)p + 0x7c);
}

int func_021B995C(int *p, int i)
{
    int func_021B9BFC(int *, int);
    return func_021B9BFC(p, i);
}

void func_021B9964(char *p)
{
    void func_021B9D58(char *);
    func_021B9D58(p);
}
